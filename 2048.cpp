#include "2048.h"


bool estEgale(int uneMat1[][4],int uneMat2[][4]){
    //on parcoure les matrices avec deux boucles
    for(int ligne=0; ligne<4; ligne++){             //une premi�re pour parcourir les lignes
        for(int colonne=0;colonne<4;colonne++){     //une sconde pour parcourir les colonnes de cette ligne
    //On retrouvera ces deux boucles pour chaque parcour de matrice dans les fonctions suivante
            if(uneMat1[ligne][colonne]!=uneMat2[ligne][colonne])return false;   //si deux m�me emplecements des matrices sont diff�rentes on retourne faux
        }
    }
    return true;        //Sinon on retourne vrai
}

bool estVide(int uneMat[][4]){
    //Pourcour de la matrice avec les deux boucles for
    for(int ligne=0; ligne<4; ligne++){
        for(int colonne=0; colonne<4; colonne++){
            if(uneMat[ligne][colonne]!=0)return false;  // Si un emplcement contient une valeur (diff�rent de 0) on retourne vrai
        }
    }return true;       // Sinon on retourne faux
}

bool estPleine(int uneMat[][4]){
    //Pourcour de la matrice avec les deux boucles for
    for(int ligne=0; ligne<4; ligne++){
        for(int colonne=0; colonne<4; colonne++){
            if(uneMat[ligne][colonne]==0)return false;  // Si un emplcement est vide (�gale � 0) on retourn vrai
        }
    }return true;       // Sinon on retourne faux
}

void copie(int uneMat[][4], int uneMatCopie[][4]){
    // Parcours des matrices avec les deux boucles for
    for(int ligne=0; ligne<4; ligne++){
        for(int colonne=0;colonne<4;colonne++){
            uneMatCopie[ligne][colonne]=uneMat[ligne][colonne]; // Pour chaque emplacement la matrice copie
        }                                                       // r�cup�re la valeur au m�me emplacement de la matrice � copi�
    }
}

void afficherMatrice(int uneMat[][4], int* score, int meilleurScore){int ligne,colonne;
    system("cls");                      //On efface le terminal actuel
    // On met une forme de grille � la matrice
    printf(" ___ ___ ___ ___ \n");
    for(ligne=0; ligne<4; ligne++){
        printf("|   |   |   |   |\n|");
       for(colonne=0; colonne<4; colonne++){                // On parcour chaque colonne
            if(uneMat[ligne][colonne]==0)printf("   |");    // Si l'emplacement est vide, on affiche rien
            else printf(" %d |", uneMat[ligne][colonne]);   // Si l'emplacement contient une valeur, on affiche cette valeur
       }
        printf("\n|___|___|___|___|\n");

    }
    printf("\n score:%d meilleur score:%d",*score, meilleurScore);  // on affiche le score et le meilleur score
}

void insertion (int uneMat[][4]){
int ligne, colonne;
int i, valeur;
    if((rand()%5)==0)valeur=4;          // La valeur ins�r� sera 4 (si le resultat est 0) ou 2 en fonction du r�sultat obtenu au hasard
    else valeur=2;                      //avec une probabilit� inferieur d'obtenir un 0 qu'une autre
    if (estVide(uneMat))                // On verifie si la matrice est vide
    {
        // Insertion au hasard
        for(i=0; i<=1; i++){            // On r�p�te l'insertion d'un 2 deux foix lorsque la matrice esy vide
            do{
                ligne=rand()%4;         //on choisit une ligne et une colonne au hasard
                colonne=rand()%4;
            }while(uneMat[ligne][colonne]!=0);  // Limite aux emplacments vide et � la matrice elle m�me
            uneMat[ligne][colonne] = 2;
        }
    }
    else
       {
           // Insertion au hasard
            do{
                ligne=rand()%4;
                colonne=rand()%4;
             }while(uneMat[ligne][colonne]!=0);
             uneMat[ligne][colonne] = valeur;
         }
}

