#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction() = default;

	void print();

	Fraction sum(Fraction b);   //Example: c = a.sum(b)
	Fraction sub(Fraction b);
	Fraction mul(Fraction b);
	Fraction div(Fraction b);

	void reduce(); //Сокращение дроби

	int getNumerator();
	int getDenominator();

	void setNumerator(int value);
	void setDenominator(int value);

public:
	int numerator = 0;	 //Вторая очередь инициализации (выполняется только при пропущенной первой)
	int denominator = 1; //Вторая очередь инициализации (выполняется только при пропущенной первой)
};