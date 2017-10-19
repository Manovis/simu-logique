#include "vecteurs.h"

vecteurs::vecteurs()
{
    //ctor
}

vecteurs::~vecteurs()
{
    //dtor
}

void vecteurs::lecture_vecteurs(string path){
    //Load the file pointed by "path" in "file"
    ifstream file(path.c_str(), ios::in);

    if(file){ //If the file is open
        cout << "Fichier '" << path << "' ouvert" << endl;
        cout << endl; //Just a space

        int i = 0;
        int u = 0;
        string tmp;

        //Calculate how many lines the text file contain
        while(!file.eof()){
            getline(file, tmp);
            i++;
        }

        int n_vectors = i - 2;
        int n_lines = i - 1;
        cout << "Nombre de vecteurs = " << n_vectors << endl;
        cout << "Nombre de lignes = " << n_lines << endl;
        cout << endl; //Just a space


        //Clearing the cursor
        file.clear();
        file.seekg(0, ios::beg);
        i = 0;

        //Creation of the content
        string contenu[n_lines + 1];

        cout << "Voici le contenu du fichier:" << endl;
        //Get lines content
        while(!file.eof()){
            getline(file, contenu[i]);
            cout << contenu[i] << endl;
            i++;
        }
        cout << endl; //Just a space


        int n_entrees = contenu[1].size();
        int content[n_vectors];

        for(i=1; i<n_lines; i++){
            content[i] = atoi(contenu[i].c_str());
        }

        cout << "Voici le contenu du fichier en int " << content[2] << endl;

    }
    else{ //If the file isn't open
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
}


