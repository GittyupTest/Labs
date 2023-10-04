#pragma once
#include <iostream>

class Array
{
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	Array(Array &&other);
	~Array();

	int size() const;
	void print() const;

	void swap(Array &other);

	void resize(int size);

	Array &operator=(const Array &other);
	Array &operator=(Array &&other);
	const int &operator[](const int index) const;
	int &operator[](const int index);

	Array operator+(const Array &other) const;
	Array &operator+=(const Array &other);

private:
	int *m_array = nullptr;
	int m_size = 0;
};

std::ostream &operator<<(std::ostream &stream, const Array &arr);
std::istream &operator>>(std::istream &stream, Array &arr);
