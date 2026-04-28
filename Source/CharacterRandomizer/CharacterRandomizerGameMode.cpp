// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterRandomizerGameMode.h"
#include "Serialization/JsonSerializer.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

ACharacterRandomizerGameMode::ACharacterRandomizerGameMode() {

}
ACharacterRandomizerGameMode::~ACharacterRandomizerGameMode() {

}

void ACharacterRandomizerGameMode::BeginPlay()
{
	// Call the base class
	Super::BeginPlay();

	Http = &FHttpModule::Get();
}

void ACharacterRandomizerGameMode::HttpRequest()
{
	TSharedRef<IHttpRequest> Request = Http->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ACharacterRandomizerGameMode::OnResponseReceived);
	Request->SetURL("https://localhost:44373/api/avatar");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void ACharacterRandomizerGameMode::HttpResponse_Implementation()
{

}

void ACharacterRandomizerGameMode::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bConnectedSuccessfully)
{
	Succeed = bConnectedSuccessfully && Response.IsValid() && Response->GetResponseCode() == 200;

	if (Succeed) {
		TSharedPtr<FJsonObject> JsonObject;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(*Response->GetContentAsString());
		FJsonSerializer::Deserialize(Reader, JsonObject);
		UE_LOG(LogTemp, Display, TEXT("Response %s"), *Response->GetContentAsString());
		UE_LOG(LogTemp, Display, TEXT("TestParam %s"), *JsonObject->GetStringField(TEXT("SkinColorInt")));

		ACharacterRandomizerGameMode::Succeed = true;
		ACharacterRandomizerGameMode::SkinColorInt = JsonObject->GetIntegerField(TEXT("SkinColorInt"));
		ACharacterRandomizerGameMode::UpperBodyInt = JsonObject->GetIntegerField(TEXT("UpperBodyInt"));
		ACharacterRandomizerGameMode::LowerBodyInt = JsonObject->GetIntegerField(TEXT("LowerBodyInt"));
		ACharacterRandomizerGameMode::EyesColorInt = JsonObject->GetIntegerField(TEXT("EyesColorInt"));
		ACharacterRandomizerGameMode::HairStyleInt = JsonObject->GetIntegerField(TEXT("HairStyleInt"));
		ACharacterRandomizerGameMode::HairColorInt = JsonObject->GetIntegerField(TEXT("HairColorInt"));
		ACharacterRandomizerGameMode::HandsInt = JsonObject->GetIntegerField(TEXT("HandsInt"));
		ACharacterRandomizerGameMode::FeetInt = JsonObject->GetIntegerField(TEXT("FeetInt"));
		ACharacterRandomizerGameMode::BodyTypeFloat = JsonObject->GetNumberField(TEXT("BodyTypeFloat"));

	}
	HttpResponse();
}