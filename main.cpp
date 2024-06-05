#include "Matrix.h"
#include <windows.h>
#include <conio.h> //_kbhit � _getch

int main()
{
    try {
        setlocale(LC_ALL, "ru");
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;
        char ch;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;//������ �������

        int a;
        while (true) {
            system("cls");
            std::cout << std::string(columns / 2.5, ' ') << "���� ��������:" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "ESC - �����" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "����� �������� ����� �������, ������� 1" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "����� �������� �������� �������, ������� 2" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "����� �������� ������������ �������, ������� 3" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "����� ��������������� �������, ������� 4" << std::endl;

            ch = _getch();
            if (ch == 27) { // ASCII-��� ESC
                break;
            }
            
            switch (ch)
            {
            case '1':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("������� 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("������� 2:");
                if (mx1.GetRowsMatrix() == mx2.GetRowsMatrix() && mx1.GetColsMatrix() == mx2.GetColsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 + mx2).PrintMatrix("����� ������:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "������� ������ ����� ���������� �����������! ���������� ��� ���." << std::endl; system("pause"); }
            }

            case '2':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("������� 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("������� 2:");
                if (mx1.GetRowsMatrix() == mx2.GetRowsMatrix() && mx1.GetColsMatrix() == mx2.GetColsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 - mx2).PrintMatrix("�������� ������:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "������� ������ ����� ���������� �����������! ���������� ��� ���." << std::endl; system("pause"); }
            }

            case '3':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("������� 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("������� 2:");
                if (mx1.GetColsMatrix() == mx2.GetRowsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 * mx2).PrintMatrix("������������ ������:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "������� ������ ����� ����������� m,p �� p,n! ���������� ��� ���." << std::endl; system("pause"); }
            }
            case '4':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();
                mx1.PrintMatrix("�������:");
                mx1 = mx1;

                std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                mx1 = mx1.Transpose();
                mx1.PrintMatrix("����������������� �������:");
                std::cout << std::endl;
                
                Sleep(5000);
                break;
            }
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return 0;
}