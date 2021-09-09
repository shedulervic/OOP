#include <iostream>
#include <vector>
using namespace std;

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const
{
    int value = 0;
    if (m_IsFaceUp)
    {
        value = m_Rank;
        if (value > 10)
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
    Hand();
    // виртуальный деструктор
    ~Hand() {
        Clear();
    };

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу
    // значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}
// деструктор по-прежнему виртуальный
// это уже можно не обозначать


void Hand::Add(Card* pCard)
{
    m_Cards.push_back(pCard);
}

int Hand::GetTotal() const
{
    // если карт в руке нет, возвращает значение 0
    if (m_Cards.empty())
    {
        return 0;
    }

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_Cards[0]->GetValue() == 0)
    {
        return 0;
    }

    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        total += (*iter)->GetValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
    {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }

    return total;
}

// Задание 1
template <class T>
class Pair1 {
private:
    T m_a;
    T m_b;
public:
    Pair1(const T& a, const T& b){
        m_a = a;
        m_b = b;
    }
    ~Pair1() {
        
    }
    T& first() {
        return m_a;
    }
    const T& first() const{
    return m_a;
    }
    T& second(){
        return m_b;
    }
    const T& second() const {
        return m_b;
    }
};

//Задание 2
template<class T, class S>
class Pair {
private:
    T m_t;
    S m_s;
public:
    Pair(T t, S s) {
        m_t = t;
        m_s = s;
    }
    T first() {
        return m_t;
    }
    S second() {
        return m_s;
    }
};

//Задание 3
template <class V>
class StringValuePair : public Pair<std::string, V>
{
public:
    StringValuePair(const std::string& str, const V& data)
        : Pair<std::string, V>(str, data){
    }
};

//Задание 4
class GenericPlayer {
private:
	string g_name;
    bool busted;
    int total;
public:
    GenericPlayer(string name) {
        g_name = name;
        busted = false;
    }
    virtual bool IsHitting() {
        if (total < 21){
            return true;
        }
        else{
            false;
        }
    }
    bool IsBoosted() {
        total = Hand().GetTotal();
        if (total > 21){
            busted = true;
            return busted;
        }
    }
    void Bust() {
        cout << "Игрок: " << g_name << "ПЕРЕБОР!" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    //Задание 1
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
    //Задание 2
    Pair<int, double> p3(6, 7.8);
    cout << "Pair2: " << p3.first() << ' ' << p3.second() << '\n';

    Pair<double, int> p4(3.4, 5);
    cout << "Pair2: " << p4.first() << ' ' << p4.second() << '\n';

    //Задание 3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}

