#include <algorithm>
#include <assert.h>

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

Array::Array(const Array &other)
	: m_size(other.m_size)
{
	std::cout << "Array::Array(const Array &other): begin \n";
	m_array = new int[m_size];

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}
}

Array::Array(Array &&other)
{
	//m_size == 0, m_array == nullptr
	std::cout << "Array::Array(Array &&other): begin \n";
	swap(other);
}

Array::~Array()
{
	std::cout << "Array::~Array: begin \n";
	delete[] m_array;
}

int Array::size() const
{
	return m_size;
}

void Array::swap(Array &other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}

void Array::resize(int size)
{
	if (size < 0) {
		std::cerr << "Array::resize: size is negative, invert...\n";
		size = -size;
	}

	Array res(size);

	int count = std::min(m_size, size);
	for (int i = 0; i < count; ++i) {
		res.m_array[i] = m_array[i];
	}

	res.swap(*this); 
}

void Array::print() const
{
	std::cout << *this;
}

Array &Array::operator=(Array &&other)
{
	swap(other);
	return *this;
}

Array &Array::operator=(const Array &other)
{
	/*
		//Альтернативная реализация через copy-and-swap idiom
		//Будет существенно медленее нашей реализации только
		// если размеры массивов одинаковы (т.к. память можно не удалять)
		Array &Array::operator=(Array other)
		{
			swap(other);
			return *this;
		}
	*/

	if (this == &other) {
		return *this;
	}

	if (m_size != other.m_size) {
		m_size = other.m_size;
		delete[] m_array;
		m_array = new int[m_size];
	}

	for (int i = 0; i < m_size; ++i) {
		m_array[i] = other.m_array[i];
	}

	return *this;
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

Array Array::operator+(const Array &other) const
{
	std::cout << "Array::operator+: begin \n";
	Array res(m_size + other.m_size);

	for (int i = 0; i < m_size; ++i) {
		res.m_array[i] = m_array[i];
	}

	for (int i = 0; i < other.m_size; ++i) {
		res.m_array[m_size + i] = other.m_array[i];
	}

	std::cout << "Array::operator+: return \n";
	return res;
}

Array &Array::operator+=(const Array &other)
{
	std::cout << "Array::operator+=: begin \n";
	Array tmp(*this + other);
	std::cout << "Array::operator+=: tmp created \n";
	this->swap(tmp);
	std::cout << "Array::operator+=: return \n";
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Array &arr)
{
	stream << '[';
	for (int i = 0; i < arr.size() - 1; ++i) {
		stream << arr[i] << ", ";
	}
	stream << arr[arr.size() - 1] << "]\n";
	return stream;
}

std::istream &operator>>(std::istream &stream, Array &arr)
{
	for (int i = 0; i < arr.size(); ++i) {
		stream >> arr[i];
	}
	return stream;
}