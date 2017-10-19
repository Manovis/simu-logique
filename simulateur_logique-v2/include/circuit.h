#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

#include "circuit.h"

using namespace std;


class circuit
{
    public:
        circuit();
        virtual ~circuit();
        void acquisition_texte(string path);
    protected:

    private:

};

struct element_matrice{
    string name;
    string sortie_interm;
    char type; //Type can be I for input, O for output, D for door
    int index;
};

#endif // CIRCUIT_H
