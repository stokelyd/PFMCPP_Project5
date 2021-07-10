/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */




#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
*/
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

// BurgerShack implementations
BurgerShack::BurgerShack() : 
numBurgersServedPerDay(576), numToppingOptions(12), profitPerWeek(745.32f), beefUsedPerWeek(47.5f)
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


struct BurgerShackWrapper
{
    BurgerShackWrapper( BurgerShack* ptr ) : pointerToBurgerShack( ptr ) { }
    ~BurgerShackWrapper()
    {
        delete pointerToBurgerShack;
    }

    BurgerShack* pointerToBurgerShack = nullptr;
};



/*
 copied UDT 2:
*/
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

FishingTrawler::FishingTrawler() : numFishingNets(5), numCrewMembers(4), amountOfFishCaughtPerDay(323.4f)
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


struct FishingTrawlerWrapper
{
    FishingTrawlerWrapper( FishingTrawler* ptr ) : pointerToFishingTrawler(ptr) { }
    ~FishingTrawlerWrapper()
    {
        delete pointerToFishingTrawler;
    }

    FishingTrawler* pointerToFishingTrawler = nullptr;
};



/*
 copied UDT 3:
*/
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


struct SteamLocomotiveWrapper
{
    SteamLocomotiveWrapper( SteamLocomotive* ptr ) : pointerToSteamLocomotive( ptr ) { }
    ~SteamLocomotiveWrapper()
    {
        delete pointerToSteamLocomotive;
    }

    SteamLocomotive* pointerToSteamLocomotive = nullptr;
};



/*
 new UDT 4:
 with 2 member functions
*/
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


struct BurgerChainWrapper
{
    BurgerChainWrapper( BurgerChain* ptr ) : pointerToBurgerChain( ptr ) { }
    ~BurgerChainWrapper()
    {
        delete pointerToBurgerChain;
    }

    BurgerChain* pointerToBurgerChain = nullptr;
};



/*
 new UDT 5:
 with 2 member functions
*/
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


struct FishingFleetWrapper
{
    FishingFleetWrapper( FishingFleet* ptr ) : pointerToFishingFleet( ptr ) { }
    ~FishingFleetWrapper()
    {
        delete pointerToFishingFleet;
    }

    FishingFleet* pointerToFishingFleet = nullptr;
};



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>

void printDivider(int numToPrint = 1)
{
    for (int i = 0; i < numToPrint; ++i)
    {
        std::cout << "-----------------------------------------------\n"; 
    }
}

int main()
{
    /*
     Task 5.3-5: instantiate and call UDTs using wrapper classes
    */
    BurgerShackWrapper firstBurgerShack( new BurgerShack() );
    BurgerShackWrapper secondBurgerShack( new BurgerShack() );
    FishingTrawlerWrapper trawler1( new FishingTrawler() );
    FishingTrawlerWrapper trawler2( new FishingTrawler() );
    SteamLocomotiveWrapper transCanada( new SteamLocomotive() );
    SteamLocomotiveWrapper localService( new SteamLocomotive() );
    BurgerChainWrapper familyBurger( new BurgerChain() );
    FishingFleetWrapper pacificCatch( new FishingFleet() );

    // calling member functions
    std::cout << "TASK 3.3-4\n";
    firstBurgerShack.pointerToBurgerShack->cleanGrill(true);
    printDivider();
    trawler1.pointerToFishingTrawler->pullInNet(4);
    printDivider();
    localService.pointerToSteamLocomotive->addCoalToFurnace(32.3f);
    printDivider();

    // print member variables/return values
    std::cout << "TASK 3.3-5\n";
    std::cout << "The first burger shack serves " << firstBurgerShack.pointerToBurgerShack->numBurgersServedPerDay << " burgers each day.\n"; 
    firstBurgerShack.pointerToBurgerShack->printNumBurgersServedPerDay();
    printDivider();
    std::cout << "The second trawler has " << trawler2.pointerToFishingTrawler->amountOfGasRemaining << " gallons of fuel remaining.\n";
    trawler2.pointerToFishingTrawler->printAmountOfGasRemaining();
    printDivider();
    std::cout << "The Local Service is " << localService.pointerToSteamLocomotive->age << " years old.\n";
    localService.pointerToSteamLocomotive->printAge();
    printDivider();
    
    // calls to looping member functions
    std::cout << "TASK 3.5-4\n";
    std::cout << "Is it time to clean the grease trap?\n" << (firstBurgerShack.pointerToBurgerShack->isItTimeToCleanTheGreaseTrap(6, 5) ? "YES" : "NO") << ": it has been " << firstBurgerShack.pointerToBurgerShack->daysSinceGreaseTrapCleaned << " days.\n";
    firstBurgerShack.pointerToBurgerShack->printIsItTimeToCleanTheGreaseTrap(6, 5);
    printDivider();
    trawler2.pointerToFishingTrawler->setSailForNumDays(5);
    std::cout << "Fuel remaining: " << trawler2.pointerToFishingTrawler->amountOfGasRemaining << " gallons.\n";
    trawler2.pointerToFishingTrawler->printAmountOfGasRemaining();
    printDivider();
    localService.pointerToSteamLocomotive->removeCarsFromTrain(5);
    std::cout << "There are " << localService.pointerToSteamLocomotive->numCarsOnTrain << " cars on this train.\n";
    localService.pointerToSteamLocomotive->printNumCarsOnTrain();
    printDivider(3);

    std::cout << "TASK 5.1-7\n";
    std::cout << "Total weekly profit of this Burger Chain is: $" << familyBurger.pointerToBurgerChain->tallyWeeklyProfits() << std::endl;
    familyBurger.pointerToBurgerChain->printTallyWeeklyProfits();
    familyBurger.pointerToBurgerChain->addNewToppingOption(3);
    printDivider();

    std::cout << "Total amount of fish caught per week: " << pacificCatch.pointerToFishingFleet->calculateTotalWeeklyFishCaughtAmount() << "lbs.\n";
    pacificCatch.pointerToFishingFleet->printCalculateTotalWeeklyFishCaughtAmount();
    pacificCatch.pointerToFishingFleet->sailFleet(4);

    printDivider();
    std::cout << "good to go!" << std::endl;
    printDivider();
}
