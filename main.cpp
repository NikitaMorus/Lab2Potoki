#include <iostream>
#include "Storage.h"
#include "Train.h"
#include "TextScan.h"
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    Store store; // ������, ��� ����� ��������� ������
    // ���� ����
    while (1)
    {
        string choice; // ���������� ������ ������������

        cout << "\n~~~����~~~" << endl;
        cout << "1 - ����� �� ������ ����������\n"
            << "2 - ������� ���� �������\n"
            << "3 - �������� ������������ ����\n"
            << "4 - �������� ��������\n"
            << "5 - �������� ��������\n"
            << "6 - ������� ��������\n"
            << "7 - ������� ������ �� ������" << endl;
        cout << "�����: ";
        cin >> choice; // ���� ������
        cout << "\n" << endl;

        // ��������� ����� (�������������� ��������)
        try
        {
            // ��������� ��� �������
            for (int id = 0; id < choice.size(); id++)
            {
                // ���� �����, ������ ������
                if (isalpha(choice[id])) throw "Error";
            }

            // ���� ����� �� ����� � ���������, ������ ������
            if (choice > "7" || choice < "1") throw "Error";
        }
        catch (const char* mssg) // ��������� ������
        {
            cout << "������ �����" << endl;
            exit(0);
        }

        // �������� ������ ������������
        if (choice == "1") store.FindTrain();
        else if (choice == "2") store.ExtractField();
        else if (choice == "3") store.GetFiel();
        else if (choice == "4") store.Set();
        else if (choice == "5") store.Change();
        else if (choice == "6") store.Delete();
        else if (choice == "7") TextScaner();
        else { cout << "������ �����" << endl; exit(0); }
    }

}
