/** @file */
//
// Created by rfok7 on 24.10.2020.
//

#ifndef PROJEKT_ZBIOR_H
#define PROJEKT_ZBIOR_H

#include <iostream>
using namespace std;

template <class T>
class Zbior: public Lista<T>
{
public:

    Zbior() = default;
    Zbior<T>(const Zbior<T> &_zbior);
    ~Zbior() = default;


    /**
     *
     * @param value - value - wartosc do usunieca ze zbioru
     * \brief Metoda wywoluje metode Lista::usunZListy, odziedziczona z klasy Lista
     */
    void usun(const T &value);

    /**
     * \brief Metoda wywoluje metode Lista::oproznijListe, odziedziczona z klasy Lista
     */
    void oproznij();

    /**
     *
     * @param os - strumien wyjsciowy
     * \brief Metoda wywoluje metode Lista::wyswietlListe, odziedziczona z klasy Lista
     */
    void wyswietl(ostream &os);

    /**
     *
     * @param value - wartosc, ktora nalezy wpisac do zbioru
     * \brief Metoda wywoluje metode Lista::dodajDoListy, odziedziczona z klasy Lista
     */
    void dodaj(const T &value);

    /**
     * \brief Metoda wywoluje metode Lista::ileElementowLista, odziedziczona z klasy Lista
     * @return Zwraca ilosc elementow w zbiorze
     */
    int ileElementow();

    /**
     * \brief Metoda wywoluje metode Lista::czyNalezyDoListy, odziedziczona z klasy Lista
     * @param value - wartosc, ktora jest przekazywana do sprawdzenia czy nalezy do zbioru
     * @return Zwraca true jezeli wartosc nalezy do zbioru, false w przeciwnym wypadku
     */
    bool czyNalezy(const T &value);

    /**
     * \brief Przeciazony operator sumy
     * @param _zbior - adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego sumy zbiorow
     */
    Zbior<T> operator+ (Zbior<T> &_zbior);

    /**
     * \brief Przeciazony operator roznicy
     * @param _zbior adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego roznicy zbiorow
     */
    Zbior<T> operator- (Zbior<T> &_zbior);

    /**
     *
     * @param _zbior adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego iloczynu zbiorow
     */
    Zbior<T> operator* (Zbior<T> &_zbior);

    /**
     * \brief Metoda zaimplementowana inline, wykorzystuje operator+ do ktorego przekazuje wybrany zbior
     * @param _zbior adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego sumy zbiorow
     */
    inline Zbior operator+= (Zbior<T> &_zbior);

    /**
     * \brief Metoda zaimplementowana inline, wykorzystuje operator- do ktorego przekazuje wybrany zbior
     * @param _zbior adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego roznicy zbiorow
     */
    inline Zbior operator-= (Zbior<T> &_zbior);

    /**
     * \brief Metoda zaimplementowana inline, wykorzystuje operator* do ktorego przekazuje wybrany zbior
     * @param _zbior adres drugiego zbioru
     * @return Zwraca nowy zbior bedacy wynikiem dzialania arytmetycznego iloczynu zbiorow
     */
    inline Zbior operator*= (Zbior<T> &_zbior);
};


template <class T>
ostream &operator<<(ostream &osOutput, Zbior<T> &zbior) ; // done
template <class T>
istream &operator>>(istream &isInput, Zbior<T> &zbior); //done

template<class T>
Zbior<T>::Zbior(const Zbior<T> &_zbior): Zbior() {}

template<class T>
void Zbior<T>::wyswietl(ostream &os){
    Lista<T>::wyswietlListe(os);
}

template<class T>
void Zbior<T>::dodaj(const T &value){
    Lista<T>::dodajDoListy(value);
}

template<class T>
void Zbior<T>::usun(const T &value){
    Lista<T>::usunZListy(value);
}

template<class T>
void Zbior<T>::oproznij(){
    Lista<T>::oproznijListe();
}

template<class T>
int Zbior<T>::ileElementow(){
    return Lista<T>::ileElementowLista();
}

template<class T>
bool Zbior<T>::czyNalezy(const T &value) {
    return Lista<T>::czyNalezyDoListy(value);
}

