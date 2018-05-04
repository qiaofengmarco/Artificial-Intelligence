#ifndef MY_DATA_PROCESSING_HPP
#define MY_DATA_PROCESSING_HPP

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "math.h"

void split_trainingset(char* filename) {

    FILE *fp, *fp1;

    char buf1[500];
    char **buf = (char**) malloc(sizeof(char*) * 277);
    for (int i = 0; i < 277; i++)
        buf[i] = (char*) malloc(sizeof(char) * 500);

    if (filename[0] == '\0') {
        printf("IMGL_LOAD_IMAGES_FROM_TEXTFILE: Invalid file '%s'\n", filename);
        return;
    }

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("IMGL_LOAD_IMAGES_FROM_TEXTFILE: Couldn't open '%s'\n", filename);
        return;
    }

    int count = 0;
    while (fgets(buf1, 1999, fp) != NULL) {

        printf("Loading '%s'...", buf1);  
        //fflush(stdout);
                
        strcpy(buf[count], buf1);
        count++;
        fflush(stdout);
    }

    char* str = (char*) malloc(300);
    int *flag = (int*) malloc(sizeof(int) * 277);
    int *seq = (int*) malloc(sizeof(int) * 25);
    for (int i = 0; i < 277; i++)
        flag[i] = 0;

    count = 0;
    int last_temp = 0, temp = 276;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 25; j++) {
            srand((unsigned int) (102149 * exp(abs(i + 0.6 * j) / (temp + 1))));
            temp = my_random(277) + last_temp;
            temp %= 277;
            while (flag[temp]) {
                temp++;
                temp %= 277;
            }
            flag[temp] = 1;
            seq[j] = temp;
            last_temp = temp;
        }

        sprintf(str, "../all_train/%d.list", i);
        printf("%s\n", str);
        fp1 = fopen(str, "w");
        for (int j = 0; j < 25; j++) {
            fwrite(buf[seq[j]], 1, strlen(buf[seq[j]]), fp1);
            printf("%d ", j);
        }
        fclose(fp1);
    }

    sprintf(str, "../all_train/%d.list", 10);
    fp1 = fopen(str, "w");
    for (int i = 0; i < 277; i++) 
        if (!flag[i])
            fwrite(buf[i], 1, strlen(buf[i]), fp1);
    fclose(fp1);
    printf("%s\n", str);

    fclose(fp);
}

void file_copy(char* des, int k, char* signal) {
    char *str1, *buf1;
    FILE *fp1, *fp2;
    str1 = (char*) malloc(200);
    buf1 = (char*) malloc(500);
    sprintf(str1, "../all_train/%d.list", k);
    fp1 = fopen(str1, "r");
    fp2 = fopen(des, signal);
    while (fgets(buf1, 1999, fp1) != NULL) {
        fwrite(buf1, 1, strlen(buf1), fp2);
        fflush(stdout);
    }
    fclose(fp2);
    fclose(fp1);
}

void preprocessing(int k) {
    int flag = 0;
    file_copy("../all_train/validation.list", k, "w");
    for (int i = 0; i < 11; i++) {
        if (i != k) {
            if (flag)
                file_copy("../all_train/train.list", i, "a");
            else {
                file_copy("../all_train/train.list", i, "w");
                flag = 1;
            }
        }
    }
}

#endif