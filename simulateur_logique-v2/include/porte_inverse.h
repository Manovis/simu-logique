#ifndef PORTE_INVERSE_H
#define PORTE_INVERSE_H

#include <porte_base.h>


class porte_inverse : protected porte_base
{
    public:
        porte_inverse(string name);
        virtual ~porte_inverse();

        void calculate_output();
        void print_info();
        void set_input(int input);


    protected:

    private:
        int entree;
        int sortie;
        string nom;
};

#endif // PORTE_INVERSE_H
