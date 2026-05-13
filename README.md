public class Ejercicio3_Binario2 {

    // ============================================
    // CLASE NODO
    // ============================================
    static class Nodo {

        int valor;
        Nodo izquierdo;
        Nodo derecho;

        Nodo(int v) {
            valor = v;
            izquierdo = null;
            derecho = null;
        }
    }

    // ============================================
    // CALCULAR ALTURA DEL ARBOL
    // ============================================
    public static int calcularAltura(Nodo raiz) {

        // Caso base: árbol vacío
        if (raiz == null) {
            return 0;
        }

        // Altura del subárbol izquierdo
        int alturaIzquierda = calcularAltura(raiz.izquierdo);

        // Altura del subárbol derecho
        int alturaDerecha = calcularAltura(raiz.derecho);

        // Retorna la mayor altura + 1
        return Math.max(alturaIzquierda, alturaDerecha) + 1;
    }

    // ============================================
    // MAIN
    // ============================================
    public static void main(String[] args) {

        //        1
        //         \
        //          2
        //         /
        //        3

        Nodo raiz = new Nodo(1);

        raiz.derecho = new Nodo(2);

        raiz.derecho.izquierdo = new Nodo(3);

        System.out.println("--- Prueba Ejercicio 3 ---");

        System.out.println("Altura esperada: 3");

        System.out.println(
            "Altura calculada: "
            + calcularAltura(raiz)
        );

        System.out.println(
            "Altura de árbol nulo (esperado 0): "
            + calcularAltura(null)
        );
    }
}
--INFORME--

INFORME DE GUÍA PRÁCTICA

I.	PORTADA
Tema: 					Árboles
Unidad de Organización Curricular:	BÁSICA
Nivel y Paralelo:			3”B”
Alumnos participantes:			Acosta Gavilanes Emmanuel Alejandro
					
Asignatura:				Estructura de datos
Docente:				Ing. José Caiza, Ph.D.

II.	INFORME DE GUÍA PRÁCTICA
1.	PP
2.	YY
2.1	Objetivos

General:
Desarrollar habilidades en el trabajo con árboles
Específicos:
•	Implementar el recorrido In-Order en un árbol binario de búsqueda mediante recursión, verificando que los valores se obtienen en orden ascendente.
•	Desarrollar la función de inserción en un BST respetando la propiedad de orden (menores a la izquierda, mayores a la derecha).
•	Calcular la altura de un árbol binario identificando el camino más largo desde la raíz hasta una hoja utilizando std::max.
•	Invertir (reflejar en espejo) un árbol binario intercambiando recursivamente los hijos izquierdo y derecho de cada nodo.
•	Contar el número total de nodos en un árbol N-ario recorriendo cada lista de hijos con un bucle iterativo combinado con recursión.
2.2	Modalidad
Presencial

2.3	Tiempo de duración
Presenciales: 8
No presenciales: 0

2.4	Instrucciones
1. Lleve a cabo las actividades indicadas. 
2. Suba a plataforma un informe con el resultado obtenido.

2.5	Listado de equipos, materiales y recursos 

Inteligencia artificial, TAC PC de escritorio o portátil con JDK instalado e IDE de su elección

TAC (Tecnologías para el Aprendizaje y Conocimiento) empleados en la guía práctica:
☐Plataformas educativas
☐Simuladores y laboratorios virtuales
☒Aplicaciones educativas
☒Recursos audiovisuales
☐Gamificación
☒Inteligencia Artificial
Otros (Especifique): _____________________

2.6	Actividades por desarrollar
Desarrollar lo indicado en archivo adjunto. Luego, elaborar un informe del trabajo llevado a cabo donde resalte los aspectos fundamentales tenidos en cuenta en su propuesta de solución.

2.7	 Resultados obtenidos
-	Ejercicio 1 
Contar nodos en árbol N-ario: Se implementó la función contarNodos de forma recursiva en C++ y Java. El algoritmo cuenta el nodo raíz (total = 1) y acumula la cantidad de nodos de cada subárbol hijo mediante un bucle. Para el árbol de prueba con raíz 1, hijos 2, 3, 4 y nietos 5, 6, se obtuvo correctamente el valor esperado de 6 nodos.














































Funcionamiento:





-	Ejercicio 2
Inserción en BST: Se implementó la función insertar en C++ y Java. La lógica compara el valor con el nodo actual y dirige la inserción hacia el subárbol izquierdo (valor menor) o derecho (valor mayor o igual), creando un nuevo nodo al llegar a un puntero nulo. Las pruebas con los valores 5, 15 y 3 sobre la raíz 10 produjeron la estructura BST esperada.

























Funcionamiento:







-	Ejercicio 3 
Altura del árbol: Se implementó calcularAltura usando std::max en C++. La función retorna 0 para nodos nulos y 1 + max(alturaIzq, alturaDer) en cada nivel. Para el árbol de prueba (1 → 2 → 3 en cadena) se obtuvo la altura correcta de 3.











































