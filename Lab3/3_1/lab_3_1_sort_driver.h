//
// Created by vhundef on 22.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_LAB_3_1_SORT_DRIVER_H


#include "lab_3_1_sort.h"

using namespace std;

class Lab_3_1_Sort_Driver {
public:
	void Sort(int *arr,int *, int size, char);
private:
	int * tmp= nullptr,*tmpRev= nullptr;
	Lab3_1_Sort sort;
	static bool validateSort(const int *,int);

};

void Lab_3_1_Sort_Driver::Sort(int *arrUnsort,int *arrBkSort, int size, char type) {
	tmp=new int[size];
	tmpRev=new int[size];

	for (int i = 0; i <=size ; ++i) {
		tmp[i]=arrUnsort[i];
	}
	for (int i = 0; i <=size ; ++i) {
		tmpRev[i]=arrBkSort[i];
	}
	if (type == 'i') {
		cout<<"\nSorting unsorted array"<<endl;
		sort.insertionSort(tmp,size+1);
		cout<<"Sorting of sorted array"<<endl;
		sort.insertionSort(tmp,size+1);
		cout<<"Sorting back sorted array"<<endl;
		sort.insertionSort(tmpRev,size+1);
		cout<<"\n_________________________\n";

	}
	else if (type == 'b') {
		cout<<"\nSorting unsorted array"<<endl;
		sort.binInsertionSort(tmp,size+1);
		cout<<"Sorting of sorted array"<<endl;
		sort.binInsertionSort(tmp,size+1);
		cout<<"Sorting back sorted array"<<endl;
		sort.binInsertionSort(tmpRev,size+1);
		cout<<"\n_________________________\n";
	}
	else if (type == 'p') {
		cout<<"\nSorting unsorted array"<<endl;
		sort.pyramSort(tmp,size);
		cout<<"Sorting of sorted array"<<endl;
		sort.pyramSort(tmp,size);
		cout<<"Sorting back sorted array"<<endl;
		sort.pyramSort(tmpRev,size);
		cout<<"\n_________________________\n";
	}
	else if (type == 'q') {
		cout<<"\nSorting unsorted array"<<endl;
		sort.setTStart();
		sort.xORSort(tmp,0,size-1);
		sort.setTEnd();
		std::cout << "Сортировка заняла " << sort.calcTimeDiffInMs() << " мс\n"<< "Кол-во сравнений: " <<sort.getCompr()<<"\n";

		cout<<"Sorting of sorted array"<<endl;
		sort.setTStart();
		sort.xORSort(tmp,0,size-1);
		sort.setTEnd();
		std::cout << "Сортировка заняла " << sort.calcTimeDiffInMs() << " мс\n" << "Кол-во сравнений: " <<sort.getCompr()<<"\n";


		cout<<"Sorting back sorted array"<<endl;
		sort.setTStart();
		sort.xORSort(tmpRev,0,size-1);
		sort.setTEnd();
		std::cout << "Сортировка заняла " << sort.calcTimeDiffInMs() << " мс\n" << "Кол-во сравнений: " <<sort.getCompr()<<"\n";
		cout<<"\n_________________________\n";
	}


	if(!validateSort(tmp,size))
		throw std::runtime_error("FK INCORRECT SORT");
	delete [] tmp;
	delete [] tmpRev;
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
