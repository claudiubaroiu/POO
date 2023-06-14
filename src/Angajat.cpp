#include "Supermarket.h"
#include "Produs.h"
#include "Angajat.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

Angajat::Angajat()
{
    //ctor
}

Angajat::~Angajat()
{
    //dtor
    delete[]ang;
}

Angajat::Angajat(char *filename){
    file.open(filename, ios::in);
    while(!file.eof()){
        char linie[50];
        file.getline(linie, 50);

        char *ptr = strtok(linie, " ");
        if(ptr == NULL)
            break;

        ang[numar].nume = new char[strlen(ptr)];
        strcpy(ang[numar].nume, ptr);
        ptr = strtok(NULL, " ");

        ang[numar].prenume = new char[strlen(ptr)];
        strcpy(ang[numar].prenume, ptr);
        ptr = strtok(NULL, " ");



        ang[numar].varsta = new char[strlen(ptr)];
        strcpy(ang[numar].varsta, ptr);
        ptr = strtok(NULL, " ");


        ang[numar].ID = new char[strlen(ptr)];
        strcpy(ang[numar].ID, ptr);
        ptr = strtok(NULL, " ");
        numar++;
       // delete[]magazin;
    }

}

void Angajat::showAngajat(){

 ifstream file("angajat.txt.txt");

    if (file.is_open()) {
        string line;
        int numarAngajat = 1;

        while (getline(file, line)) {
            stringstream ss(line);
            string nume, prenume, varsta,ID;

            getline(ss, nume, ' ');
            getline(ss, prenume, ' ');
            getline(ss, varsta, ' ');
            getline(ss, ID);

           cout<<"\nAngajatul numarul "<< numarAngajat<<": "<<nume<<" "<<prenume <<"\nVarsta: "<<varsta<<"\nID: "<<ID<<endl;
           cout<<"\n";
            numarAngajat++;
        }

        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
    }
 }

void Angajat::adaugare()
{
     /*std::ofstream file("date.txt.txt", std::ios::app); // Deschide fisierul in modul de scriere adaugata

    if (file.is_open()) {
        std::string magazin, locatie, interval_orar;

        // Cere utilizatorului sa introduca datele
        std::cout << "Introduceti numele magazinului: ";
        std::cin >> magazin;

        std::cout << "Introduceti locatia magazinului: ";
        std::cin >> locatie;

        std::cout << "Introduceti intervalul orar: ";
        std::cin >> interval_orar;

        // Scrie datele in fisierul text
        file <<magazin << " " << locatie << " " << interval_orar << std::endl;

        // Inchide fisierul
        file.close();
        std::cout << "Datele au fost adaugate in fisierul 'date.txt'." << std::endl;
    } else {
        std::cout << "Eroare la deschiderea fisierului." << std::endl;
    }*/
 ofstream file("angajat.txt", std::ios::app);

    if (file.is_open()) {
        string nume,prenume, varsta,ID;

        cout << "Introduceti numele angajatului: ";
        cin >>nume;

        cout << "Introduceti prenumele angajatului: ";
        cin >> prenume;

        cout << "Introduceti varsta: ";
        cin >> varsta;

        cout << "Introduceti ID-ul: ";
        cin >> ID;

        file << nume << " " << prenume << " " << varsta << " " << ID << endl;

        file.close();

        cout << "Datele au fost adaugate in fisierul '" <<"angajat.txt" << "'." << endl;
    } else {
        cout << "Eroare la deschiderea fisierului." << endl;
    }



    }

void Angajat::cautare()
{
    string name;
    cout<<"Introduceti ID-ul angajatului cautat: "<<endl;
    cin>>name;
    cout << "Angajatul cu ID-ul " << name << " este: ";
    ifstream file("angajat.txt.txt");
     if (file.is_open()) {

        string line;
        int numarAngajat = 1,nr=0;

        while (getline(file, line)) {
            stringstream ss(line);
            string nume, prenume,varsta,ID;

            getline(ss, nume, ' ');
            getline(ss, prenume, ' ');
            getline(ss, varsta,' ');
            getline(ss, ID);
            if(name==ID){
            cout << nume <<" "<<prenume<<endl;
            }
            numarAngajat++;
        }


        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
        }
}


