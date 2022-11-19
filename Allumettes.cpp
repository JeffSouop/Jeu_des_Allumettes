#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

void jeuHumain(int n, int coup1, int coup2, int N);
void JeuVsIA(int n, int coup1, int coup2, int N, int niveau);
int gagnant(int Jgagnant, int nombre_joueurs, int n, int niveau);
int affiche_menu();
void jouer();
void menu_jeu(int n);
int regles_jeu();
int credit();



//	char t[50], s[50];
//	printf("Joueur 1 entrez votre nom : ");
//	scanf("%s",&t[50]);
//	printf("Joueur 2 entrez votre nom : ");
//	scanf("%s",&s[50]);
	
	
	
int main(){
	affiche_menu();
	//return 0;
}

int affiche_menu(){
	
	int choice;
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t______________________\n");
	printf("\t\t       |                      |\n");
	printf("***********************");
	printf("|  JEU DES ALLUMETTES  |");
	printf("***********************\n");
	printf("\t\t       |                      |\n");
	printf("\t\t\t----------------------\n");
	printf("\n\n\n");
	printf("Bienvenu dans le jeu des allumettes\n");
	printf("\n\n");
	printf("Dans le menu vous aurez 4 options.\nVous pourrez choisir si vous voulez jouer,\nensuite si vous voulez voir les regles du jeu ou non,\npuis voir qui sont les concepteurs et enfin Quitter\n\n\n\n\n\n\n");
	
	printf("Quel est votre choix\n\n\n");
	printf("1  - Jouer\n\n2  - Regles du jeu\n\n3  - Credit\n\n4  - Quitter");
	printf("\n\n");
	printf("Mon choix est le :");
	scanf("%d",&choice);
	switch(choice){
		case 1 : 
			jouer();
			break;
		case 2 :
			regles_jeu();
			break;
		case 3 :
			credit();
			break;
		case 4 :
			return 0;
			break;
		default :
			printf("\n\nVeuillez refaire votre choix");
			system("pause");
			affiche_menu();	
	}
	return 0;
	
}

void jouer(){
	
	system("cls");
	int n, choice;
	printf("1  - Nombre Aleatoire d'allumettes\n\n");
	printf("2  - Nombre d'allumettes predefini\n\n");
	printf("3  - Entrer le nombre d'allumettes\n\n");
	printf("Quel est votre choix :\t");
	scanf("%d",&choice);
	switch(choice){
		
		case 1 :
			do{
				n = rand()%45;
			}
			while(n<15);
			break;
		case 2 :
			n = 30;
			break;
		case 3 :
			printf("\nVeuillez entrer le nombre d'allumettes a utiliser : ");
			scanf("%d",&n);
			while(n <= 15){
				printf("Nombre trop petit\nVeuillez entrer un plus grand : ");
				scanf("%d",&n);
			}
			break;
		default :
			system("cls");
			printf("Veuillez entrer un bon choix");
			jouer();
			break;
	}
	menu_jeu(n);
}

void menu_jeu(int n){
	
	system("cls");
	int choice, niveau;
	printf("1  - Jeu a 2\n\n");
	printf("2  - Jeu contre l'Ordinateur\n\n");
	printf("Quel est votre choix : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			jeuHumain(n, 0, 0, n);
			break;
		case 2 :
			printf("\n\n***Choisir le niveau de Difficulte***\n\n");
			printf("1  - Facile\n\n");
			printf("2  - Normal\n\n");
			printf("3  - Difficile\n\n");
			do{
				scanf("%d",&niveau);
			}
			while((niveau < 0) ||(niveau > 3));
			system("cls");
			
			JeuVsIA(n, 0, 0, n, niveau);
			break;
		default :
			system("cls");
			printf("Veuillez faire un bon choix");
			menu_jeu(n);
			break;
	}
	
}

void jeuHumain(int n, int coup1, int coup2, int N){
	
	int joueur1, joueur2, i;

	
	
	for(i=1;i<=n;i++){
		printf(" |");
	}
	printf("il y a encore %d allumettes\n",n);
	if(coup1 == coup2){
		printf("Jouer 1-->Nombre a enlever : ");
		scanf("%d",&joueur1);
		if((joueur1<0)||(joueur1>3)){
			printf("Operation impossible !!!\n");
			jeuHumain(n, coup1, coup2, N);
		}
		
		int ok = 1;
		while(ok == 1){
			if(joueur1<n){
				n = n - joueur1;
				ok = 0;
			}
			else{
				jeuHumain(n, coup1, coup2, N);
			}
		}
	//	n = n-joueur1;
		coup1 = coup1 + 1;
		
		
		if(n == 1){
			gagnant(1, 2, N, 0);
		}
		else{
			jeuHumain(n, coup1, coup2, N);
		}
	}
	else{
		printf("Joueur 2-->Nombre a enlever : ");
		scanf("%d", &joueur2);
		if((joueur2<0)||(joueur2>3)){
			printf("Operation impossible !!!");
			jeuHumain(n, coup1, coup2, N);
		}
		
		int ko = 1;
		while(ko == 1){
			if(joueur2<n){
				n = n - joueur2;
				ko = 0;
			}
			else{
				jeuHumain(n, coup1, coup2, N);
			}
		}
		//n = n - joueur2;
		coup2 = coup2 + 1;
		
		
		if(n==1){
			gagnant(2, 2, N, 0);
		}
		else{
			jeuHumain(n, coup1, coup2, N);
		}
	}
	
}

