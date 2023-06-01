#ifndef YTL_MEMORY
#define YTL_MEMORY

#include <memory>
#include <cstring>

namespace ytl
{
	///simple non-owning pointer representation
	template <typename T>
	class observer_ptr
	{
		T* ptr_ = nullptr;

	public:

		using element_type = T;
		using pointer = T*;
		using reference = T&;

		observer_ptr(std::unique_ptr<T> const& ptr) : ptr_{ ptr.get() } {};
		observer_ptr(std::shared_ptr<T> const& ptr) : ptr_{ ptr.get() } {};
		observer_ptr(T* ptr) : ptr_{ ptr } {};
		observer_ptr() = default;
		~observer_ptr() = default;

		observer_ptr(observer_ptr<T> const&) = default;
		observer_ptr<T>& operator=(observer_ptr<T> const&) = default;
		observer_ptr(observer_ptr<T>&&) = default;
		observer_ptr<T>& operator=(observer_ptr<T>&&) = default;

		T* operator->() const { return ptr_; }
		T* get() const { return ptr_; }

		T operator*() const { return *ptr_; }
		operator T* () const { return ptr_; }
	};


	template <typename T>
	static void zero_memory(T* ptr)
	{
		memset(ptr, 0, sizeof(T));
	}

}

#endif
