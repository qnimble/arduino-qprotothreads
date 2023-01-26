*qProtothreads* is a fork of Protothreads, an extremely lightweight stackless threads designed for
severely memory constrained systems. 

qProtothreads provides a blocking context on top of an event-driven
system, without the overhead of per-thread stacks. The purpose of
qProtothreads is to implement sequential flow of control without
complex state machines or full multi-threading.

Main features:

    * No machine specific code - the qProtothreads library is pure C
    * Does not use error-prone functions such as longjmp()
    * Very small RAM overhead - only two bytes per qProtothread
    * Provides blocking wait without full multi-threading or
      stack-switching
    * Freely available under a BSD-like open source license    

The qProtothreads library is released under an open source BSD-style
license that allows for both non-commercial and commercial usage. The
only requirement is that credit is given.

The qProtothreads library was written by Adam Dunkels <adam@sics.se>
with support from Oliver Schmidt <ol.sc@web.de>. Arduino port by 
Ben Artin <ben@artins.org>

More information the original Protothreads at
homepage: http://www.sics.se/~adam/pt/

The original code lives at: https://gitlab.com/airbornemint/arduino-protothreads

The latest qProtothreads code lives at: https://github.com/qnimble/arduino-qprotothreads

Documentation can be found in the doc/ subdirectory.

Two Arduino example programs are included to illustrate the use of qProtothreads:

 * Blink: Blinks the on-board LED. 
 * Button: Turns the on-board LED on an off with a push button.

Both examples are based on stock Arduino sample code, modified to work with 
qProtothreads.

qNimble, Jan 27 2023

Baseed on work by Ben Artin, July 15 2020

Based on work by Adam Dunkels, 3 June 2006
