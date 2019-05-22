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

	void pyramSort(int *, int);

	void xORSort(int *data, int first, int last);

	void setTStart();

	void setTEnd();

	double calcTimeDiffInMs() {
		return std::chrono::duration<double, std::milli>(t_end - t_start).count();
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> t_start;
	std::chrono::time_point<std::chrono::high_resolution_clock> t_end;

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


// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom) {
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)    // если мы в последнем ряду,
			maxChild = root * 2;    // запоминаем левый потомок
			// иначе запоминаем больший потомок из двух
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		// если элемент вершины меньше максимального потомка
		if (numbers[root] < numbers[maxChild]) {
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		} else // иначе
			done = 1; // пирамида сформирована
	}
}

void Lab3_1_Sort::pyramSort(int *data, int size) {
// Функция сортировки на куче
	setTStart();
	// Формируем нижний ряд пирамиды
	for (int i = (size / 2) - 1; i >= 0; i--)
		siftDown(data, i, size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = size - 1; i >= 1; i--) {
		int temp = data[0];
		data[0] = data[i];
		data[i] = temp;
		siftDown(data, 0, i - 1);
	}
	setTEnd();
	calcTimeDiffInMs();
	std::cout << "Сортировка заняла " << calcTimeDiffInMs() << " мс" << std::endl;
}

void Lab3_1_Sort::xORSort(int *data, int first, int last) {

	int i = first, j = last;
	int tmp, x = data[(first + last) / 2];

	do {
		while (data[i] < x)
			i++;
		while (data[j] > x)
			j--;

		if (i <= j) {
			if (i < j) {
				tmp = data[i];
				data[i] = data[j];
				data[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		xORSort(data, i, last);
	if (first < j)
		xORSort(data, first, j);



}

void Lab3_1_Sort::setTStart() {
	t_start = std::chrono::high_resolution_clock::now();
}

void Lab3_1_Sort::setTEnd() {
	t_end = std::chrono::high_resolution_clock::now();
}


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_H
