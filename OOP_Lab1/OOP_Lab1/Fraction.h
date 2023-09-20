#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(int numerator, int denominator);
	~Fraction() = default;

	int getNumerator();	  //или можно назвать int numerator();
	int getDenominator(); //или можно назвать int denominator();
	//Кому как больше нравится: fraction.getNumerator() или fraction.numerator()

	void setNumerator(int value);
	void setDenominator(int value);

	void print();

	Fraction sum(Fraction b);   //Пример использования: c = a.sum(b)
	Fraction sub(Fraction b);
	Fraction mul(Fraction b);
	Fraction div(Fraction b);

	void reduce(); //Сокращение дроби

private:
	int m_numerator = 0;	 //Вторая очередь инициализации (выполняется только при пропущенной первой)
	int m_denominator = 1; //Вторая очередь инициализации (выполняется только при пропущенной первой)
};