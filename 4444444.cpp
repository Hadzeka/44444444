#include <iostream>

using namespace std;

//����� ��� ������������� ����� �� �����
class Money {
private:
    double amount; // ����� �� �����

public:
    Money() : amount(0) {} // ����������� �� ��������� �������������� ����� �����

    Money(double amount) { // ����������� ��� ��������� ��������� ����� �� �����
        if (amount < 0) {
            throw invalid_argument("����� �� ����� ���� ������������� "); // �������� �� ������������� �����
        }
        this->amount = amount;
    }

    double getAmount() const { // ����� ��� ��������� ����� �� �����
        return amount;
    }
};

// ����� ��� ������������� ���� �������� �����
class Date {
private:
    int day, month, year; // ����, �����, ���

public:
    Date() : day(1), month(1), year(2000) {} // ����������� �� ��������� �������������� ���� 01/01/2000

    Date(int day, int month, int year) { // ����������� ��� ��������� ���� �������� �����
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) { // �������� ����
            throw invalid_argument("�� ���������� ����� ���� �� �� ");
        }
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void display() const {                       // ����� ��� ������ ���� �������� �����
        cout << day << "/" << month << "/" << year << endl;
    }
};

// ����� ��� ������������� ����������� �����
class Account {
private:
    Money balance; // ����� �� ����� � ���� �������� �����
    Date openingDate;

public:
    // ����������� ��� �������� ����� � ��������� ������ � ����� ��������
    Account(double initialBalance, int day, int month, int year) {
        try {
            balance = Money(initialBalance); //��������� ��������� ����� � ���� �������� �����
            openingDate = Date(day, month, year);
        }
        catch (const invalid_argument& e) { // ��������� ������
            cerr << "��������: " << e.what() << endl; // ����� ������
            throw; // ������������� ���������� ����
        }
    }

    // ����� ��� ������ ������ � ���������� (��������� ����� � ���� �������� �����)
    void read() {
        double initialBalance;
        int day, month, year;

        cout << "������� �������������� ������: ";
        cin >> initialBalance;

        cout << "������� ���� �������� (���� ����� ���(���������) ): ";
        cin >> day >> month >> year;

        try {
            balance = Money(initialBalance); // ��������� ��������� �����
            openingDate = Date(day, month, year); // ��������� ���� �������� �����
        }
        catch (const invalid_argument& e) { // ��������� ������
            cerr << "��������: " << e.what() << endl; // ����� ������ ��� �������
            throw; // ������������� ���������� ����
        }
    }

    // ����� ��� ������ ������ �� ����� (������� ����� �� ����� � ���� �������� �����)
    void display() const {
        cout << "������: " << balance.getAmount() << endl; // ����� ������� ����� �� �����
        cout << "���� ��������: ";
        openingDate.display(); // ����� ���� �������� �����
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    try {
        Account account(0, 1, 1, 2024); // �������� ������� ������ Account � ��������� ������ � ����� ��������
        account.read(); // ���� ������ � ����������
        account.display(); // ����� ������ �� �����
    }
    catch (const invalid_argument& e) { // ��������� ������
        cerr << "������: " << e.what() << endl; // ����� ������
    }

    return 0;
}