void deplacementHaut(int uneMat[][4], int* score){
int ligne, colonne;
    ///Fusion des tuiles vers le haut
    //Parcour de la matrice avec les deux boucles for, on par du haut pour la fusion et le d�palcement des tuiles
    for(ligne=0; ligne<4; ligne++){
        for(colonne=0;colonne<4;colonne++){
            int i=ligne;
            if(uneMat[ligne][colonne]!=0){          //On verifie que la colonne n'est pas vide et que l'emplacement non plus
                do{
                    i++;               // On incremente de 1 � i pour parcourir la colonne vers le bas
                }while(uneMat[i][colonne]==0);      // On d�cale de ligne jusqua trouv� une case contenant une valeur
                if(i<4 && uneMat[ligne][colonne]==uneMat[i][colonne])   // On v�rifie que l'on a pas d�pac� les limites de la matrice
                {                                                       // et que les valeurs sont biens �gales pour les fusionner
                    uneMat[ligne][colonne]=uneMat[ligne][colonne]*2;
                    uneMat[i][colonne]=0;
                    *score=*score+uneMat[ligne][colonne];               // On actualise l score
                }
            }
        }
    }
    /// Deplacment des tuiles vers le haut
    //Parcour de la matrice avec les deux boucles for
    for(ligne=0; ligne<4; ligne++){
        for(colonne=0;colonne<4;colonne++){
            int i=ligne;
            if(uneMat[ligne][colonne]==0)
            {
                do{
                    i++;
                }while(uneMat[i][colonne]==0);  // Pareil que pour la fusion, on d�cale de ligne jusqua trouv� une case contenant une valeur
                if(i<4 && uneMat[i][colonne]!=0){   // On v�rifie que l'on a pas d�pac� les limites de la matrice
                    uneMat[ligne][colonne]=uneMat[i][colonne];
                    uneMat[i][colonne]=0;
                }
            }
        }
    }
}

void deplacementBas(int uneMat[][4], int* score){
int ligne, colonne;
    ///Fusion des tuiles vers le bas
    //Parcour de la matrice, on par du bas pour la fusion et le deplacement des tuiles
    for(int i=0; i<4; i++)
    {
        ligne=(4-1)-i;                      // la variable ligne varie de 3 � 0
        for(colonne=0;colonne<4;colonne++)
        {
            int i=ligne;
            //Meme principe de fusion que pour le d�placement vers le haut, en partant du bas
            if(uneMat[ligne][colonne]!=0)
            {
                do{
                    i--;        //une enl�ve 1 � i pour parcourir la colonne vers le haut
                }while(uneMat[i][colonne]==0);
                if(i>=0 && uneMat[ligne][colonne]==uneMat[i][colonne])
                {
                    uneMat[ligne][colonne]=uneMat[ligne][colonne]*2;
                    uneMat[i][colonne]=0;
                    *score=*score+uneMat[ligne][colonne];
                }
            }
        }
    }
    //Parcour de la matrice, m�me principe que pour le deplacement vers le haut mais en partant du bas
    ///Fusion des tuiles vers le bas
    for(int i=0; i<4; i++){
        ligne=(4-1)-i;
        for(colonne=0;colonne<4;colonne++){
            int i=ligne;
            if(uneMat[ligne][colonne]==0)
            {
                do{
                    i--;
                }while(uneMat[i][colonne]==0);
                if(i>=0 && uneMat[i][colonne]!=0){
                    uneMat[ligne][colonne]=uneMat[i][colonne];
                    uneMat[i][colonne]=0;

                }
            }
        }
    }
}

void deplacementGauche(int uneMat[][4], int* score){
int ligne, colonne;
    ///Fusion des tuiles vers la droite
    //Parcour de la matrice, on par de la droite de la ligne  pour la fusion et le deplacement des tuiles
    for(colonne=0; colonne<4; colonne++){   // On parcour la colonne avec cette premi�re boucle
        for(ligne=0;ligne<4;ligne++){
            int i=colonne;
            if(uneMat[ligne][colonne]!=0){  // puis on parcour la ligne de la colonne avec cette seconde boucle
            // On utilise le m�me principe que pour la fusion haut, mais en parcourant d'abord les lignes de chaque colonne
                do{
                    i++;    // on incr�mente i de 1 pour parcourir la ligne
                }while(uneMat[ligne][i]==0);
                if(i<4 && uneMat[ligne][colonne]==uneMat[ligne][i])
                {
                    uneMat[ligne][colonne]=uneMat[ligne][colonne]*2;
                    uneMat[ligne][i]=0;
                    *score=*score+uneMat[ligne][colonne];
                }
            }
        }
    }
    ///Deplacement des tuiles vers la droite
    //Parcour de la matrice, on par de la droite de la colonne
    // On utilise encore le m�me pricipe de deplacement, mais en parcourant d'abord les lignes de chaque colonne
    for(colonne=0; colonne<4; colonne++){
        for(ligne=0;ligne<4;ligne++){
            int i=colonne;
            if(uneMat[ligne][colonne]==0)
            {
                do{
                    i++;
                }while(uneMat[ligne][i]==0);
                if(i<4 && uneMat[ligne][i]!=0){
                    uneMat[ligne][colonne]=uneMat[ligne][i];
                    uneMat[ligne][i]=0;
                }
            }
        }
    }
}

