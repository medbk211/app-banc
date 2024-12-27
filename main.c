#include <stdio.h>
#include <stdlib.h>

#define Cmax 20
int choix ,x;
char line[150];

typedef struct  {
    int code_cli;
    char Nom[Cmax];
    char prenon[Cmax];
} S_client;

typedef struct  {
    int jours;
    int mois;
    int anne;
} Date;

typedef struct {
    int code_Cpt;
    int code_cli;
    Date d_cpt;
    int somme;
} S_compte;

    S_client client[20];
    S_compte compts[20];

                         // menu **********************************
void menu () {

    printf ("1- Gestion des cleints \n");
    printf ("2- Gestion des compts \n");
    printf("3- Gestion des operation \n");
    printf("4- Quitter  le menu  \n");
    printf(" **** choisir le menu : ");
    scanf("%d",&choix);
    sous_menu(choix);

}                           // sous-menu *******************************
void sous_menu(int a) {


    switch (a) {
        case 1:
            printf("1- Ajouter\n");
            printf("2- Modifier\n");
            printf("3- Supprimer\n");
            printf("4- Afficher\n");
            printf("5- Retour\n");
            printf("****Choisir un sous menu : ");
            scanf("%d", &x);
            gerer_client(x);
            break;
        case 2:
            printf("1- Ajouter\n");
            printf("2- Rechercher\n");
            printf("3- Afficher la liste\n");
            printf("4- Supprimer\n");
            printf("5- Retour\n");
            printf("****Choisir un sous menu : ");
            scanf("%d", &x);
            gerer_compte(x);
            break;
        case 3:
            printf("1- Retrait\n");
            printf("2- Versement d'argent\n");
            printf("Choisir un sous menu : ");
            scanf("%d", &x);
            gerer_operation(x);
            break;
        case 4:
            // Si a == 4, il n'y a pas de sous-menu, donc rien � faire ici.
            break;
        default:
            printf("Mauvais choix\n");
            break;
    }
}

                   // fonction ajouter client *****************************
void ajouter_client(S_client client[], int n) {
    FILE *file;

    file = fopen("client.txt", "a");
    if (file != NULL) {
        for (int i = 0; i < n; i++) {
            printf("Code Client : ");
            scanf("%d", &client[i].code_cli);
            printf("Nom : ");
            scanf("%s", client[i].Nom);
            printf("Prenom : ");
            scanf("%s", client[i].prenon);

            fprintf(file, "%d %s %s\n", client[i].code_cli, client[i].Nom, client[i].prenon);
        }
        fclose(file);
        printf("Clients ajout�s avec succ�s.\n");
    } else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }
}

                              //foction gerer client ********************************

void gerer_client(int a) {
    int n ;



     switch (a) {
        case 1:
      printf("saisir combient client :");
      scanf("%d",&n);
      ajouter_client(client,n);
      menu();


        break;
    case 2:
      modifier_client();

        break;
    case 3:
        supprimer_client();
        break;
    case 4:

         afficher_client();
         menu();
         break;

    case 5:
           menu();

         }
         }

                                    //fonction modifier compte *********************

void modifier_client() {
    FILE *file, *tempFile;
    S_client client;
    S_client nvclient;

    printf("Code Client � modifier : ");
    scanf("%d", &nvclient.code_cli);


    file = fopen("client.txt", "r");


    tempFile = fopen("temp.txt", "w");

    if (file != NULL && tempFile != NULL) {
        int found = 0;

        while (fscanf(file, "%d %s %s", &client.code_cli, client.Nom, client.prenon) != EOF) {
        if (client.code_cli == nvclient.code_cli) {
        found = 1;

        printf("Nouveau nom : ");
        scanf("%s", nvclient.Nom);
        printf("Nouveau pr�nom : ");
        scanf("%s", nvclient.prenon);
        fprintf(tempFile, "%d %s %s\n", nvclient.code_cli, nvclient.Nom, nvclient.prenon);
        printf("Client modifi� avec succ�s.\n");
        } else {

        fprintf(tempFile, "%d %s %s\n", client.code_cli, client.Nom, client.prenon);
        }
        }
        fclose(file);
        fclose(tempFile);
        remove("client.txt");
        rename("temp.txt", "client.txt");

        if (!found) {
            printf("Client non trouv�.\n");
        }
    } else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }
}
                          //fonction supprimer compt *******************
