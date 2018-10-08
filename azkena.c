#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct etudiant etudiant;
struct etudiant{
	int age;
	char nom[20];
	etudiant*suivant;
	
};




	etudiant* creation(){
		etudiant*tete=NULL;
		etudiant*P_E=NULL;
		int bol=1;
		do {
			P_E=(etudiant*)malloc(sizeof(etudiant));
			printf("entrez le nom et l age");
			scanf("%s   %i",&(*P_E).nom, &(*P_E).age);
			(*P_E).suivant=tete;
			tete=P_E;
			printf("vous voulez continue?\n 0:nom 1:oui\n");
			scanf("%d",&bol);
			
			
		}while(bol==1);
		return tete;
		
		
	}
	
	
	
	int main(){
		
		etudiant* liset;
		liset=creation();
		system("clr");
		
		
		
	
	
	getch();	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