void deplacementDroit(int uneMat[][4], int* score){
int ligne, colonne;
    ///Fusion des tuiles vers la droite
    //Parcour de la matrice, on par de la gauche de la ligne pour la fusion et le deplacement des tuiles
    for(int i=0; i<4; i++)
    {
        colonne=(4-1)-i;
        for(ligne=0;ligne<4;ligne++)
        {
            int i=colonne;
            if(uneMat[ligne][colonne]!=0)
            {
                // On utilise le m�me principe que pour la fusion gauche, mais en parcourant les lignes de gauche � droite
                do{
                    i--;
                }while(uneMat[ligne][i]==0);
                if(i>=0 && uneMat[ligne][colonne]==uneMat[ligne][i])
                {
                    uneMat[ligne][colonne]=uneMat[ligne][colonne]*2;
                    uneMat[ligne][i]=0;
                    *score=*score+uneMat[ligne][colonne];
                }
            }
        }
    }
    ///Deplacement des tuiles vers la droite
    //Parcour de la matrice, on par du bas pour la fusion et le deplacement des tuiles
    for(int i=0; i<4; i++){
        colonne=(4-1)-i;
        for(ligne=0;ligne<4;ligne++){
            int i=colonne;
            if(uneMat[ligne][colonne]==0)
            {
                // On utilise le m�me principe que pour le deplacement gauche, mais en parcourant les lignes de gauche � droite
                do{
                    i--;
                }while(uneMat[ligne][i]==0);
                if(i>=0 && uneMat[ligne][i]!=0){
                    uneMat[ligne][colonne]=uneMat[ligne][i];
                    uneMat[ligne][i]=0;
                }
            }
        }
    }
}

void deplacement(int uneMat[][4], int* score){
int laTouche;           // Variable utilis� pour r�cup�rer le code ASCII de la touche rentr�
int laMatBis[4][4];     // Matrice temporaire utilis� pour executer les instructions et v�rifi� qu'elle change
bool test=false;        // Variable bool�enne permettznt la v�rification de la matrice, si on peut encore la modifi� (false) ou pas (true)
   copie(uneMat, laMatBis);     // On copie la matrice � l'aide de la procedure copie()
    while(estEgale(laMatBis, uneMat) && test==false)    // On execute les instructions tant que la mattrice n'a pas chang� ou qu'elle est encore modifiable
    {
        laTouche = getch();                 // On recup�re le code ASCII de la touche rentr�
        while(laTouche != 224)              // On v�rifie la valeur de la touche (224 suivit d'une autre valeur pour les fl�ches directioonnelle
        {
            printf("ERREUR, utiliser les fleches directionnelle\n");  // On revoie ce message si la touche rentr� est autre qu'un fl�che directionnelle
            laTouche=getch();                                       // et on recup�re le code ASCII
        }
        laTouche = getch();                 // On recup�re le  code ASCII suivant '224'
        switch (laTouche)                   // execution des proc�dures en fonction de la valeur de la touche
        {
            case 72: deplacementHaut(laMatBis, score);    // fl�che haute
            break;
            case 80: deplacementBas(laMatBis, score);     // fl�che basse
            break;
            case 77: deplacementDroit(laMatBis, score);   // fl�che droite
            break;
            case 75: deplacementGauche(laMatBis, score);  // fl�che gauche
            break;
        }
        test=verification(uneMat);      // On v�rifie que la matrice est encore modifiable (on sort de la boucle sinon grace � la variable test
    }
    copie(laMatBis, uneMat);            // On copie la matrice temporaire apr�s que le deplacement � �t� effectu�
}

bool verification(int uneMat[][4]){
int uneMatTest[4][4];   // Matrice temporaire utilis� pour effectu� les d�placement sans modifi� la matrice d'origine
int score=0;            // score quelconque pour utilis� les proc�dure de deplacement
    if(!estPleine(uneMat))return false;     // On verifie que la matrice est bien pleine, sinon on retourne faux
    copie(uneMat, uneMatTest);
    deplacementHaut(uneMatTest, &score);            // On effectue le d�placement haut sur la matrice de test
    if(!estEgale(uneMatTest, uneMat))return false;          // Si la matrice � chang�, on retourne faux
    deplacementBas(uneMatTest, &score);             // On effectue le d�placement bas sur la matrice de test
    if(!estEgale(uneMatTest, uneMat))return false;          // Si la matrice � chang�, on retourne faux
    deplacementDroit(uneMatTest, &score);           // On effectue le d�placement droit sur la matrice de test
    if(!estEgale(uneMatTest, uneMat))return false;          // Si la matrice � chang�, on retourne faux
    deplacementGauche(uneMatTest, &score);          // On effectue le d�placement gauche sur la matrice de test
    if(!estEgale(uneMatTest, uneMat))return false;          // Si la matrice � chang�, on retourne faux
    return true;    // Si il n'y a eu aucun changement on retourne vrai
}

