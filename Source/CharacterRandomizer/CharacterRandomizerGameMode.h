// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "Json.h"
#include "CharacterRandomizerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CHARACTERRANDOMIZER_API ACharacterRandomizerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    FHttpModule* Http;

    UPROPERTY(BlueprintReadOnly) bool Succeed = false;
    UPROPERTY(BlueprintReadWrite) int SkinColorInt = 0;
    UPROPERTY(BlueprintReadWrite) int UpperBodyInt = 0;
    UPROPERTY(BlueprintReadWrite) int LowerBodyInt = 0;
    UPROPERTY(BlueprintReadWrite) int EyesColorInt = 0;
    UPROPERTY(BlueprintReadWrite) int HairStyleInt = 0;
    UPROPERTY(BlueprintReadWrite) int HairColorInt = 0;
    UPROPERTY(BlueprintReadWrite) int HandsInt = 0;
    UPROPERTY(BlueprintReadWrite) int FeetInt = 0;
    UPROPERTY(BlueprintReadWrite) float BodyTypeFloat = 0;

    UFUNCTION(BlueprintCallable, category = "Http Request")
        void HttpRequest();

    UFUNCTION(BlueprintNativeEvent, category = "Http Request")
        void HttpResponse();

    virtual void BeginPlay() override;

    ACharacterRandomizerGameMode();
    ~ACharacterRandomizerGameMode();

private:
    void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully);
	
};
