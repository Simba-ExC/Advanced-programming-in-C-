#pragma once
#include <stdint.h>
#include <math.h>

struct ExeptNotPtr {};

template<class T>
class unique_ptr
{
private:
	T* ptr = nullptr;


public:
	unique_ptr(T*);			// Конструктор, принимающий сырой указатель
	unique_ptr(const unique_ptr &) = delete;	// конструктор копирования
	~unique_ptr();			// деструктор

	unique_ptr& operator= (const unique_ptr&) = delete;	// оператор присваивания
	friend std::ostream& operator<< (std::ostream& out, const unique_ptr<T>& uptr)
	{
		return out << uptr.ptr;
	}
	T& operator* () const;	// оператор разименования
	T* release();			// освобождает владение и возвращает сырой указатель.
};



template<class T>
inline unique_ptr<T>::unique_ptr(T* rawPtr) : ptr(rawPtr)
{
	std::cout << "-= Constructor =-\n";
}

template<class T>
inline unique_ptr<T>::~unique_ptr()
{
	std::cout << "-= Destructor =-\n";
	delete ptr;
}

template<class T>
inline T& unique_ptr<T>::operator*() const
{
	if (!ptr)
	{
		throw ExeptNotPtr();
	}
	return *ptr;
}

template<class T>
inline T* unique_ptr<T>::release()
{
	std::cout << "-= Release =-\n";
	T* temp(ptr);
	ptr = nullptr;

	return temp;
}
