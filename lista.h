/** @file */
//
// Created by rfok7 on 27.10.2020.
//

#ifndef PROJEKT_LISTA_H
#define PROJEKT_LISTA_H
#include <iostream>
using namespace std;

template<class T>
class Lista{
    struct element{

        element* pNext;
        T value;
        element(const T& _value):value(_value),pNext(nullptr){}
    };
protected:
    ///Wskaznik typu element na glowe listy
    element *pHead;

    /**
     *
     * @param value - wartosc do usunieca ze zbioru
     * \brief Metoda przekazuje zadana wartosc do usuniecia, nastepnie w metodzie sprawdzane jest czy element do usuniecia znajduje sie na poczatku listy czy nie. Wykonywana jest operacja delete, a na koncu przywracane sa adresy poczatkowe glowy listy.
     */
    void usunZListy(const T &value);

    /**
     * \brief Metoda usuwa cala liste jednokierunkowa oraz zwalnia zaalokowana wczesniej pamiec.
     */
    void oproznijListe();

    /**
 *
 * @param ostream &os - strumien wyjsciowy
 * \brief Metoda wyswietla zbior, ktory jest przechowywany w liscie jednokierunkowej. Po zakonczeniu wyswietlania wskazniki ustawiane sa na adresy poczatkowe.
 */
    void wyswietlListe(ostream &os);

    /**
     * \brief Metoda dodaje wartosc do listy jednokierunkowej
     * @param value - wartosc, ktora nalezy wpisac do zbioru
     */
    void dodajDoListy(const T &value);

    /**
     * \brief Metoda ma za zadanie przejrzenie calej listy jendokierunkowej w celu zliczenia ilosci elementow w zbiorze.
     * @return Zwraca ilosc elementow w zbiorze
     */
    int ileElementowLista();

    /**
     *
     * @param value - wartosc, ktora jest przekazywana do sprawdzenia czy nalezy do zbioru
     * @return Zwraca true jezeli wartosc nalezy do zbioru, false w przeciwnym wypadku
     */
    bool czyNalezyDoListy(const T &value);

public:
    /**
     * \brief Konstruktor z domyslna inicjalizacja pHead(nullptr)
     */
    Lista() : pHead(nullptr){};

    /**
     *
     * \brief Konstruktor kopiujacy dla klasy Lista
     */
    Lista(const Lista<T> &_lista);

    ~Lista();
};

template<class T>
Lista<T>::Lista(const Lista<T> &_lista):pHead(nullptr)
{
    if (_lista.pHead)
    {
        pHead = new element; //utworzenie nowego elementu
        (*pHead) = *_lista.pHead; //skopiowanie elementu
    }
}

template<class T>
Lista<T>::~Lista() {
    Lista::oproznijListe(); //wywolanie metody w celu usuniecia calej listy
} //done

template<class T>
void Lista<T>::usunZListy(const T &value) {
    auto tempHead = this->pHead; //kopia adresu poczatkowego
    Lista::element *prev;

    while (this->pHead)
    {
        if (this->pHead->value == value)
        {
            if (this->pHead == tempHead) // sprawdzenie czy jest to pierwszy element
            {
                prev = this->pHead->pNext;
                delete this->pHead;
                this->pHead = prev;
                break;
            }
            else
            {
                prev->pNext = this->pHead->pNext;
                delete this->pHead;
                this->pHead = tempHead;
                break;
            }
        }
        prev = this->pHead;
        this->pHead = this->pHead->pNext;
    }
    this->pHead = tempHead;  //przywrocenie adresu z kopii
} //done

template<class T>
void Lista<T>::oproznijListe(){
    while (this->pHead)
    {
        auto tempHead = this->pHead->pNext;
        delete this->pHead; //zwalnianie pamieci
        this->pHead = tempHead;
    }
} //done

template<class T>
void Lista<T>::wyswietlListe(ostream &os){
    auto tempHead = this->pHead; //kopia adresu poczatkowego
    while (this->pHead)
    {
        os<<this->pHead->value<<endl; //zapis aktualnej wartosci do strumienia wyjsciowego
        this->pHead = this->pHead->pNext;
    }
    this->pHead = tempHead; //przywrocenie adresu z kopii
} //done

template<class T>
void Lista<T>::dodajDoListy(const T &value){
    auto nowyElement = new element(value); //utworzenie nowego obiektu element
    bool czyZawiera; //flaga

    if(!this->pHead)
    {
        this->pHead = nowyElement;
    }
    else
    {
        auto tempHead = this->pHead;
        while (this->pHead)
        {
            if (this->pHead->value == value) //sprawdzenie czy istnieje juz taka wartosc
            {
                czyZawiera = true;
                this->pHead = tempHead;
                break;
            }
            else
            {
                czyZawiera = false;
                this->pHead = this->pHead->pNext;
            }
        }

        if (!czyZawiera) //jezeli nie ma takiego elementu w calej liscie to go dodaj
        {
            this->pHead = tempHead;
            this->pHead = nowyElement;
            nowyElement->pNext = tempHead;
        }
    }
} //done

template<class T>
int Lista<T>::ileElementowLista(){
    auto tempHead = this->pHead;
    int iloscElementow = 0;

    while(this->pHead)
    {
        iloscElementow++; //jezeli istnieje wartosc zwieksz licznik
        this->pHead = this->pHead->pNext;
    }
    this->pHead = tempHead; //przywrocenie adresu kopii
    return iloscElementow;
} //done

template<class T>
bool Lista<T>::czyNalezyDoListy(const T &value) {

    auto tempHead = this->pHead;

    while (this->pHead)
    {
        if (this->pHead->value == value) //jezeli istnieje taki element zwroc true
        {
            this->pHead = tempHead;
            return true;
        }
        else
            this->pHead = this->pHead->pNext;
    }
    this->pHead = tempHead;
    return false;
}


//done


#endif //PROJEKT_LISTA_H
