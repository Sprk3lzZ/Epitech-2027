/*
** EPITECH PROJECT, 2022
** framebuffer
** File description:
** framebuffer
*/

#include <SFML/Graphics.h>
#include "framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *framebuffer = malloc(sizeof(framebuffer_t));

    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->pixels = malloc(width * height * 4);
    return (framebuffer);
}
