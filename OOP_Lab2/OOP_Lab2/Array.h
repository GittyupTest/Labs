#pragma once

class Array
{
public:
	Array(const int size = 10, const int value = 0);
	~Array();

	int size() const;
	void print() const;

	const int &operator[](const int index) const;
	int &operator[](const int index);

private:
	int *m_array = nullptr;
	int m_size = 0;
};

