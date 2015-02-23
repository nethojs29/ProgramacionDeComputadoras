/*
Nombre:Programa 14 de lista de algoritmos
Autor: Ángel de Jesús Worley Parra
Fecha: 28/01/2014
Descripcion: Dado un mes y un año cuantos dias tuvo ese mes en tal año.
*/

#include <iostream>
#include <cstdlib>
using namespace std;



int main ()
{
	int mes, a;
	
	cout << "Programa que dira cuantos dias tiene el mes que desea saber el usuario en tal\n a\xa4o. \n";
	
	cout << "Que a\xa4o? " << endl;
	cin>>a;
	
	cout << "1.- Enero\n2.- Febrero\n3.- Marzo\n4.- Abril\n5.- Mayo\n6.- Junio\n7.- Julio\n8.- Agosto\n9.- Septiembre\n10.- Octubre\n11.- Noviembre\n12.- Diciembre\n"<<endl;
	cout << "Utilizando del 1 al 12 selecciona el mes." << endl;
	cin >> mes;
	
	if (a > 0 && mes > 0 ) {
		switch (mes){
			
			case 1: 
				cout << "Enero del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias. "<<endl;
				break;
			case 2:
				if ((a % 4 == 0) || (a % 400 == 0 && a % 100 == 0 )){
				cout << "Febrero del "<<a<<" "<< "tuvo, tiene o va a tener 29 dias."<<endl;
			    break;
				}
				else cout<< "Febrero del "<<a<<" "<< "tuvo, tiene o va a tener 28 dias."<<endl;
				break;
			case 3:
				cout << "Marzo del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
			case 4:
				cout<< "Abril del "<<a<<" "<< "tuvo, tiene o va a tener 30 dias."<<endl;
				break;
			case 5:
				cout<< "Mayo del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
			case 6:
				cout<< "Junio del "<<a<<" "<< "tuvo, tiene o va a tener 30 dias."<<endl;
				break;
			case 7:
				cout<< "Julio del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
			case 8:
				cout<< "Agosto del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
			case 9:
				cout<< "Septiembre del "<<a<<" "<< "tuvo, tiene o va a tener 30 dias."<<endl;
				break;
			case 10:
				cout<< "Octubre del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
			case 11:
				cout<< "Noviembre del "<<a<<" "<< "tuvo, tiene o va a tener 30 dias."<<endl;
				break;
			case 12:
				cout<< "Diciembre del "<<a<<" "<< "tuvo, tiene o va a tener 31 dias."<<endl;
				break;
		}
	}

	else 
	cout <<endl<<"Introduzca valores validos."<<endl;


system ("pause");
return 0;

}
