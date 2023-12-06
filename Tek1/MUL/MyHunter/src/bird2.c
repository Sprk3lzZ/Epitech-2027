/*
** EPITECH PROJECT, 2022
** bird2.c
** File description:
** bird2.c
*/

#include "bird.h"
#include "game.h"

#include <stdlib.h>

void change_bird (bird_t *bird)
{
    if (bird->frame == 0) {
        if (bird->flip == -1) {
            sfSprite_setTextureRect(bird->sprite,
            (sfIntRect){115, 329, 17, 21});
        } else {
            sfSprite_setTextureRect(bird->sprite,
            (sfIntRect){156, 408, 17, 21});
        }
    } else {
        if (bird->flip == -1) {
            sfSprite_setTextureRect(bird->sprite,
            (sfIntRect){115, 353, 17, 21});
        } else {
            sfSprite_setTextureRect(bird->sprite,
            (sfIntRect){156, 432, 17, 21});
        }
    }
}

void tap_wall(bird_t *bird, int zoom)
{
    if (bird->position.x > 570 - zoom * 21) {
        bird->speed.x = -bird->speed.x;
        bird->position.x = 570 - zoom * 21;
        bird->flip = -bird->flip;
    }
    if (bird->position.x < 150) {
        bird->speed.x = -bird->speed.x;
        bird->position.x = 150;
        bird->flip = -bird->flip;
    }
}

void sound_touch_bird(bird_t *bird)
{
    bird->buffer = sfSoundBuffer_createFromFile("res/bird.wav");
    bird->sound = sfSound_create();
    sfSound_setBuffer(bird->sound, bird->buffer);
    sfSound_setVolume(bird->sound, 50);
}

void sound_miss_bird(bird_t *bird)
{
    bird->buffer2 = sfSoundBuffer_createFromFile("res/bruh.wav");
    bird->sound2 = sfSound_create();
    sfSound_setBuffer(bird->sound2, bird->buffer2);
    sfSound_setVolume(bird->sound2, 50);
}
