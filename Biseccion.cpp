#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>
#include <conio2.h>

using namespace std;

long double evaluar(long double);
void encabezado();


int main(){
    int n;
    long double an=0,bn=1,pn,fan,fbn,fpm,fpn,error;

    cout<<"Programa para calcular la aproximaci\xa2n a la ra\xa1z de F(x)"<<endl;
    cout<<"F(x) = e^-x + 4x^3 - 5\n\n"<<endl;

    do{
        cout<<"Dame el n\xa3mero de iteraciones: ";
        cin>>n;
        if(n<=0) cout<<"N\xa3mero no v\xa0lido"<<endl;
    }while(n<=0);

    system("cls");


        pn=(an+bn)/2;
        fan=evaluar(an);
        fbn=evaluar(bn);
        fpn=evaluar(pn);

        encabezado();

        gotoxy(1,3); cout<<'1';
        gotoxy(4,3); cout<<an;
        gotoxy(17,3); cout<<bn;
        gotoxy(25,3); cout<<pn;
        gotoxy(35,3); cout<<fan;
        gotoxy(49,3); cout<<fpn;
        gotoxy(64,3); cout<<'-';

        error=1;

        for(int i=2; i<=n || fpn==0;++i){
            //if(fan*fpn>=0) an=pn;
            if(fan*fpn<0) bn=pn;
                else an=pn;

            fpm=fpn;

            pn=(an+bn)/2;
            fan=evaluar(an);
            fbn=evaluar(bn);
            fpn=evaluar(pn);
            error=abs(fpn-fpm);

            gotoxy(1,i+2); cout<<i;
            gotoxy(4,i+2); cout<<an;
            gotoxy(17,i+2); cout<<bn;
            gotoxy(25,i+2); cout<<pn;
            gotoxy(35,i+2); cout<<fan;
            gotoxy(49,i+2); cout<<fpn;
            gotoxy(64,i+2); cout<<error;

        }
}

long double evaluar(long double x){
    return (x-pow(2,-x));
}

void encabezado(){
    gotoxy(1,2);
    cout<<"n";
    gotoxy(4,2);
    cout<<"an";
    gotoxy(17,2);
    cout<<"bn";
    gotoxy(24,2);
    cout<<"pn";
    gotoxy(37,2);
    cout<<"f(an)";
    gotoxy(49,2);
    cout<<"f(pn)";
    gotoxy(65,2);
    cout<<"error";
}

