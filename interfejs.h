//
// Created by rfok7 on 03.11.2020.
//

#ifndef PROJEKT_INTERFEJS_H
#define PROJEKT_INTERFEJS_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

template<class T>
class Interfejs: public Zbior<T>
{
    int ileZbiorow;
    vector<Zbior<T>*>wsk_Zbior; //Kontener przechowujacy wskazniki typu Zbior

public:

    /**
     *
     * @param ileZbiorow - ilosc zbiorow do utworzenia
     * @param flaga - okresla typ zbioru, 1 - int, 2 - double, 3 - char
     */
    Interfejs(const int &ileZbiorow, const int &flaga);
    ~Interfejs() = default;

    /**
     * \brief Metoda wywoluje w petli Interfejs::wprowadzDane, dokladnie tyle razy ile tego wymaga uzytkownik
     * @param flaga - okresla typ zbioru, 1 - int, 2 - double, 3 - char
     */
    void stworzZbiory(const int &flaga);

    /**
     * \brief Metoda tworzy nowy obiekt typu Zbior, odczytuje znaki wprowadzane w terminalu i wpisuje je do listy. Na koncu wprowadza wskaznik nowo utworzonego zbioru do vectora.
     * @param flaga - okresla typ zbioru, 1 - int, 2 - double, 3 - char
     */
    void wprowadzDane(const int &flaga);

    /**
     * \brief Metoda wyswietla mozliwe operacjie na zbiorach, oczekuje na wprowadzenie przez uzytkownika cyfry odpowiadajacej operacji, oraz wywoluje metode Interfejs::wykonajDzialanie z odpowiednim parametrem.
     */
    void wyswietlOpcje();

    /**
     *
     * @param flaga - okresla typ zbioru, 1 - int, 2 - double, 3 - char
     * \brief Metoda oczekuje na wprowadzenie przez uzytkownika cyfr / cyfry odpowiadajacej wybranemu zbiorowi, pobiera wskaznik wybranego zbioru z vectora, wywoluje odpowiednia metode operacji arytmetycznej, na koncu wypisuje nowo utworzony zbior.
     */
    void wykonajDzialanie(const int &flaga);
};



template<class T>
Interfejs<T>::Interfejs(const int &ileZbiorow, const int &flaga): ileZbiorow(ileZbiorow){
    this->stworzZbiory(flaga);
}

template<class T>
void Interfejs<T>::wprowadzDane(const int &flaga) {
    auto zbior =  new Zbior<T>();
    T znak;

    if(flaga != 3)
    {
        while(true)
        {
            cin>>znak;
            if(!cin.good())
            {
                cin.clear();
                cin.ignore(1000, '\n'); //"wyczysc" konsole
                break;
            }
            zbior->dodaj(znak);
        }
    }
    else
    {
        while(true)
        {
            cin>>znak;
            if(znak == '^')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                break;
            }
            zbior->dodaj(znak);
        }
    }
    wsk_Zbior.push_back(zbior); //dodaj wskaznik nowego zbioru do vectora
}

template<class T>
void Interfejs<T>::stworzZbiory(const int &flaga){
    cout<<"Znak ^ przerywa wprowadzanie do zbioru"<<endl;
    for (int i = 0; i < this->ileZbiorow ; ++i) {
        cout << "Podaj elementu zbioru #" << i+1 << endl;
        wprowadzDane(flaga);
    }
    wyswietlOpcje();
}

template<class T>
void Interfejs<T>::wyswietlOpcje() {
    int operacja;
    cout<<"Podaj cyfre odpowiadajaca zadanej operacji na zbiorze / dwoch zbiorach"<<endl;
    cout<<"Mozliwe opearcje:"<<endl;
    cout<<"1. +"<<endl;
    cout<<"2. -"<<endl;
    cout<<"3. *"<<endl;
    cout<<"4. +="<<endl;
    cout<<"5. -="<<endl;
    cout<<"6. *="<<endl;
    cin>>operacja;
    switch (operacja) {
        case 1: {wykonajDzialanie(1); cout << string(50, '\n');}
            break;
        case 2: {wykonajDzialanie(2); cout << string(50, '\n');}
            break;
        case 3: {wykonajDzialanie(3); cout << string(50, '\n');}
            break;
        case 4: {wykonajDzialanie(4); cout << string(50, '\n');}
            break;
        case 5: {wykonajDzialanie(5); cout << string(50, '\n');}
            break;
        case 6: {wykonajDzialanie(6); cout << string(50, '\n');}
            break;
        default: cout<<"Podano zla operacje..."<<endl;cout << string(50, '\n')<<endl;wyswietlOpcje();
            break;
    }

}

template<class T>
void Interfejs<T>::wykonajDzialanie(const int &flaga) {
    int nrZbioru, nrZbioru2;
    char znak;

    switch (flaga) {
        case 1: {cout<<"Podaj dwa zbiory z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            cin>>nrZbioru2;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T>* zbior2 = wsk_Zbior[nrZbioru2-1];
            Zbior<T> nowyZbior = zbior1->operator+(*zbior2);
            cout<<"Nowo utworzony zbior: "<<endl;
            cout<<nowyZbior;
            }
            break;
        case 2: {cout<<"Podaj dwa zbiory z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            cin>>nrZbioru2;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T>* zbior2 = wsk_Zbior[nrZbioru2-1];
            Zbior<T> nowyZbior = zbior1->operator-(*zbior2);
            cout<<"Nowo utworzony zbior: "<<endl;
            cout<<nowyZbior;}
            break;
        case 3: {cout<<"Podaj dwa zbiory z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            cin>>nrZbioru2;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T>* zbior2 = wsk_Zbior[nrZbioru2-1];
            Zbior<T> nowyZbior = zbior1->operator*(*zbior2);
            cout<<"Nowo utworzony zbior: "<<endl;
            cout<<nowyZbior;}
            break;
        case 4: {cout<<"Podaj jeden zbior z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T> nowyZbior = zbior1->operator+=(*zbior1);}
            break;
        case 5: {cout<<"Podaj jeden zbior z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T> nowyZbior = zbior1->operator-=(*zbior1);}
            break;
        case 6: {cout<<"Podaj jeden zbior z przedzialu od 1 - "<<this->ileZbiorow<<endl;
            cin>>nrZbioru;
            Zbior<T>* zbior1 = wsk_Zbior[nrZbioru-1];
            Zbior<T> nowyZbior = zbior1->operator*=(*zbior1);}
            break;
        default: cout<<"Podano zla operacje..."<<endl;cout << string(50, '\n')<<endl;wyswietlOpcje();
            break;
    }

    cout<<"Wprowadz ^ aby powrocic do wyboru operacji, inny znak zamyka program"<<endl;

    while(true)
    {
        cin>>znak;
        if(znak == '^')
        {
            cin.clear();
            cin.ignore(1000, '\n');
            wyswietlOpcje();
        }
        else{ return;}
    }
}


#endif //PROJEKT_INTERFEJS_H
