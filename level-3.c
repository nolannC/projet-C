// Libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Initialisation des fonctions
int show_film(string arr[3][3], int index);
string toLower(string str);

int main(void)
{
    /*
        Programme qui permet d'afficher les films pour une tranche d'âge et demande si l'utilisateur veux le voir
    */

    // listes des films
    string films[3][3] =
    {
        {"Harry Potter à l'école des sorciers", "Harry Potter et la chambre des secrets", "Harry Potter et le prisonnier d'Askaban"},
        {"Harry Potter et la coupe de feu", "Harry Potter et l'ordre du Phénix", "Harry Potter et le prince de sang-mêlé"},
        {"Harry Potter et les reliques de la mort - partie 1", "Harry Potter et les reliques de la mort - partie 2", "Matrix 1"}
    };

    // demande de l'age
    int age = get_int("Quel est votre âge ? ");

    // si l'utilisateur est trop jeune
    if (age <= 3)
    {
        printf("Entrée refusée, vous êtes trop jeune !\n");
        return 1;
    }

    printf("Vous pouvez aller voir ce film : ");

    // si l'utilisateur est un enfant
    if (age > 3 && age < 11)
    {
        int result = show_film(films, 0);
        if (result == 0)
        {
            return 0;
        }
        printf("Vous êtes compliqués !\n");
    }
    // si l'utilisateur est un ado
    if (age >= 11 && age <= 17)
    {
        // on commence par les films pour ados puis enfants
        for (int cat = 1; cat >= 0; cat--)
        {
            int result = show_film(films, cat);
            if (result == 0)
            {
                return 0;
            }
        }
        printf("Vous êtes compliqués !\n");
    }
    // si l'utilisateur est un adulte
    if (age >= 18)
    {
        // on commence par les films pour adultes puis ados et enfin enfants
        int result = show_film(films, 2);
        if (result == 0)
        {
            return 0;
        }
        string next = get_string("Quelle autre catégorie pourrais vous plaire ? (Enfant/Ado) ");
        next = toLower(next);
        if (strcmp(next, "enfant") == 0)
        {
            result = show_film(films, 0);
        }
        if (strcmp(next, "ado") == 0)
        {
            result = show_film(films, 1);
        }
        if (result == 0)
        {
            return 0;
        }

        printf("Vous êtes compliqués !\n");
    }

}

int show_film(string arr[3][3], int index)
{
    /*
        Fonction qui affiche les films par catégorie (grâce â l'index)
    */
    // affichage des films
    for (int i = 0; i < 3; i++)
    {
        // affichage du premier film
        printf("%s\n", arr[index][i]);
        // demande si l'utilisateur veux garder ce film
        string voir = get_string("Voulez vous voir ce film ? (Oui/Non) ");
        //chaque caractere entrer par l'utilisateur est mis en minuscule pour sécurisé l'input
        voir = toLower(voir);
        // si la réponse est oui on affiche le choix sinon un reboucle au début
        if (strcmp(voir, "oui") == 0)
        {
            printf("Vous avez choisi %s.\n", arr[index][i]);
            printf("Bon film !\n");
            return 0;
        }
    }
    return 1;
}

string toLower(string str)
{
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}