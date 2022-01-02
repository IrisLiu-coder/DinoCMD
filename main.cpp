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
    string
        obstacle[9][3] = {
            {/*type0*/"   ","   "," o "},{/*type1*/"   "," o "," o "},{/*type2*/"   "," o ","o o"},
            {/*type3*/"   "," o ","o  "},{/*type4*/"   "," o ","  o"},{/*type5*/"   ","   ","oo "},
            {/*type6*/"   "," o ","   "},{/*type7*/" o ","   ","   "},{/*type8*/" o "," o ","   "}
    };
    int i, j;
    for (i = 0;i < 3;i++) {
        for (j = 0;j <= 20;j++) {
            screen[23 + i][a + j] = obstacle[type][i][j];
        }
    }
}

int main()
{
    system("mode con cols=100 lines=30");
    int i, j, a = 74,score=0,type=0; 
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
        int n = score,k=0;
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
        for (i = 0;i < 9*3;i++) {
                for (j = 0;j < 16*3*2;j++) {
                    cout << screen[i][j];
                }
                cout << "\n";
            }
        cout << "jump up->w\nlie down->s\n";
        if (jumptime == 0) { movement = getInput('p'); }
        else {
            movement = getInput('p');
            movement = 'o';
        }     
        system("cls");
        a--;
        if (a <= 0) {
            a = 74;
        }
        score++;
    }
    return 0;
}