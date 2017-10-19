#include "porte_inverse.h"

porte_inverse::porte_inverse(string name)
{
    //ctor
    cout << "Constructeur de la Porte Inverseuse " << endl;
    entree = 0;
    sortie = 0;
    nom = name;
}

porte_inverse::~porte_inverse()
{
    //dtor
    cout << "Destructeur de la Porte Inverseuse " << endl;
}

void porte_inverse::calculate_output()
{
    sortie=not(bool(entree)); //Invert the entry
}

void porte_inverse::print_info()
{
    //Display gate name, entry and output
    cout << "Nom de la porte "<< nom << endl;
    cout << "Entree e1 = "<< entree << endl;
    cout << "Sortie s = "<< sortie << endl;
}

void porte_inverse::set_input(int input)
{
    entree = input; //Acquire the entry and store it into "entree"
}
