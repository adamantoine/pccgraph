//
//  pccgraph.c
//  
//
//  Created by I. Groz on 14/04/2016.
//
//

#include <stdio.h>
#include <string.h>

int nbligne(char *fic) { FILE* fp; int c=0; char flag=0;
    if ( (fp=fopen(fic,"rt"))==NULL) return 0;
    else
        while (!feof(fp))
            if (fgetc(fp)=='\n') {if (flag) c++; flag=0;}
            else flag=1;
    fclose(fp);
    return c;
}

int lecture(FILE* fp, char* mot) {
    char inter[512];
    int i,j;
    if (fscanf(fp,"%[^\n -]s",mot)==EOF) return 0;
    fscanf(fp,"%*c");
    for (i=j=0; mot[i]; i++)
        if (!ispunct(mot[i])) inter[j++]=mot[i];
        else if (mot[i]=='\'') j=0;
    inter[j]=0;
    strcpy(mot,inter);
    return 1;
}

int lectureLigneDico(char* mot, int n, FILE *fp) {
    if (fgets(mot,n,fp)==NULL) return 0;
    if (mot[strlen(mot)-1]<' ') mot[strlen(mot)-1]=0;
    return 1;
}


Liste creer_liste(void)
{
    return NULL;
}
int est_vide(Liste L)
{
    return !L;
}
/*void visualiser_liste(Liste L)
{
    Liste p;
    p=L;
    while(!est_vide(p))
    {
//        affiche(&p->carte);
        p=p->suiv;
    }
    
}
*/
Liste ajout_tete(Arc a,Liste L)
{
    Liste p;
    p=calloc(1,sizeof(*p));
    if(p==NULL) return NULL;
    p->arc.poids = a.poids;
    p->arc.pred = a.pred;
    p->arc.suiv = a.suiv;
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

Liste ajout_queue(Arc a,Liste L)
{
    Liste p,l;
    p=L;
    if(est_vide(L)) return ajout_tete(a,L);
    while(!est_vide(p->suiv))
    {
        p=p->suiv;
    }
    l=calloc(1,sizeof(*l));
    l->arc.poids = a.poids;
    l->arc.pred = a.pred;
    l->arc.suiv = a.suiv;
    l->suiv=NULL;
    p->suiv=l;
    return L;
}
/*
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

void visualiser_sommets(Sommets* s)
{
    Sommets* p;
    p=s;
    printf(" %lf %s %d   ",p->poids,p->station,p->No);
  
	}



void affiche_graphe(graphe g){
	int i;
	for(i=0;i<(g->nX);i++){
		visualiser_sommets(g->sommets+i);
		}
	for(i=0;i<(g->nX);i++){
		visualiser_liste(g->(sommets+i)->arc);
		}
	}


void detruit_graphe(graphe g)
{
    free(g->sommets);
    free(g);
}

void graphe_ecrit_nA(graphe g, unsigned int nA)
{
    if (g!=NULL) g->nA=nA;
}
void graphe_ecrit_nX(graphe g, unsigned int nX)
{
    if (g!=NULL) g->nX=nX;
}


unsigned int graphe_lit_nA(graphe g)
{
    if (g!=NULL) return g->nA;
}
unsigned int graphe_lit_nX(graphe g)
{
    if (g!=NULL) return g->nX;
}

void graphe_ecrit_poids(graphe g, unsigned int u, double val)
{
    Sommets* s;
    if (g!=NULL)
    {
        s=g->sommets;
        (s+u)->poids=val;
    }
}
double graphe_lit_poids(graphe g, unsigned int u)
{
    Sommets* s;
    if (g!=NULL)
    {
        s=g->sommets;
        return (s+u)->poids;
    }
}

void graphe_ecrit_poids_arc(graphe g, unsigned int u, unsigned int v, double val)
{
    Sommets* s;
    Liste l,p;
    unsigned int i=222222222222;
    if(g!=NULL)
    {
        s=g->sommets;
        if(s!=NULL)
        {
            l=(s+u)->arc;//??????????????????????????????????????????????????
            while(i!=v && l->suiv!=NULL)
            {
	         p=p->suiv;
                 i=(l->arc).pred;
            }
            if(i==v) (l->arc).poids=val;
            else printf("station d'arrivée pas existante v trop grand ecriture")
        }
        else printf("tableau de sommets non existant");
    }
    else printf("graphe non existant");
}
double graphe_lit_poids_arc(graphe g, unsigned int u, unsigned int v)
{
    Sommets* s;
    Liste l;
    unsigned int i=0;
    if(g!=NULL)
    {
        s=g->sommets;
        if(s!=NULL)
        {
            l=(s+u)->arc;
            while(i!=v && l->suiv!=NULL)
            {
                 i++;
                 l=l->suiv;
            }
            if(i==v) return (l->arc).poids;
            else 
            {
                printf("v trop grand lecture")
                return -1;
            }
        }
        else 
        {
             printf("tableau de sommets non existant");
             return -1;
        }
    }
    else
    {   
        printf("graphe non existant ou vide");
        return -1;
    }
}

graphe lit_graphe(char * fichier);
{
    if ((fp=fopen(fichier,"rt"))==NULL) return NULL;
    int i=0;
    unsigned int nX,nA;
    fscanf(fp,"%d %d",&nX,&nA);
    graphe g;
    g=nouveau_graphe(nX, nA);
    fgets(fp);
    for(i=0;i<nX;i++)
    {
    	 
    }
    fclose(fp);
}
void graphe_ajoute_arc(graphe g, unsigned int u, unsigned int v, double val);
double graphe_pcc(graphe g, unsigned int u, unsigned int v);
