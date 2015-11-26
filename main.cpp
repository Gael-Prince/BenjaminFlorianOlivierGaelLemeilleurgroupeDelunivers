/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 26 novembre 2015, 10:09
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class cases {

private :

int pixel;
int nombre=0;

public :

int getPixel (){return pixel;}
int getNombre(){return nombre;}
void plusone (){ nombre++;}
void setpixel (int i){pixel =i;nombre=0;}



};


/*void lectureImage(vector<int[2]> matrice)
{



}*/

int main(int argc, char** argv) {


    vector<cases> matrice;
    cases c;
    for(int i(0) ; i<256 ; i++)
    {
        c.setpixel(i);
        matrice.push_back(c);
        cout << "pixel : " <<matrice[i].getPixel() <<"      "<< "nombre : " <<matrice[i].getNombre() << endl;
    }

    int lon, lar, maxGris, pixel;
    string tmp;

    ifstream imageChargee("image1.txt", ios::in); //ouverture en lecture
    ofstream histogramme("histogramme.txt", ios::out); //en ecriture

    if(!imageChargee)  // si l'ouverture a échoué
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    getline(imageChargee, tmp);
    getline(imageChargee, tmp);

    imageChargee >> lon;
    imageChargee >> lar;
    imageChargee >> maxGris;

    for(int i(0) ; i < lar ; i++)
    {
        for(int j(0) ; j < lon ; j++)
        {
            imageChargee>>pixel;
            matrice[pixel].plusone();
        }
    }

    imageChargee.close();

    return 0;
}



