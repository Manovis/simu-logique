#ifndef PORTE_ET_H
#define PORTE_ET_H

#include <porte_base.h>


class porte_et : public porte_base
{
    public:
        porte_et(string name);
        virtual ~porte_et();

        void calculate_output();
        void print_info();
        void set_input(int val, int i);
        void create_entree(int n);

    protected:

    private:
        int n_entree;
        int sortie;
        int *e;
        string nom;
};

#endif // PORTE_ET_H
