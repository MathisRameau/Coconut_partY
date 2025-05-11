Readme Projet Coconut partY :

Description du jeu :
Coconut Party est un jeu de type Tower Defense, développé en langage C dans le cadre du projet de fin de semestre en Informatique à CY Tech.  
Le joueur doit protéger la couronne du roi des singes des crabes voleurs en plaçant des singes défensifs sur une carte afin de les repousser. Le jeu se déroule entièrement dans le terminal Linux.

Compilation et exécution du jeu : 
Pour compiler, ouvrez un terminal, placez-vous dans le dossier du projet et tapez ensuite : make clean
Puis taper : 
 make

Comment y jouer ?
1.	Commencez une partie
2.	Ecrivez votre pseudo
3.	Tapez les coordonnées d’une case du plateau de jeu où vous voulez positionner votre singe.
4.	Votre singe est prêt à défendre cette zone !
5.	Une armée de crabes commencera à apparaitre
6.	Si un crabe se trouve sur l’une des cases adjacentes à celle que vous avez choisi, il se fait éliminer automatiquement.
7.	C’est parti ! A vous de jouer !


Commandes :
Commencez une partie, puis entrez votre pseudo, la taille du plateau de jeu, et les coordonnées (x , y) où vous voulez placer votre singe.




Fichiers.c :

•	main.c : boucle principale du jeu
•	makefile : compilation automatique du projet
•	crabs_creation.c : création des crabes
•	crabs_movement.c : gestion du déplacement des crabes
•	monkeys_creation.c : création et positionnement des singes
•	gameBoard_dimension.c : choix de la taille du plateau
•	gameBoard_creation.c : création des cases
•	gameBoard_playArea.c : génération de la zone de jeu
•	gameBoard_smooth.c : lissage et ajustement du terrain
•	gameBoard_display.c : affichage du plateau dans le terminal
•	gameBoard_free.c : libération de la mémoire du plateau
•	path_creation.c : création du chemin emprunté par les crabes
•	path_direction.c : calcul de la direction des déplacements
•	clean_screen.c : efface proprement l’écran du terminal entre chaque tour
•	ask_monkey_position.c : Permet de demander et de récupérer la position d’un singe à l’utilisateur.
•	ask_players_name.c : Demande à l’utilisateur de saisir un pseudonyme pour le joueur.
•	game_over_display_menu.c : Affiche le menu de fin de jeu et permet à l'utilisateur de choisir entre recommencer ou quitter.
•	load.c : Charge une sauvegarde du jeu en récupérant les données précédentes de crabes et de singes.
•	menu_display.c : Affiche le menu principal du jeu, permettant à l'utilisateur de démarrer ou de charger une partie.
•	monkey_attack.c : Gère les attaques des singes contre les crabes.
•	monkeys_store.c : Permet aux joueurs d’acheter ou d'améliorer des singes dans le agasin de singes.
•	save.c : Sauvegarde l'état actuel du jeu, y compris les positions des crabes et des singes, ainsi que les autres variables du jeu.
•	decompte.c : Implémente la logique du décompte avant le début d'un tour ou d'un événement dans le jeu.
•	display_crabs_tour.c : Contient les fonctions pour afficher les crabes et leur statut pendant chaque tour de jeu.
•	tour_creation.c : Gère la création d'un tour, en initialisant les propriétés d'un tour spécifique dans le jeu.
•	tour.c : Contient la logique principale pour gérer le déroulement d'un tour dans le jeu, incluant les actions des crabes et des singes.



Fichiers.h :
•	crabs_creation.h
•	crabs_movement.h 
•	monkeys_creation.h 
•	gameBoard_dimension.h  
•	gameBoard_creation.h
•	gameBoard_playArea.h
•	gameBoard_smooth.h  
•	gameBoard_display.h  
•	gameBoard_free.h
•	path_creation.h
•	path_direction.h 
•	clean_screen.h 
•	ask_monkey_position.h  
•	ask_players_name.h 
•	game_over_display_menu.h 
•	load.h 
•	menu_display.h 
•	monkey_attack.h 
•	monkeys_store.h 
•	save.h 
•	decompte.h.
•	display_crabs_tour.h
•	tour_creation.h
•	tour.h

NB : Les fichiers : game_over_display_menu.c/.h ; load.c/.h et save.c/.h ont été développés mais n’ont pas pu être intégrés dans le programme final.

Groupe : MI1-A
Lahouari GUETARNI
Mathis RAMEAU
Sara BELGHAZI
