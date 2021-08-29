#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h> 
using namespace std;
// 1 Задание
class Figure
{
public:
	virtual void area() = 0;
private:
};

class Parallelogram : public Figure
{
public:
	 Parallelogram(int a, int b) {
		m_a = a;
		m_b = b;
	};
	~Parallelogram() {};
	virtual void area() {
		std::cout << "Площадь фигуры =  " << m_a*m_b << endl;
	}
private:
	int m_a;
	int m_b;
};

class Circle :public Figure
{
public:
	Circle(double r) {
		radius = r;
	};
	~Circle() {};
	void area () {
		std::cout << "Площадь круга =  " << M_PI*radius*radius << endl;
	}
private:
	double radius;
};

class Rectangle :public Parallelogram
{
public:
	Rectangle(int a, int b) : Parallelogram(a, b) {};
	~Rectangle() {};
};

class Square :public Parallelogram
{
public:
	Square();
	Square(int a) : Parallelogram(a, a)
	{
		m_a = a;
	};
	~Square() {};
	void area() {
		
		std::cout << "Площадь квадрата =  " << pow(m_a, 2) << endl;
	}
private:
	int m_a;
};

class Rhombus :public Parallelogram
{
public:
	Rhombus(int a, int b) : Parallelogram(a, b) {};
	~Rhombus() {};
};

 // 2 Задание
class Car
{
public:
	Car(string company, string model) {
		m_company = company;
		m_model = model;
	};
	virtual void data() {
		std::cout << "автомобиль, марки " << m_model << ", производства " << m_company << endl;
	};
private:
	string m_company;
	string m_model;
};

class  PassengerCar : virtual public Car
{
public:
	PassengerCar(string company, string model): Car(company, model) {
		m_company = company;
		m_model = model;
	};
	virtual void data() {
		std::cout << "легковой автомобиль, марки " << m_model << ", производства " << m_company << endl;
	};
	~PassengerCar() {};

private:
	string m_company;
	string m_model;
};

class Bus : virtual public Car
{
public:
	Bus(string company, string model) : Car(company, model) {
		m_company = company;
		m_model = model;
	};
	virtual void data() {
		std::cout << "автобус, марки " << m_model << ", производства " << m_company << endl;
	};
	~Bus() {};

private:
	string m_company;
	string m_model;
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(string company, string model) : Bus(company, model), PassengerCar(company, model), Car(company, model) {
		m_company = company;
		m_model = model;
	};
	void data() {
		std::cout << "минивен, марки " << m_model << ", производства " << m_company << endl;
	};
private:
	string m_company;
	string m_model;
};

// 3 задание
class Fraction
{
private:
	double m_fraction[2];
	Fraction simplification(Fraction r_fraction) { // Не успел дипилить до раб. состояния
		int less, j;
		int a = r_fraction.m_fraction[0];
		int b = r_fraction.m_fraction[1];
		do
		{
			if (a < b)
				less = a;
			else
				less = b;
			for (j = less; j > 0; j--) {
				if (!(a % j) && !(b % j))
				{
					a /= j;
					b /= j;
					break;
				}
			}
		} while (j != 1);
		return Fraction(a, b);
	};
public:
	Fraction(double numenator, double denomenator) {
		if (denomenator == 0)
		{
			std::cout << "Знаменатель не должен быть равен нулю!" << endl;
		}
		else
		{
			m_fraction[0] = numenator;
			m_fraction[1] = denomenator;
		}
	};
	void printFraction() {
		std::cout << m_fraction[0] << "/" << m_fraction[1] << endl;
	}
	
	Fraction operator+(Fraction r_fraction) {
		Fraction f = Fraction(((m_fraction[0]) * (r_fraction.m_fraction[1])) + ((m_fraction[1] * r_fraction.m_fraction[0])), 
	((m_fraction[1] * r_fraction.m_fraction[1])));
		return simplification(f);
	};
	Fraction operator-(Fraction r_fraction) {
		return Fraction(m_fraction[0] * r_fraction.m_fraction[1], m_fraction[1] * r_fraction.m_fraction[1]);
	};
};

// 4 задание
class Card
{
private:
	bool m_position;
	enum Suit
	{
		spades, clubs, hearts, diamonds
	};
	enum cardValue
	{
		TWO, THREE, FOUR, FIVE, SIX, SEVEN,
		EIGHT, NINE, TEN, ACE, KING, QUEEN, JACK
	};
	Suit m_card_suit;
	cardValue m_card_value;
public:
	Card(Suit suit, cardValue value, bool position) {
		m_card_suit = suit;
		m_card_value = value;
		m_position = position;
	};
	void Flip(){
		m_position = !m_position;
	};
	cardValue GetValue() const {
		return m_card_value;
	};
	~Card();
};

int main()
{
	setlocale(LC_ALL, "Russian");
    std::cout << "Задание 1" << endl;
	// 1 Задание
	Circle circle(2);
	Figure* figureCircle = &circle;
	figureCircle->area();
	Square square(2);
	Figure* figureSquare = &square;
	figureSquare->area();
	Rhombus rhombus(2, 4);
	rhombus.area();
	// 2 Задание
	std::cout << "Задание 2" << endl;
	PassengerCar car1("lada", "2201");
	car1.data();
	Bus bus("ikarus", "А я и не помгю моделей");
	bus.data();
	Minivan van("dodje", "caravan");
	van.data();
	// 3 Задание
	std::cout << "Задание 3" << endl;
	Fraction fraction(3, 7);
	fraction.printFraction();
	Fraction fraction2(5, 9);
	Fraction fraction3 = fraction + fraction2;
	fraction3.printFraction();
	Fraction fraction4 = fraction3 - fraction2;
	fraction4.printFraction();

}

