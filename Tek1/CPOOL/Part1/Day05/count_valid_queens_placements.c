/*
** EPITECH PROJECT, 2022
** count_valid_queens_placements
** File description:
** count_valid_queens_placement
*/

int my_absolute(int nb)
{
    if (nb < 0)
        return -nb;
    return nb;
}

int placement(int pos, int *area)
{
    int i;

    for (i = 1; i < pos; i++) {
        if ((area[i] == area[pos]) ||
            ((my_absolute(area[i] - area[pos]) == my_absolute(i - pos))))
            return 0;
    }
    return 1;
}

int count_valid_queens_placements(int nb)
{
    int area[30];
    int count = 0;
    int k = 1;
    area[k] = 0;

    while (k != 0) {
        do {
            area[k]++;
        } while ((area[k] <= nb) && !placement(k, area));
        if (area[k] <= nb) {
            if (k == nb)
                count++;
            else {
                k++;
                area[k] = 0;
            }
        }else
            k--;
    }
    return count;
}
