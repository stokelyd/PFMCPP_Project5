#include "BurgerChain.h"

BurgerChain::BurgerChain()
{
    std::cout << "-->CTOR: BurgerChain\n";
    float totalWeeklyBeefNeeded = franchisedBurgerShack1.beefUsedPerWeek + franchisedBurgerShack2.beefUsedPerWeek + franchisedBurgerShack3.beefUsedPerWeek;
    std::cout << "Expected amount of beef needed this week: " << totalWeeklyBeefNeeded << "lbs.\n\n";
}

BurgerChain::~BurgerChain()
{
    std::cout << "-->DTOR: BurgerChain\n";
    franchisedBurgerShack1.cleanGrill(true);
    franchisedBurgerShack2.cleanGrill(true);
    franchisedBurgerShack3.cleanGrill(true);
}

float BurgerChain::tallyWeeklyProfits()
{
    float totalWeeklyProfit = 0.f;

    totalWeeklyProfit += franchisedBurgerShack1.profitPerWeek;
    totalWeeklyProfit += franchisedBurgerShack2.profitPerWeek;
    totalWeeklyProfit += franchisedBurgerShack3.profitPerWeek;

    return totalWeeklyProfit;
}

void BurgerChain::addNewToppingOption(int numToppingsToAdd = 1)
{
    franchisedBurgerShack1.numToppingOptions += numToppingsToAdd;
    franchisedBurgerShack2.numToppingOptions += numToppingsToAdd;
    franchisedBurgerShack3.numToppingOptions += numToppingsToAdd;

    std::cout << "Updated number of toppings available to " << franchisedBurgerShack1.numToppingOptions << std::endl;
}

void BurgerChain::printTallyWeeklyProfits()
{
    std::cout << "Total weekly profit of this Burger Chain is: $" << this->tallyWeeklyProfits() << std::endl;
}
