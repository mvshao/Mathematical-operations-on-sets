/** @file */
//
// Created by rfok7 on 24.10.2020.
//
#include <iostream>
#include "lista.h"
#include "zbior.h"
#include "interfejs.h"

using namespace std;
int main() {

    cout<<"Podaj cyfre odpowiadajaca typowi zbiorow:"<<endl;
    cout<<"1. Calkowito liczbowy"<<endl;
    cout<<"2. Zmiennoprzecinkowy"<<endl;
    cout<<"3. Znakowy"<<endl;

    int wybor,ileZbiorow;
    cin>>wybor;

    cout<<"Liczba zbiorow do utworzenia: "<<endl;
    if(!(cin>>ileZbiorow))
        return 0;

    switch (wybor) {
        case 1: {Interfejs<int>interfejsInt(ileZbiorow,1);
            break;}
        case 2: {Interfejs<double>interfejsDouble(ileZbiorow,2);
            break;}
        case 3: {Interfejs<char>interfejsString(ileZbiorow,3);
            break;}
        default: cout<<"Podano bledny typ..."<<endl;
            break;
    }

/*
    Zbior<int> zbior;
    Zbior<int> zbior2;
    zbior.dodaj(1);
    zbior.dodaj(2);
    zbior.dodaj(3);


    //=====================

    zbior2.dodaj(2);
    zbior2.dodaj(5);


    cout << zbior;
    cout<<"==================="<<endl;
    cout<<zbior.ileElementow()<<endl;
    cout<<"==================="<<endl;
    zbior.usun(512.32);
    cout << zbior;
    cout<<"==================="<<endl;
    if (zbior.czyNalezy(12.2))
    {
        cout<<"Nalezy"<<endl;
    }
    else
        cout<<"Nie nalezy"<<endl;
    cout<<"==================="<<endl;

    auto nowyZbior = zbior2.operator*=(zbior2);
    //auto nowyZbior = zbior.operator*(zbior2);
    //cin>>zbior;
    //cout << zbior;
    cout<<"Po operator*="<<endl;
    cout<<nowyZbior;
    cout<<"==================="<<endl;
    cout<<nowyZbior.ileElementow()<<endl;
    cout<<"==================="<<endl;
*/
return 0;
}