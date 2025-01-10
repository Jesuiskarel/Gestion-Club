#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "taches.h"

GestionTache gestionTache = { .nb_taches = 0 };
Membre membres[MAX_MEMBRES];
int nb_membres = 0;


void charger_membres() {
    FILE *fichier = fopen("Membres.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier Membres.txt\n");
        return;
    }

    nb_membres = 0;
    while (fscanf(fichier, "%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f", &membres[nb_membres].numero, membres[nb_membres].nom, membres[nb_membres].prenom, membres[nb_membres].roles, membres[nb_membres].coordonnees.adresse, membres[nb_membres].coordonnees.telephone, membres[nb_membres].coordonnees.email, membres[nb_membres].horaires, &membres[nb_membres].nom_tranches, &membres[nb_membres].montant_adhesion[0], &membres[nb_membres].montant_adhesion[1], &membres[nb_membres].montant_adhesion[2]) == 12) {
        nb_membres++;
    }
    fclose(fichier);
}

void charger_Taches() {
    FILE *fichier = fopen("Taches.txt", "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier Taches.txt\n");
        return;
    }

    gestionTache.nb_taches = 0;
    while (fscanf(fichier, "%d\t%s\t%f\t%d\t%d\t%d\t%d\t%d\t%s\t%s", &gestionTache.taches[gestionTache.nb_taches].numero, gestionTache.taches[gestionTache.nb_taches].libelle, &gestionTache.taches[gestionTache.nb_taches].budget, (int*)&gestionTache.taches[gestionTache.nb_taches].statut, &gestionTache.taches[gestionTache.nb_taches].date_fin.jour, &gestionTache.taches[gestionTache.nb_taches].date_fin.mois, &gestionTache.taches[gestionTache.nb_taches].date_fin.annee, &gestionTache.taches[gestionTache.nb_taches].responsable.numero, gestionTache.taches[gestionTache.nb_taches].responsable.nom, gestionTache.taches[gestionTache.nb_taches].responsable.prenom) == 10) {
        gestionTache.nb_taches++;
    }
    fclose(fichier);
}

void sauvegarder_Taches() {
    FILE *fichier = fopen("Taches.txt", "w");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier Taches.txt\n");
        return;
    }

    for (int i = 0; i < gestionTache.nb_taches; i++) {
        Tache t = gestionTache.taches[i];
        fprintf(fichier, "%d\t%s\t%.2f\t%d\t%d\t%d\t%d\t%d\t%s\t%s\n", t.numero, t.libelle, t.budget, t.statut, t.date_fin.jour, t.date_fin.mois, t.date_fin.annee, t.responsable.numero, t.responsable.nom, t.responsable.prenom);
    }
    fclose(fichier);
}

void CreerTache() {
    if (gestionTache.nb_taches >= MAX_TACHES) {
        printf("Nombre maximum de tâches atteint.\n");
        return;
    }

    Tache tache;
    tache.numero = gestionTache.nb_taches + 1;

    printf("***********CRÉER UNE TÂCHE*************\n\n");
    printf("Entrez le libellé de la tâche : ");
    scanf(" %s", tache.libelle);
    printf("Entrez le budget de la tâche : ");
    scanf("%f", &tache.budget);
    printf("Entrez la date de fin (jour mois année) : ");
    scanf("%d %d %d", &tache.date_fin.jour, &tache.date_fin.mois, &tache.date_fin.annee);
    tache.statut = EN_ATTENTE;

    // Simplement attribuer le premier membre comme responsable (à améliorer)
    if (nb_membres > 0) {
        tache.responsable = membres[0];
    } else {
        printf("Aucun membre disponible pour être responsable.\n");
        return;
    }

    gestionTache.taches[gestionTache.nb_taches++] = tache;
    sauvegarder_Taches();

    printf("\nTâche créée avec succès.\n");
    printf("-----------------------------------------------------------------\n");
}

