//----Algoritmo 'Insertion Sort' (Ordenamiento por inserción)----//
#include <iostream>
#include<ctime>

unsigned t0,t1;
 
void insertionSort(int [], int);  
void printArray(int [], int);  

  
/* Driver code */
int main()  
{  
    t0=clock();
    int arr[] = { 12, 11, 13, 5, 6 };
    //int arr[] = {7,2,4,1,5,3 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    
    //----Llamamos a las funciones----//
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    
    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<<"Execution time: "<< time <<std::endl;
    return 0;  
}  

//----Implementaciónes de las funciones----//
void insertionSort(int arr[], int n)  
{  
    int key;  //key es el valor que extraemos del grupo desordenado para colocarlo en el grupo ordenado
    for (int i = 1; i <= n-1; i++) 
    {  
        key = arr[i];  //key almacena la segunda variable del arreglo
        int agujero = i ;  
  
        //----Agujero sera igual a 0 cuando se encunetre en la primera posición ----//
        //----Y haremos el recorrido a la derecha de arr[agujero-1] si el valor actual -> key es menor a este----// 
        while ( agujero >=0 && arr[agujero-1] > key) 
        {  
            arr[agujero] = arr[agujero-1]; //desplazamiento  
            agujero-=1;  //retrocede una posición tras hacer el desplazamiento para asi poder seguir comparando
 
        }
        //----SI no se cumplen las condiciones del while----//
        //----quiere decir quen estamos en la posición 0 o no hubo necesidad de desplazamientos----//  
        arr[agujero]=key; //simplemente el valor se mantiene
    }  
}  

//----Función para imprimir un arreglo----//  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        std::cout << arr[i] << " ";  
    std::cout<<std::endl; 
}  

