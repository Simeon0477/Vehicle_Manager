#include <iostream>
#include "vehicle.h"

using namespace std;

//Fonction de copie
void copy(char *dest, const char *source){
    const char *ptr = source;
    char *ptr2 = dest;

    while(*ptr != '\0'){
        *ptr2 = *ptr;
        ptr++;
        ptr2++;
    }
}


/*
Classe Parent VEHICLE
*/

//Constructeur par défaut
Vehicle::Vehicle() {
    m_immatriculation[0] = '\0';
    m_typeCarburant[0] = '\0';
    m_annee = 0;
    m_poids = 0.0;
    m_prix = 0;
}

//Constructeur paramétré
Vehicle::Vehicle(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix) {
    SetImmatriculation(immatriculation);
    SetTypeCarburant(typeCarburant);
    m_annee = annee;
    m_poids = poids;
    m_prix = prix;
}

//Getteurs
const char* Vehicle::GetImmatriculation() { return m_immatriculation; }

const char* Vehicle::GetTypeCarburant() { return m_typeCarburant; }

int Vehicle::GetAnnee() { return m_annee; }

float Vehicle::GetPoids() { return m_poids; }

int Vehicle::GetPrix() { return m_prix; }

//Setteurs
void Vehicle::SetImmatriculation(const char immatriculation[]) {
    copy(m_immatriculation, immatriculation);
}

void Vehicle::SetTypeCarburant(const char typeCarburant[]) {
    copy(m_typeCarburant, typeCarburant);
}

void Vehicle::SetAnnee(int annee) { m_annee = annee; }
void Vehicle::SetPoids(float poids) { m_poids = poids; }
void Vehicle::SetPrix(int prix) { m_prix = prix; }

//Affichage des  caractéristiques
void Vehicle::ShowCharacteristics(){
    cout << "Les Caractéristiques  du véhicule sont :\n"
         << " - Numéro d'immatriculation : " << m_immatriculation
         << " - Type de carburant : " << m_typeCarburant
         << " - Année de fabrication :" << m_annee
         << " - Poids : " << m_poids
         << " - Prix : " << m_prix
         <<endl;
}

//Calcul du coût d'entretien
float MaintenanceCost(){
    float facteurCarburant;

    switch(m_typeCarburant){
        case "essence": facteurCarburant = 1.0; break;
        case "diesel": facteurCarburant = 1.05; break;
        case "hybride": facteurCarburant = 0.9; break;
        case "electrique": facteurCarburant = 0.7; break;
        default: facteurCarburant = 1.0;
    }

    return (0.02 * m_prix + 5 * (2025 - m_annee) + 0.001 * m_poids) * facteurCarburant;
}

/*
Classe Dérivée Car
*/

// Constructeur par défaut
Car::Car() : Vehicle() {
    m_segment[0] = '\0';
    m_nombrePortes = 0;
}

// Constructeur avec paramètres
Car::Car(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, const char segment[], int nombrePortes) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    SetSegment(segment);
    m_nombrePortes = nombrePortes;
}

//Getteurs
const char* Car::GetSegment() { return m_segment; }
int Car::GetNombrePortes() { return m_nombrePortes; }

//Setteurs
void Car::SetSegment(const char segment[]) {
    copy(m_segment, segment);
}

void Car::SetNombrePortes(int nombrePortes) { m_nombrePortes = nombrePortes; }

//Affichage des  caractéristiques
void Car::ShowCharacteristics(){
    Vehicle::ShowCharacteristics();
    cout << " - Segment : " << m_segment
         << " - Nombre de portes : " << m_nombrePortes
         <<endl;
}



/*
Classe Dérivée Motorcycle
*/

// Constructeur par défaut
Motorcycle::Motorcycle() : Vehicle() {
    m_typeMoto[0] = '\0';
    m_nombreRoues = 0;
}

// Constructeur avec paramètres
Motorcycle::Motorcycle(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, const char typeMoto[], int nombreRoues) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    SetTypeMoto(typeMoto);
    m_nombreRoues = nombreRoues;
}

//Getteurs
const char* Motorcycle::GetTypeMoto() { return m_typeMoto; }
int Motorcycle::GetNombreRoues() { return m_nombreRoues; }

//Setteurs
void Motorcycle::SetTypeMoto(const char typeMoto[]) {
    copy(m_typeMoto, typeMoto);
}

void Motorcycle::SetNombreRoues(int nombreRoues) { m_nombreRoues = nombreRoues; }

//Affichage des  caractéristiques
void Motorcycle::ShowCharacteristics(){
    Vehicle::ShowCharacteristics();
    cout << " - Type de moto : " << m_typeMoto
         << " - Nombre de roues : " << m_nombreRoues
         <<endl;
}


/*
Classe Dérivée Truck
*/

// Constructeur par défaut
Truck::Truck() : Vehicle() {
    m_chargeUtile = 0;
    m_nombreEssieux = 0;
}

// Constructeur avec paramètres
Truck::Truck(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, int chargeUtile, int nombreEssieux) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    m_chargeUtile = chargeUtile;
    m_nombreEssieux = nombreEssieux;
}

//Getteurs
int Truck::GetChargeUtile() { return m_chargeUtile; }
int Truck::GetNombreEssieux() { return m_nombreEssieux; }

//Setteurs
void Truck::SetChargeUtile(int chargeUtile) { m_chargeUtile = chargeUtile; }
void Truck::SetNombreEssieux(int nombreEssieux) { m_nombreEssieux = nombreEssieux; }

//Affichage des  caractéristiques
void Truck::ShowCharacteristics(){
    Vehicle::ShowCharacteristics();
    cout << " - Charge Utile : " << m_chargeUtile
         << " - Nombre d'Essieux : " << m_nombreEssieux
         <<endl;
}