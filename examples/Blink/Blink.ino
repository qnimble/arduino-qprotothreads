/*
  Example for using protothreads for toggling LED's at different rates.
*/

#include "protothreads.h"

//The first thread will blink the LED red, toggling every 500ms.
PT_THREAD(blinkRed(void)) {
  PT_FUNC_START(pt);

  // Loop forever
  while(true) {
    PT_SLEEP(pt, 500);
    toggleLEDRed();
  }

  PT_FUNC_END(pt);
}

//The second thread will blink the LED blue, toggling every 450ms.
PT_THREAD(blinkBlue(void)) {
  PT_FUNC_START(pt);

  // Loop forever
  while(true) {
    PT_SLEEP(pt, 450);
    toggleLEDBlue();
  }

  PT_FUNC_END(pt);
}

// the main loop runs forever and runs the threads as needed
void loop() {
  // Run the two threads
  PT_SCHEDULE(blinkRed());
  PT_SCHEDULE(blinkBlue());
}
