#include <iostream>
using namespace std;
void imprimirmat(char**,int);
char** createboard(int);
void limpiar(char**,int);
char** llenado (char**);
int main (){//el main
	char** matriz= NULL;
	matriz=createboard(11);//el tablero es de 11*11
	matriz=llenado(matriz);
	imprimirmat(matriz,11);
	limpiar(matriz,11);
	bool juego=false; //boolean que decidira si se acaba el juego
	int turno=1;//int de los turnos 1 empiezan los moscovitas, 2 empiezan los suecos
	//while(juego!=true){
		if(turno==1){
		//turno moscovita
			cout << "es el turno de los moscovitas [M] "<< endl;		
				
		}else{
		//turno de los suecos
			cout<< "es el turno de los suecos" << endl;
		
		}
	//}
}
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
char** llenado(char** matriz ){//la s es de los suecos, la M de moscovitas
	for(int i=0;i<11;i++){
		for(int j=0; j<11;j++){
			matriz[i][j]=' ';
		}
	}
	//lenado de las X
	matriz[0][0]='X';
	matriz[10][10]='X';
	matriz[0][10]='X';
	matriz[10][0]='X';

	//llenado de moscovitas
	matriz[0][4]='M';
	matriz[0][5]='M';
	matriz[0][6]='M';
	matriz[1][4]='M';
	matriz[1][6]='M';
	matriz[3][5]='M';
	matriz[4][0]='M';
	matriz[4][1]='M';
	matriz[5][0]='M';
	matriz[5][2]='M';
	matriz[6][0]='M';
	matriz[6][1]='M';
	matriz[4][9]='M';
	matriz[4][10]='M';
	matriz[4][9]='M';
	matriz[5][8]='M';
	matriz[5][10]='M';
	matriz[6][10]='M';
	matriz[6][9]='M';
	matriz[8][5]='M';
	matriz[9][4]='M';
	matriz[9][6]='M';
	matriz[10][4]='M';
	matriz[10][5]='M';
	matriz[10][6]='M';

	//fin llenado de moscovitas
	//incio llenado de suecos
	matriz[5][5]='W';
	matriz[5][3]='S';
	matriz[5][4]='S';
	matriz[5][6]='S';
	matriz[5][7]='S';
	matriz[4][4]='S';
	matriz[4][5]='S';
	matriz[4][6]='S';
	matriz[3][5]='S';
	matriz[6][4]='S';
	matriz[6][5]='S';
	matriz[6][6]='S';
	matriz[7][5]='S';
	//fin llenado de suecos
return matriz;
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
	cout << "   [1][2][3][4][5][6][7][8][9][10][11]" <<endl;
	for(int i = 0; i < size ; i++){
		for(int j = 0; j < size; j++ ){
			if(j==0 && i==0){
				cout << "[a]";
			}
			if(j==0 && i==1){
                                cout << "[b]";
                        }
			if(j==0 && i==2){
                                cout << "[c]";
                        }
			if(j==0 && i==3){
                                cout << "[d]";
                        }
			if(j==0 && i==4){
                                cout << "[e]";
                        }
			if(j==0 && i==5){
                                cout << "[f]";
                        }
			if(j==0 && i==6){
                                cout << "[g]";
                        }
			if(j==0 && i==7){
                                cout << "[h]";
                        }
			if(j==0 && i==8){
                                cout << "[i]";
                        }
			if(j==0 && i==9){
                                cout << "[j]";
                        }
			if(j==0 && i==10){
                                cout << "[k]";
                        }
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


