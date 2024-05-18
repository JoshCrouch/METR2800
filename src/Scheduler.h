#ifndef ASYNCHRONY_H
#define ASYNCHRONY_H

/*
    This code is heavily based on the library by littleBitsman, however, I
    was having some compilation issues so I rewrote it. Link to the original:
    https://github.com/littleBitsman/Asynchrony/tree/main
*/

#include <Arduino.h>

class Scheduler
{
private:
    struct Task
    {
        void (*func)();
        unsigned long executeAt;
    };

    static Task Tasks[20];

public:
    /*  Method to schedule a function with a time delay without blocking your loop.
     *  In order for this to work, you must call `Scheduler::update` in your loop function to update
     *  the event loop.
     *  DO NOT pass a function that yields using `delay()`. It will still stop execution.
     */
    static int schedule(unsigned long delay, void (*func)());

    // Run the event loop and execute scheduled tasks.
    static void update();
};

#endif