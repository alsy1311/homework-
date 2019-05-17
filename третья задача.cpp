#include<iostream>
#include<vector>
using namespace std;
class Vector3D
{
protected:
    vector<int>v;
public:
    Vector3D( )
    {
        v.resize(3);
    }
    ~Vector3D()
    {
    }
//    функция, которая добавляет координаты
    void setValue(unsigned int i , int value )
    {
        v[i] = value;
    }
  //  функция, которая возвращает координату
    int getValue(unsigned int i) const
    {
        return v[i];
    }
    bool operator == (const Vector3D& v2) const {
        unsigned int k = 0;
        for (unsigned int i = 1; i < 4; i++)
        {
            if (v[i] == v2.getValue(i))
            {
                k = k + 1 ;
            }
        }
        return k == 3;
        };

    // Оператор != проверяет два вектора на неравенство,
    // они не равны, если хотя бы одна координата отличается
    bool operator != (const Vector3D& v2) const {
        unsigned int m = 0;
        for (unsigned int i = 1; i < 4; i++)
        {
            if (v[i] == v2.getValue(i))
            {
                m = m + 1 ;
            }
        }
        return m != 3;
        };
        Vector3D operator+ (const Vector3D& v2) const {
        int t = 0;
        Vector3D Sum;
        for (unsigned int i = 1; i < 4; i++)
        {
            t = v[i] + v2.getValue(i);
            Sum.setValue(i, t);
        }
        return Sum;
        }
        Vector3D operator- (const Vector3D& v2) const {
        int f = 0;
        Vector3D Sub;
        for (unsigned int i = 1; i < 4 ; i++)
        {
            f = v[i] - v2.getValue(i);
            Sub.setValue(i, f);
        }
        return Sub;
        }
        Vector3D operator* (const int& q) const {
        int m = 0;
        Vector3D Mult;
        for (unsigned int i = 1; i < 4; i++)
        {
            m = q * v[i] ;
            Mult.setValue(i, m);
        }
        return Mult;
        }
        int operator* (const Vector3D& v2) const {
        int p = 0 ;
        for (unsigned int i = 1; i < 4; i++)
        {
            p +=  v[i] * v2.getValue(i);
        }
        return p;
        }
};
const Vector3D operator* (const int& q, const Vector3D& v)
{
    return v * q;
}

class Matrix
{
friend class Vector3D;
protected:
    vector<double> m;
public:
    // Конструктор вектора размерности n
    Matrix()
    {
        m.resize(10);
        for(unsigned int i = 1; i < 10; ++i)
    {
        m[i] = 0;
    }
    }
    // Деструктор
    ~Matrix()
    {

    }
    double getValue(unsigned int i) const
    {
        return m[i];
    }
     // Задание значения i-ой координаты матрицы равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, double value)
    {
        m[i] = value;
    }
//перегрузим операторы
// Умножение матрицы на константу
        Matrix operator* (const int& q) const {
        Matrix Mult;
        for (unsigned int i = 1; i < 10; i++)
        {
            Mult.setValue(i, q * m[i]);
        }
        return Mult;
        }
// Сложение матриц
        Matrix operator+ (const Matrix& m2) const {
        Matrix Sum;
        for (unsigned int i = 1; i < 10; i++)
        {
            Sum.setValue(i, m[i] + m2.getValue(i));
        }
        return Sum;
        }
//Вычитание матриц
        Matrix operator- (const Matrix& m2) const {
        Matrix Sub;
        for (unsigned int i = 1; i < 10 ; i++)
        {
            Sub.setValue(i, m[i] - m2.getValue(i));
        }
        return Sub;
        }
//Умножение матриц
        Matrix operator* (const Matrix& m2) const {
        Matrix Multip;
        Multip.setValue(1, m[1] * m2.getValue(1) + m[2] * m2.getValue(4) + m[3] * m2.getValue(7));
        Multip.setValue(2, m[1] * m2.getValue(2) + m[2] * m2.getValue(5) + m[3] * m2.getValue(8));
        Multip.setValue(3, m[1] * m2.getValue(3) + m[2] * m2.getValue(6) + m[3] * m2.getValue(9));
        Multip.setValue(4, m[4] * m2.getValue(1) + m[5] * m2.getValue(4) + m[6] * m2.getValue(7));
        Multip.setValue(5, m[4] * m2.getValue(2) + m[5] * m2.getValue(5) + m[6] * m2.getValue(8));
        Multip.setValue(6, m[4] * m2.getValue(3) + m[5] * m2.getValue(6) + m[6] * m2.getValue(9));
        Multip.setValue(7, m[7] * m2.getValue(1) + m[8] * m2.getValue(4) + m[9] * m2.getValue(7));
        Multip.setValue(8, m[7] * m2.getValue(2) + m[8] * m2.getValue(5) + m[9] * m2.getValue(8));
        Multip.setValue(9, m[7] * m2.getValue(3) + m[8] * m2.getValue(6) + m[9] * m2.getValue(9));
        return Multip;
        }
        Vector3D operator* (const Vector3D& v2) const {
        Vector3D Multiply;
        Multiply.setValue(1,m[1] * v2.getValue(1) + m[2] * v2.getValue(2) + m[3] * v2.getValue(3));
        Multiply.setValue(2,m[4] * v2.getValue(1) + m[5] * v2.getValue(2) + m[6] * v2.getValue(3));
        Multiply.setValue(3,m[7] * v2.getValue(1) + m[8] * v2.getValue(2) + m[9] * v2.getValue(3));
        return Multiply;
        }
        double determinant ( ) {
        double p = 0;
        p = m[1] * (m[5] * m[9] - m[6] * m[8]) - m[2] * ( m[4] * m[9] - m[7] * m[6] ) + m[3] * ( m[4] * m[8] - m[7] * m[5] );
        return p;
        }
};
const Matrix operator* (const int& q, const Matrix& m)
{
    return m * q;
}

int main()
{
    int zv = 0;
    Vector3D av;
    av.setValue(3, 4);
    av.setValue(2, 3);
    av.setValue(1, 2);

    Vector3D bv;
    bv.setValue(3, 8);
    bv.setValue(2, 7);
    bv.setValue(1, 6);

    Vector3D cv = av + bv;
    Vector3D dv = cv * 5;
    Vector3D ev = av - bv;
    zv = av * bv;

    for(unsigned int i = 1; i < 4; ++i)
    {
        cout << dv.getValue(i) << endl;
    }
    cout << zv << endl;

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
    Vector3D v0 = a * av;
    double z = a.determinant();
   // cout << z << endl;
    for(unsigned int i = 1; i < 4; ++i)
    {
        cout << v0.getValue(i) << endl;
    }
}
