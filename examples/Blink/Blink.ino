/*
  Example for using protothreads for toggling LED's at different rates.
*/

#include "protothreads.h"

// Each protothread needs its own object to store its state information
// We will create two such objects: ptBlinkRed and ptBlinkBlue
pt ptBlinkRed;
pt ptBlinkBlue;

//The first thread will blink the LED red, toggling every 450ms.
PT_THREAD(blinkRed(struct pt* pt)) {
  PT_BEGIN(pt);

  // Loop forever
  while(true) {
    setLEDRed(true);
    PT_SLEEP(pt, 450);
    setLEDRed(false);
    PT_SLEEP(pt, 450);
  }

  PT_END(pt);
}

//The second thread will blink the LED blue, toggling every 500ms.
PT_THREAD(blinkBlue(struct pt* pt)) {
  PT_BEGIN(pt);

  // Loop forever
  while(true) {
    setLEDBlue(true);
    PT_SLEEP(pt, 500);
    setLEDBlue(false);
    PT_SLEEP(pt, 500);
  }

  PT_END(pt);
}

// once on startup, initialize the threads.
void setup() {
  PT_INIT(&ptBlinkRed);
  PT_INIT(&ptBlinkBlue);
}

// the main loop runs forever and runs the threads as needed
void loop() {
  // Run the two threads, wi
  PT_SCHEDULE(blinkRed(&ptBlinkRed));
  PT_SCHEDULE(blinkBlue(&ptBlinkBlue));
}
