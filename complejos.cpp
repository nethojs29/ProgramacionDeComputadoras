/*
  Nombre: Operaciones con números Complejos
  Autor: JesÃºs Ernesto Jaramillo Salazar
  Descripción: Programa que realiza suma, resta, multiplicación o división, según el usuario decida, con dos números complejos
  Fecha: 20/06/14 03:35
*/

#include <iostream>
#include <cstdlib>

using namespace std;

///////////////////////////////////////////////////////////////////////////////////
class Complejo{
    friend ostream& operator<< (ostream&,Complejo&);
    friend istream& operator>> (istream&,Complejo&);

    public:
        Complejo();
        Complejo(float);
        Complejo(float, float);

        Complejo operator+ (const Complejo&);
        Complejo operator- (const Complejo&);
        Complejo operator* (const Complejo&);
        Complejo operator/ (const Complejo&);

    private:
        float real, imaginaria;

};

////////////////////////Constructores////////////////////////////////////////////
Complejo::Complejo()
{
    real=0;
    imaginaria=0;
}

Complejo::Complejo(float x)
{
    real=x;
    imaginaria=0;
}

Complejo::Complejo(float x, float y)
{
    real=x;
    imaginaria=y;
}
/////////////////Funciones-MÃ©todos///////////////////////////////////////////////
istream& operator>>(istream& c, Complejo& z)
{
    cout<<"Parte real: ";
    cin>>z.real;
    cout<<"Parte imaginaria: ";
    cin>>z.imaginaria;
}

ostream& operator<<(ostream& c, Complejo& z)
{

    char x='+';
    if (z.imaginaria<0){
        x='-';
        z.imaginaria*=-1;
    }
    if(z.imaginaria==1) cout<<"("<<z.real<<" "<<x<<" "<<"i)";
    else cout<<"("<<z.real<<" "<<x<<" "<<z.imaginaria<<"i)";
}

Complejo Complejo::operator+ (const Complejo& z)
{
    Complejo S;
    S.real = real+z.real;
    S.imaginaria = imaginaria+z.imaginaria;
    return S;
}

Complejo Complejo::operator- (const Complejo& z)
{
    Complejo S;
    S.real= real-z.real;
    S.imaginaria= imaginaria-z.imaginaria;
    return S;
}

Complejo Complejo::operator* (const Complejo& z)
{
    Complejo S;
    S.real = real*z.real-imaginaria*z.imaginaria;
    S.imaginaria = real*z.imaginaria+imaginaria*z.real;
    return S;
}

Complejo Complejo::operator/ (const Complejo& z)
{
    Complejo S;
    S.real = (real*z.real+imaginaria*z.imaginaria)/(z.real*z.real+z.imaginaria*z.imaginaria);
    S.imaginaria = (imaginaria*z.real-real*z.imaginaria)/(z.real*z.real+z.imaginaria*z.imaginaria);
    return S;
}

int main()
{
    int opc;
    char signo='+';
    Complejo A,B,R;
    cout<<"Programa para realizar operaciones con n\xa3meros complejos\n\n";

    cout<<"Datos del primer n\xa3mero complejo: "<<endl;
    cin>>A;
    cout<<"\nDatos del segundo n\xa3mero complejo: "<<endl;
    cin>>B;

    cout<<"\xa8Qu\x82 operaci\xa2n deseas realizar?"<<endl;
    cout<<"1) Suma"<<endl<<"2) Resta"<<endl<<"3) Multiplicacion"<<endl<<"4) Division"<<endl;
    do{
        cin>>opc;
    }while(opc<1 || opc>4);

    switch(opc){
        case 1:
            R = A+B;
            break;
        case 2:
            R = A-B;
            signo='-';
            break;
        case 3:
            R = A*B;
            signo='*';
            break;
        case 4:
            R = A/B;
            signo='/';
            break;
    }

	cout<<endl<<endl;
    cout<<A<<" "<<signo<<" "<<B<<" = "<<R;
	
    cout<<endl;
    system("PAUSE");
    return 0;
}
