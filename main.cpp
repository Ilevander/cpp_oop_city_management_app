#include "ville.h"

int main()
{

    Ville x;
    cout << "Cette ville est construit par défaut pour le test : " << endl;

    x.affiche();

    Ville v1(5,"Rabat",15);
    v1.affiche();
    cout << endl;
    Ville v2(10,"Casa Blanca",16);
    v2.affiche();

    int result= v1.comparer(v1,v2);

    cout << "Après la comparaison des deux ville : " <<result << endl;
     /* ******************************************************  */

     Ville v3(1,"Rabat",4);
     Ville v4(2,"Casa",45);
     Ville v5(3,"Temara",9);
     Ville v6(4,"Warzazat",7);
     Ville v7(5,"Marrakeche",3);

     Ville villes[] = {v3,v4,v5,v6,v7};

     Circuit c("Tanger",villes);

     if(c.villeExists(v7))
         {
           cout << v7.getNom() << "Existe dans le circuit " << c.getNom() << endl;
         }
           else
               {
                 v7.getNom() << "N'existe pas dans le circuit" << c.getNom() << endl;
               }

     Circuit c2("Meknes",villes);

     if(c2.ajouterVille(v7))
     {
        cout << v7.getNom() << "été ajouté par succès au circuit" << c2.getNom() << endl;
     }

   cout << "La durée total dans le circuit " << c2.getNom() << " est " << c2.totalDuree() << " jours" << endl;

    c2.retirerVille(2);

    for(int i=0;i<6;i++)
        cout << villes[i] << endl;

    Circuit c3("Oujda",villes);

    c3.afficheCircuit();

   return 0;
}
