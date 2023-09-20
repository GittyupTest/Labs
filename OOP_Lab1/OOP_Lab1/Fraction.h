#pragma once

class Fraction
{
public:
	Fraction() = default; //Сработает вторая очередь инициализации, получим дробь 0/1
	Fraction(const int numerator, const int denominator);
	~Fraction() = default;

	int getNumerator() const;	  //или можно назвать int numerator() const;
	int getDenominator() const; //или можно назвать int denominator() const;
	//Кому как больше нравится: fraction.getNumerator() или fraction.numerator()

	void setNumerator(const int value);
	void setDenominator(const int value);

	void print() const;

	Fraction sum(const Fraction &other) const;   //Пример использования: c = a.sum(b)
	Fraction sub(const Fraction &other) const;
	Fraction mul(const Fraction &other) const;
	Fraction div(const Fraction &other) const;

	void reduce(); //Сокращение дроби

	/**
	 * Не сокращает дроби при сравнении.
	 * Если программисту это нужно, он может вызвать reduce() перед сравнением.
	 */
	bool operator==(const Fraction &other) const;
	bool operator!=(const Fraction &other) const;

private:
	int m_numerator = 0;	 //Вторая очередь инициализации (выполняется только при пропущенной первой)
	int m_denominator = 1; //Вторая очередь инициализации (выполняется только при пропущенной первой)
};