/*
** EPITECH PROJECT, 2022
** game_over.c
** File description:
** game_over.c
*/

#include "game_over.h"
#include <stdlib.h>

void game_over_create(scene_t *scene)
{
    game_over_data_t *data = malloc(sizeof(game_over_data_t));

    data->font = sfFont_createFromFile("res/Fruit Days.ttf");
    data->text = sfText_create();
    sfText_setFont(data->text, data->font);
    sfText_setString(data->text, "Game Over");
    sfText_setCharacterSize(data->text, 60);
    sfText_setPosition(data->text, (sfVector2f){220, 85});
    scene->data = data;
}

void game_over_destroy(scene_t *scene)
{
    game_over_data_t *data = scene->data;

    sfFont_destroy(data->font);
    sfText_destroy(data->text);
    free(data);
}

void game_over_on_event(scene_t *scene, sfEvent *event)
{
    sfView *view;
    sfVector2u size;
    float aspect_ratio;

    if (event->type == sfEvtResized) {
        view = sfView_create();
        size = sfRenderWindow_getSize(scene->window);
        aspect_ratio = (float)size.x / (float)size.y;
        sfView_setCenter(view, (sfVector2f){360, 128});
        sfView_setSize(view, (sfVector2f){256 * aspect_ratio, 256});
        sfRenderWindow_setView(scene->window, view);
        sfView_destroy(view);
    }
}

void game_over_update(scene_t *scene, float dt)
{
    (void)scene;
    (void)dt;
}

void game_over_render(scene_t *scene)
{
    game_over_data_t *data = scene->data;

    sfRenderWindow_drawText(scene->window, data->text, NULL);
}
