export module Cardinal.Settings:Base;

export import Cardinal.Core;
export import Cardinal.Logger;
export import Cardinal.Memory.DataSizeT;
export import Cardinal.Settings.ConstSettings;
export import Cardinal.Threading.SRWLock;

namespace Cardinal
{
	template<typename THeap>
	class BaseString;

	namespace Memory
	{
		class Heap;
	}
}