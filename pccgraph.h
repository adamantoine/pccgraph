//
//  pccgraph.h
//  
//
//  Created by I. Groz on 14/04/2016.
//
//

#ifndef pccgraph_h
#define pccgraph_h

#include <stdio.h>
#include <stdlib.h>
/*struct liste {
 Arc arc;
 struct liste *suiv;};
 typedef struct liste * Liste;
 
 Liste creer_liste(void);
 int est_vide(Liste L);
 void visualiser_liste(Liste L);
 Liste ajout_tete(CARTE c,Liste L);
 Liste supprimer_tete(Liste L);
 Liste ajout_queue(CARTE c,Liste L);
 Liste supprimen(int n, Liste L);
 Liste concat(Liste L1, Liste L2);
 Liste copie(Liste L);
 */


typedef struct {
    unsigned int nX;
    unsigned int nA;
    Sommets * sommets;
} * graphe;
typedef struct {
    double poids;
    unsigned int ;
    Liste * arc;
    
} * Sommets;
typedef struct {
    double poids;
    unsigned int pred;
    unsigned int dest;
} * Arc;

graphe nouveau_graphe(unsigned int nX,unsigned int nA);
void affiche_graphe(graphe g);
void detruit_graphe(graphe g);
void graphe_ecrit_nA(graphe g, unsigned int nA);
void graphe_ecrit_nX(graphe g, unsigned int nX);
unsigned int graphe_lit_nA(graphe g);
unsigned int graphe_lit_nX(graphe g);
void graphe_ecrit_poids(graphe g, unsigned int u, double val);
double graphe_lit_poids(graphe g, unsigned int u);
void graphe_ecrit_poids_arc(graphe g, unsigned int u, unsigned int v, double val);
double graphe_lit_poids_arc(graphe g, unsigned int u, unsigned int v);
graphe lit_graphe(char * fichier);
void graphe_ajoute_arc(graphe g, unsigned int u, unsigned int v, double val);
double graphe_pcc(graphe g, unsigned int u, unsigned int v);
#endif /* pccgraph_h */
