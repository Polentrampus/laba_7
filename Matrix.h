#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // ��� std::shuffle
#include <iterator> 
#include <stdexcept>

//const char* err_index = "index out of range";
//const char* err_dim = "illegal dimension";

class Matrix
{
private:
    int** matrix;      //��������� �� ������ ����� ���������� �������
    size_t rows;     //���-�� �����
    size_t cols;     //���-�� ��������

    void create(size_t _rows, size_t _cols);
    void destroy();
    void copy(const Matrix& op);
    void move(Matrix& op) noexcept;
    int minValue = 0, maxValue = 100;

public:

    Matrix() : matrix(nullptr), rows(0), cols(0)
    {
        std::cout << "������� ���������� �����: "; //������� ���������� �����
        std::cin >> rows; //����� "n" �� �����
        std::cout << "������� ���������� ��������: "; //������� ���������� ��������
        std::cin >> cols;//����� "m" �� �����

        create(rows, cols);
    }

    Matrix(size_t n, size_t m) : matrix(nullptr), rows(0), cols(0)
    {
        create(n, m);
    }
    Matrix(const Matrix& op) : matrix(nullptr), rows(0), cols(0) {
        copy(op);
    }
    Matrix(Matrix&& op) noexcept : matrix(nullptr), rows(0), cols(0) {
        move(op);
    }
    ~Matrix()
    {
        destroy();
    }
    Matrix& operator = (const Matrix& op) {
        if (this == &op)
            return *this;
        destroy();
        copy(op);
        return *this;
    }
    Matrix& operator = (Matrix&& op) noexcept {
        if (this == &op)
            return *this;
        destroy();
        move(op);
        return *this;
    }

    void SetMatrix();
    void PrintMatrix(const char* header) const;
    int Get_Element(size_t r, size_t c) const;
    int GetRowsMatrix() { return rows; }
    int GetColsMatrix() { return cols; }

    int& operator () (size_t r, size_t c);
    size_t Get_Row_Matrix() const{return rows;}

    // ���������� ���������� ��������
    size_t Get_Column_Matrix() const{ return cols; }

    // ���������� ����������������� �������
    Matrix Transpose() const;

    friend Matrix operator + (const Matrix& A, const Matrix& B);
    friend Matrix operator - (const Matrix& A, const Matrix& B);
    friend Matrix operator * (const Matrix& A, const Matrix& B);

};