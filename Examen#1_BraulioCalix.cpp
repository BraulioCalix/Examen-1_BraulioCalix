#include <iostream>
using namespace std;
void imprimirmat(char**,int);
char** createboard(int);
void limpiar(char**,int);
char** llenado (char**);
int* lectura();
bool cmueve(char**,int,int,int,int);
int main (){//el main
	int* movimiento=NULL;
	int* posicion= NULL;	
	char** matriz= NULL;
	matriz=createboard(11);//el tablero es de 11*11
	matriz=llenado(matriz);
	imprimirmat(matriz,11);
	
	bool juego=false; //boolean que decidira si se acaba el juego
	int turno=1;//int de los turnos 1 empiezan los moscovitas, 2 empiezan los suecos
	while(juego!=true){
		if(turno==1){
		//turno moscovita		
			cout << "es el turno de los moscovitas [M] "<< endl;		
			bool posivalida=false;//revisa si la posicion es ocupada por una fija
			while(posivalida==false){
				cout << "ingrese la posicion de la pieza que desea mover " << endl;				
				posicion=lectura();
				imprimirmat(matriz,11);
				if(matriz[posicion[0]][posicion[1]]=='M'){
					posivalida=true;
				}else{
					cout << "ingreso una posicion incorrecta , reingrese los datos: " <<endl;
				}

			}
			bool mover=true;;
			while(mover==true){
				cout << "ingrese la posicion a donde lo quiere mover" <<endl;
				movimiento=lectura();
				if(matriz[movimiento[0]][movimiento[1]==' ']){
					mover=cmueve(matriz,posicion[0],posicion[1],movimiento[0],movimiento[1]);	

				}
				if(mover==true){
					matriz[posicion[0]][posicion[1]]=' ';
					matriz[movimiento[0]][movimiento[1]]='M';
				cout << "real" << endl;
				}else{
				cout << "no lo es" <<endl;
					mover=true;
				}
			}

			imprimirmat(matriz,11);	
			
			turno=2;
			}else{
		//turno de los suecos
			imprimirmat(matriz,11);
			cout<< "es el turno de los suecos [S]" << endl;
			bool posivalida=false;//revisa si la posicion es ocupada por una fija
                        while(posivalida==false){
                                posicion=lectura();
                                imprimirmat(matriz,11);
                                if(matriz[posicion[0]][posicion[1]]=='S'){
                                        posivalida=true;
                                }else{
                                        cout << "ingreso una posicion incorrecta , reingrese los datos: " <<endl;
                                }

                        }
                        bool mueve=true;
                        bool posi=true;
                        while(mueve==true){
                                movimiento=lectura();
                                if(matriz[movimiento[0]][movimiento[1]==' ']){
                                        posi=false;
                                }
                                while(posi==false){
                                        int x1=0,y1=0,x2=0,y2=0;
                                        x1= posicion[0];
                                        y1= posicion[1];
                                        x2= movimiento[0];
                                        y2= movimiento[1];
                                        posi = cmueve(matriz,x1,y1,x2,y2);
                                }
                                if(posi==false){
                                        matriz[posicion[0]][posicion[1]]=' ';
                                        matriz[movimiento[0]][movimiento[1]]='S';
                                        mueve=false;
                                }

                        }

		turno=1;
		}
	}//fin dell while del juego
	delete[] posicion;
	limpiar(matriz,11);
}
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
//inicio de metodos
bool cmueve(char** mat,int x1,int y1,int x2,int y2){
	cout << "x1 " <<x1 <<"y1 " <<y1 << "x2 "<< x2 << "y2 " <<y2 << endl;
	bool valido=true;
	if(x1==x2){//se va a mover de forma horizontal
		if(y1 < y2){
			for(int i=y1;i<=y2;i++){
				if(mat[x1][i]==' '){
							
				}else{
					valido=false;
				}
			}
		}else if(y1 > y2){
			for(int i= y2; i <=y1;i++){
				if(mat[x1][i]==' '){
				
				}else{
					valido=false;
				}
			}
		}else{
			valido=true;
		}
	}else if(y1==y2){// se va a mover de forma vertical
		cout << "los y son iguales" << endl;
		if(x1 < x2){

			for(int i=x1;i<=x2;i++){
				if(mat[i][y1]==' '){
				
				}else{
					valido=false;
				} 
			}
		}else if(x1 > x2){
			cout << "x1 es mayor" << endl;
			for(int i= x2; i<=x1;i++){
				if(mat[i][y1]==' '){
					cout << "puedto " << mat[i][y1]<< " ]" <<endl;
				}else {
					cout << "[" << mat[i][y1]<< "]"<< endl;
					valido=false;
				}
			}
		}else{
			valido=true;
		}
	}else {
	//no se puede mover
	
		cout<< " nose puede mover" << endl;
	valido=true;
	}
	return valido;
}
int* lectura(){
	int* posicion=new int[3];
	bool digitos=false;
	bool validodato1=false;
	bool validodato2=false;
       	bool general=false;	
	for(int i =0; i<3;i++){
		posicion[i]=-1;
	}
	while(general==false){
		//las variables validodato 1 y 2 sirven para verificar que se ingreso bien la lectura 
		string leer="";
		cin >> leer;
		cout << "leyo: " << endl;
		if(leer[2]=='0' && leer[1]==1){
                	posicion[1]=9;
        		digitos=true;
			validodato2=true;
		}
		if(leer[2]=='1' && leer[1]==1){
			posicion[1]=10;
			digitos=true;
			validodato2=true;	
		}
		if(digitos==false){
			if(leer[1]=='1'){
               			 posicion[1]=0;
        			validodato2=true;	
		 	 }
		}
		if(leer[0]=='a'){
			posicion[0]=0;
			validodato1=true;	
		}
			//cout << "bools " << validodato1<<" " << validodato2 << endl;
		if(leer[0]=='b'){
               		posicion[0]=1;
        		validodato1=true;
		}
		if(leer[0]=='c'){
               		posicion[0]=2;
        		validodato1=true;
		}
		if(leer[0]=='d'){
                	posicion[0]=3;
        		validodato1=true;
		}
		if(leer[0]=='e'){
                	posicion[0]=4;
        		validodato1=true;
		}
		if(leer[0]=='f'){
                	posicion[0]=5;
        		validodato1=true;
		}
		if(leer[0]=='g'){
                	posicion[0]=6;
        		validodato1=true;
		}
		if(leer[0]=='h'){
                	posicion[0]=7;
        		validodato1=true;
		}
		if(leer[0]=='i'){
                	posicion[0]=8;
        		validodato1=true;
		}
		if(leer[0]=='j'){
                	posicion[0]=9;
        		validodato1=true;
		}
		if(leer[0]=='k'){
               		posicion[0]=10;
        		validodato1=true;
		}
		if(leer[1]=='2'){
                	posicion[1]=1;
			validodato2=true;

        	}
		if(leer[1]=='3'){
                	posicion[1]=2;
			validodato2=true;

		}
		if(leer[1]=='4'){
                	posicion[1]=3;
			validodato2=true;

		}	
		if(leer[1]=='5'){
               		posicion[1]=4;
			validodato2=true;

		}
		if(leer[1]=='6'){
                	posicion[1]=5;
			validodato2=true;

		}
		if(leer[1]=='7'){
                	posicion[1]=6;
			validodato2=true;

		}
		if(leer[1]=='8'){
                	posicion[1]=7;
			validodato2=true;

		}
		if(leer[1]=='9'){
                	posicion[1]=8;
			validodato2=true;

		}
		cout << "paso if" <<endl;
		if(validodato2==true && validodato1==true){
			general=true;
		}else{
				cout<< "ingreso un valor invalido " << endl;
				cout << "no se que pedo" << endl;

		}
	
	}
//	cout<< "antes del return" << endl;
		return posicion;
}
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


