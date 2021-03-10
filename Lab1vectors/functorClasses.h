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
    } // �������������
    void operator()(int x) { res += x; num++; } // ����������
    double result() {
        if (num != 0) {
            res /= num;
        }
        return res;
    } // ������� �����
};

template <class T> class Sum
{
    T res;
public:
    explicit Sum(T i = 0) : res(i) {} // �������������
    void operator()(T x) { res += x; } // ����������
    T result() const { return res; } // ������� �����
};

class Modify
{
    int(*visitor)(int x, int min);
    vector<int> v;
    int min;
public:
    explicit Modify(int min, int(*visitor)(int x, int min)) {
        this->visitor = visitor;
        this->min = min;
    }
    void operator()(int x) { 
        v.push_back(visitor(x, min)); 
    } // ����������
    vector<int> result() const { return v; } // ������� �����
};

class Transform
{
    double _halfMax;
    int countNegative = 0;

public:
    int(*visitor)(int x, int min);
    vector<int> v;
    int min;
public:
    explicit Transform(int min, int(*visitor)(int x, int min)) {
        this->visitor = visitor;
        this->min = min;
    }
    int operator()(int x) {
        return visitor(x, min);
    } 
    vector<int> result() const { return v; } // ������� 
};