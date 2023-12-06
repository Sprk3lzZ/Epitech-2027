/*
** EPITECH PROJECT, 2022
** cursor.h
** File description:
** cursor.h
*/

#pragma once

#include <SFML/Graphics.h>

#include "scene.h"

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
} cursor_t;

cursor_t *create_cursor(scene_t *scene);
void destroy_cursor(scene_t *scene, cursor_t *cursor);
void update_cursor(scene_t *scene, cursor_t *cursor);
void render_cursor(scene_t *scene, cursor_t *cursor);
