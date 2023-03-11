#include <stdexcept>

template <typename T>
class simple_vector
{
public:
	simple_vector(size_t capacity) : m_capacity(capacity)
	{
		m_values = new T[m_capacity];
	}

	simple_vector() : simple_vector(0)
	{

	}

	// в задаче не требуется, пока что запретим копирование и присвоение
	simple_vector(const simple_vector&) = delete;
	simple_vector& operator=(const simple_vector&) = delete;

	~simple_vector()
	{
		delete[] m_values;
	}

	void push_back(T value)
	{
		if (m_size == m_capacity)
		{
			// Расширяем массив для данных
			m_capacity = m_capacity > 0 ? m_capacity * 2 : 1;
			T* newArr = new T[m_capacity];
			copy(m_values, newArr, m_size);
			delete[] m_values;
			m_values = newArr;
		}

		m_values[m_size++] = value;
	}

	size_t size()
	{
		return m_size;
	}

	size_t capacity()
	{
		return m_capacity;
	}

	T& at(size_t index)
	{
		checkIndex(index);
		return m_values[index];
	}

	const T& at(size_t index) const
	{
		checkIndex(index);
		return m_values[index];
	}

private:
	T* m_values = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;

	void copy(T* arr_from, T* arr_to, size_t size) {
		for (int i = 0; i < size; ++i) {
			arr_to[i] = arr_from[i];
		}
	}

	void checkIndex(size_t index)
	{
		if (index >= m_size)
		{
			throw std::out_of_range("Переданный индекс элемента находится вне допустимого диапазона");
		}
	}
};