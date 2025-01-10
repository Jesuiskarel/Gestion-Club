#ifndef FINANCE_H
#define FINANCE_H

#define MAX_TRANSACTION 100

typedef struct{
	int jour;
	int mois;
	int annee;
} Dates;

typedef struct{
	int id; // identifiant unique pour chaque transaction
	float montant;
	char description[100];
	Dates date;
} Transaction;

typedef struct{
	Transaction cotisations[MAX_TRANSACTION];
	int nb_cotisations;
	Transaction depenses[MAX_TRANSACTION];
	int nb_depenses;
} Budget;

// Prototypes des fonctions
void Ajouter_cotisation();
void Ajouter_depense();
void Suivi_cotisation();
void Suivi_depense();
void Generation_des_rapports();
void Generation_des_statistiques();


#endif 
