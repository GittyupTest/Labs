#pragma once

#include <algorithm>
#include <assert.h>
#include <iostream>

template <typename ItemType>
class Array
{
public:
	template <typename IT, typename AT>
	class TemplateIterator;
	using Iterator = TemplateIterator<ItemType, Array>;
	using ConstIterator = TemplateIterator<const ItemType, const Array>;

public:
	Array(const int size = 10, const ItemType &value = ItemType());
	Array(const Array &other);
	Array(Array &&other);
	~Array();

	Iterator begin();
	Iterator end();

	ConstIterator begin() const;
	ConstIterator end() const;

	int size() const;
	void print() const;

	void swap(Array &other);

	void resize(int size);

	Array &operator=(const Array &other);
	Array &operator=(Array &&other);
	const ItemType &operator[](const int index) const;
	ItemType &operator[](const int index);

	Array operator + (const Array &other) const;
	Array &operator += (const Array &other);

private:
	ItemType *m_array = nullptr;
	int m_size = 0;
};

template <typename ItemType>
template <typename IT, typename AT>
class Array<ItemType>::TemplateIterator
{
public:
	TemplateIterator(AT *array = nullptr, const int pos = 0);

	IT &operator*();
	IT &operator[](const int offset);

	TemplateIterator &operator++();
	TemplateIterator &operator--();
	TemplateIterator operator++(int);
	TemplateIterator operator--(int);

	bool operator==(const TemplateIterator &other) const;
	bool operator!=(const TemplateIterator &other) const;

private:
	AT *m_array;
	int m_pos = -1;
};

template <typename ItemType>
std::ostream &operator<<(std::ostream &stream, const Array<ItemType> &arr);

template <typename ItemType>
std::istream &operator>>(std::istream &stream, Array<ItemType> &arr);

#include "Array.cpp"