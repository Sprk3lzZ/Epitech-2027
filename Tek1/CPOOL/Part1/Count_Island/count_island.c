/*
** EPITECH PROJECT, 2022
** count_island
** File description:
** count_island
*/

int expend(char **world, int i, int j, int counter)
{
    if (world[i][j] != 'X')
        return 0;
    world[i][j] = counter + '0';
    if (world[i + 1] != 0)
        expend(world, i + 1, j, counter);
    if (i != 0)
        expend(world, i - 1, j, counter);
    if (world[i][j + 1] != 0)
        expend(world, i, j + 1, counter);
    if (j != 0)
        expend(world, i, j - 1, counter);
    return 1;
}

int count_island(char **world)
{
    int number_of_island = 0;

    for (int i = 0; world[i] != 0; i++) {
        for (int j = 0; world[i][j] != 0; j++) {
            number_of_island += expend(world, i, j, number_of_island);
        }
    }
    return number_of_island;
}
