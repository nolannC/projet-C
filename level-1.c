// Libraries
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*
        Programme qui permet d'afficher les films pour une tranche d'âge
    */

    // listes des films
    string filmCategorieEnfant[] = {"Harry Potter à l'école des sorciers", "Harry Potter et la chambre des secrets", "Harry Potter et le prisonnier d'Askaban"};
    string filmCategorieAdos[] = {"Harry Potter et la coupe de feu", "Harry Potter et l'ordre du Phénix", "Harry Potter et le prince de sang-mêlé"};
    string filmCategorieAdulte[] = {"Harry Potter et les reliques de la mort - partie 1", "Harry Potter et les reliques de la mort - partie 2", "Matrix 1"};

    // demande de l'age
    int age = get_int("Quel est votre âge ? ");

    // si l'utilisateur est trop jeune
    if (age <= 3)
    {
        printf("Entrée refusée !\n");
        return 0;
    }

    printf("Vous pouvez aller voir les films suivants : \n");

    // si l'utilisateur est un enfant
    if (age > 3 && age < 11)
    {
        // affichage des films pour enfant
        for (int i = 0; i < 3; i++)
        {
            printf("- %s\n", filmCategorieEnfant[i]);
        }
    }
    // si l'utilisateur est un ado
    if (age >= 11 && age <= 17)
    {
        // affichage des films pour ado
        for (int i = 0; i < 3; i++)
        {
            printf("- %s\n", filmCategorieAdos[i]);
        }
    }
    // si l'utilisateur est un adulte
    if (age >= 18)
    {
        // affichage des films pour adulte
        for (int i = 0; i < 3; i++)
        {
            printf("- %s\n", filmCategorieAdulte[i]);
        }
    }

}