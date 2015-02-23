/*
    Programa: Tabulación de sucesiones
    Autor: Jesús Ernesto Jaramillo Salazar
    fecha: 8 de Septiembre 2014
    Descripción: Programa ue generá una sucesión y la tabula de forma ordenada según la iteración realizada
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <conio2.h>
#include <conio.h>

using namespace std;

long double redondear(long double numero, int cifras);
void marco(int,int);

enum {
    ESQ_INF_DER = 217,
    ESQ_SUP_IZQ,
    ESQ_SUP_DER = 191,
    ESQ_INF_IZQ,
    HORIZONTAL = 196,
    VERTICAL = 179,
    NUMCERO = 48
};

int main (){
    long double x0 = 1;
    long double x1 = -2;
    x1/=3;

    x0 = redondear(x0,5);
    x1 = redondear(x1,5);

    int n;
    cout<<"n: ";
    cin>>n;

    long double xn,fxn,errorAbs,errorRel,errorRelPorc;

    system ("cls");

    gotoxy(30,1);
    cout<<"Tabulaci\xa2n de sucesiones.";

    gotoxy(2,1);
    marco(75,n+3);

    gotoxy(5,3);
    cout<<"n";
    gotoxy(10,3);
    cout<<"xn";
    gotoxy(22,3);
    cout<<"f(xn)";
    gotoxy(33,3);
    cout<<"En";
    gotoxy(50,3);
    cout<<char(156)<<"n";
    gotoxy(64,3);
    cout<<"En%";

    for(int i=0;i<n;++i){
        gotoxy(5,i+4);
        cout<<i+1;
        gotoxy(10,i+4);
        xn=x0+x1*(i+1);
        cout<<xn;
        gotoxy(22,i+4);
        fxn = redondear(xn,5);
        cout<<fxn;
        errorAbs=xn-fxn;
        gotoxy(33,i+4);
        cout<<errorAbs;
        gotoxy(50,i+4);
        errorRel= (xn-fxn)/xn;
        cout<<errorRel;
        gotoxy(64,i+4);
        errorRelPorc= errorRel*100;
        cout<<errorRelPorc;

    }



    cout<<endl;
    gotoxy(3,n+9);
    system ("pause");
}

long double redondear(long double numero, int cifras){
    int i;
    for(i=0;abs(numero)>1;++i) numero/=10;
    numero= round(numero*pow(10.0,cifras));
    numero*=pow(10.0,-cifras);
    numero*=pow(10.0,i);
    return numero;
}

void marco(int ancho, int alto){
    gotoxy(2,2);
    cout<<char(ESQ_SUP_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_SUP_DER)<<endl;
    for(int i=1; i<=alto; i++){
        gotoxy(2, 2+i);
        cout<<char(VERTICAL);
        for(int j=0; j<ancho; j++)cout<<' ';
        cout<<char(VERTICAL)<<endl;
    }
    gotoxy(2, 2+alto+1);
    cout<<char(ESQ_INF_IZQ);
    for(int i=0; i<ancho; i++) cout<<char(HORIZONTAL);
    cout<<char(ESQ_INF_DER)<<endl<<endl;
}
