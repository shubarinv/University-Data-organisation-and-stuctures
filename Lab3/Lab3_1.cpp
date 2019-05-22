// По возрастанию

//N1=15000
//N2=40000
//N3=80000
//N4=150000


#include <fstream>
#include <iostream>
#include "lab_3_1_sort.h"

using namespace std;
int main(){
	Lab3_1_Sort sort;



	int *arr,tmp,i=0;

	cout<<"=============\nСортировка простыми вставками\n=============\n";
	//For N1
	arr=new int[15000];

	cout<<"N1 15000 элементов"<<endl;

	ifstream infile("unsorted.txt");
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,15001);
	i=0;
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,15001);
	i=0;
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,15001);

	delete(arr);

	//For N2

	cout<<"\n____________\nN2 40000 элементов"<<endl;

	arr=new int[40000];
	i=0;

	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,40001);
	i=0;
	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,40001);
	i=0;
	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}

	infile.close();

	sort.insertionSort(arr,40001);


	//For N3

	cout<<"\n____________\nN3 80000 элементов"<<endl;

	arr=new int[80000];
	i=0;

	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,80001);
	i=0;
	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,80001);
	i=0;
	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}


	sort.insertionSort(arr,80001);

	delete(arr);

	//For N4

	cout<<"\n____________\nN4 150000 элементов"<<endl;


	arr=new int[150000];
	i=0;

	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,150001);
	i=0;
	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}

	sort.insertionSort(arr,150001);
	i=0;
	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}


	sort.insertionSort(arr,150001);

	delete(arr);


	cout<<"\n=============\nСортировка бинарными вставками\n=============\n";
	//For N1
	arr=new int[15000];

	cout<<"N1 15000 элементов"<<endl;

	infile.open("unsorted.txt");
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,15000);
	i=0;
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,15000);
	i=0;
	while ((infile >> tmp)&&i<=15000){
		arr[i]=tmp;
		i++;
	}
	infile.close();

	sort.binInsertionSort(arr,15000);

	//For N2

	cout<<"\n____________\nN2 40000 элементов"<<endl;

	arr=new int[40000];
	i=0;

	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,40000);
	i=0;
	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,40000);
	i=0;
	while ((infile >> tmp)&&i<=40000){
		arr[i]=tmp;
		i++;
	}


	sort.binInsertionSort(arr,40000);



	//For N3

	cout<<"\n____________\nN3 80000 элементов"<<endl;

	arr=new int[80000];
	i=0;

	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,80000);
	i=0;
	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,80000);
	i=0;
	while ((infile >> tmp)&&i<=80000){
		arr[i]=tmp;
		i++;
	}


	sort.binInsertionSort(arr,80000);


	//For N4

	cout<<"\n____________\nN4 150000 элементов"<<endl;

	arr=new int[150000];
	i=0;

	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,150000);
	i=0;
	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}

	sort.binInsertionSort(arr,150000);
	i=0;
	while ((infile >> tmp)&&i<=150000){
		arr[i]=tmp;
		i++;
	}

	infile.close();

	sort.binInsertionSort(arr,150000);


	return 0;
}