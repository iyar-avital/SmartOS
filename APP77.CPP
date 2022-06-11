/********************************************************************/
/* A Small Real Time System for the Real-Time laboratory            */
/* built by: A.Teitelbaum on an idea of H.G.Mendelbaum              */
/* Jerusalem College of Technology, 5759-64 (1999-03)               */
/* update  Tishrey   5777                                           */
/* APP77.CPP, an application to demonstrate SMARTS77  functioning   */
/********************************************************************/
#include "smarts77.h"
Mutex ioMutex;
Event evBtoAF, evCtoBG, evDtoCH, evEtoD;
int abMutex = 0, bcMutex = 1, cdMutex = 2, deMutex = 3;

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
	evBtoAF.wait(c);
	printIntoFile("A wake up from waiting by event");

	printIntoFile("A acquire abMutex");
	SMARTS.acquire(abMutex);
	printIntoFile("A get abMutex");

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

	printIntoFile("A release abMutex");
	SMARTS.release(abMutex);

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

	ioMutex.acquire();
	cout << "\n *************   A Finish   *********************";
	ioMutex.release();
}

void b()
{
	ioMutex.acquire();
	cout << "\n *************   B Start    *********************";
	ioMutex.release();

	printIntoFile("B start section 1/5");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 1/5");

	printIntoFile("B wait for event");
	char c;
	evCtoBG.wait(c);
	printIntoFile("B wake up from waiting by event");

	printIntoFile("B acquire abMutex");
	SMARTS.acquire(abMutex);
	printIntoFile("B get abMutex");

	printIntoFile("B start send event to A");
	evBtoAF.send('A', NULL, 0);
	printIntoFile("B finish send event to A");
	printIntoFile("B start send event to F");
	evBtoAF.send('F', NULL, 0);
	printIntoFile("B finish send event to F");

	printIntoFile("B start section 2/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 2/5");

	printIntoFile("B acquire bcMutex");
	SMARTS.acquire(bcMutex);
	printIntoFile("B get bcMutex");

	printIntoFile("B start section 3/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 3/5");

	printIntoFile("B release bcMutex");
	SMARTS.release(bcMutex);

	printIntoFile("B start section 4/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 4/5");

	printIntoFile("B release abMutex");
	SMARTS.release(abMutex);

	printIntoFile("B start section 5/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "B";
		ioMutex.release();
	}
	printIntoFile("B finish section 5/5");

	ioMutex.acquire();
	cout << "\n *************   B Finish   *********************";
	ioMutex.release();
}

void c()
{
	ioMutex.acquire();
	cout << "\n *************   C Start    *********************";
	ioMutex.release();

	printIntoFile("C start section 1/5");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 1/5");

	printIntoFile("C wait for event");
	char c;
	evDtoCH.wait(c);
	printIntoFile("C wake up from waiting by event");

	printIntoFile("C acquire bcMutex");
	SMARTS.acquire(bcMutex);
	printIntoFile("C get bcMutex");

	printIntoFile("C start send event to B");
	evCtoBG.send('B', NULL, 0);
	printIntoFile("C finish send event to B");
	printIntoFile("C start send event to G");
	evCtoBG.send('G', NULL, 0);
	printIntoFile("C finish send event to G");

	printIntoFile("C start section 2/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 2/5");

	printIntoFile("C acquire cdMutex");
	SMARTS.acquire(cdMutex);
	printIntoFile("C get cdMutex");

	printIntoFile("C start section 3/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 3/5");

	printIntoFile("C release cdMutex");
	SMARTS.release(cdMutex);

	printIntoFile("C start section 4/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 4/5");

	printIntoFile("C release bcMutex");
	SMARTS.release(bcMutex);

	printIntoFile("C start section 5/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "C";
		ioMutex.release();
	}
	printIntoFile("C finish section 5/5");

	ioMutex.acquire();
	cout << "\n *************   C Finish   *********************";
	ioMutex.release();
}

void d()
{
	ioMutex.acquire();
	cout << "\n *************   D Start    *********************";
	ioMutex.release();

	printIntoFile("D start section 1/5");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 1/5");

	printIntoFile("D wait for event");
	char c;
	evEtoD.wait(c);
	printIntoFile("D wake up from waiting by event");

	printIntoFile("D acquire cdMutex");
	SMARTS.acquire(cdMutex);
	printIntoFile("D get cdMutex");

	printIntoFile("D start send event to C");
	evDtoCH.send('C', NULL, 0);
	printIntoFile("D finish send event to C");
	printIntoFile("D start send event to H");
	evDtoCH.send('H', NULL, 0);
	printIntoFile("D finish send event to H");

	printIntoFile("D start section 2/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 2/5");

	printIntoFile("D acquire deMutex");
	SMARTS.acquire(deMutex);
	printIntoFile("D get deMutex");

	printIntoFile("D start section 3/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 3/5");

	printIntoFile("D release deMutex");
	SMARTS.release(deMutex);

	printIntoFile("D start section 4/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 4/5");

	printIntoFile("D release cdMutex");
	SMARTS.release(cdMutex);

	printIntoFile("D start section 5/5");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "D";
		ioMutex.release();
	}
	printIntoFile("D finish section 5/5");

	ioMutex.acquire();
	cout << "\n *************   D Finish   *********************";
	ioMutex.release();
}

