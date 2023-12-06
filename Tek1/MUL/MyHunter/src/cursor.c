/*
** EPITECH PROJECT, 2022
** cursor.c
** File description:
** cursor.c
*/

#include "cursor.h"
#include <stdlib.h>

cursor_t *create_cursor(scene_t *scene)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->texture = sfTexture_createFromFile("res/cursor.png", NULL);
    cursor->sprite = sfSprite_create();
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    sfSprite_setPosition(cursor->sprite, (sfVector2f){0, 0});
    sfSprite_setScale(cursor->sprite, (sfVector2f){0.5, 0.5});
    sfRenderWindow_setMouseCursorVisible(scene->window, sfFalse);
    return cursor;
}

void destroy_cursor(scene_t *scene, cursor_t *cursor)
{
    sfRenderWindow_setMouseCursorVisible(scene->window, sfTrue);
    sfSprite_destroy(cursor->sprite);
    sfTexture_destroy(cursor->texture);
    free(cursor);
}

void update_cursor(scene_t *scene, cursor_t *cursor)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(scene->window);
    sfVector2f mouse_pos_f = sfRenderWindow_mapPixelToCoords(scene->window,
    mouse_pos, NULL);

    mouse_pos_f.x -= 55 / 2.0f;
    mouse_pos_f.y -= 23 / 2.0f;
    sfSprite_setPosition(cursor->sprite, mouse_pos_f);
}

void render_cursor(scene_t *scene, cursor_t *cursor)
{
    sfRenderWindow_drawSprite(scene->window, cursor->sprite, NULL);
}
