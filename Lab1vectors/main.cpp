#include "utills.h"
#include "functions.h"
//#include "functorClasses.h"

int actionFunc(int x, int min)
{
	return x * min;
}

int main() {
	setlocale(LC_ALL, "Russian");

	vector<int> v = { 3, 4, 2, 5 };

	fillFileWithNumbers("numbers.txt", 3, 5);
	v = getNumbersFromFile<int>("numbers.txt");

	cout << "��������� ������" << endl;
	printToConsole<int>(v.begin(), v.end());

	cout << "��������� modify" << endl;
	modify<int>(v, actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "��������� ������������� modify" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modify<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "��������� modify � Transform" << endl;
	//v = getNumbersFromFile("numbers.txt");
	modifyWithTransform<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());

	cout << "��������� modify � ForEach" << endl;
	//v = getNumbersFromFile("numbers.txt");
	v = modifyWithForEach<int>(v.begin(), v.end(), actionFunc);
	printToConsole<int>(v.begin(), v.end());


	cout << "�����: " << calculateSum<int>(v.begin(), v.end()) << endl;
	cout << "�������: " << calculateAvg<int>(v.begin(), v.end());
	return 0;
}