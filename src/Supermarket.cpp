#include "Supermarket.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

Supermarket::Supermarket()
{
    //ctor
}

Supermarket::~Supermarket()
{
    //dtor

}

Supermarket::Supermarket(char *filename){
    file.open(filename, ios::in);
    while(!file.eof()){
        char linie[50];
        file.getline(linie, 50);

        char *ptr = strtok(linie, " ");
        if(ptr == NULL)
            break;

        nume = new char[strlen(ptr)];
        strcpy(nume, ptr);
        ptr = strtok(NULL, " ");



        locatia = new char[strlen(ptr)];
        strcpy(locatia, ptr);
        ptr = strtok(NULL, " ");


        interval_orar = new char[strlen(ptr)];
        strcpy(interval_orar, ptr);
        ptr = strtok(NULL, " ");
        numar++;

    }

}

void Supermarket::showSupermarket(){

 ifstream file("date.txt.txt");

    if (file.is_open()) {
        string line;
        int numarMagazin = 1;

        while (getline(file, line)) {
            stringstream ss(line);
            string nume, locatie, interval_orar;

            getline(ss, nume, ' ');
            getline(ss, locatie, ' ');
            getline(ss, interval_orar);

            cout << "Pentru magazinul " << numarMagazin << " numele este: " << nume
                      << ", locatia este: " << locatie << " iar intervalul este: " << interval_orar << std::endl;

            numarMagazin++;
        }

        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
    }
 }

void Supermarket::adaugare()
{

 ofstream file("date.txt.txt", std::ios::app);

    if (file.is_open()) {
        string magazin, locatie, interval_orar;

        cout << "Introduceti numele magazinului: ";
        cin >> magazin;

        cout << "Introduceti locatia magazinului: ";
        cin >> locatie;

        cout << "Introduceti intervalul orar: ";
        cin >> interval_orar;

        file << magazin << " " << locatie << " " << interval_orar << endl;

        file.close();

        cout << "Datele au fost adaugate in fisierul '" <<"date.txt.txt" << "'." << endl;
    } else {
        cout << "Eroare la deschiderea fisierului." << endl;
    }



    }

void Supermarket::cautare()
{
    string name;
    cout<<"Introduceti numele magazinului: "<<endl;
    cin>>name;
    cout << "Magazinele cu numele :" << name << " se pot gasi in : \n";
    ifstream file("date.txt.txt");
     if (file.is_open()) {

        string line;
        int numarMagazin = 1,nr=0;

        while (getline(file, line)) {
            stringstream ss(line);
            string nume, locatie, interval_orar;

            getline(ss, nume, ' ');
            getline(ss, locatie, ' ');
            getline(ss, interval_orar);
            if(name==nume){
            cout << ++nr <<"."<< locatie << endl;
            }
            numarMagazin++;
        }


        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
        }
}


