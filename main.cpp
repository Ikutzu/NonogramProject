#include "Nonogrammap.h"
#include "NonogramSolver.h"

int main()
{
	Nonogrammap test(10, 10);
	NonogramSolver testi(&test);

	test.printAnswer();

	testi.SolvePuzzle();
	testi.PrintSolution();

 	system("PAUSE");

	return 0;
}