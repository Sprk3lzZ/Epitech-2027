#include "fractals.h"
char *tab_of_patterns(char *str, int size_map)
{
    str[my_strlen(str) - 1] = '\0';

    char **tab = malloc(size_of(char) * size_map + 1);

    for (int i = 0; i < size_map; i++)
        tab[i] = malloc(sizeof(char) * size_map + 1);
    for (int i = 0; i < size_map; i++) {
	for (int j = 0; j < size_map; j++)
	    
    }
}

char *create_map(int nb_cols)
{
    char *map = malloc(sizeof(char) * (nb_cols * nb_cols) + nb_cols);
    int i = 0;
    int col = 0;

    while (i <= nb_cols * nb_cols + nb_cols - 1) {
	col++;
	if (col == nb_cols + 1) {
	    map[i] = '\n';
	    col = 0;
	} else {
	    map[i] = '*';
	}
        i++;
    }
    map[i] = '\0';
    return map;
}

int main(int ac, char **av)
{
    char *pattern_1 = get_pattern(av[2]);
    char *pattern_2 = get_pattern(av[3]);
    int iteration = my_getnbr(av[1]);
    int size_map = my_strlen(pattern_1) - get_nb_cols(pattern_1) + 1;

    int test = my_compute_power_rec(size_map, iteration);
    int nb_cols = my_compute_power_rec(get_nb_cols(pattern_1), iteration);
    char *map = create_map(nb_cols);
    printf("%s\n", tab_of_patterns(map));
}
