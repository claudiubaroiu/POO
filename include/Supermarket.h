#ifndef STUDENT_H
#define STUDENT_H
#include <fstream>
#include <iostream>

using namespace std;

class Supermarket
{
    public:
        Supermarket();
        Supermarket(char *filename);
        void adaugare();
        void showSupermarket();
        virtual ~Supermarket();
        void cautare();
    protected:
    private:
        char*locatia;
        char*interval_orar;
        char* nume;
        int numar = 0;

        fstream file;

};

#endif // STUDENT_H
