#include <iostream>
#include <vector>
using namespace std;

struct NodoN {
    int valor;
    vector<NodoN*> hijos;
    NodoN(int v) : valor(v) {}
};

// Cuenta todos los nodos de un árbol N-ario de forma recursiva

int contarNodos(NodoN* raiz) {
    if (raiz == nullptr)  // Caso base: nodo vacío no cuenta
        return 0;

    int total = 1;  // Cuenta el nodo actual

    // Recorre cada hijo y suma recursivamente sus nodos
    for (NodoN* hijo : raiz->hijos) {
        total += contarNodos(hijo);
    }

    return total;
}

// Función auxiliar para liberar memoria recursivamente
void liberarArbol(NodoN* nodo) {
    if (nodo == nullptr) return;
    for (NodoN* hijo : nodo->hijos)
        liberarArbol(hijo);
    delete nodo;
}

int main() {
    
    NodoN* n5 = new NodoN(5);
    NodoN* n6 = new NodoN(6);

    NodoN* n2 = new NodoN(2);
    n2->hijos.push_back(n5);
    n2->hijos.push_back(n6);

    NodoN* n3 = new NodoN(3);
    NodoN* n4 = new NodoN(4);

    NodoN* raiz = new NodoN(1);
    raiz->hijos.push_back(n2);
    raiz->hijos.push_back(n3);
    raiz->hijos.push_back(n4);

    cout << "--- Prueba Ejercicio 1 ---" << endl;
    cout << "Nodos esperados:  6" << endl;
    cout << "Nodos calculados: " << contarNodos(raiz) << endl;

    liberarArbol(raiz);
    return 0;
}
