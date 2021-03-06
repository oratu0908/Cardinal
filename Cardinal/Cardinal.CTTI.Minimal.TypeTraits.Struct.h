#pragma once
#include "Cardinal.CTTI.Minimal.TypeTraits.Base.h"

#define DefStructFieldData(Struct, Name)                                       \
    Cardinal::CTTI::TypeTraits::Details::FieldTypeData<                        \
        Struct,                                                                \
        decltype(Struct::Name),                                                \
        (Cardinal::SizeT) StructOffsetOfMember(Struct, Name),                  \
        decltype(Cardinal::Details::CreateTypeStr(L"" #Name)),                 \
        []() constexpr { return Cardinal::Details::CreateTypeStr(L"" #Name); } \
    >(Cardinal::Details::CreateTypeStr(L"" #Name))

#define DefStructMetaDataObj(Struct, ...)                                      \
    Cardinal::CTTI::TypeTraits::Details::MakeCustomStruct<Struct>(__VA_ARGS__)

#define DefStructMetaData(Struct, ...)                                         \
    static constexpr auto FieldMetaData = DefStructMetaDataObj(Struct, __VA_ARGS__) 