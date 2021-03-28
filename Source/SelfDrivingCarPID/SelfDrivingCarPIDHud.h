// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SelfDrivingCarPIDHud.generated.h"

UCLASS(config = Game)
class ASelfDrivingCarPIDHud : public AHUD
{
	GENERATED_BODY()

public:
	ASelfDrivingCarPIDHud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
