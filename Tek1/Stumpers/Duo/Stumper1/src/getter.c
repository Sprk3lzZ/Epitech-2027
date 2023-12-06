int get_nb_lines(char *str)
{
    int nb_lines = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int get_nb_cols(char *str)
{
    int nb_cols = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        nb_cols++;
    }
    return nb_cols;
}

char *get_pattern(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
	if (str[i] == '@')
	    str[i] = '\n';
    }
    return str;
}
