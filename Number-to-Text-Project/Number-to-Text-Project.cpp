#include <iostream>
#include <vector>
using namespace std;

// Класс единичных значений (от 1 до 9)
class Digits
{
public:
    unsigned int dig_num; // цифровое значение
    string text_num; // текстовое значение

    vector <string> digits = {
        "",
        "один",
        "два",
        "три",
        "четыре",
        "пять",
        "шесть",
        "семь",
        "восемь",
        "девять",
    };

    Digits(unsigned int n)
    {
        dig_num = n;
        text_num = digits[n - (n / 10) * 10];
    }
};

// Класс десятков 
class Tens
{
public:

    unsigned int dig_num;
    string text_num;

    vector <string> teens = {
    "десять",
    "одиннадцать",
    "двенадцать",
    "тринадцать",
    "четырнадцать",
    "пятнадцать",
    "шестнадцать",
    "семнадцать",
    "восемнадцать",
    "девятнадцать"
    };

    vector <string> tens = {
    "",
    "десять",
    "двадцать",
    "тридцать",
    "сорок",
    "пятьдесят",
    "шестьдесят",
    "семдесят",
    "восемдесят",
    "девяносто",
    };

    Tens(unsigned int n)
    {
        dig_num = n;
        if ((dig_num % 100 <= 19) & (dig_num % 100 > 9))
        {
            text_num += teens[dig_num % 100 - 10];
        }
        else
        {
            Digits A(dig_num);
            if (dig_num % 100 > 19)
                text_num += tens[((dig_num - ((dig_num / 100) * 100)) / 10)] + " ";

            text_num += A.text_num;
        }
    }
};

// Класс сотен
class Hundreds
{
public:

    unsigned int dig_num;
    string text_num;

    vector <string> hundreds = {
    "",
    "сто",
    "двести",
    "триста",
    "четыреста",
    "пятьсот",
    "шестьсот",
    "семьсот",
    "восемьсот",
    "девятьсот",
    };

    Hundreds(unsigned int n)
    {
        dig_num = n;
        text_num += hundreds[dig_num / 100] + " ";
        Tens A(n);
        text_num += A.text_num;
    }
};

// Класс тысяч
class Thousands
{
public:

    unsigned int dig_num;
    string text_num;

    Thousands(unsigned int n)
    {
        dig_num = n;

        // разделяем число на 2 части: правая часть - неизменяемая, левая часть - может меняться 
        int right = dig_num % 1000;
        Hundreds B(right);
        string text_right = B.text_num;

        if (dig_num >= 1000)
        {
            int left = dig_num / 1000;
            Hundreds A(left);
            string text_left = A.text_num;

            string middle = "тысяч";

            if (left - ((left / 10) * 10) == 1 and ((left % 100) / 10) != 1)
            {
                text_left.replace(text_left.find("один"), 4, "одна");
                middle = "тысяча";
            }

            if (left - ((left / 10) * 10) == 2 and ((left % 100) / 10) != 1)
            {
                text_left.replace(text_left.find_last_of("два") - 2, 3, "две");
                middle = "тысячи";
            }

            if (left - ((left / 10) * 10) == 3 and ((left % 100) / 10) != 1)
                middle = "тысячи";

            if (left - ((left / 10) * 10) == 4 and ((left % 100) / 10) != 1)
                middle = "тысячи";

            text_num = text_left + " " + middle + " " + text_right;
        }
        else
            text_num = text_right;
    }
};

// Класс миллионов
class Millions
{
public:
    unsigned int dig_num;
    string text_num;

    Millions(unsigned int n)
    {
        dig_num = n;

        int right = dig_num % 1000000;
        Thousands B(right);
        string text_right = B.text_num;

        if (dig_num >= 1000000)
        {
            int left = dig_num / 1000000;
            Hundreds A(left);
            string text_left = A.text_num;
            string middle = "миллионов";

            if (left - ((left / 10) * 10) == 1 and ((left % 100) / 10) != 1)
                middle = "миллион";

            if ((left - ((left / 10) * 10) == 2 and ((left % 100) / 10) != 1))
                middle = "миллиона";

            if ((left - ((left / 10) * 10) == 3 and ((left % 100) / 10) != 1))
                middle = "миллиона";

            if ((left - ((left / 10) * 10) == 4 and ((left % 100) / 10) != 1))
                middle = "миллиона";

            text_num = text_left + " " + middle + " " + text_right;
        }
        else
            text_num = text_right;
    }
};

// Класс миллиардов
class Billions
{
public:
    unsigned int dig_num;
    string text_num;

    Billions(unsigned int n)
    {
        dig_num = n;
        int right = dig_num % 1000000000;
        Millions B(right);
        string text_right = B.text_num;

        if (dig_num >= 1000000000)
        {
            int left = dig_num / 1000000000;
            Hundreds A(left);
            string text_left = A.text_num;
            string middle = "миллиардов";

            if (left - ((left / 10) * 10) == 1 and ((left % 100) / 10) != 1)
                middle = "миллиард";

            if (left - ((left / 10) * 10) == 2 and ((left % 100) / 10) != 1)
                middle = "миллиарда";

            if (left - ((left / 10) * 10) == 3 and ((left % 100) / 10) != 1)
                middle = "миллиарда";

            if (left - ((left / 10) * 10) == 4 and ((left % 100) / 10) != 1)
                middle = "миллиарда";

            text_num = text_left + " " + middle + " " + text_right;
        }
        else
            text_num = text_right;
    }
};

int main()
{
    unsigned int n; // исходное число
    string num; // текстовый формат
    setlocale(LC_ALL, "Russian");
    cout << "Введите число: ";
    cin >> n;

    if ((n == 0) or (n > 2147483647 * 2))
    {
        if (n == 0)
            cout << "ноль";
        else
            cout << "Число находится за пределами допустимых значений";
    }
    else
    {
        Billions C(n);
        num = C.text_num;

        bool flag = true;

        // Удаление лишних пробелов
        while (flag)
        {
            if (num.find("  ") != string::npos)
                num.replace(num.find("  "), 2, " ");
            else flag = false;
        }

        // Удаление первого пробела, если он есть
        if (num.size() > 0)
            if (num.at(0) == ' ')
                num = num.substr(1, num.size() - 1);

        // Печать результата
        cout << num;
    }

    return 0;
}