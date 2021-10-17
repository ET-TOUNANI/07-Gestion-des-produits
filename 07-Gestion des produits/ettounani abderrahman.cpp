#include <stdio.h>
#include <stdlib.h>
#include <string.h>
		struct produit{ 
			int ref;
			char designation[50] ;
			float prix;
			int qtestock; 
		};
	struct produit p1[10]; 
		struct produit2{ 
			int ref2;
			char designation2[50] ;
			float prix2;
			int qtestock2; 
		};
	struct produit2 p2[10];
	struct produit p[10];
	static int n,i=0,m=0;
	static char c;
	static float some=0,nbr,dd;
		void ajoute_un_produit(){ 
		FILE *Rania ;
		Rania=fopen("fichierproduit.txt","a+");  
		if(Rania!=NULL )   
		{
		
		printf("entrer le nombre d'enregistrements des produits : ");
		scanf("%d",&n);
		for(i=0;i<n;i++){
				printf("donnez les information de  produit num %d :\n ",i+1);
				printf("\t une referance :");
				fflush(stdin);
				scanf("%d",&p1[i].ref);
				printf(" \t un designation :");
				fflush(stdin);
				gets(p1[i].designation);
				printf("\t un prix :");
				scanf("%f",&p1[i].prix);
				printf("\t un quantite de stock :");
				scanf("%d",&p1[i].qtestock);
				fprintf(Rania,"%d\n%s\n%.2f\n%d\n",p1[i].ref,p1[i].designation,p1[i].prix,p1[i].qtestock);
		}
		}
		else printf("erreur");
		fclose(Rania);
	}
	void liste_des_produit_et_moyenne_prix(){ 
		FILE *Rania ;
		Rania=fopen("fichierproduit.txt","r"); 
		m=0; 
		if(Rania!=NULL )   
		{	
				fseek(Rania,0,SEEK_SET);
				printf("\n*** les info des produits est : ***\n");
				do{
					c=fgetc(Rania);
					if(c=='\n')
					m=m+1;
				}
				while(c!=EOF);
				nbr=(float)m/4;
				fseek(Rania,0,SEEK_SET);
				for(i=0;i<nbr;i++){
					fscanf(Rania,"%d",&p[i].ref);
					fscanf(Rania,"%s",&p[i].designation);
					fscanf(Rania,"%f",&p[i].prix);
					fscanf(Rania,"%d",&p[i].qtestock);
				}
			if(nbr>=1){
					for(i=0;i<nbr;i++){
						printf("\t designation : %s \n",p[i].designation);
						printf("\t referance : %d \n ",p[i].ref);
						printf("\t prix : %.2f \n",p[i].prix);
						printf("\t quantit de stock : %d \n",p[i].qtestock );
						printf("-----------------------> \n");
					}
					for(i=0;i<nbr;i++){
						some=some+p[i].prix;
					}
				dd=(float)some/nbr;
					printf("\n\n la moyenne des prix est : %.2f \n",dd);
			}
			else printf("aucun elsement enregestrer ");
	}
	else{
		printf("erour");
		}
		fclose(Rania);
	}
	void supprimer_un_produit(){
		FILE *Rania,*Raniacpy;
		Rania=fopen("fichierproduit.txt","r");
		Raniacpy=fopen("fichierproduitcpy.txt","a+");
		if(Rania!=NULL || Raniacpy!= NULL){
			int s,a=0;
			char suppro[100];
			char ch;
		m=0;
				fseek(Rania,0,SEEK_SET);
				do{
					c=fgetc(Rania);
					if(c=='\n')
					m=m+1;
				}
				while(c!=EOF);
				nbr=(float)m/4;
				fseek(Rania,0,SEEK_SET);
				for(i=0;i<nbr;i++){
					fscanf(Rania,"%d",&p[i].ref);
					fscanf(Rania,"%s",&p[i].designation);
					fscanf(Rania,"%f",&p[i].prix);
					fscanf(Rania,"%d",&p[i].qtestock);
				}
				fseek(Rania,0,SEEK_SET);
				fseek(Raniacpy,0,SEEK_SET);
				printf("designation a supprumer : ");
				gets(suppro);
				for(i=0;i<nbr;i++){
						
							if(strcmp(p[i].designation,suppro)==0){
								int j=j+1;
							}
							else{
							   fprintf(Raniacpy,"%d\n%s\n%.2f\n%d\n",p[i].ref,p[i].designation,p[i].prix,p[i].qtestock);
								//system("fichierproduitcpy.txt fichierproduit.txt");
							}
						
				}
		   
		
		fclose(Rania);
		fclose(Raniacpy);
		if(remove("fichierproduit.txt") == 0) {
		      printf("File deleted successfully");
		   } else {
		      printf("Error: unable to delete the file");
		   }
		   rename("fichierproduitcpy.txt","fichierproduit.txt");
		}
	}
	void trier_par_quantite(){ 
		FILE *Rania;
		Rania=fopen("fichierproduit.txt","r");
		m=0;
		fseek(Rania,0,SEEK_SET);
			do{
					c=fgetc(Rania);
					if(c=='\n')
					m=m+1;
				}
				while(c!=EOF);
				nbr=(float)m/4;
				printf("%d,%f",m,nbr);
				fseek(Rania,0,SEEK_SET);
				for(i=0;i<nbr;i++){
					fscanf(Rania,"%d",&p[i].ref);
					fscanf(Rania,"%s",&p[i].designation);
					fscanf(Rania,"%f",&p[i].prix);
					fscanf(Rania,"%d",&p[i].qtestock);
				}
			for(i=0;i<nbr;i++){
				for(int j=i+1;j<=nbr;j++){
					if(p[i].qtestock > p[j].qtestock){
						p2[i].qtestock2=p[i].qtestock;
						p2[i].ref2=p[i].ref;
						p2[i].prix2=p[i].prix;
						strcpy(p2[i].designation2,p[i].designation);
						
						p[i].qtestock=p[j].qtestock;
						p[i].ref=p[j].ref;
						p[i].prix=p[j].prix;
						strcpy(p[i].designation,p[j].designation);
						
						p[j].qtestock=p2[i].qtestock2;
						p[j].ref=p2[i].ref2;
						p[j].prix=p2[i].prix2;
						strcpy(p[j].designation,p2[i].designation2);
					}
				}
			}
			printf("%d.....",nbr);
			for(i=0;i<nbr;i++){
							printf(" \n\n les information de  produit n:%d est :  \n ",i+1);
							printf("\t  referance :%d \n",p[i].ref);
							printf("\t  designation : %s \n ",p[i].designation);
							printf("\t  prix : %.2f \n",p[i].prix);
							printf("\t  quantite de stock : %d \n\n\n",p[i].qtestock);				
			}
		
		fclose(Rania);
	}
	void chercher_le_prix_un_produit(){	 
			static int d,g=0,j=0;
			m=0;
			char designation3[10];
			FILE *Rania;
			Rania=fopen("fichierproduit.txt","r");
			
			if(Rania !=NULL ){
				fseek(Rania,0,SEEK_SET);
				printf("entrer la designation de produit que vous cherchez : ");
				fflush(stdin);
				gets(designation3);	
					do{
						c=fgetc(Rania);
						if(c=='\n')
						m=m+1;
					}
					while(c!=EOF);
					nbr=(float)m/4;
					fseek(Rania,0,SEEK_SET);
					for(i=0;i<nbr;i++){
						fscanf(Rania,"%d",&p[i].ref);
						fscanf(Rania,"%s",&p[i].designation);
						fscanf(Rania,"%f",&p[i].prix);
						fscanf(Rania,"%d",&p[i].qtestock);
					}
				for(i=0;i<nbr;i++){
					if(strcmp(designation3,p[i].designation)==0){
						g=1;
						 d=i;	
					}
					else{
						j=1;
					}
				}
				if(g==1)printf("le prix de produit chercher est : %.2f \n",p[d].prix);
				else printf("produit n exeste pas \n");
			
			fclose(Rania);
	}	
}
	int main(){					
		
					printf("\t\t\t programme : gestion de produit / le 28-02-2020 \n\n");
					printf("\t\t\t realiser par : ABDERRAHMANE ETT-OUNANI + Rania ait ben omar \n\n");
					printf("\t\t\t descadrer par : Pr KHALID :) \n\n ");
					int choix,quitter=1;
					do{
						 printf("\n");
						 printf("\t\t\t\t\t\tGESTION DES PRODUITS  \n\n\n");
						 printf ("\t\t===========================<<<<<<<<<<<!!!!!>>>>>>>>>>>============================\n\n");
						 printf ("\t\t{}                                                                               {} \n");
						 printf ("\t\t{}  [1] : ==========<<<<<<<  Ajouter un produit              >>>>>>========      {} \n");
						 printf ("\t\t{}  [2] : ==========<<<<<<<  Afficher les produits           >>>>>>========      {} \n");
						 printf ("\t\t{}  [3] : ==========<<<<<<<  Supprimer un produit            >>>>>>========      {} \n");
						 printf ("\t\t{}  [4] : ==========<<<<<<<  Trier par quantite              >>>>>>========      {} \n");
						 printf ("\t\t{}  [5] : ==========<<<<<<<  Rechercher un produit           >>>>>>========      {} \n");
						 printf ("\t\t{}  [6] : ==========<<<<<<<  Quitter                         >>>>>>========      {} \n");
						 printf ("\t\t{}                                                                               {} \n");
						 printf ("\t\t============================<<<<<<<<<<!!!!!>>>>>>>>>>>===========================\n\n");
						 printf("Veuillez faire votre choix : ");
						 scanf("%d",&choix);
						fflush(stdin);
 						system("cls");						
					switch(choix)
				    {
								case 1: ajoute_un_produit();    
							break;
							    case 2: liste_des_produit_et_moyenne_prix();    
							break;
							    case 3: supprimer_un_produit();    
							break; 
							    case 4: trier_par_quantite();		
							break;
							    case 5: chercher_le_prix_un_produit(); 
							break;
							    case 6: printf(" VOULEZ VOUS VRAIMENTTER ?     OUI:    1     NON:    2\n");
							scanf("%d",&choix);
							if(choix==1) quitter=0; else quitter=1; system("cls");  
							break;
							    default: printf(" VEILLEZ entrer un nombre entre 1 et 6");
							break;
					};
				}while (quitter==1);
	return 0;

}
