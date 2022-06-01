#include "smarts77.h"

Mutex::Mutex()
{
    count = 0;
    owner = -1;
    level = 0;
}

void Mutex::acquire()
{
    SMARTS.contextSwitchOff();
    int current = SMARTS.getCurrentTask();
    if (count == 1 || owner == current)
        count = 0;
    else
    {
        queue.enqueue(current);
        SMARTS.contextSwitchOn();
        SMARTS.suspended();
        SMARTS.contextSwitchOff();
    }
    owner = current;
    level++;
    SMARTS.contextSwitchOn();
}

void Mutex::release()
{
    SMARTS.contextSwitchOff();
    int current = SMARTS.getCurrentTask();

    if (owner == current)
    {
        if (--level)
            return;
        else
        {
            owner = -1;
            if (!queue.isEmpty())
            {
                int nextTask = queue.dequeue();
                SMARTS.Resume(nextTask);
            }
            else
                count = 1;
        }
    }
    SMARTS.contextSwitchOn();
}