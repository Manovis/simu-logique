#ifndef PORTE_OU_H
#define PORTE_OU_H

#include <porte_base.h>


class porte_ou : public porte_base
{
    public:
        porte_ou(string name);
        virtual ~porte_ou();

        void calculate_output();
        void print_info();
        void set_input(int val, int i);
        void create_entree(int n);

    protected:

    private:
        int n_entree;
        int *e_or;
        int sortie;
        string nom;
};

#endif // PORTE_OU_H
