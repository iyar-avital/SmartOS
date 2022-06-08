/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
Mutex ioMutex, xMutex(1);
Event evC;

void printIntoFile(char *text);
// user Functionss
void a()
{
	ioMutex.acquire();
	cout << "\n *************   A Start    *********************";
	ioMutex.release();

	printIntoFile("A start section 1/3");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}
	printIntoFile("A finish section 1/3");

	printIntoFile("A wait for event");
	char c;
	evC.wait(c);
	printIntoFile("A wake up from waiting by event");

	printIntoFile("A start section 2/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}
	printIntoFile("A finish section 2/3");

	printIntoFile("A acquire xMutex");
	xMutex.acquire();
	printIntoFile("A get xMutex");

	printIntoFile("A start section 3/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "A";
		ioMutex.release();
	}
	printIntoFile("A finish section 3/3");

	printIntoFile("A release xMutex");
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

	printIntoFile("B start section 1/2");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 1/2");

	printIntoFile("B wait for event");
	char c;
	evC.wait(c);
	printIntoFile("B wake up from waiting by event");

	printIntoFile("B start section 2/2");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 2/2");

	ioMutex.acquire();
	cout << "\n *************   B Finish   *********************";
	ioMutex.release();
}

void c()
{
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************";
	ioMutex.release();

	printIntoFile("C start section 1/4");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 1/4");

	printIntoFile("C acquire xMutex");
	xMutex.acquire();
	printIntoFile("C get xMutex");

	printIntoFile("C start section 2/4");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 2/4");

	evC.send('A', NULL, 0);
	printIntoFile("C send event to A");
	evC.send('B', NULL, 0);
	printIntoFile("C send event to B");

	printIntoFile("C start section 3/4");
	for (j = 0; j < 5; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 3/4");

	printIntoFile("C release xMutex");
	xMutex.release();

	printIntoFile("C start section 4/4");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 4/4");

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

void printIntoFile(char *text)
{
	FILE *file = fopen("test_3.txt", "a");
	fprintf(file, text);
	fprintf(file, "\n");
	fclose(file);
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
