#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Pour usleep sur Linux
#include "membre.h"
#include "taches.h"
#include "ressource.h"
#include "finance.h"

#ifdef _WIN32
#include <windows.h> // Pour Sleep sur Windows
#define usleep(x) Sleep((x)/1000)
#endif

void afficherBienvenue()
{
	char *message = "BIENVENUE DANS NOTRE PROGRAMME DE GESTION DE CLUB";
	int len = strlen(message);
	
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		printf(" %c", message[i]);
		fflush(stdout);
		usleep(50000);
	}
	printf("\n\n");
}

void afficherAuRevoir()
{
	char *message = "Merci d'avoir utilise notre Programme. AU REVOIR!!!";
	int len = strlen(message);
	
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		printf("%c", message[i]);
		fflush(stdout);
		usleep(50000);
	}
	printf("\n\n");
}

void afficherMenuPrincipal()
{
	printf("*********************M E N U   P R I N C I P A L************************\n\n");
	printf("1. Gestion des Membres.\n");
	printf("2. Gestion des Taches.\n");
	printf("3. Gestion des Ressources.\n");
	printf("4. Gestion des Finances.\n");
	printf("0. Quitter\n");
	printf("Entrez votre choix: ");
}

void afficherMenuMembre()
{
	printf("**************M E N U   D E   G E S T I O N   D E S   M E M B R E S**********\n\n");
	printf("1. Ajouer un Membre.\n");
	printf("2. Afficher un Membre.\n");
	printf("3. Supprimer un Membre.\n");
	printf("4. Modifier un Membre.\n");
	printf("5. Rechercher un Membre.\n");
	printf("0. Retour au Menu Principal.\n");
	printf("Entrez votre choix: ");
}

void afficherMenuTache()
{
	printf("***********M E N U   D E   G E S T I O N   D E S   T A C H E S************\n\n");
	printf("1. Creer une Tache.\n");
	printf("2. Mettre a jour une tache.\n");
	printf("3. Supprimer une tache.\n");
	printf("4. Suivre les statuts des taches.\n");
	printf("5. Rappels des taches.\n");
	printf("0. Retour au Menu Principal.\n");
	printf("Entrez votre choix: ");
}

void afficherMenuRessource()
{
	printf("***********M E N U   D E   G E S T I O N   D E S   R E S S O U R C E S***********\n\n");
	printf("1. Ajouter une Ressource.\n");
	printf("2. Reserver unne Ressource.\n");
	printf("3. Verifier la disponibilite des ressources.\n");
	printf("4. Planifier l'utilisation des ressources.\n");
	printf("5. Suivre l'utilisation des ressources.\n");
	printf("0. Retour au Menu Principal.\n");
	printf("Entrez votre choix: ");
}

void afficherMenuFinance()
{
	printf("************M E N U   D E   G E S T I O N   D E S   F I N A N C E S************\n\n");
	printf("1. Ajouter une Cotisation.\n");
	printf("2. Ajouter une Depense.\n");
	printf("3. Suivre des Cotisations.\n");
	printf("4. Suivre des Depenses.\n");
	printf("5. Generation des Rapports.\n");
	printf("6. Generation des Statistiques.\n");
	printf("0. Retour au Menu Principal.\n");
	printf("Entrez votre choix: ");
}
int main()
{
	int choix_principal, choix_membre, choix_tache, choix_ressource, choix_finance;
	charger_Taches();
	chargerRessources();
	charger_membres();
	
	
	printf("*******************************************************************************\n");
	printf("*******************************************************************************\n");
	afficherBienvenue();
	
	
	do
	{
		afficherMenuPrincipal();
		scanf("%d", &choix_principal);
		
		switch(choix_principal)
		{
			case 1:
				system("clear");
				do
				{
					afficherMenuMembre();
					scanf("%d", &choix_membre);
					
					switch(choix_membre)
					{
						case 1:
							system("clear");
							Ajouter_Membre();
							break;
						case 2:
							system("clear");
							Afficher_Tous_LesMembres();
							break;
						case 3:
							system("clear");
							Supprimer_Membre();
							break;
						case 4:
							system("clear");
							Modifier_Membre();
							break;
						case 5:
							system("clear");
							Rechercher_Membre();
							break;
						case 0:
							system("clear");
							printf("Retour au Menu Principal.\n");
							break;
						default:
							printf("Choix invalide, Veuillez ressayer.\n");
					}
				}while(choix_membre != 0);
				break;
			case 2:
				system("clear");
				do
				{
					afficherMenuTache();
					scanf("%d", &choix_tache);
					
					switch(choix_tache)
					{
						case 1:
							system("clear");
							CreerTache();
							break;
						case 2:
							system("clear");
							MettreAJourTache();
							break;
						case 3:
							system("clear");
							Delete_tache();
							break;
						case 4:
							system("clear");
							SuivreStatuts();
							break;
						case 5:
							system("clear");
							RappelsTaches();
							break;
						case 0:
							system("clear");
							printf("Retour au Menu Principal.\n");
							break;
						default:
							printf("Choix invalide, Veuillez ressayer.\n");
					}
				}while(choix_tache != 0);
				break;
			case 3:
				system("clear");
				do
				{
					afficherMenuRessource();
					scanf("%d", &choix_ressource);
					
					switch(choix_ressource)
					{
						case 1:
							system("clear");
							AjouterRessource();
							break;
						case 2:
							system("clear");
							ReserverRessource();
							break;
						case 3:
							system("clear");
							VerifierDisponibilite();
							break;
						case 4:
							system("clear");
							PlanifierUtilisation();
							break;
						case 5:
							system("clear");
							SuivreUtilisation();
							break;
						case 0:
							system("clear");
							printf("Retour au Menu Principal.\n");
							break;
						default:
							printf("Choix invalide, Veuillez ressayer.\n");
					}
				}while(choix_ressource != 0);
				break;
			case 4:
				system("clear");
				do
				{
					afficherMenuFinance();
					scanf("%d", &choix_finance);
					
					switch(choix_finance)
					{
						case 1:
							system("clear");
							Ajouter_cotisation();
							break;
						case 2:
							system("clear");
							Ajouter_depense();
							break;
						case 3:
							system("clear");
							Suivi_cotisation();
							break;
						case 4:
							system("clear");
							Suivi_depense();
							break;
						case 5:
							system("clear");
							Generation_des_rapports();
							break;
						case 6:
							system("clear");
							Generation_des_statistiques();
							break;
						case 0:
							system("clear");
							printf("Retour au Menu Principal.\n");
							break;
						default:
							printf("Choix invalide, Veuillez ressayer.\n");
					}
				}while(choix_finance != 0);
				break;
			case 0:
				system("clear");
				afficherAuRevoir();			
				break;
			default: 
				printf("Choix invalide, Veuillez ressayer.\n");
		}
		
	}while(choix_principal != 0);
	
	
	return 0;
}
