#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief contains a value and the next element
 * in a list.
 */
struct element
{
    int val;
    struct element * suiv;
};

/**
 * @brief contains the last element (preferably NULL)
 * and the last added one.
 */
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

/**
 * @brief Create an element with a number associated
 * 
 * @param num int
 * @return struct element* the element
 */
struct element * createList(int num)
{
    struct element * vide=(struct element*)malloc(sizeof(struct element));
    vide->val=num;
    vide->suiv=NULL;
    return vide;
}

/**
 * @brief add a new element (int) to a given pointer list,
 * 
 * @param l  liste* the list you want to modify
 * @param val val int
 */
void ajoutfile(liste* l,int val)
{
    struct element* suivant=(struct element*)malloc(sizeof(struct element));
    suivant->val=val;
    suivant->suiv=l->premier;
    l->premier = suivant;
}

/**
 * @brief Delete the first element of the list
 * 
 * @param l liste * the list you want to modify
 */
void supprimefile(liste* l)
{
    struct element * oldElement = l->premier->suiv;
    free(l->premier);
    l->premier = oldElement;
}

/**
 * @brief Prints the given list in order
 * 
 * @param l liste
 */
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

/**
 * @brief Returns the size of a given list
 * 
 * @param l liste
 * @return int
 */
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

/**
 * @brief verify if a list is null
 * 
 * @param l 
 * @return true if the size of the given list is 0
 * @return false else
 */
bool isVoid(liste l)
{
    return sizeliste(l)==0;
}