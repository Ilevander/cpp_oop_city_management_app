#include<iostream>
#include<cstring>

using namespace std;

class Ville
{

    int code;
    string nom;
    int nombreJour;
public:
    /*getters*/
    int getCode();
    string getNom();
    int getNombreJour();
    /*Constructors*/
    Ville();
    Ville(int,string,int);
    /*Mehods*/
    void affiche();
    void saisir();
    int comparer(const Ville&,const Ville&);
};

class Circuit
{
    string nom;
    int nombreVille;
    Ville villes[7];
public:
    /*Getters*/
    string getNom();
    int getNombreVille();
    Ville* getVille();
    /*Cojnstructors*/
    Circuit();
    Circuit(string,int,const Ville&);
    Circuit(const Circuit&);
    /*Methods*/
    /*vérifier si unr ville existe existe dans un circuit ou pas*/
    bool villeExists(const Ville&);
    bool ajouterVille(const Ville&);
    int totalDuree();
    void retirerVille(int);
    void afficheCircuit();
};
