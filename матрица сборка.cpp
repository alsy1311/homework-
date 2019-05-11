#include<iostream>
#include<vector>
using namespace std;
class Vectorok
{
protected:
    unsigned int k;
    double value;
    unsigned int i;

public:
    vector<double> p;
    // Конструктор вектора размерности n
    Vectorok()
    {
        this->k = 3;
        p.resize(k+1);
        for(unsigned int i = 1; i < 4; ++i)
    {
        p[i] = 0;
    }

    }
    // Деструктор
    ~Vectorok()
    {

    }
    double getValue(unsigned int i) const
    {
        return p[i];
    }
     // Задание значения i-ой координаты матрицы равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, double value)
    {
        p[i] = value;
    }
};

class Matrix
{
friend class Vectorok;
protected:
    unsigned int n;
    double value;
    unsigned int i;

public:
    vector<double> v;
    // Конструктор вектора размерности n
    Matrix()
    {
        this->n = 9;
        v.resize(n+1);
        for(unsigned int i = 1; i < 10; ++i)
    {
        v[i] = 0;
    }
    }
    // Деструктор
    ~Matrix()
    {

    }
    double getValue(unsigned int i) const
    {
        return v[i];
    }
     // Задание значения i-ой координаты матрицы равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, double value)
    {
        v[i] = value;
    }
//перегрузим операторы
// Умножение матрицы на константу
        Matrix operator* (const int& q) const {
        Matrix Mult;
        for (unsigned int i = 1; i < n + 1; i++)
        {
            Mult.setValue(i, q * v[i]);
        }
        return Mult;
        }
// Сложение матриц
        Matrix operator+ (const Matrix& v2) const {
        Matrix Sum;
        for (unsigned int i = 1; i < n + 1; i++)
        {
            Sum.setValue(i, v[i] + v2.getValue(i));
        }
        return Sum;
        }
//Вычитание матриц
        Matrix operator- (const Matrix& v2) const {
        Matrix Sub;
        for (unsigned int i = 1; i < n + 1 ; i++)
        {
            Sub.setValue(i, v[i] - v2.getValue(i));
        }
        return Sub;
        }
//Умножение матриц
        Matrix operator* (const Matrix& v2) const {
        Matrix Multip;
        Multip.setValue(1, v[1] * v2.getValue(1) + v[2] * v2.getValue(4) + v[3] * v2.getValue(7));
        Multip.setValue(2, v[1] * v2.getValue(2) + v[2] * v2.getValue(5) + v[3] * v2.getValue(8));
        Multip.setValue(3, v[1] * v2.getValue(3) + v[2] * v2.getValue(6) + v[3] * v2.getValue(9));
        Multip.setValue(4, v[4] * v2.getValue(1) + v[5] * v2.getValue(4) + v[6] * v2.getValue(7));
        Multip.setValue(5, v[4] * v2.getValue(2) + v[5] * v2.getValue(5) + v[6] * v2.getValue(8));
        Multip.setValue(6, v[4] * v2.getValue(3) + v[5] * v2.getValue(6) + v[6] * v2.getValue(9));
        Multip.setValue(7, v[7] * v2.getValue(1) + v[8] * v2.getValue(4) + v[9] * v2.getValue(7));
        Multip.setValue(8, v[7] * v2.getValue(2) + v[8] * v2.getValue(5) + v[9] * v2.getValue(8));
        Multip.setValue(9, v[7] * v2.getValue(3) + v[8] * v2.getValue(6) + v[9] * v2.getValue(9));
        return Multip;
        }
        Vectorok operator* (const Vectorok& v2) const {
        Vectorok Multiply;
        Multiply.setValue(1,(v[1] + v[2] + v[3]) * v2.getValue(1) );
        Multiply.setValue(2,(v[4] + v[5] + v[6]) * v2.getValue(2) );
        Multiply.setValue(3,(v[7] + v[8] + v[9]) * v2.getValue(3) );
        return Multiply;
        }
        double determinant ( ) {
        double p = 0;
        p = v[1] * (v[5] * v[9] - v[6] * v[8]) - v[2] * ( v[4] * v[9] - v[7] * v[6] ) + v[3] * ( v[4] * v[8] - v[7] * v[5] );
        return p;
        }
};
const Matrix operator* (const int& q, const Matrix& v)
{
    return v * q;
}

int main()
{
    Vectorok o;
    o.setValue(3,1);
    o.setValue(2,1);
    o.setValue(1,1);

    Matrix a;
    a.setValue(9, 2);
    a.setValue(8, 2);
    a.setValue(7, 2);
    a.setValue(6, 2);
    a.setValue(5, 2);
    a.setValue(4, 2);
    a.setValue(3, 2);
    a.setValue(2, 2);
    a.setValue(1, 2);

    Matrix b;
    b.setValue(9, 1);
    b.setValue(8, 1);
    b.setValue(7, 1);
    b.setValue(6, 1);
    b.setValue(5, 1);
    b.setValue(4, 1);
    b.setValue(3, 1);
    b.setValue(2, 1);
    b.setValue(1, 1);

    Matrix c = a + b;
    Matrix d = c * 5;
    Matrix e = a - b;
    Matrix g = a * b;
    Vectorok v = a * o;
    double z = a.determinant();
    cout << z << endl;

    for(unsigned int i = 1; i < 4; ++i)
    {
        cout << v.getValue(i) << endl;
    }
}
