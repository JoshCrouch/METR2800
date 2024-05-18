#include <Arduino.h>
#include <Scheduler.h>

// Initialize the array of scheduled tasks
Scheduler::Task Scheduler::Tasks[20];

// Method to schedule a function with a time delay without blocking your loop.
int Scheduler::schedule(unsigned long delay, void (*func)()) // Change to specific function pointer type
{
    unsigned long executeAt = millis() + delay;

    for (int i = 0; i < sizeof(Tasks) / sizeof(Tasks[0]); ++i)
    {
        if (Tasks[i].func == nullptr)
        {
            Tasks[i].func = func;
            Tasks[i].executeAt = executeAt;
            break;
        }
    }

    return executeAt;
}

int old_time = millis();

// Run the event loop and execute scheduled tasks.
void Scheduler::update()
{
    unsigned long currentTime = millis();
    Serial.print("Scheduler Updated after ");
    Serial.print(old_time - currentTime);
    Serial.println(" milliseconds!");

    for (int i = 0; i < sizeof(Tasks) / sizeof(Tasks[0]); i++)
    {
        if (Tasks[i].func != nullptr && currentTime >= Tasks[i].executeAt)
        {
            Tasks[i].func();

            Tasks[i].func = nullptr;
            Tasks[i].executeAt = 0;
        }
    }

    old_time = currentTime;
}