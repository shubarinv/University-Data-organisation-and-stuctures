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
	cout<<"N1 15000 элементов"<<endl;

	sortDriver.Sort(arrM,15000,'i');
	sortDriver.Sort(arrM,15000,'i');
	sortDriver.Sort(arrM,15000,'i');


	cout<<"N2 40000 элементов"<<endl;

	sortDriver.Sort(arrM,40000,'i');
	sortDriver.Sort(arrM,40000,'i');
	sortDriver.Sort(arrM,40000,'i');

	cout<<"N3 80000 элементов"<<endl;

	sortDriver.Sort(arrM,80000,'i');
	sortDriver.Sort(arrM,80000,'i');
	sortDriver.Sort(arrM,80000,'i');

	cout<<"N4 150000 элементов"<<endl;

	sortDriver.Sort(arrM,150000,'i');
	sortDriver.Sort(arrM,150000,'i');
	sortDriver.Sort(arrM,150000,'i');

}