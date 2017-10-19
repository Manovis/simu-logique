#include "circuit.h"

circuit::circuit()
{
    //ctor
}

circuit::~circuit()
{
    //dtor
}

void circuit::acquisition_texte(string path){

    //Load the file pointed by "path" in "file"
    ifstream file(path.c_str(), ios::in);

    if(file){ //If the file is open
        cout << "Fichier '" << path<< "' ouvert" << endl;
        cout << endl; //Just a space


        int i = 0, j = 0;
        string tmp;
        bool found = 0;
        int n_lines = 0;
        int n_entree = 0;
        int n_sortie = 0;
        int n_portes = 0;
        int taille_matrice_incidence;
        int index;

        string entrees_primaires;
        string sorties_primaires;

        //Calculate how many lines the text file contain
        while(!file.eof()){
            getline(file, tmp);
            i++;
        }

        //Create variable with i lines, clear file.eof value, initialise cursor and i
        n_lines = i;
        file.clear();
        string contenu[n_lines];
        i = 0;
        file.seekg(0, ios::beg);

        cout << "Voici le contenu du fichier:" << endl;
        //Get lines content
        while(!file.eof()){
            getline(file, contenu[i]);
            cout << contenu[i] << endl;
            i++;
        }
        cout << endl; //Just a space

        //State machine to find key char in the content
        for(i=0; i<n_lines; i++){
            if(contenu[i].find("INPUT") != string::npos){
                cout << "Caractere INPUT trouve" << endl;
                entrees_primaires = contenu[i].substr(6, contenu[i].size());
                cout << "Les entrees primaires sont donc " << entrees_primaires << endl;
            }
            else if(contenu[i].find("OUTPUT") != string::npos){
                cout << "Caractere OUTPUT trouve" << endl;
                sorties_primaires = contenu[i].substr(7, contenu[i].size());
                cout << "Les sorties primaires sont donc " << sorties_primaires << endl;
            }
            //This part is not used at the moment but not deleted cause it might be usefull in the future
            /*
            else if(contenu[i].find("and") != string::npos){
                cout << "Appel d'une porte AND" << endl;
            }
            else if(contenu[i].find("or") != string::npos){
                cout << "Appel d'une porte OR" << endl;
            }
            else if(contenu[i].find("not") != string::npos){
                cout << "Appel d'une porte INVERSEUSE" << endl;
            }
            else{
                cout << "Fin de fichier ou caractère non trouvé" << endl;
            }*/
        }

        cout << endl; //Just a space

        //Calculate the number of entries
        for (i=0; i<entrees_primaires.size(); i++){
            if(entrees_primaires.substr(i,1) == " "){
                n_entree++;
            }
            else if(entrees_primaires.substr(i,1) == ";"){
                n_entree++;
                break;
            }
        }

        //Calculate the number of outputs
        for (i=0; i<sorties_primaires.size(); i++){
            if(sorties_primaires.substr(i,1) == " "){
                n_sortie++;
            }
            else if(sorties_primaires.substr(i,1) == ";"){
                n_sortie++;
                break;
            }
        }

        n_portes = n_lines - 3; //In the file there is only 3 lines for the inpout/output definition
        cout << "Il y a " << n_portes << " portes dans le fichier." << endl;
        cout << "Il y a " << n_entree << " entrees primaires dans le fichier" << endl;
        cout << "Il y a " << n_sortie << " sorties primaires dans le fichier" << endl;
        cout << endl; //Just a space

        taille_matrice_incidence = n_entree + n_sortie + n_portes; //The matrix contains the entries, outputs and doors
        element_matrice elem[taille_matrice_incidence]; //Creation of the matrix from the structure
        index = 0;

        //Creation of the incidence matrix
        int big_matrice[taille_matrice_incidence][taille_matrice_incidence];

        for (i=0; i<taille_matrice_incidence; i++){
            for (j=0; j<taille_matrice_incidence; j++){
                big_matrice[i][j] = 0;
            }
        }

        //Insert the entries in the matrix
        for (i=0; i<entrees_primaires.size(); i++){
            if(entrees_primaires.substr(i,1) == " "){
                index++; //Increment the index every time there is a space
            }
            else if(entrees_primaires.substr(i,1) == ";"){
                index++; //Increment the index at the end of the line
                break;
            }
            else {
                elem[index].name += entrees_primaires.substr(i, 1);
                elem[index].index = index;
                elem[index].type = 'I';
            }
        }

        //After the entries, insert the outputs in the matrix
        for(i=0; i<sorties_primaires.size(); i++){
            if(sorties_primaires.substr(i,1) == " "){
                index++; //Increment the index every time there is a space
            }
            else if(sorties_primaires.substr(i,1) == ";"){
                index++; //Increment the index at the end of the line
                break;
            }
            else {
                elem[index].name += sorties_primaires.substr(i, 1);
                elem[index].index = index;
                elem[index].type = 'O';
            }
        }
        int temp = 0;
        bool s_inter = true;

        //Finally insert the doors in the matrix, depending on their type
        for(i=0; i<n_lines; i++){
            if(contenu[i].find("and") != string::npos){
                elem[index].name = "and";
                elem[index].index = index;
                elem[index].type = 'A';

                for (temp = n_entree ; temp < (n_entree+n_sortie) ; temp++){
                    if(contenu[i].find(elem[temp].name) != string::npos){
                        //No other output
                        elem[index].sortie_interm = "";
                        break;
                    }
                    else{
                        //Other output detected
                        elem[index].sortie_interm = contenu[i].substr(7, 1); //Store the intermediary output
                    }
                }
                index++;
            }
            if(contenu[i].find("or") != string::npos){
                elem[index].name = "or";
                elem[index].index = index;
                elem[index].type = 'O';

                for (temp = n_entree ; temp < (n_entree+n_sortie) ; temp++){
                    if(contenu[i].find(elem[temp].name) != string::npos){
                        //No other output
                        elem[index].sortie_interm = "";
                        break;
                    }
                    else{
                        //Other output detected
                        elem[index].sortie_interm = contenu[i].substr(6, 1); //Store the intermediary output
                    }
                }

                index++;
            }
            if(contenu[i].find("not") != string::npos){
                elem[index].name = "not";
                elem[index].index = index;
                elem[index].type = 'N';

                for (temp = n_entree ; temp < (n_entree+n_sortie) ; temp++){
                    if(contenu[i].find(elem[temp].name) != string::npos){
                        //No other output
                        elem[index].sortie_interm = "";
                        break;
                    }
                    else{
                        //Other output detected
                        elem[index].sortie_interm = contenu[i].substr(7, 1); //Store the intermediary output
                    }
                }
                index++;
            }
        }

        for (i=0; i<taille_matrice_incidence; i++){
            //Display all the informations about an index
            cout << "Nom: " << elem[i].name << endl;
            cout << "Indice: " << elem[i].index << endl;
            cout << "Type: " << elem[i].type << endl;
            cout << "Sortie Intermediaire si il y a: " << elem[i].sortie_interm << endl;
            cout << "" << endl; //Just a space
        }

        int temp_entry = 0;
        int temp_gate = 0;
        int temp_output = 0;

        //Infill the elementary entries/gates part of the matrix
        i=2; //Beginning at the 2nd line of contenu[i], the first gate
        for (temp_gate=(n_entree+n_sortie); temp_gate<taille_matrice_incidence; temp_gate++){ //Scanning the gates
                for (temp_entry = 0 ; temp_entry < (n_entree) ; temp_entry++){ //scanning the entries
                        if(contenu[i].find(elem[temp_entry].name) != string::npos){ //Search for the first elementary entry in the content
                            //If we find an elementary entry in this line
                            big_matrice[elem[temp_gate].index][elem[temp_entry].index]=1;
                            big_matrice[elem[temp_entry].index][elem[temp_gate].index]=1;
                            cout << "L'entree "<<elem[temp_entry].name << " a ete trouve dans la ligne " << i+1 << endl;
                            cout << "Elle a ete place dans la ligne " << temp_gate+1 << " colonne " << temp_entry+1 << endl;
                        }
                        else{
                            //No elementary entry in this line
                        }
                }
            i++; //Incrementing the line
        }
        cout << "" << endl; //Just a space
        cout << "Relation entrée / porte complétée" << endl;
        cout << "" << endl; //Just a space

        //Infill the output/gates part of the matrix
        i=2; //Beginning at the 2nd line of contenu[i], the first gate
        for (temp_gate=(n_entree+n_sortie); temp_gate<taille_matrice_incidence; temp_gate++){ //Scanning the gates
                for (temp_output = n_entree ; temp_output < (n_entree+n_sortie+1) ; temp_output++){ //scanning the outputs
                        if(contenu[i].find(elem[temp_output].name) != string::npos){ //Search for the first elementary entry in the content
                            //If we find an elementary entry in this line
                            big_matrice[elem[temp_gate].index][elem[temp_output].index]=1;
                            big_matrice[elem[temp_output].index][elem[temp_gate].index]=1;
                            cout << "La sortie "<<elem[temp_output].name << " a ete trouve dans la ligne " << i+1 << endl;
                            cout << "Elle a ete place dans la ligne " << temp_gate+1 << " colonne " << temp_output+1 << endl;
                        }
                        else{
                            //No elementary entry in this line
                        }
                }
            i++; //Incrementing the line
        }
        cout << "" << endl; //Just a space
        cout << "Relation sorties / porte complétée" << endl;
        cout << "" << endl; //Just a space




        cout << "Voici la matrice d'incidence: " << endl;
        int k = 0;

        for(i=0; i<taille_matrice_incidence; i++){
            for(k=0; k<taille_matrice_incidence; k++){
                printf("+---");
            }
            puts("+");

            for(j=0; j<taille_matrice_incidence; j++){
                printf("|%3d", big_matrice[i][j]);
            }
            puts("|");
        }
        for(k=0; k<taille_matrice_incidence; k++){
            printf("+---");
        }
        puts("+");


        cout << "" << endl; //Just a space

        file.close(); //Close the file
    }//end if file is open
    else{ //If the file isn't open
        cout << "Erreur lors de l'ouverture du fichier" << endl;
    }
}

