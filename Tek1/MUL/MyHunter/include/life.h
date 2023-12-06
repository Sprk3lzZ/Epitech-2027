/*
** EPITECH PROJECT, 2022
** life.h
** File description:
** life.h
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
    int previous_life;
    int *life;
} life_t;

life_t *create_life(scene_t *scene, int *life);
void destroy_life(life_t *score);
void update_life(life_t *life, float dt);
void render_life(life_t *life, scene_t *scene);
