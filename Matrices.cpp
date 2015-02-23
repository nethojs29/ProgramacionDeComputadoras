/*
  Nombre: Operaciones con matrices
  Autor: Jesús Ernesto Jaramillo Salazar
  Descripción:
  Fecha:
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>

using namespace std;

#define MAXREN 10
#define MAXCOL 10

void Imprimir(float [][MAXCOL],int,int);
void ImprimirTranspuesta(float [][MAXCOL],int,int);
void Capturar(float [][MAXCOL],int,int);
void Sumar(float [][MAXCOL],float [][MAXCOL],int,int,float [][MAXCOL]);
void Restar(float [][MAXCOL],float [][MAXCOL],int,int,float [][MAXCOL]);
void Multiplicar(float [][MAXCOL],float [][MAXCOL],int,int,float [][MAXCOL]);
void PorEscalar(float[][MAXCOL],int,int,float,float[][MAXCOL]);
void GenerarIdentidad(float[][MAXCOL],int);
void ceros_arriba(int , int , int , float [][MAXCOL], float [][MAXCOL]);
void ceros_abajo(int , int , int , float [][MAXCOL], float [][MAXCOL]);
int Invertir(float[][MAXCOL],float[][MAXCOL],int);


int main()
{
	float A[MAXREN][MAXCOL], B[MAXREN][MAXCOL], C[MAXREN][MAXCOL];
	int m,n,k,escalar,opc;
	bool salir=false;

	cout<<"Programa para operar matrices de mxn\n\n";

	do{
		do{
			cout<<"m = ";
			cin>>m;
		}while(m<1 || m>MAXREN);

		do{
			cout<<"n = ";
			cin>>n;
		}while(n<1 || n>MAXCOL);

		cout<<"Qu\x82 operaci\xa2n desea realizar?"<<endl;
		cout<<"1) Suma"<<endl;
		cout<<"2) Resta"<<endl;
		cout<<"3) Multiplicaci\xa2n entre matrices"<<endl;
		cout<<"4) Multiplicac\xa2n por escalar"<<endl;
		cout<<"5) Transpuesta de la Matriz"<<endl;
		cout<<"6) Invertir Matriz"<<endl;

		do{
			cin>>opc;
			if(opc<1 || opc>7) cout<<"Opci\xa2n no disponible, elija otra: "<<endl;
		}while(opc<1 || opc>7);

		switch(opc){
			case 1:
				Capturar(A,m,n);
				Capturar(B,m,n);
				Sumar(A,B,m,n,C);
				Imprimir(C,m,n);
				break;
			case 2:
				Capturar(A,m,n);
				Capturar(B,m,n);
				Restar(A,B,m,n,C);
				Imprimir(C,m,n);
				break;
			case 3:
				Capturar(A,m,n);
				Capturar(B,m,n);
				Multiplicar(A,B,m,n,C);
				Imprimir(C,m,n);
				break;
			case 4:
				Capturar(A,m,n);
				cout<<"k = ";
				cin>>k;
				PorEscalar(A,m,n,k,C);
				Imprimir(C,m,n);
				break;
			case 5:
				Capturar(A,m,n);
				ImprimirTranspuesta(A,m,n);
				break;
			case 6:
				if(m!=n){ cout<<"Las matrices no cuadradas no tienen inversa."; break; }
				Capturar(A,m,n);
				if(Invertir(A,B,n)==1){
					cout<<"La matriz no tiene inversa."<<endl; break;
				}else
				Imprimir(B,m,n);
				break;
		}

		cout<<"\n\nDesea salir? (0 para salir): ";
		cin>>opc;

		if(opc==0) break;
		else system("cls");

	}while(salir==false);

	cout<<endl;
	system("PAUSE");
	return 0;
}

//***************************************************************
void Imprimir(float A[][MAXCOL],int m,int n)
{
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j) cout<<setw(15)<<A[i][j];  // *(*(A+i)+j)
		cout<<endl;
	}
}

void ImprimirTranspuesta(float A[][MAXCOL],int m,int n)
{
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cout<<setw(10)<<A[j][i];  // *(*(A+i)+j)
		cout<<endl;
	}
}
//***************************************************************

void Capturar(float A[][MAXCOL],int m,int n)
{
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout<<"Introduce el numero ("<<i+1<<","<<j+1<<"): ";
			cin>>A[i][j];  // *(*(A+i)+j)
		}
		cout<<endl;
	}
}
//***************************************************************

void Sumar(float A[][MAXCOL],float B[][MAXCOL],int m,int n,float C[][MAXCOL])
{
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) C[i][j]=A[i][j]+B[i][j];
}

void Restar(float A[][MAXCOL],float B[][MAXCOL],int m,int n,float C[][MAXCOL])
{
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) C[i][j]=A[i][j]-B[i][j];
}

void Multiplicar(float A[][MAXCOL],float B[][MAXCOL],int m,int n,float C[][MAXCOL])
{
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			C[i][j]=0;
         	for(int l=0;l<n;l++) {
				C[i][j]=C[i][j]+A[i][l]*B[l][j];
          	}
       	}
    }
}

void PorEscalar(float A[][MAXCOL],int m,int n,float k,float C[][MAXCOL])
{
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) C[i][j]=A[i][j]*k;
}

void GenerarIdentidad(float B[][MAXCOL],int n)
{
	for(int i=0;i<n;++i){
		for (int j=0;j<n;++j){
			if(i==j){
				B[i][j]=1;
			}else B[i][j]=0;
		}
	}
}

void ceros_arriba(int i, int j, int n, float A[][MAXCOL], float B[][MAXCOL])
{

	int k,l;
	float aux=0;

	for(k=0;k<i;k++){
		aux=A[k][j]*-1;
			for(l=0;l<n;l++){
				A[k][l]=(A[k][l])+A[i][l]*aux;
				B[k][l]=(B[k][l])+B[i][l]*aux;
			}
	}
}

void ceros_abajo(int i, int j, int n, float A[][MAXCOL], float B[][MAXCOL])
{
	int k,l;
	float aux=0;

	for(k=n-1;k>i;k--){
		aux=A[k][j]*-1;
		for(l=0;l<n;l++){
			A[k][l]=(A[k][l])+A[i][l]*aux;
			B[k][l]=(B[k][l])+B[i][l]*aux;

		}
	}
}

int Invertir(float A[][MAXCOL],float B[][MAXCOL],int n)
{
	int i,j,k;
	int aux1=0,aux2=0;
	float aux3;
	float aux[MAXREN];

	GenerarIdentidad(B,n);

	j=1;
	while (A[0][0]==0){

			for(i=0;i<n;i++){
				aux[i]=A[0][i];
				A[0][i]=A[j][i];
				A[j][i]=aux[i];
			}
			j++;
	}

	for(i=0;i<n;i++) {
			aux1=0;
			j=0;
			while(aux1==0) {
				if(A[i][j]!=0) {
					if(A[i][j]!=1) {
						aux3=pow(A[i][j],-1);
						for(k=0;k<n;k++){
							A[i][k]=(A[i][k])*aux3;
							B[i][k]=(B[i][k])*aux3;
						}

					}

					ceros_arriba(i,j,n,A,B);
					ceros_abajo(i,j,n,A,B);
					aux1=1;
				}
				j++;
			}
		}

	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j){
				if(A[i][j]!=1) aux2=1;
			}
			else{
				if(A[i][j]!=0) aux2=1;
			}
		}

		if(aux2==1) return 1;
}

