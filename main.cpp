#include <iostream>
using namespace std;

int oglindit(int n, int o){
	if(n == 0){
		return o;
	}
	oglindit(n/10,o * 10 + n % 10);
}


int main(){
	int o = oglindit(1234,0);
	cout << o;
	return 0;
}
