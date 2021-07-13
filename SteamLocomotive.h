#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct SteamLocomotive
{
    int numCarsOnTrain, age, horsepower, numCrewMembers;
    float amountOfCoalUsedPerDay { 7.5f };

    SteamLocomotive();
    ~SteamLocomotive();

    void detachFromCurrentTrainCar(bool warnCrew);
    void addCoalToFurnace(float lbsCoalToAdd);
    void slamOnTheBrakes(int delayTime);
    void removeCarsFromTrain(int numCarsToRemove);
    
    void printAge();
    void printNumCarsOnTrain();

    JUCE_LEAK_DETECTOR(SteamLocomotive)
};
