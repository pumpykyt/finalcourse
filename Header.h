#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <iomanip>




const int MAXROW = 20;
const int MAXCOL = 15;
const int numofbombs = 25;


using namespace std;


//Prototypu usih funkciy
int minearr[MAXROW][MAXCOL];
bool manage_mine[MAXROW][MAXCOL];
void intro();
void init_mine();
void prep_mine(int tmpr, int tmpc);
void openingemptybox(int rownum, int colnum);
int openedboxnum();
void show_mine();
void game_over();
bool test_input(int rowno, int colno);
void menu();
void gotoxyGAME(int x, int y);