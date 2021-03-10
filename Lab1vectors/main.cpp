#include "utills.h"
#include "functions.h"
using namespace std;

int actionFunc(int x, int min)
{
	return x * min;
}

int main() {
	vector<int> v;

	//fillFileWithNumbers("numbers.txt", 10, 10);
	v = getNumbersFromFile("numbers.txt");
	 
	modify(v, actionFunc);
	printToConsole(v.begin(), v.end());

	v = getNumbersFromFile("numbers.txt");
	modify(v.begin(), v.end(), actionFunc);
	printToConsole(v.begin(), v.end());

	v = getNumbersFromFile("numbers.txt");
	modifyWithTransform(v.begin(), v.end(), actionFunc);
	printToConsole(v.begin(), v.end());

	v = getNumbersFromFile("numbers.txt");
	v = modifyWithForEach(v.begin(), v.end(), actionFunc);
	printToConsole(v.begin(), v.end());

	cout << calculateSum(v.begin(), v.end()) << endl;
	cout << calculateAvg(v.begin(), v.end());

	return 0;
}