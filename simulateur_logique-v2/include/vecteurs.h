#ifndef VECTEURS_H
#define VECTEURS_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class vecteurs
{
    public:
        vecteurs();
        virtual ~vecteurs();
        void lecture_vecteurs(string path);

    protected:

    private:
};

#endif // VECTEURS_H
