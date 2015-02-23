/*
    Nombre: Juego carta mayor
    Autor: Jesús Ernesto Jaramillo Salazar
    Descripcion: Se simulará el juego de la carta mayor según las veces que el usuario deseé
    Fecha: 3/07/2014 11:28 am
*/

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include <time.h>

using namespace std;

int xAux, yAux;

enum {
    ESQ_INF_DER = 217,
    ESQ_SUP_IZQ,
    ESQ_SUP_DER = 191,
    ESQ_INF_IZQ,
    HORIZONTAL = 196,
    VERTICAL = 179,
    NUMCERO = 48
};

void Moverse(unsigned short,unsigned short);

class Carta{
    public:
        void setpalo(int);
        void setnumero(int);
        int getpalo();
        int getnumero();

        friend ostream& operator<< (ostream&,Carta&);

        void PrintCarta(int, int);
        void Marco(int, int, int, int);
    private:
        int palo=3,numero=8;
        bool jugada;
};

////////////////////////////////////////////////////////////////////////
int Carta::getpalo()
{
	return palo;
}

int Carta::getnumero()
{
    return numero;
}

void Carta::setpalo(int n)
{
	this->palo = n;
}

void Carta::setnumero(int n)
{
	this->numero = n;
}

////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream&c, Carta &A)
{
	 char cartaNum[3] = "A\0";
     textbackground(WHITE);
	 switch(A.numero){
	 	case 1: cartaNum[0]='A'; break;
	 	case 10:
			 cartaNum[0]=char(NUMCERO +1);
			 cartaNum[1]=char(NUMCERO);
			 break;
		case 11: cartaNum[0]='J'; break;
		case 12: cartaNum[0]='Q'; break;
		case 13: cartaNum[0]='K'; break;
		default: cartaNum[0]=char(NUMCERO +A.numero);
	 };
	 int x=xAux, y=yAux;
	 A.Marco(x, y, 9, 9);
	 int color=BLACK;
     if(A.palo<=4) color = RED;
  	 textcolor(color);
	 Moverse(++x, ++y);
	 cout<<cartaNum;
	 Moverse(x, ++y);
	 cout<<char(A.palo);
	 //girar?
	 Moverse(x=xAux+11, y=yAux+11);
	 if(A.numero==10) cout<<'\b';
	 cout<<cartaNum;
	 Moverse(x, --y);
	 cout<<char(A.palo);

	 x=xAux+4;
	 y=yAux+3;
	 //coord(x,y) justo a la izquierda del simbolo en la esquina superior izquierda
	 Moverse(x,y);
  	 int numSimb = A.numero>10 ? 1 : A.numero;
  	 /*x=numero se simbolos; y=numero de simbolos en centro:
      x|1 2 3 4 5 6 7 8 9 10
      y|1 2 3 0 1 0 1 2 1 2
    */
	 int enCentro = numSimb==6 ? 0 : numSimb <=5 ? numSimb%4 : 2-numSimb%2;
	 int enLados = (numSimb-enCentro)/2;
	 //caso especial al acomodar los simbolos con el 7 y el 10
	 float fixer = numSimb == 7 ? 0.5 : numSimb == 10 ? 2 : 1;
	 int fixer2 = numSimb == 10 ? -3 : 0;
	 /*
       busque una funcion (matematica) de la que conosco todo el dominio y rango,
       que depende del numero de simbolos en la columna, y el indice al imprimir cada simbolo.
     */
	 int m = (enLados*enLados -7*enLados +14);
	 int b = - 3*enLados*enLados/2 +19*enLados/2 -16;

	 for(int i=1;i<=enLados;i++){
	     //posicion es una funcion f(enLados, i) que devuelve la altura de cada figura en las columnas:
 		   int posicion = m*i+b ;
 		   Moverse(x, y+posicion);
 		   cout<<char(A.palo);
	 }
	 x+=2;

	 for(int i=1; i<=enCentro; i++){

	 	int posicion = fixer*2*i +2 -enCentro + fixer2;
 	 	Moverse(x, y+posicion);
	    cout<<char(A.palo);
	 }
	 x+=2;

	 for(int i=1;i<=enLados;i++){

 		   int posicion = m*i+b;
 		   Moverse(x, y+posicion);
 		   cout<<char(A.palo);
	 }
	 Moverse(1,12);
	 textcolor(WHITE);
	 textbackground(BLACK);
}

////////////////////////////////////////////////////////////////////////
void Moverse(unsigned short x,unsigned short y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {x-1,y-1};
	SetConsoleCursorPosition(handle,coord);
}
////////////////////////////////////////////////////////////////////////
void Carta::Marco(int x, int y, int ancho, int alto)
{
    Moverse(x, y);
    cout<<char(ESQ_SUP_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_SUP_DER)<<endl;
    for(int i=1; i<=alto; i++){
        Moverse(x, y+i);
        cout<<char(VERTICAL);
        for(int j=0; j<ancho; j++)cout<<' ';
        cout<<char(VERTICAL)<<endl;
    }
    Moverse(x, y+alto+1);
    cout<<char(ESQ_INF_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_INF_DER)<<endl<<endl;
}

////////////////////////////////////////////////////////////////////////
int main(){
    Carta A,B;

    Moverse(10,16);
    cout<<B;

    cout<<endl;
    system("pause");
}
