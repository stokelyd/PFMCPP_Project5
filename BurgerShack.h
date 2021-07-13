#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct BurgerShack
{
    int numBurgersServedPerDay, numToppingOptions, daysSinceGreaseTrapCleaned;
    float profitPerWeek, beefUsedPerWeek;
    
    BurgerShack();
    BurgerShack(int numDailyBurgersServed, float weeklyProfit, float weeklyBeefUsed);
    ~BurgerShack();

    struct Customer
    {
        std::string name = "Dave";
        bool isRegularCustomer = false;
        int customerNumber;
        float tipPercentage, dollarsInWallet;

        Customer();

        void payForMeal(float amountOwed, bool tip = true);
        float checkHowMuchSodaLeftInCup(bool removeLid = false);
        void getExtraNapkins(int numNapkins);
    };

    void serveBurger(Customer customer, bool withFries);
    float chargeCustomer(Customer customer, float discountPercentage);
    void cleanGrill(bool extraMessToClean);
    bool isItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed = 7);

    void printNumBurgersServedPerDay();
    void printIsItTimeToCleanTheGreaseTrap(int cleaningThreshold, int numDaysElapsed = 7);

    Customer nextCustomerInLine;

    JUCE_LEAK_DETECTOR(BurgerShack)
};
