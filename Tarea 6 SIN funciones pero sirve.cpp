/*
  Name:
  Author: IRC
  Date: 11/03/14 14:22
  Description:
*/

#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 20
typedef char tipo;


bool Pertenece(tipo [], int, tipo);

int main()
{
    tipo A[MAX],B[MAX],U[2*MAX],I[MAX],C[MAX],D[MAX];
    int cardA,cardB,cardU,cardI=0,cardC=0,cardD=0,opc;

    cout<<"1) Uni\xa2n"<<endl<<"2) Intersecci\xa2n"<<endl<<"3) Complemento"<<endl<<"4) Contenci\xa2n"<<endl<<"5) Diferencia"<<endl<<"Escoge una opci\xa2n: ";

	do{
		cin>>opc;
		if(opc<1 || opc>5) cout<<"Opci\xa2n no disponible"<<endl;
	}while(opc<1 || opc>5);
    do{
        cout<<"Cardinalidad de A: ";
        cin>>cardA;
    }while(cardA<0 || cardA>MAX);

    cout<<"Introduce los "<<cardA<<" elementos del conjunto A\n";
    for(int i=0;i<cardA;){
        cout<<"Elemento "<<i+1<<": ";
        cin>>A[i];
        if(!Pertenece(A,i,A[i])) ++i;
        else cout<<"Elemento repetido, introd\xA3 \bcelo de nuevo...\n";
    }

    cout<<endl;
    do{
        cout<<"Cardinalidad de B: ";
        cin>>cardB;
    }while(cardB<0 || cardB>MAX);

    cout<<"Introduce los "<<cardB<<" elementos del conjunto B\n";
    for(int i=0;i<cardB;){
        cout<<"Elemento "<<i+1<<": ";
        cin>>B[i];
        if(!Pertenece(B,i,B[i])) ++i;
        else cout<<"Elemento repetido, introd\xA3 \bcelo de nuevo...\n";
    }



    //Uniendo los conjuntos A y B

	for(int i=0;i<cardA;++i) U[i]=A[i];
    cardU=cardA;
    for(int i=0;i<cardB;++i)
    	if(!Pertenece(A,cardA,B[i])) U[cardU++]=B[i];


    cout<<"\n\n{ ";
    for(int i=0;i<cardA;++i) cout<<A[i]<<",";
    cout<<"\b } U ";

    cout<<"{ ";
    for(int i=0;i<cardB;++i) cout<<B[i]<<",";
    cout<<"\b } = ";

    cout<<"{ ";
    for(int i=0;i<cardU;++i) cout<<U[i]<<",";
    cout<<"\b }";

   // Intersección de los conjuntos A y B

	for(int i=0,k=0;i<cardA;++i){
    	for(int j=0;j<cardB;++j){
    		if(A[i]==B[j]){
    			 I[k++]=A[i];
    			 cardI++;
    		}
    	}
    }

    for(int i=0;i<cardI;++i) cout<<I[i]<<",";
    cout<<endl;

    //Complemento de B con universo A
    int k=0;
    for(int i=0;i<cardA;++i){
    	if(!Pertenece(B,cardB,A[i])){
    		 C[k++]=A[i];
    		 cardC++;
    	}
    }

    for(int i=0;i<cardC;++i) cout<<C[i]<<",";
    cout<<endl;

    //Contención de A en B
    int cont=0;
    for(int i=0;i<cardA;++i){
    	if(Pertenece(B,cardB,A[i])){
    		cont++;
    	}
    }
    if(cont==cardA) cout<<"A esta contenido en B"<<endl;

    //Diferencia de A menos B
    k=0;
    for (int i=0;i<cardA;++i){
    	if(!Pertenece(B,cardB,A[i])){
			D[k++]=A[i];
			cardD++;
    	}
    }
    for(int i=0;i<cardD;++i) cout<<D[i]<<",";
    cout<<endl;

    cout<<endl;
    system("pause");
    return 0;
}


bool Pertenece(tipo Conj[], int card, tipo elem)
{
    for(int j=0;j<card;++j)
        if(elem==Conj[j]) return true;
    return false;
}
