#pragma once

struct random_gen
{
    const int l_t, r_t;
    random_gen(int l, int r)
        : l_t(l), r_t(r)
    {
    }
    int operator () ()
    {
        return rand() % (r_t - l_t + 1) + l_t;
    }
};

template <class T> class Avg
{
    double res;
    int num;
public:
    explicit Avg()
    {
        res = 0;
        num = 0;
    } 
    void operator()(T x) { res += x; num++; } // ����������
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

template <class T> class Modify
{
    int(*visitor)(int x, int min);
    vector<int> v;
    T min;
public:
    explicit Modify(T min, int(*visitor)(int x, int min)) {
        this->visitor = visitor;
        this->min = min;
    }
    void operator()(T x) { 
        v.push_back(visitor(x, min)); 
    } // ����������
    vector<T> result() const { return v; } // ������� �����
};


template <class T> class Transform
{
public:
    int(*visitor)(int x, int min);
    vector<T> v;
    T min;
public:
    explicit Transform(T min, int(*visitor)(int x, int min)) {
        this->visitor = visitor;
        this->min = min;
    }
    int operator()(T x) {
        return visitor(x, min);
    } 
    vector<T> result() const { return v; } // ������� 
};