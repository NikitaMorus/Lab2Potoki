#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // ������� ����� �����
    file.open("Text.txt"); // �������� �����

    if (!file.is_open()) // ���� ���� �� ��������
    {
        cout << "������ �������� �����!" << endl;
        exit(0);
    }

    else
    {
        string line; // ������, � ������� ����� ����������� �������� �� �����
        unsigned int flag_one = 0; // "" ���� �� ������� �������
        unsigned int flag_two = 0; // '' ���� �� ��������� ������� 

        while (!file.eof()) // ���� �� ����� �����
        {
            getline(file, line); // ��������� ������ 

            for (int id = 0; id < line.size(); id++) // ���������� ������� � ������
            {
                if (flag_one) // ���� ������� ������� ����������� ������
                { 
                    if (line[id] == '"') // ���� ������ ����������� ������� �������
                    {
                        flag_one = 0; // ������ ���� 
                        cout << "\n";
                        continue; // ��������� �� ��������� ��������
                    } 

                    cout << line[id]; // ������� �������
                }

                else if (flag_two) // ���� ��������� ������� (���������� � ��������)
                {
                    if (line[id] == '\'')
                    { 
                        cout << "\n";
                        continue;
                    }
                     
                    cout << line[id];
                }

                if (line[id] == '"' && flag_two == 0) flag_one = 1; // ���� ����������� ������� ������� � �� ���� ���������, ������ ����
                if (line[id] == '\'' && flag_one == 0) flag_two = 1; // ��� ��, ��� � � ��������, ������ � ����������
            }
        }
    }
     
    file.close(); // ��������� ����
}
 