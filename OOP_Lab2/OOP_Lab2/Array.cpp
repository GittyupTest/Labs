#include <assert.h>
#include <iostream>

#include "Array.h"

Array::Array(const int size, const int value)
{
	if (size < 0) {
		std::cerr << "Array::Array: size is negative, invert...\n";
		m_size = -size;
	}
	else {
		m_size = size;
	}

	m_array = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = value;
	}
}

int Array::size() const
{
	return m_size;
}

Array::~Array()
{
	delete[] m_array;
}

void Array::print() const
{
	std::cout << '[';
	for (int i = 0; i < m_size - 1; ++i) {
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1] << "]\n";
}

const int &Array::operator[](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

int &Array::operator[](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}
