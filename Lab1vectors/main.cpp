#include "utills.h"
#include "functions.h"
using namespace std;

int actionFunc(int x)
{
	return x * 2;
}

int main() {
	vector<int> v;
	
	v = getNumbersFromFile("numbers.txt");
	 
	//modify(v, actionFunc);
	//modify(v.begin() + 2, v.end(), actionFunc);
	//modify(v.begin(), v.end(), actionFunc);
	//modifyWithTransform(v.begin(), v.end(), actionFunc);
	//v = modifyWithForEach(v.begin(), v.end(), actionFunc);

	//int sum = calculateSum(v.begin(), v.end());
	//int avg =  calculateAvg(v.begin(), v.end());


	return 0;
	//fillFileWithNumbers("numbers.txt", 10, 10);
}