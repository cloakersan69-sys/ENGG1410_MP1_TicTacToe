/*
 * input.c -- ENGG*1410 Mini-Project 1
 *
 * SUPPLIED FILE. Do not change this file.
 *
 * Each function reads one full line, so leftover characters never
 * carry over into the next read. That is what prevents the classic
 * infinite loop when someone types a letter where scanf wants a number.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

#define LINE_LEN 100

/* Read one line into `line`. Exits the program if input has ended.
   If the line was too long to fit, the rest of it is thrown away. */
static void read_line(char line[], int size)
{
    if (fgets(line, size, stdin) == NULL) {
        printf("\nNo more input. Goodbye.\n");
        exit(0);
    }
    if (strchr(line, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
            /* discard the rest of an over-long line */
        }
    }
}

int read_int(void)
{
    char line[LINE_LEN];
    int value;
    char extra;

    while (1) {
        read_line(line, LINE_LEN);
        if (sscanf(line, "%d %c", &value, &extra) == 1) {
            return value;
        }
        printf("Please enter a whole number: ");
    }
}

char read_char(void)
{
    char line[LINE_LEN];
    char c;

    while (1) {
        read_line(line, LINE_LEN);
        if (sscanf(line, " %c", &c) == 1) {
            return c;
        }
        printf("Please type a character: ");
    }
}
