// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = atoi(&fraction[0]);
    // Aqui es un string = char un caracter de cadena el cual se utiliza la funcion atoi para pasarlo a un valor entero.
    int y = atoi(&fraction[2]);

    int duration = (8 * x) / y;

    return round(duration); // Round es la funcion de redondear esa duración.
    // TODO
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{

// Aqui se especifica la frecuencia y el calculo de los semitonos.
    int tono;


    switch (note[0])
    {

        case 'A':  // Aqui esta letras equivale switch que se especifica la distancia que hay de los tonos de A a G
            tono =  0;
            break;

        case 'B':
            tono =  2;
            break;

        case 'C':
            tono = - 9;
            break;

        case 'D':
            tono = - 7;
            break;

        case 'E':
            tono = - 5;
            break;

        case 'F':
            tono = - 4;
            break;

        case 'G':
            tono = - 2;
            break;

    }




    if (note[1] == '#') // En este caso # = sostenido aumenta
    {

        tono++;
        tono += (note[2] - '0' - 4) * 12;

    }
    else if (note[1] == 'b') // En este caso b = Bemol disminuye
    {

        tono--;
        tono += (note[2] - '0' - 4) * 12;


    }
    else
    {
        tono += (note[1] - '0' - 4) * 12;
    }



    return round(440 * pow(2, tono / 12.0));
    // Aqui la letra  "tono" es n el cual equivale la posición de la nota en la octava. Aqui esta la formula.




    // TODO
}

// Determines whether a string represents a rest
bool is_rest(string s)
{

    string a = (""); // Esta comparando dos cadenas de caracter el silencio y el string s

    if (strcmp(s, a) == 0)
    {
        return true;

    }
    else
    {
        return false;
    }

    // TODO
}
