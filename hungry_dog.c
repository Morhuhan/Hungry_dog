#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

void main (void) {

    char map[11][21];      //10 - y    20 - x
    int i;
    int key;
    int x = 10, y = 5;
    int exit_sign = 0;
    int apple_x = 4, apple_y = 3;

    
    srand(time(NULL));

    do {
        
        sprintf(map[0], "####################");
        for (i = 1; i < 9; i++) {
            sprintf(map[i], "#                  #");        
        }
        sprintf(map[9], "####################");
        //sprintf(map[10], "                   ");
        sprintf(map[10], "Hodit' na W A S D ");



        map[y][x] = '@';            // собака
        map[apple_y][apple_x] = '*'; // яблоко

        system("cls");
        
        for (i = 0; i < 10; i++) {  // Вывод картинки
        printf("%s \n", map[i]);
        }

        int wall_x = x;
        int wall_y = y;    

        key = getch();

        if (key == 'w') y--;
        if (key == 'a') x--;
        if (key == 's') y++;
        if (key == 'd') x++;

        if (map[y][x] == '#') {
            x = wall_x;
            y = wall_y;
        }

        if ((x == apple_x) && (y == apple_y)) {

            apple_x = rand() * 1.0 / RAND_MAX * 18 + 1;
            apple_y = rand() * 1.0 / RAND_MAX * 8 + 1;

        }

    }
    while (key != 'e');

}