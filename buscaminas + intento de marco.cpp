#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio2.h>
#include <ctime>
#include <cstdlib>


using namespace std;

#define COLUMNAS 10
#define FILAS 10
#define SIN_BOMBA -2
#define BOMBA -1
#define SIN_JUGAR -3

#define ESTADO_PERDEDOR 0
#define ESTADO_GANADOR  1
#define ESTADO_EN_JUEGO 2

enum {
    ESQ_INF_DER = 217,
    ESQ_SUP_IZQ,
    ESQ_SUP_DER = 191,
    ESQ_INF_IZQ,
    HORIZONTAL = 196,
    VERTICAL = 179,
    NUMCERO = 48
};


void Print(int,int,int[][FILAS],bool[][FILAS]);
int Contar2(int,int,int[][FILAS]);
void EstablecerNumeros(int[][FILAS]);
void PrintAll(int[][FILAS]);
void jugada(int,int,int[][FILAS],bool[][FILAS]);
int ContarJugadas(bool[][FILAS]);
void JugadaEnGrupo(int,int, int &,int&, int[][FILAS],bool[][FILAS]);
bool GetMenu();
void IniciarJuego(int[][FILAS],bool[][FILAS]);
void Marco(int , int , int, int);


int main(int argc, char** argv) {

    int campo[FILAS][COLUMNAS];
    bool jugadas[FILAS][COLUMNAS];
    //bool cadena_valida = true;
    bool QuiereJugar;

    do{

        QuiereJugar = GetMenu();
        if (QuiereJugar) IniciarJuego(campo, jugadas);
        cin.ignore();
    }while(QuiereJugar);
}

void IniciaArr(int campo[][FILAS], bool jugadas[][FILAS]){
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){

            campo[i][j] = SIN_BOMBA;
            jugadas[i][j] = false;
        }
    }
}



void AgregaBombas(int nbombas,int campo[][FILAS]){
    int x,y;
    for (int i = 0; i < nbombas;++i){
        x = rand()%FILAS;
        y = rand()%COLUMNAS;
        if (campo[x][y] != BOMBA)
        campo[x][y] = BOMBA;
    }
}

void Print(int x,int y,int campo[][FILAS], bool jugadas[][FILAS]){
    int i,j;
    for( i = 0; i < FILAS; ++i){
        gotoxy(25,5+i);
        for(j = 0; j < COLUMNAS; ++j){
            if(i==x && j==y) textcolor(RED);

            if( jugadas[i][j] ){
                if( campo[i][j] == BOMBA){
                    cout << " * ";
                }else{
                    cout << " " << campo[i][j] << " ";
                }
            }else{
                cout << " - ";
            }
            textcolor(WHITE);
        }
        cout << endl;
    }
}

int Contar2(int x, int y, int campo[][FILAS]){
    int nbombas = 0;
    for(int i = x-1; i < x+2; i++){
        for(int j = y-1; j < y+2; j++){
            if( i >= 0 && i < FILAS && j >= 0 && j < COLUMNAS ){
                if( campo[i][j] == BOMBA){
                    nbombas++;
                }
            }
        }
    }
    return nbombas;
}

void EstablecerNumeros(int campo[][FILAS]){
    int i,j, numero;
    for( i = 0; i < FILAS; i++){
        for(j = 0; j < COLUMNAS; j++){
            if( campo[i][j] == SIN_BOMBA){
                numero = Contar2(i,j, campo);
                campo[i][j] = numero;
            }
        }
    }
}

