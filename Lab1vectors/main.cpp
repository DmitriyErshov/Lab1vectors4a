#include "utills.h"
#include "functions.h"


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

	vector<int> v = { 2, 3, 4, 5 };

	fillFileWithNumbers("numbers.txt", 3, 5);
	v = getNumbersFromFile("numbers.txt");
	vector<int>::iterator begin = v.begin();
	vector<int>::iterator end = v.end();
	cout << "��������� ������" << endl;
	printToConsole<vector<int>>(begin, end);

	cout << "��������� modify" << endl;
	modify<vector<int>>(v, actionFunc);
	printToConsole<vector<int>>(begin, end);

	cout << "��������� ������������� modify" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modify<vector<int>>(begin, end, actionFunc);
	printToConsole<vector<int>>(begin, end);

	cout << "��������� modify � Transform" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modifyWithTransform<vector<int>>(begin, end, actionFunc);
	printToConsole<vector<int>>(begin, end);

	cout << "��������� modify � ForEach" << endl;
	//v = getNumbersFromFile("numbers.txt");
	v = modifyWithForEach<vector<int>>(begin, end, actionFunc);
	begin = v.begin();
	end = v.end();
	printToConsole<vector<int>>(begin, end);


	cout << "�����: " << calculateSum(v.begin(), v.end()) << endl;
	cout << "�������: " << calculateAvg(v.begin(), v.end());

	return 0;
}