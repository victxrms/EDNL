
#include <stdio.h>
#include <algorithm>
#include <complex>
#include "abin.hpp"

//Ejercicio 1:
//numero de nodos de un arbol binario

template <typename T>
int contar (const Abin <T> &a)
{
    return contar_rec(a.raiz(), a);
}

template <typename T>
int contar_rec(typename Abin<T>::nodo n, const Abin<T> &a)
{
    static cont = 0;
    if (n == Abin<t>::NODO_NULO)
        return cont;
    else cont += contar_rec(a.hijoIzqdo(n), a) + contar_rec(a.hijoDrcho(n), a);
}

//Ejercicio 2
//Contar altura

template <typename T>
int altura (const Abin <T> &a)
{
    return altura_rec(a.raiz, a);
}

template <typename T>
int altura_rec (typename Abin<T>::nodo n, Abin<T> &a)
{
    static cont = 0;
    if (n == NODO_NULO)
    return - 1;
    else return 1 + max (altura_rec(a.hijoIzqdo, a), altura_rec(a.hijoDcho, a));
}

//Ejercicio 3
//Calcula profundidad

template <typename T>
int profundidad (Abin<T> &a, typename Abin<T>::nodo n)
{
    if (n == a.NODO_NULO)
        return -1;
    else return 1+return(a, n.padre());
}

//Ejercicio 4 y 5 son con arboles vectoriales que no se usan para nada

//Ejercicio 6
//Calculo desequilibrio

template <typename T>
int desequilibrio(Abin<T> &a)
{
    if (a.arbolVacio)
        return -1;
    else return abs (altura(a.hijoIzqdo) - altura(a.hijoDrcho))
}

//Ejercicio 7
//Arbol Pseudocompleto

template <typename T>
bool pseudocompleto (Abin<T> &a)
{
    return pseudo_rec(a.raiz(), a)
}

template <typename T>
bool pseudo_rec (typename Abin<T>::nodo n, Abin<T> &a)
{
    if (n == a.NODO_NULO)
     return true
    else if (profundidad(n) == altura(n)-1)
            if ((a.hijoIzqdo != a.NODO_NULO && a.hijoDrcho != a.NODO_NULO) && ((a.hijoIzqdo == a.NODO_NULO && a.hijoDrcho == a.NODO_NULO)))
                return true;
            else return false;
        else return and (pseudo_rec(n.hijoDrcho, a), pseudo_rec(n.hijoIzqdo, a));
}