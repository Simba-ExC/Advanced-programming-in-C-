#include <stdexcept>
#include "SmartArray.h"

SmartArray::SmartArray(size_t size)
{
	m_elements = new int[size];
	m_size = size;
}

SmartArray::~SmartArray()
{
	delete[] m_elements;
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