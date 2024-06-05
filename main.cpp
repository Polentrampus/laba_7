#include "Matrix.h"
#include <windows.h>
#include <conio.h> //_kbhit и _getch

int main()
{
    try {
        setlocale(LC_ALL, "ru");
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;
        char ch;

        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;//размер консоли

        int a;
        while (true) {
            system("cls");
            std::cout << std::string(columns / 2.5, ' ') << "Ваши действия:" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "ESC - ВЫХОД" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "Чтобы ПОЛУЧИТЬ СУММУ МАТРИЦЫ, нажмите 1" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "Чтобы ПОЛУЧИТЬ РАЗНОСТЬ МАТРИЦЫ, нажмите 2" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "Чтобы ПОЛУЧИТЬ ПРОИЗВЕДЕНИЕ МАТРИЦЫ, нажмите 3" << std::endl;
            std::cout << std::string(columns / 0.8, ' ') << "Чтобы ТРАНСПОНИРОВАТЬ МАТРИЦУ, нажмите 4" << std::endl;

            ch = _getch();
            if (ch == 27) { // ASCII-код ESC
                break;
            }
            
            switch (ch)
            {
            case '1':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("Матрица 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("Матрица 2:");
                if (mx1.GetRowsMatrix() == mx2.GetRowsMatrix() && mx1.GetColsMatrix() == mx2.GetColsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 + mx2).PrintMatrix("Сумма матриц:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "Матрицы должны иметь одинаковую размерность! Попробуйте еще раз." << std::endl; system("pause"); }
            }

            case '2':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("Матрица 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("Матрица 2:");
                if (mx1.GetRowsMatrix() == mx2.GetRowsMatrix() && mx1.GetColsMatrix() == mx2.GetColsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 - mx2).PrintMatrix("Разность матриц:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "Матрицы должны иметь одинаковую размерность! Попробуйте еще раз." << std::endl; system("pause"); }
            }

            case '3':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();

                mx1.PrintMatrix("Матрица 1:");

                Matrix mx2;
                mx2.SetMatrix();
                mx2.PrintMatrix("Матрица 2:");
                if (mx1.GetColsMatrix() == mx2.GetRowsMatrix())
                {
                    std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                    (mx1 * mx2).PrintMatrix("Произведение матриц:");
                    std::cout << std::endl;

                    Sleep(5000);
                    break;
                }
                else { system("cls"); std::cout << "Матрицы должны иметь размерность m,p на p,n! Попробуйте еще раз." << std::endl; system("pause"); }
            }
            case '4':
            {
                system("cls");
                Matrix mx1;
                mx1.SetMatrix();
                mx1.PrintMatrix("Матрица:");
                mx1 = mx1;

                std::cout << std::string(columns + 30, ' ') << "=" << std::endl;

                mx1 = mx1.Transpose();
                mx1.PrintMatrix("Транспонированная матрица:");
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