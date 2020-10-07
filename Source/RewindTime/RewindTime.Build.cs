// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RewindTime : ModuleRules
{
	public RewindTime(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
