/*
** EPITECH PROJECT, 2022
** opening a window
** File description:
** opening a window
*/

#include <SFML/Graphics.h>

int *loop_window(window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
}

int main(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {800, 600, 32};

    window = sfRenderWindow_create(video_mode,
    "Opening a window task01", sfClose, NULL);
    while (sfRenderWindow_isOpen(window)) {
        loop_window(window);
    }
}
