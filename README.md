# Logiciel de Gestion de Club

Ce projet est un logiciel de gestion pour un club, permettant de gérer les membres, les tâches, les ressources, ainsi que le suivi des budgets et des statistiques. Le programme est écrit en langage C et est organisé en plusieurs modules pour une meilleure gestion et maintenance du code.

## Fonctionnalités

### Gestion des Membres
Le logiciel permet de gérer les informations des membres du club, y compris les profils (numéro, noms, prénoms, rôles, coordonnées, horaires). Chaque membre doit payer un montant pour adhérer, éventuellement en 1, 2 ou 3 tranches.

- **Ajouter un membre**
- **Afficher tous les membres**
- **Supprimer un membre**
- **Modifier un membre**
- **Rechercher un membre**

### Gestion des Tâches
Le logiciel permet la création et le suivi des tâches assignées aux membres du club, avec des rappels, des deadlines et des statuts de progression. Une tâche est confiée à un responsable et est décrite par un numéro, un libellé, un budget, un statut (en attente, en cours, terminée) et une date de fin.

- **Créer une tâche**
- **Mettre à jour une tâche**
- **Supprimer une tâche**
- **Suivre les statuts des tâches**
- **Rappels des tâches**

### Gestion des Ressources
Le logiciel permet de gérer les ressources du club, telles que les dons, les équipements et les fournitures, en permettant la réservation, la planification et la disponibilité de ces ressources.

- **Ajouter une ressource**
- **Réserver une ressource**
- **Vérifier la disponibilité des ressources**
- **Planification et suivi de l'utilisation des ressources**

### Suivi des Budgets et Statistiques
Le logiciel inclut des fonctionnalités de suivi des cotisations et des dépenses du club, permettant de gérer les finances liées aux activités du club. Il permet également de générer des rapports et des statistiques pour évaluer les performances du club.

- **Ajouter une cotisation**
- **Ajouter une depense**
- **Suivre les cotisations**
- **Suivre les dépenses**
- **Générer des rapports et des statistiques**

## Organisation du Code

### `main.c`
Le fichier principal du programme, contenant le menu principal permettant d'accéder aux différentes fonctionnalités du logiciel.

### Modules
- **Membre** : Gestion des membres du club (`membre.h`, `membre.c`)
- **Tâche** : Gestion des tâches du club (`taches.h`, `taches.c`)
- **Ressource** : Gestion des ressources du club (`ressource.h`, `ressource.c`)
- **Finance** : Suivi des budgets et des statistiques (`finance.h`, `finance.c`)

## Utilisation

1. **Compilation** : Pour compiler le programme, utilisez un compilateur C comme `gcc`.
   ```sh
   gcc -o gestion_club main.c membre.c tache.c ressource.c budget.c
   ```

2. **Exécution** : Une fois compilé, exécutez le programme.
   ```sh
   ./gestion_club
   ```

3. **Navigation** : Utilisez le menu principal pour accéder aux différentes fonctionnalités du logiciel.

## Contributeurs

- Ondo jean karel

## Licence

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.
