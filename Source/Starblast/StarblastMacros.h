#pragma once

#include "Starblast/StarLogChannels.h"

#define GUARD(Condition, ReturnValue, ...) \
if (!Condition) \
{ \
	const FString FunctionName = __FUNCTION__; \
	UE_LOG(LogStarblast, Error, TEXT("[%s]: " __VA_ARGS__), *FunctionName); \
	return ReturnValue; \
}
