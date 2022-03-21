
#include <stdio.h>
#include <algorithm>
#include <complex>
#include "abin.hpp"

//Ejercio 1
//Árboles similares

template <typename T>
bool similar (const Abin <T> &a, const Abin <T> &b)
{
    if (a.arbolVacio() && b.arbolVacio())
        return true
    else
        return similar_rec(a.raiz, b.raiz, a, b);
}

template <typename T>
bool similar_rec (typename Abin<T>::nodo a_, typename Abin<T>::nodo b_, const Abin <T> &a, const Abin <T> &b)
{
    if (a_ == a.NODO_NULO && b_ == b.NODO_NULO)
        return true;
    else if ((a_ == a.NODO_NULO && b_ != b.NODO_NULO) || (a_ != NODO_NULO && b_ == NODO_NULO))
        return false
        else return (similar_rec(a.hijoDrcho(a_), b.hijoDrcho(b_), a, b) && similar_rec(a.hijoIzqdo(a_), b.hijoIzqdo(b_), a, b));
}

//Ejercicio 2
//Árbol reflejado

template <typename T>
Abin<T> espejo (const Abin<T> &a)
{
    typename Abin<T> aR;

    if (!a.arbolVacio())
    {
        aR.insertarRaiz (a.elto(a.raiz()));
        espejo_rec (aR, aR.raiz, a.raiz, a);
    }

    return aR;
       
}

template <typename T>
Abin<T> espejo_rec (Abin<T> aR, typename Abin<T>::nodo a_, typename Abin<T>::nodo aR_, Abin<T> a)
{
    if (a.hijoIzqdo(a_) != a.NODO_NULO)
    {
        aR.insertarHijoDrcho(aR_, a.elemento(a, a.hijoIzqdo(a_)));
        espejo_rec(aR, aR.hijoDrcho(aR_), a.hijoIzqdo(a_), a);
    }

    if (a.hijoDrcho(a_) != a.NODO_NULO)
    {
        aR.insertarHijoIzqdo(aR_, a.elemento(a, a.hijoDrcho(a_)));
        espejo_rec(aR, aR.hijoIzqdo(aR_), a.hijoDrcho(a_), a);
    }

}

//Ejericio 3
//Calculadora - Sería posible usar tanto un strcut como un enum para este caso en concreto

typedef struct elm{char op; float num;};

template <typename elm>
float calculadora (const Abin <elm> &a)
{
    return calculadora_rec(a.raiz, a);
}

template <typename elm>
float calculadora_rec(typename Abin <elm>::nodo a_, Abin <elm> &a)
{

    if (a.hijoDrcho(a_) == a.NODO_NULO && a.hijoIzqdo(a_) == a.NODO_NULO)
        return a.elemento(n).num;
    else 
        switch (a.elto(a_).op)
            case '+':
                return calculadora_rec(a.hijoDrcho(a), a) + calculora_rec(a.hijoIzqdo(a), a);
                break;
            case '-':
                return calculadora_rec(a.hijoDrcho(a), a) - calculora_rec(a.hijoIzqdo(a), a);
                break;
            case '*':
                return calculadora_rec(a.hijoDrcho(a), a) * calculora_rec(a.hijoIzqdo(a), a);
                break;
            case '/':
                return calculadora_rec(a.hijoDrcho(a), a) / calculora_rec(a.hijoIzqdo(a), a);
                break;
}

//Ejercicios - Nodos verdes
//Diferentes variantes

//Contar nodos de X tipo, ejemplo nodos con 3 nietos

template <typename T>
int contarHijos(typename Abin<T>::nodo n, const Abin<T> &a)
{   
    int cont = 0;
    if ((a.hijoIzqdo(n) != a.NODO_NULO)) hijos++;
    if ((a.hijoDrcho(n) != a.NODO_NULO)) hijos++;
	return hijos;
}

template <typename T>
int tresNietos(const Abin<T> &a)
{
    return tresNietos_rec (a.raiz, a);
}

template <typename T>
int tresNietos_rec(typename Abin<T>::nodo n, const Abin<T> &a)
{
    int contador = 0;
    if (n.hijoIzqdo != a.NODO_NULO || n.hijoDrcho != a.NODO_NULO)
        if ((contarHijos(a.hijoIzqdo(n), a) + contarHijos(a.hijoDrcho(n), a)) == 3)
        	contador++: 
    else return contador;
}


//Borrar nodos a partir de condición específica 
//Nodo con elemento X -> Ej: a.elemento() == 3

template <typename T>
void elementoPoda(Abin<T> &a)
{
	elementoPoda_rec(a.raiz, a);
}

template <typename T>
void elementoPoda_rec(typename Abin<T>::nodo n , Abin <T> &a)
{
	if (n != a.NODO_NULO)
		if (a.elemento(n) == 3)
		cortar(n, a);
		else {elementoPoda_rec(a.hijoIzqdo(n), a); elementoPoda_rec(a.hijoDrcho(n), a)};
}

template <typename T>
void cortar(typename Abin<T>::nodo n , Abin <T> &a)
{
	if (a.hijoIzqdo(n) == a.NODO_NULO)
		a.eliminarHijoIzqdo(n);
	else cortar{(a.hijoIzqdo(n), a); (a.hijoDrcho(n), a);}

	if (a.hijoDrcho(n) == a.NODO_NULO)
		a.eliminarHijoDrcho(n);
	else cortar{(a.hijoIzqdo(n), a); (a.hijoDrcho(n), a);}
}


//Buscar nodos con X condición
//Nodos nostalgicos -> Aquellos nodos con mas antecesores que predecesores

template <typename T>
int nodosNostalgicos(Abin <T> &a)
{
    return nodosNostalgicos_rec(a.raiz, a);
}

template <typename T>
int nodosNostalgicos_rec(typename Abin<T>::nodo n, Abin <T> a)
{

    if (n == a.NODO_NULO)
        return 0;
    if (contarPredecesor(n, a) > contarSucesor(n, a))
        return 1 + nodosNostalgicos_rec(a.hijoDrcho(n), a) + nodosNostalgicos_rec(a.hijoIzqdo(n), a);
}

template <typename T>
int contarPredecesor(typename Abin<T>::nodo n, Abin <T> a)
{
    static cont = 0;
    if (n == a.NODO_NULO)
        return cont;
    else
        return (1 + contarPredecesor(a.padre(n), a));
}

template <typename T>
int contarSucesor(typename Abin<T>::nodo n, Abin <T> a)
{
    static cont = 0;
    if (n == a.NODO_NULO)
        return cont;
    else
        return (1 + contarSucesor(a.hijoDrcho(n), a) + contarSucesor(a.hijoIzqdo(n), a));
}
