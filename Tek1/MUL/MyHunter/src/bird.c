/*
** EPITECH PROJECT, 2022
** bird.c
** File description:
** bird.c
*/

#include "bird.h"
#include "game.h"
#include "my.h"

#include <stdlib.h>

static const int zoom = 2;

bird_t *create_bird(scene_t *scene, sfTexture *spritesheet, int *score,
    int *life)
{
    bird_t *bird = malloc(sizeof(bird_t));
    bird->sprite = sfSprite_create();
    bird->texture = spritesheet;
    bird->scene = scene;
    bird->position = (sfVector2f){150 - 8.5, rand() % 150};
    bird->score = score;
    bird->life = life;
    bird->elapsed = 0;
    bird->frame = 0;
    bird->speed = (sfVector2f){100, 0};
    bird->flip = -1;
    sound_touch_bird(bird);
    sound_miss_bird(bird);
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    sfSprite_setScale(bird->sprite, (sfVector2f){zoom, zoom});
    sfSprite_setPosition(bird->sprite, bird->position);
    return bird;
}

void destroy_bird(bird_t *bird)
{
    sfSprite_destroy(bird->sprite);
    free(bird);
}

void on_event_bird(bird_t *bird, sfEvent *event)
{
    sfFloatRect rect = {
        bird->position.x, bird->position.y, 17 * zoom, 21 * zoom
    };

    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        sfVector2f pos = sfRenderWindow_mapPixelToCoords(bird->scene->window,
            (sfVector2i){event->mouseButton.x, event->mouseButton.y}, NULL);
        if (sfFloatRect_contains(&rect, pos.x, pos.y)) {
            sfSound_play(bird->sound);
            bird->position = (sfVector2f){150 - 8.5, rand() % 150};
            bird->speed.x *= 1.1;
            *bird->score += 100;
        } else {
            sfSound_play(bird->sound2);
            *bird->life -= 1;
        }
    }
}

void update_bird(bird_t *bird, float dt)
{
    bird->position.x += bird->speed.x * dt;
    bird->elapsed += dt;

    if (bird->elapsed > 0.25) {
        bird->elapsed = 0;
        bird->frame = (bird->frame + 1) % 2;
    }
    change_bird(bird);
    tap_wall(bird, zoom);
    sfSprite_setPosition(bird->sprite, bird->position);
}

void render_bird(bird_t *bird)
{
    sfRenderWindow_drawSprite(bird->scene->window, bird->sprite, NULL);
}