void JeuVsIA(int n, int coup1, int coup2, int N, int niveau){
	
	int joueur1, joueur2, i, k;
	for(i=1; i<=n; i++){
		printf(" |");
	}
	if(n<=24){
		k = 48-2*n;
	}
	else{
		k=3;
	}
	printf("il y a encore %d allumettes\n", n);
	if(coup1 == coup2){
		printf("Joueur 1 --> Nombre a enlever : ");
		scanf("%d",&joueur1);
		if((joueur1<=0)||(joueur1>3)){
			printf("Operation impossible!!!");
			JeuVsIA(n, coup1, coup2, N, niveau);
		}
		n = n - joueur1;
		coup1 = coup1 + 1;
		if(n==1){
			gagnant(1, 1, N, niveau);
		}
		else{
			JeuVsIA(n, coup1, coup2, N, niveau);
		}	
	}
	else{
		if(niveau == 3){
			if(n<=4){
				joueur2 = n-1;
			}
			else if((n>5)&&(n<=8)){
				joueur2 = n-5;
			}
			else if(n%4==0){
				joueur2 = 3;
			}
			else if(n%4==2){
				joueur2 = 1;
			}
			else if(n%4==3){
				joueur2 = 2;
			}
			else{
				do{
					joueur2 = rand()%3;
				}
				while(joueur2==0);			
			}
		}
		else if(niveau == 2){
			if(n<=4){
			joueur2 = n-1;
			}
			else if(n%4==0){
				joueur2 = 3;
			}
			else if(n%4==2){
				joueur2 = 1;
			}
			else if(n%4==3){
				joueur2 = 2;
			}
			else{
				do{
					joueur2 = rand()%3;
				}
				while(joueur2==0);			
			}
		}
		else{
			if(n==3){
				do{
					joueur2 = rand()%2;
				}
				while(joueur2==0);
			}
			if(n==2){
				joueur2 = 1;
			}
			else{
				do{
					joueur2 = rand()%3;
				}
				while(joueur2 == 0);
			}
		}
		printf("IA enleve %d allumettes\n",joueur2);
		n = n - joueur2;
		coup2 = coup2 + 1;
		if(n==1){
			gagnant(3, 1, N, niveau);
		}
		else{
			JeuVsIA(n, coup1, coup2, N, niveau);
		}
	}
	
}

int gagnant(int Jgagnant, int nombre_joueurs, int n, int niveau){
	
	int choice;
	switch(Jgagnant){
		case 1 :
		case 2 :
			printf("*********************************************Joueur%d est l'heureux gagnant***************************************\n", Jgagnant);
			break;
		default :
			printf("*********************************************IA est l'heureux gagnant**********************************************\n");
	}
	printf("\nUne nouvelle partie ?\n");
	printf("1  - Rejouer\n");
	printf("2  - Retour au Menu Principal\n");
	printf("3  - Quitter\n");
	scanf("%d",&choice);
	system("cls");
	switch(choice){
		
		case 1 :
			if(nombre_joueurs == 2){
				jeuHumain(n, 0, 0, n);
			}
			else{
				JeuVsIA(n, 0, 0, n, niveau);
			}
			break;
		case 2 :
			jouer();
			break;
		case 3 :
			return EXIT_SUCCESS;
			break;
		default :
			printf("Veuillez refaire votre choix");
			gagnant(Jgagnant, nombre_joueurs, n, niveau);
	}
	return 0;
	
}

int regles_jeu(){
	
	int choice;
	printf("le but du jeu est simple\n");
	printf("");
	
	
	printf("1  - Jouer\n");
	printf("2  - Quitter\n");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			jouer();
			break;
		case 2 :
			return 0;
			break;
		default :
			printf("Veuillez resaisir votre demande\n");
			system("pause");
			regles_jeu();
	}
	return 0;
	
}

int credit(){
	system("cls");
	int choice;
	printf("SOUOP Audrey Jordan & MOHAMMED AWAL\n\n");
	printf("Etudiant 3A ESIEA\n\n");
	printf("******contacts:******\n\n");
	printf("Tel. : +33 (0)---------\n\n");
	printf("Fax :-----\n\n");
	printf("Em@il : etudiant@et.esiea.fr\n\n\n\n\n\n");
	
	
	printf("1  - Jouer\n");
	printf("2  - Quitter\n");
	scanf("%d",&choice);
	switch(choice){
		case 1 :
			jouer();
			break;
		case 2 :
			return 0;
			break;
		default :
			printf("Veuillez resaisir votre demande\n");
			system("pause");
			regles_jeu();
	}
	return 0;
	
}