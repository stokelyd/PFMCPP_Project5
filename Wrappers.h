#pragma once

#include "BurgerShack.h"
#include "FishingTrawler.h"
#include "SteamLocomotive.h"
#include "BurgerChain.h"
#include "FishingFleet.h"

struct BurgerShackWrapper
{
    BurgerShackWrapper( BurgerShack* ptr );
    ~BurgerShackWrapper();

    BurgerShack* pointerToBurgerShack = nullptr;
};

struct FishingTrawlerWrapper
{
    FishingTrawlerWrapper( FishingTrawler* ptr );
    ~FishingTrawlerWrapper();

    FishingTrawler* pointerToFishingTrawler = nullptr;
};

struct SteamLocomotiveWrapper
{
    SteamLocomotiveWrapper( SteamLocomotive* ptr );
    ~SteamLocomotiveWrapper();

    SteamLocomotive* pointerToSteamLocomotive = nullptr;
};

struct BurgerChainWrapper
{
    BurgerChainWrapper( BurgerChain* ptr );
    ~BurgerChainWrapper();

    BurgerChain* pointerToBurgerChain = nullptr;
};

struct FishingFleetWrapper
{
    FishingFleetWrapper( FishingFleet* ptr );
    ~FishingFleetWrapper();

    FishingFleet* pointerToFishingFleet = nullptr;
};
