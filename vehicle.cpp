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

//Fonction de comparaison
bool compare(const char* chaine1, const char* chaine2) {

    while (*chaine1 && *chaine2) { 
        if (*chaine1 != *chaine2)   
            return false;
        chaine1++; 
        chaine2++; 
    }

    return (*chaine1 == '\0' && *chaine2 == '\0');
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
Vehicle::Vehicle(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix) {
    SetImmatriculation(immatriculation);
    SetTypeCarburant(typeCarburant);
    m_annee = annee;
    m_poids = poids;
    m_prix = prix;
}

//Constructeur par copie
Vehicle::Vehicle(Vehicle &vehicule) {
    SetImmatriculation(vehicule.GetImmatriculation());
    SetTypeCarburant(vehicule.GetTypeCarburant());
    m_annee = vehicule.GetAnnee();
    m_poids = vehicule.GetPoids();
    m_prix = vehicule.GetPrix();
}

//Getters
const char* Vehicle::GetImmatriculation() { return m_immatriculation; }

const char* Vehicle::GetTypeCarburant() { return m_typeCarburant; }

int Vehicle::GetAnnee() { return m_annee; }

float Vehicle::GetPoids() { return m_poids; }

int Vehicle::GetPrix() { return m_prix; }

//Setters
void Vehicle::SetImmatriculation(const char *immatriculation) {
    copy(m_immatriculation, immatriculation);
}

void Vehicle::SetTypeCarburant(const char *typeCarburant) {
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
float Vehicle::facteurCarburant(){

    if(compare(m_typeCarburant, "essence")){ return 1.0; }
    else if(compare(m_typeCarburant, "diesel")){ return 1.05; }
    else if(compare(m_typeCarburant, "hybride")){ return 0.9; }
    else if(compare(m_typeCarburant, "electrique")){ return 0.5; }
    else { return 1.0; }

    return 0;
}

float Vehicle::MaintenanceCost(){
    return (0.02 * m_prix + 5 * (2025 - m_annee) + 0.001 * m_poids) * facteurCarburant();
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
Car::Car(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, const char *segment, int nombrePortes) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    SetSegment(segment);
    m_nombrePortes = nombrePortes;
}

// Constructeur par copie
Car::Car(Car &car) : Vehicle(car.GetImmatriculation(), car.GetTypeCarburant(), car.GetAnnee(), car.GetPoids(), car.GetPrix()) 
{
    SetSegment(car.GetSegment());
    m_nombrePortes = car.GetNombrePortes();
}

//Getters
const char* Car::GetSegment() { return m_segment; }
int Car::GetNombrePortes() { return m_nombrePortes; }

//Setters
void Car::SetSegment(const char *segment) {
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

//Calcul du coût d'entretien
float Car::MaintenanceCost() {
    int B_segment, B_portes;

    if(compare(m_segment, "citadine")){ B_segment = 0; }
    else if(compare(m_segment, "berline")){ B_segment = 20; }
    else if(compare(m_segment, "SUV")){ B_segment = 50; }
    else { B_segment = 0; }

    if(m_nombrePortes == 3){ B_portes = -10; }
    else { B_portes = 0; }

    return (0.02 * GetPrix() + 5 * (2025 - GetAnnee()) + 0.001 * GetPoids() + B_segment + B_portes) * facteurCarburant();
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
Motorcycle::Motorcycle(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, const char *typeMoto, int nombreRoues) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    SetTypeMoto(typeMoto);
    m_nombreRoues = nombreRoues;
}

// Constructeur par copie
Motorcycle::Motorcycle(Motorcycle &moto) : Vehicle(moto.GetImmatriculation(), moto.GetTypeCarburant(), moto.GetAnnee(), moto.GetPoids(), moto.GetPrix()) 
{
    SetTypeMoto(moto.GetTypeMoto());
    m_nombreRoues = moto.GetNombreRoues();
}

//Getters
const char* Motorcycle::GetTypeMoto() { return m_typeMoto; }
int Motorcycle::GetNombreRoues() { return m_nombreRoues; }

//Setters
void Motorcycle::SetTypeMoto(const char *typeMoto) {
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

//Calcul du coût d'entretien
float Motorcycle::MaintenanceCost() {
    int B_type, B_roues;

    if(compare(m_typeMoto, "sport")){ B_type = 40; }
    else if(compare(m_typeMoto, "trail") || compare(m_typeMoto, "cross")){ B_type = 20; }
    else if(compare(m_typeMoto, "custom")){ B_type = 10; }
    else { B_type = 0; }

    if(m_nombreRoues >= 3){ B_roues = 20; }
    else { B_roues = 0; }

    return (0.015 * GetPrix() + 3 * (2025 - GetAnnee()) + 0.0005 * GetPoids() + B_type + B_roues) * facteurCarburant();
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
Truck::Truck(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, int chargeUtile, int nombreEssieux) : Vehicle(immatriculation, typeCarburant, annee, poids, prix) 
{
    m_chargeUtile = chargeUtile;
    m_nombreEssieux = nombreEssieux;
}

// Constructeur par copie
Truck::Truck(Truck &truck) : Vehicle(truck.GetImmatriculation(), truck.GetTypeCarburant(), truck.GetAnnee(), truck.GetPoids(), truck.GetPrix()) 
{
    m_chargeUtile = truck.GetChargeUtile();
    m_nombreEssieux = truck.GetNombreEssieux();
}

//Getters
int Truck::GetChargeUtile() { return m_chargeUtile; }
int Truck::GetNombreEssieux() { return m_nombreEssieux; }

//Setters
void Truck::SetChargeUtile(int chargeUtile) { m_chargeUtile = chargeUtile; }
void Truck::SetNombreEssieux(int nombreEssieux) { m_nombreEssieux = nombreEssieux; }

//Affichage des  caractéristiques
void Truck::ShowCharacteristics(){
    Vehicle::ShowCharacteristics();
    cout << " - Charge Utile : " << m_chargeUtile
         << " - Nombre d'Essieux : " << m_nombreEssieux
         <<endl;
}

//Calcul du coût d'entretien
float Truck::MaintenanceCost() {
    return (0.04 * GetPrix() + 8 * (2025 - GetAnnee()) + 0.0015 * GetPoids() + (m_chargeUtile / 100) + 50 * (m_nombreEssieux - 2)) * facteurCarburant();
}

/*
Classe Garage
*/

// Constructeur par défaut
Garage::Garage() {
    m_vehicules = new Vehicle*[m_capacity];
}

//Agrandissement du tableau
void Garage::Growth(){
    if (m_size >= m_capacity) {
        m_capacity += 10;
        Vehicle** temp = new Vehicle*[m_capacity];
        for (int i = 0; i < m_size; i++){
            temp[i] = m_vehicules[i];
        }
        delete[] m_vehicules;
        m_vehicules = temp;
    }
}

//Ajout d'un véhicule
void Garage::AddVehicle(Vehicle* vehicule) {
    Growth();
    m_vehicules[m_size] = vehicule;
    m_size++;
}

//Accès a un élément
Vehicle* Garage::operator[](int index) {
    if (index >= 0 && index < m_size) {
        return m_vehicules[index]; 
    }
    return nullptr;
}

//Destructeur
Garage::~Garage() {
    for(int i = 0; i < m_size; i++) {
        delete m_vehicules[i];
    }

    delete[] m_vehicules;
}