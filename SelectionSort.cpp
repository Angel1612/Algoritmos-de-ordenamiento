//----Algortimo 'Selection Sort' (Ordenamiento por selección) ----//
#include <iostream>
#include<ctime>
unsigned t0,t1; 
  
//----Prototipos de las funciones----//
void swap(int *xp, int *yp);  //funcion swap convencional
void selectionSort(int arr[], int n);  
void printArray(int arr[], int size); //funcion para mostrar un array (iterativamente)

int main()  
{  
    t0=clock();
    
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    
    //----Llamamos a las funciones----//
    selectionSort(arr, n);  
   
    printArray(arr, n);  
    
    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution time: " << time <<std::endl;

    return 0;  
}  
  

//----definiciones de las funciones----// 
//----Función 'swap' convencional----//
void swap(int *xp, int *yp)  
{  
    if (*xp != *yp){ //las variables pueden ser iguales
        int temp = *xp;  
        *xp = *yp;  
        *yp = temp;
    }
}  
  
void selectionSort(int arr[], int n)  
{  
    int  min_idx;  
  
    for (int i = 0; i < n-1; i++)  
    {  
        //----Encuentra el minimo en el array desordenao ----//  
        min_idx = i;  
        for (int j = i+1; j < n; j++){ 
            if (arr[j] < arr[min_idx]){  
                min_idx = j;
            }  
        }
        //----Intercambio entre el elemento menor y el primer elemento----//
        swap(&arr[min_idx], &arr[i]); //'arr[min_idx]' puede ser igual a 'arr[i]' 
    }  
}  
  
//----Función convencional para imprimir un arreglo----//
void printArray(int arr[], int tam)  
{    
    for (int i=0; i < tam; i++)  
        std::cout << arr[i] << " ";  
    std::cout << std::endl;  
}  