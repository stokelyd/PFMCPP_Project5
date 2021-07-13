#include "FishingTrawler.h"

FishingTrawler::FishingTrawler() : FishingTrawler(5, 4, 323.4f)
{
    amountOfGasRemaining = 25.4f;
    distanceTraveledPerWeek = 134.3f;
}

FishingTrawler::FishingTrawler(int numNets, int numCrew, float fishCaughtPerDay) :
numFishingNets(numNets), numCrewMembers(numCrew), amountOfFishCaughtPerDay(fishCaughtPerDay)
{
    amountOfGasRemaining = 150.f;
    distanceTraveledPerWeek = 134.3f;
}

FishingTrawler::~FishingTrawler()
{
    std::cout << "---->DTOR: FishingTrawler\n";
}

void FishingTrawler::pullInNet(int netId)
{
    std::cout << "Pulled in net #" << netId << " out of " << numFishingNets << " total fishing nets." << std::endl;
}

void FishingTrawler::turnToPort(int degrees)
{
    std::cout << "Turned " << degrees << " degrees to port";
}

void FishingTrawler::cleanBarnaclesFromHull(bool inDrydock)
{
    std::cout << "Cleaned the barnacles off of the hull" << std::endl;

    if(inDrydock)
    {
        std::cout << "(very thoroughly, b/c the boat was in drydock)";
    }
}

void FishingTrawler::setSailForNumDays(int numDaysToSailFor, float amountFuelUsedPerDay)
{
    float totalNumFishCaught = 0.f;

    for (int i = 1; i <= numDaysToSailFor; ++i)
    {
        if (amountOfGasRemaining >= amountFuelUsedPerDay)
        {
            amountOfGasRemaining -= amountFuelUsedPerDay;
            totalNumFishCaught += amountOfFishCaughtPerDay;

            std::cout << "Day " << i << ": Caught " << amountOfFishCaughtPerDay << "lbs of fish today, for a total of " << totalNumFishCaught << "lbs.\n";
        }
        else
        {
            std::cout << "Out of gas...\n";
            break;
        }
    }

    std::cout << "In total, caught " << totalNumFishCaught << "lbs of fish.\n";
}

void FishingTrawler::printAmountOfGasRemaining()
{
    std::cout << "The second trawler has " << this->amountOfGasRemaining << " gallons of fuel remaining.\n";
}
