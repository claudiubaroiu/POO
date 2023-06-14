#ifndef PRODUS_H
#define PRODUS_H
#include <fstream>
#include <iostream>

using namespace std;
struct prod{
    char *nume;
    char *categoria;
    char* pret;
};
class Produs
{
    public:
        Produs();
        Produs(char *filename);
        void adaugare();
        void showProdus();
        void stergere();
        virtual ~Produs();

        void cautare();
    protected:
    private:
        int numar = 0;
        prod produs[10];
        fstream file;

};

#endif // PRODUS_H
