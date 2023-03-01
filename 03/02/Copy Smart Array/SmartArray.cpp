#include <stdexcept>
#include "SmartArray.h"

SmartArray::SmartArray(size_t size)
{
	m_elements = new int[size];
	m_size = size;
}

SmartArray::SmartArray(const SmartArray& src)
{
	copyFrom(src);
}

SmartArray& SmartArray::operator =(const SmartArray& src)
{
	// Избегаем копирования объекта самого в себя
	if (&src != this)
	{
		// При присваивании в существующий объект не только копируем, но и очищаем старые данные
		cleanup();
		copyFrom(src);
	}

	return *this;
}

SmartArray::~SmartArray()
{
	cleanup();
}

void SmartArray::addElement(int value)
{
	// В условиях задачи нет требования сделать массив динамическим, просто проверяем заполненность
	// Массив уже заполнен
	if (m_head >= m_size)
	{
		throw std::out_of_range("Попытка добавления элемента с превышением размера массива");
	}

	m_elements[m_head++] = value;
}


int SmartArray::getElement(size_t index)
{
	// Считаем, что есть только добавленные элементы
	if (index >= m_head)
	{
		throw std::out_of_range("Индекс элемента массива вне допустимого диапазона");
	}

	return m_elements[index];
}

size_t SmartArray::getLength()
{
	return m_head;
}

void SmartArray::copyFrom(const SmartArray& src)
{
	m_elements = new int[src.m_size];
	for (auto i = 0; i < src.m_head; ++i)
	{
		m_elements[i] = src.m_elements[i];
	}

	m_head = src.m_head;
	m_size = src.m_size;
}

void SmartArray::cleanup()
{
	delete[] m_elements;
}