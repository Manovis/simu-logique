#ifndef PORTE_BASE_H
#define PORTE_BASE_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "porte_base.h"

using namespace std;


class porte_base
{
    public:
        porte_base();
        virtual ~porte_base();
        void calculate_output();
        void print_info();
        void set_input(int input);

    protected:
        int entree;
        int sortie;

    private:
};

#endif // PORTE_BASE_H
