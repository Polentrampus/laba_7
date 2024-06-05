#include "Matrix.h"

void Matrix::create(size_t _rows, size_t _cols) {
    rows = _rows;
    cols = _cols;
    matrix = new int* [rows];
    for (size_t i = 0; i < rows; i++)
        matrix[i] = nullptr;
    for (size_t i = 0; i < rows; i++) //цикл на корректное количество строк
    {
        matrix[i] = new int[cols]; //и столбцов
    }
}

void Matrix::destroy() {
    if (matrix != nullptr) {
        for (size_t i = 0; i < rows; i++)
            if (matrix[i] != nullptr)
                delete[] matrix[i];
        delete[] matrix;
    }
}

void Matrix::copy(const Matrix& op) {
    create(op.cols, op.rows);

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            matrix[i][j] = op.matrix[i][j];
}

void Matrix::move(Matrix& op) noexcept {
    cols = op.cols;
    rows = op.rows;
    matrix = op.matrix;
    op.cols = op.rows = 0;
    op.matrix = nullptr;
}


void Matrix::SetMatrix() {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % (maxValue - minValue + 1) + minValue;
        }
    }
}

//вывод матрицы
void Matrix::PrintMatrix(const char* header) const
{
    std::cout << header << "\n\n";


    for (size_t i = 0; i < rows; i++) //цикл для корректного вывода
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "      ";
        }
        std::cout << std::endl;
    }
}

int Matrix::Get_Element(size_t r, size_t c) const
{
    /*if (r >= rows || c >= cols)
        throw std::out_of_range(err_index);*/
    return matrix[r][c];
}

// оператор доступа к элементу
int& Matrix::operator () (size_t r, size_t c) {
    /*if (r >= rows || c >= cols)
        throw std::out_of_range(err_index);*/
    return matrix[r][c];
}

// возвращает транспонированную матрицу
Matrix Matrix::Transpose() const
{
    Matrix S(cols, rows);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            S.matrix[j][i] = matrix[i][j];
    return S;
}

Matrix operator + (const Matrix& A, const Matrix& B)
{
    /*if (A.rows != B.rows || A.cols != B.cols)
        throw std::invalid_argument(err_dim);*/

    Matrix S(A.rows, A.cols);
    for (size_t i = 0; i < A.rows; i++)
    {
        for (size_t j = 0; j < A.cols; j++)
        {
            S.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }
    return S;
}

Matrix operator - (const Matrix& A, const Matrix& B)
{
    //if (A.rows != B.rows || A.cols != B.cols)
        //throw std::invalid_argument(err_dim);

    Matrix S(A.rows, A.cols);
    for (size_t i = 0; i < A.rows; i++)
    {
        for (size_t j = 0; j < A.cols; j++)
        {
            S.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }
    return S;
}

Matrix operator * (const Matrix& A, const Matrix& B)
{
    /*if (A.rows != B.cols || A.cols != B.rows)
        throw std::invalid_argument(err_dim);*/

    Matrix S = Matrix(A.rows, B.cols);

    for (size_t i = 0; i < S.rows; i++)
    {
        for (size_t j = 0; j < S.cols; j++)
        {
            S.matrix[i][j] = 0;
            for (size_t k = 0; k < A.cols; k++)
                S.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
        }
    }
    return S;
}