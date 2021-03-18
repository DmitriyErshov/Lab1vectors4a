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
vector<int> getNumbersFromFile(string fileName);

/*
������� modify, ����������� �������������� ����������� ����������. �� ����
������� ������ ��������� ���������, � �������� ���������� ������� ������
���������� ���������������� ���������.
*/
template <typename T>
void modify(vector<T>& v, T (*visitor)(T x, T min));

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
void modifyWithTransform(typename T::iterator begin, typename T::iterator end, int(*visitor)(int x, int min));

/*
�������, ����������� ��������� �������������� � �������������� ���������
std::for_each ������ ������� modify.
*/
template <typename T>
vector<int> modifyWithForEach(typename T::iterator begin, typename T::iterator end, int(*visitor)(int x, int min));

/*
�������, ����������� ����� � ������� �������������� �����, ������������ �
����������.
*/
template <typename T>
int calculateSum(typename vector <T> ::iterator begin, typename vector <T> ::iterator end);

template <typename T>
double calculateAvg(typename vector <T> ::iterator begin, typename vector <T> ::iterator end);

template <typename T>
int findMin(typename T::iterator begin, typename T::iterator end);

template <typename T>
void printToConsole(typename T::iterator begin, typename T::iterator end);

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

vector<int> getNumbersFromFile(string fileName)
{
    ifstream in;       // ����� ��� ������
    in.open(fileName); // �������� ���� ��� ������
    if (in.is_open())
    {
        int n;
        in >> n;
        vector<int> v1;

        int temp;
        for (int i = 0; i < n; i++)
        {
            in >> temp;
            v1.push_back(temp);
        }

        return v1;
    }
    in.close();

    return vector<int>();
}

template <typename T>
int findMin(typename T::iterator begin, typename T::iterator end) {
    typename T::iterator it = begin;

    int min = *begin;

    for (it++; it <= end - 1; it++) {
        if (*it < min) {
            min = *it;
        }
    }

    return min;
}

template <typename T>
void modify(typename T::iterator begin, typename T::iterator end, int(*visitor)(int x, int min))
{
    int min = findMin<T>(begin, end);

    typename T::iterator it;

    for (it = begin; it <= end - 1; it++) {
        *it = visitor(*it, min);
    }
}

template <typename T>
void modify(T& v, int(*visitor)(int x, int min)) {

    typename T::iterator begin = v.begin();
    typename T::iterator end = v.end();

    //modify<vector<T>>(begin, end, visitor);

	int min = int(findMin<T>(begin, end));

	for (int i = 0; i < v.size(); i++) {
		v.at(i) = visitor(v.at(i), min);
	}
}


template <typename T>
void modifyWithTransform(typename T::iterator begin, typename T::iterator end, int(*visitor)(int x, int min))
{
    int min = findMin<T>(begin, end);

    Transform s(min, visitor);

    transform(begin, end, begin, s);
}


template <typename T>
vector<int> modifyWithForEach(typename T::iterator begin, typename T::iterator end, int(*visitor)(int x, int min))
{
    int min = findMin<T>(begin, end);

    Modify s(min, visitor);

    s = std::for_each(begin, end, s);
    return s.result();
}


//template <typename T>
int calculateSum(vector<int>::iterator begin, vector<int>::iterator end)
{
    Sum<double> s;
    s = std::for_each(begin, end, s);
    return s.result();
}


double calculateAvg(vector<int>::iterator begin, vector<int>::iterator end)
{
    Avg s;
    s = std::for_each(begin, end, s);
    return s.result();
}

template <typename T>
void printToConsole(typename T::iterator begin, typename T::iterator end)
{
    typename T::iterator it;

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
