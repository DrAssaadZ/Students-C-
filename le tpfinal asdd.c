#include <stdio.h>
#include <stdlib.h>

struct etud {
	int num;
	int groupe;
	char nom[20];
	char prenom[20];
	float tl;
	float alg_sdd;
	float si;
	float poo;
	float logique_math;
	float ao;
	float ang;
	int credit;
	float moyenne;
	struct etud* suivant;
	
};

void calculerMoyenne(struct etud** j){
	
	struct etud* l;
	l = *j;
	
	while(l != NULL){
		
		float somme = ((*l).alg_sdd) * 3 + ((*l).poo) * 3 + ((*l).si) * 3 + ((*l).tl) * 2 + ((*l).logique_math) * 2 + ((*l).ao) * 2 + ((*l).ang);
		
		(*l).moyenne = somme / 16;

		l = (*l).suivant;

	}
	
}


void calculerCredit(struct etud** k){

	struct etud* list;
	list = *k;
	
	while(list != NULL){
		if ((*list).moyenne < 10){
			
			
			if ((*list).tl >= 10){
				(*list).credit += 4;
			}
			if ((*list).alg_sdd >= 10){
				(*list).credit += 6;
			}
			if ((*list).si >= 10){
				(*list).credit += 4;
			}
			if ((*list).logique_math >= 10){
				(*list).credit += 4;
			}
			if ((*list).ao >= 10){
				(*list).credit += 5;
			}
			if ((*list).poo >= 10){
				(*list).credit += 5;
			}
			if ((*list).ang >= 10){
				(*list).credit += 2;}
		}else{
			 (*list).credit = 30;
			}
			
			
		}
		
		list = (*list).suivant;
	}



struct etud* majorPromo(struct etud* j){
	struct etud* l;
	l = (*j).suivant;
	struct etud* major;
	major = j;
	
	while(l != NULL){
		
		if (((*l).moyenne) > ((*major).moyenne)){
			major = l;
		}
		
		l = (*l).suivant;
		
	}

	return major;
}

/*to do: write "afficher" function*/



int main(int argc, char *argv[]) {
	system("COLOR 3f");
	struct etud* p;
	p = (struct etud*)malloc(sizeof(struct etud));
	struct etud* p1;
	p1 = p;
	int i = 1;
	int l = 1;
	while (l == 1){
		system("cls");
		printf("le nom d'etudiant N: %d\n", i);
		scanf("%s",(*p1).nom);
		printf("le prenom d'etudiant: %d \n",i);
		scanf("%s",(*p1).prenom);
		do{
		printf("le groupe : ( 1 -> 10 ) \n",(*p1).nom,(*p1).prenom);
		scanf("%d", &(*p1).groupe);
		}while((*p1).groupe < 0 || (*p1).groupe > 10);
		printf("le code de l'etudiant %s %s \n",(*p1).nom,(*p1).prenom);
		scanf("%d",&(*p1).num);
		do{
		printf("la note du TL: \n");
		scanf("%f",&(*p1).tl);
		}while((*p1).tl < 0 || (*p1).tl > 20);
		do{
		printf("ASDD: \n");
		scanf("%f",&(*p1).alg_sdd);
		}while((*p1).alg_sdd < 0 || (*p1).alg_sdd > 20);
		do{
		printf("SI:  \n");
		scanf("%f",&(*p1).si);
		}while((*p1).si < 0 || (*p1).si > 20);
		do{
		printf("POO:  \n");
		scanf("%f",&(*p1).poo);
		}while((*p1).poo < 0 || (*p1).poo > 20);
		do{
		printf("LM:  \n");
		scanf("%f",&(*p1).logique_math);
		}while((*p1).logique_math < 0 || (*p1).logique_math > 20);
		do{
		printf("AO:  \n");
		scanf("%f",&(*p1).ao);
		}while((*p1).ao < 0 || (*p1).ao > 20);
		do{
		printf("Anglais:  \n");
		scanf("%f",&(*p1).ang);
		}while((*p1).ang < 0 || (*p1).ang > 20);
		(*p1).moyenne = 0.0;
		(*p1).credit = 0;
		
				
		printf("esq tu veut entrer un nv etudiant? 1 = Oui 0 = Non: ");
		scanf("%d", &l);
			i++;
		if (l == 1){
			(*p1).suivant = (struct etud*)malloc(sizeof(struct etud));
			p1 = (*p1).suivant;
			system("cls");
		}
		
		
	}
    (*p1).suivant = NULL;
    struct etud* supp;
    supp = p;
	calculerMoyenne(&supp);
	supp = p;
	calculerCredit(&supp);
	supp = p;
	struct etud* m;
	
    /*major de promo fonction*/

	m = majorPromo(supp);


	//lafichage de major de promo



	system("cls");
    printf("le major de promo : ");
	printf("Le nom : %s \n",(*m).nom);
	printf("Le prenom : %s \n",(*m).prenom);
	printf("Le grp: %d \n",(*m).groupe);
	printf("Identificateur: %d\n",(*m).num);
	printf("La moyenne de TL: %.2f --\n",(*m).tl);
	printf("La moyenne de ASDD: %.2f --\n",(*m).alg_sdd);
	printf("La moyenne de SI: %.2f --\n",(*m).si);
	printf("La moyenne de POO: %.2f --\n",(*m).poo);
	printf("La moyenne de LM: %.2f --\n",(*m).logique_math);
	printf("La moyenne de AO: %.2f --\n",(*m).ao);
	printf("La moyenne de ANG: %.2f --\n",(*m).ang);
	printf("La Moyenne: %.2f\n",(*m).moyenne);
	printf("Le Credit: %d\n",(*m).credit);
	

	getchar();

	
	
	
	return 0;
}