int meilleurScore(){
FILE* fichierScore = NULL;  // Variable destin� � contenir le ponteur sur le fichier des scores, initialis� � NULL
int leMeilleurScore;        // variable destin� � r�cup�rer la valeur du meilleur score

    fichierScore = fopen("score.txt", "r");         // Ouverture du fichier en mode lecture
    if(fichierScore == NULL)                        // Si le fichier n'existe pas,
    {
        fclose(fichierScore);                       // On ferme le fichier
        fichierScore = fopen("score.txt", "w");     // On le r�ouvre en mode ecriture (cela cr�e le fichier)
        fputc('0',fichierScore);                    // On �crit la valeur 0 dans le fichier
        fclose(fichierScore);                       // On referme le fichier
        fichierScore = fopen("score.txt", "r");     // On le r�ouvre en mode lecture
    }
    fscanf(fichierScore,"%d",&leMeilleurScore);     // On recup�re le prmier nombre �crit dans le fichier
    fclose(fichierScore);                           // On referme le fichier
    return leMeilleurScore;     // On revoie la valeur du meilleur score
}

bool maximumAtteint(int Mat[][4]){
    //on parcoure les matrices avec deux boucles
    for(int ligne=0; ligne<4; ligne++){
        for(int colonne=0;colonne<4;colonne++){
            if(Mat[ligne][colonne]== 131072 )return true;   // Si une tuile contient la valeur maximum (131 072), on retourne vrai
        }
    }
    return false;        //Sinon on retourne faux
}

void changeScore(int unScore, int* unMeilleurScore, bool Max){
FILE* fichierScore = NULL;      // Variable destin� � contenir le ponteur sur le fichier des scores, initialis� � NULL
char Score[20] = "";            // variable permettant de recup�rer la valeur des scores de chaque ligne dansd le fichier, sous forme de chaine de caract�re
char lesScores[200] = "";       // varible destin� � recevoir tous les scores du fichier, sous forme de chaine de caract�re
int i;
    // On �crit une phrase en fonction de la valeur de Max (si la valeur maximal est atteinte ou pas
    if(Max)printf(" \n \t BRAVO valeur maximal atteinte");
    else printf(" \n \t PERDU");;
    if(*unMeilleurScore < unScore)
    {
        i=0;
        if(*unMeilleurScore==0)fichierScore = fopen("score.txt", "w+"); // Si le meilleur score est 0, on ouvre le fichier en mode lecture et �criture, avec suppression du contenu au pr�alable
        else
        {
            fichierScore = fopen("score.txt", "r");         // Sinon on ouvre le fichier en mode lecture
            while(fgets(Score,100,fichierScore) != NULL)    // On lit le fichier tant qu'on ne re�oit pas de valeur NULL, signifiant la fin du fichier
            {
                if(i<9)strcat(lesScores, Score);            // On concat�ne la chaine contenant les scores avec la chaine contenant le score de la ligne, jusqu'a la neuvi�me ligne
                i++;         // On incr�mente i de 1 � chaque retour � la ligne
            }
            fclose(fichierScore);                           // On referme le fuichier
            fichierScore = fopen("score.txt", "w+");        // On ouvre le fichier en mode lecture et �criture, avec suppression du contenu au pr�alable
        }
        *unMeilleurScore=unScore;       // On modifie la valeur du meilleur score
        fprintf(fichierScore,"%d\n%s",*unMeilleurScore, lesScores);     // On ecrit le meilleur score et les 9 meilleures scores suivant
        fclose(fichierScore);                                           // On referme le fichier
        printf(" \t Nouveaux Meilleur Score:%d",*unMeilleurScore);      // On �crit la phrase de fin avec le nouveaux meilleur score
    }
}

void jeu2048(){
int laMat[4][4]={0};            // la Matrice utilis� pour le programme, initialis� � 0 comme �tant vide
int score=0;                    // le score, �tant actualis� � chaque fusion
bool Perdu = false;             // la variable pour savoir s'il est possible de modif� la matrice
bool Max = false;               // la variable permettant de savoir si la valeur maximal � �t� atteinte
int leMeilleurScore=meilleurScore();    // le meilleur score de tout les partis d�j� faite jusqu'a pr�sent
    srand(time(NULL));      // Fixe la fonction rand sur la valeur de l'heure, qui change tout le temps
    afficherMatrice(laMat, &score, leMeilleurScore);
    laMat[1][2]=2;
    laMat[3][2]=2;
    while (Perdu == false && Max == false)      // Le jeu s'execute tant que la matrice est encore modifiable ou que la valeur maximal n'a pas �tait atteinte
    {
        insertion(laMat);
        afficherMatrice(laMat, &score, leMeilleurScore);
        deplacement(laMat, &score);
        afficherMatrice(laMat, &score, leMeilleurScore);
        Perdu=verification(laMat);
        Max=maximumAtteint(laMat);
    }
    changeScore(score, &leMeilleurScore, Max);
}
