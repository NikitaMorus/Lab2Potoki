#pragma once

#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
    string destination; // ����� ����������
    string train_number; // ����� ������
    string departure_time; // ����� �����������

public:
    Train(); // ����������� �� ���������
    Train(string destination, string train_number, string departure_time); // ����������� � ����������
    Train(const Train& t); // ����������� �����������
    ~Train(); // ����������

    void Extract(); // ����� ���������� ��������
    void Get(); // ����� ��������� �����
    string GetTime(); // ����� ��������� ���� ������� ��� ��������������
    string GetDestination(); // ����� ��������� ������ ����������
    string GetTrainNumber(); // ����� ��������� ������ ������
    void Set(); // ����� ��������� ��������
    void Change(); // ����� �������������� ��������

    friend ostream& operator<< (ostream& stream, Train& t); // ���������� ��������� �����������
    friend istream& operator>> (istream& stream, Train& t); // ���������� ��������� �������
};
