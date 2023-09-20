#include <iostream>

#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator)
	//Первая очередь инициализации
	: numerator(numerator)
	/*, denominator(denominator) */ //Не инициализируем здесь, нужны доп. проверки.
	//Вторая очередь инициализации для тех полей, коотрых не было в первой очереди (см. .h)
{
	//Третья очередь инициализации. Сейчас this->numerator == numerator, this->denominator == 1

	if (denominator == 0) {
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
		//Ничего не меняем, this->denominator и так == 1
	}
	else {
		//denominator = denominator; //Кто где?
		this->denominator = denominator; //Никакой путаницы
	}

	if (this->denominator < 0) {
		this->numerator *= -1;
		this->denominator *= -1;
	}
}

Fraction Fraction::div(Fraction b)
{
	//Особый случай:
	if (b.numerator == 0) {
		std::cerr << "Fraction::div: error: b.numerator is 0, result will be 0/1.\n";
		return Fraction(0, 1); //Fraction(1, 1); или любую на ваше усмотрение
		/**
		 * cerr << "Fraction::div: error: b.numerator is 0, won't divide.";
		 * return *this;
		 */
	}

	Fraction result;
	result.numerator = numerator * b.denominator;
	result.denominator = denominator * b.numerator;
	return result;
}

void Fraction::setDenominator(int value)
{
	if (value == 0) {
		std::cerr << "Fraction::setDenominator: error: value is 0, won't assign.\n";
		return;
	}

	denominator = value;
}

void Fraction::print()
{
	std::cout << numerator << '/' << denominator << '\n';
}