void MettreAJourTache() {
    int numero;
    printf("**********METTRE À JOUR UNE TÂCHE************\n\n");
    printf("Entrez le numéro de la tâche à mettre à jour : ");
    scanf("%d", &numero);

    for (int i = 0; i < gestionTache.nb_taches; i++) {
        if (gestionTache.taches[i].numero == numero) {
            printf("Entrez le nouveau libellé de la tâche : ");
            scanf(" %s", gestionTache.taches[i].libelle);
            printf("Entrez le nouveau budget de la tâche : ");
            scanf("%f", &gestionTache.taches[i].budget);
            printf("Entrez la nouvelle date de fin (jour mois année) : ");
            scanf("%d %d %d", &gestionTache.taches[i].date_fin.jour, &gestionTache.taches[i].date_fin.mois, &gestionTache.taches[i].date_fin.annee);
            printf("Entrez le nouveau statut de la tâche (0: EN_ATTENTE, 1: EN_COURS, 2: TERMINEE) : ");
            int statut;
            scanf("%d", &statut);
            gestionTache.taches[i].statut = (Statut)statut;

            sauvegarder_Taches();

            printf("\nTâche mise à jour avec succès.\n");
            printf("-----------------------------------------------------------------\n");
            return;
        }
    }

    printf("Tâche non trouvée.\n");
    printf("-----------------------------------------------------------------\n");
}

void Delete_tache() {
    int numero;
    printf("************SUPPRIMER UNE TÂCHE************\n\n");
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &numero);

    for (int i = 0; i < gestionTache.nb_taches; i++) {
        if (gestionTache.taches[i].numero == numero) {
            for (int j = i; j < gestionTache.nb_taches - 1; j++) {
                gestionTache.taches[j] = gestionTache.taches[j + 1];
            }
            gestionTache.nb_taches--;
            sauvegarder_Taches();
            printf("\nTâche supprimée avec succès.\n");
            printf("-----------------------------------------------------------------\n");
            return;
        }
    }

    printf("Tâche non trouvée.\n");
    printf("-----------------------------------------------------------------\n");
}

void SuivreStatuts() {
    printf("**********SUIVI DES STATUTS DES TÂCHES************\n\n");

    for (int i = 0; i < gestionTache.nb_taches; i++) {
        Tache t = gestionTache.taches[i];
        printf("Numéro: %d\n", t.numero);
        printf("Libellé: %s\n", t.libelle);
        printf("Budget: %.2f\n", t.budget);
        printf("Statut: %d\n",t.statut);
        printf("Date de fin: %d-%d-%d\n",t.date_fin.jour, t.date_fin.mois, t.date_fin.annee);
        printf("Responsable: %s %s\n", t.responsable.nom, t.responsable.prenom);
    }

    printf("\n-----------------------------------------------------------------\n");
}

void RappelsTaches() {
    printf("***********RAPPELS DES TÂCHES***********\n\n");

    // Déterminer la date actuelle
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    Datex date_actuelle = {
        .jour = tm_now->tm_mday,
        .mois = tm_now->tm_mon + 1,
        .annee = tm_now->tm_year + 1900
    };

    for (int i = 0; i < gestionTache.nb_taches; i++) {
        Tache t = gestionTache.taches[i];

        // Comparer la date actuelle avec la date de fin de la tâche
        if ((t.date_fin.annee < date_actuelle.annee) ||
            (t.date_fin.annee == date_actuelle.annee && t.date_fin.mois < date_actuelle.mois) ||
            (t.date_fin.annee == date_actuelle.annee && t.date_fin.mois == date_actuelle.mois && t.date_fin.jour < date_actuelle.jour)) {
            printf("La tâche %d (%s) est en retard !\n", t.numero, t.libelle);
        } else if ((t.date_fin.annee == date_actuelle.annee && t.date_fin.mois == date_actuelle.mois && t.date_fin.jour == date_actuelle.jour)) {
            printf("La tâche %d (%s) doit être terminée aujourd'hui !\n", t.numero, t.libelle);
        }
    }

    printf("\n-----------------------------------------------------------------\n");
}

