#include "membre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void Ajouter_Membre()
{
	Membre membre;
	FILE *fichier;
	fichier = fopen("Membres.txt", "a");
	if(fichier == NULL){
        	printf("Impossible d'ouvrir le fichier\n");
        	exit(1);
    	}

	printf("************AJOUTER DES MEMBRES************\n\n");
	
	float somme = 0;
	
	printf("Entrez le numero du Membre : ");
	scanf("%d", &membre.numero);
	printf("Entrez le nom du Membre : ");
	scanf("%s", membre.nom);
	printf("Entrez le prenom du Membre : ");
	scanf("%s", membre.prenom);
	printf("Entrez le role du Membre : ");
	scanf("%s", membre.roles);
	printf("Entrez les coordonnees du Membre : \n\n");
	printf("Saisissez l'adresse du membre : ");
	scanf("%s", membre.coordonnees.adresse);
	printf("Saisissez le telephone du membre : ");
	scanf("%s", membre.coordonnees.telephone);
	printf("Saisissez l'email du membre : ");
	scanf("%s", membre.coordonnees.email);
	printf("Entrez les horaires du Membre : ");
	scanf("%s", membre.horaires);
	do
	{
		printf("Combien de tranche : ");
		scanf("%d", &membre.nom_tranches);
	}while(membre.nom_tranches <= 0 || membre.nom_tranches > 3);
		
	for(int j=0;j<membre.nom_tranches;j++)
	{
		printf("Entrez le montant d'adhesion du Membre %s %s : ", membre.nom, membre.prenom);
		scanf("%f", &membre.montant_adhesion[j]);
		somme += membre.montant_adhesion[j];
	}
	
	
	
	fprintf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n", membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, membre.nom_tranches, membre.montant_adhesion[0], membre.montant_adhesion[1], membre.montant_adhesion[2], somme);
	
	fclose(fichier);
	
	printf("\n");
    	printf("Le membre %s %s a ete ajoutes avec succes.\n", membre.nom, membre.prenom);
    	printf("\n\n");
    	printf("-----------------------------------------------------------------\n");
}



void Modifier_Membre()
{
	int numeroMembre;
	int choix;
	FILE *fichier;
	Membre membre;
	fichier = fopen("Membres.txt", "r+");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		exit(1);
	}
	
	printf("************MODIFIER LES INFORMATIONS D'UN MEMBR************\n\n");
	
	printf("Entrez le numero du membre a modifier : ");
	scanf("%d", &numeroMembre);
	
	while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f\n", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
	{
		if(membre.numero == numeroMembre)
		{
			printf("Membre %d trouve.\n", membre.numero);
			printf("Que souhaitez-vous modifier ?\n");
			printf("1. Nom.\n");
			printf("2. Prenom.\n");
			printf("3. Role.\n");
			printf(" Coordonnees.\n");
			printf("4. Adresse\n");
			printf("5. Telephone\n");
			printf("6. Email\n");
			printf("7. Horaires.\n");
			printf("8. Montant adhesion.\n");
			printf("Entrez votre choix : ");
			scanf("%d", &choix);
			
			switch(choix)
			{
				case 1: 
					printf("Entrez le nouveau nom  : ");
					scanf("%s", membre.nom);
				break;
				case 2: 
					printf("Entrez le nouveau prenom  : ");
					scanf("%s", membre.prenom);
				break;
				case 3: 
					printf("Entrez le nouveau role  : ");
					scanf("%s", membre.roles);
				break;
				case 4: 
					printf("Entrez la nouvelle adresse  : ");
					scanf("%s", membre.coordonnees.adresse);
				break;
				case 5: 
					printf("Entrez le nouveau telephone  : ");
					scanf("%s", membre.coordonnees.telephone);
				break;
				case 6: 
					printf("Entrez le nouvel email  : ");
					scanf("%s", membre.coordonnees.email);
				break;
				case 7: 
					printf("Entrez les nouveaux horaires  : ");
					scanf("%s", membre.horaires);
				break;
				case 8: 
					float somme = 0;
					for(int j=0;j<membre.nom_tranches;j++)
					{
						printf("Entrez le nouveau montant d'adhesion pour la tranche %d :", j+1);
						scanf("%f", &membre.montant_adhesion[j]);
						somme += membre.montant_adhesion[j];
					}
					printf("La somme totale des adhesions pour le membre %d a ete mise a jour a %.2f.\n", numeroMembre, somme);
				break;
				default :
					printf("Choix invalide.\n");
				break;
			}
			fseek(fichier, -1 * sizeof(float) * 4 + sizeof(int) + sizeof(char) * 250, SEEK_CUR); // Se positionner au debut de la ligne a modifier
			fprintf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n", membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, membre.nom_tranches, membre.montant_adhesion[0], membre.montant_adhesion[1], membre.montant_adhesion[2]);
			printf("Les informations ont ete mises a jour.\n");
			break;
		}
		
	}
	
	fclose(fichier);
}



