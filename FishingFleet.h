#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"
#include "FishingTrawler.h"

// struct FishingTrawler;

struct FishingFleet
{
    FishingTrawler trawler1{ 4, 3, 294.2f };
    FishingTrawler trawler2{ 6, 5, 423.4f };
    FishingTrawler trawler3;

    FishingFleet();
    ~FishingFleet();

    float calculateTotalWeeklyFishCaughtAmount();
    void sailFleet(int numDaysToSailFor);

    void printCalculateTotalWeeklyFishCaughtAmount();

    JUCE_LEAK_DETECTOR(FishingFleet)
};
