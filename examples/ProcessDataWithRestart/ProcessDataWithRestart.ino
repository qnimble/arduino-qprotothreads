#include <protothreads.h>

/* This example has one thread toggle a the LED every 500ms while a second
   thread does some number crunching. When the number-crunching thread is
   finished, the LED changes from blinking red to blinking green. Additionally,
   a third thread restarts the processing thread 10s after it finishes. More
   details at https://qnimble.com/Quarto/Examples/Threads
*/
pt ptProcessData = {0};
pt* ptProcess = &ptProcessData;

PT_THREAD(blinkLED(void)) {
  PT_FUNC_START(pt);

  while(true) {
    PT_SLEEP(pt, 500);
    if (PT_SCHEDULE(processData())) {
      setLED(1,0,0); //turn on RED LED
    } else {
      setLED(0,1,0); //turn on Green LED
    }
    PT_SLEEP(pt, 500);
    setLED(0,0,0); //turn off LEDs
  }

  PT_FUNC_END(pt);
}


PT_THREAD(reProcess(void)) {
  PT_FUNC_START(pt);

  while(true) {
    PT_WAIT_THREAD(pt,processData()); //wait until processData thread completes
    PT_SLEEP(pt,10000); //wait 10s after processData is done
    PT_RESTART(ptProcess); //Restart the finished thread
  }

  PT_FUNC_END(pt);
}



PT_THREAD(processData(void)) {
  PT_FUNC_START_EXT(ptProcess);

  static double calc = 0.1234;
  static uint i=0;

  for(i=0; i< 2500000;i++) {
    double temp = cos(calc*(calc-1.23*i));
    calc = temp*sin((calc-0.23*i)*3.456)+calc*calc/9.8765;
    PT_YIELD(ptProcess); // pause here to check if other threads need to be run
  }

  PT_FUNC_END(ptProcess);
}

void loop() {
  PT_SCHEDULE(processData());
  PT_SCHEDULE(reProcess());
  PT_SCHEDULE(blinkLED());
}