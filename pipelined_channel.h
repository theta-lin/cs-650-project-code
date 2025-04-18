#ifndef __PIPELINED_CHANNEL_H
#define __PIPELINED_CHANNEL_H

#include <omnetpp.h>

using namespace omnetpp;

/**
 * A custom channel that models both a fixed propagation delay and a serialization delay.
 * It accumulates the transmission delay (packet length divided by channel data rate) so that
 * if packets are sent back-to-back, their arrival times reflect both the fixed delay and the
 * cumulative serialization delay.
 */
class PipelinedChannel : public cDatarateChannel {
  protected:
    // Internal variable that tracks the finish time of the last transmitted packet.
    simtime_t txFinishTime = 0;
  public:
    PipelinedChannel(const char *name = nullptr) : cDatarateChannel(name) {}
    virtual ~PipelinedChannel() {}

    // Indicate that this channel is a transmission channel.
    virtual bool isTransmissionChannel() const override { return true; }

    /**
     * processMessage() calculates the transmission delay for the given message.
     * Instead of blocking the sender when a packet is being "serialized",
     * it uses an internal variable (txFinishTime) to accumulate serialization delays.
     *
     * The resulting delay applied to this packet is:
     *     fixed delay + transmissionDelay,
     * and the internal finish time is updated accordingly.
     *
     * @param msg     The message being sent (should be a cPacket for serialization delay calculation).
     * @param options The sending options (not used in this implementation).
     * @param t       The time when the packet reaches the channel.
     * @return        The result containing computed delays and duration.
     */
    virtual Result processMessage(cMessage *msg, const SendOptions &options, simtime_t t) override;
};

#endif // __PIPELINED_CHANNEL_H
