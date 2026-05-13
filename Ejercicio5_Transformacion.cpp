#include <iostream>
#include <algorithm> // std::max
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Calcula la altura de un árbol binario (número de niveles)
// La altura es el camino más largo desde la raíz hasta una hoja
int calcularAltura(Nodo* raiz) {
    if (raiz == nullptr)  // Caso base: árbol vacío tiene altura 0
        return 0;

    int alturaIzq = calcularAltura(raiz->izquierdo);  // Altura del subárbol izquierdo
    int alturaDer = calcularAltura(raiz->derecho);    // Altura del subárbol derecho

    // La altura del nodo actual es 1 (el nodo mismo) +
    // el mayor entre ambos subárboles
    return 1 + max(alturaIzq, alturaDer);
}

// Libera la memoria del árbol recursivamente
void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    delete nodo;
}

int main() {
    
    Nodo* raiz = new Nodo(1);
    raiz->derecho = new Nodo(2);
    raiz->derecho->izquierdo = new Nodo(3);

    cout << "--- Prueba Ejercicio 3 ---" << endl;
    cout << "Altura esperada:  3" << endl;
    cout << "Altura calculada: " << calcularAltura(raiz) << endl;
    cout << "Altura de arbol nulo (esperado 0): " << calcularAltura(nullptr) << endl;

    liberarArbol(raiz);
    return 0;
}
