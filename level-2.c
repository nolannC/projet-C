// Libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int age;

int main(void)
{
    /*
        Programme qui permet d'afficher les films pour une tranche d'âge et demande si l'utilisateur veux le voir
    */

    // listes des films
    string filmCategorieEnfant[] = {"Harry Potter à l'école des sorciers", "Harry Potter et la chambre des secrets", "Harry Potter et le prisonnier d'Askaban"};
    string filmCategorieAdos[] = {"Harry Potter et la coupe de feu", "Harry Potter et l'ordre du Phénix", "Harry Potter et le prince de sang-mêlé"};
    string filmCategorieAdulte[] = {"Harry Potter et les reliques de la mort - partie 1", "Harry Potter et les reliques de la mort - partie 2", "Matrix 1"};

    // demande de l'age
    age = get_int("Quel est votre âge ? ");

    // si l'utilisateur est trop jeune
    if (age <= 3)
    {
        printf("Entrée refusée !\n");
        return 0;
    }

    printf("Vous pouvez aller voir ce film : ");

    // si l'utilisateur est un enfant
    if (age > 3 && age < 11)
    {
        // affichage des films pour enfant
        for (int i = 0; i < 3; i++)
        {
            // affichage du premier film
            printf("%s\n", filmCategorieEnfant[i]);
            // demande si l'utilisateur veux garder ce film
            string voir = get_string("Voulez vous voir ce film ? (Oui/Non) ");
            //chaque caractere entrer par l'utilisateur est mis en minuscule pour sécurisé l'input
            for (int j = 0, n = strlen(voir); j < n; j++)
            {
                voir[j] = tolower(voir[j]);
            }
            // si la réponse est oui on affiche le choix sinon un reboucle au début
            if (strcmp(voir, "oui") == 0)
            {
                printf("Vous avez choisi %s.\n", filmCategorieEnfant[i]);
                printf("Bon film !\n");
                return 0;
            }
        }
    }
    // si l'utilisateur est un ado
    if (age >= 11 && age <= 17)
    {
        // affichage des films pour ado
        for (int i = 0; i < 3; i++)
        {
            // affichage du premier film
            printf("%s\n", filmCategorieAdos[i]);
            // demande si l'utilisateur veux garder ce film
            string voir = get_string("Voulez vous voir ce film ? (Oui/Non) ");
            //chaque caractere entrer par l'utilisateur est mis en minuscule pour sécurisé l'input
            for (int j = 0, n = strlen(voir); j < n; j++)
            {
                voir[j] = tolower(voir[j]);
            }
            // si la réponse est oui on affiche le choix sinon un reboucle au début
            if (strcmp(voir, "oui") == 0)
            {
                printf("Vous avez choisi %s.\n", filmCategorieAdos[i]);
                printf("Bon film !\n");
                return 0;
            }
        }
    }
    // si l'utilisateur est un adulte
    if (age >= 18)
    {
        // affichage des films pour adulte
        for (int i = 0; i < 3; i++)
        {
            // affichage du premier film
            printf("%s\n", filmCategorieAdulte[i]);
            // demande si l'utilisateur veux garder ce film
            string voir = get_string("Voulez vous voir ce film ? (Oui/Non) ");
            //chaque caractere entrer par l'utilisateur est mis en minuscule pour sécurisé l'input
            for (int j = 0, n = strlen(voir); j < n; j++)
            {
                voir[j] = tolower(voir[j]);
            }
            // si la réponse est oui on affiche le choix sinon un reboucle au début
            if (strcmp(voir, "oui") == 0)
            {
                printf("Vous avez choisi %s.\n", filmCategorieAdulte[i]);
                printf("Bon film !\n");
                return 0;
            }
        }
    }

}