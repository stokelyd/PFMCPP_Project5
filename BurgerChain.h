#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"
#include "BurgerShack.h"
// struct BurgerShack;

struct BurgerChain
{
    BurgerShack franchisedBurgerShack1{ 436, 623.12f, 40.5f };
    BurgerShack franchisedBurgerShack2{ 476, 712.23f, 56.21f };
    BurgerShack franchisedBurgerShack3{ 643, 924.82f, 75.64f };

    BurgerChain();
    ~BurgerChain();

    float tallyWeeklyProfits();
    void addNewToppingOption(int numToppingsToAdd);
    void printTallyWeeklyProfits();

    JUCE_LEAK_DETECTOR(BurgerChain)
};
