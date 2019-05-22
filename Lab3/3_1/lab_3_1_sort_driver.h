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
	static bool validateSort(const int *,int);

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
		sort.binInsertionSort(tmp,size+1);
	}
	else if (type == 'p') {
		sort.pyramSort(tmp,size);
	}
	else if (type == 'q') {
		sort.setTStart();
		sort.xORSort(tmp,0,size-1);
		sort.setTEnd();
		sort.calcTimeDiffInMs();
		std::cout << "Сортировка заняла " << sort.calcTimeDiffInMs() << " мс" << std::endl;
	}


	if(!validateSort(tmp,size))
		throw std::runtime_error("FK INCORRECT SORT");
	delete [] tmp;
}

bool Lab_3_1_Sort_Driver::validateSort(const int *tmpV,int size) {
	for (int i = 1; i <size ; i++) {
		if(tmpV[i-1]>tmpV[i]){
			std::cout<<i<<"\n\n"<<tmpV[i-1]<<" and "<<tmpV[i]<<"\n";
			return false;}
	}
	return true;
}


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H
