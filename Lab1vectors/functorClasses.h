#pragma once

class Avg
{
    double res;
    int num;
public:
    explicit Avg()
    {
        res = 0;
        num = 0;
    } // инициализация
    void operator()(int x) { res += x; num++; } // накопление
    double result() {
        if (num != 0) {
            res /= num;
        }
        return res;
    } // возврат суммы
};

template <class T> class Sum
{
    T res;
public:
    explicit Sum(T i = 0) : res(i) {} // инициализация
    void operator()(T x) { res += x; } // накопление
    T result() const { return res; } // возврат суммы
};

class Modify
{
    int(*visitor)(int x);
    vector<int> v;
public:
    explicit Modify(int(*visitor)(int x)) {
        this->visitor = visitor;
    }
    void operator()(int x) { v.push_back(visitor(x)); } // накопление
    vector<int> result() const { return v; } // возврат суммы
};