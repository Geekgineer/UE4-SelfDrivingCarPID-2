// Copyright Epic Games, Inc. All Rights Reserved.

#include "SelfDrivingCarPIDGameMode.h"
#include "SelfDrivingCarPIDPawn.h"
#include "SelfDrivingCarPIDHud.h"

ASelfDrivingCarPIDGameMode::ASelfDrivingCarPIDGameMode()
{
	DefaultPawnClass = ASelfDrivingCarPIDPawn::StaticClass();
	HUDClass = ASelfDrivingCarPIDHud::StaticClass();
}
