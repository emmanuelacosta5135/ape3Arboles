#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Inserta un valor en un Árbol Binario de Búsqueda (BST)
// Regla BST: menores van a la izquierda, mayores a la derecha

Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr)          // Caso base: posición vacía, crear nodo nuevo
        return new Nodo(valor);

    if (valor < raiz->valor)      // El valor es menor → va al subárbol izquierdo
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else if (valor > raiz->valor) // El valor es mayor → va al subárbol derecho
        raiz->derecho = insertar(raiz->derecho, valor);
    // Si valor == raiz->valor, no se inserta (no se permiten duplicados)

    return raiz;  // Retorna el nodo actual con el subárbol ya actualizado
}

// Libera la memoria del árbol recursivamente
void liberarArbol(Nodo* nodo) {
    if (nodo == nullptr) return;
    liberarArbol(nodo->izquierdo);
    liberarArbol(nodo->derecho);
    delete nodo;
}

int main() {
    
    Nodo* raiz = new Nodo(10);

    raiz = insertar(raiz, 5);   // 5 < 10  → izquierda de 10
    raiz = insertar(raiz, 15);  // 15 > 10 → derecha de 10
    raiz = insertar(raiz, 3);   // 3 < 10 → izq de 10 → 3 < 5 → izq de 5

    cout << "--- Prueba Ejercicio 2 ---" << endl;
    cout << "Raiz (Esperado 10): " << raiz->valor << endl;

    if (raiz->izquierdo)
        cout << "Hijo Izquierdo (Esperado 5): " << raiz->izquierdo->valor << endl;
    else
        cout << "Hijo Izquierdo: null" << endl;

    if (raiz->derecho)
        cout << "Hijo Derecho (Esperado 15): " << raiz->derecho->valor << endl;
    else
        cout << "Hijo Derecho: null" << endl;

    if (raiz->izquierdo && raiz->izquierdo->izquierdo)
        cout << "Hijo Izq del 5 (Esperado 3): " << raiz->izquierdo->izquierdo->valor << endl;
    else
        cout << "Hijo Izq del 5: null" << endl;

    liberarArbol(raiz);
    return 0;
}
