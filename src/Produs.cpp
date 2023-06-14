#include "Produs.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

Produs::Produs()
{
    //ctor
}

Produs::~Produs()
{
    //dtor
    delete[]produs;
}

Produs::Produs(char *filename){
    file.open(filename, ios::in);
    while(!file.eof()){
        char linie[50];
        file.getline(linie, 50);

        char *ptr = strtok(linie, " ");
        if(ptr == NULL)
            break;

        produs[numar].nume = new char[strlen(ptr)];
        strcpy(produs[numar].nume, ptr);
        ptr = strtok(NULL, " ");



        produs[numar].categoria = new char[strlen(ptr)];
        strcpy(produs[numar].categoria, ptr);
        ptr = strtok(NULL, " ");


        produs[numar].pret = new char[strlen(ptr)];
       strcpy(produs[numar].pret, ptr);
    ///  strcpy(produs[numar].pret,ptr);

        ptr = strtok(NULL, " ");
        numar++;
       // delete[]magazin;
    }

}

void Produs::showProdus(){

 ifstream file("produs.txt.txt");

    if (file.is_open()) {
        string line;
        int numarProdus = 1;

        while (getline(file, line)) {
            stringstream ss(line);
            string nume, categorie, pret;

            getline(ss, nume, ' ');
            getline(ss, categorie, ' ');
            getline(ss, pret);

            cout << "Produsul numarul: " << numarProdus << "\nNume: " << nume
                      << "\nCategorie: " << categorie << " \nPret: " <<pret << endl;
            cout<<"\n";
            numarProdus++;
        }

        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
    }
 }

void Produs::adaugare()
{

 ofstream file("produs.txt.txt", std::ios::app);

    if (file.is_open()) {
        string nume, categorie;
        float pret;

        cout << "Introduceti numele produsului: ";
        cin >>nume;

        cout << "Introduceti categoria produsului: ";
        cin >> categorie;

        cout << "Introduceti pretul: ";
        cin >> pret;

        file << nume << " " << categorie<< " " << pret << endl;

        file.close();

        cout << "Datele au fost adaugate in fisierul '" <<"produs.txt" << "'." << endl;
    } else {
        cout << "Eroare la deschiderea fisierului." << endl;
    }
}




void Produs::cautare()
{
    string name;
    cout<<"Introduceti categoria produsului: "<<endl;
    cin>>name;
    cout << "Produsele din categoria: "<<name<<" care se afla in stoc sunt: \n" ;
     ifstream file("produs.txt.txt");
     if (file.is_open()) {
        string line;
        int numarProdus = 1,nr=0;
            while (getline(file, line)) {
            stringstream ss(line);
            string nume, categorie;
            string pret;

            getline(ss, nume, ' ');
            getline(ss, categorie, ' ');
            getline(ss, pret);
            if(name==categorie){

            cout << ++nr <<"."<< nume << endl;
            }
            numarProdus++;
        }


        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului." << std::endl;
        }
}


void Produs::stergere()
{
    ifstream inputFile("produs.txt.txt");
    if (!inputFile.is_open()) {
        cout << "Eroare la deschiderea fisierului." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile.is_open()) {
        cout << "Eroare la deschiderea fisierului temporar." << endl;
        inputFile.close();
        return;
    }


    string numeSters;
    cout << "Introduceti numele produsului de sters: ";
    cin >> numeSters;

    string line;
    bool sters = false;
    while (getline(inputFile, line)) {
        if (line.find(numeSters) != string::npos) {
            sters = true;
            continue;
        }
        tempFile << line << endl;
    }

    inputFile.close();
    tempFile.close();
    remove("produs.txt.txt");
    rename("temp.txt", "produs.txt.txt");
     if (sters) {
        cout << "Produsul '" << numeSters << "' a fost sters." << std::endl;
    } else {
        cout << "Produsul '" << numeSters << "' nu a fost gasit." << std::endl;
    }

}
