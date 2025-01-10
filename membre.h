#ifndef MEMBRE_H
#define MEMBRE_H

#define MAX_MEMBRE 100

typedef struct{
	char adresse[50];
	char telephone[50];
	char email[50];
} Coordonnees;


typedef struct{
	int numero;
	char nom[50];
	char prenom[50];
	char roles[50];
	Coordonnees coordonnees;
	char horaires[50];
	float montant_adhesion[3];
	int nom_tranches;
} Membre;


// Prototypes des fonctions
void Ajouter_Membre();
void Modifier_Membre();
void Supprimer_Membre();
void Rechercher_Membre();
void Afficher_Tous_LesMembres();


#endif
