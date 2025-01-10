#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "finance.h"
#include "membre.h"

Budget budget = {.nb_cotisations = 0, .nb_depenses = 0};

void Ajouter_cotisation()
{
	FILE *fichier;
	fichier = fopen("Finance.txt", "a");
	if(fichier == NULL){
        	printf("Impossible d'ouvrir le fichier\n");
        	exit(1);
    	}
	
	printf("*********AJOUTER UNE COTISATION***********\n\n");
	if(budget.nb_cotisations >= MAX_TRANSACTION)
	{
		printf("Nombre maximum de cotisations atteint.\n");
		return;
	}
	
	Transaction cotisation;
	cotisation.id = budget.nb_cotisations + 1;
	
	
	printf("Entreez le montant de la cotisation : ");
	scanf("%f", &cotisation.montant);
	printf("Entreez la description de la cotisation : ");
	scanf(" %s", cotisation.description);
	printf("Entreez la date(jour mois annee) : ");
	scanf(" %d %d %d", &cotisation.date.jour, &cotisation.date.mois, &cotisation.date.annee);
	
	budget.cotisations[budget.nb_cotisations++] = cotisation;
	
	fprintf(fichier,"%.2f\t%s\t%d\t%d\t%d\n", &cotisation.montant, cotisation.description, &cotisation.date.jour, &cotisation.date.mois, &cotisation.date.annee);
	fclose(fichier);
	
	printf("\nCotisation ajoutee avec succes.\n");
	printf("-------------------------------------\n");
}

void Ajouter_depense()
{
	FILE *fichier;
	fichier = fopen("Finance.txt", "a");
	if(fichier == NULL){
        	printf("Impossible d'ouvrir le fichier\n");
        	exit(1);
    	}
	
	printf("********AJOUTER UNE DEPENSE*********\n\n");
	if(budget.nb_depenses >= MAX_TRANSACTION)
	{
		printf("Nombre maximum de cotisations atteint.\n");
		return;
	}
	
	Transaction depense;
	depense.id = budget.nb_depenses + 1;
	
	
	printf("Entreez le montant de la depense : ");
	scanf("%f", &depense.montant);
	printf("Entreez la description de la depense : ");
	scanf(" %s", depense.description);
	printf("Entreez la date(jour mois annee) : ");
	scanf(" %d %d %d", &depense.date.jour, &depense.date.mois, &depense.date.annee);
	
	budget.depenses[budget.nb_depenses++] = depense;
	
	fprintf(fichier,"%.2f\t%s\t%d/%d/%d\n", &depense.montant, depense.description, &depense.date.jour, &depense.date.mois, &depense.date.annee);
	fclose(fichier);
	
	printf("\nCotisation ajoutee avec succes.\n");
	printf("-------------------------------------\n");
}

void Suivi_cotisation()
{
	printf("********SUIVI DES COTISATIONS***********\n\n");
	
	for(int i = 0; i < budget.nb_cotisations; i++)
	{
		Transaction c = budget.cotisations[i];
		printf("ID: %d\n", c.id);
		printf("Montant: %.2f\n", c.montant);
		printf("Description: %s\n", c.description);
		printf("Date: %d-%d-%d\n", c.date.jour, c.date.mois, c.date.annee);
	}
	
	printf("\n---------------------------------\n");
}

void Suivi_depense()
{
	printf("*********SUIVI DES DEPENSES*********\n\n");
	
	for(int i = 0; i < budget.nb_depenses; i++)
	{
		Transaction c = budget.depenses[i];
		printf("ID: %d\n", c.id);
		printf("Montant: %.2f\n", c.montant);
		printf("Description: %s\n", c.description);
		printf("Date: %d-%d-%d\n", c.date.jour, c.date.mois, c.date.annee);
	}
	
	printf("\n---------------------------------\n");
}


void Generation_des_rapports()
{
	printf("*********GENERATION DES RAPPORTS*********\n\n");
	
	float total_cotisation = 0;
	float total_depense = 0;
	
	for(int i = 0; i < budget.nb_cotisations; i++)
	{
		total_cotisation += budget.cotisations[i].montant;
	}
	
	for(int i = 0; i < budget.nb_depenses; i++)
	{
		total_depense += budget.depenses[i].montant;
	}
	
	printf("Rapport financier:\n");
	printf("Total des cotisations: %.2f\n", total_cotisation);
	printf("Total des depenses: %.2f\n", total_depense);
	printf("Solde actuel: %.2f\n", total_cotisation - total_depense);
	
	FILE *fichier = fopen("Membres.txt", "r");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		exit(1);
	}
	
	printf("\nMembres n'ayant pas paye la totalite de leurs frais d'inscription :\n");
	
	Membre membre;
	float somme = 5000;
	while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f\t\n", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
	{
		float total_adhesion = 0;
		for(int i = 0; i < membre.nom_tranches; i++)
		{
			total_adhesion += membre.montant_adhesion[i];
		}
		if(total_adhesion < somme)
		{
			printf("Membre: %s %s\n", membre.nom, membre.prenom);
			printf("Total paye: %.2f, Total du: %.2f", total_adhesion, somme - total_adhesion);
			break;
		}
	}
	fclose(fichier);
	
	printf("\n----------------------------------------\n");
}


void Generation_des_statistiques()
{
	printf("*********GENERATION DES STATISTIQUES***********\n\n");
	
	float moyenne_cotisation = 0;
	if(budget.nb_cotisations > 0)
	{
		for(int i = 0; i < budget.nb_cotisations; i++)
		{
			moyenne_cotisation += budget.cotisations[i].montant;
		}
		moyenne_cotisation /= budget.nb_cotisations;
	}
	
	float moyenne_depense = 0;
	if(budget.nb_depenses > 0)
	{
		for(int i = 0; i < budget.nb_depenses; i++)
		{
			moyenne_depense += budget.depenses[i].montant;
		}
		moyenne_depense /= budget.nb_depenses;
	}
	
	printf("Nombre de cotisations : %d\n", budget.nb_cotisations);
	printf("Moyenne des cotisations : %.2f\n", moyenne_cotisation);
	printf("Nombre de depenses : %d\n", budget.nb_depenses);
	printf("Moyenne des depenses : %.2f\n", moyenne_depense);
	
	printf("\n------------------------------------------\n");
}
