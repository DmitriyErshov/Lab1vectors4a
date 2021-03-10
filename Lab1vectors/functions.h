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
void modify(vector<int>& v, int (*visitor)(int x, int min));

/*
������������� ������� modify, ����������� �� ���� ��������� ������ � �����
�������������� ����� ����������.
*/
void modify(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));


/*
�������, ����������� ��������� �������������� � �������������� ���������
std::transform ������ ������� modify.
*/
void modifyWithTransform(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));

/*
�������, ����������� ��������� �������������� � �������������� ���������
std::for_each ������ ������� modify.
*/
vector<int> modifyWithForEach(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));

/*
�������, ����������� ����� � ������� �������������� �����, ������������ �
����������.
*/
int calculateSum(vector <int> ::iterator begin, vector <int> ::iterator end);

double calculateAvg(vector <int> ::iterator begin, vector <int> ::iterator end);

int findMin(vector<int>::iterator begin, vector<int>::iterator end);

void printToConsole(vector <int> ::iterator begin, vector <int> ::iterator end);

void printToFile(vector <int> ::iterator begin, vector <int> ::iterator end, string fileName);
/*
������� ������ ���������� � ���� � �� ����� (�����������).
*/
