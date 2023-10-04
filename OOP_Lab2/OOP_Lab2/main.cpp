#include <iostream>

#include "Array.h"

double calculateAvg(const Array arr)
{
	if (arr.size() == 0) {
		return 0;
	}

	double avg = 0;
	for (int i = 0; i < arr.size(); ++i) {
		avg += arr[i];
	}
	avg /= arr.size();
	return avg;
}

int main()
{
	{
		Array arrA(5, 0);
		Array arrB(5, 1);
		arrA += arrB;
		arrA.print();
	}
	getchar();

	Array arr(10, 0);
	int a = arr[3];
	std::cout << arr[3] << ' ' << arr[9] << std::endl;
	arr[3] = 16;
	arr[5] = arr[3];
	std::cout << "Average value: " << calculateAvg(arr) << '\n';
	arr.print();

	getchar();
	return 0;
}