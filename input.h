/*
 * input.h -- ENGG*1410 Mini-Project 1
 *
 * SUPPLIED FILE. Do not change this file or input.c.
 * Use these two functions for ALL keyboard input in your program.
 * You do not need to understand how input.c works.
 */
#ifndef INPUT_H
#define INPUT_H

/* Read one whole number typed on its own line and return it.
   If the player types anything else ("abc", "1.5", "2 3"), prints
   "Please enter a whole number: " and waits for another try.
   It does NOT check ranges -- that is your job.
   If keyboard input ends, the program exits. */
int read_int(void);

/* Read one non-space character, for example 'y' or 'n', and return it.
   The rest of the line is thrown away.
   If keyboard input ends, the program exits. */
char read_char(void);

#endif
