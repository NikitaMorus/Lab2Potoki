#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Train.h"

using namespace std;

// ����������� �� ���������
Store::Store()
{
    this->array = new Train * [1]; // �������� ������
    this->countElement = 0; // ���-�� ��������� = 0
    cout << "������ ����������� �� ��������� ������ Store" << endl;
}

// ����������� � ����������
Store::Store(int size)
{
    this->array = new Train * [size]; // �������� ������ ��� ������
    this->countElement = 0; // ���-�� ��������� = 0
    cout << "������ ����������� c ���������� ������ Store" << endl;
}

// ����������� �����������
Store::Store(const Store& s)
{
    this->countElement = s.countElement; // �������� ���-�� ���������
    this->array = new Train * [this->countElement]; // �������� ����������� ���-�� ������

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id]; // �������� ������ ��������

    cout << "������ ����������� ����������� ������ Store" << endl;
}

// ����������
Store::~Store()
{
    delete array; // ����������� ���������� ������
    cout << "������ ���������� ������ Store" << endl;
}

// ���������� �������
void Store::SortedArray()
{
    // ����� ���������� - ���������
    for (int id1 = 0; id1 < countElement; id1++) // ���-�� �������� = ���-�� ���������
    {
        for (int id2 = 0; id2 < countElement - 1; id2++) // ���������� �������� �� ������ �� ����������
        {
            if (array[id2]->GetTime() > array[id2 + 1]->GetTime()) // ���� ������� ������ ������������, �� ������ �� �������
            {
                Train* buf = array[id2];
                array[id2] = array[id2 + 1];
                array[id2 + 1] = buf;
            }
        }
    }
}

// ����� �� ������ ����������
void Store::FindTrain()
{
    // ������� ����� �����
    string buf;
    getline(cin, buf);

    string findDestination; // ����������, ������� ������ �������� �������� ������
    cout << "\n����� ������ ���������� � �������, ������� ����� ����������: ";
    getline(cin, findDestination); // ����

    int flagFind = 0; // ����, ���� �� ��������� ������ �� ������ ����������

    cout << "\n~���������� � �������~" << endl;

    for (int id = 0; id < countElement; id++) // ���������� ��� ��������
    {

        if (findDestination == array[id]->GetDestination()) // ���� ����� ����� ����
        {
            flagFind = 1; // ������ ����, ��� ��� ����� �����
            cout << array[id]->GetTrainNumber() << endl; // ������� ����� ������
        }
    }

    if (!flagFind) cout << "\n������� �� ������ �������� ���!" << endl; // ���� ������� �� ������ ������ ���
}

// ���������� ���� ��������
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract(); // ������� ��� ��������
}

// ��������� �����
void Store::GetFiel()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    string choice; // ���������� ������ ��������
    cout << "\n������� ����� ��������, ���� �������� �� ������ �������: ";
    cin >> choice; // ����

    // �������� �� ������������ ����� (������ � �������������� ���������)
    try
    {
        // ���� � ������ ���� �����, ���������� ������
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // ���� � ������ ���� �����, ���������� ������
        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch (const char* mssg) // ��������� ������
    {
        cout << "�������� ����!" << endl;
        exit(0);
    }

    // ���� ����� �������� ��������� �������� ���-�� ��������� ��� ������ 0, �� ������
    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "������ �����" << endl;
        exit(0);
    }

    // �����
    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get(); // ������� ����
    }
}

// ����� ��������� ��������
void Store::Set()
{
    Train* train = new Train(); // ������� ��������� �� ������
    train->Set(); // �������� ����� ����� �������
    array[countElement++] = train; // ��������� � ������
    this->SortedArray(); // ��������� ������ �� ������� �����������
}

// ����� ��������� ��������
void Store::Change()
{
    // �������� ����� �����
    string buf;
    getline(cin, buf);

    cout << "\n�������� ����� ��������, ������ �������� ������ ��������: ";
    string choice; // ���������� ������ ��������, �������� �������� �� ����� ��������
    cin >> choice; // ����

    // ��������� �������������� �������� (�������� �� ����)
    try
    {
        // ��������� ��� �� ����
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        // ���� �� ����� � ���������
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch (const char* mssg) // ��������� ������
    {
        cout << "������ �����!" << endl;
        exit(0);
    }

    // �������� ����� ��������� �������
    array[stoi(choice)]->Change();
}

// ����� ��������
void Store::Delete()
{
    // ������� ����� �����
    string buf;
    getline(cin, buf);

    cout << "\n�������� ����� ��������, ������ �������� ������ �������: ";
    string choice; // ���������� ����� ������ ��������
    cin >> choice; // ����

    // ��������� �������������� ��������
    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch (const char* mssg)
    {
        cout << "������ �����!" << endl;
        exit(0);
    }

    // �������� ��������
    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id + 1];
    countElement--;
}
