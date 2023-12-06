/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** game.c
*/

#include "game.h"
#include "game_over.h"
#include "app.h"

#include <stdlib.h>

void game_create(scene_t *scene)
{
    game_data_t *data = malloc(sizeof(game_data_t));

    data->score = 0;
    data->life = 3;
    data->time = 0;
    data->spritesheet = sfTexture_createFromFile("res/spritesheet.png", NULL);
    data->bg = create_background(scene, data->spritesheet);
    data->bird = create_bird(scene, data->spritesheet, &data->score,
        &data->life);
    data->score_scene = create_score(scene, &data->score);
    data->music = sfMusic_createFromFile("res/music.wav");
    sfMusic_setLoop(data->music, sfTrue);
    sfMusic_play(data->music);
    data->life_scene = create_life(scene, &data->life);
    data->time_scene = create_time(scene, &data->time);
    data->cursor = create_cursor(scene);
    scene->data = data;
}

void game_destroy(scene_t *scene)
{
    game_data_t *data = scene->data;

    sfTexture_destroy(data->spritesheet);
    destroy_bird(data->bird);
    destroy_background(data->bg);
    destroy_score(data->score_scene);
    destroy_life(data->life_scene);
    destroy_time(data->time_scene);
    destroy_cursor(scene, data->cursor);
    sfMusic_destroy(data->music);
    free(data);
}

void game_on_event(scene_t *scene, sfEvent *event)
{
    game_data_t *data = scene->data;

    on_event_background(data->bg, event);
    on_event_bird(data->bird, event);
}

void game_update(scene_t *scene, float dt)
{
    game_data_t *data = scene->data;
    scene_t *game_over;

    if (data->life == 0){
        game_destroy(scene);
        game_over = malloc(sizeof(scene_t));
        game_over->create = game_over_create;
        game_over->destroy = game_over_destroy;
        game_over->on_event = game_over_on_event;
        game_over->update = game_over_update;
        game_over->render = game_over_render;
        game_over_create(game_over);
        app_set_scene(scene->app, game_over);
        return;
    }
    update_bird(data->bird, dt);
    update_score(data->score_scene, dt);
    update_life(data->life_scene, dt);
    update_time(data->time_scene, dt);
    update_cursor(scene, data->cursor);
}

void game_render(scene_t *scene)
{
    game_data_t *data = scene->data;

    render_background(data->bg);
    render_bird(data->bird);
    render_score(data->score_scene, scene);
    render_life(data->life_scene, scene);
    render_time(data->time_scene, scene);
    render_cursor(scene, data->cursor);
}
