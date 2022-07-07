export module Cardinal.Core:Interlocked;

import :Types;
import :TypeTraits;
import :Concepts;

namespace Cardinal::Core::Internals
{
#pragma region Intrisc definition
	extern "C" {
		long _InterlockedAdd(
			long volatile* Addend,
			long Value
		);

		__int64 _InterlockedAdd64(
			__int64 volatile* Addend,
			__int64 Value
		);

		short _InterlockedIncrement16(
			volatile short* lpAddend
		);

		long _InterlockedIncrement(
			volatile long* lpAddend
		);

		__int64 _InterlockedIncrement64(
			volatile __int64* lpAddend
		);

		long _InterlockedDecrement(
			volatile long* lpAddend
		);

		short _InterlockedDecrement16(
			volatile short* lpAddend
		);

		__int64 _InterlockedDecrement64(
			volatile __int64* lpAddend
		);

		char _InterlockedCompareExchange8(
			char volatile* destination,
			char exchange,
			char comperand
		);

		short _InterlockedCompareExchange16(
			short volatile* destination,
			short exchange,
			short comperand
		);

		long _InterlockedCompareExchange(
			long volatile* destination,
			long exchange,
			long comperand
		);

		__int64 _InterlockedCompareExchange64(
			__int64 volatile* destination,
			__int64 exchange,
			__int64 comperand
		);

		char _InterlockedExchange8(
			char volatile* Target,
			char Value
		);

		short _InterlockedExchange16(
			short volatile* Target,
			short Value
		);

		long _InterlockedExchange(
			long volatile* Target,
			long Value
		);

		__int64 _InterlockedExchange64(
			__int64 volatile* Target,
			__int64 Value
		);

		void* _InterlockedExchangePointer(
			void* volatile* Target,
			void* Value
		);

		__int16 __iso_volatile_load16(const volatile __int16*);
		__int32 __iso_volatile_load32(const volatile __int32*);
		__int64 __iso_volatile_load64(const volatile __int64*);
		__int8 __iso_volatile_load8(const volatile __int8*);

		void __iso_volatile_store16(volatile __int16* Location, __int16 Value);
		void __iso_volatile_store32(volatile __int32* Location, __int32 Value);
		void __iso_volatile_store64(volatile __int64* Location, __int64 Value);
		void __iso_volatile_store8(volatile __int8* Location, __int8 Value);
	}
#pragma endregion
}

namespace Cardinal::Core
{
#ifndef _M_AMD64
#error Interlocked work only with AMD64 arch
#endif
	/// <summary>
	/// A set of atomic "InterlockedXXX" operations
	/// </summary>
	class Interlocked final {
	public:
#pragma region Add
		/// <summary>
		/// Atomic addition
		/// </summary> 
		/// <param name = "to">"volatile" a variable to which will be added a value "what"</param> 
		/// <param name = "what">A variable who will be added</param>
		/// <returns>New value of variable "to"</returns>
		__forceinline static Int32 InterlockedAdd(volatile Int32& to, Int32 what) {
			return Internals::_InterlockedAdd(reinterpret_cast<volatile long*>(&to), what);
		}

		/// <summary>
		/// Atomic addition
		/// </summary>
		/// <param name = "to">"volatile" a variable to which will be added a value "what"</param> 
		/// <param name = "what">A variable who will be added</param>
		/// <returns>New value of variable "to"</returns>
		__forceinline static UInt32 InterlockedAdd(volatile UInt32& to, UInt32 what) {
			return Internals::_InterlockedAdd(reinterpret_cast<volatile long*>(&to), what);
		}

		/// <summary>
		/// Atomic addition
		/// </summary>
		/// <param name = "to">"volatile" a variable to which will be added a value "what"</param>
		/// <param name = "what">A variable who will be added</param>
		/// <returns>New value of variable "to"</returns>
		__forceinline static Int64 InterlockedAdd(volatile Int64& to, Int64 what) {
			return Internals::_InterlockedAdd64(reinterpret_cast<volatile __int64*>(&to), what);
		}

		/// <summary>
		/// Atomic addition
		/// </summary>
		/// <param name = "to">"volatile" a variable to which will be added a value "what"</param>
		/// <param name = "what">A variable who will be added</param>
		/// <returns>New value of variable "to"</returns>
		__forceinline static UInt64 InterlockedAdd(volatile UInt64& to, UInt64 what) {
			return Internals::_InterlockedAdd64(reinterpret_cast<volatile __int64*>(&to), what);
		}
#pragma endregion

#pragma region Increment
		/// <summary>
		/// Atomic variable incrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int16 Increment(volatile Int16& what) {
			return Internals::_InterlockedIncrement16(reinterpret_cast<volatile short*>(&what));
		}

