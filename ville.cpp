#include "ville.h"

/* Ville */

/*getters*/
int Ville::getCode()
                    {
                        return code;
                    }

string Ville::getNom()
                     {
                         return nom;
                     }

int Ville::getNombreJour()
                          {
                              return nombreJour;
                          }

Ville::Ville()
             {
                code =00;
                nom= "__";
                nombreJour=00;
             }

Ville::Ville(int inCode,string inNom,int inNombreJour)
                     {
                        code=inCode;
                        nom=inNom;
                        nombreJour=inNombreJour;
                     }

void Ville::affiche()
                     {
                         cout<< "*******************" << endl;
                         cout<< "****Infos Ville****" << endl;
                         cout<< "Code : " << code << endl;
                         cout<< "Nom  : " << nom  << endl;
                         cout<< "Nombre de Jour : " << nombreJour << endl;
                         cout<< "*******************" << endl;
                     }

void Ville::saisir()
                   {
                         cout<< "*******************" << endl;
                         cout<< "****Saisi Ville****" << endl;
                         cout<< "Code : ";
                         cin>>code;
                         cout<< "Nom  : " ;
                         cin>> nom;
                         cout<< "Nombre de Jour : ";
                         cin>>nombreJour;
                         cout<< "*******************" << endl;
                   }


int Ville::comparer(const Ville& a,const Ville& b)
                                       {
                                        if(a.code<b.code)
                                            return 0;
                                            else if(a.code>b.code)
                                                return 1;
                                                    else
                                                        return -1;
                                            }

/*  Circuit */

/*getters*/
string Circuit::getNom()
                        {
                            return nom;
                        }

int Circuit::getNombreVille()
                             {
                                 return nombreVille;
                             }
Ville* Circuit::getVille()
                          {
                             return villes;
                          }
/*Constructors*/
//Comme optimisation de préférence de ne rien mettre là-dans:
/*Circuit( ) {  }*/
Circuit::Circuit()
                  {
                       nom = "__";
                       nombreVille = 00;
                       for(int i=0;i<nombreVille;i++)
                           villes[i]=Ville();
                  }

Circuit::Circuit(string inNom,int inNombreVille,const Ville& inVille[])
                                        {
                                             nom = inNom;
                                             nombreVille =inNombreVille;
                                             for(int i=0;i<nombreVille;i++)
                                                  villes[i]=inVille[i];
                                        }

Circuit::Circuit(const Circuit& inCircuit)
                      {
                          nom=inCircuit.nom;
                          nombreVille =inCircuit.nombreVille;
                          for(int i=0;i<nombreVille;i++)
                          villes[i]=inCircuit.villes[i];
                      }

 /*Methods*/

bool Circuit::villeExists(const Ville& ville)
                                      {
                                         for(int i=0;i<nombreVille;i++)
                                            {
                                              if(villes[i].getCode()==ville.getCode())
                                                  return true;
                                            }
                                             return false;
                                      }

 bool Circuit::ajouterVille(const Ville& inVille)
                                         {
                                            if (nombreVille>=7)
                                              {
                                               cout<< "Circuit déjà remplie , impossible d'ajouter d'autres ville" << endl;
                                               return false;
                                              }
                                              for(int i=0;i<nombreVille;i++)
                                              {
                                                  if(villes[i].getCode()==inVille.getCode())
                                                  {
                                                    cout << "Ville déjà exixte" << endl;
                                                    return false;
                                                  }
                                              }
                                            villes[nombreVille]=inVille;
                                                nombreVille++;
                                            return true;
                                         }

int Circuit::totalDuree()
                        {
                          int duree=0;
                          for(int i=0;i<nombreVille;i++)
                             {
                              duree +=villes[i].getNombreJour();
                             }
                             return duree;
                        }
void Circuit::retirerVille(int inCode)
                               {
                                   int indice=-1;
                                   for(int i=0;i<nombreVille;i++)
                                   {
                                       if(villes[i].getCode()==inCode)
                                       {
                                           indice=i;//get the index of city to remove first
                                           break;
                                         /*supprime la ville en déplaçant le
                                         tableau des villes vers la gauche et quitte.*/
                                       }
                                   }
                                   if(indice==-1)
                                       {
                                         cout << "Erreur , le code " << inCode << "ne fait pas partit de ce circuit" << endl;
                                         return;
                                       }
                                    for(int i=indice;i<nombreVille-1;i++)
                                        {
                                          villes[i]=villes[i+1];
                                        }
                                      nombreVille--;/*Diminuer la taille après suppression*/
                               }
void Circuit::afficheCircuit()
                         {
                             cout<< "====================" << endl;
                             cout<< "Nom de Circuit :" << nom << endl;
                             cout<< " Les Villes dans le circuit" << endl;
                             for (int i=0;i<nombreVille;i++)
                                 {
                                   cout<< "Ville" << i+1 << ":" <<villes[i].nom << "Nombre de jours :"<< villes[i].nombreJour << endl;
                                 }
                         }





