export module Cardinal.Containers.InitilizerList;

export namespace std 
{
	/// <summary>
	/// Initialization list
	/// </summary>
	template<class _Elem>
	class initializer_list {
	public:
		typedef _Elem value_type;
		typedef const _Elem& reference;
		typedef const _Elem& const_reference;
		typedef size_t size_type;

		typedef const _Elem* iterator;
		typedef const _Elem* const_iterator;

		constexpr initializer_list()
			: _First(nullptr), _Last(nullptr) {
		}

		constexpr initializer_list(const _Elem* _First_arg,
			const _Elem* _Last_arg)
			: _First(_First_arg), _Last(_Last_arg) {
		}

		[[nodiscard]] constexpr const _Elem* begin() const {	// Get beginning of list
			return (_First);
		}

		[[nodiscard]] constexpr const _Elem* end() const {	// Get end of list
			return (_Last);
		}

		[[nodiscard]] constexpr size_t size() const {	// Get length of list
			return (static_cast<size_t>(_Last - _First));
		}

	private:
		const _Elem* _First;
		const _Elem* _Last;
	};

	template<class _Elem>
	[[nodiscard]] constexpr const _Elem* begin(initializer_list<_Elem> _Ilist) {	// Get beginning of sequence
		return (_Ilist.begin());
	}

	template<class _Elem>
	[[nodiscard]] constexpr const _Elem* end(initializer_list<_Elem> _Ilist) {	// Get end of sequence
		return (_Ilist.end());
	}
}

export namespace Cardinal
{
	/// <summary>
	/// Initialization list
	/// </summary>
	template<typename T>
	using InitilizerList = std::initializer_list<T>;
}