#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <math.h>


void jeu2048();     //porcédure coprs du programme tous les appels de fonctions et les initialisations de variables se font dedans

bool estEgale(int uneMat1[][4],int uneMat2[][4]);   //fonction booléenne renvoyant vrai si les deux matrices rentré sont égalles

bool estVide(int uneMat[][4]);                      //fonction booléenne renvoyant vrai si la matrice rentré est vide

bool estPleine(int uneMat[][4]);                    //fonction booléenne renvoyant vrai si la matrice rentré est pleine

void copie(int uneMat[][4], int uneMatCopie[][4]);  //procedure faisant la coipie de uneMat dans uneMatCopie (uneMatCopie dois être créé au préalable)

void afficherMatrice(int uneMat[][4], int* score, int meilleurScore);  //procedure permettant l'affichage de la matrice

void insertion(int uneMat [][4]);     //procedure insérant un 2 ou un 4 dans la matrice

void deplacement(int uneMat[][4], int* score, int leMeilleurScore); //procedure recuperant la valeur de la touche tapé, appellant ensuite la procedure correspondante

void deplacementHaut(int uneMat[][4], int* score);      //procedure permettant le déplacement et la fusuion des tuiles vers le haut

void deplacementBas(int uneMat[][4], int* score);       //procedure permettant le déplacement et la fusuion des tuiles vers le bas

void deplacementDroit(int uneMat[][4], int* score);     //procedure permettant le déplacement et la fusuion des tuiles vers la droite

void deplacementGauche(int uneMat[][4], int* score);    //procedure permettant le déplacement et la fusuion des tuiles vers la gauche

bool verification(int uneMat[][4]);         //procedure booléenne renvoyant vrai si la matrice ne peut plus être modifié

bool maximumAtteint(int uneMat[][4]);       //procedure booléenne renvoyant vrai si la matrice contient la valeur maximum

int meilleurScore();                        // fonction renvoyant la valeur du meilleur score effectué

void changeScore(int unScore, int* unMeilleurScore, bool Max);    //procedure ajoutant le nouveaux meilleur score à la feuille de score et renvoyant la phrase de fin
