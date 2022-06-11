/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
Mutex ioMutex;
Event evCToAB, evFToDE;
int xMutex = 0, yMutex = 1;

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
	evCToAB.wait(c);
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
	SMARTS.acquire(xMutex);
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
	SMARTS.release(xMutex);

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
	evCToAB.wait(c);
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
	SMARTS.acquire(xMutex);
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

	printIntoFile("C start send event to A");
	evCToAB.send('A', NULL, 0);
	printIntoFile("C finish send event to A");
	printIntoFile("C start send event to B");
	evCToAB.send('B', NULL, 0);
	printIntoFile("C finish send event to B");

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
	SMARTS.release(xMutex);

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

void d()
{
	ioMutex.acquire();
	cout << "\n *************   D Start    *********************";
	ioMutex.release();

	printIntoFile("D start section 1/3");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 1/3");

	printIntoFile("D wait for event");
	char c;
	evFToDE.wait(c);
	printIntoFile("D wake up from waiting by event");

	printIntoFile("D start section 2/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 2/3");

	printIntoFile("D acquire yMutex");
	SMARTS.acquire(yMutex);
	printIntoFile("D get yMutex");

	printIntoFile("D start section 3/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 3/3");

	printIntoFile("D release xMutex");
	SMARTS.release(yMutex);

	ioMutex.acquire();
	cout << "\n *************   D Finish   *********************";
	ioMutex.release();
}

void e()
{
	ioMutex.acquire();
	cout << "\n *************   E Start    *********************";
	ioMutex.release();

	printIntoFile("E start section 1/2");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "E";
		ioMutex.release();
	}
	printIntoFile("E finish section 1/2");

	printIntoFile("E wait for event");
	char c;
	evFToDE.wait(c);
	printIntoFile("E wake up from waiting Ey event");

	printIntoFile("E start section 2/2");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "E";
		ioMutex.release();
	}
	printIntoFile("E finish section 2/2");

	ioMutex.acquire();
	cout << "\n *************   E Finish   *********************";
	ioMutex.release();
}

void f()
{
	ioMutex.acquire();
	cout << "\n *************   F Start    *********************";
	ioMutex.release();

	printIntoFile("F start section 1/4");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish section 1/4");

	printIntoFile("F acquire yMutex");
	SMARTS.acquire(yMutex);
	printIntoFile("F get yMutex");

	printIntoFile("F start section 2/4");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish section 2/4");

	printIntoFile("F start send event to D");
	evFToDE.send('D', NULL, 0);
	printIntoFile("F finish send event to D");
	printIntoFile("F start send event to E");
	evFToDE.send('E', NULL, 0);
	printIntoFile("F finish send event to E");

	printIntoFile("F start section 3/4");
	for (j = 0; j < 5; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish section 3/4");

	printIntoFile("F release yMutex");
	SMARTS.release(yMutex);

	printIntoFile("F start setcion 4/4");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish seFtion 4/4");

	ioMutex.acquire();
	cout << "\n *************   F Finish   *********************";
	ioMutex.release();
}

void main()
{
	clrscr();
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	SMARTS.declareTask(a, 'A', 400, 3);
	SMARTS.declareTask(b, 'B', 401, 3);
	SMARTS.declareTask(c, 'C', 402, 3);
	SMARTS.declareTask(d, 'D', 403, 3);
	SMARTS.declareTask(e, 'E', 404, 3);
	SMARTS.declareTask(f, 'F', 405, 3);
	SMARTS.declareMutex(xMutex, 1);
	SMARTS.declareMutex(yMutex, 1);
	SMARTS.runTheTasks();
}

void printIntoFile(char *text)
{
	FILE *file = fopen("TEST.txt", "a");
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
