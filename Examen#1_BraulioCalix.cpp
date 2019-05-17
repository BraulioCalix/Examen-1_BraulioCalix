#include <iostream>
using namespace std;
oid imprimirmat(char**,int);
char** createboard(int);
void limpiar(char**,int);
void visual ();
int main (){//el main







}
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
void visual(){

	int cont=1;
	for(int i=1;i<4 ;i++){
		for(int j=1;j<4;j++){
			cout<< "[" << cont << "]";
			cont++;
		}
		cout << endl;
	}
}//metodo visual
char** createboard(int size){
	char** matriz = NULL;
	matriz = new char* [size];
	for(int i= 0;i< size ; i++){
		matriz[i]= new char[size];
	}
	return matriz;
}//metodo crear


void imprimirmat(char** mat,int size){//metodo imprimir
	for(int i = 0; i < size ; i++){
		for(int j = 0; j < size; j++ ){
			cout<<"[" <<mat[i][j]<<"]";
		}
		cout << endl;

	}
	cout<< endl;
}//fin metodo imprimir


void limpiar(char** mat,int size){//metodo liberador de memoria
	for(int i=0;i<size;i++){
		if(mat[i]!=NULL){
			delete[] mat[i];
       			mat[i]= NULL;
		}
	}



}//fin metodo liberar


