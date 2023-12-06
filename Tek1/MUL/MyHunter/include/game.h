/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** game.h
*/

#pragma once

#include "scene.h"
#include "background.h"
#include "bird.h"
#include "score.h"
#include "life.h"
#include "scene_time.h"
#include "cursor.h"

#include <SFML/Audio.h>

typedef struct {
    sfTexture *spritesheet;
    background_t *bg;
    bird_t *bird;
    score_t *score_scene;
    life_t *life_scene;
    scene_time_t *time_scene;
    cursor_t *cursor;
    sfMusic *music;
    int score;
    int life;
    float time;
} game_data_t;

void game_create(scene_t *scene);
void game_destroy(scene_t *scene);
void game_on_event(scene_t *scene, sfEvent *event);
void game_update(scene_t *scene, float dt);
void game_render(scene_t *scene);
