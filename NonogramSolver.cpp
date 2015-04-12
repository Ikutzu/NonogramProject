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

	//päivitä reunavektorit

	while (unSolved > 0)
	{
		// 2. vertaile serialien määrää
			// hae ensimmäinen täytetty jonka jälkeen hae ensimmäinen tyhjä ja täytä
			// seruaavaan täytettyyn asti

		//päivitä reunavektorit
		
		// 3. vartaile omien reunavektoreiden serial arvoja mapin vastaaviin
			// onko määrä sama? tai onko oma serial arvo sama kuin mapin isoin serial arvo
			// onko samoja serialeja (samassa kohdassa)?
				// aseta reunat EMPTYksi (tarkista ettei mapin ulkopuolella)
		
		// päivitä reunavektorit

		// 4. jos omien ja mapin serialien määrä sama, ja omia serialeja vain yksi ratkaisematta
			// kokorivin UNKNOWNit -> EMPTY. 
			// laske mapin serial - oma serial = erotus
			// etsi serialia vastaava rypäs, ensimmäinen FILLED ja sen koordinaatti ( X ) minus erotus 
			// välinen alue asetetaan UNKNOWN, viimeinen FILLED koordinaatti ja X + map serial 
			// välinen alue asetetaan UNKNOWN
			// muista tarkistaa ettei mennä vektori rajojen ulkopuolelle

		// päivitä reunavektorit

		// 5. pitäis miettiä logiikka uusiksi ja tarkemmin niin että se toimii aina eikä tuu virheitä
	
	

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