#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct FishingTrawler
{
    int numFishingNets, numCrewMembers;
    float amountOfFishCaughtPerDay, amountOfGasRemaining, distanceTraveledPerWeek;

    FishingTrawler();
    FishingTrawler(int numNets, int numCrew, float fishCaughtPerDay);
    ~FishingTrawler();

    void pullInNet(int netId);
    void turnToPort(int degrees);
    void cleanBarnaclesFromHull(bool inDrydock);
    void setSailForNumDays(int numDaysToSailFor, float amountFuelUsedPerDay = 6.94f);

    void printAmountOfGasRemaining();

    JUCE_LEAK_DETECTOR(FishingTrawler)
};
