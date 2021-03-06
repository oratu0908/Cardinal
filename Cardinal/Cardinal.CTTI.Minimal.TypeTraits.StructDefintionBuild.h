#pragma once
#include "Cardinal.CTTI.Minimal.TypeTraits.Base.h"
#include "Cardinal.CTTI.Minimal.TypeTraits.Struct.h"

#define StructCttiDef(StructName, ...)                                     \
	constexpr static auto FieldMetaDataGetter()                            \
	{                                                                      \
		auto FieldMetaData = DefStructMetaDataObj(StructName,__VA_ARGS__); \
		return FieldMetaData;                                              \
	}