#ifndef __VEHICLE_H__
#define __VEHICLE_H__

//Fonction de copie
void copy(char *dest, const char *source);

//Fonction de comparaison
bool compare(const char* chaine1, const char* chaine2);

class Vehicle{
    private:
        char m_immatriculation[10];
        char m_typeCarburant[20];
        int m_annee;
        float m_poids;
        int m_prix;
    public:
        //Constructeurs
        Vehicle();
        Vehicle(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix);
        Vehicle(Vehicle &vehicule);

        //Getters
        const char* GetImmatriculation();
        const char* GetTypeCarburant();
        int GetAnnee();
        float GetPoids();
        int GetPrix();

        //Setters
        void SetImmatriculation(const char *immatriculation);
        void SetTypeCarburant(const char *typeCarburant);
        void SetAnnee(int annee);
        void SetPoids(float poids);
        void SetPrix(int prix);

        //Affichage des  caractéristiques
        virtual void ShowCharacteristics();

        //Calcul du cout d'entretien
        float facteurCarburant();
        virtual float MaintenanceCost();

        //Vérification du format des immatriculations
        bool VerifyImmatriculation(const char *immatriculation);

        //Destructeur
        virtual ~Vehicle(){}
};

class Car : public Vehicle{
    private:
        char m_segment[20];
        int m_nombrePortes;
    public:
        //Constructeurs
        Car();
        Car(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, const char *segment, int nombrePortes);
        Car(Car &car);

        //Getters
        const char* GetSegment();
        int GetNombrePortes();

        //Setters
        void SetSegment(const char *segment);
        void SetNombrePortes(int nombrePortes);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        float MaintenanceCost() override;

        //Destructeur
        ~Car(){}
};

class Motorcycle : public Vehicle{
    private:
        char m_typeMoto[20];
        int m_nombreRoues;
    public:
        //Constructeurs
        Motorcycle();
        Motorcycle(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, const char *typeMoto, int nombreRoues);
        Motorcycle(Motorcycle &moto);

        //Getters
        const char* GetTypeMoto();
        int GetNombreRoues();

        //Setters
        void SetTypeMoto(const char *typeMoto);
        void SetNombreRoues(int nombreRoues);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        float MaintenanceCost() override;
        
        //Destructeur
        ~Motorcycle(){}
};

class Truck : public Vehicle{
    private:
        int m_chargeUtile;
        int m_nombreEssieux;
    public:
        //Constructeurs
        Truck();
        Truck(const char *immatriculation, const char *typeCarburant, int annee, float poids, int prix, int chargeUtile, int nombreEssieux);
        Truck(Truck &truck);

        //Getters
        int GetChargeUtile();
        int GetNombreEssieux();

        //Setters
        void SetChargeUtile(int chargeUtile);
        void SetNombreEssieux(int nombreEssieux);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        float MaintenanceCost() override;
        
        //Destructeur
        ~Truck(){}
};

class Garage{
    private:
        Vehicle** m_vehicules;
        int m_size = 0;
        int m_capacity = 10;
    public:
        //Constructeurs
        Garage();

        //Agrandissement du tableau
        void Growth(); 

        //Ajout d'un véhicule
        void AddVehicle(Vehicle* vehicule);

        //Accès a un élément
        Vehicle* operator[](int index);

        //Affichage des caractéristiques de chaque véhicule
        void showVehicle();

        //Recherche d'un véhicule
        Vehicle* VehicleSearch(const char* immat);

        //Calcul du coût d'entretien d'un véhicule
        void CostCalculation(int index);

        //Destructeur
        ~Garage();
};

#endif