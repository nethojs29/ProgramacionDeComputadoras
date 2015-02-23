/*
  Programa:Metodos_de_Ordenamiento.cpp
  Nombre: Erick Ferndo Lopez Fimbres
  Fecha:25/03/14 17:02
  Descripción: Programa que llena de manera aleatoria o por captura del usuario un arreglo que ese arreglo hace un histograma y que es 
  ordenado mediante los metodos burbuja, seleccion, insercion y quick sort, cada uno de estos metodos es una funcion tambien 
  estan otras funciones como la de impresion, captura, la de crear y liberar y se puede ver como se va modificando el histograma al usar 
  cada una de las funciones los oredna de manera diferente unas mas eficientes que otras pero al final hacen cumplen con su funcion ordenar.
  

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <new>
#include <conio2.h>

using namespace std;

#define MAX 70 //definimos el valor maximo de largo del histograma
#define NUMMAX 20//los valores solo pueden ser del 1 al 20 
//Prototipo de Funciones//
int * Crear(int );
void Liberar(int *&);
int Menu();
void LlenarAleatorio(int [],int,int);
void LlenarPorCaptura(int [],int,int);
void Impresion(const int [], char, int, int, int=0, int=0);
void Insercion (int [],char,int,int);
void Burbuja (int [],char,int,int);
void Seleccion (int [],char,int,int);
void QuickSort(int [], char, int, int, int, int);
void gotoxy(int x, int y);
void textcolor(int color);

int main()
{
	int *Elementos = NULL;//Este es el arreglo lo iniciamos en NULL por si no hay memoria suficiente 
    int n;//aqui ira el tamaño del histograma es decir lo largo
    int Opcion;//guardamos la opcion que arroja el menu
	int resp;// respuesta del usuario para gener aleatorio o capturarlos el mismo
	char simbolo; //simbolo del histograma
	
    
    while(Opcion!=0){//Lo hacemos hasta que el usuario desee salir
        Opcion=Menu();//presentamos el menu
        if(Opcion==0) return 0;//si la opcion es 0 terminamos
    	
    	do{
    		cout<<"tama\xA4o del histograma: ";
    		cin>>n;
    	}while(n<1 || n>MAX);
    
    	if(!(Elementos = Crear(n))){
		  cout<<"Lo sentimos no hay memoria suficiente para llevar a cabo este programa"<<endl;	
		  system("PAUSE");
		  return 0;
	   }
	   	
    	do{
        	cout<<"\xA8 \bC\xA2mo desea llenar los datos del histograma?"<<endl;
        	cout<<"1) Quiero llenarlo yo mismo"<<endl;
        	cout<<"2) Quiero llenarlo aleatoriamente"<<endl;
    	    cin>>resp;
    	   if(resp<1 || resp>2){
                cout<<"Opci\xA2 no disponible.Introduzaca una correcta: ";
                cin>>resp;
            }
    	}while(resp<1 || resp>2);
    	
        cout<<"Introduzca un s\xA1mbolo: ";
    	cin>>simbolo;
        	
        system("cls");
    	if(resp==1){
            LlenarPorCaptura(Elementos,n,NUMMAX);
            system("cls");
            switch(Opcion){
                case 1: Burbuja(Elementos,simbolo,NUMMAX,n); break;
                case 2: Seleccion(Elementos,simbolo,NUMMAX,n); break;
                case 3: Insercion(Elementos,simbolo,NUMMAX,n); break;
                case 4: QuickSort(Elementos,simbolo,NUMMAX,n,0,n-1); break;
            }
        }
        if(resp==2){
            LlenarAleatorio(Elementos,n,NUMMAX);
            switch(Opcion){
                case 1: Burbuja(Elementos,simbolo,NUMMAX,n); break;
                case 2: Seleccion(Elementos,simbolo,NUMMAX,n); break;
                case 3: Insercion(Elementos,simbolo,NUMMAX,n); break;
                case 4: QuickSort(Elementos,simbolo,NUMMAX,n,0,n-1); break;
            }
        }
        system("pause");
        system("cls");
        Liberar(Elementos);//liberamos el arreglo
    }
    system("PAUSE");
	return 0;
}
//Definicion de funciones//
//*******************************************************************************************************************************************
int Menu()
{
    int opcion;
    
    cout<<"Programa que realiza un histograma hecho con figuras y es ordenado mediante los metodos de Burbuja, Selecci\xA2n, Inserci\xA2n y Quick Sort"<<endl<<endl;
    
    cout<<" 0) Salir"<<endl;
    cout<<" 1) Burbuja"<<endl;
    cout<<" 2) Selecci\xA2n"<<endl;
    cout<<" 3) Inserci\xA2n"<<endl;
    cout<<" 4) Quick Sort"<<endl<<endl;
    
    cout<<endl;
    cout<<"\xA8 \bC\xA3 \bal m\x82todo de ordenamiento elige? ";
    cin>>opcion;
    do{
        if(opcion<0 || opcion>4){
            cout<<"Opci\xA2n no disponible. Por favor introduzca una opci\xA2n correcta: ";
            cin>>opcion;
        }
    }while(opcion<0 || opcion>4);
    return opcion;
}
//*******************************************************************************************************************************************
void LlenarAleatorio(int Elem [],int tamMax,int NumM)
{
    srand(time(NULL));
    for(int i=0;i<tamMax;++i) Elem[i]=1+rand()%NumM;   //Generamos los numeros alazar y los guardamos en el arreglo
}
//*******************************************************************************************************************************************
void LlenarPorCaptura(int Elem [],int tamMax,int NumM)
{
    for(int i=0;i<tamMax;++i){ //Pedimos los elementos uno por uno al usuario
        do{
            cout<<"Introduzca el valor n\xA3mero "<<i+1<<" : ";
            cin>>Elem[i];
        }while(Elem[i]<1 || Elem[i]>NumM);//Validamos que esten en el rango requerido de 1 a 20
    }
}
//*******************************************************************************************************************************************
void Impresion(const int Elem [], char simbolo, int NumM, int tam, int izq, int der)
{
    //Todos estos dos ciclos imprimen las columnas
	for(int j=NumM;j>=1;--j){ //controla lo alto de la columna
		for(int i=0;i<tam;++i) //controla lo largo
			cout<< (Elem[i]>=j ? simbolo :' '); //mientras el numero sea menor j que comienza en el maxiomo imprimira espacios en blanco y se disminuye j
		cout<<endl;	 //Es lo que le da la forma de columna
	}
	
	cout<<endl;	//Este salto de linea le da la forma de columna
}
//*******************************************************************************************************************************************
void Insercion (int Elem [], char simbolo, int NumM, int tam)
{
    int aux; //Declaramos una variable auxiliar para poder realizar los intercambios
    for (int i=1;i<tam;i++){ //iniciamos un ciclo externo que recorrera todos los elementos del arreglo desde el segundo elemento
        aux=Elem[i]; //guardamos al segundo elemento en la variable auxiliar
        for (int j=i;(j>0 && aux<Elem[j-1]);--j){//iniciamos otro ciclo para hacer las comparaciones entre el siguiente elemento y los anteriores mientras recorremos el arreglo
           Elem[j]=Elem[j-1];   //hacemos los intercambios puesto que en el ciclo se revisa si el segundo valor es menor que el primero el segundo valor toma el valor del primero           
           Elem[j-1]=aux; //como el segundo valor era menor toma la posicion numero uno
           Impresion(Elem,simbolo,NumM,tam); //llamamos a la funcion imprimir para que cada vez que haya un cambio se note
           gotoxy(1,1);//nos regresamos a la posicion inicial para que se vea continua la impresion
        }
    }
    gotoxy(1,21);//cuando termine nos vamos a esta posicion para que se vea bien y no estorben las letras del final 
}
//********************************************************************************************************************************************
void Burbuja(int Elem [], char simbolo, int NumM, int tam)
{
    int mayor;//Declaramos una variable auxiliar para guardar el mayor elemento de todos y poder hacer las comparaciones 
    for(int i=0;i<tam-1;++i){//iniciamos un ciclo externo que recorrera todos los elementos del arreglo desde el primer elemento hasta uno anterior
        for(int j=0;j<tam-1;++j){//iniciamos otro ciclo para hacer las comparaciones entre todos los elementos mientras recorremos el arreglo
            if(Elem[j]>Elem[j+1]){//si primer elemento es mayor al siguiente si no lo ignoramos e incrementamos
                mayor=Elem[j];//entonces el mayor es el primer elemento  y lo guardamos en la variable auxiliar
                Elem[j]=Elem[j+1];//al primer elemento del arreglo le asignamos el segundo puesto que es el menor
                Elem[j+1]=mayor;//al segundo elemento del arreglo le asignamos el primero puesto que es el mayor
                Impresion(Elem,simbolo,NumM,tam);//llamamos a la funcion imprimir para que cada vez que haya un cambio se note
                gotoxy(1,1);//nos regresamos a la posicion inicial para que se vea continua la impresion
            }
        }
    }
    gotoxy(1,21);//cuando termine nos vamos a esta posicion para que se vea bien y no estorben las letras del final 
}
//*******************************************************************************************************************************************
void Seleccion (int Elem [], char simbolo, int NumM, int tam)
{
    int menor;//Declaramos una variable auxiliar para guardar el menor elemento de todos y poder hacer las comparaciones 
    for(int i=0;i<tam-1;++i){//iniciamos un ciclo externo que recorrera todos los elementos del arreglo desde el primer elemento hasta uno anterior
        for(int j=i+1;j<tam;++j){//iniciamos otro ciclo para hacer las comparaciones entre todos los elementos del arreglo mientras recorremos el arreglo
            if(Elem[j]<Elem[i]){   //si el segundo elemeto es menor al primero entonces
                menor=Elem[j];//guardamos al segundo elemento en la avriable auxiliar llamada menor
                Elem[j]=Elem[i];//al segundo elemento le asignamos el valor del primer elemento y
                Elem[i]=menor;//al primer elemento le asignamos el valor de la variable auxiliar que tenia el valor del segundo elemento del arreglo que era el menor
                Impresion(Elem,simbolo,NumM,tam);//llamamos a la funcion imprimir para que cada vez que haya un cambio se note
                gotoxy(1,1);   //nos regresamos a la posicion inicial para que se vea continua la impresion
            }
        }
    }
    gotoxy(1,21); //cuando termine nos vamos a esta posicion para que se vea bien y no estorben las letras del final 
}
//*******************************************************************************************************************************************
void QuickSort(int Elem [], char simbolo, int NumM, int tam, int izq, int der)
{
    int pivote, aux,i,j; 
    i=izq;//llamamos i al primer valor que sera 0
    j=der;//llamamos j al tam del arreglo-1 
    pivote=Elem[(i+j)/2];//obtenemos el pivote este sera el valor del elemento que este en el primer elemento del arreglo + el tamaño del arreglo/2
    
    do{
        while((Elem[i]< pivote)&&(j<=der)){//si el primer elemento es menor al valor del pivote y que el valor de la derecha este antes de la ultima posicion o en la ultima posicion
            ++i;//avanzamos por la izquierda
        }
        while((pivote<Elem[j])&&(j>izq)){//si el pivote es menor que el elemento de la derecha y el valor de la derecha es mayor que el de la izquierda
            --j;//reducimos el valor de la derecha para ir uno anterior
        }
        if(i<=j){ //cuando no pase lo de arriba que es el caso donde estan medio ordenados es decir los menores a la izq y los mayores a la der hacemos los intercambios
            aux=Elem[i];//guardamos elprimer elemento en la variable auxiliar
            Elem[i]=Elem[j]; //como el primer elemento sera menor que el del lado de la derecha los cambiamos
            Elem[j]=aux;//el elemento de la derecha tomara el valor del de la izquierda que sera un valor mayor
            ++i;
            --j;
            //inv¿crementamos y decrementamos para avanzar
            Impresion(Elem,simbolo,NumM,tam,izq,der);//imprimimos si hubo intercambios
            gotoxy(1,1);//nos regresamos a la posicion inicial para que se vea continua la impresion
        }
    }while(i<=j);//mientra avanzamos de izquierda a derecha y derecha a izquierda y hasta que sean iguales dejaremos de hacer el recorrido y los intercambios 
    if(izq<j){//aqui nos encargamos de la parte izquierda es como si hubieramos partido en la lista de valores
    //volvemos a lo mismo hacemos el mismo proceso pero como ya tenemos una funcion la podemos llamar
            QuickSort(Elem,simbolo,NumM,tam, izq,j);//llamamos a la misma funcion pero ahora sera de 0 hasta antes del pivote
            gotoxy(1,1);//nos vamos a la primera posicion
            Impresion(Elem,simbolo,NumM,tam,izq,der);//llamamos a la funcion imprimir para que se vea el cambio
            gotoxy(1,1);//regresamos a la primera posicion
    }
    if( i < der ) {//aqui nos encargamos de la segunda lista de valores que son los mayores de la parte derecha
            QuickSort(Elem,simbolo,NumM,tam, i, der ); //llamamos a la misma funcion pero ahora sera de el pivote hasta antes del ultimo elemento
            gotoxy(1,1);//nos vamos a la primera posicion
            Impresion(Elem,simbolo,NumM,tam,izq,der);//llamamos a la funcion imprimir para que se vea el cambio
            gotoxy(1,1);//regresamos a la primera posicion
    }
    gotoxy(1,21);//al terminar nos vamos a esta posicion para que se vea bien
}
//********************************************************************************************************************************************
int * Crear(int n)
{
	try{   //pedimos memoria la sistema
		return new int[n];    //pedimos el tamaño
	}catch(...){   //si no hay memoria suficiente
		return NULL;  //regresamos un 0
	}
}
//********************************************************************************************************************************************
void Liberar(int *&Arreglo)
{
	delete [] Arreglo; //borramos el arreglo
	Arreglo = NULL;
}
