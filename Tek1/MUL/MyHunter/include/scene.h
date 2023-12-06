/*
** EPITECH PROJECT, 2022
** scene.h
** File description:
** scene.h
*/

#pragma once

#include "types.h"

#include <SFML/Graphics.h>

struct scene {
    void (*create)(scene_t *scene);
    void (*destroy)(scene_t *scene);
    void (*on_event)(scene_t *scene, sfEvent *event);
    void (*update)(scene_t *scene, float dt);
    void (*render)(scene_t *scene);
    sfRenderWindow *window;
    app_t *app;
    void *data;
};
