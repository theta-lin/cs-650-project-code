#ifndef __GLOBAL_H
#define __GLOBAL_H

#include <algorithm>
#include <numeric>
#include <limits>

#include <omnetpp.h>
using namespace omnetpp;

const double msToS = 1e3;
const double gbpsToBytes = 1e9 / 8;

class Global : public cSimpleModule
{
  protected:
    virtual void initialize() override;

  public:
    int n, m, B, Bm, D, F, L, dtSize;
    double mbCnt;
    double Lg;
    int numBatch;
    double inSize;
    int firstSubserver;
    std::vector<int> nextSubserver, prevSubserver;
};

#endif
