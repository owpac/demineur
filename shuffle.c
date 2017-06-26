////  shuffle.c//  demineur////  Created by Thomas Faugier on 10/12/2016.//  Copyright � 2016 Thomas Faugier. All rights reserved.//#include "shuffle.h"/* Dans la plupart des contextes, un tableau est converti implicitement en un pointeur vers son premier �l�ment.  Dans les prototypes de fonction, la syntaxe des tableaux permet parfois de declarer un pointeur.  Une fonction ne peut prendre comme param�tre un tableau. On contourne cette limite en passant un pointeur vers le premier �l�ment du tableau, ce qui est facilit� par la conversion implicite du tableau en un pointeur vers son premier �l�ment.  Les tableaux multidimentionnels n'existent pas en C. On contourne en utilisant des tableaux de tableaux (il y a des langages qui ont les deux, ca apporte son lot de confusion). Si on veut passer un tableau bidimentionnel, donc un tableau de tableaux, � une fonction, on passe un pointeur vers le premier �l�ment du tableau, qui lui meme est un tableau. */void navette_knuth(int** matrice, int nbrColonnes, int nbrLignes){	int k = 0;	int taille = 0;		taille = nbrColonnes*nbrLignes;		//�change d'une case d'indice k avec une case d'indice al�atoire	for (k=0; k<taille-2; k++)	{		//le nombre al�atoire est tir� dans l'intervalle de [k; taille du tableau sur une dimension]		swap(matrice, nbrColonnes, k, nbr_aleatoire(k, taille-1));	}		return;}void swap(int** matrice, int nbrColonnes, int cellule, int celluleAleatoire){	int temp = 0;		//�change de la cellule matrice[(cellule-(cellule%nbrColonnes))/nbrColonnes][cellule%nbrColonnes] avec matrice[(celluleAleatoire-(celluleAleatoire%nbrColonnes))/nbrColonnes][celluleAleatoire%nbrColonnes]	temp = matrice[(cellule-(cellule%nbrColonnes))/nbrColonnes][cellule%nbrColonnes];		matrice[(cellule-(cellule%nbrColonnes))/nbrColonnes][cellule%nbrColonnes] = matrice[(celluleAleatoire-(celluleAleatoire%nbrColonnes))/nbrColonnes][celluleAleatoire%nbrColonnes];		matrice[(celluleAleatoire-(celluleAleatoire%nbrColonnes))/nbrColonnes][celluleAleatoire%nbrColonnes] = temp;		return;}int nbr_aleatoire(int min, int max){	//nombre al�atoire dans l'intervalle [min; max]	return (rand()%(max + 1 - min)) + min;}