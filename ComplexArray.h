//
// Created by Parth Parakh on 09/01/21.
//

#ifndef IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_COMPLEXARRAY_H
#define IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_COMPLEXARRAY_H

class Complex
{
private:
    double real;
    double complex;
public:
    Complex(int size);
    virtual ~Complex() = default;
};

class ComplexArray
{
private:
    Complex *array;
    int size;
public:
    ComplexArray()=default;
    ~ComplexArray() ;
    ComplexArray(int size_);
    ComplexArray(const ComplexArray &rhs);
    ComplexArray &operator = ( const ComplexArray &rhs)  ;
    ComplexArray &operator [] (ComplexArray &rhs);
    const ComplexArray &operator [] (const ComplexArray &rhs) const;
    int minindex() const;
    int maxindex() const;
};

ComplexArray::ComplexArray(int size_) : size(size_)
{
    array = new Complex(size);
    for(int i=0;i<size;i++)
    {
        array[i] = 0;
    }
}

ComplexArray::~ComplexArray()
{
    delete [] array;
}

#endif //IMPLIED_VOLATILITY_USING_NEWTON_RAPSON_COMPLEXARRAY_H
