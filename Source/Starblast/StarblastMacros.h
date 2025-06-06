#pragma once

#include "Starblast/StarLogChannels.h"

#define GUARD(Condition, ReturnValue, Format, ...) \
if (!(Condition)) \
{ \
	const FString FunctionName = __FUNCTION__; \
	UE_LOG(LogStarblast, Error, TEXT("[%s]: ") Format, *FunctionName, ##__VA_ARGS__); \
	return ReturnValue; \
}
