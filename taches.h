#ifndef TACHE_H
#define TACHE_H

#include "membre.h" 

#define MAX_TACHES 100
#define MAX_MEMBRES 100
// Structure de donnees pour la date 

typedef struct {
    int jour;
    int mois;
    int annee;
} Datex;

// Enumeration des statuts
typedef enum {
    EN_ATTENTE,
    EN_COURS,
    TERMINEE
} Statut;

// Declaration des taches
typedef struct {
    int numero;
    char libelle[100];
    float budget;
    Statut statut;
    Datex date_fin;
    Membre responsable;
} Tache;

// Declaration de la structure Gection des taches
typedef struct {
    Tache taches[MAX_TACHES];
    int nb_taches;
} GestionTache;

// Declaration des instances globales de gestion des taches
extern GestionTache gestionTache;

// Prototypes des fonctions
void CreerTache();
void MettreAJourTache();
void Delete_tache();
void SuivreStatuts();
void RappelsTaches();
void charger_Taches();
void sauvegarder_Taches();
void charger_membres();

#endif
