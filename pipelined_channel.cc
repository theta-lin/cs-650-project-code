#include "pipelined_channel.h"

Define_Channel(PipelinedChannel);

PipelinedChannel::Result PipelinedChannel::processMessage(cMessage *msg, const SendOptions &options, simtime_t t)
{
    Result result;

    simtime_t transmission = 0;
    if (msg->isPacket()) {
        cPacket *pkt = check_and_cast<cPacket*>(msg);
        transmission = pkt->getBitLength() / getDatarate();
    }

    simtime_t startTx = std::max(t, txFinishTime);

    result.delay = getDelay() + transmission + (startTx - t);
    result.duration = 0;

    txFinishTime = t + transmission + (startTx - t);

//    EV << "txFinishTime: " << txFinishTime << '\n';
    return result;
}
