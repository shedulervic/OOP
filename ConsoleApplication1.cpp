#include <iostream>
#include <string>
using namespace std;

//Задание 1

int numStudent;
enum eSex{
   Male, Female
};

class Person    
{
public:
    string m_name;
    int m_age;
    int m_weight;
    eSex m_sex;

    Person(string name = "", int age = 0, int weight = 0, eSex sex = Male)
        : m_name(name), m_age(age), m_weight(weight), m_sex(sex)
    {
    }
    void setName(string name) {
        m_name = name;
    }
    void setAge(int age){
        m_age = age;
    }
    void setWieght(int wieght) {
        m_weight = wieght;
    }

    string getName() const { return m_name; }
    int getAge() const { return m_age; }

};

class Student : public Person
{
public:
    const int m_startStudy;
    int m_numYear;

    Student(int start = 0, string name = "", int age = 0, int weight = 0, eSex sex = Male) : m_startStudy(start)
    {
        m_name = name;
        m_age = age;
        m_weight = weight;
        m_sex = sex;
        m_numYear = 0;
        numStudent++;
    }
    void setNumYear(int numYear)
    {
        m_numYear = numYear;
    }
    void incNumYear(){
        m_numYear++;
        int years = m_startStudy + m_numYear;
    }
    void printStudent(string name) const {
        string s_sex;
        if (m_sex == 0)
        {
            s_sex = "мужской";
        }
        else
        {
            s_sex = "женский";
        }
        int years = m_startStudy + m_numYear;
        std::cout << "Студент: " << m_name << " возраст: " << m_age << " вес " << m_weight << "кг. пол " << s_sex << endl;
        std::cout << "Годы обучения студента c " << m_startStudy << " по " << years << endl;
        
    }
};

// Задание 2

class Fruit
{
public:
    string Name;
    string Color;
    Fruit() {}
    Fruit(string name, string color ) {
        Name = name;
        Color = color;
    };
    ~Fruit() {
    };

    string getName() const {
        return Name;
    }
    string getColor() const {
        return Color;
    }
private:
  
};
 
class Apple : public Fruit
{
public: 
    Apple(string color) {
        Name = "apple";
        Color = color;
    }
    ~Apple() {};
   
private:
};

class Banana : public Fruit
{
public:
    Banana() {
        Name = "banana";
        Color = "yellow";
    };
    ~Banana() {};

private:

};

class GrannySmith : public Apple
{
public:
    GrannySmith() : Apple("green") {
        Name = "Granny Smith";
    };
    ~GrannySmith() {};
};

// Задание 3
class GameCycle {}; //непосредственно партия, можно еще щетчик партий.
class NPCGamer {}; // чтобы не скучно.
class Dealer {}; // без дилера ни как.
class Party {}; // собственно партия, колличеством колод (по правилам их может быть больше одной) со списком игроков, рук и т.д.
class Top {}; // вывод и сохранение в файл результатов игр, для самолюбования.

int main()
{
    // Первое задание
    setlocale(LC_ALL, "Russian");
	Person Danny("Danny", 25, 124, Male);
    Student Gerry(2021, "Gerry", 22, 64, Male);
    Gerry.setNumYear(4);
    Gerry.incNumYear();
    Gerry.printStudent("Gerry");
    std::cout << "Колличество студентов: " << numStudent << endl;

    //// Второе задание
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

