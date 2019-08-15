//
// Created by vhundef on 22.05.19.
//

#include <fstream>
#include "lab_3_1_sort_driver.h"

using namespace std;
int main(){
	Lab_3_1_Sort_Driver sortDriver;

	int ArrUnSorted[150000],ArrBackSorted[150000],tmp,i=0;

	ifstream infile("unsorted.txt");
	while ((infile >> tmp)&&i<=150000){
		ArrUnSorted[i]=tmp;
		i++;
	}
	infile.close();

	ifstream infileBkSrt("reverseSorted.txt");
	i=0;
	while ((infileBkSrt >> tmp)&&i<=150000){
		ArrBackSorted[i]=tmp;
		i++;
	}
	infileBkSrt.close();

	cout<<"=============\nСортировка простыми вставками\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'i');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'i');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'i');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'i');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'i');

	cout<<"=============\nСортировка бинарными вставками\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'b');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'b');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'b');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'b');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'b');


	cout<<"=============\nПирамидальная Сортировка\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'p');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'p');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'p');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'p');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'p');

	cout<<"=============\nXOR Сортировка\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 15000, 'q');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 40000, 'q');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 80000, 'q');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'q');
	sortDriver.Sort(ArrUnSorted,ArrBackSorted, 150000, 'q');

}