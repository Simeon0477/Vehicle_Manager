#include <iostream>
#include "vehicle.h"

using namespace std;

Garage garage;
int choix, ind;

int main(){
    cout << "\033[35m******** Simulateur de Scores ******** \n\033[0m";

    while (1) {
        //Menu
        cout << "\nMenu :\n";
        cout << " 1 - Afficher les caractéristiques des véhicules\n";
        cout << " 2 - Ajouter un véhicule\n";
        cout << " 3 - Rechercher d'un véhicule par immatriculation\n";
        cout << " 4 - Calculer le coût d'entretien d'un véhicule\n";
        cout << " 5 - Quitter\n";
        cout << "Votre choix -> ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "\n\033[32m1 - Afficher les caractéristiques des véhicules \n\n\033[0m";
                garage.showVehicle();
                break;

            case 2:
                int vehicle_choice;
                cout << "\n\033[32m2 - Ajouter un véhicule \n\n\033[0m";
                cout << "Quel type de véhicule voulez vous ajouter? : " 
                     << "\n 1 - Voiture"
                     << "\n 2 - Moto"
                     << "\n 3 - Camion"
                     << endl;
                cin << vehicle_choice;

                //Enregistrement des informations
                
                break;
                                            
            case 3:
                char immatriculation[10];
                cin.ignore();
                cout << "\n\033[32m3 - Rechercher d'un véhicule par immatriculation \n\n\033[0m";
                cout << "Entrez le numéro d'imatriculation de la voiture : ";
                cin.getline(immatriculation, 10);
                garage.VehicleSearch(immatriculation);
                break;
                
            case 4:
                cout << "\n\033[32m3 - Calculer le coût d'entretien d'un véhicule \n\n\033[0m";
                
                break;

            case 5:
                cout << "Au revoir!\n";
                exit(0);

            default:
                cout << "Option invalide. Veuillez réessayer.\n";
                break;
        }
    }

    return 0;
}