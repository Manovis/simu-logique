#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "porte_base.h"
#include "porte_inverse.h"
#include "porte_et.h"
#include "porte_ou.h"
#include "circuit.h"
#include "vecteurs.h"

using namespace std;

int main()
{
    int n=3, i=0;
    int val[n];
    val[0] = 1;
    val[1] = 0;
    val[2] = 1;

    //All this part is to test the creation of the gates and the functions related to them
    /*
    //Création de l'objet correspondant à la porte et
    porte_et et("P1");
    //Création du vecteur contenant les entrées
    et.create_entree(n);

    for(i=0; i<n; i++){
        et.set_input(val[i], i); //Envoie des entrées
        cout << "Envoie de la valeur " << i << endl;
    }

    //Calcul des sorties
    et.calculate_output();
    //Affichage des infos de la porte
    et.print_info();

    cout << endl;

    //Création de l'objet correspondant a la porte inverseuse
    porte_inverse inv("P2");
    //Attribution de l'entrée à la main pour le moment
    inv.set_input(1);
    //Calcul de la sortie
    inv.calculate_output();
    //Affichage des infos de la porte
    inv.print_info();

    cout << endl;

    //Création de l'objet correspondant à la porte ou
    porte_ou ou("P3");
    //Création du vecteur contenant les entrées
    ou.create_entree(n);

    for(i=0; i<n; i++){
        ou.set_input(val[i], i);
        cout << "Envoie de la valeur " << i << endl;
    }

    //Calcul des sorties
    ou.calculate_output();
    //Affichage des infos de la porte
    ou.print_info();

    cout << endl;
    */

    string path_circ = "liste-circuits/circuit1.txt";
    circuit cir;
    cir.acquisition_texte(path_circ);

    string path_vect = "liste-circuits/vecteurs.txt";
    vecteurs vect;
    vect.lecture_vecteurs(path_vect);

    return 0;
}
