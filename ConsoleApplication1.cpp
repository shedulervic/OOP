#include <iostream>
#include <cstdint>
#define SIZE 10
using namespace std;

//1. Создать класс Power, который содержит два вещественных числа. 

class Power
{
    float aP;
    float bP;
public:
Power() : aP(1), bP(1){};
Power(float a, float b)
{
    aP = a;
    bP = b;
}

~Power(){}

void setPower(float a, float b)
{
    aP = a;
    bP = b;
}

void calculatePower()
{
    std::cout << aP << " в степени " << bP << " = " << pow(aP, bP);
}
};

//Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу).

class RGBA
{
    std::uint8_t m_red;
    std::uint8_t m_green;
    std::uint8_t m_blue;
    std::uint8_t m_alpha;
public:
    RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {};

    RGBA(int red, int green, int blue, int alpha)
    {
        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    }

    ~RGBA(){}

    void printRGBA()
    {
        //Добавление унарного оператора + перед переменной любого примитивного типа данных даст печатное числовое значение вместо символа ASCII.
        std::cout << "red: " << +m_red << " green: " << +m_green << " blue: " << +m_blue << " alpha: " << +m_alpha << endl;
    }
};

// Написать класс, который реализует функциональность стека. 

class Stack
{
    int cursor = -1;
    int stack[SIZE];
public:
    Stack() {}
    ~Stack() {}
    void push(int data)
    {
        if (cursor < SIZE)
        {
            stack[++cursor] = data;
        }
        else
        {
            std::cout << "Стек заполнен!" << endl;;
        }
    }
    int pop()
    {
        if (cursor != -1)
        {
            return stack[cursor--];
        }
        else
        {
            std::cout << "Стек пуст!" << endl;
            return -1;
        }
    }
    void reset()
    {
        cursor = -1;
    }
    void print()
    {
        if (cursor != -1)
        {
            std::cout << "(";
            for (int i = 0; i <= cursor; i++)
            {
                std::cout << stack[i] << " ";
            }
            std::cout << ")" << endl;
        }
        else
        {
            std::cout << "()" << endl;
        }
           
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задание 1
    Power pow;
    pow.setPower(4, 4);
    pow.calculatePower();
    std::cout << endl;

    Power pow2(2, 2);
    pow2.calculatePower();
    std::cout << endl;

    // Задание 2
    RGBA myrgba;
    myrgba.printRGBA();
    std::cout << endl;

    // Задание 3
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();

}


