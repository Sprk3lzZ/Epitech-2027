/*
** EPITECH PROJECT, 2022
** life.c
** File description:
** life.c
*/

#include "life.h"
#include "bird.h"
#include "my.h"
#include <stdlib.h>

static void life_text(life_t *life)
{
    life->text2 = sfText_create();
    sfText_setString(life->text2, "Life: ");
    sfText_setFont(life->text2, life->font);
    sfText_setCharacterSize(life->text2, 13);
    sfText_setPosition(life->text2, (sfVector2f) {165, 230});
}

life_t *create_life(__attribute((unused)) scene_t *scene, int *l)
{
    life_t *life = malloc(sizeof(life_t));

    life->life = l;
    life->previous_life = *l;
    life->font = sfFont_createFromFile("res/Fruit Days.ttf");
    life->text = sfText_create();
    life->str = my_strdup("3");
    sfText_setString(life->text, life->str);
    sfText_setFont(life->text, life->font);
    sfText_setCharacterSize(life->text, 12);
    sfText_setPosition(life->text, (sfVector2f) {200, 230});
    life_text(life);
    return life;
}

void destroy_life(life_t *life)
{
    free(life->str);
    sfFont_destroy(life->font);
    sfText_destroy(life->text);
}

void update_life(life_t *life, __attribute((unused)) float dt)
{
    if (life->previous_life != *life->life) {
        free(life->str);
        life->str = malloc(sizeof(char) * 100);
        sfText_setString(life->text, number_to_string(*life->life));
        life->previous_life = *life->life;
    }
}

void render_life(life_t *life, scene_t *scene)
{
    sfRenderWindow_drawText(scene->window, life->text, NULL);
    sfRenderWindow_drawText(scene->window, life->text2, NULL);
}
