//
// Created by vhundef on 21.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H


#include <chrono>
#include <iostream>

class Lab3_1_Sort {
public:
	void insertionSort(int *, int);

	void binInsertionSort(int *, int);

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> t_end;


	void setTStart();

	void setTEnd();

	double calcTimeDiffInMs() {
		return std::chrono::duration<double, std::milli>(t_end - t_start).count();
	}
};

void Lab3_1_Sort::insertionSort(int *arrayPtr, int length) {
	setTStart();
	int temp, // временная переменная для хранения значения элемента сортируемого массива
			item; // индекс предыдущего элемента
	for (int counter = 1; counter < length; counter++) {
		temp = arrayPtr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива
		while (item >= 0 &&
		       arrayPtr[item] > temp) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
		{
			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
			arrayPtr[item] = temp;
			item--;
		}
	}
	setTEnd();
	std::cout << "Сортировка заняла " << calcTimeDiffInMs() << " мс" << std::endl;
	//return ;

}

void Lab3_1_Sort::binInsertionSort(int *data, int size) {
	setTStart();
	int x;
	int left;
	int right;
	int sred;
	for (int i = 1; i < size; i++)
		if (data[i - 1] > data[i]) {
			x = data[i];
			left = 0;
			right = i - 1;
			do {
				sred = (left + right) / 2;
				if (data[sred] < x) left = sred + 1;
				else right = sred - 1;
			} while (left <= right);
			for (int j = i - 1; j >= left; j--)
				data[j + 1] = data[j];
			data[left] = x;
		}
	setTEnd();
	calcTimeDiffInMs();
	std::cout << "Сортировка заняла " << calcTimeDiffInMs() << " мс" << std::endl;
}

void Lab3_1_Sort::setTStart() {
	t_start = std::chrono::high_resolution_clock::now();
}

void Lab3_1_Sort::setTEnd() {
	t_end = std::chrono::high_resolution_clock::now();
}


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H
