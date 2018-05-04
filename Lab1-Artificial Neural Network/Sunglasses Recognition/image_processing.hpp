/*
******************************************************************
* Southeast University Artificial Intelligence Course Project
*
* Author: Qiaofeng Marco LIU
*
* Contact Info: qiaofengmarco@outlook.com
******************************************************************
*/

#ifndef MY_IMAGE_PROCESSING_HPP
#define MY_IMAGE_PROCESSING_HPP

#include <stdio.h>
#include "pgmimage.hpp"
#include "string.h"

extern void exit();

#define TARGET_HIGH 1.0
#define TARGET_LOW 0.0

void load_man_target(IMAGE* img, double** target)
{
    int scale;
    char userid[40], head[40], expression[40], eyes[40], photo[40];

    userid[0] = head[0] = expression[0] = eyes[0] = photo[0] = '\0';

    /*** scan in the image features ***/
    sscanf(NAME(img), "%[^_]_%[^_]_%[^_]_%[^_]_%d.%[^_]",
           userid, head, expression, eyes, &scale, photo);

    if (!strcmp(eyes, "sunglasses"))
    {
        target[0][0] = TARGET_HIGH;  /* ´÷ÑÛ¾µ, set target to HIGH */
    }
    else
    {
        target[0][0] = TARGET_LOW;   /* Ã»´÷ÑÛ¾µ, set it to LOW */
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