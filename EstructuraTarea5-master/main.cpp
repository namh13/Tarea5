#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <set>          // std::list
using namespace std;

int infinito = 9999;

//Dado: un grafo con 5 nodos implementado en una tabla (arreglo bidimensional)
//Dado: las columnas de la tabla representan el inicio y las filas el destino
//Dado: las aristas tienen un valor de 0 si apuntan a ellas, infinito si no esta conectada y de lo contrario significa que sí hay una conexion entre los nodos

//Devuelve verdadero si existe al menos un camino para llegar desde el nodo inicio hasta el nodo destino
bool existeCamino(int grafo[5][5], int inicio, int destino)
{
    if(grafo[destino][inicio] == infinito && grafo[destino][inicio] != 0) // comprobamos en el grafo si el destino y el inicio es igual a inifinito y diferente de cero, lo que quiere decir que no hay ningun camino hasta el nodo destino
    {
        return true; //entonces mandamos verdadero
    }
    return false; // de lo contrario mandamos falso
}

//Ej. si la profundidad es igual a 0 solo se devuelve el nodo inicial
//Ej. si la profundidad es igual a 1 se devuelve el nodo inicial y sus adjacentes
//Ej. si la profundidad es igual a 2 se devuelve el nodo inicial, sus adjacentes y los adjacentes de los adjacentes
set<int> obtenerAdjacentes(int grafo[5][5], int inicio, int profundidad)
{
    set<int> respuesta;
    int con1 = 0; //variable contador 1
    int con2 = 0; //variable contador 2

//0
    while(profundidad == 0) //si la profundidad es igual a 0 dentra en el ciclo
    {
        respuesta.insert(inicio); // insertamos en el set de respuesta el inicio
        return respuesta; //retornamos el nodo inicial
    }

//1
    while(profundidad == 1 && con1 < 5) //mientras la profundidad sea igual a 1 y el contador menor que 5 entramos en el ciclo
    {
        while(con1 < 5) // hacemos devuelta la comprobacion que con1 sea menor que 5 porque no servira como columna en el grafo
        {
            if(!(grafo[inicio][con1] == infinito && grafo[inicio][con1] != 0)) // siempre y cuando la posicion enviada al grafo sea diferente o sea todo lo opuesto
            {
                respuesta.insert(con1); //entonces insertamos en el set el adyacente o sea con1
            }
            con1++; // con1 aumenta en uno en uno
        }
        return respuesta; // retornamos el set de respuesta
    }

//2
    while(profundidad == 2 && con2 < 5) //mientras la profundidad sea igual a 2 y el contador menor que 5 entramos en el ciclo
    {
        while(con2 < 5) // hacemos devuelta la comprobacion que con2 sea menor que 5 porque no servira como columna en el grafo
        {
            if(!(grafo[inicio][con2] == infinito && grafo[inicio][con2] != 0)) // siempre y cuando la posicion enviada al grafo sea diferente o sea todo lo opuesto
            {
                respuesta.insert(con2); //entonces insertamos en el set el adyacente osea con2

                int cambio = 0; //creamos un variable que nos servira para poder ingresar los adyacentes de los adyacentes por decir los sub-adyacentes y tambien para recorrer el ciclo
                while(cambio < 5) //mientras cambio sea menor que 5 entramos en el ciclo, donde cambio nos servira como columna para ingresar los sub-adyacentes
                {
                    if(!(grafo[con2][cambio] == infinito && grafo[con2][cambio] != 0)) //siempre y cuando la posicion enviada sea diferente lo opuesto
                    {
                        respuesta.insert(cambio); // insertamos en el set los sub-adyacentes
                    }
                    cambio++; //cambio va aumentando en uno en uno
                }
            }
            con2++; //con2 va aumentando en uno en uno
        }

        return respuesta; //retornamos el set respuesta
    }

}

int main ()
{
    evaluar();

    return 1;
}
