#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <thread>
#include <chrono>
#include <vector>
#include <sstream>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
using namespace std;
char getInput(char b)
{
    char a;
    clock_t t,t0;
    t = clock();
    while (true)
    {
        t0 = clock();
        if (_kbhit()) {
            a = _getch();
            return a;
        }
        else if (t0-t>= 250) {
            return b;
        }
    }
}

void background(string screen[],int a) {
    string
        cloud[3] = {
        "        cloud        ",
        "      cloudcloud     ",
        "cloudcloudcloudcloud ",
    };
    int i, j;
    for (i = 0;i < 3;i++) {
        for (j = 0;j <= 20;j++) {
            screen[4 + i][a + j] = cloud[i][j];
        }
    }
}

void obstacle(string screen[], int type, int a) {
    switch(type){
        case 0:
            screen[25][a]='X';
            break;
        case 1:
            screen[24][a]='X';
            screen[25][a]='X';
            break;
        case 2:
            screen[23][a]='X';
            break;
        case 3:
            screen[23][a]='X';
            screen[24][a]='X';
            break;
    }
}

int main()
{   srand( time(NULL) );
    int min = 0;
    int max = 3;
    int type =0;
    system("mode con cols=100 lines=30");
    int i, j, a = 74,score=0;
    long long movement = 9,jumptime=0,lietime=0,jb=0,lb=0;
    while (true) {
        string
        MainCharacter = "YOU",
        screen[27] = {
        "boundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundary",
        "b                                                                                              b",
        "o   score:                                                                                     o",
        "u                                                                                              u",
        "n                                                                                              n",
        "d                                                                                              d",
        "a                                                                                              a",
        "r                                                                                              r",
        "y                                                                                              y",
        "b                                                                                              b",
        "o                                                                                              o",
        "u                                                                                              u",
        "n                                                                                              n",
        "d                                                                                              d",
        "a                                                                                              a",
        "r                                                                                              r",
        "y                                                                                              y",
        "b                                                                                              b",
        "o                                                                                              o",
        "u                                                                                              u",
        "n                                                                                              n",
        "d                                                                                              d",
        "a                                                                                              a",
        "r                                                                                              r",
        "y                                                                                              y",
        "s                                                                                              s",
        "boundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundary"
    },
        score_str=" ";
        background(screen, a);

        int n = score,k=0,g=3;
        while (n > 0) {
            score_str.push_back(n%10+'0');
            n=n / 10;
            k++;
        }
        for (i = 0;i <= k;i++) {
            screen[2][10 + i] = score_str[k-i];
        }
        if (jumptime > 0) {
            if(jumptime==1||jumptime==3){
                for (i = 0;i < 3;i++) {
                    screen[22 + i][14] = MainCharacter[i];
                };
            }
            else if(jumptime==2){
                for (i = 0;i < 3;i++) {
                    screen[21 + i][14] = MainCharacter[i];
                };
            }
            jumptime--;
            movement = 'o';
            jb = 1;
        }
        else if (lietime > 0) {
            for (i = 0;i < 3;i++) {
                screen[25][14 + i] = MainCharacter[i];
            };
            lietime--;
            movement = 'o';
            lb = 1;
        }
        else if (movement == 'w'&& jumptime + lietime==0) {
            if (jb != 0 || lb != 0) {
                jb = 0;lb = 0;
                for (i = 0;i < 3;i++) {
                    screen[23 + i][14] = MainCharacter[i];
                };
            }else{for (i = 0;i < 3;i++) {
                screen[22 + i][14] = MainCharacter[i];
            };
            jumptime = 3;}
        }
        else if (movement == 's' && jumptime + lietime == 0) {
            if (jb != 0 || lb != 0) {
                jb = 0;lb = 0;
                for (i = 0;i < 3;i++) {
                    screen[23 + i][14] = MainCharacter[i];
                };
            }else{for (i = 0;i < 3;i++) {
                screen[25][14 + i] = MainCharacter[i];
            };
            lietime = 2;}
        }
        else if(movement=='p' && jumptime + lietime == 0){
            for (i = 0;i < 3;i++) {
                screen[23 + i][14] = MainCharacter[i];
            };
        }
        obstacle(screen,type,a);
        for (i = 0;i < 9*3;i++) {
                for (j = 0;j < 16*3*2;j++) {
                    cout << screen[i][j];
                    if(screen[i][j]=='Y'||screen[i][j]=='O'||screen[i][j]=='U'){
                        g--;
                    }
                }
                cout << "\n";
            }
        cout << "jump up->w\nlie down->s\n"<<g;
        if (jumptime == 0) { movement = getInput('p'); }
        else {
            movement = getInput('p');
            movement = 'o';
        }
        if(g>0&&score!=0){
            break;
        }
        system("cls");
        a--;
        if (a <= 0) {
            a = 74;
            type = rand() % (max - min + 1) + min;
        }
        score++;
    }
    string screen_end[27] = {
        "boundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundary",
        "b                                                                                              b",
        "o                                                                                              o",
        "u                         l          oooooooo    sssssss    eeeeeeee                           u",
        "n                         l          o      o    s     s    e                                  n",
        "d                         l          o      o      s        e                                  d",
        "a                         l          o      o        s      eeeeeeee                           a",
        "r                         l          o      o    s     s    e                                  r",
        "y                         llllllll   oooooooo    sssssss    eeeeeeee                           y",
        "b                                                                                              b",
        "o                                         score:                                               o",
        "u                                                                                              u",
        "n                                                                                              n",
        "d                                                                                              d",
        "a                                                                                              a",
        "r                                                                                              r",
        "y                                                                                              y",
        "b                                                                                              b",
        "o                                                                                              o",
        "u                                                                                              u",
        "n                                                                                              n",
        "d                                                                                              d",
        "a                                                                                              a",
        "r                                                                                              r",
        "y                                                                                              y",
        "s                                                                                              s",
        "boundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundaryboundary"};
    system("cls");
    int v = score,q=0;
    string score_str_e=" ";
    while (v > 0) {
            score_str_e.push_back(v%10+'0');
            v=v / 10;
            q++;
        }
        for (i = 0;i <= q;i++) {
            screen_end[2][10 + i] = score_str_e[q-i];
        }
    for (i = 0;i < 9*3;i++) {
        for (j = 0;j < 16*3*2;j++) {
            cout << screen_end[i][j];
        }
        cout << "\n";
    }


    return 0;
}
