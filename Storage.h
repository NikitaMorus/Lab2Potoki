#pragma once

#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

class Store
{
private:
    Train** array; // ������ ��� �������� ��������
    int countElement; // ���-�� ���������

public:
    Store(); // ����������� �� ���������
    Store(int size); // ����������� � ����������
    Store(const Store& s); // ����������� �����������
    ~Store(); // ����������

    void SortedArray(); // ���������� ����� �����
    void FindTrain(); // ����� �� ������ ����������
    void ExtractField(); // ������� �������� �������
    void GetFiel(); // �������� ����
    void Set(); // �������� �������� �������
    void Change(); // �������� ��������
    void Delete(); // ������� �������
};
