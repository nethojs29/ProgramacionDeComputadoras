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
#include <ctime>
#include <cstdlib>

#define salir 0

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

class Carta{
    public:
        void setpalo(int);
        void setnumero(int);
        void setJugada(bool);
        int getpalo();
        int getnumero();
        bool getJugada();

        friend ostream& operator<< (ostream&,Carta&);

        void PrintCarta(int,int);
        void Marco(int, int, int, int);
    private:
        int palo,numero;
        bool jugada;
};

bool CrearArr(Carta **&, int);
void LlenarBaraja(Carta**&);
void Barajar(Carta*[],int,int);
void Moverse(unsigned short,unsigned short);



////////////////////////////////////////////////////////////////////////
int Carta::getpalo()
{
	return palo;
}

int Carta::getnumero()
{
    return numero;
}

bool Carta::getJugada()
{
    return jugada;
}

void Carta::setpalo(int n)
{
	this->palo = n;
}

void Carta::setnumero(int n)
{
	this->numero = n;
}

void Carta::setJugada(bool n)
{
    this->jugada = n;
}



////////////////////////////////////////////////////////////////////////
void Carta::PrintCarta(int _x,int _y)
{
	 char cartaNum[3] = "A\0";
     textbackground(WHITE);
	 switch(numero){
	 	case 1: cartaNum[0]='A'; break;
	 	case 10:
			 cartaNum[0]=char(NUMCERO +1);
			 cartaNum[1]=char(NUMCERO);
			 break;
		case 11: cartaNum[0]='J'; break;
		case 12: cartaNum[0]='Q'; break;
		case 13: cartaNum[0]='K'; break;
		default: cartaNum[0]=char(NUMCERO +numero);
	 };
	 int x=_x, y=_y;
	 Marco(xAux, yAux, 9, 9);
	 int color=BLACK;
     if(palo<=4) color = RED;
  	 textcolor(color);
	 Moverse(++x, ++y);
	 cout<<cartaNum;
	 Moverse(x, ++y);
	 cout<<char(palo);
	 //girar?
	 Moverse(x=_x+9, y=_y+9);
	 if(numero==10) cout<<'\b';
	 cout<<cartaNum;
	 Moverse(x, --y);
	 cout<<char(palo);

	 x=_x+3;
	 y=_y+2;

	 Moverse(x,y);
  	 int numSimb = numero>10 ? 1 : numero;

	 int enCentro = numSimb==6 ? 0 : numSimb <=5 ? numSimb%4 : 2-numSimb%2;
	 int enLados = (numSimb-enCentro)/2;

	 float fixer = numSimb == 7 ? 0.5 : numSimb == 10 ? 2 : 1;
	 int fixer2 = numSimb == 10 ? -3 : 0;

	 int m = (enLados*enLados -7*enLados +14);
	 int b = - 3*enLados*enLados/2 +19*enLados/2 -16;

	 for(int i=1;i<=enLados;i++){

 		   int posicion = m*i+b ;
 		   Moverse(x, y+posicion);
 		   cout<<char(palo);
	 }
	 x+=2;

	 for(int i=1; i<=enCentro; i++){

	 	int posicion = fixer*2*i +2 -enCentro + fixer2;
 	 	Moverse(x, y+posicion);
	    cout<<char(palo);
	 }
	 x+=2;

	 for(int i=1;i<=enLados;i++){

 		   int posicion = m*i+b;
 		   Moverse(x, y+posicion);
 		   cout<<char(palo);
	 }

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

bool CrearArr(Carta **&baraja, int n){
    try{
        baraja = new Carta*[n];
        return true;
    }catch(...){
        return false;
    }

}

void LlenarBaraja(Carta**&baraja){
    for(int i=0; i<4; ++i)
        for(int j=0; j<13; ++j){
            baraja[i*13+j]->setpalo(i+3);
            baraja[i*13+j]->setnumero(j+1);
        }
}

void Barajar(Carta*baraja[],int i,int j)
{
    Carta *aux = baraja[i];
    baraja[i]=baraja[j];
    baraja[j]=aux;
}



////////////////////////////////////////////////////////////////////////
int main(){
    srand((time(0)));
    int k,l,opc,puntosUsuario=0,puntosMaquina=0,m=0,n=1;
    char nombreUsuario[50];
    Carta **Baraja=NULL;
    textcolor(WHITE);
    if(!CrearArr(Baraja, 52)){
        cout<<"Error, no hay memoria suficiente para ejecutar el programa."<<endl;
        return 0;
    }

    for(int i=0; i<52; ++i)
        Baraja[i]= new Carta;
    LlenarBaraja(Baraja);
    Moverse(18,1);
    cout<<"Programa que simula el juego de la Carta mayor\n\n";

    cout<<"\xa8"<<"Cu\xa0l es tu nombre? ";
    cin.getline(nombreUsuario,50);

    do{
        for(int i=0;i<100;++i){
            k=rand()%26;
            l=rand()%26+26;
            Barajar(Baraja, k, l);
        }

        xAux = 1;
        yAux = 5;

        Baraja[m]->PrintCarta(xAux,yAux);
        Baraja[m]->setJugada(true);


        xAux = 69;
        yAux = 5;

        Baraja[n]->PrintCarta(xAux,yAux);
        Baraja[n]->setJugada(true);


        Moverse(40,5);
        if(Baraja[m]->getnumero() > Baraja[n]->getnumero()){
            puntosUsuario++;
            Moverse(35,9);
            cout<<"      ";
        }else
            if(Baraja[n]->getnumero() > Baraja[m]->getnumero()){
                puntosMaquina++;
                Moverse(35,9);
                cout<<"      ";
            }else{

                Moverse(35,9);
                cout<<"Empate";
            }

        Moverse(20,10);
        cout<<nombreUsuario;
        Moverse(22,11);
        cout<<puntosUsuario;
        Moverse(50,10);
        cout<<"Maquina";
        Moverse(53,11);
        cout<<puntosMaquina;

        if(m>=51 || n>=51){
            Moverse(30,14);
            cout<<"Juego terminado";
            Moverse(30,15);
            textcolor(YELLOW);
            if(puntosUsuario>puntosMaquina) cout<<"Ganador: "<<nombreUsuario;
            else cout<<"Ganador: Maquina";
            textcolor(WHITE);
            Moverse(1,20);
            return 0;
        }

        Moverse(1,18);
        do{
            cout<<"\xa8Quieres seguir jugando? (0 para salir): ";
            cin>>opc;
            if(!opc<0) cout<<"Opci\xa2n no disponible."<<endl;
        }while(!opc<0);
        m+=2;
        n+=2;
    }while(opc!=0);

    delete [] Baraja;

    cout<<endl;
    system("pause");
}
