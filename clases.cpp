/*
  Nombre:
  Autor:
  Fecha:
  Descripción:
*/

#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cmath>
#include<conio2.h>

using namespace std;

class Tablero{
    friend ostream& operator<<(ostream&, Tablero&);
    friend istream& operator>>(istream&, Tablero&);
public:
    Tablero(int=8, int=8);
    ~Tablero();
    void Switch();
    operator bool();
private:
    bool **arr, centinela;
    int n, m, x, y;
} LightsOut;

Tablero::Tablero(int _n, int _m): n(_n), m(_m), x(0), y(0), centinela(true)
{
	srand(time(NULL));
    arr = new bool* [n];
    for(int i=0; i<n; ++i){
        arr[i] = new bool [m];
        for(int j=0; j<m; ++j) arr[i][j] = bool(rand()%2);
    }
}

Tablero::~Tablero()
{
	for(int i=0; i<n; ++i) delete [] arr[i];
	delete [] arr;
}

void Tablero::Switch()
{
	int compy, compx;
	arr[y][x]=(bool)(1-(int)arr[y][x]);
	for(int k=0; k<4; ++k){
		compy =(int)round(sin(k*M_PI/2));
		compx =(int)round(cos(k*M_PI/2));
		if((y+compy+1)%9 && (x+compx+1)%9) arr[y+compy][x+compx]=(bool)(1-(int)arr[y+compy][x+compx]);
	}
}

Tablero::operator bool()
{
    if(!centinela){
        centinela = true;
        return false;
    }
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(arr[i][j]) return true;
    return false;
}
/////////////////////////////////
ostream& operator<<(ostream &lout, Tablero &T)
{
    lout<<"WASD para moverse, L para cambiar luces, 0 para salir\n\n";
    for(int i=0; i<T.n; ++i){
        for(int j=0; j<T.m; ++j) lout<<char(1+(int)T.arr[i][j])<<' ';
        lout<<endl;
    }
    gotoxy(2*T.x+1, T.y+3);

    return lout;
}

istream& operator>>(istream &lin, Tablero &T)
{
	char mover;
	mover = getch();
	switch(mover){
		case 'A': case 'a': if(T.x>0) --T.x; break;
		case 'D': case 'd': if(T.x<7) ++T.x; break;
		case 'W': case 'w': if(T.y>0) --T.y; break;
		case 'S': case 's': if(T.y<7) ++T.y; break;
		case 'L': case 'l':	T.Switch(); break;
		case '0': T.centinela = false;
	}
	return lin;
}

int main()
{
    while(LightsOut){
        cout<<LightsOut;
        cin>>LightsOut;
        system("cls");
    }
    if(!LightsOut) cout<<"Felicidades!"<<endl;
	system("PAUSE");
	return 0;
}
