/*
** EPITECH PROJECT, 2022
** framebuffer
** File description:
** frame_buffer
*/
#pragma once
#include <SFML/Graphics.h>

typedef struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
} framebuffer_t;
