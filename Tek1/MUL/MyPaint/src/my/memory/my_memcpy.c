/*
** EPITECH PROJECT, 2023
** my_memcpy.c
** File description:
** my_memcpy.c
*/

#include "my/memory.h"

void *my_memcpy(void *dest, const void *src, size_t bytes)
{
    for (size_t i = 0; i < bytes; i++)
        ((uint8_t *)dest)[i] = ((const uint8_t *)src)[i];
    return dest;
}
