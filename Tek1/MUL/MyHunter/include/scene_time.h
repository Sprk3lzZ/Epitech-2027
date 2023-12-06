/*
** EPITECH PROJECT, 2022
** time.h
** File description:
** time.h
*/

#pragma once

#include <SFML/Graphics.h>

#include "scene.h"

typedef struct {
    sfText *text;
    sfText *text2;
    sfFont *font;
    sfVector2f pos;
    char *str;
    float *time;
    int previous_time;
} scene_time_t;

scene_time_t *create_time(scene_t *scene, float *time);
void destroy_time(scene_time_t *time);
void update_time(scene_time_t *time, float dt);
void render_time(scene_time_t *time, scene_t *scene);
