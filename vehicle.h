#ifndef __VEHICLE_H__
#define __VEHICLE_H__

//Fonction de copie
void copy(char *dest, const char *source);

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
        Vehicle(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix);
        
        //Getteurs
        const char* GetImmatriculation();
        const char* GetTypeCarburant();
        int GetAnnee();
        float GetPoids();
        int GetPrix();

        //Setteurs
        void SetImmatriculation(const char immatriculation[]);
        void SetTypeCarburant(const char typeCarburant[]);
        void SetAnnee(int annee);
        void SetPoids(float poids);
        void SetPrix(int prix);

        //Affichage des  caractéristiques
        virtual void ShowCharacteristics();

        //Calcul du cout d'entretien
        virtual float MaintenanceCost();

        //Destructeur
        ~Vehicle(){}
};

class Car : public Vehicle{
    private:
        char m_segment[20];
        int m_nombrePortes;
    public:
        //Constructeurs
        Car();
        Car(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, const char segment[], int nombrePortes);

        //Getteurs
        const char* GetSegment();
        int GetNombrePortes();

        //Setteurs
        void SetSegment(const char segment[]);
        void SetNombrePortes(int nombrePortes);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        virtual float MaintenanceCost() override;

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
        Motorcycle(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, const char typeMoto[], int nombreRoues);
        
        //Getteurs
        const char* GetTypeMoto();
        int GetNombreRoues();

        //Setteurs
        void SetTypeMoto(const char typeMoto[]);
        void SetNombreRoues(int nombreRoues);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        virtual float MaintenanceCost() override;
        
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
        Truck(const char immatriculation[], const char typeCarburant[], int annee, float poids, int prix, int chargeUtile, int nombreEssieux);
        
        //Getteurs
        int GetChargeUtile();
        int GetNombreEssieux();

        //Setteurs
        void SetChargeUtile(int chargeUtile);
        void SetNombreEssieux(int nombreEssieux);

        //Affichage des  caractéristiques
        void ShowCharacteristics() override;

        //Calcul du cout d'entretien
        virtual float MaintenanceCost() override;
        
        //Destructeur
        ~Truck(){}
};

#endif