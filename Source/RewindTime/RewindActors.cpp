// Code by Leonardo Paiva


#include "RewindActors.h"

// Sets default values
ARewindActors::ARewindActors()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARewindActors::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = Mesh->GetOwner()->GetActorLocation();

	FinalLocation[0] = InitialLocation;
}

// Called every frame
void ARewindActors::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ActualLocation = Mesh->GetOwner()->GetActorLocation();
	
	if(ActualLocation != FinalLocation.Last())
	{
		FinalLocation.Add(ActualLocation);
	}

	if(Character->bIsRewinding == true)
	{
		Rewind();
	}
}

void ARewindActors::Rewind()
{
	while (ActualLocation != InitialLocation)
	{
		for(int32 i = FinalLocation.Num(); i >= 0; i--)
		{
			Mesh->GetOwner()->SetActorLocation(FinalLocation[i]);
		}
	}
}

