#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <array>
using namespace std;


int comp1(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

class Card // емли я правильно понял то здесь только сама карта, колода отдельным объектом?
{
private:
	
public:
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
	Card(Suit suit, cardValue value, bool position) {
		m_card_suit = suit;
		m_card_value = value;
		m_position = position;
	};
	void Flip() {
		m_position = !m_position;
	};
	cardValue GetValue() const {
		return m_card_value;
	};
	~Card() {};
};

class Hand
{
private:
	vector<Card*> hand;
	int pointArr[13]{ 2,3,4,5,6,7,8,9,10,1,10,10,10 };
public:
	Hand(Card *card) {
		hand.push_back(card);
	};
	void handAdd(Card *card) {
		hand.push_back(card);
	};
	void handPrint() {
		if (hand.empty())
		{
			cout << "рука пуста" << endl;
		}
		else
		{
			string suit[]{ "spades", "clubs", "hearts", "diamonds" };
			string cardvalue[]{"TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "ACE", "KING", "QUEEN", "JACK"
			};
			for (auto& v : hand)
			{
				cout << suit[v->m_card_suit] << "|" << cardvalue[v->GetValue()] << "|" << v->m_position << endl;
			}

		}
			};
	void GetValue() {
		int value = 0;
		int a = 0;
		for (auto& v : hand)
		{
			value += pointArr[v->GetValue()];
			if (pointArr[v->GetValue()] == 1)
			{
				a = a + 1;
			}
		}
		if (a > 0)
		{
			for (a > 0; a--;)
			{
				if (value < 11)
				{
					value = value + 10;
				}
			}
		}
		//for (int i = 0; i < hand.size(); i++)
		//{
		//	if (hand[i]->GetValue() == 1)
		//	{
		//		a + 1;
		//	}
		//	else
		//	{
		//	/*	value += pointArr[];*/
		//	}
		//}
		//if (a > 0)
		//{
		//	for (a > 0; a--;)
		//	{
		//		if (value < 11)
		//		{
		//			value + 10;
		//		}
		//	}
		//}
		
		cout << "очков: " << value << endl;
	};
	~Hand() {
		hand.clear();
	};
};

class ArrayInt
{
private:
	int *m_data;
	int m_length;
public:
	ArrayInt() : m_length(0), m_data(nullptr) {

	}
	ArrayInt(int lenght) : m_length(lenght) {
		assert(lenght >= 0);
		if (lenght > 0)
		{
			m_data = new int[lenght];
		}
		else
		{
			m_data = nullptr;
		}
	}
	~ArrayInt() {
		delete[] m_data;
	}
	void clear() {
		delete[] m_data;
		m_data = nullptr;
		m_length = 0;
	}
	int size() {
		return m_length;
	}
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
	void resize(int newLength) {
		if (newLength == m_length)
			return;
		if (newLength <= 0)
			clear();
		return;
		int *data = new int[newLength];
		int elementsToCopy = newLength > m_length ? m_length : newLength;
		for (int i = 0; i < elementsToCopy; ++i)
		{
			data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = data;
		m_length = newLength;
	}
	void insertBefore(int value, int index) {
		//Проверка корректности индекса
		assert(index >= 0 && index <= m_length);
		//создаем массив +1 к старому
		int *data = new int(m_length + 1);
		// Копируем элементы до индекса
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];
		// вставляем элемент
		data[index] = value;
		//копируем элементы после всталяемого
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];
		//Удаляем старый массив и оставляем новый
		delete[] m_data;
		m_data = data;
		++m_length;
	}
	//задание 1
	int popBack() {
		return m_data[m_length];
		m_length--;
	}
	int popFront() {
		return m_data[0];
		int* data = new int(m_length - 1);
		for (int index = 0; index < m_length - 1; index++)
			data[index] = m_data[index + 1];
	}
	void sortArr() {
		qsort(m_data, m_length, sizeof(int), comp1);
	}
	void print(int index) {
		(assert(index >= 0 && index <= m_length));
		cout << m_data[index] << endl;
	}
	void push_back(int value) {
		insertBefore(value, m_length);
	}
	void getValue() {
	
	};
};

int main()
{
    setlocale(LC_ALL, "Russian");
	/*ArrayInt arr(3);
	int a = 1;
	arr.insertBefore(a, 0);
	arr.print(0)*/; // может вы подскажете что здесь не так? гдето поппутал с ссылками?

	//Задание 2 
	vector<int> v{ 1,5,5,5,4 };
	sort(v.begin(), v.end());
	int results = unique(v.begin(), v.end()) - v.begin();
	cout << results << endl;
	//Задание 3
	Card card(Card::Suit::clubs, Card::cardValue::THREE, 0);
	Card card2(Card::Suit::hearts, Card::cardValue::ACE, 0);
	Card card3(Card::Suit::diamonds, Card::cardValue::JACK, 0);
	Card card4(Card::Suit::hearts, Card::cardValue::FIVE, 0);
	Hand hand(&card);
	hand.handAdd(&card2);
	hand.handAdd(&card3);
	hand.handAdd(&card4);
	hand.handPrint();
	hand.GetValue();
	hand.~Hand();
	hand.handPrint();
}