void supprimer_client(){
    FILE *file, *tempFile;
    S_client client;
    int code;


    printf("Code Client � supprimer : ");
    scanf("%d", &code);


    file = fopen("client.txt", "r");


    tempFile = fopen("temp.txt", "w");

    if (file != NULL && tempFile != NULL) {
        int found = 0;

        while (fscanf(file, "%d %s %s", &client.code_cli, client.Nom, client.prenon) != EOF) {
        if (client.code_cli != code) {
        found = 1;
        fprintf(tempFile, "%d %s %s\n", client.code_cli, client.Nom, client.prenon);

        }
        printf(" Client � supprimer avec succ�s ");
        }
        fclose(file);
        fclose(tempFile);
        remove("client.txt");
        rename("temp.txt", "client.txt");

        if (!found) {
            printf("Client non trouv�.\n");
        }
    } else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }
}

                            //fonction afichage client***********
void afficher_client() {
    FILE *file;
    S_client client;

    file = fopen("client.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%d %s %s", &client.code_cli, client.Nom, client.prenon) != EOF) {
            printf("\nCode client : %d", client.code_cli);
            printf("\nNom: %s | Prenom: %s", client.Nom, client.prenon);
            printf("\n");
        }
        fclose(file);
    } else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }
}
                             //gerer compte **************
void gerer_compte(int a) {
    int n ;



     switch (a) {
        case 1:

      ajouter_compte();
      menu();


        break;
    case 2:
        rechrche();
        menu();
        break;
    case 3:
        afficher_compte();
        menu();
        break;
    case 4:
       supprimer_compte();

         menu();
         break;

    case 5:
           menu();

         }
         }
void ajouter_compte() {
    S_compte compts;

    FILE *file;

    // Ouvrir le fichier en mode append ("a") pour ajouter les donn�es � la fin du fichier
    file = fopen("compt.txt", "a");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    printf("Code compte : ");
    scanf("%d", &compts.code_Cpt);
    printf("Code Client : ");
    scanf("%d", &compts.code_cli);
    printf("Date de creation du compte | ");
    printf("Jour : ");
    scanf("%d", &compts.d_cpt.jours);
    printf("Mois : ");
    scanf("%d", &compts.d_cpt.mois);
    printf("Annee : ");
    scanf("%d", &compts.d_cpt.anne);
    printf("Somme : ");
    scanf("%d", &compts.somme);

    // �crire les donn�es dans le fichier
    fprintf(file, "%d %d %d %d %d %d \n", compts.code_Cpt, compts.code_cli, compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne, compts.somme);

    // Fermer le fichier
    fclose(file);

    printf("Donn�es ajout�es avec succ�s dans le fichier.\n");
}
void rechrche(){
   S_compte compts;
   int code ;

   printf(" enterz le code du  compte a chercher :");
   scanf("%d",&code);


   FILE *file;
    int found=0;
   file = fopen("compt.txt","r");
   if (file != NULL){
         while(fscanf(file, "%d %d %d %d %d %d \n", &compts.code_Cpt, &compts.code_cli, &compts.d_cpt.jours, &compts.d_cpt.mois, &compts.d_cpt.anne, &compts.somme)  != EOF  && found == 0){
             if (compts.code_Cpt == code){
                 printf("\n Code compte : %d", compts.code_Cpt);
                    printf("\n Code client : %d", compts.code_cli);
                    printf("\n Date creation %d / %d / %d", compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne);
                    printf("\n Somme %d", compts.somme);
                    printf("\n-----------------------------------------");
                    found =1;
                    }

             }
             if(found != 1){
                printf("ce compte introuvable !\n");
             }
             fclose(file);
             } else{
            printf("Erreur lors de l'ouverture du fichier.\n");
            }


}
void afficher_compte() {
        S_compte compts;
        FILE *file;

        file = fopen("compt.txt", "r");
      if (file != NULL){
         while (fscanf(file, "%d %d %d %d %d %d \n", &compts.code_Cpt, &compts.code_cli, &compts.d_cpt.jours, &compts.d_cpt.mois, &compts.d_cpt.anne, &compts.somme)  != EOF) {
                    printf("\n Code compte : %d", compts.code_Cpt);
                    printf("\n Code client : %d", compts.code_cli);
                    printf("\n Date creation %d / %d / %d", compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne);
                    printf("\n Somme %d", compts.somme);
                    printf("\n-----------------------------------------\n");
        }
        fclose(file);
      }else{
      printf("ereur !!!!!");
      }

    }
