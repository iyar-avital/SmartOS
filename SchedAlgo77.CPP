/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory                 */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum                  */
/* Jerusalem College of Technology, 5759-64 (1999)                            */
/* SchedAlgo64.CPP, short-term scheduler algorithms                */
/****************************************************************/

#include "smarts77.h"

int roundRobin()
// Round Robin short-term algorithm
{
	int count;
	int nextTask = (SMARTS.getCurrentTask() + 1) % SMARTS.getTotalTasks();
	for (count = 0;
		 SMARTS.getStatus(nextTask) != READY && count < SMARTS.getTotalTasks();
		 count++)
		nextTask = ++nextTask % SMARTS.getTotalTasks();
	if (count == SMARTS.getTotalTasks()) // no found READY task to run
		nextTask = SMARTS.getTotalTasks();
	return nextTask;
}

int EDF()
// EDF algorithm
{
	int minLeftTime = MAXINT;
	int nextTask = 0;
	for (int i = 0; i < SMARTS.getTotalTasks(); i++)
	{
		if (SMARTS.getStatus(i) == READY)
		{
			int leftTime = SMARTS.getLeftPeriodTime(i);
			if (leftTime < minLeftTime)
			{
				minLeftTime = leftTime;
				nextTask = i;
			}
		}
	}

	if (minLeftTime == MAXINT) // no found READY task to run
		nextTask = SMARTS.getTotalTasks();
	return nextTask;
}

int RMS()
// RMS algorithm
{
	// Max poriority in the lowest value
	int maxPriority = MAXINT;
	int nextTask = 0;
	for (int i = 0; i < SMARTS.getTotalTasks(); i++)
	{
		if (SMARTS.getStatus(i) == READY)
		{
			int priority = SMARTS.getPriority(i);
			if (priority < maxPriority)
			{
				maxPriority = priority;
				nextTask = i;
			}
		}
	}

	if (maxPriority == MAXINT) // no found READY task to run
		nextTask = SMARTS.getTotalTasks();
	return nextTask;
}