		/// <summary>
		/// Atomic variable incrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt16 Increment(volatile UInt16& what) {
			return Internals::_InterlockedIncrement16(reinterpret_cast<volatile short*>(&what));
		}

		/// <summary>
		/// Atomic variable incrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int32 Increment(volatile Int32& what) {
			return Internals::_InterlockedIncrement(reinterpret_cast<volatile long*>(&what));
		}

		/// <summary>
		/// Atomic variable incrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt32 Increment(volatile UInt32& what) {
			return Internals::_InterlockedIncrement(reinterpret_cast<volatile long*>(&what));
		}

		/// <summary>
		/// Atomic variable incrementation
		/// e</summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int64 Increment(volatile Int64& what) {
			return Internals::_InterlockedIncrement64(reinterpret_cast<volatile long long*>(&what));
		}

		/// <summary>
		/// Atomic variable incrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be incremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt64 Increment(volatile UInt64& what) {
			return Internals::_InterlockedIncrement64(reinterpret_cast<volatile long long*>(&what));
		}
#pragma endregion

#pragma region Decrement
		/// <summary>
		/// Atomic variable decrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int16 Decrement(volatile Int16& what) {
			return Internals::_InterlockedDecrement16(reinterpret_cast<volatile short*>(&what));
		}

		/// <summary>
		/// Atomic variable decrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt16 Decrement(volatile UInt16& what) {
			return Internals::_InterlockedDecrement16(reinterpret_cast<volatile short*>(&what));
		}

		/// <summary>
		/// Atomic variable decrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int32 Decrement(volatile Int32& what) {
			return Internals::_InterlockedDecrement(reinterpret_cast<volatile long*>(&what));
		}

		/// <summary>
		/// Atomic variable decrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt32 Decrement(volatile UInt32& what) {
			return Internals::_InterlockedDecrement(reinterpret_cast<volatile long*>(&what));
		}

		/// <summary>
		/// Atomic variable decrementation
		/// e</summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static Int64 Decrement(volatile Int64& what) {
			return Internals::_InterlockedDecrement64(reinterpret_cast<volatile long long*>(&what));
		}

		/// <summary>
		/// Atomic variable decrementation
		/// </summary>
		/// <param name = "what">A variable which is needed to be decremented</param>
		/// <returns>A new value</returns>
		__forceinline static UInt64 Decrement(volatile UInt64& what) {
			return Internals::_InterlockedDecrement64(reinterpret_cast<volatile long long*>(&what));
		}
#pragma endregion

