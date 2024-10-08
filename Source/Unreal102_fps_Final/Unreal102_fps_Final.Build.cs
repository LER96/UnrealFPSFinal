// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Unreal102_fps_Final : ModuleRules
{
	public Unreal102_fps_Final(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
