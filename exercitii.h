#ifndef EXERCITII_H_INCLUDED
#define EXERCITII_H_INCLUDED

#include <iostream>
using namespace std;

//sa se sorteze tip munte cu poz. de control al celui de al 4-lea element ce are intre 3-5 div. proprii

void afisareVector(int v[], int dim){
	for(int i = 0; i < dim; i++){
		cout << v[i] << " ";
	}
}

int numarDivizori(int numar){
	int contor = 0;
	for(int d = 2; d * d < numar; d++){
		if(numar % d == 0)
			contor+=2;
		if(d * d  == numar){
			contor-=1;
		}
	}
	return contor;
}

int pozitiaDeControlDivizori(int v[], int dim){
	int ct = 0,pozDeControl;
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		if(numar > 2){
			int nrDivizori = numarDivizori(numar);
			if(nrDivizori >=3 && nrDivizori <=5){
				ct++;
			}
		}
		if(ct == 4){
			pozDeControl = v[i];
			return pozDeControl;
		}
	}
	return -1;
}

void sortareCrescAB(int v[], int a, int b){
	/*bool sortare = true;
	do{
		sortare = true;
		for(int i = a; i < b - 1; i++){
			if(v[i] > v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortare = false;
			}
		}
	}
	while(sortare == false);*/
	for(int i = a; i < b; i++){
		for(int j = a; j < b; j++){
			if(v[j] < v[j - 1]){
				int aux = v[j];
				v[j] = v[j - 1];
				v[j - 1] = aux;
			}
		}
	}
}

void sortareDescAB(int v[], int a, int b){
	/*bool sortare = true;
	do{
		sortare = true;
		for(int i = a; i < b - 1; i++){
			if(v[i] < v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				sortare = false;
			}
		}
	}
	while(sortare == false);*/
	for(int i = a; i < b; i++){
		for(int j = a; j < b; j++){
			if(v[j] > v[j - 1]){
				int aux = v[j];
				v[j] = v[j - 1];
				v[j - 1] = aux;
			}
		}
	}
}

void munte(int v[], int dim){
	int pozDeControl = pozitiaDeControlDivizori(v, dim);
	int a = 0, b = pozDeControl;
	sortareCrescAB(v, a, b);
	a = pozDeControl, b = dim;
	sortareDescAB(v, a, b);
	afisareVector(v, dim);
}

void ex1(){
	int v[100] = {10,90,400,345,20,12,25,76,39,20,79,567,554,897,34,12};
	int dim = 16;
	munte(v, dim);
}

//sa se sorteze tip vale cu poz. de control al k-lea element ce are t cifre de 1 in baza 2

int transformareInBaza2 (int numar){
	int raspuns = 0, p = 1;
	while(numar){
		raspuns += p * (numar % 2);
		p *= 10;
		numar/= 2;
	}
	return raspuns;
}

int contorizare1InBaza2 (int raspuns){
	int contor = 0;
	while(raspuns != 0){
		if(raspuns % 10 == 1){
				contor++;
		}
		raspuns/=10;
	}
	return contor;
}

int pozitiaDeControlBaza2(int v[], int dim, int k, int t){
	int cnt = 0;
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		int raspuns = transformareInBaza2(numar);
		int aux = contorizare1InBaza2(raspuns);
		if(aux == t){
			cnt++;
		}
		if(cnt == k){
			return i;
		}
	}
	return 0;
}

void vale(int v[], int dim, int k, int t){
	int pozDeControl= pozitiaDeControlBaza2(v, dim, k, t);
	int a = 0, b = pozDeControl;
	sortareDescAB(v, a, b);
	a = pozDeControl, b = dim;
	sortareCrescAB(v, a, b);
	afisareVector(v, dim);
}

void ex2(){
	int v[100] = {10,90,8,20,11,25,76,39,20,79,54,97,34,12};
	int dim = 14, k = 1, t = 5;
	vale(v, dim, k, t);
}

//sa se sorteze vectorul crescator intre elementul de minim si cel de maxim, iar descrescator in rest
//se va lua in considerare doar primul minim si ultimul maxim

int indNumarMaximVector(int v[], int dim){
	int indice, maxim = INT_MIN;
	for(int i = 0; i < dim; i++){
		if(v[i] >= maxim){
			maxim = v[i];
			indice = i;
		}
	}
	return indice;
}

int indNumarMinimVector(int v[], int dim){
	int indice, minim = INT_MAX;
	for(int i = 0; i < dim; i++){
		if(v[i] < minim){
			minim = v[i];
			indice = i;
		}
	}
	return indice;
}

void sortare(int v[], int dim){
	int indmax = indNumarMaximVector(v, dim);
	int indmin = indNumarMinimVector(v, dim);
	if(indmin > indmax){
		int aux = indmin;
		indmin = indmax;
		indmax = aux;
	}
	int a = 0, b = indmin;
	sortareDescAB(v, a, b);
	a = indmin, b = indmax;
	sortareCrescAB(v, a, b);
	a = indmax, b = dim;
	sortareDescAB(v, a, b);
	afisareVector(v, dim);
}

void ex3(){
	int v[100] = {10,90,8,20,25,76,39,97,79,54,20,34,12};
	int dim = 13;
	sortare(v, dim);
}

///PB Info
//sa se stearga din vector toate elementele prime

bool isPrim(int numar){
	if(numar < 2){
		return false;
	}
	for(int d = 2; d * d <= numar; d++){
		if(numar % d == 0){
			return false;
		}
	}
	return true;
}

