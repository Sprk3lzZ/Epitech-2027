/*
** EPITECH PROJECT, 2022
** bird.h
** File description:
** bird.h
*/

#pragma once

#include "scene.h"
#include <SFML/Audio.h>

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    scene_t *scene;
    int *score;
    int *life;
    float elapsed;
    int flip;
    int frame;
    sfSound *sound;
    sfSound *sound2;
    sfSoundBuffer *buffer;
    sfSoundBuffer *buffer2;
    sfVector2f position;
    sfVector2f speed;
} bird_t;

bird_t *create_bird(scene_t *scene, sfTexture *spritesheet, int *score,
    int *life);
void destroy_bird(bird_t *bird);

void update_bird(bird_t *bird, float dt);
void on_event_bird(bird_t *bird, sfEvent *event);
void render_bird(bird_t *bird);

void sound_touch_bird(bird_t *bird);
void sound_miss_bird(bird_t *bird);
void change_bird (bird_t *bird);
void tap_wall(bird_t *bird, int zoom);