void PrintAll(int campo[][FILAS]){

    for(int i = 0; i < FILAS; i++){
        gotoxy(25,5+i);
        for(int j = 0; j < COLUMNAS; j++){
            if( campo[i][j] == BOMBA){
                textcolor(RED);
                cout << " * ";
                textcolor(WHITE);
            }else{
                cout << " " << campo[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void jugada(int x, int y, int estado, int campo[][FILAS], bool jugadas[][FILAS]){
    if( x >= 0 && x < FILAS && y >= 0 && y < COLUMNAS ){
        jugadas[x][y] = true;
        if( campo[x][y] == BOMBA){
            estado = ESTADO_PERDEDOR;
        }
    }else{
        cout << "Imposible jugada" << endl;
        system("pause");
    }
}

void Marco(int x, int y, int ancho, int alto)
{
    gotoxy(x, y);
    cout<<char(ESQ_SUP_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_SUP_DER)<<endl;
    for(int i=1; i<=alto; i++){
        gotoxy(x, y+i);
        cout<<char(VERTICAL);
        for(int j=0; j<ancho; j++)cout<<' ';
        cout<<char(VERTICAL)<<endl;
    }
    gotoxy(x, y+alto+1);
    cout<<char(ESQ_INF_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_INF_DER)<<endl<<endl;
}

int ContarJugadas(bool jugadas[][FILAS]){
    int numero = 0;
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            if ( jugadas[i][j]){
                numero++;
            }
        }
    }
    return numero;
}

void JugadaEnGrupo(int x, int y, int &estado,int &njugadas, int campo[][FILAS], bool jugadas[][FILAS]){
    njugadas++;
    if(campo[x][y]==0){
        for(int i = x-1; i < x+2; i++){
            for(int j = y-1; j < y+2; j++){
                if(i>=0 && i< FILAS && j>=0 && j<COLUMNAS){
                    if( campo[i][j] == 0 && !jugadas[i][j]){
                        jugadas[i][j] = true;
                        JugadaEnGrupo(i,j, estado,njugadas, campo, jugadas);
                    }else{
                        if (!jugadas[i][j])njugadas++;
                        jugadas[i][j] = true;

                    }

                }
            }
        }
    }

}


///////////////////////////////////////////////////////////////////////////////
bool GetMenu(){
    gotoxy(30,16);
    cout << "1. Jugar Buscaminas." << endl;
    gotoxy(30,17);
    cout << "0. Salir." << endl;
    char opt[30];
    bool cadena_valida=true;

   do{
        cadena_valida = true;

        gotoxy(30,18);
        cout << "Opci\xa2n: ";
        cin.getline(opt, 30,'\n');

        if (  (opt[0] == char(48) && opt[1]=='\0') || (opt[0] == char(49) && opt[1]=='\0')){
        } else cadena_valida = false;
    }while(!cadena_valida);
    int n = opt[0] - 48;
    if (n == 1) return true;
    if (n == 0) return false;

}


void IniciarJuego(int campo[][FILAS], bool jugadas[][FILAS]){
    int njugadas=0;
    int estado;
    int nbombas = -1;
    while( nbombas < 0 || nbombas > 70 ){
        gotoxy(30,19);
        cout << "Numero de bombas: ";
        cin >> nbombas;
    }

    int opcion,x=0,y=0;
    estado = ESTADO_EN_JUEGO;
    IniciaArr(campo, jugadas);

    srand ( time(NULL) );
    AgregaBombas( nbombas, campo );
    EstablecerNumeros(campo);

    system("cls");
    Marco(24,4,FILAS*3,FILAS);
    while( estado == ESTADO_EN_JUEGO){
        Print(x,y,campo, jugadas);
        if( njugadas == ( FILAS*COLUMNAS - nbombas) ){
            estado = ESTADO_GANADOR;
        }
        opcion = getch();


        if (opcion == 'w' && x - 1 >= 0) --x;
        if (opcion == 's' && x + 1 <= COLUMNAS-1) ++x;
        if (opcion == 'a' && y - 1 >= 0) --y;
        if (opcion == 'd' && y + 1 <= FILAS-1) ++y;

        if (opcion == 'i'){
                jugadas[x][y] = true;

                if( campo[x][y] == BOMBA){
                    estado = ESTADO_PERDEDOR;
                }else{
                    JugadaEnGrupo(x,y, estado,njugadas, campo,jugadas);
                }
            }
    }
        system("cls");

    if( estado == ESTADO_PERDEDOR){
        textcolor(RED);
        gotoxy(35,1);
        cout << "Perdiste" << endl;
        textcolor(WHITE);
        gotoxy(35,3);
        cout << "Solucion: " << endl;
        Marco(24,4,FILAS*3,FILAS);
        PrintAll(campo);
    }else{
        gotoxy(33,1);
        textcolor(YELLOW);
        cout << "\xAD \xAD GANASTE !!" << endl;
        textcolor(WHITE);
        Marco(24,4,FILAS*3,FILAS);
        PrintAll(campo);
    }
}
