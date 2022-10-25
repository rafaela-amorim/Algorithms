#include <iostream>
#include <iomanip>

using namespace std;

double div(double num,double num2){
	if(num2 == 0) throw "Divisao por zero";
	return num/num2;
}

int fat(int num){
	if(num < 0) throw "numero negativo";
	if(num == 0 || num == 1){
		return num;
	}
	return num * fat(num - 1);
}

int main(){
	try{
		cout << fat(11) << endl;
		// cout << fat(-1) << endl;
		cout <<  div(10.0,4.0) << endl;
		cout <<  div(10.0,0.0) << endl;
	}catch(const char* e){
		cerr << "Erro: " << e << endl;
	}catch(...){
		cerr << "erro inesperado\n" << endl;
	}
	return 0;
}
