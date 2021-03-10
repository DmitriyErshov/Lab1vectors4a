#pragma once
#include "utills.h"
#include "functorClasses.h"

/*
Функцию заполнения текстового файла N целыми случайными числами в
диапазоне от -M до M. Имя файла, N и M поступают на вход функции, файл
возвращается функцией как результат (использовать потоки ввода-вывода).
Реализовать два варианта генерации чисел — в цикле и с использованием
алгоритма std::generate.
*/
void fillFileWithNumbers(string fileName, int n, int m);

/*
Функцию, получающую файл на вход, и возвращающую последовательный
контейнер, заполненный числами из файла.
*/
vector<int> getNumbersFromFile(string fileName);

/*
Функцию modify, выполняющую преобразование полученного контейнера. На вход
функции должен поступать контейнер, в качестве результата функция должна
возвращать модифицированный контейнер.
*/
void modify(vector<int>& v, int (*visitor)(int x, int min));

/*
Перегруженную функцию modify, принимающую на вход итераторы начала и конца
обрабатываемой части контейнера.
*/
void modify(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));


/*
Функцию, реализующую требуемое преобразование с использованием алгоритма
std::transform вместо функции modify.
*/
void modifyWithTransform(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));

/*
Функцию, реализующую требуемое преобразование с использованием алгоритма
std::for_each вместо функции modify.
*/
vector<int> modifyWithForEach(vector <int> ::iterator begin, vector <int> ::iterator end, int (*visitor)(int x, int min));

/*
Функции, вычисляющие сумму и среднее арифметическое чисел, содержащихся в
контейнере.
*/
int calculateSum(vector <int> ::iterator begin, vector <int> ::iterator end);

double calculateAvg(vector <int> ::iterator begin, vector <int> ::iterator end);

int findMin(vector<int>::iterator begin, vector<int>::iterator end);

void printToConsole(vector <int> ::iterator begin, vector <int> ::iterator end);

void printToFile(vector <int> ::iterator begin, vector <int> ::iterator end, string fileName);
/*
Функцию вывода результата в файл и на экран (опционально).
*/
