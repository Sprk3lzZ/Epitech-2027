/*
** EPITECH PROJECT, 2022
** background.c
** File description:
** background.c
*/

#include "background.h"

#include <stdlib.h>

background_t *create_background(scene_t *scene, sfTexture *spritesheet)
{
    background_t *background = malloc(sizeof(background_t));
    sfView *view = sfView_create();
    sfVector2u size = sfRenderWindow_getSize(scene->window);
    float aspect_ratio = (float)size.x / (float)size.y;

    sfView_setCenter(view, (sfVector2f){360, 128});
    sfView_setSize(view, (sfVector2f){256 * aspect_ratio, 256});
    sfRenderWindow_setView(scene->window, view);
    sfView_destroy(view);
    background->scene = scene;
    background->texture = spritesheet;
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setTextureRect(background->sprite, (sfIntRect){0, 0, 144, 256});
    return background;
}

void destroy_background(background_t *bg)
{
    sfSprite_destroy(bg->sprite);
    free(bg);
}

void on_event_background(background_t *bg, sfEvent *event)
{
    sfView *view;
    sfVector2u size;
    float aspect_ratio;

    if (event->type == sfEvtResized) {
        view = sfView_create();
        size = sfRenderWindow_getSize(bg->scene->window);
        aspect_ratio = (float)size.x / (float)size.y;
        sfView_setCenter(view, (sfVector2f){360, 128});
        sfView_setSize(view, (sfVector2f){256 * aspect_ratio, 256});
        sfRenderWindow_setView(bg->scene->window, view);
        sfView_destroy(view);
    }
}

void render_background(background_t *bg)
{
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(bg->sprite, (sfVector2f){144 * i, 0});
        sfRenderWindow_drawSprite(bg->scene->window, bg->sprite, NULL);
    }
}
