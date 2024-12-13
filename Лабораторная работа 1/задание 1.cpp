#include <iostream>
using namespace std;

int main() {
	system("chcp 1251");
	const int size = 10;

	double arr[size] = { 3.14, 2.71, 1.41, 1.73, 2.24, 3.33, 4.44, 5.55, 6.66, 7.77 };

	cout << "Содержимое массива:\n";
	for (int i = 0; i < size; ++i) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	cout << "\nАдрес начала массива: " << arr << endl;

	cout << "\nРасстояние каждого элемента от начала массива (в байтах):\n";
	for (int i = 0; i < size; ++i) {
		cout << "Элемент arr[" << i << "] находится на расстоянии "
			<< (reinterpret_cast<char*>(&arr[i]) - reinterpret_cast<char*>(arr)) << " байт.\n";
	}

	return 0;
}