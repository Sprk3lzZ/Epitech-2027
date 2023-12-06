/*
** EPITECH PROJECT, 2022
** time.c
** File description:
** time.c
*/

#include "scene_time.h"
#include "bird.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

static void time_text(scene_time_t *time)
{
    time->text2 = sfText_create();
    sfText_setString(time->text2, "Time: ");
    sfText_setFont(time->text2, time->font);
    sfText_setCharacterSize(time->text2, 13);
    sfText_setPosition(time->text2, (sfVector2f) {325, 230});
}

scene_time_t *create_time(__attribute((unused)) scene_t *scene, float *t)
{
    scene_time_t *time = malloc(sizeof(scene_time_t));

    time->time = t;
    time->previous_time = *t;
    time->font = sfFont_createFromFile("res/Fruit Days.ttf");
    time->text = sfText_create();
    time->str = my_strdup("0");
    sfText_setString(time->text, time->str);
    sfText_setFont(time->text, time->font);
    sfText_setCharacterSize(time->text, 12);
    sfText_setPosition(time->text, (sfVector2f) {375, 230});
    time_text(time);
    return time;
}

void destroy_time(scene_time_t *time)
{
    free(time->str);
    sfFont_destroy(time->font);
    sfText_destroy(time->text);
}

void update_time(scene_time_t *time, float dt)
{
    *time->time += dt;
    if (time->previous_time != *time->time) {
        free(time->str);
        time->str = malloc(sizeof(char) * 50);
        sfText_setString(time->text, number_to_string((int)*time->time));
        time->previous_time = *time->time;
    }
}

void render_time(scene_time_t *time, scene_t *scene)
{
    sfRenderWindow_drawText(scene->window, time->text, NULL);
    sfRenderWindow_drawText(scene->window, time->text2, NULL);
}
