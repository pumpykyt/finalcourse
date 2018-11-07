#pragma once
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <iomanip>

using namespace std;

const int rowc = 20;
const int colc = 15;
const int numofbombs = 25;


//Prototypu usih funkciy
int field[rowc][colc];
bool admin_mine[rowc][colc];
void intro();
void init_mine();
void prep_mine(int tmpr, int tmpc);
void recursive_open_field(int rownum, int colnum);
int opened_field_num();
void show_mine();
void game_over();
void menu();
void gotoxyGAME(int x, int y);