#include "FishingFleet.h"
// #include "FishingTrawler.h"

FishingFleet::FishingFleet()
{
    std::cout << "-->CTOR: FishingFleet\n";

    if (trawler1.amountOfGasRemaining < 150.f)
        std::cout << "Trawler 1 needs fuel before leaving port...\n";

    if (trawler2.amountOfGasRemaining < 150.f)
        std::cout << "Trawler 2 needs fuel before leaving port...\n";
    
    if (trawler3.amountOfGasRemaining < 150.f)
        std::cout << "Trawler 3 needs fuel before leaving port...\n";

    std::cout << "\n";
}

FishingFleet::~FishingFleet()
{
    std::cout << "-->DTOR: FishingFleet\n";
    trawler1.cleanBarnaclesFromHull(false);
    trawler2.cleanBarnaclesFromHull(false);
    trawler3.cleanBarnaclesFromHull(false);
}

float FishingFleet::calculateTotalWeeklyFishCaughtAmount()
{
    float totalAmountWeeklyFishCaught = 0.f;

    totalAmountWeeklyFishCaught += trawler1.amountOfFishCaughtPerDay * 7.f;
    totalAmountWeeklyFishCaught += trawler2.amountOfFishCaughtPerDay * 7.f;
    totalAmountWeeklyFishCaught += trawler3.amountOfFishCaughtPerDay * 7.f;

    return totalAmountWeeklyFishCaught;
}

void FishingFleet::sailFleet(int numDaysToSailFor)
{
    std::cout << "Putting the fishing fleet to sea...\n";
    trawler1.setSailForNumDays(numDaysToSailFor);
    std::cout << trawler1.amountOfGasRemaining << " gallons of fuel remaining.\n\n";
    trawler2.setSailForNumDays(numDaysToSailFor);
    std::cout << trawler2.amountOfGasRemaining << " gallons of fuel remaining.\n\n";
    trawler3.setSailForNumDays(numDaysToSailFor);
    std::cout << trawler3.amountOfGasRemaining << " gallons of fuel remaining.\n\n";
}

void FishingFleet::printCalculateTotalWeeklyFishCaughtAmount()
{
    std::cout << "Total amount of fish caught per week: " << this->calculateTotalWeeklyFishCaughtAmount() << "lbs.\n";
}
