#include <iostream>

using namespace std;

//класс для представления суммы на счете
class money {
private:
    double amount; // сумма на счете

public:
    money() : amount(0) {} // конструктор по умолчанию инициализирует сумму нулем

    money(double amount) { // конструктор для установки начальной суммы на счете
        if (amount < 0) {
            throw invalid_argument("Сумма не может быть отрицательной!!! "); // проверка на отрицательную сумму
        }
        this->amount = amount;
    }

    double getAmount() const { // метод для получения суммы на счете
        return amount;
    }
};

// класс для представления даты открытия счета
class Date {
private:
    int day, month, year; // День, месяц, год

public:
    Date() : day(1), month(1), year(2000) {} // конструктор по умолчанию инициализирует дату 01/01/2000

    Date(int day, int month, int year) { // конструктор для установки даты открытия счета
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) { // проверка даты
            throw invalid_argument("не существует такой даты ты чо ");
        }
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void display() const {                       // метод для вывода даты открытия счета
        cout << day << "/" << month << "/" << year << endl;
    }
};

// класс для представления банковского счета
class Account {
private:
    money balance; // сумма на счете и дата открытия счета
    Date openingDate;

public:
    // конструктор для создания счета с начальной суммой и датой открытия
    Account(double initialBalance, int day, int month, int year) {
        try {
            balance = money(initialBalance); //установка начальной суммы и даты открытия счета
            openingDate = Date(day, month, year);
        }
        catch (const invalid_argument& e) { // обработка ошибок
            cerr << "ошибочкк: " << e.what() << endl; // вывод ошибки
            throw; // пробрасывание исключения выше
        }
    }

    // метод для вводда данных с клавиатуры (начальной суммы и даты открытия счета)
    void read() {
        double initialBalance;
        int day, month, year;

        cout << "Введите первоначальный баланс: ";
        cin >> initialBalance;

        cout << "Введите дату открытия (день месяц год(раздельно) ): ";
        cin >> day >> month >> year;

        try {
            balance = money(initialBalance); // установка начальной суммы
            openingDate = Date(day, month, year); // установка даты открытия счета
        }
        catch (const invalid_argument& e) { // обработка ошибок
            cerr << "ошибочка: " << e.what() << endl; // вывод ошибки еще разочек
            throw; // пробрасывание исключения выше
        }
    }

    // метод для вывода данных на экран (текущей суммы на счете и даты открытия счета)
    void display() const {
        cout << "Баланс: " << balance.getAmount() << endl; // вывод текущей суммы на счете
        cout << "Дата открытия: ";
        openingDate.display(); // вывод даты открытия счета
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        Account account(0, 1, 1, 2024); // создание объекта класса Account с начальной суммой и датой открытия
        account.read(); // ывод данных с клавиатуры
        account.display(); // вывод данных на экран
    }
    catch (const invalid_argument& e) { // обработка ошибок
        cerr << "ошибка: " << e.what() << endl; // вывод ошибки
    }

    return 0;
}
