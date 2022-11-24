#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct element
{
    int val;
    struct element * suiv;
};

typedef struct
{
    struct element * premier;
    struct element * dernier;
} liste;

void init(liste * l);
struct element * createList(int num);
void ajoutfile(liste* l,int val);
void supprimefile(liste* l);
void printlist(liste l);
int sizeliste(liste l);
bool isVoid(liste l);

int main(void)
{
    liste l1,l2;
    init(&l1);
    init(&l2);
    ajoutfile(&l1,56);
    ajoutfile(&l1,23);
    ajoutfile(&l1,12);
    printlist(l1);
    printf("Sizeliste : %d\n",sizeliste(l1));
    supprimefile(&l1);
    printlist(l1);
    printf("Sizeliste : %d\n",sizeliste(l1));
    printf("\n L2 ---\n");
    printf("Is void ? %d\n",isVoid(l2));
    return 0;
}

/**
 * @brief Initialize a list
 * 
 * @param l (liste *) 
 */
void init(liste * l)
{
    l->premier = createList(0);
    l->dernier = createList(0);
}

struct element * createList(int num)
{
    struct element * vide=(struct element*)malloc(sizeof(struct element));
    vide->val=num;
    vide->suiv=NULL;
    return vide;
}

void ajoutfile(liste* l,int val)
{
    struct element* suivant=(struct element*)malloc(sizeof(struct element));
    suivant->val=val;
    suivant->suiv=l->premier;
    l->premier = suivant;
}

void supprimefile(liste* l)
{
    struct element * oldElement = l->premier->suiv;
    free(l->premier);
    l->premier = oldElement;
}

void printlist(liste l)
{
    struct element * ePremier = l.premier;
    struct element * eDernier = l.dernier;
    while(ePremier->suiv != eDernier->suiv)
    {
        printf("%d, ",ePremier->val);
        ePremier=ePremier->suiv;
    }
    printf("NULL \n");
}

int sizeliste(liste l)
{
    int returnValue=0;
    struct element * vide = l.dernier;
    struct element * e = l.premier;
    while(e->suiv != vide->suiv)
    {
        returnValue++;
        e = e->suiv;
    }
    return returnValue;
}

bool isVoid(liste l)
{
    return sizeliste(l)==0;
}