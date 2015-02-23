/*
  Nombre: Métodos de ordenamiento
  Autor: Jesús Ernesto Jaramillo Salazar
  Descripción: Dado un connjunto de n elementos no ordenados, se ordenarán según el proceso que haya escogido el usuario
  Fecha: 30/03/14 15:14
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int * Crear(int);
void Captura(int[],int);
void Histograma(int[],int, int);
void Generar(int[],int,int,int);
void Burbuja(int[],int);
void Seleccion(int[],int);
void Insercion(int[],int);
void Quicksort(int[],int,int);

int main()
{
	int *array,n,opc,Sel;
	
	cout<<"Programa para ordenar un conjunto de n elementos. (1<= n <= 70)\n\n";
	
	do{
		cout<<"n: ";
		cin>>n;		
	}while (n<1 || n>70);
	
	if(!(array = Crear(n))){
		cout<<"No hay memoria...\n";	
		system("PAUSE");
		return 0;
	}
	
	do{
		cout<<"\xa8Quieres generar los elementos del arreglo al azar? (0 Azar, 1 Dados por usuario)";
		cin>>Sel;
	}while (Sel <0 || Sel>1);
	
	if(Sel==0){
		Generar(array,n,1,20);	
	}else{
		Captura(array,n);
	}
	
	do{
		cout<<"\n \xa8Qu\x82 procedimiento de ordenamiento deseas utilizar?"<<endl<<"1) Burbuja"<<endl<<"2) Selecci\xa2n"<<endl<<"3) Inserci\xa2n"<<endl<<"4) Quicksort"<<endl;
		cin>>opc;
		if(opc<1 || opc>4) cout<<"Opci\xa2n no disponible\n";
	}while(opc<1 || opc>4);
	
	switch(opc){
		case 1: Burbuja(array,n);
				break;
		case 2: Seleccion(array,n);
				break;
		case 3: Insercion(array,n);
				break;
		case 4: Quicksort(array,0,20);
				break;
	}
	
  	cout<<endl;
   	system("PAUSE");
	return 0;
}

int * Crear(int n)
{
	try{
		return new int[n];
	}catch(...){
		return NULL;
	}
}

void Generar(int array[],int n,int inicio,int fin)
{
	srand(time(NULL));
	for(int i=0;i<n;++i) array[i]=inicio+rand()%(fin-inicio+1);
}

void Captura(int array[],int n)
{
	for(int i=0;i<n;++i){
		cout<<"Elemento "<<i+1<<" del Conjunto: ";
		cin>>array[i];
		cout<<endl;
	}
}

void Burbuja(int array[],int n)
{
	int k;
	for(int i=1;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
        	system("cls");
        	Histograma(array,20,n);
        	system("pause");
            if(array[j]>array[j+1]){
            	k=array[j+1]; array[j+1]=array[j]; array[j]=k;
            }
            
        }
    }
}
void Histograma (int array[], int max, int n)
{
	for(int j=max;j>=1;--j){
		for(int i=0;i<n;++i)
			cout<< (array[i]>=j ? '*' :' ');
		cout<<endl;	
	}
}

void Seleccion(int array[],int n)
{
	for (int i=0;i<n;++i){
    	int aux,menor;
    	menor = i;
    	for (int j=i+1;j<n;j++){
    		
			if(array[j]<array[menor]){
    			menor = j;
    		}
    	}
    	system("cls");
        Histograma(array,20,n);
        system("pause");
    	aux=array[i]; array[i]=array[menor]; array[menor]=aux;
    }
}

void Insercion (int array[],int n)
{
	int aux,j;
  	for (int i = 1; i < n; i++){
         aux = array[i];
         j = i - 1;
         while (j >= 0 && array[j] > aux){
              array[j + 1] = array[j];
              j--;
         }
		          
         array[j + 1] = aux;
         system("cls");
         Histograma(array,20,n);
         system("pause");
  	} 
}

void Quicksort(int array[], int izq, int der)
{
	int i,j,x,aux;
	i = izq;
	j = der;
	x = array[(izq+der)/2];
		
		do{
			while((array[i]< x) && (j<=der)){ 
				i++;
			}
			while((x<array[j]) && (j>izq)){ 
				j--;
			}
			if(i<=j){ 
				aux=array[i];
				array[i] = array[j];
				array[j] = aux;
				i++;
				j--;
			}
		}while(i<=j);
		
		system("cls");
        Histograma(array,20,der+1);
        system("pause");
		
		if(izq<j){
			Quicksort(array,izq,j);
		}
		if(i<der){
			Quicksort(array,i,der); 
		}
		
}
