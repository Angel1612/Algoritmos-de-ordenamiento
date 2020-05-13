//----Algoritmo 'Radix Sort'----//
#include<iostream> 
#include<ctime>

unsigned t0,t1;

//----Prototipos de las funciones----//
int getMax(int [], int); //----Retorna  numero mayor del arreglo----//
void radixsort(int [], int); //general
void countSort(int [], int, int); //hace el conteo (digito a digito)--actualización de valores
void print(int [], int);


int main() 
{
    t0=clock();
     
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
    
	radixsort(arr, n); 
	print(arr, n);

    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<<  << time <<std::endl; 

	return 0; 
} 

//----Obetenemos el valor maximo de forma convencional (iterativamente)----//
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; //guarda el maximo elemento del arreglo 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; //se retorna este valor maximo, qué sera nuestro 'rango'/techo
} 


void radixsort(int arr[], int n) 
{ 
	//----Usamos la funcion getMax para obtener el número maximo----//
	int m = getMax(arr, n); 

	//exp es 10 ^ i donde i es el número de dígito actual
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 


//hace el conteo con ayuda de 'exp'
void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; // output array 
	int i, count[10] = {0}; 

	//----Almacenamos los valores en count----//
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

    //----Actualiza count[i] para tener la posición real del digito en la salida----//
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	//construye la matriz de salida 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		std::cout << arr[i] << " "; 
    std::cout<<std::endl; 

} 

