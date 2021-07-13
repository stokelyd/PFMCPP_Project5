#include "SteamLocomotive.h"

SteamLocomotive::SteamLocomotive() : numCarsOnTrain(15), age(25)
{
    horsepower = 4532;
    numCrewMembers = 2;
}

SteamLocomotive::~SteamLocomotive()
{
    std::cout << "---->DTOR: SteamLocomotive\n";
}

void SteamLocomotive::detachFromCurrentTrainCar(bool warnCrew)
{
    if(warnCrew)
    {
        std::cout << "Warned the crew and..." << std::endl;
    }

    std::cout << "Detached the locomotive from the currently attached train car: " << (numCarsOnTrain - 1) << " cars remaining.\n";
}

void SteamLocomotive::addCoalToFurnace(float lbsCoalToAdd)
{
    std::cout << "Added " << lbsCoalToAdd << "lbs of coal to the furnace." << std::endl;
}

void SteamLocomotive::slamOnTheBrakes(int delayTime)
{
    std::cout << "After " << delayTime << " seconds, slammed on the brakes" << std::endl;
}

void SteamLocomotive::removeCarsFromTrain(int numCarsToRemove)
{
    for (int i = 0; i < numCarsToRemove; ++i)
    {
        if (numCarsOnTrain > 0)
        {
            --numCarsOnTrain;
            std::cout << "Removed the last car from the train, leaving a total of " << numCarsOnTrain << " remaining\n";
        }
        else
        {
            std::cout << "All of the train cars have been removed...\n";
            break;
        }
    }
}

void SteamLocomotive::printAge()
{
    std::cout << "The Local Service is " << this->age << " years old.\n";
}

void SteamLocomotive::printNumCarsOnTrain()
{
    std::cout << "There are " << this->numCarsOnTrain << " cars on this train.\n";
}
