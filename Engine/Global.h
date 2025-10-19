#pragma once
#include "Direct3D.h"
#include <concepts>

//安全にメモリを開放するためのマクロ
#define SAFE_DELETE(p) {if ((p)!=nullptr) { delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p) {if ((p)!=nullptr) { delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p) {if ((p)!=nullptr) { p->Release(); (p)=nullptr;}}

template<typename TYPE>
concept HasRelease = requires(TYPE* _ptr)
{
	{ _ptr->Release() } -> std::same_as<void>;
};

template<typename TYPE>
static inline void SafeDelete(TYPE* _ptr)
{
	if (_ptr != nullptr)
	{
		delete _ptr;
		_ptr = nullptr;
	}
}

template<typename TYPE>
static inline void SafeRelease(TYPE* _ptr)
{
	if (HasRelease<TYPE>)
	{
		if (_ptr != nullptr)
		{
			_ptr->Release();
			_ptr = nullptr;
		}
	}
	else
	{
		SafeDelete(_ptr);
	}
}