void supprimer_compte() {
    S_compte compts;
    int code;
    FILE *file, *temp;

    printf("Entrez le code du compte � supprimer : ");
    scanf("%d", &code);

    file = fopen("compt.txt", "r");
    temp = fopen("temp.txt", "w");

    if (file != NULL && temp != NULL) {
        int found = 0;

        while (fscanf(file, "%d %d %d %d %d %d \n", &compts.code_Cpt, &compts.code_cli, &compts.d_cpt.jours, &compts.d_cpt.mois, &compts.d_cpt.anne, &compts.somme) != EOF) {
            if (compts.code_Cpt != code) {
                fprintf(temp, "%d %d %d %d %d %d \n", compts.code_Cpt, compts.code_cli, compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne, compts.somme);
            } else {
                found = 1; // Set found to 1 when a match is found
            }
        }

        fclose(file);
        fclose(temp);
        remove("compt.txt");
        rename("temp.txt", "compt.txt");

        if (found == 1) {
            printf("Compte supprim� avec succ�s\n");
        } else {
            printf("Compte non trouv�.\n");
        }
    } else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }
}

void gerer_operation(int a){

    switch (a){
 case 1 :

    Retrait();
    menu();
    break;

    }

}

void Retrait(){
    S_compte compts;
    int code, m;
    FILE *file, *temp;

    printf("Entrez le code du compte  : ");
    scanf("%d", &code);

    do {
        printf(" Montant ne d�passe pas 500dt : ");
        scanf("%d", &m);
    } while (m > 500);

    file = fopen("compt.txt", "r");
    temp = fopen("temp.txt", "w");
    int found = 0;
    if (file != NULL && temp != NULL) {


        while (fscanf(file, "%d %d %d %d %d %d \n", &compts.code_Cpt, &compts.code_cli, &compts.d_cpt.jours, &compts.d_cpt.mois, &compts.d_cpt.anne, &compts.somme) != EOF) {
            if (compts.code_Cpt == code) {
                    compts.somme = compts.somme - m;
                    fprintf(temp, "%d %d %d %d %d %d \n", compts.code_Cpt, compts.code_cli, compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne, compts.somme);
                    found = 1;
                } else {
                    fprintf(temp, "%d %d %d %d %d %d \n", compts.code_Cpt, compts.code_cli, compts.d_cpt.jours, compts.d_cpt.mois, compts.d_cpt.anne, compts.somme);
                }
            }
        }else {
        printf("Erreur: Impossible d'ouvrir le fichier.\n");
    }

        fclose(file);
        fclose(temp);
        remove("compt.txt");
        rename("temp.txt", "compt.txt");

        if (found != 0) {
            printf("Retrait ex�cut� avec succ�s\n");
        } else {
            printf("Compte non trouv�.\n");
        }
    }




int main() {
    menu();

    return 0;
}
