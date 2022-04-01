/*
** EPITECH PROJECT, 2021
** header du lem-in
** File description:
** bcp de definitions
*/
#pragma once

// read, write, malloc, free and getline.

// read
#include <sys/types.h>
#include <sys/uio.h>
// write && read
#include <unistd.h>
// malloc
#include <stdlib.h>
// getline
#include <stdio.h>
// bool
#include <stdbool.h>

#define BUFF_SIZE 512

// * ////////////// SRC DIR //////////////////////////////////////////

// main

int main (int ac, char **av);
