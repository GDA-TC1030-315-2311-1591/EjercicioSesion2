#include <fstream>
#include "Fraccion.hpp"
using namespace std;

void lecturaArchivo(Fraccion arr[]){
    int num, den;
    ifstream archivo;
    archivo.open("Datos.txt");
    int i=0;
    while(archivo>>num>>den){
        arr[i].setNum(num);
        arr[i].setDen(den);
        i++;
    }
    archivo.close();
}

void escrituraArchivo(int& max){
    int num, den, cuantos;
    ofstream archivo;
    archivo.open("Datos.txt");
    cout<<"Numero de fracciones: ";
    cin>>max;
    for(int i=0;i<max;i++){
        cout<<"Ingresa el numerador y el denominador separado por un espacio: ";
        cin >> num >> den;
        archivo<<num<<" ";
        archivo<<den<<endl;
    }
    archivo.close();
}

void modificaArreglo(Fraccion arr[], int tam, Fraccion& otra){
    for(int i=0; i<tam;i++){
        arr[i] = arr[i].suma(otra);
    }

}

void imprimeArreglo(Fraccion arr[], int tam){
    for(int i=0; i<tam;i++){
        arr[i].imprime();
    }
}

int main(){
    int cuantos;
    escrituraArchivo(cuantos);
    Fraccion arreglo[cuantos];
    lecturaArchivo(arreglo);
    Fraccion asumar(1,2);
    imprimeArreglo(arreglo, cuantos);
    modificaArreglo(arreglo, cuantos, asumar);
    cout<<"\nLas fracciones a las que se les sumo 1/2:\n";
    imprimeArreglo(arreglo, cuantos);
    cout<<endl;
    return 0;
}