#ifndef ANGAJAT_H
#define ANGAJAT_H
#include <fstream>
#include <iostream>


using namespace std;
struct angajat{
    char *nume;
    char *prenume;
    char *varsta;
    char *ID;
};
class Angajat
{
    public:
        Angajat();
        Angajat(char *filename);
        void adaugare();
        void showAngajat();
        virtual ~Angajat();
        void cautare();
    protected:
    private:
        int numar = 0;
        angajat ang[10];
        fstream file;

};


#endif // ANGAJAT_H