void e()
{
	ioMutex.acquire();
	cout << "\n *************   E Start    *********************";
	ioMutex.release();

	printIntoFile("E start section 1/3");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "E";
		ioMutex.release();
	}
	printIntoFile("E finish section 1/3");

	printIntoFile("E acquire deMutex");
	SMARTS.acquire(deMutex);
	printIntoFile("E get deMutex");

	printIntoFile("E start send event to D");
	evEtoD.send('D', NULL, 0);
	printIntoFile("E finish send event to D");

	printIntoFile("E start section 2/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "E";
		ioMutex.release();
	}
	printIntoFile("E finish section 2/3");

	printIntoFile("E release deMutex");
	SMARTS.release(deMutex);

	printIntoFile("E start section 3/3");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "E";
		ioMutex.release();
	}
	printIntoFile("E finish section 3/3");

	ioMutex.acquire();
	cout << "\n *************   E Finish   *********************";
	ioMutex.release();
}

void f()
{
	ioMutex.acquire();
	cout << "\n *************   F Start    *********************";
	ioMutex.release();

	printIntoFile("F start section 1/2");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish section 1/2");

	printIntoFile("F wait for event");
	char c;
	evBtoAF.wait(c);
	printIntoFile("F wake up from waiting by event");

	printIntoFile("F start section 2/2");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "F";
		ioMutex.release();
	}
	printIntoFile("F finish section 2/2");

	ioMutex.acquire();
	cout << "\n *************   F Finish   *********************";
	ioMutex.release();
}

void g()
{
	ioMutex.acquire();
	cout << "\n *************   G Start    *********************";
	ioMutex.release();

	printIntoFile("G start section 1/2");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "G";
		ioMutex.release();
	}
	printIntoFile("G finish section 1/2");

	printIntoFile("G wait for event");
	char c;
	evCtoBG.wait(c);
	printIntoFile("G wake up from waiting by event");

	printIntoFile("G start section 2/2");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "G";
		ioMutex.release();
	}
	printIntoFile("G finish section 2/2");

	ioMutex.acquire();
	cout << "\n *************   G Finish   *********************";
	ioMutex.release();
}

void h()
{
	ioMutex.acquire();
	cout << "\n *************   H Start    *********************";
	ioMutex.release();

	printIntoFile("H start section 1/2");
	for (int j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "H";
		ioMutex.release();
	}
	printIntoFile("H finish section 1/2");

	printIntoFile("H wait for event");
	char c;
	evDtoCH.wait(c);
	printIntoFile("H wake up from waiting by event");

	printIntoFile("H start section 2/2");
	for (j = 0; j < 10; j++)
	{
		for (long i = 0; i < 200000; i++)
			;
		ioMutex.acquire();
		cout << "H";
		ioMutex.release();
	}
	printIntoFile("H finish section 2/2");

	ioMutex.acquire();
	cout << "\n *************   H Finish   *********************";
	ioMutex.release();
}

void main()
{
	clrscr();
	SMARTS.externalFunctions(timerInterruptHandler, scheduler, myTaskEnd, RMS);
	SMARTS.declareTask(a, 'A', 400, 3);
	SMARTS.declareTask(b, 'B', 402, 3);
	SMARTS.declareTask(c, 'C', 404, 3);
	SMARTS.declareTask(d, 'D', 406, 3);
	SMARTS.declareTask(e, 'E', 407, 3);

	SMARTS.declareTask(f, 'F', 401, 3);
	SMARTS.declareTask(g, 'G', 403, 3);
	SMARTS.declareTask(h, 'H', 405, 3);

	SMARTS.declareMutex(abMutex, 0);
	SMARTS.declareMutex(bcMutex, 0);
	SMARTS.declareMutex(cdMutex, 0);
	SMARTS.declareMutex(deMutex, 0);
	SMARTS.runTheTasks();
}

void printIntoFile(char *text)
{
	FILE *file = fopen("TEST2.txt", "a");
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
