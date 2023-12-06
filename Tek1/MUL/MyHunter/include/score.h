/*
** EPITECH PROJECT, 2022
** score.h
** File description:
** score.h
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
    int *score;
    int previous_score;
} score_t;

score_t *create_score(scene_t *scene, int *score);
void destroy_score(score_t *score);
void update_score(score_t *score, float dt);
void render_score(score_t *score, scene_t *scene);
