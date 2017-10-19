#include "porte_ou.h"

porte_ou::porte_ou(string name)
{
    //ctor
    cout << "Constructeur de la Porte Ou " << endl;
    n_entree = 0;
    sortie = 0;
    e_or = NULL;
    nom = name;
}

porte_ou::~porte_ou()
{
    //dtor
    cout << "Destructeur de la Porte Ou " << endl;

}

void porte_ou::calculate_output()
{
    int u;
    for(u=0; u<n_entree;u++){
        if(e_or[u]==1){ //If at least one entry is = 1 then output=1
            sortie = 1;
            break;
        }
        else { //Else, it means every entries are = 0 so output = 0
            sortie = 0;
        }
    }
}

void porte_ou::create_entree(int n)
{
    e_or = new int[n]; //Allocation of the memory for e
    n_entree = n;
}

void porte_ou::set_input(int val, int i)
{
    cout << "Réception de la valeur " << i << endl;
    e_or[i] = val; //Acquire entry values and save it
}

void porte_ou::print_info()
{
    int i = 0;

    cout << "Nom de la porte "<< nom << endl; //Display gate name

    //Affichage de toutes les entrées
    for (i=0 ; i<n_entree ; i++){
        cout << "Entree n°"<< i << " = "<< e_or[i] << endl; //Display value of each entry
    }

    cout << "Sortie s = "<< sortie << endl; //Display output value
}
