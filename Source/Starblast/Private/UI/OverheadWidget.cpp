// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(const FString& TextToDisplay)
{
	if (!DisplayText) return;

	DisplayText->SetText(FText::FromString(TextToDisplay));
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	const ENetRole RemoteRole = InPawn->GetRemoteRole();
	const ENetRole LocalRole = InPawn->GetLocalRole();
	FString RRole;
	switch (RemoteRole)
	{
	case ROLE_Authority:
		RRole = FString("Authority");
		break;
	case ROLE_AutonomousProxy:
		RRole = FString("Autonomous Proxy");
		break;
	case ROLE_SimulatedProxy:
		RRole = FString("Simulated Proxy");
		break;
	case ROLE_None:
	default:
		RRole = FString("None");
	}
	FString LRole;
	switch (LocalRole)
	{
	case ROLE_Authority:
		LRole = FString("Authority");
		break;
	case ROLE_AutonomousProxy:
		LRole = FString("Autonomous Proxy");
		break;
	case ROLE_SimulatedProxy:
		LRole = FString("Simulated Proxy");
		break;
	case ROLE_None:
	default:
		LRole = FString("None");
	}

	const FString RemoteRoleString = FString::Printf(TEXT(
		"Remote Role: %s\n"
		"Local Role: %s"
		),
		*RRole,
		*LRole
	);
	SetDisplayText(RemoteRoleString);
}
