#include "Node.h"
#include "Iterator.h"
#include "LinkedList.h"

#include <iostream>
using namespace std;

// METODOS CLASS NODE ===================================================
template<typename T>
Node<T>::Node(T elem) {
    this->elem = elem;
}
template<typename T>
Node<T>::Node(Node<T> &o) {   // ctor. copia
    elem = o.elem; next = o.next;
}
template<typename T>
T Node<T>::getElem() {
    return elem;
}
template<typename T>
Node<T>* Node<T>::getNext() {
    return next;
}
template<class T>
void Node<T>::setElem(T elem) {
    this->elem = elem;
}
template<typename T>
void Node<T>::setNext(Node<T>* next) {
    this->next = next;
}

// METODOS CLASS LINKED LIST ===================================================
template<typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = nullptr;
}
template<typename T>
LinkedList<T>::LinkedList(LinkedList &o) { // ctor. copia
    size = o.size; head = o.head;
}
template<typename T>
LinkedList<T>::~LinkedList() {
    if (head != nullptr)
    {
        Node<T>* tmp = head;
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
            delete head;
            head = tmp;
        }
        delete head;
    }
}
template<class T>
void LinkedList<T>::insert(T nuevoValor) {
    Node<T>* test = head;
    Node<T>* nuevoNodo = new Node<T>(nuevoValor);

    if (test == nullptr)   // insertarndo en array vacio
        head = nuevoNodo;
    else if (nuevoValor < test->getElem()) { // existe array pero debe insertar en pos 0
        nuevoNodo->setNext(head);
        head = nuevoNodo;
    }
    else {    // existe array y no sabe donde insertar
        while (test->getNext() != nullptr && test->getNext()->getElem() < nuevoValor)
            test = test->getNext();
        if (test->getNext() != nullptr)
            nuevoNodo->setNext(test->getNext());
        test->setNext(nuevoNodo);
    }
    size++;
}
template<class T>
void LinkedList<T>::remove(T elem) {
    Node<T>* test = head;
    if (test == nullptr)  // comprueba que no esta vacio
        cout << "esta vacio" << endl;
    else if (test->getElem() == elem) {  // testea primer elemento
        head = test->getNext();
        delete test;
        size--;
    }
    else {
        Node<T>* tmp;
        while(test->getNext() != nullptr) {   // se desplaza buscando elem, si llega a null quiere decir q no se encontró
            tmp = test;
            test = test->getNext();
            if (test->getElem() == elem) {
                tmp->setNext(test->getNext());
                delete test;
                size--;
                return;
            }
        }
        cout << "no se encontro" << endl;
    }
}
template<typename T>
void LinkedList<T>::print() {
    Node<T>* test = head;
    if (test == nullptr) { return; } // comprueba lista vacia
    do {
        cout << test->getElem() << " ";
        test = test->getNext();
    } while (test != nullptr);
    cout << endl;
}
template<typename T>
void LinkedList<T>::printIterator() {
    for (Iterator<T> i = this->begin(); !(i == this->end()); i.nextPosicion())
        cout << i.getValue() << " ";
    cout << endl;
}

// METODOS CLASS ITERATOR ===================================================
template<typename T>
Iterator<T>::Iterator() {
    posicion = nullptr;
}
template<typename T>
bool Iterator<T>::operator==(const Iterator& i) {
    return posicion == i.posicion;
}
template<typename T>
void Iterator<T>::nextPosicion() {
    if (posicion == nullptr)
        return;
    posicion = posicion->getNext();
}
template<class T>
T Iterator<T>::getValue() {
    if (posicion == nullptr) {
        cout << "sin valor puntero NULL" << endl;
        return -1;
    }
    return posicion->getElem();
}
template<typename T>
Iterator<T> LinkedList<T>::begin() {
    Iterator<T> i;
    i.posicion = head;
    return i;
}
template<typename T>
Iterator<T> LinkedList<T>::end() {
    Iterator<T> i;
    i.posicion = nullptr;
    return i;
}

int main()
{
    LinkedList<float> lista;

    lista.insert(27);
    lista.insert(3.2);
    lista.insert(17.2);
    lista.insert(0);
    lista.print();

    LinkedList<float> listaCopia = lista;
    listaCopia.print();
    listaCopia.remove(0);

    cout << "print normal   : ";
    listaCopia.print();
    cout << "print iterador : ";
    listaCopia.printIterator();

    return 0;
}
