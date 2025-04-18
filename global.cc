#include "global.h"

Define_Module(Global);

double aGet(const cPar &a, int i, int j)
{
    auto *t0 = check_and_cast<cValueArray*>(a.objectValue());
    auto *t1 = check_and_cast<cValueArray*>(t0->get(i).objectValue());
    return t1->get(j).doubleValue();
}

void Global::initialize()
{
    n = par("n").intValue();
    m = par("m").intValue();
    B = par("B").intValue();
    Bm = par("Bm").intValue();
    D = par("D").intValue();
    F = par("F").intValue();
    L = par("L").intValue();
    dtSize = par("dtSize").intValue();
    numBatch = par("numBatch").intValue();

    Lg = 1.0 * L / n;
    mbCnt = 1.0 * B / Bm;
    inSize = 1.0 * Bm * D * dtSize;

    const cPar &sDelay = par("subserverDelay");
    const cPar &sBandwidth = par("subserverBandwidth");

    double minCost = std::numeric_limits<double>::max();
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    nextSubserver.resize(n);
    prevSubserver.resize(n);
    do
    {
        double cost = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            cost += aGet(sDelay, p[i], p[i + 1]) * msToS
                    + 1.0 * B * D * F * dtSize / (aGet(sBandwidth, p[i], p[i + 1]) * gbpsToBytes);
        }
        if (cost < minCost)
        {
            minCost = cost;
            firstSubserver = p[0];
            for (int i = 0; i < n - 1; ++i) nextSubserver[p[i]] = p[i + 1];
            nextSubserver[p[n - 1]] = -1;
            prevSubserver[p[0]] = -1;
            for (int i = 0; i < n - 1; ++i) prevSubserver[p[i + 1]] = p[i];
        }
    }
    while (std::next_permutation(p.begin(), p.end()));

    EV << "Optimal subserver order: ";
    for (int i = firstSubserver; i != -1; i = nextSubserver[i]) EV << i << ' ';
    EV << "\n";
    EV << "minCost = " << minCost << '\n';
}
