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

#include "BurgerChain.h"
#include "BurgerShack.h"
#include "FishingFleet.h"
#include "FishingTrawler.h"
#include "SteamLocomotive.h"
#include "Wrappers.h"

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


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
