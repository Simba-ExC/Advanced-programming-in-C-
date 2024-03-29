#pragma once

class SmartArray
{
public:
	SmartArray(size_t size);
	// ����������� ����������� ���������� ��� ������������� ������ �������
	// ������������� �������������
	SmartArray(const SmartArray& src);
	// �������� ������������ ���������� ��� ������������ ������� � ������������ ������
	SmartArray& operator =(const SmartArray& src);
	~SmartArray();
	void addElement(int value);
	int getElement(size_t index);
	size_t getLength();
private:
	int* m_elements = nullptr;
	size_t m_size = 0;
	size_t m_head = 0;
	void cleanup();
	void copyFrom(const SmartArray& src);
};