#ifndef ALGORITMI_H_INCLUDED
#define ALGORITMI_H_INCLUDED

#include <iostream>
using namespace std;

//sortarea prin selectie a unui vector

void afisareVector(int v[], int dim){
	for(int i = 0; i < dim; i++){
		cout << v[i] << " ";
	}
}

void sortareSelectieVector(int v[], int dim){
	for(int i = 1; i < dim; i++){
		for(int j = 1; j < dim; j++){
			if(v[j] < v[j - 1]){
				int aux = v[j];
				v[j] = v[j - 1];
				v[j - 1] = aux;
			}
		}
	}
	afisareVector(v, dim);
}

//sortarea prin insertie a unui vector

void bubbleSort(int v[], int dim){
	bool sortat = true;
	do{
		sortat = true;
		for(int i = 0;i  < dim - 1; i++){
			if(v[i] > v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortat = false;
			}
		}
	}while(sortat == false);
	afisareVector(v, dim);
}

void testare1(){
	int v[100]={9,8,7,6,5,4,3,2,1,0};
	int dim = 10;
	bubbleSort(v, dim);
}

//interclasarea

void afisare1Vector(int c[], int dim){
	for(int z = 0; z < dim; z++){
		cout << c[z] << " ";
	}
}

void interclasareVectori(int a[], int dim1, int b[], int dim2){
	int i = 0, j = 0, k = 0, c[100];
	while(i < dim1 && j < dim2){
		if(a[i] < b[j]){
			c[k] = a[i];
			k++;
			i++;
		}
		if(a[i] > b[j]){
			c[k] = b[j];
			k++;
			j++;
		}

		if(a[i] == b[j]){
			c[k] = a[i];
			k++;
			i++;
			j++;
		}
	}
	while(i < dim1){
		c[k] = a[i];
		k++;
		i++;
	}
	while(j < dim2){
		c[k] = b[j];
			k++;
			j++;
	}
	int dim = dim1 + dim2 - 1;
	afisare1Vector(c, dim);
}

void testare2(){
	int a[100] = {1,3,5,7,9,11,13}, dim1 = 7;
	int b[100] = {2,4,6,7,8,10,12,14,16,28}, dim2 = 10;
	interclasareVectori(a, dim1, b, dim2);
}

//cautarea binara pe rezultat

bool cautareBinara(int v[], int dim, int numar){
	int st = 0, dr = dim - 1, mijloc;
	while(dr - st > 1){
		mijloc = (st+dr)/2;
		if(numar < mijloc){
			dr = mijloc;
		}
		else{
			st = mijloc;
		}
		if(mijloc == numar)
			return true;
	}
	return false;
}

void testare3(){
	int v[100] = {1,2,3,4,5,6,7,8,9,10};
	int dim = 10, numar = 11;
	cout << cautareBinara(v, dim, numar);
}

//inserarea unui element in vector pe pozitia data

void inserareElementVector(int v[], int& dim, int poz, int elem){
	for(int i = dim; i >= poz; i--){
		v[i+1] = v[i];
	}
	v[poz] = elem;
	dim++;
}

//stergerea unui element din vector pe pozitia data

void stergereElementVector(int v[], int& dim, int poz){
	for(int i = poz; i < dim; i++){
		v[i] = v[i+1];
	}
	dim--;
}

void testare4(){
	int v[100] = {10,90,8,20,25,76,39,97,79,54,20,34,12};
	int dim = 13, poz = 3;
	stergereElementVector(v, dim, poz);
	afisareVector(v,dim);
}

#endif // ALGORITMI_H_INCLUDED
