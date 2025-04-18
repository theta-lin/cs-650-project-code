#include <omnetpp.h>
#include "packet_m.h"
#include "global.h"

using namespace omnetpp;

class Client : public cSimpleModule
{
  private:
    Global *g;
    int cId;
//    FIXME !!!
    double C;
    double tCompute;
    std::map<int, int> mbCompleted;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Client);

void Client::initialize()
{
    g = check_and_cast<Global *>(getModuleByPath("global"));
    cId = par("id").intValue();
    C = (cId + 1) * 3e12;
//    C = (cId + 1) * 3e14;
    tCompute = 1.0 * g->Bm / 5 / C * g->D * g->F * g->Lg;
//    EV << "tCompute: " << tCompute << '\n';
}

void Client::handleMessage(cMessage *msg)
{
    if (auto rec = dynamic_cast<DownloadIn*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        auto *pkt = new UploadIn();
        pkt->setInId(inId);
        pkt->setBId(bId);
        pkt->setByteLength(g->inSize);
        sendDelayed(pkt, SimTime(tCompute, SIMTIME_S, true), "out");
//        send(pkt, "out");
    }
    else if (auto rec = dynamic_cast<DownloadDOut*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        auto *pkt = new UploadDOut();
        pkt->setInId(inId);
        pkt->setBId(bId);
        pkt->setByteLength(g->inSize);
        sendDelayed(pkt, SimTime(tCompute, SIMTIME_S, true), "out");
//        send(pkt, "out");

        auto &cnt = mbCompleted[bId];
        cnt += 1;
        if (cnt == g->mbCnt)
        {
            mbCompleted.erase(bId);
            auto *pkt = new UploadReduce();
            pkt->setBId(bId);
//            FIXME
            pkt->setByteLength(2.0 * g->D * g->F * g->Lg);
            send(pkt, "out");
        }
    }

    delete msg;
}
