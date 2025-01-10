#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ressource.h"

GestionRessource gestionRessource;

void chargerRessources() {
    FILE *file = fopen("Ressources.txt", "r");
    if (file == NULL) {
        gestionRessource.nb_ressources = 0;
        return;
    }

    gestionRessource.nb_ressources = 0;
    while (fscanf(file, "%d\t%d\t%d\t%d\t%d\t%d", &gestionRessource.ressources[gestionRessource.nb_ressources].type, &gestionRessource.ressources[gestionRessource.nb_ressources].disponibilite, &gestionRessource.ressources[gestionRessource.nb_ressources].quantite, &gestionRessource.ressources[gestionRessource.nb_ressources].date_disponibilite.jour, &gestionRessource.ressources[gestionRessource.nb_ressources].date_disponibilite.mois, &gestionRessource.ressources[gestionRessource.nb_ressources].date_disponibilite.annee) != EOF) {
        gestionRessource.nb_ressources++;
    }

    fclose(file);
}

void sauvegarderRessources() {
    FILE *file = fopen("Ressources.txt", "w");
    if (file == NULL) {
        printf("Erreur d'ouverture du fichier Ressources.txt\n");
        return;
    }

    for (int i = 0; i < gestionRessource.nb_ressources; i++) {
        Ressource r = gestionRessource.ressources[i];
        fprintf(file, "%d\t%d\t%d\t%d\t%d\t%d\n",r.type, r.disponibilite, r.quantite,r.date_disponibilite.jour, r.date_disponibilite.mois, r.date_disponibilite.annee);
    }

    fclose(file);
}

void AjouterRessource() {
    if (gestionRessource.nb_ressources >= MAX_RESSOURCES) {
        printf("Nombre maximum de ressources atteint.\n");
        return;
    }

    Ressource r;
    printf("************AJOUTER UNE RESSOURCE***********\n\n");
    printf("Entrez le type de ressource (0: DON, 1: EQUIPEMENT, 2: FOURNITURE): ");
    scanf("%d", &r.type);
    printf("Entrez la disponibilité de la ressource (0: DISPONIBLE, 1: RESERVE): ");
    scanf("%d", &r.disponibilite);
    printf("Entrez la quantité de la ressource: ");
    scanf("%d", &r.quantite);
    printf("Entrez la date de disponibilité (jour mois année): ");
    scanf("%d %d %d", &r.date_disponibilite.jour, &r.date_disponibilite.mois, &r.date_disponibilite.annee);

    gestionRessource.ressources[gestionRessource.nb_ressources++] = r;
    sauvegarderRessources();

    printf("\nRessource ajoutée avec succès.\n");
    printf("-----------------------------------------------------------------\n");
}

void ReserverRessource() {
    int type, quantite;
    printf("**********RÉSERVER UNE RESSOURCE************\n\n");
    printf("Entrez le type de ressource à réserver (0: DON, 1: EQUIPEMENT, 2: FOURNITURE): ");
    scanf("%d", &type);
    printf("Entrez la quantité à réserver: ");
    scanf("%d", &quantite);

    for (int i = 0; i < gestionRessource.nb_ressources; i++) {
        if (gestionRessource.ressources[i].type == type && gestionRessource.ressources[i].disponibilite == DISPONIBLE && gestionRessource.ressources[i].quantite >= quantite) {
            gestionRessource.ressources[i].quantite -= quantite;
            if (gestionRessource.ressources[i].quantite == 0) {
                gestionRessource.ressources[i].disponibilite = RESERVE;
            }
            sauvegarderRessources();
            printf("\nRessource réservée avec succès.\n");
            printf("-----------------------------------------------------------------\n");
            return;
        }
    }

    printf("Ressource non disponible ou quantité insuffisante.\n");
    printf("-----------------------------------------------------------------\n");
}

void VerifierDisponibilite() {
    printf("***********VÉRIFIER LA DISPONIBILITÉ DES RESSOURCES************\n\n");
    for (int i = 0; i < gestionRessource.nb_ressources; i++) {
        Ressource r = gestionRessource.ressources[i];
        printf("Type: %d\n", r.type);
        printf("Disponibilité: %d\n", r.disponibilite);
        printf("Quantité: %d\n", r.quantite);
        printf("Date de disponibilité: %d-%d-%d\n",  r.date_disponibilite.jour, r.date_disponibilite.mois, r.date_disponibilite.annee);
    }
    printf("-----------------------------------------------------------------\n");
}

void PlanifierUtilisation() {
    printf("**********PLANIFICATION DE L'UTILISATION DES RESSOURCES************\n\n");
    for (int i = 0; i < gestionRessource.nb_ressources; i++) {
        Ressource r = gestionRessource.ressources[i];
        if (r.disponibilite == DISPONIBLE) {
            printf("Type: %d\n",r.type);
            printf("Quantité: %d\n", r.quantite);
            printf("Date de disponibilité: %d-%d-%d\n", r.date_disponibilite.jour, r.date_disponibilite.mois, r.date_disponibilite.annee);
        }
    }
    printf("-----------------------------------------------------------------\n");
}

void SuivreUtilisation() {
    printf("************SUIVI DE L'UTILISATION DES RESSOURCES**************\n\n");
    for (int i = 0; i < gestionRessource.nb_ressources; i++) {
        Ressource r = gestionRessource.ressources[i];
        printf("Type: %d\n", r.type);
        printf("Quantité restante: %d\n", r.quantite);
        printf("Date de disponibilité: %d-%d-%d\n", r.date_disponibilite.jour, r.date_disponibilite.mois, r.date_disponibilite.annee);
        printf("Disponibilité: %d\n", r.disponibilite);
    }
    printf("-----------------------------------------------------------------\n");
}

