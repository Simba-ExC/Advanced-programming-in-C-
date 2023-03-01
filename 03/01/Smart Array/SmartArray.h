#pragma once

class SmartArray
{
public:
	SmartArray(size_t size);
	SmartArray(const SmartArray&) = delete;
	SmartArray& operator=(const SmartArray&) = delete;
	~SmartArray();
	void addElement(int value);
	int getElement(size_t index);
	size_t getLength();
private:
	int* m_elements = nullptr;
	size_t m_size = 0;
	size_t m_head = 0;
};