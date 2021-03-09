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
    int(*visitor)(int x);
    vector<int> v;
public:
    explicit Modify(int(*visitor)(int x)) {
        this->visitor = visitor;
    }
    void operator()(int x) { v.push_back(visitor(x)); } // ����������
    vector<int> result() const { return v; } // ������� �����
};