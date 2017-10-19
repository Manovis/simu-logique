#include "porte_base.h"

porte_base::porte_base()
{
    //ctor
    cout << "Constructeur de la Porte de Base " << endl;
}

porte_base::~porte_base()
{
    //dtor
    cout << "Destructeur de la Porte de Base " << endl;
}


void porte_base::calculate_output()
{
    //Nothing because define in each door
}

void porte_base::set_input(int entree)
{
    //Import the entries
}

void porte_base::print_info()
{
    //Display the gate type and the current I/O values
}
