#include <iostream>
#include <string.h>
#include "Train.h"
#include <string>

using namespace std;

// ����������� �� ���������
Train::Train()
{
    this->destination = "None";
    this->train_number = "None";
    this->departure_time = "None";

    cout << "������ ����������� �� ��������� ������ Train" << endl;
}

// ����������� � ����������
Train::Train(string destination, string train_number, string departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;

    cout << "������ ����������� � ���������� ������ Train" << endl;
}

// ����������� �����������
Train::Train(const Train& t)
{
    this->destination = t.destination;
    this->train_number = t.train_number;
    this->departure_time = t.departure_time;

    cout << "������ ����������� ����������� ������ Train" << endl;
}

// ����������
Train::~Train()
{
    cout << "������ ���������� ������ Train" << endl;
}

// ����� ���������� �����
void Train::Extract()
{
    cout << *this;
}

// ����� ��������� �����
void Train::Get()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice; // ���������� ������ ����
    cout << "\n��� ������ ��������?\n" <<
        "1 - ����� ����������\n" <<
        "2 - ����� ������\n" <<
        "3 - ����� �����������\n" <<
        "4 - ��� ����" << endl;
    cout << "�����: ";
    cin >> choice; // ����

    // ��������� �������������� ��������
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "�������� ����" << endl;
    }

    if (choice == "1") cout << "����� ����������: " << this->destination << endl;
    else if (choice == "2") cout << "����� ������: " << this->train_number << endl;
    else if (choice == "3") cout << "����� �����������: " << this->departure_time << endl;
    else if (choice == "4") cout << "����� ����������: " << this->destination << " | ����� ������: " << this->train_number << " | ����� �����������: " << this->departure_time << endl;
    else
    {
        cout << "������ ������" << endl;
        exit(0);
    }
}

// ����� ��������� ���� ������� (��� ����������)
string Train::GetTime()
{
    return this->departure_time;
}

// ����� ��������� ������ ����������
string Train::GetDestination()
{
    return this->destination;
}

// ����� ��������� ������ ������
string Train::GetTrainNumber()
{
    return this->train_number;
}

// ����� ��������� ��������
void Train::Set()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    cin >> *this;
}

void Train::Change()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice;
    cout << "\n��� ������ ��������?\n" <<
        "1 - ����� ����������\n" <<
        "2 - ����� ������\n" <<
        "3 - ����� �����������" << endl;
    cout << "�����: ";
    cin >> choice;

    // ��������� �������������� ��������
    try
    {
        for (int id = 0; id < choice.size(); id++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch (const char* mssg)
    {
        cout << "�������� ����" << endl;
    }

    if (choice == "1")
    {
        getline(cin, choice);

        cout << "����� ����������: ";
        getline(cin, this->destination);
    }

    else if (choice == "2")
    {
        getline(cin, choice);

        cout << "����� ������: ";
        getline(cin, this->train_number);
    }

    else if (choice == "3")
    {
        getline(cin, choice);

        cout << "����� �����������: ";
        getline(cin, this->departure_time);
    }

    else
    {
        cout << "������ ������" << endl;
        exit(0);
    }
}

// ���������� ��������� ������
std::ostream& operator<< (std::ostream& stream, Train& t) // ���������� ��������� �����������
{
    stream << "\n��� ���� ������:" << endl;
    stream << t.destination << endl;
    stream << t.train_number << endl;
    stream << t.departure_time << endl;

    return stream;
}

// ���������� ��������� �����
std::istream& operator>> (std::istream& stream, Train& t) // ���������� ��������� �������
{
    string buf;

    cout << "\n������� ��������:" << endl;
    cout << "����� ����������: ";
    getline(stream, buf);
    t.destination = buf;

    cout << "����� ������: ";
    getline(stream, buf);
    t.train_number = buf;

    cout << "����� ����������: ";
    getline(stream, buf);
    t.departure_time = buf;

    return stream;
}
