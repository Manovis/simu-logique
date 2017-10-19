#include "porte_et.h"

porte_et::porte_et(string name)
{
    //ctor
    cout << "Constructeur de la Porte Et " << endl;
    n_entree = 0;
    sortie = 0;
    e = NULL;
    nom = name;

}

porte_et::~porte_et()
{
    //dtor
    cout << "Destructeur de la Porte Et " << endl;
}

void porte_et::create_entree(int n)
{
    e = new int[n]; //Allocation of the memory for e
    n_entree = n;
}

void porte_et::set_input(int val, int i)
{
    cout << "Réception de la valeur " << i << endl;
    e[i] = val; //Acquire entry values and save it
}

void porte_et::calculate_output()
{
    int u;
    for(u=0; u<n_entree;u++){
        if(e[u]==0){  //If at least one entry is = 0 then output=0
            sortie = 0;
            break;
        }
        else {  //Else, it means every entries are = 0 so output = 0
            sortie = 1;
        }
    }
}

void porte_et::print_info()
{
    int i = 0;

    cout << "Nom de la porte "<< nom << endl; //Display gate name

    //Affichage de toutes les entrées
    for (i=0 ; i<n_entree ; i++){
        cout << "Entree n°"<< i << " = "<< e[i] << endl;//Display value of each entry
    }

    //Affichage de la sortie
    cout << "Sortie s = "<< sortie << endl;//Display output value
}
