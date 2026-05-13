class Nodo {
    int valor;
    Nodo izquierdo, derecho;
    Nodo(int valor) { this.valor = valor; }
}

public class Ejercicio2_Binario {

    // Inserta un valor en un Árbol Binario de Búsqueda (BST)
    // Regla BST: menores van a la izquierda, mayores o iguales a la derecha
   
    public static Nodo insertar(Nodo raiz, int valor) {
        if (raiz == null)           // Caso base: posición vacía, crear nodo nuevo
            return new Nodo(valor);

        if (valor < raiz.valor)     // El valor es menor → va al subárbol izquierdo
            raiz.izquierdo = insertar(raiz.izquierdo, valor);
        else                        // El valor es mayor o igual → va al subárbol derecho
            raiz.derecho = insertar(raiz.derecho, valor);

        return raiz;  // Retorna el nodo actual con el subárbol ya actualizado
    }

    public static void main(String[] args) {
        
        Nodo raiz = new Nodo(10);

        raiz = insertar(raiz, 5);   // 5  < 10 → izquierda de 10
        raiz = insertar(raiz, 15);  // 15 > 10 → derecha de 10
        raiz = insertar(raiz, 3);   // 3  < 10 → izq de 10 → 3 < 5 → izq de 5

        System.out.println("--- Prueba Ejercicio 2 ---");
        System.out.println("Raiz (Esperado 10): " + raiz.valor);

        String izq = (raiz.izquierdo != null)
                ? String.valueOf(raiz.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo de Raiz (Esperado 5): " + izq);

        String der = (raiz.derecho != null)
                ? String.valueOf(raiz.derecho.valor) : "null";
        System.out.println("Hijo Derecho de Raiz (Esperado 15): " + der);

        String izqIzq = (raiz.izquierdo != null && raiz.izquierdo.izquierdo != null)
                ? String.valueOf(raiz.izquierdo.izquierdo.valor) : "null";
        System.out.println("Hijo Izquierdo del 5 (Esperado 3): " + izqIzq);
    }
}
