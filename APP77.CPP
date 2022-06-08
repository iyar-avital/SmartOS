/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
Mutex ioMutex, xMutex;
Event evAtoC, evBtoC;
// user Functionss
void a()
{
	ioMutex.acquire();
	cout << "\n *************   A Start    *********************";
	ioMutex.release();
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}

	char c;
	evAtoC.wait(c);

	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}

	xMutex.acquire();

	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}

	xMutex.release();
	ioMutex.acquire();
	cout << "\n *************   A Finish   *********************";
	ioMutex.release();
}

void b()
{
	ioMutex.acquire();
	cout << "\n *************   B Start    *********************";
	ioMutex.release();
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}

	char c;
	evBtoC.wait(c);

	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   B Finish   *********************";
	ioMutex.release();
}

void c()
{
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************";
	ioMutex.release();
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}

	xMutex.acquire();
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}

	evAtoC.send('A', NULL, 0);
	evBtoC.send('B', NULL, 0);

	for (j = 0; j < 5; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}

	xMutex.release();

	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}

	ioMutex.acquire();
	cout << "\n *************   C Finish   *********************";
	ioMutex.release();
}

void main()
{
	clrscr();
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	SMARTS.declareTask(a, 'A', 400, 3);
	SMARTS.declareTask(b, 'B', 401, 3);
	SMARTS.declareTask(c, 'C', 402, 3);
	// SMARTS.declareTask(d, 'D', 403, 3);
	// SMARTS.declareTask(e, 'E', 404, 3);
	// SMARTS.declareTask(f, 'F', 405, 3);
	SMARTS.runTheTasks();
}

// Iyar Avital 323075499
// Rivka Zizovi 207265711

// EDF and RR works fine
// for each function a,b,c the nested loop define by value:
// i = 0 -> 200000

// EDF works fine but RR fails
// for each function a,b,c the nested loop define by value:
// i = 0 -> 500000

// RR works fine but EDF fails
// Not possible

// EDF and RR fails
// i = 0 -> 2000000
