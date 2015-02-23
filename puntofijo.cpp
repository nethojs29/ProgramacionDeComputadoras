/*
    Nombre: Punto fijo
    Autor: Jesús Ernesto Jaramillo Salazar
    Fecha: 29/09/2014
    Descripción: Programa que calcula la raíz de una función utilizando el método de punto fijo.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <conio2.h>

double evaluar(double);

using namespace std;

int main(){
    textcolor(WHITE);
    double x0,tolerancia,xn,error;
    int n, aux;

    cout<<"Programa para calcular una aproximacion a la raiz con el metodo del punto fijo"<<endl;

    cout<<"Valor inicial de x0: ";
    cin>>x0;
    cout<<"Tolerancia: ";
    cin>>tolerancia;
    cout<<"Numero iteraciones: ";
    cin>>n;

    aux = 1;
    for(int i=1;i <= n && aux == 1;++i){
        //paso 3
        xn = evaluar(x0);
        cout<<i<<"          "<<x0<<"           "<<xn<<"           "<<error<<endl;
        //paso 4
        error = fabs(xn - x0);
        if(error < tolerancia){
            cout<<"\n\nLa aproximacion de la raiz es: ";
            textcolor(YELLOW);
            cout<<xn<<endl<<endl;
            textcolor(WHITE);
            aux = 0;
        }else{
            x0 = xn;
        }
    }
    if(aux == 1)
        cout<<"El metodo no es eficaz para dicha funcion";

    system("pause");
    return 0;


}

double evaluar(double x){
    double a;
    a = sqrt(exp(x)/3);
    return a;
}

