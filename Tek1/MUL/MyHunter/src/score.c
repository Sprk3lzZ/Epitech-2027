/*
** EPITECH PROJECT, 2022
** score.c
** File description:
** score.c
*/

#include "score.h"
#include "bird.h"
#include "my.h"
#include <stdlib.h>
char *number_to_string(int nb);

static void score_text(score_t *score)
{
    score->text2 = sfText_create();
    sfText_setString(score->text2, "Score: ");
    sfText_setFont(score->text2, score->font);
    sfText_setCharacterSize(score->text2, 13);
    sfText_setPosition(score->text2, (sfVector2f) {480, 230});
}

score_t *create_score(__attribute((unused)) scene_t *scene, int *s)
{
    score_t *score = malloc(sizeof(score_t));

    score->score = s;
    score->previous_score = *s;
    score->font = sfFont_createFromFile("res/Fruit Days.ttf");
    score->text = sfText_create();
    score->str = my_strdup("0");
    sfText_setString(score->text, score->str);
    sfText_setFont(score->text, score->font);
    sfText_setCharacterSize(score->text, 12);
    sfText_setPosition(score->text, (sfVector2f) {525, 230});
    score_text(score);
    return score;
}

void destroy_score(score_t *score)
{
    free(score->str);
    sfFont_destroy(score->font);
    sfText_destroy(score->text);
}

void update_score(score_t *score, __attribute((unused)) float dt)
{
    if (score->previous_score != *score->score) {
        free(score->str);
        score->str = malloc(sizeof(char) * 100);
        sfText_setString(score->text, number_to_string(*score->score));
        score->previous_score = *score->score;
    }
}

void render_score(score_t *score, scene_t *scene)
{
    sfRenderWindow_drawText(scene->window, score->text2, NULL);
    sfRenderWindow_drawText(scene->window, score->text, NULL);
}
