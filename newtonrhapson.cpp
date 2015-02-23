/*
	Nombre: NewtonRaphson.cpp
	Autor:	Jesús Ernesto Jaramillo Salazar
	Fecha:	29 /9/2014
	Descripcion: Este programa aproxima la raiz de una funcion en un intervalo utilizando elwton-Raphson
*/
#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<math.h>
using namespace std;
class NewtonRaphson{
public:
	void capturarDatos();
	long double evaluarF(const long double &);
	long double evaluarFPrima(const long double &);
	long double evaluarFBiprima(const long double &);
	long double getA() {return a;}
	long double getB() {return b;}
	double getTol() {return tolerancia;}
	int getIte() {return iteracion;}
private:
	long double a, b;
	double tolerancia;
	int iteracion;
};
//*****************************************************
void imprimir(NewtonRaphson &);
long double valorAbsoluto(long double);
//*****************************************************
int main()
{
	cout<<"Este programa aproxima la ra\xA1z de la funci\xA2n f(x)= e^(x-1) - 5x^3\ncon el metodo Newton-Raphson\n\n";

	NewtonRaphson aux;
	aux.capturarDatos();
	imprimir(aux);

	cout<<endl;
	system("pause");
}
//*****************************************************
void NewtonRaphson::capturarDatos()
{
	int aux = 0;
	cout<<"Ingresa el intervalo [a,b]\n";
	do{
		if(aux==1) cout<<"No hay ra\xA1z en el intervalo\n";
		cout<<"a: ";
		cin>>a;
		cout<<"b: ";
		cin>>b;
		aux = 1;
	}while(evaluarF(a) * evaluarF(b)>0 || evaluarFPrima(a) * evaluarFBiprima(b) > 0);

	do{
		cout<<"Tolerancia :";
		cin>>tolerancia;
	}while(tolerancia<0);

	do{
		cout<<"N\xA3mero m\xA0ximo de iteraciones: ";
		cin>>iteracion;
	}while(iteracion<0);
}
//*****************************************************
long double NewtonRaphson::evaluarF(const long double &x)
{
	return exp(x-1) - 5*pow(x, 3);
}
//*****************************************************
long double NewtonRaphson::evaluarFPrima(const long double &x)
{
	return exp(x-1) - 15*pow(x, 2);
}
//*****************************************************
long double NewtonRaphson::evaluarFBiprima(const long double &x)
{
	return exp(x-1) - 30*x;
}
//*****************************************************
long double valorAbsoluto(long double x)
{
	if(x<0) return -x;
		else return x;
}
//*****************************************************
void imprimir(NewtonRaphson &aux)
{
	long double valorActual = (aux.getA()+aux.getB())/2 , valorAnterior = 0;
	long double error = 0;
	cout<<"  n      Xn         f(Xn)          f'(Xn)        Error"<<endl;
	for(int i=0; i<aux.getIte() || error>=pow(10.0,-aux.getTol()); ++i){
      valorAnterior = valorActual;
      valorActual = valorAnterior - aux.evaluarF(valorAnterior) / aux.evaluarFPrima(valorAnterior);
      error = valorAbsoluto((valorActual - valorAnterior) / valorActual);
      if(i==0) cout<<"  "<<setiosflags(ios::left)<<setw(6)<<i+1<<setw(15)<<valorActual<<setw(15)<<aux.evaluarF(valorActual)<<setw(10)<<aux.evaluarFPrima(valorActual)<<setw(10)<<"-";
      else cout<<"  "<<setiosflags(ios::left)<<setw(6)<<i+1<<setw(15)<<valorActual<<setw(15)<<aux.evaluarF(valorActual)<<setw(10)<<aux.evaluarFPrima(valorActual)<<setw(10)<<error;
	  system("pause");
	}
}
