//
// Created by vhundef on 22.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H


#include "lab_3_1_sort.h"

class Lab_3_1_Sort_Driver {
public:
	void Sort(int *arr, int size, char);
private:
	int * tmp= nullptr;
	Lab3_1_Sort sort;
};

void Lab_3_1_Sort_Driver::Sort(int *arr, int size, char type) {
	tmp=new int[size];

	for (int i = 0; i <=size ; ++i) {
		tmp[i]=arr[i];
	}

	if (type == 'i') {
		sort.insertionSort(tmp,size+1);

	}
	else if (type == 'b') {
		sort.binInsertionSort(tmp,size);
	}
	else if (type == 'r') {}

	delete [] tmp;
}


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H
