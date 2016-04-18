//
//  pccgraph.c
//  
//
//  Created by I. Groz on 14/04/2016.
//
//



/*
Liste creer_liste(void)
{
    return NULL;
}
int est_vide(Liste L)
{
    return !L;
}
void visualiser_liste(Liste L)
{
    Liste p;
    p=L;
    while(!est_vide(p))
    {
//        affiche(&p->carte);
        p=p->suiv;
    }
    
}
Liste ajout_tete(Arc a,Liste L)
{
    Liste p;
    p=calloc(1,sizeof(*p));
    if(p==NULL) return NULL;
//
    p->suiv=L;
    return p;
}
Liste supprimer_tete(Liste L)
{
    if(!est_vide(L))
    {
        Liste p;
        p=L->suiv;
        free(L);
        return(p);
    }
    return NULL;
}
Liste ajout_queue(CARTE c,Liste L)
{
    Liste p,l;
    p=L;
    if(est_vide(L)) return ajout_tete(c,L);
    while(!est_vide(p->suiv))
    {
        p=p->suiv;
    }
    l=calloc(1,sizeof(*l));
    l->carte.rang = c.rang;
    l->carte.visible = c.visible;
    l->carte.couleur = c.couleur;
    l->suiv=NULL;
    p->suiv=l;
    return L;
}
Liste supprimen(int n, Liste L)
{
    Liste p,l;
    p=L;
    int i;
    if(est_vide(L)) return L;
    if(n==1) return supprimer_tete(L);
    for(i=1;i<n-1;i++)
    {
        if(est_vide(p->suiv))
        {
            printf("Fin de la liste");
            return L;
        }
        p=p->suiv;
    }
    if(p->suiv==NULL)
    {
        printf("Fin de la liste");
        return L;
    }
    l=p;
    l=(l->suiv)->suiv;
    free(p->suiv);
    p->suiv=l;
    return L;
}

Liste concat(Liste L1, Liste L2)
{
    Liste l;
    l=L2;
    while(!est_vide(l))
    {
        L1=ajout_queue(l->carte,L1);
        l=l->suiv;
    }
    return L1;
}
Liste copie(Liste L)
{
    Liste p=NULL,l=L;
    while(!est_vide(l))
    {
        p=ajout_queue(l->carte,p);
        l=l->suiv;
    }
    return p;
}


*/
#include "pccgraph.h"
graphe nouveau_graphe(unsigned int nX,unsigned int nA)
{
    graphe g;
    g=calloc(1,sizeof(*g));
    if(g==NULL)
    {
        printf("erreur d'allocation memoire graphe\n");
        return NULL;
    }
    g->nX=nX;
    g->nA=nA;
    g->sommets=calloc(nX,sizeof(Sommets));
    if(g->sommets==NULL)
    {
        printf("erreur d'allocation memoire tableau sommets\n");
        return NULL;
    }
    return g;
}

//void affiche_graphe(graphe g)


void detruit_graphe(graphe g)
{
    free(g->sommets);
    free(g);
}

//void graphe_ecrit_nA(graphe g, unsigned int nA)

void graphe_ecrit_nX(graphe g, unsigned int nX)
{
    if (g!=NULL) g->nX=nX;
}


//unsigned int graphe_lit_nA(graphe g)

unsigned int graphe_lit_nX(graphe g);
{
    if (g!=NULL) return g->nX;
}

//void graphe_ecrit_poids(graphe g, unsigned int u, double val)

double graphe_lit_poids(graphe g, unsigned int u);
{
    Sommets* s;
    if (g!=NULL)
    {
        s=g->sommets;
        return *(s+u)->poids
    }
}

//void graphe_ecrit_poids_arc(graphe g, unsigned int u, unsigned int v, double val);

double graphe_lit_poids_arc(graphe g, unsigned int u, unsigned int v)
