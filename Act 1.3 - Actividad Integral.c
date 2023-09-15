// =========================================================
// File: Tarea2.c
// Author: Brisa Itzel Reyes Castro - A01710395
// Date: 15/09/2023
// =========================================================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//creamos nuestra structura 
struct SecuenciaConInversiones {
	//tipo de datos
    string secuencia;
    int inversiones;
   
    bool EsMenor(const SecuenciaConInversiones& otra) const {
        return inversiones < otra.inversiones;
    }
};

// Función para contar inversiones en una cadena creada 
//usamos lenght para contar el numero de argumentos
int ContarInversiones(const string& secuencia) {
    int inversiones = 0;
    int longitud = secuencia.length();
//utilizamos el for  para recorrer la cadena 
    for (int i = 0; i < longitud - 1; ++i) {
        for (int j = i + 1; j < longitud; ++j) {
            if (secuencia[i] > secuencia[j]) {
                inversiones++;
            }
        }
    }

    return inversiones;
}
//definimos nuestro main
int main() {
    int n, m;
    cin >> n >> m;
//creamos nuestro vector donde almacenaremos secuencia de inversiones
 //con el fin de  ordenarlos
    vector<SecuenciaConInversiones> secuenciasConInversiones(m);

    for (int i = 0; i < m; ++i) {
        cin >> secuenciasConInversiones[i].secuencia;
        secuenciasConInversiones[i].inversiones = ContarInversiones(secuenciasConInversiones[i].secuencia);
    }

    // Ordenar secuencias en función del número de inversiones
   // el begin() devuelve el iterador donde esta apuntando
   //utilIZAMOS EL SORT para ordenar los elementos 
    sort(secuenciasConInversiones.begin(), secuenciasConInversiones.end(), [](const SecuenciaConInversiones& a, const SecuenciaConInversiones& b) {
        return a.EsMenor(b);
    });

    // Imprimir secuencias ordenadas
    for (const SecuenciaConInversiones& sec : secuenciasConInversiones) {
        cout << sec.secuencia << endl;
    }

    return 0;
}