void stergereElemPrime(int v[], int& dim){
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		if(isPrim(numar)){
			for(int j = i; j < dim; j++){
				v[j] = v[j + 1];
			}
			dim--;
		}
	}
}

void ex4(){
	int v[100] = {10,90,8,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
	stergereElemPrime(v, dim);
	afisareVector(v, dim);
}

//sa se transforme vectorul, duplicand fiecare aparitie a valorii minime

int numarMinimVector(int v[], int dim){
	int minim = INT_MAX;
	for(int i = 0; i < dim; i++){
		if(v[i] < minim){
			minim = v[i];
		}
	}
	return minim;
}

void duplicareElemMinVector(int v[], int& dim){
	int minim = numarMinimVector(v, dim);
	for(int i = 0; i < dim; i++){
		if(minim == v[i]){
			for(int j = dim; j > i; j--){
				v[j + 1] = v[j];
			}
			dim++;
			v[i + 1] = minim;
			i++;
		}
	}
}

void ex5(){
	int v[100] = {10,90,5,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
	duplicareElemMinVector(v, dim);
	afisareVector(v, dim);
}

//sa se stearga din vector toate elementele egale cu minimul din vector

void stergereElemMin(int v[], int& dim){
	int minim = numarMinimVector(v, dim);
	for(int i = 0; i < dim; i++){
		if(v[i] == minim){
			for(int j = i; j < dim; j++){
				v[j] = v[j + 1];
			}
			dim--;
		}
	}
}

void ex6(){
	int v[100] = {10,90,5,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
	stergereElemMin(v, dim);
	afisareVector(v, dim);
}

//sa se stearga dintr-un vector toate elementele pare

void stergereElemPare(int v[], int& dim){
	for(int i = 0; i < dim; i++){
		if(v[i] % 2 == 0){
			for(int j = i; j < dim; j++){
				v[j] = v[j + 1];
			}
			dim--;
			i--;
		}
	}
}

void ex7(){
	int v[100] = {10,90,5,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
	stergereElemPare(v, dim);
	afisareVector(v, dim);
}

//sa se stearga elementele care se repeta, pastrandu-se doar primul de la st la dr

bool cautareNumar(int x[], int dim1, int numar){
	for(int i = 0; i < dim1; i++){
		if(x[i] == numar){
			return true;
		}
		return false;
	}
}

void stergereElemRep(int v[], int& dim){
	int x[100], dim1 = 0;
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		if(cautareNumar(x, dim1, numar)){
			for(int j = i; j < dim; j++){
				v[j] = v[j + 1];
			}
			dim--;
			i--;
		}
		else{
			x[dim1++] = v[i];
		}
	}
}

void ex8(){
	int v[100] = {10,90,5,10,25,7,39,90,76,5,53,20,7};
	int dim = 13;
	stergereElemRep(v, dim);
	afisareVector(v, dim);
}

///Fisa de lucru

//sa se stearga al 3-lea elem. prim din vector

void stergere3ElemPrim(int v[], int& dim){
	int cnt = 0;
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		if(isPrim(numar)){
			cnt++;
		}
		if(cnt == 3){
			for(int j = i; j < dim; j++){
				v[j] = v[j + 1];
			}
			dim--;
		}
	}
}

void ex9(){
	int v[100] = {10,90,5,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
	stergere3ElemPrim(v, dim);
	afisareVector(v, dim);
}

//sa se stearga toate elem ce au cel putin 2 cifre si prima = ultima

int oglindit(int numar){
	int o = 0;
	while(numar != 0){
		o = o * 10 + numar % 10 ;
		numar /= 10;
	}
	return o;
}

bool primaUltima(int numar){
	int aux = numar % 10;
	numar = oglindit(numar);
	if(aux == numar % 10){
		return true;
	}
	else{
		return false;
	}
}

void stergereElem2Cif(int v[], int dim){
	for(int i = 0; i < dim; i++){
		int numar = v[i];
		if(primaUltima(numar) ){
			for(int j = 0;;){
				j = 0;
			}
		}
	}
}
void ex10(){
	int v[100] = {10,90,5,20,25,76,39,97,79,5,53,20,7};
	int dim = 13;
}

///

int numarCifre(int numar){
	int ctCifra = 0;
	while(numar != 0){
		ctCifra++;
		numar/=10;
	}
}

int putere(int pozMijloc) {
    int p = 1;
    while(pozMijloc != 0) {
        p *= 10;
        pozMijloc--;
    }
    return p;
}

int cifraMijloc(int numar) {
    int ctCifre = numarCifre(numar), mijloc;
    int pozMijloc = ctCifre / 2;
    int p = putere(pozMijloc);
    if(ctCifre % 2 == 0) {
        mijloc = (numar / p) % 10;
        p/=10;
        mijloc *=10;
        mijloc += (numar / p) % 10;
    }
    else {
        mijloc = (numar / p) % 10;
    }
    return mijloc;
}

bool isPatrPerfect(int cifra) {
    for(int i = 1; i < cifra; i++) {
        if(i * i == cifra) {
            return true;
        }
    }
    return false;
}

void stergereElemMijPatrPerfect(int v[], int& dim) {
    for(int i = 0; i < dim; i++) {
        int numar = v[i];
        int cifra = cifraMijloc(numar);
        if(isPatrPerfect(cifra)) {
            //stergereNumar(v, dim, i);
        }
    }
    afisareVector(v, dim);
}

void ex11() {
    int v[100] = {1255,16,9819,10,9,8,72,65,64,4,3,2,1,0};
    int dim = 14;
    stergereElemMijPatrPerfect(v, dim);
}

#endif // EXERCITII_H_INCLUDED
