#include<iostream>
#include<Windows.h>

int Find_X_Count(int *arr, int size, int find_x) {
	int start = 0;
	int medium = 0;
	int finish = size - 1;
	bool flag = true;
	while (flag) {
		medium = ((start + finish) / 2);
		if (find_x < arr[medium]) {
			finish = medium;
		}
		if (find_x >= arr[medium]) {
			start = medium + 1;
			if (find_x >= arr[finish]) {
				flag = false;
				medium = size;
			}
		}	
		if ((arr[medium - 1] <= find_x) && (find_x < arr[medium])) {
			flag = false;
		}
	}
	return (size - medium);
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int size = 9;
	int count;
	int arr[size] = {14, 16, 19, 32, 32, 32, 56, 69, 72};
	int find_x;
	std::cout << "Введите точку отсчёта: ";
	std::cin >> find_x;

	count = Find_X_Count(arr, size, find_x);
	std::cout << "Количество элементов в массиве больших, чем " << find_x << " : " << count << std::endl;

	return 0;
}