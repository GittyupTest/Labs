#pragma once

class Fraction
{
public:
	Fraction() = default; //Сработает вторая очередь инициализации, получим дробь 0/1
	Fraction(const int numerator, const int denominator);
	~Fraction() = default;

	int getNumerator();	  //или можно назвать int numerator();
	int getDenominator(); //или можно назвать int denominator();
	//Кому как больше нравится: fraction.getNumerator() или fraction.numerator()

	void setNumerator(const int value);
	void setDenominator(const int value);

	void print();

	Fraction sum(const Fraction &other);   //Пример использования: c = a.sum(b)
	Fraction sub(const Fraction &other);
	Fraction mul(const Fraction &other);
	Fraction div(const Fraction &other);

	void reduce(); //Сокращение дроби

	/**
	 * Не сокращает дроби при сравнении.
	 * Если программисту это нужно, он может вызвать reduce() перед сравнением.
	 */
	bool operator==(const Fraction &other);
	bool operator!=(const Fraction &other);

private:
	int m_numerator = 0;	 //Вторая очередь инициализации (выполняется только при пропущенной первой)
	int m_denominator = 1; //Вторая очередь инициализации (выполняется только при пропущенной первой)
};