#pragma region CompareAndSwap
		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static Boolean CompareAndSwap(volatile Boolean& destination, Boolean exchange, Boolean comperand) {
			static_assert(sizeof(Boolean) == sizeof(char));

			return Internals::_InterlockedCompareExchange8(reinterpret_cast<volatile char*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static Int8 CompareAndSwap(volatile Int8& destination, Int8 exchange, Int8 comperand) {
			return Internals::_InterlockedCompareExchange8(reinterpret_cast<volatile char*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static UInt8 CompareAndSwap(volatile UInt8& destination, UInt8 exchange, UInt8 comperand) {
			return Internals::_InterlockedCompareExchange8(reinterpret_cast<volatile char*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static Int16 CompareAndSwap(volatile Int16& destination, Int16 exchange, Int16 comperand) {
			return Internals::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static UInt16 CompareAndSwap(volatile UInt16& destination, UInt16 exchange, UInt16 comperand) {
			return Internals::_InterlockedCompareExchange16(reinterpret_cast<volatile short*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static Int32 CompareAndSwap(volatile Int32& destination, Int32 exchange, Int32 comperand) {
			return Internals::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static UInt32 CompareAndSwap(volatile UInt32& destination, UInt32 exchange, UInt32 comperand) {
			return Internals::_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static Int64 CompareAndSwap(volatile Int64& destination, Int64 exchange, Int64 comperand) {
			return Internals::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		__forceinline static UInt64 CompareAndSwap(volatile UInt64& destination, UInt64 exchange, UInt64 comperand) {
			return Internals::_InterlockedCompareExchange64(reinterpret_cast<volatile long long*>(&destination), exchange, comperand);
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		template<typename T>
		__forceinline static T* CompareAndSwap(volatile T*& destination, TypeTraits::IdentitV<T>* exchange, TypeTraits::IdentitV<T>* comperand) {
			return reinterpret_cast<T*>(
				Internals::_InterlockedCompareExchange64(
					reinterpret_cast<volatile long long*>(&destination),
					reinterpret_cast<long long>(exchange),
					reinterpret_cast<long long>(comperand)));
		}

		/// <summary>
		/// Atomic comparing and swap
		/// <para>Compares "destination" with "comperand" and swaps them if equal</para>
		/// </summary>
		/// <param name = "destination">A reference to variable in which will be written the result if success</param>
		/// <param name = "exchange">A new value</param>
		/// <param name = "comperand">Old value</param>
		/// <returns>Initial value</returns>
		template<Concepts::IsEnum T>
		__forceinline static T CompareAndSwap(volatile T& destination, TypeTraits::IdentitV<T> exchange, TypeTraits::IdentitV<T> comperand) {
			using U = TypeTraits::EnumUnderlyingTypeV<T>;

			U result = CompareAndSwap(
				*reinterpret_cast<volatile U*>(&destination),
				*reinterpret_cast<U*>(&exchange),
				*reinterpret_cast<U*>(&comperand));

			return *reinterpret_cast<T*>(&result);
		}
#pragma endregion

#pragma region Load
		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static Boolean Load(volatile Boolean& target) {
			auto a =
				Internals::__iso_volatile_load8(reinterpret_cast<const volatile char*>(&target));

			return *reinterpret_cast<Boolean*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static Int8 Load(volatile Int8& target) {
			auto a =
				Internals::__iso_volatile_load8(reinterpret_cast<const volatile char*>(&target));

			return *reinterpret_cast<Int8*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static UInt8 Load(volatile UInt8& target) {
			auto a =
				Internals::__iso_volatile_load8(reinterpret_cast<const volatile char*>(&target));

			return *reinterpret_cast<UInt8*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static Int16 Load(volatile Int16& target) {
			auto a =
				Internals::__iso_volatile_load16(reinterpret_cast<const volatile short*>(&target));

			return *reinterpret_cast<Int16*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static UInt16 Load(volatile UInt16& target) {
			auto a =
				Internals::__iso_volatile_load16(reinterpret_cast<const volatile short*>(&target));

			return *reinterpret_cast<UInt16*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static Int32 Load(volatile Int32& target) {
			auto a =
				Internals::__iso_volatile_load32(reinterpret_cast<const volatile int*>(&target));

			return *reinterpret_cast<Int32*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static UInt32 Load(volatile UInt32& target) {
			auto a =
				Internals::__iso_volatile_load32(reinterpret_cast<const volatile int*>(&target));

			return *reinterpret_cast<UInt32*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static Int64 Load(volatile Int64& target) {
			auto a =
				Internals::__iso_volatile_load64(reinterpret_cast<const volatile long long int*>(&target));

			return *reinterpret_cast<Int64*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		__forceinline static UInt64 Load(volatile UInt64& target) {
			auto a =
				Internals::__iso_volatile_load64(reinterpret_cast<const volatile long long int*>(&target));

			return *reinterpret_cast<UInt64*>(&a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		template<typename T>
		__forceinline static T* Load(volatile T*& target) {
			auto a =
				Internals::__iso_volatile_load64(reinterpret_cast<const volatile long long int*>(&target));

			return reinterpret_cast<T*>(a);
		}

		/// <summary>
		/// Atomic variable reading
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <returns>Variable value</returns>
		template<Concepts::IsEnum T>
		__forceinline static T Load(volatile T& target) {
			using U = TypeTraits::EnumUnderlyingTypeV<T>;

			auto v = Load(*reinterpret_cast<volatile U*>(&target));

			return *reinterpret_cast<T*>(&v);
		}
#pragma endregion

#pragma region Store
		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile bool& target, bool value) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&target), *reinterpret_cast<char*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile Int8& target, Int8 value) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&target), *reinterpret_cast<char*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile UInt8& target, UInt8 value) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&target), *reinterpret_cast<char*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile Int16& target, Int16 value) {
			Internals::__iso_volatile_store16(reinterpret_cast<volatile short*>(&target), *reinterpret_cast<short*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile UInt16& target, UInt16 value) {
			Internals::__iso_volatile_store16(reinterpret_cast<volatile short*>(&target), *reinterpret_cast<short*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile Int32& target, Int32 value) {
			Internals::__iso_volatile_store32(reinterpret_cast<volatile int*>(&target), *reinterpret_cast<int*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile UInt32& target, UInt32 value) {
			Internals::__iso_volatile_store32(reinterpret_cast<volatile int*>(&target), *reinterpret_cast<int*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile Int64& target, Int64 value) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&target), *reinterpret_cast<__int64*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		__forceinline static void Store(volatile UInt64& target, UInt64 value) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&target), *reinterpret_cast<__int64*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		template<typename T>
		__forceinline static void Store(volatile T*& target, TypeTraits::IdentitV<T>* value) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&target), *reinterpret_cast<__int64*>(&value));
		}

		/// <summary>
		/// Atomic variable value storing
		/// </summary>
		/// <param name="target">A reference to variable</param>
		/// <param name="value">A new value</param>
		template<Concepts::IsEnum T>
		__forceinline static void Store(volatile T& target, TypeTraits::IdentitV<T> value) {
			using U = TypeTraits::EnumUnderlyingTypeV<T>;

			Store(*reinterpret_cast<volatile U*>(&target), *reinterpret_cast<U*>(&value));
		}
#pragma endregion

#pragma region Swap
		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile bool& first, volatile bool& second) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&second),
				Internals::_InterlockedExchange8(reinterpret_cast<volatile char*>(&first), *reinterpret_cast<char*>(const_cast<bool*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile Int8& first, volatile Int8& second) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&second),
				Internals::_InterlockedExchange8(reinterpret_cast<volatile char*>(&first), *reinterpret_cast<char*>(const_cast<Int8*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile UInt8& first, volatile UInt8& second) {
			Internals::__iso_volatile_store8(reinterpret_cast<volatile char*>(&second),
				Internals::_InterlockedExchange8(reinterpret_cast<volatile char*>(&first), *reinterpret_cast<char*>(const_cast<UInt8*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile Int16& first, volatile Int16& second) {
			Internals::__iso_volatile_store16(reinterpret_cast<volatile short*>(&second),
				Internals::_InterlockedExchange16(reinterpret_cast<volatile short*>(&first), *reinterpret_cast<short*>(const_cast<Int16*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile UInt16& first, volatile UInt16& second) {
			Internals::__iso_volatile_store16(reinterpret_cast<volatile short*>(&second),
				Internals::_InterlockedExchange16(reinterpret_cast<volatile short*>(&first), *reinterpret_cast<short*>(const_cast<UInt16*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile Int32& first, volatile Int32& second) {
			Internals::__iso_volatile_store32(reinterpret_cast<volatile __int32*>(&second),
				Internals::_InterlockedExchange(reinterpret_cast<volatile long*>(&first), *reinterpret_cast<long*>(const_cast<Int32*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile UInt32& first, volatile UInt32& second) {
			Internals::__iso_volatile_store32(reinterpret_cast<volatile __int32*>(&second),
				Internals::_InterlockedExchange(reinterpret_cast<volatile long*>(&first), *reinterpret_cast<long*>(const_cast<UInt32*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile Int64& first, volatile Int64& second) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&second),
				Internals::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&first), *reinterpret_cast<long long*>(const_cast<Int64*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		__forceinline static void Swap(volatile UInt64& first, volatile UInt64& second) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&second),
				Internals::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&first), *reinterpret_cast<long long*>(const_cast<UInt64*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		template<typename T>
		__forceinline static void Swap(volatile T*& first, volatile TypeTraits::IdentitV<T>*& second) {
			Internals::__iso_volatile_store64(reinterpret_cast<volatile __int64*>(&second),
				Internals::_InterlockedExchange64(reinterpret_cast<volatile long long*>(&first), *reinterpret_cast<long long*>(const_cast<UInt64*>(&second))));
		}

		/// <summary>
		/// Atomic values swapping
		/// </summary>
		/// <param name="first">Left operand</param>
		/// <param name="second">Right operand</param>
		template<Concepts::IsEnum T>
		__forceinline static void Swap(volatile T& first, volatile TypeTraits::IdentitV<T>& second) {
			using U = TypeTraits::EnumUnderlyingTypeV<T>;

			Swap(*reinterpret_cast<volatile U*>(&first), *reinterpret_cast<volatile U*>(&second));
		}
#pragma endregion
	};
}