#ifndef RESSOURCE_H
#define RESSOURCE_H

#define MAX_RESSOURCES 100

typedef enum {
    DON,
    EQUIPEMENT,
    FOURNITURE
} TypeRessource;

typedef enum {
    DISPONIBLE,
    RESERVE
} Disponibilite;

typedef struct Date{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct Ressource{
    TypeRessource type;
    Disponibilite disponibilite;
    int quantite;
    Date date_disponibilite;
} Ressource;

typedef struct GestionRessource{
    Ressource ressources[MAX_RESSOURCES];
    int nb_ressources;
} GestionRessource;

// Global instance of GestionRessource
extern GestionRessource gestionRessource;

// Function prototypes
void chargerRessources();
void sauvegarderRessources();
void AjouterRessource();
void ReserverRessource();
void VerifierDisponibilite();
void PlanifierUtilisation();
void SuivreUtilisation();

#endif
