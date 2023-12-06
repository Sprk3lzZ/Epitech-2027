/*
** EPITECH PROJECT, 2022
** game_over.h
** File description:
** game_over.h
*/

#pragma once

#include "scene.h"

typedef struct {
    sfText *text;
    sfFont *font;
} game_over_data_t;

void game_over_create(scene_t *scene);
void game_over_destroy(scene_t *scene);
void game_over_on_event(scene_t *scene, sfEvent *event);
void game_over_update(scene_t *scene, float dt);
void game_over_render(scene_t *scene);
