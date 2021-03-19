#pragma once
#include "utills.h"
#include "functorClasses.h"

/*
������� ���������� ���������� ����� N ������ ���������� ������� �
��������� �� -M �� M. ��� �����, N � M ��������� �� ���� �������, ����
������������ �������� ��� ��������� (������������ ������ �����-������).
����������� ��� �������� ��������� ����� � � ����� � � ��������������
��������� std::generate.
*/
void fillFileWithNumbers(string fileName, int n, int m);

/*
�������, ���������� ���� �� ����, � ������������ ����������������
���������, ����������� ������� �� �����.
*/
template <typename T>
vector<T> getNumbersFromFile(string fileName);

/*
������� modify, ����������� �������������� ����������� ����������. �� ����
������� ������ ��������� ���������, � �������� ���������� ������� ������
���������� ���������������� ���������.
*/
template <typename T>
void modify(vector <T>& v, int(*visitor)(int x, int min));

/*
������������� ������� modify, ����������� �� ���� ��������� ������ � �����
�������������� ����� ����������.
*/
template <typename T>
void modify(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min));

/*
�������, ����������� ��������� �������������� � �������������� ���������
std::transform ������ ������� modify.
*/
template <typename T>
void modifyWithTransform(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min));

/*
�������, ����������� ��������� �������������� � �������������� ���������
std::for_each ������ ������� modify.
*/
template <typename T>
vector <T> modifyWithForEach(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min));

/*
�������, ����������� ����� � ������� �������������� �����, ������������ �
����������.
*/
template <typename T>
T calculateSum(typename vector<T>::iterator begin, typename vector<T>::iterator end);

template <typename T>
double calculateAvg(typename vector<T>::iterator begin, typename vector<T>::iterator end);

template <typename T>
T findMin(typename vector <T> ::iterator begin, typename vector <T> ::iterator end);

template <typename T>
void printToConsole(typename vector<T>::iterator begin, typename vector<T>::iterator end);

template <typename T>
void printToFile(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, string fileName);
/*
������� ������ ���������� � ���� � �� ����� (�����������).
*/



void fillFileWithNumbers(string fileName, int n, int m)
{
    ofstream out;       // ����� ��� ������
    out.open(fileName); // �������� ���� ��� ������
    if (out.is_open())
    {
        vector<int> v1(n);
        std::generate_n(v1.begin(), n, random_gen(-m, m));
        out << n << endl;
        for (const int& a : v1)
            out << a << " ";

        /*for (int i = 0; i < n; i++)
        {
            out << rand() % (m - (-m) + 1) + -m << " ";
        }*/
    }
    out.close();
}

template <typename T>
vector<T> getNumbersFromFile(string fileName)
{
    vector<T> v1;
    ifstream in;       // ����� ��� ������
    in.open(fileName); // �������� ���� ��� ������
    if (in.is_open())
    {
        int n;
        in >> n;

        T temp;
        for (int i = 0; i < n; i++)
        {
            in >> temp;
            v1.push_back(temp);
        }

        return v1;
    }
    in.close();

    return v1;
}

template <typename T>
T findMin(typename vector <T> ::iterator begin, typename vector <T> ::iterator end) {
    typename vector <T> ::iterator it = begin;
    T min = *begin;

    for (it++; it <= end - 1; it++) {
        if (*it < min) {
            min = *it;
        }
    }

    return min;
}

template <typename T>
void modify(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min))
{
    T min = findMin<T>(begin, end);

    typename vector <T> ::iterator it;

    for (it = begin; it <= end - 1; it++) {
        *it = visitor(*it, min);
    }
}

template <typename T>
void modify(vector <T>& v, int(*visitor)(int x, int min)) {

    typename vector <T> ::iterator begin = v.begin();
    typename vector <T> ::iterator end = v.end();
    //modify<vector<T>>(begin, end, visitor);

	T min = findMin<T>(begin, end);

	for (int i = 0; i < v.size(); i++) {
		v.at(i) = visitor(v.at(i), min);
	}
}


template <typename T>
void modifyWithTransform(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min))
{
    T min = findMin<T>(begin, end);

    Transform<T> s(min, visitor);

    transform(begin, end, begin, s);
}


template <typename T>
vector <T> modifyWithForEach(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, int(*visitor)(int x, int min))
{
    T min = findMin<T>(begin, end);

    Modify<T> s(min, visitor);

    s = std::for_each(begin, end, s);
    return s.result();
}


template <typename T>
T calculateSum(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
    Sum<T> s;
    s = std::for_each(begin, end, s);
    return s.result();
}

template <typename T>
double calculateAvg(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
    Avg<T> s;
    s = std::for_each(begin, end, s);
    return s.result();
}

template <typename T>
void printToConsole(typename vector<T>::iterator begin, typename vector<T>::iterator end)
{
    typename vector <T> ::iterator it;

    for (it = begin; it <= end - 1; it++) {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T>
void printToFile(typename vector <T> ::iterator begin, typename vector <T> ::iterator end, string fileName)
{
    ofstream out;       // ����� ��� ������
    out.open(fileName); // �������� ���� ��� ������
    if (out.is_open())
    {
        typename vector <T> ::iterator it;

        for (it = begin; it <= end - 1; it++) {
            out << *it << " ";
        }
    }
    out.close();
}
