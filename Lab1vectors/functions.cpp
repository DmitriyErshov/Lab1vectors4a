#include "functions.h"





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



void modify(vector<int>& v, int (*visitor)(int x)) {
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = visitor(v.at(i));
    }
}

void modify(vector<int>::iterator begin, vector<int>::iterator end, int(*visitor)(int x))
{
    vector <int> :: iterator it;

    for (it = begin; it <= end - 1; it++) {
        *it = visitor(*it);
    }
}

void modifyWithTransform(vector<int>::iterator begin, vector<int>::iterator end, int(*visitor)(int x))
{
    transform(begin, end, begin, visitor);
}



vector<int> modifyWithForEach(vector<int>::iterator begin, vector<int>::iterator end, int(*visitor)(int x))
{
    //for_each(begin, end, visitor);
    Modify s(visitor);
    // ���������� ����� ��������� ������
    s = std::for_each(begin, end, s);
    return s.result();
}



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

void printToConsole(vector<int>::iterator begin, vector<int>::iterator end)
{
    vector <int> ::iterator it;

    for (it = begin; it <= end - 1; it++) {
        cout << *it;
    }
}

void printToFile(vector<int>::iterator begin, vector<int>::iterator end, string fileName)
{
    ofstream out;       // ����� ��� ������
    out.open(fileName); // �������� ���� ��� ������
    if (out.is_open())
    {   
        vector <int> ::iterator it;

        for (it = begin; it <= end - 1; it++) {
            out << *it;
        }
    }
    out.close();
}
