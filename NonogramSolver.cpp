#include "NonogramSolver.h"


NonogramSolver::NonogramSolver(Nonogrammap* puzzleToSolve)
{
	puzzle = puzzleToSolve;
	unSolved = puzzle->getCount();
	
	for (int x = 0; x < puzzle->getWidth(); x++)
	{
		std::vector<state> tempRow;
		for (int y = 0; y < puzzle->getHeight(); x++)
		{
			tempRow.push_back(UNKNOWN);
		}
		column.push_back(tempRow);
	}
}

void NonogramSolver::solvePuzzle()
{
	// 1. laske varmat

	//p�ivit� reunavektorit

	while (unSolved > 0)
	{
		// 2. vertaile serialien m��r��
			// hae ensimm�inen t�ytetty jonka j�lkeen hae ensimm�inen tyhj� ja t�yt�
			// seruaavaan t�ytettyyn asti

		//p�ivit� reunavektorit
		
		// 3. vartaile omien reunavektoreiden serial arvoja mapin vastaaviin
			// onko m��r� sama? tai onko oma serial arvo sama kuin mapin isoin serial arvo
			// onko samoja serialeja (samassa kohdassa)?
				// aseta reunat EMPTYksi (tarkista ettei mapin ulkopuolella)
		
		// p�ivit� reunavektorit

		// 4. jos omien ja mapin serialien m��r� sama, ja omia serialeja vain yksi ratkaisematta
			// kokorivin UNKNOWNit -> EMPTY. 
			// laske mapin serial - oma serial = erotus
			// etsi serialia vastaava ryp�s, ensimm�inen FILLED ja sen koordinaatti ( X ) minus erotus 
			// v�linen alue asetetaan UNKNOWN, viimeinen FILLED koordinaatti ja X + map serial 
			// v�linen alue asetetaan UNKNOWN
			// muista tarkistaa ettei menn� vektori rajojen ulkopuolelle

		// p�ivit� reunavektorit

		// 5. pit�is mietti� logiikka uusiksi ja tarkemmin niin ett� se toimii aina eik� tuu virheit�
	
	

	}
}

// private

void NonogramSolver::CalculateBetween(std::vector<int> unsolvedSeries, int between)
{
	for (int i = 0; i < unsolvedSeries.size(); i++)
	{
		int tempOverflow = AddUpSeries(unsolvedSeries, unsolvedSeries[i]);
		if (tempOverflow > between)
		{

		}

	}


}

int NonogramSolver::AddUpSeries(std::vector<int> series, int currentSerial)
{
	int tempAddedSeries = 0;

	for (int i = 0; i < series.size(); i++)
	{
		tempAddedSeries += series[i];
	}

	tempAddedSeries += series.size() - 1;
	tempAddedSeries += series.at(currentSerial);

	return tempAddedSeries;
}