#pragma once
#include "Cardinal.CTTI.Minimal.TypeTraits.Base.h"

/// <summary>
/// The meta description for the enumeration type
/// </summary>
/// <param name="Type">The enumeration type</param>
/// <param name="...">The enumeration value</param>
#define EnumCttiDefinition(Type, ...)                                                                         \
export template<>																			                  \
struct __identifier(enum)<Type>: Cardinal::TypeTraits::LogicTrue {                                            \
	static constexpr auto Data = Cardinal::CTTI::TypeTraits::Details::EnumDefinitionT<Type, __VA_ARGS__>{};   \
	static constexpr SizeT DataCount = COUNT_ARGUMENTS(__VA_ARGS__);                                          \
}