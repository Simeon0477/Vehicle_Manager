#include <iostream>
#include "vehicle.h"

using namespace std;

Garage garage;
int choix, index_vehicle;
char immatriculation[10];
Car *car;
Motorcycle *motorcycle;
Truck *truck;

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
                cin >> vehicle_choice;

                //Enregistrement des informations
                char typeCarburant[20];
                int annee, prix;
                float poids;
                cin.ignore();
                cout << "Entrez le numéro d'imatriculation du véhicule : ";
                cin.getline(immatriculation, 10);
                cout << "Entrez le type de carburant du véhicule : ";
                cin.getline(typeCarburant, 20);
                cout << "Entrez l'année de production de votre véhicule' : ";
                cin >> annee;
                cout << "Entrez le prix d'achat de votre véhicule' : ";
                cin >> prix;
                cout << "Entrez le poids de votre véhicule' : ";
                cin >> poids;

                switch(vehicle_choice){
                    case 1:
                        char segment[20];
                        int nombrePortes;
                        cin.ignore();
                        cout << "Entrez le segment de la voiture : ";
                        cin.getline(segment, 20);
                        cout << "Entrez le nombre de porte de la voiture' : ";
                        cin >> nombrePortes;
                        car = new Car(immatriculation, typeCarburant, annee, poids, prix, segment, nombrePortes); 
                        garage.AddVehicle(car);
                        break;
                    case 2:
                        char typeMoto[20];
                        int nombreRoues;
                        cin.ignore();
                        cout << "Entrez le type de moto : ";
                        cin.getline(typeMoto, 20);
                        cout << "Entrez le nombre de roues de la moto' : ";
                        cin >> nombreRoues;
                        motorcycle = new Motorcycle(immatriculation, typeCarburant, annee, poids, prix, typeMoto, nombreRoues); 
                        garage.AddVehicle(motorcycle);
                        break;
                    case 3:
                        int chargeUtile;
                        int nombreEssieux;
                        cout << "Entrez la charge utile du camion' : ";
                        cin >> chargeUtile;
                        cout << "Entrez le nombre d'essieux du camion' : ";
                        cin >> nombreEssieux;
                        truck = new Truck(immatriculation, typeCarburant, annee, poids, prix, chargeUtile, nombreEssieux); 
                        garage.AddVehicle(truck);
                        break;
                }

                break;
                                            
            case 3:
                cin.ignore();
                cout << "\n\033[32m3 - Rechercher d'un véhicule par immatriculation \n\n\033[0m";
                cout << "Entrez le numéro d'imatriculation de la voiture : ";
                cin.getline(immatriculation, 10);
                garage.VehicleSearch(immatriculation);
                break;
                
            case 4:
                cout << "\n\033[32m3 - Calculer le coût d'entretien d'un véhicule \n\n\033[0m";
                while(1){
                    printf("Entrez l'index du véhicule : ");
                    cin >> index_vehicle;
                    if (index_vehicle < 1 || index_vehicle > garage.GetSize()) {
                        printf("Index invalide, réessayez\n");
                    }else{
                        break;
                    }
                }

                garage.CostCalculation(index_vehicle);
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