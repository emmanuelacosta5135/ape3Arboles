#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

// Recorrido In-Order: izquierdo → raíz → derecho
// Esto garantiza que los valores salgan en orden ascendente en un BST
void inOrderAux(Nodo* nodo, vector<int>& resultado) {
    if (nodo == nullptr)  // nodo vacío, no hay nada que recorrer
        return;

    inOrderAux(nodo->izquierdo, resultado);  // 1. Visita el subárbol izquierdo
    resultado.push_back(nodo->valor);        // 2. Procesa el nodo actual
    inOrderAux(nodo->derecho, resultado);    // 3. Visita el subárbol derecho
}

// Función pública que inicializa el vector y lanza el recorrido
vector<int> recorridoInOrder(Nodo* raiz) {
    vector<int> resultado;
    inOrderAux(raiz, resultado);
    return resultado;
}

int main() {
    Nodo* raiz = new Nodo(4);
    raiz->izquierdo = new Nodo(2);
    raiz->derecho = new Nodo(6);
    raiz->izquierdo->izquierdo = new Nodo(1);
    raiz->izquierdo->derecho = new Nodo(3);
    raiz->derecho->izquierdo = new Nodo(5);
    raiz->derecho->derecho = new Nodo(7);

    vector<int> res = recorridoInOrder(raiz);

    cout << "--- Prueba Ejercicio 4 ---" << endl;
    cout << "Resultado esperado: 1 2 3 4 5 6 7 " << endl;
    cout << "Tu resultado:       ";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    // Liberar memoria
    delete raiz->izquierdo->izquierdo;
    delete raiz->izquierdo->derecho;
    delete raiz->derecho->izquierdo;
    delete raiz->derecho->derecho;
    delete raiz->izquierdo;
    delete raiz->derecho;
    delete raiz;

    return 0;
}
