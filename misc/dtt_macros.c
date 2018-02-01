#include<stdio.h>

typedef enum fe_status {
    FE_HAS_SIGNAL    = 0x01,   /*  found something above the noise level */
    FE_HAS_CARRIER    = 0x02,   /*  found a DVB signal  */
    FE_HAS_VITERBI    = 0x04,   /*  FEC is stable  */
    FE_HAS_SYNC    = 0x08,   /*  found sync bytes  */
    FE_HAS_LOCK    = 0x10,   /*  everything's working... */
    FE_TIMEDOUT    = 0x20,   /*  no lock within the last ~2 seconds */
    FE_REINIT    = 0x40    /*  frontend was reinitialized,  */
} fe_status_t;              /*  application is recommended to reset */

/* Tuner event definitions */
/*
 DTT_TUNER_EVENT_CARRIER_LOCKED
 A signal above noise level has been detected.
 */
#define DTT_TUNER_EVENT_CARRIER_LOCKED      (0x00000001)
/*
 DTT_TUNER_EVENT_CARRIER_UNLOCKED
 The carrier has been lost.
 */
#define DTT_TUNER_EVENT_CARRIER_UNLOCKED    (0x00000002)
/*
 DTT_TUNER_EVENT_DEMOD_LOCKED
 The USB tuner demodulator has locked.
 */
#define DTT_TUNER_EVENT_DEMOD_LOCKED        (0x00000004)
/*
 DTT_TUNER_EVENT_DEMOD_UNLOCKED
 The USB tuner demodulator has lost lock.
 */
#define DTT_TUNER_EVENT_DEMOD_UNLOCKED      (0x00000008)
/*
 DTT_TUNER_EVENT_SYNC_LOCKED
 The USB tuner has got sync lock. This is the final stage of tuning, so if sync lock has been achieved it indicates that the tuning process was successful.
 */
#define DTT_TUNER_EVENT_SYNC_LOCKED         (0x00000010)
/*
 DTT_TUNER_EVENT_SYNC_UNLOCKED
 The USB tuner has lost sync lock. This is defined by the relevant standard.
 */
#define DTT_TUNER_EVENT_SYNC_UNLOCKED       (0x00000020)

/* Tuner status definitions */
/*
 The USB tuner has detected no carrier, but is still trying to tune.
 */
#define DTT_TUNER_SIGNAL_NO_CARRIER   (0x00)
/*
 The USB tuner has detected a carrier.
 */
#define DTT_TUNER_SIGNAL_CARRIER      (0x01)
/*
 The USB tuner is demodulating the signal.
 */
#define DTT_TUNER_SIGNAL_DEMOD        (0x02)
/*
The USB tuner has successfully acquired the signal.
 */
#define DTT_TUNER_SIGNAL_SYNC         (0x04)

 
#define FE_READY (FE_HAS_SIGNAL|FE_HAS_CARRIER|FE_HAS_LOCK|FE_HAS_VITERBI|FE_HAS_SYNC)
#define DTT_READY ( DTT_TUNER_EVENT_CARRIER_LOCKED  |DTT_TUNER_EVENT_DEMOD_LOCKED|DTT_TUNER_EVENT_SYNC_LOCKED)
#define DTT_NOT_READY ( DTT_TUNER_EVENT_CARRIER_UNLOCKED |DTT_TUNER_EVENT_DEMOD_UNLOCKED|DTT_TUNER_EVENT_SYNC_UNLOCKED)

int main()
{
    printf("\n Value of FE_READY is %x\n",FE_READY);
    printf("\n Value of DTT_READY is %x\n",DTT_READY);
    printf("\n Value of DTT_NOT_READY is %x\n",DTT_NOT_READY);
    printf("\n value of events is %x\n",DTT_TUNER_EVENT_SYNC_LOCKED|DTT_TUNER_EVENT_SYNC_UNLOCKED);
    printf("\n events is %x\n",(DTT_TUNER_EVENT_CARRIER_LOCKED|DTT_TUNER_EVENT_CARRIER_UNLOCKED));
    if(-1) printf("hi");
    return 0;
}