void Supprimer_Membre()
{
	int numeroMembre;
	FILE *fichier, *tempFichier;
	Membre membre;
	
	fichier = fopen("Membres.txt", "r");
	tempFichier = fopen("temp.txt", "w");
	
	if(fichier == NULL || tempFichier == NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		exit(1);
	}
	
	
	printf("************SUPPRIMER UN MEMBRE************\n\n");
	
	printf("Entrez le numero du membre a supprimer : ");
	scanf("%d", &numeroMembre);
	
	while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f\n", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
	{
		if(membre.numero != numeroMembre)
		{
			fprintf(tempFichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%.2f\t%.2f\t%.2f\n", membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, membre.nom_tranches, membre.montant_adhesion[0], membre.montant_adhesion[1], membre.montant_adhesion[2]);
		}
	}
	
	fclose(fichier);
	fclose(tempFichier);
	
	
	remove("Membres.txt");
	rename("temp.txt", "Membres.txt");
	
	printf("\nLe membre avec le numero %d a ete supprime avec succes.\n", numeroMembre);
}


void Rechercher_Membre()
{
	int numeroMembre;
	char nomMembre[50];
	char choix[10];
	FILE *fichier;
	Membre membre;
	
	fichier = fopen("Membres.txt", "r");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		exit(1);
	}
	
	printf("************RECHERCHER UN MEMBRE************\n\n");
	
	printf("Souhaitez-vous rechercher par numero (N) ou par nom (M) ? ");
	scanf("%s", choix);
	if(strcmp(choix, "N") == 0)
	{
		printf("Entrez le numero du membre a rechercher : ");
		scanf("%d", &numeroMembre);
		
		while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f\n", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
		{
			if(membre.numero == numeroMembre)
			{
				
				printf("Membre trouve :\n");
				printf("Numero : %d\n", membre.numero);
				printf("Nom : %s\n", membre.nom);
				printf("Prenom : %s\n", membre.prenom);
				printf("Role : %s\n", membre.roles);
				printf("Adresse : %s\n", membre.coordonnees.adresse);
				printf("Telephone : %s\n", membre.coordonnees.telephone);
				printf("Email : %s\n", membre.coordonnees.email);
				printf("Horaires : %s\n", membre.horaires);
			
				printf("Nombre de tranches : %d\n", membre.nom_tranches);
				for(int i=0;i<membre.nom_tranches;i++)
				{
					printf("Montant d'adhesion N°%d : %.2f\n", i+1, membre.montant_adhesion[i]);
				}
				break;
			}else{
				printf("Aucun membre avec ce numero.\n");
				break;
			}
		}
	} else if(strcmp(choix, "M") == 0){
		printf("Entrez le nom du membre : ");
		scanf("%s", nomMembre);
		
		while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f\n", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
	{
		if(strcmp(membre.nom, nomMembre) == 0)
		{
			printf("Membre trouve :\n");
			printf("Numero : %d\n", membre.numero);
			printf("Nom : %s\n", membre.nom);
			printf("Prenom : %s\n", membre.prenom);
			printf("Role : %s\n", membre.roles);
			printf("Adresse : %s\n", membre.coordonnees.adresse);
			printf("Telephone : %s\n", membre.coordonnees.telephone);
			printf("Email : %s\n", membre.coordonnees.email);
			printf("Horaires : %s\n", membre.horaires);
			
			printf("Nombre de tranches : %d\n", membre.nom_tranches);
			for(int i=0;i<membre.nom_tranches;i++)
			{
				printf("Montant d'adhesion N°%d : %.2f\n", i+1, membre.montant_adhesion[i]);
			}
			break;
			}else{
				printf("Aucun membre avec ce nom.\n");
				break;
			}
		}
	}else{
		printf("Choix invalide. Veuillez entre N ou M.\n");
	}
	
	fclose(fichier);
}



void Afficher_Tous_LesMembres()
{
	FILE *fichier;
	Membre membre;
	
	fichier = fopen("Membres.txt", "r");
	if(fichier == NULL)
	{
		printf("Impossible d'ouvrir le fichier.\n");
		exit(1);
	}
	
	
	printf("************AFFICHER TOUS LES MEMBRES************\n\n");
	
	printf("Liste de tous les membres enregistres :\n");
	printf("-------------------------------------------\n");
	
	
	while(fscanf(fichier,"%d\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%d\t%f\t%f\t%f", &membre.numero, membre.nom, membre.prenom, membre.roles, membre.coordonnees.adresse, membre.coordonnees.telephone, membre.coordonnees.email, membre.horaires, &membre.nom_tranches, &membre.montant_adhesion[0], &membre.montant_adhesion[1], &membre.montant_adhesion[2]) != EOF)
	{
		printf("Numero : %d\n", membre.numero);
		printf("Nom : %s\n", membre.nom);
		printf("Prenom : %s\n", membre.prenom);
		printf("Role : %s\n", membre.roles);
		printf("Adresse : %s\n", membre.coordonnees.adresse);
		printf("Telephone : %s\n", membre.coordonnees.telephone);
		printf("Email : %s\n", membre.coordonnees.email);
		printf("Horaires : %s\n", membre.horaires);
			
		printf("Nombre de tranches : %d\n", membre.nom_tranches);
		for(int i=0;i<membre.nom_tranches;i++)
		{
			printf("Montant d'adhesion N°%d : %.2f\n", i+1, membre.montant_adhesion[i]);
		}
		printf("------------------------------------------------\n");
	}
	fclose(fichier);
}

