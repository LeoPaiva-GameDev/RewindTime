// Code by Leonardo Paiva


#include "RewindActors.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ARewindActors::ARewindActors()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ARewindTimeCharacter Character = Cast<ARewindTimeCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ARewindActors::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	FinalLocation.Add(InitialLocation);
}

// Called every frame
void ARewindActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ActualLocation = GetActorLocation();
	
	if(ActualLocation != FinalLocation.Last())
	{
		FinalLocation.Add(ActualLocation);
	}

	if(Character)
	{
		if(Character->bIsRewinding == true)
		{
			Rewind();
		}
	}
	
}

void ARewindActors::Rewind()
{
	if(ActualLocation != InitialLocation)
	{
		for(int32 i = FinalLocation.Num(); i >= 0; i--)
		{
			//Mesh->GetOwner()->SetActorLocation(FinalLocation[i]);
			SetActorLocation(FinalLocation[i]);
		}
	}
}
