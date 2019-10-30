/*
** EPITECH PROJECT, 2018
** infinadd
** File description:
** infinadd
*/

#include <stdlib.h>
#include "include/my.h"

int mama(char **av)
{
    int i = 1;
    int tmp = 0;
    int len_nb1 = my_strlen(av[1]);
    int len_nb2 = my_strlen(av[2]);

    while (i <= len_nb1)
    {
        if (i <= len_nb2)
            tmp = ((av[1][len_nb1 - i] - 48) +
                   (av[2][len_nb2 - i] - 48) +
                   tmp) / 10;
        else
            tmp = ((av[1][len_nb1 - i] - 48) +
                   tmp) / 10;
        i++;
    }
    return (i + tmp);
}

char *res(char **av)
{
    int nb1 = my_strlen(av[1]);
    int nb2 = my_strlen(av[2]);
    char *result;
    char *hop;

    if (nb1 < nb2){
        hop = av[1];
        av[1] = av[2];
        av[2] = hop;
    }
    result = malloc(sizeof(char) * mama(av));
    return (result);
}

char *infinadd(char **av)
{
    char *result = res(av);
    int i = 1;
    int tmp = 0;
    int len_res = mama(av) - 1;
    int len_nb1 = my_strlen(av[1]);
    int len_nb2 = my_strlen(av[2]);

    while (i <= len_nb1)
    {
      if (i <= len_nb2) {
          result[len_res - i] = ((av[1][len_nb1 - i] - 48) +
                                 (av[2][len_nb2 - i] - 48) + tmp) % 10 + 48;
          tmp = ((av[1][len_nb1 - i] - 48) + (av[2][len_nb2 - i] - 48) +
                 tmp) / 10;
      }else{
          result[len_res - i] = ((av[1][len_nb1 - i] - 48) + tmp) % 10 + 48;
          tmp = ((av[1][len_nb1 - i] - 48) + tmp) / 10;
      }
      i++;
    }
    if (tmp != 0)
        result[len_res - i] = tmp + 48;
    result[len_res] = '\0';
    return result;
}

int main(int ac, char **av)
{
    char *result = infinadd(av);
    my_putstr(result);
    return (0);
}
