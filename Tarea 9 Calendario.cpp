/*
  Nombre: Calendario.cpp
  Autor: Jesús Ernesto Jaramillo Salazar
  Descripción: Dado un mes y un año, se mostrará de forma gráfica el calendario de dicho mes en el respectivo año
  Fecha: 13/04/14 11:06
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define MAXREN 6
#define MAXCOL 7

void Imprimir(int [][MAXCOL],int ,int );
int DiaPrimero(int, int);
int DiaUltimo(int, int);

int main()
{
	char Dias[MAXCOL]={'D','L','M','M','J','V','S'};
	int Arreglo[MAXREN][MAXCOL]={};
	int PDia,UDia,mes,year;

	cout<<"Programa para mostrar el calendario de forma gr\xa0"<<"fica de un mes y a\xa4o dados por el usuario\n\n";

	cout<<"Dame un mes (1) Enero, 2) Febrero, ... , 12) Diciembre: ";
	do{
		cin>>mes;
	}while(mes<1 || mes>12);
	
	cout<<"Dame un a\xa4o: ";
	do{
		cin>>year;
	}while(year<1);
	
	PDia=DiaPrimero(mes,year);
	UDia=DiaUltimo(mes,year);

	
	for(int *aux=*(Arreglo+0)+PDia,i=1; i<=UDia ;++aux) *aux=i++;
	
	
	cout<<endl<<endl;
	for(int i=0;i<MAXCOL;++i) cout<<setw(6)<<Dias[i]; cout<<endl;
	Imprimir(Arreglo,MAXREN,MAXCOL);	
	
	
	cout<<endl;
	system("PAUSE");
	return 0;
}

void Imprimir(int A[][MAXCOL],int m,int n)
{
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			 if(A[i][j]!=0)
			 	cout<<setw(6)<<A[i][j];
			else cout<<setw(6)<<char(32);
		}
		cout<<endl;
	}
}

int DiaPrimero(int mes, int year)
{
	int a,y,m,d,PrimerDia;
	
	a = (14-mes) / 12;
	y = year - a;
	m = mes + 12*a - 2;
	PrimerDia = 1 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12);	
	
	d = PrimerDia % 7; 
	return d;
}

int DiaUltimo(int mes, int year)
{
	int d;
	switch(mes){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				d = 31; break;
				
		case 2:
				if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
					d= 29;
				}else{
					d = 28;
				} break;
				
		case 4: case 6: case 9: case 11:
				d=30; break;
	}
	return d;
}

