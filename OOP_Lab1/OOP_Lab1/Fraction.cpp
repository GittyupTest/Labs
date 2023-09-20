#include <iostream>

#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
	//Первая очередь инициализации
	: m_numerator(numerator)
	/*, m_denominator(denominator) */ //Не инициализируем здесь, нужны доп. проверки.
	//Вторая очередь инициализации для тех полей, коотрых не было в первой очереди (см. .h)
{
	//Третья очередь инициализации. Сейчас m_numerator == numerator, m_denominator == 1

	if (denominator == 0) {
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
		//Ничего не меняем, m_denominator и так == 1
	}
	else {
		m_denominator = denominator;
	}

	if (m_denominator < 0) {
		m_numerator *= -1;
		m_denominator *= -1;
	}
}

int Fraction::getNumerator()
{
	return m_numerator;
}

int Fraction::getDenominator()
{
	return m_denominator;
}

void Fraction::setNumerator(int value)
{
	m_numerator = value;
}

void Fraction::setDenominator(int value)
{
	if (value == 0) {
		//Если знаменатель неправильный, ничего не делаем. Хотя можно было бы положить 1, как в конструкторе.
		std::cerr << "Fraction::setDenominator: error: value is 0, won't assign.\n";
		return;
	}

	m_denominator = value;
}

void Fraction::print()
{
	std::cout << m_numerator << '/' << m_denominator << '\n';
}

Fraction Fraction::div(Fraction b)
{
	//Особый случай:
	if (b.m_numerator == 0) {
		std::cerr << "Fraction::div: error: b.m_numerator is 0, result will be 0/1.\n";
		return Fraction(0, 1); //Fraction(1, 1); или любую на ваше усмотрение
		/**
		 * Или вообще ничего не делать
		 * cerr << "Fraction::div: error: b.numerator is 0, won't divide.";
		 * return *this;
		 */
	}

	Fraction result;
	result.m_numerator = m_numerator * b.m_denominator;
	result.m_denominator = m_denominator * b.m_numerator;
	return result;
}

bool Fraction::operator==(Fraction other)
{
	return (m_numerator == other.m_numerator &&
			m_denominator == other.m_denominator);
}

bool Fraction::operator!=(Fraction other)
{
	//Сокращаем дублирование кода за счёт использования уже реализованных методов
	return !operator==(other);
}