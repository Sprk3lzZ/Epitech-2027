/*
** EPITECH PROJECT, 2022
** background.h
** File description:
** background.h
*/

#pragma once

#include "scene.h"

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    scene_t *scene;
} background_t;

background_t *create_background(scene_t *scene, sfTexture *spritesheet);
void destroy_background(background_t *bg);
void on_event_background(background_t *bg, sfEvent *event);
void render_background(background_t *bg);
