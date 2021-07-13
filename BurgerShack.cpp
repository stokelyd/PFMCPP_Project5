#include "BurgerShack.h"

BurgerShack::BurgerShack() : BurgerShack(576, 745.32f, 47.5f)
{
    daysSinceGreaseTrapCleaned = 2;
}

BurgerShack::BurgerShack(int numDailyBurgersServed, float weeklyProfit, float weeklyBeefUsed) :
numBurgersServedPerDay(numDailyBurgersServed), profitPerWeek(weeklyProfit), beefUsedPerWeek(weeklyBeefUsed)
{
    daysSinceGreaseTrapCleaned = 0;
    numToppingOptions = 12;
}

BurgerShack::~BurgerShack()
{
    std::cout << "---->DTOR: BurgerShack\n";
}

void BurgerShack::serveBurger(Customer customer, bool withFries)
{
    std::cout << "Served burger to " << customer.name << std::endl;
    if(withFries)
    {
        std::cout << "with a side of fries" << std::endl;
    }
}

float BurgerShack::chargeCustomer(Customer customer, float discountPercentage)
{
    float costOfMeal = 5.75f;
    float amountToCharge = costOfMeal - (costOfMeal * discountPercentage);

    std::cout << "Charged " << customer.name << amountToCharge << "dollars";
    return amountToCharge;
}

void BurgerShack::cleanGrill(bool extraMessToClean)
{
    std::cout << "Cleaned the grill..." << std::endl;

    if(extraMessToClean)
    {
        std::cout << "...it was really gross, probably because the shack uses " << beefUsedPerWeek << "lbs of meat per week." << std::endl;   
    }
}

bool BurgerShack::isItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed)
{
    int currentGreaseTrapStatus = daysSinceGreaseTrapCleaned + numDaysElapsed;
    daysSinceGreaseTrapCleaned += numDaysElapsed;

    if (currentGreaseTrapStatus >= cleaningThreshold)
    {
        return true;
    }
    return false;    
}

void BurgerShack::printNumBurgersServedPerDay()
{
    std::cout << "The first burger shack serves " << this->numBurgersServedPerDay << " burgers each day.\n";
}

void BurgerShack::printIsItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed)
{
    std::cout << "Is it time to clean the grease trap?\n" << (this->isItTimeToCleanTheGreaseTrap(cleaningThreshold, numDaysElapsed) ? "YES" : "NO") << ": it has been " << this->daysSinceGreaseTrapCleaned << " days.\n";
}


// Customer implementations
BurgerShack::Customer::Customer() : customerNumber(27)
{
    tipPercentage = 0.15f;
    dollarsInWallet = 53.24f;
}

void BurgerShack::Customer::payForMeal(float amountOwed, bool tip)
{
    if(tip)
    {
        amountOwed += amountOwed * 0.15f;
    }

    std::cout << "Paid " << amountOwed << "dollars" << std::endl;
}

float BurgerShack::Customer::checkHowMuchSodaLeftInCup(bool removeLid)
{
    float estimatedAmountOfSodaLeft = removeLid ? 0.231f : 0.25f;

    return estimatedAmountOfSodaLeft;
}

void BurgerShack::Customer::getExtraNapkins(int numNapkins)
{
    std::cout << "Got " << numNapkins << " extra napkins" << std::endl;
}
