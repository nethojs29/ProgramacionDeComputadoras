/*
  Nombre: Donde quedaron los días.cpp
  Autor: Jesús Ernesto Jaramillo Salazar
  Descripción: Dado 2 números, que representan un mes y un año, se dará en qué día de la semana cayó el primer y ultimo día dicho mes
  Fecha: 03/02/14 23:03
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int mes, year, a, y, m, PrimerDia, UltimoDia,d;
	
	cout<<"Programa para calcular qu\x82 d\xa1"<<"a de la semana caen el primer y el \xa3ltimo d\xa1"<<"a del mes\n\n";
	
	do{
		cout<<"Dame un mes: (1 Enero, 2 Febrero, ... , 12 Diciembre): ";
		cin>>mes;
		if(mes<1 || mes>12){
			cout<<"Valor incorrecto\n";
		}
	}while(mes<1 || mes>12);
	do{
		cout<<"Dame un a\xa4o: ";
		cin>>year;
		if(year<1){
			cout<<"Valor incorrecto\n";
		}
	}while(year<1);
	
	a = (14-mes) / 12;
	y = year - a;
	m = mes + 12*a - 2;
	PrimerDia = 1 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12);	
	
	switch(mes){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				UltimoDia = 31 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12); break;
				
		case 2:
				if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
					UltimoDia = 29 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12);; 
				}else{
					UltimoDia = 28 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12);
				} break;
				
		case 4: case 6: case 9: case 11:
				UltimoDia = 30 + y + (y / 4) - (y / 100) + (y / 400) + ((31*m) / 12); break;
				
		default: break;
	}
	d = PrimerDia % 7; 
	
	switch(d){
		case 0:
				cout<<"El primer d\xa1"<<"a es Domingo\n"; break;
		case 1:
				cout<<"El primer d\xa1"<<"a es Lunes\n"; break;
		case 2:
				cout<<"El primer d\xa1"<<"a es Martes\n"; break;
		case 3:
				cout<<"El primer d\xa1"<<"a es Mi\x82rcoles\n"; break;
		case 4:
				cout<<"El primer d\xa1"<<"a es Jueves\n"; break;
		case 5:
				cout<<"El primer d\xa1"<<"a es Viernes\n"; break;
		case 6:
				cout<<"El primer d\xa1"<<"a es S\xa0"<<"bado\n"; break;
		default: break;			
	}
	d = UltimoDia % 7;
	
	switch(d){
		case 0:
				cout<<"El \xa3ltimo d\xa1"<<"a es Domingo\n"; break;
		case 1:
				cout<<"El \xa3ltimo d\xa1"<<"a es Lunes\n"; break;
		case 2:
				cout<<"El \xa3ltimo d\xa1"<<"a es Martes\n"; break;
		case 3:
				cout<<"El \xa3ltimo d\xa1"<<"a es Mi\x82rcoles\n"; break;
		case 4:
				cout<<"El \xa3ltimo d\xa1"<<"a es Jueves\n"; break;
		case 5:
				cout<<"El \xa3ltimo d\xa1"<<"a es Viernes\n"; break;
		case 6:
				cout<<"El \xa3ltimo d\xa1"<<"a es S\xa0"<<"bado\n"; break;
		default: break;			
	}
	system("PAUSE");
	return 0;
}

