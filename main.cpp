#include "Supermarket.h"
#include "Produs.h"
#include "Angajat.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>

#include<windows.h>



using namespace std;


void setConsoleColor(int bgColor, int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
    SetConsoleCursorPosition(hConsole, pos);
}

void printCenteredTitle(const std::string& title) {
    // Setează fundalul alb și textul negru
    setConsoleColor(15, 0);

    // Află dimensiunea consolei
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.dwSize.X;

    // Calculează poziția centrală pentru afișarea titlului
    int titleLength = static_cast<int>(title.length());
    int xPos = (consoleWidth - titleLength) / 2;
    int yPos = csbi.dwCursorPosition.Y;

    // Setează poziția cursorului
    setCursorPosition(xPos, yPos);

    // Afișează titlul
    std::cout << title;
}


void meniu1()
{
    Supermarket s("date.txt.txt");
    int d1;
    do
    {
        cout<<"\n1.Afisarea datelor din fisier\n";
        cout<<"2.Adaugare supermarket\n";
        cout<<"3.Cautare magazin\n";
        cout<<"4.Revenire la meniul principal\n";
        cout<<"Introduceti optiunea dorita: ";
        cin>>d1;
        system("cls");
        switch(d1)
        {
        case 1:
        {
            s.showSupermarket();
            break;
        }
        case 2:
        {
            s.adaugare();

            break;
        }
        case 3:
        {
            s.cautare();
            break;
        }
        case 4:
            break;
        }
    }
    while(d1!=4);

}

void meniu2()
{
    Produs p("date.txt.txt");
    int d2;
    do
    {
        cout<<"\n1.Afisarea datelor din fisier\n";
        cout<<"2.Adaugare produs\n";
        cout<<"3.Cautare produse\n";
        cout<<"4.Stergere produs\n";
        cout<<"5.Revenire la meniul principal\n";
        cout<<"Introduceti optiunea dorita: ";
        cin>>d2;
        system("cls");
        switch(d2)
        {
        case 1:
        {
            p.showProdus();
            break;
        }
        case 2:
        {
            p.adaugare();

            break;
        }
        case 3:
        {
            p.cautare();
            break;
        }

        case 4:
            p.stergere();
            break;
        case 5:
            break;
        }
    }
    while(d2!=5);

}


void meniu3()
{
    Angajat a("angajat.txt.txt");
    int d3;
    do
    {
        cout<<"\n1.Afisarea datelor din fisier\n";
        cout<<"2.Adaugare angajat\n";
        cout<<"3.Cautare angajat\n";
        cout<<"4.Revenire la meniul principal\n";
        cout<<"Introduceti optiunea dorita: ";
        cin>>d3;
        system("cls");
        switch(d3)
        {
        case 1:
        {
            a.showAngajat();
            break;
        }
        case 2:
        {
            a.adaugare();

            break;
        }
        case 3:
        {
            a.cautare();
            break;
        }

        case 4:
            break;
        }
    }
    while(d3!=4);

}


int main()
{
system("title Interfata grafica");
    system("color F0");  // Fundal alb, text negru

    // Afișează titlul în mijlocul consolei
    printCenteredTitle("Administrare supermarket");
    int d;

    do
    {
        cout<<"\n1.Gestionare magazine\n";
        cout<<"2.Gestionare produse\n";
        cout<<"3.Gestionare angajati\n";
        cout<<"4.Terminare program\n";
        cout<<"Introduceti optiunea dorita: ";
        cin>>d;
        system("cls");
        switch(d)
        {
        case 1:
        {
            //s.showSupermarket();
            meniu1();
            break;
        }
        case 2:
            meniu2();
            break;
        case 3:
            meniu3();
            break;
        case 4:
            break;

        }
    }
    while(d!=4);
    return 0;
}
