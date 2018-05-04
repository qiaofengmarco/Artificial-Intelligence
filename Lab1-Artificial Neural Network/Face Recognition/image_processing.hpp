#ifndef MY_IMAGE_PROCESSING_HPP
#define MY_IMAGE_PROCESSING_HPP

#include <stdio.h>
#include "pgmimage.hpp"
#include "string.h"

extern void exit();

#define TARGET_HIGH 0.9
#define TARGET_LOW 0.1

void load_man_target(IMAGE* img, double** target)
{
    int scale;
    char userid[40], head[40], expression[40], eyes[40], photo[40];

    userid[0] = head[0] = expression[0] = eyes[0] = photo[0] = '\0';

    /*** scan in the image features ***/
    sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
           userid, head, expression, eyes, &scale, photo);

    if (!strcmp(userid, "an2i"))
    {
        // 1
        target[0][0] = TARGET_HIGH;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "at33"))
    {
        // 2
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_HIGH;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "boland"))
    {
        // 3
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_HIGH;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "bpm"))
    {
        // 4
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_HIGH;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "ch4f"))
    {
        // 5
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_HIGH;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "cheyer"))
    {
        // 6
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_HIGH;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "choon"))
    {
        // 7
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_HIGH;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "danieln"))
    {
        // 8
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_HIGH;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "glickman"))
    {
        // 9
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_HIGH;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "karyadi"))
    {
        // 10
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_HIGH;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "kawamura"))
    {
        // 11
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_HIGH;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "kk49"))
    {
        // 12
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_HIGH;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "megak"))
    {
        // 13
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_HIGH;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "mitchell"))
    {
        // 14
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_HIGH;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "night"))
    {
        // 15
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_HIGH;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "phoebe"))
    {
        // 16
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_HIGH;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "saavik"))
    {
        // 17
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_HIGH;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "steffi"))
    {
        // 18
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_HIGH;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "sz24"))
    {
        // 19
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_HIGH;
        target[0][19] = TARGET_LOW;
    }
    else if (!strcmp(userid, "tammo"))
    {
        // 20
        target[0][0] = TARGET_LOW;
        target[0][1] = TARGET_LOW;
        target[0][2] = TARGET_LOW;
        target[0][3] = TARGET_LOW;
        target[0][4] = TARGET_LOW;
        target[0][5] = TARGET_LOW;
        target[0][6] = TARGET_LOW;
        target[0][7] = TARGET_LOW;
        target[0][8] = TARGET_LOW;
        target[0][9] = TARGET_LOW;
        target[0][10] = TARGET_LOW;
        target[0][11] = TARGET_LOW;
        target[0][12] = TARGET_LOW;
        target[0][13] = TARGET_LOW;
        target[0][14] = TARGET_LOW;
        target[0][15] = TARGET_LOW;
        target[0][16] = TARGET_LOW;
        target[0][17] = TARGET_LOW;
        target[0][18] = TARGET_LOW;
        target[0][19] = TARGET_HIGH;
    }
}

void image_to_target(IMAGE* img, char** name, char** pose, char** expression, char** eyes)
{
  int scale;
  char photo[40];
  photo[0] = '\0';
  /*** scan in the image features ***/
  sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
    name[0], pose[0], expression[0], eyes[0], &scale, photo[0]);
}

void image_to_input(IMAGE* img, double** input)
{
  int nr, nc, i, j, k;

  nr = ROWS(img);
  nc = COLS(img);
  //imgsize = nr * nc;;

  k = 0;
  for (i = 0; i < nr; i++) {
    for (j = 0; j < nc; j++) {
      input[0][k] = ((double) (img_getpixel(img, i, j))) / 255.0;
      //printf("%.6f ",input[0][k]);
      k++;
    }
    //printf("\n");
  }
}

#endif