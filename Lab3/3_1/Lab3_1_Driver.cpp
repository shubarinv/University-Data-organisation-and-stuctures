//
// Created by vhundef on 22.05.19.
//

#include <fstream>
#include "lab_3_1_sort_driver.h"

using namespace std;
int main(){
	Lab_3_1_Sort_Driver sortDriver;

	int arrM[1500000],tmp,i=0;

	ifstream infile("unsorted.txt");
	while ((infile >> tmp)&&i<=150000){
		arrM[i]=tmp;
		i++;
	}
	infile.close();

	cout<<"=============\nСортировка простыми вставками\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(arrM,15000,'i');
	sortDriver.Sort(arrM,15000,'i');
	sortDriver.Sort(arrM,15000,'i');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(arrM,40000,'i');
	sortDriver.Sort(arrM,40000,'i');
	sortDriver.Sort(arrM,40000,'i');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(arrM,80000,'i');
	sortDriver.Sort(arrM,80000,'i');
	sortDriver.Sort(arrM,80000,'i');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(arrM,150000,'i');
	sortDriver.Sort(arrM,150000,'i');
	sortDriver.Sort(arrM,150000,'i');

	cout<<"=============\nСортировка бинарными вставками\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(arrM,15000,'b');
	sortDriver.Sort(arrM,15000,'b');
	sortDriver.Sort(arrM,15000,'b');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(arrM,40000,'b');
	sortDriver.Sort(arrM,40000,'b');
	sortDriver.Sort(arrM,40000,'b');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(arrM,80000,'b');
	sortDriver.Sort(arrM,80000,'b');
	sortDriver.Sort(arrM,80000,'b');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(arrM,150000,'b');
	sortDriver.Sort(arrM,150000,'b');
	sortDriver.Sort(arrM,150000,'b');


	cout<<"=============\nПирамидальная Сортировка\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(arrM,15000,'p');
	sortDriver.Sort(arrM,15000,'p');
	sortDriver.Sort(arrM,15000,'p');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(arrM,40000,'p');
	sortDriver.Sort(arrM,40000,'p');
	sortDriver.Sort(arrM,40000,'p');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(arrM,80000,'p');
	sortDriver.Sort(arrM,80000,'p');
	sortDriver.Sort(arrM,80000,'p');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(arrM,150000,'p');
	sortDriver.Sort(arrM,150000,'p');
	sortDriver.Sort(arrM,150000,'p');

	cout<<"=============\nXOR Сортировка\n=============\n";
	cout<<"\nN1 15000 элементов\n"<<endl;

	sortDriver.Sort(arrM,15000,'q');
	sortDriver.Sort(arrM,15000,'q');
	sortDriver.Sort(arrM,15000,'q');


	cout<<"\nN2 40000 элементов\n"<<endl;

	sortDriver.Sort(arrM,40000,'q');
	sortDriver.Sort(arrM,40000,'q');
	sortDriver.Sort(arrM,40000,'q');

	cout<<"\nN3 80000 элементов\n"<<endl;

	sortDriver.Sort(arrM,80000,'q');
	sortDriver.Sort(arrM,80000,'q');
	sortDriver.Sort(arrM,80000,'q');

	cout<<"\nN4 150000 элементов\n"<<endl;

	sortDriver.Sort(arrM,150000,'q');
	sortDriver.Sort(arrM,150000,'q');
	sortDriver.Sort(arrM,150000,'q');

}