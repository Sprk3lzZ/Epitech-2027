/*
** EPITECH PROJECT, 2022
** app.c
** File description:
** app.c
*/

#include "app.h"

#include <stdlib.h>

app_t *app_create(unsigned int width, unsigned int height, char const *title)
{
    app_t *app = malloc(sizeof(app_t));

    app->window = sfRenderWindow_create((sfVideoMode){width, height, 32},
        title, sfDefaultStyle, NULL);
    app->scene = NULL;
    return app;
}

void app_destroy(app_t *app)
{
    sfRenderWindow_destroy(app->window);
    free(app->scene);
    free(app);
}

void app_set_scene(app_t *app, scene_t *scene)
{
    free(app->scene);
    app->scene = scene;
    scene->window = app->window;
    scene->app = app;
}

static void handle_events(app_t *app)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(app->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(app->window);
        app->scene->on_event(app->scene, &event);
    }
}

int app_run(app_t *app)
{
    sfClock *clock = sfClock_create();
    float dt;
    if (app->scene == NULL)
        return 84;
    app->scene->create(app->scene);
    while (sfRenderWindow_isOpen(app->window)) {
        dt = sfTime_asSeconds(sfClock_restart(clock));
        handle_events(app);
        app->scene->update(app->scene, dt);
        sfRenderWindow_clear(app->window, sfColor_fromRGB(50,50,50));
        app->scene->render(app->scene);
        sfRenderWindow_display(app->window);
    }
    sfClock_destroy(clock);
    app->scene->destroy(app->scene);
    return 0;
}
