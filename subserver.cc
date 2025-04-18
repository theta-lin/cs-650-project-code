#include <omnetpp.h>
#include "packet_m.h"
#include "global.h"

#include <map>
#include <tuple>

using namespace omnetpp;

class Subserver : public cSimpleModule
{
  private:
    Global *g;
    int sId, sNext, sPrev;
    int curBatch;
    std::map<int, int> localInReceived;
    std::map<int, int> localDOutReceived;
    std::map<int, int> reduceReceived;

    void sendBatch();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Subserver);

void Subserver::sendBatch()
{
    if (curBatch >= g->numBatch) return;
    for (int i = 0; i < g->mbCnt; ++i)
    {
        auto *pkt = new GlobalIn();
        pkt->setInId(i);
        pkt->setBId(curBatch);
        pkt->setByteLength(g->inSize);
        scheduleAt(simTime(), pkt);
    }
    ++curBatch;
}

void Subserver::initialize()
{
    g = check_and_cast<Global *>(getModuleByPath("global"));
    sId = par("id").intValue();
    sNext = g->nextSubserver[sId];
    sPrev = g->prevSubserver[sId];
    curBatch = 0;

    if (sId == g->firstSubserver) {
        sendBatch();
    }
}

void Subserver::handleMessage(cMessage *msg)
{
    if (auto rec = dynamic_cast<GlobalIn*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        for (int i = 0; i < g->m; ++i)
        {
            auto *pkt = new DownloadIn();
            pkt->setInId(inId);
            pkt->setBId(bId);
            pkt->setByteLength(g->inSize);
            send(pkt, "localOut", i);
        }
    }
    else if (auto rec = dynamic_cast<UploadIn*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        auto &cnt = localInReceived[inId];
        cnt += 1;

        if (cnt == g->m)
        {
            localInReceived.erase(inId);
//            EV << "sId: " << sId << "inId: " << inId << " completed" << '\n';
            if (sNext == -1)
            {
                auto *pkt = new GlobalDOut();
                pkt->setInId(inId);
                pkt->setBId(bId);
                scheduleAt(simTime(), pkt);
            }
            else
            {
                auto *pkt = new GlobalIn();
                pkt->setByteLength(g->inSize);
                send(pkt, "globalOut", sNext);
            }
        }
    }
    else if (auto rec = dynamic_cast<GlobalDOut*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        for (int i = 0; i < g->m; ++i)
        {
            auto *pkt = new DownloadDOut();
            pkt->setInId(inId);
            pkt->setBId(bId);
            pkt->setByteLength(g->inSize);
            send(pkt, "localOut", i);
        }
    }
    else if (auto rec = dynamic_cast<UploadDOut*>(msg); rec != nullptr)
    {
        int inId = rec->getInId();
        int bId = rec->getBId();
        auto &cnt = localDOutReceived[inId];
        cnt += 1;

        if (cnt == g->m)
        {
            localDOutReceived.erase(inId);
//            EV << "sId: " << sId << "inId: " << inId << " completed" << '\n';
            if (sPrev != -1)
            {
                auto *pkt = new GlobalDOut();
                pkt->setInId(inId);
                pkt->setBId(bId);
                send(pkt, "globalOut", sPrev);
            }
        }
    }
    else if (auto rec = dynamic_cast<UploadReduce*>(msg); rec != nullptr)
    {
        int bId = rec->getBId();
        auto &cnt = reduceReceived[bId];
        cnt += 1;
        if (cnt == g->m)
        {
            reduceReceived.erase(bId);
            for (int i = 0; i < g->m; ++i)
            {
                auto *pkt = new DownloadReduce();
                pkt->setBId(bId);
                pkt->setByteLength(2.0 * g->D * g->F * g->Lg);
//              FIXME
                send(pkt, "localOut", i);
            }
            if (sId == g->firstSubserver) {
                sendBatch();
            }
        }
    }

    delete msg;
}