template<typename T>
Zbior<T> Zbior<T>::operator+(Zbior<T> &_zbior){
    Zbior<T> nowyZbior = Zbior<T>(); //utworz nowy zbior

    auto tempHead = this->pHead;
    int liczbaElemetnow = this->ileElementow(); //pobierz liczbe elementow w zbiorze wskazywanym przez this
    for (int i=0; i< liczbaElemetnow; i++)
    {
        nowyZbior.dodaj(this->pHead->value);
        this->pHead = this->pHead->pNext;
    }
    this->pHead = tempHead;

    tempHead = _zbior.pHead;
    liczbaElemetnow = _zbior.ileElementow(); //pobierz liczbe elementow w zbiorze przekazanym do funkcji
    for (int i = 0; i< liczbaElemetnow; i++) //nie trzeba sprawdzac czy wartosci sie powtarzaja, poniewaz w funckji Lita::dodajDoListy jest to sprawdzenie zaimplementowane
    {
        nowyZbior.dodaj(_zbior.pHead->value);
        _zbior.pHead = _zbior.pHead->pNext;
    }
    _zbior.pHead = tempHead;

    return nowyZbior;
}



template<typename T>
Zbior<T> Zbior<T>::operator-(Zbior<T> &_zbior){
    Zbior<T> nowyZbior = Zbior<T>();

    auto tempHeadA = this->pHead;
    auto tempHeadB = _zbior.pHead;
    int liczbaElementowA = this->ileElementow();
    int liczbaElementowB = _zbior.ileElementow();
    bool consists;

    for(int i = 0; i < liczbaElementowA; i++)
    {
        for (int j = 0; j < liczbaElementowB; j++)
        {
            if(this->pHead->value == _zbior.pHead->value )
            {
                consists = true;
                _zbior.pHead = tempHeadB;
                break;
            }
            consists = false;
            _zbior.pHead = _zbior.pHead->pNext;
        }
        if(!consists){nowyZbior.dodaj(this->pHead->value);} //jezeli ten element jest w zbiorze A, ale nie ma go w B, dodaj go do nowego zbioru
        this->pHead = this->pHead->pNext;
        _zbior.pHead = tempHeadB;
    }
    this->pHead = tempHeadA;
    _zbior.pHead = tempHeadB;
    return nowyZbior;
}


template<typename T>
Zbior<T> Zbior<T>::operator*(Zbior<T> &_zbior){

    Zbior<T> nowyZbior = Zbior<T>();
    auto tempHeadA = this->pHead;
    auto tempHeadB = _zbior.pHead;
    int liczbaElementowA = this->ileElementow();
    int liczbaElementowB = _zbior.ileElementow();

    for(int i = 0; i < liczbaElementowA; i++)
    {
        for (int j = 0; j < liczbaElementowB; ++j)
        {
            if(this->pHead->value == _zbior.pHead->value) // jezeli ten element jest w zbiorze A i B, dodaj go do nowego zbioru
            {
                nowyZbior.dodaj(this->pHead->value);
            }
            _zbior.pHead = _zbior.pHead->pNext;
        }
        this->pHead = this->pHead->pNext;
        _zbior.pHead = tempHeadB;
    }
    this->pHead = tempHeadA;
    _zbior.pHead = tempHeadB;
    return nowyZbior;
}

template<typename T>
Zbior<T> Zbior<T>::operator+=(Zbior<T> &_zbior){
    return _zbior.operator+(_zbior);
}

template<typename T>
Zbior<T> Zbior<T>::operator-=(Zbior<T> &_zbior){
    return _zbior.operator-(_zbior);
}

template<typename T>
Zbior<T> Zbior<T>::operator*=(Zbior<T> &_zbior){
    return _zbior.operator+(_zbior);
}



template<class T>
ostream &operator<<(ostream &osOutput, Zbior<T> &zbior) {
    zbior.wyswietl(osOutput);
    return osOutput;
}

template<class T>
istream &operator>>(istream &isInput, Zbior<T> &zbior) {
    T tempValue;
    while (isInput>>tempValue)
    {
        zbior.dodaj(tempValue);
    }
    return isInput;
}


#endif //PROJEKT_ZBIOR_H