Funcionamiento:






-	Ejercicio 4 
Recorrido In-Order: Se implementó inOrderAux siguiendo el orden izquierdo – raíz – derecho. Para el BST de prueba con valores del 1 al 7, el recorrido produjo la secuencia ordenada 1 2 3 4 5 6 7, confirmando la propiedad fundamental del recorrido In-Order sobre un BST.












































Funcionamiento:








-	Ejercicio 5 (C++)
Inversión del árbol: Se implementó la función invertir en C++ utilizando std::swap para intercambiar los punteros izquierdo y derecho de cada nodo, seguido de llamadas recursivas en ambos subárboles. La prueba confirmó que el hijo izquierdo 2 pasó a ser el hijo derecho y el hijo derecho 3 quedó como hijo izquierdo, cumpliendo el efecto espejo esperado.







































Funcionamiento (C++):





-	Ejercicio 5 (Java)






























EJERCICIO DEL README:
















































1.1	Habilidades blandas empleadas en la práctica

☐ Liderazgo
☒ Trabajo en equipo
☐ Comunicación asertiva
☐ La empatía
☒ Pensamiento crítico
☐ Flexibilidad
☐ La resolución de conflictos
☐ Adaptabilidad
☒ Responsabilidad

1.2	Conclusiones
-	La recursión es la estrategia natural para operar sobre árboles, dado que su estructura jerárquica se presta directamente al enfoque de resolver el problema en la raíz y delegar el resto a los subárboles. Todos los ejercicios implementados (recorrido, inserción, altura, inversión y conteo) se resolvieron eficientemente con esta técnica.
-	El recorrido In-Order sobre un Árbol Binario de Búsqueda garantiza obtener los elementos en orden ascendente sin necesidad de ordenarlos explícitamente, lo que demuestra cómo la estructura del árbol codifica información de orden de forma implícita.
-	La propiedad BST (menores a la izquierda, mayores a la derecha) debe preservarse en cada inserción. Se comprobó que la función debe retornar el puntero del nodo modificado y reasignarlo en el llamador; de lo contrario, los nuevos nodos se perderían en memoria.
-	C++ y Java comparten la misma lógica algorítmica para árboles, pero difieren en la gestión de memoria: C++ requiere liberar explícitamente cada nodo con delete, mientras que Java delega esa responsabilidad al recolector de basura, reduciendo el riesgo de fugas de memoria.
1.3	Recomendaciones
-	Dibujar el árbol en papel antes de codificar. Tener la representación visual del árbol (nodos, niveles, hijos) facilita identificar los casos base y los patrones recursivos antes de escribir la primera línea de código, reduciendo errores lógicos.
-	Trazar la recursión manualmente con un árbol pequeño. Seguir paso a paso la pila de llamadas con 3 o 4 nodos permite verificar que el caso base se alcanza correctamente y que los valores de retorno se acumulan de la manera esperada.
-	Reasignar siempre el puntero retornado. En C++ y Java, al llamar a insertar() o invertir(), se debe capturar el valor de retorno (raiz = insertar(raiz, valor)) para que los cambios sobre la raíz queden reflejados en el contexto llamador.
-	Liberar la memoria en C++ al finalizar. Implementar una función liberarArbol() que recorra el árbol en postorden (primero hijos, luego raíz) y llame a delete en cada nodo, evitando fugas de memoria en programas de mayor escala.
-	Ampliar las pruebas con árboles degenerados. Probar con árboles en los que todos los nodos se insertan en orden creciente (equivalente a una lista enlazada) permite detectar problemas de rendimiento y motiva el estudio de árboles balanceados como AVL o Rojo-Negro.
1.4	Referencias bibliográficas

[1] V. Fritelli, A. Guzmán, y J. Tymoschuk, Algoritmos y estructuras de datos, 2.ª ed. Córdoba, Argentina: Jorge Sarmiento Editor – Universitas, 2020, 497 pp. [En línea]. Disponible en: enlace activo al URL institucional.
[2] S. Guardati, Estructuras de datos básicas: programación orientada a objetos con Java, 1.ª ed. Ciudad de México, México: Alfaomega, 2016, 398 pp. [Código: BFISEI1698a / BFISEI2046a].
[3] P. A. Sznajdleder, Programación orientada a objetos y estructura de datos a fondo, 1.ª ed. Buenos Aires, Argentina: Alfaomega, 315 pp. [Código: BFISEI2999a].
[4] A. Pérez Castaño, Aprender, 1.ª ed. Barcelona, España: Marcombo, 2018, 213 pp.

1.5	Anexos

-	Link del repositorio del GITHUB con los códigos y el README:

https://github.com/emmanuelacosta5135/ape3Arboles.git
