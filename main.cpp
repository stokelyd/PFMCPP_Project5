/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

 Destructors
        
 0) move all of your implementations of all functions to OUTSIDE of the class. 
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

 3) add 2 new UDTs that use only the types you copied above as member variables.

 4) add 2 member functions that use your member variables to each of these new UDTs

 5) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 7) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <iostream>

/*
 copied UDT 1:
*/
struct BurgerShack
{
    int numBurgersServedPerDay, numToppingOptions, daysSinceGreaseTrapCleaned;
    float profitPerWeek { 745.32f }, beefUsedPerWeek { 47.5f };
    
    BurgerShack();
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

    Customer nextCustomerInLine;
};

// BurgerShack implementations
BurgerShack::BurgerShack() : numBurgersServedPerDay(576), numToppingOptions(12)
{
    daysSinceGreaseTrapCleaned = 2;
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
    int currentGreaseTrapStatus = daysSinceGreaseTrapCleaned;

    while (currentGreaseTrapStatus < cleaningThreshold)
    {
        currentGreaseTrapStatus++;

        if (currentGreaseTrapStatus >= cleaningThreshold)
        {
            daysSinceGreaseTrapCleaned += numDaysElapsed;
            return true;
        }
    }

    daysSinceGreaseTrapCleaned += numDaysElapsed;
    return false;    
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



/*
 copied UDT 2:
*/
struct FishingTrawler
{
    int numFishingNets, numCrewMembers;
    float amountOfFishCaughtPerDay, amountOfGasRemaining, distanceTraveledPerWeek;

    FishingTrawler();
    ~FishingTrawler();

    void pullInNet(int netId);
    void turnToPort(int degrees);
    void cleanBarnaclesFromHull(bool inDrydock);

    void setSailForNumDays(int numDaysToSailFor, float amountFuelUsedPerDay = 6.94f);
};

FishingTrawler::FishingTrawler() : numFishingNets(5), numCrewMembers(4), amountOfFishCaughtPerDay(323.4f)
{
    amountOfGasRemaining = 25.4f;
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



/*
 new UDT 4:
 with 2 member functions
*/

/*
 new UDT 5:
 with 2 member functions
*/

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
    std::cout << "good to go!" << std::endl;
}
