/*
** EPITECH PROJECT, 2022
** app.h
** File description:
** app.h
*/

#pragma once

#include "types.h"
#include "scene.h"

#include <SFML/Graphics.h>

struct app {
    sfRenderWindow *window;
    scene_t *scene;
};

app_t *app_create(unsigned int width, unsigned int height, char const *title);
void app_destroy(app_t *app);

void app_set_scene(app_t *app, scene_t *scene);
int app_run(app_t *app);
