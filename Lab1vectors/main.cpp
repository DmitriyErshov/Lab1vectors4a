#include "utills.h"
#include "functions.h"
//#include "functorClasses.h"

int actionFunc(int x, int min)
{
	return x * min;
}


int main() {
	setlocale(LC_ALL, "Russian");
	/*
	v = {1, 2, 3, 4};
	vector<int> dvec;
	vector<int>::iterator it_b = v.begin();
	vector<int>::iterator it_e = v.end();
	print<vector<int>>(it_b, it_e);*/

	vector<int> v = { 3, 4, 2, 5 };
	/*vector<int>::iterator begin = v.begin();
	vector<int>::iterator end = v.end();*/

	fillFileWithNumbers("numbers.txt", 3, 5);
	v = getNumbersFromFile<int>("numbers.txt");

	cout << "Рандомный вектор" << endl;
	printToConsole<int>(v.begin(), v.end());

	cout << "Обработка modify" << endl;
	modify<int>(v, actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "Обработка перегруженным modify" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modify<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "Обработка modify с Transform" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modifyWithTransform<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "Обработка modify с ForEach" << endl;
	//v = getNumbersFromFile("numbers.txt");
	v = modifyWithForEach<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());


	cout << "Сумма: " << calculateSum<int>(v.begin(), v.end()) << endl;
	cout << "Среднее: " << calculateAvg<int>(v.begin(), v.end());
	return 0;
}