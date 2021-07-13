#include "Wrappers.h"

// struct BurgerShack;
// struct FishingTrawler;
// struct SteamLocomotive;
// struct BurgerChain;
// struct FishingFleet;

#include "BurgerShack.h"
#include "FishingTrawler.h"
#include "SteamLocomotive.h"
#include "BurgerChain.h"
#include "FishingFleet.h"


/*
 BurgerShackWrapper
*/
BurgerShackWrapper::BurgerShackWrapper( BurgerShack* ptr ) : 
    pointerToBurgerShack( ptr ) 
{
}

BurgerShackWrapper::~BurgerShackWrapper()
{
    delete pointerToBurgerShack;
}

/*
 FishingTrawlerWrapper
*/
FishingTrawlerWrapper::FishingTrawlerWrapper( FishingTrawler* ptr ) : 
    pointerToFishingTrawler(ptr) 
{ 
}

FishingTrawlerWrapper::~FishingTrawlerWrapper()
{
    delete pointerToFishingTrawler;
}

// FishingTrawler* pointerToFishingTrawler = nullptr;


/*
 SteamLocomotiveWrapper
*/
SteamLocomotiveWrapper::SteamLocomotiveWrapper( SteamLocomotive* ptr ) : 
    pointerToSteamLocomotive( ptr ) 
{
}

SteamLocomotiveWrapper::~SteamLocomotiveWrapper()
{
    delete pointerToSteamLocomotive;
}

// pointerToSteamLocomotive = nullptr;

/*
 BurgerChainWrapper
*/
BurgerChainWrapper::BurgerChainWrapper( BurgerChain* ptr ) : 
    pointerToBurgerChain( ptr ) 
{
}

BurgerChainWrapper::~BurgerChainWrapper()
{
    delete pointerToBurgerChain;
}

// // BurgerChain* pointerToBurgerChain = nullptr;

// /*
//  FishingFleetWrapper
// */
FishingFleetWrapper::FishingFleetWrapper( FishingFleet* ptr ) : 
    pointerToFishingFleet( ptr ) 
{
}

FishingFleetWrapper::~FishingFleetWrapper()
{
    delete pointerToFishingFleet;
}

// FishingFleet* pointerToFishingFleet = nullptr;

