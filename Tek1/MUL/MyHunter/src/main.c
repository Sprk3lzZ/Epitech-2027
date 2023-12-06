/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main.c
*/

#include "app.h"
#include "game.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void help(void)
{
    write(1, "USAGE :\n", 9);
    write(1, "        ./my_hunter\nDESSCRIPTION:\n", 35);
    write(1, "        It's a remake of the famous game, Flappy Bird, it's", 60);
    write(1, "like a AimLab,\n        the goal is to shot every ", 50);
    write(1, "bird with left or righ click of the mouse without miss.\n", 56);
    write(1, "        You have 3 life, if you miss a bird you lose one life.\n"
    , 64);
}

int main(int ac, char **av, char **env)
{
    if (ac > 2 || env[0] == NULL)
        return 84;
    if (ac == 2 && (av[1][0] != '-' || av[1][1] != 'h'))
        return 84;
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h')) {
        help();
        return 0;
    }
    app_t *app = app_create(1280, 720, "Aim Lab Flappy Bird");
    scene_t *scene = malloc(sizeof(scene_t));
    scene->create = game_create;
    scene->destroy = game_destroy;
    scene->on_event = game_on_event;
    scene->update = game_update;
    scene->render = game_render;
    srand(time(NULL));
    app_set_scene(app, scene);
    app_run(app);
    app_destroy(app);
    return 0;
}
