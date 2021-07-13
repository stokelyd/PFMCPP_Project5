#include "Wrappers.h"

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


