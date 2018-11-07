#include "Header.h"

//vsi funcs
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
char s1[256];



void GotoXY(short X, short Y) {
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

void SetColor(int text, int background) {
	SetConsoleTextAttribute(hStdOut, background * 16 + text);
}


void coutAUTHOR()
{
	SetColor(15, 0);
	cout << "  ___            _                        __           _           _    " << endl;
	cout << " / _ )          | |                      /__\_    _ ___| |__  _   _| | __" << endl;
	cout << "/ /_\ )_ __   __| |_ __ _____      __    / )// | | |_  / '_ )| | | | |/ /" << endl;
	cout << "|  _  | '_ ) / _` | '__/ _ ) \ /) / /   / _  ) |_| |/ /| | | | |_| |   < " << endl;
	cout << "| | | | | | | (_| | | |  __/) V  V /   |/ |_/|__, /___|_| |_||__,_|_|)_)" << endl;
	cout << ")_| |_/_| |_|)__,_|_|  \___| )_/)_/           |___/                      " << endl;
	cout << endl;
}

void coutPS() {
	SetColor(rand() % 15, 0);
	cout << setw(10);
	cout << "\n\n\n\n\n\n";
	cout << " .oooooo..o                                        " << endl;
	cout << "d8P'    `Y8                                        " << endl;
	cout << "Y88bo.       .oooo.   oo.ooooo.   .ooooo.  oooo d8b" << endl;
	cout << " `xY8888o.  `P  )88b   888' `88b d88' `88b `888xx8P" << endl;
	cout << "     `xY88b.  oPx888   888   888 888ooo888  888    " << endl;
	cout << "oo     .d8P d8(  888   888   888 888    .o  888    " << endl;
	cout << "8xx88888Pi  iY888xx8o  888bod8P' iY8bod8Pi d888b   " << endl;
	cout << "                       888                         " << endl;
	cout << "                      o888o                        " << endl;


	//Vivodimo dekorativnu minu
	char r = '*';
	char p = ' ';
	int n = 7;
	int z = 1;

	for (int i = 0; i < n / 2 + 1; i++)
	{
		int prob = (n - z) / 2;
		for (int j = 0; j < prob; j++)
			cout << p;
		for (int k = 0; k < z; k++)
			cout << r;
		cout << endl;


		z = z + 2;
	}
	z = n - 2;

	for (int i = n / 2; i > 0; i--)
	{
		int prob = (n - z) / 2;
		for (int j = 0; j < prob; j++)
			cout << p;
		for (int k = 0; k < z; k++)
			cout << r;
		cout << endl;
		z = z - 2;
	}
}

void intro() {


	const char c[2][256] = { " /)_/)\n (^_^)\n(\\__ /)\n", "(\\__/)\n(='.'=)\n(\")_(\")\n" };
	int state = 0;
	do
	{
		system("cls");
		system("color 0f");


		unsigned short start = 0;
		cout << "Project made by Andrij Ryzhuk\n\n" << c[state ^= 1];
		cout << endl << endl;
		cout << "\t\t\t����i�. ����� ����i.\n\t\t\tcreator: Andrew Ryzhuk\n\n*�������:  1. ����� �� ������� ��� ���� ��� ���� .\n\t2." << " \'#\' ������� ������� ��i�����, \'(b)\' ������� �����, \'-\' ����� ����." << endl;
		coutAUTHOR();
		cout << "������i�� ���� ������ ��� ���������...";
		getchar();

	} while (_getch());

	cout << endl;
	

	cout << "\n\n";
}



void init_mine() {
	int i, j;
	for (i = 0; i < MAXROW; i++) {
		for (j = 0; j < MAXCOL; j++) {
			minearr[i][j] = 0;
			manage_mine[i][j] = false;
		}
	}
	for (i = 0; i < MAXROW; i++) minearr[i][0] = minearr[i][MAXCOL - 1] = -4;
	for (i = 0; i < MAXCOL; i++) minearr[0][i] = minearr[MAXROW - 1][i] = -4;
}

void prep_mine(int tmpr, int tmpc) {
	int i, j;
	for (i = tmpr - 1; i <= tmpr + 1; i++) {
		for (j = tmpc - 1; j <= tmpc + 1; j++) {
			if (minearr[i][j] >= 0) minearr[i][j]++;
		}
	}
}

void  openingemptybox(int rownum, int colnum) {
	int i, j;
	for (i = rownum - 1; i <= rownum + 1; i++) {
		for (j = colnum - 1; j <= colnum + 1; j++) {
			if (manage_mine[i][j] == false) {
				manage_mine[i][j] = true;
				if (minearr[i][j] == 0)
					openingemptybox(i, j);
			}
		}
	}
}

int openedboxnum() {
	int i, j, sum = 0;
	for (i = 1; i < MAXROW - 1; i++) {
		for (j = 1; j < MAXCOL - 1; j++) {
			if (manage_mine[i][j] == true)
				sum++;
		}
	}
	return sum;
}

bool test_input(int rowno, int colno) {
	int i, flag1 = 0, flag2 = 0;
	for (i = 1; i < MAXROW - 1; i++) {
		if (rowno == i)
			flag1++;
	}
	for (i = 1; i < MAXCOL - 1; i++) {
		if (colno == i)
			flag2++;
	}
	if (flag1 == 0 || flag2 == 0)
		return false;
	return true;
}


void show_mine() {


	system("color f0");
	int i, j;

	//cout << " ";
	//for (int x = 1; x < MAXCOL-1; x++)
	//	cout << " " << x;
	//cout << endl;

	for (i = 1; i < MAXROW - 1; i++) {
		//cout << i; 


		for (j = 1; j < MAXCOL - 1; j++) {


			switch (manage_mine[i][j]) {
			case true:
				switch (minearr[i][j]) {
				case 0: cout << "-";
					break;
				default:
					cout << minearr[i][j];
				}
				break;

			default:

				cout << "#";
			}
		}
		cout << endl;
	}
}

void game_over() {
	int i, j;
	for (i = 1; i < MAXROW - 1; i++) {
		Sleep(150);
		for (j = 1; j < MAXCOL - 1; j++) {
			SetColor(rand() % 14 + 1, 15);
			Sleep(15);
			SetColor(rand() % 14 + 1, 15);
			switch (minearr[i][j]) {
			case 0: cout << "  -  "; break;
			case -1: cout << " (b) "; break;
			default: cout << "  " << minearr[i][j] << "  ";
			}
		}
		cout << "\n" << endl;
	}

}

void gotoxyGAME(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void saper()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int i = 0, tempr, tempc, thecolnum = 1;
	int therownum = 1;
	int closednum;


	intro();
	closednum = (MAXROW - 2)*(MAXCOL - 2) - numofbombs;
	init_mine();

	// dodaem minu
	srand(time(NULL));
	while (i < numofbombs) {
		tempr = rand() % (MAXROW - 2) + 1;
		tempc = rand() % (MAXCOL - 2) + 1;
		if (minearr[tempr][tempc] != -1) {
			minearr[tempr][tempc] = -1;
			prep_mine(tempr, tempc);
			i++;
		}
	}

	//proces sapera

	clock_t t = clock(); //stvoryv zminu dly taymera chasu sapera
	while (openedboxnum() != closednum && minearr[therownum][thecolnum] != -1) {

		system("cls");
		show_mine();


		char c;
		int x = 0;
		int y = 0;

		gotoxyGAME(0, 0);
		do {



			c = _getch();
			switch (c) {
			case 75:

				gotoxyGAME(x -= 1, y);


				break;
			case 77:

				gotoxyGAME(x += 1, y);

				break;
			case 72:

				gotoxyGAME(x, y -= 1);

				break;
			case 80:

				gotoxyGAME(x, y += 1);

				break;
			}

		} while (c != 83);


		thecolnum = x + 1;
		therownum = y + 1;




		/*PORT:
			//Vvodimo koordinaty booma
			cout << "�����: ";
			cin >> therownum;
			cout << "�������: ";
			cin >> thecolnum; */







			//Provirka na pravelnist vvedenih koordinat
			/*if (test_input(therownum, thecolnum) == false) {
				cout << "\n*������ ���������� i�������i�*\n\n";
				goto PORT;
			} */






			//Provirka susidnih klitinok na pustotu
			//yakscho = 0 - vidrivaem puste pole
		if (minearr[therownum][thecolnum] == 0)
			openingemptybox(therownum, thecolnum);
		else
			manage_mine[therownum][thecolnum] = true;
		cout << "\n" << endl;
	}


	if (minearr[therownum][thecolnum] == -1)
	{

	}

	int time = (clock() - t) / CLOCKS_PER_SEC; //zmina v yau zapusani ms yai perevedeni v secundi
	int time_min = 0;
	int time_sec = 0; //chas v secundah pisly perevodu v min+sec


	if (time > 59)
	{
		time_min = time / 60 + (time % 60);
		time_sec = time % 60;
	}
	else
		time_sec = time;



	system("cls");
	game_over();


	for (int i = 0; i < 20; i++) {

		system("cls");
		SetColor(rand() % 14 + 1, 0);
		cout << " #####     #    #     # #######     ####### #     # ####### ######\n";
		cout << "#     #   # #   ##   ## #           #     # #     # #       #     #\n";
		cout << "#        #   #  # # # # #           #     # #     # #       #     #\n";
		cout << "#  #### #     # #  #  # #####       #     # #     # #####   ######\n";
		cout << "#     # ####### #     # #           #     #  #   #  #       #   #\n";
		cout << "#     # #     # #     # #           #     #   # #   #       #    #\n";
		cout << " #####  #     # #     # #######     #######    #    ####### #     #\n";
		Sleep(100);


	}




	if (time_min != 0)
		cout << endl << "��� ��� ��������: " << time_min << "������ " << time_sec << "��� " << endl; // vidodim secundi
	else
		cout << endl << "��� ��� ��������: " << time_sec << "��� " << endl;



	if (minearr[therownum][thecolnum] == -1)
		cout << " �� ������ �� �����! " << endl;
	else
		cout << "�i���... \t��� ���������" << endl;


	game_over();
	system("color 07");
	system("pause");
}

void menu() {
	setlocale(LC_ALL, "rus");



	int f = 1, k, code;
	SetColor(0, 0);
	GotoXY(27, 12);
	SetColor(14, 0);
	cout << "-->���� ���<--";
	GotoXY(30, 13);
	SetColor(15, 0);
	cout << "   �����   ";


	do {
		k = 0;
		code = _getch();
		if (code == 224 || code == 0)
			code = _getch();
		coutPS();
		if (code == 80) {
			f = f * (-1);
			if (f == 1) {
				GotoXY(27, 12);
				SetColor(14, 0);
				cout << "-->���� ���<--";
				GotoXY(30, 13);
				SetColor(15, 0);
				cout << "   �����  ";
			}
			else {
				GotoXY(27, 12);
				SetColor(15, 0);
				cout << "   ���� ���   ";
				GotoXY(30, 13);
				SetColor(14, 0);
				cout << "-->�����<--";
			}
		}
		else if (code == 72) {
			f = f * (-1);
			if (f == 1) {
				GotoXY(27, 12);
				SetColor(14, 0);
				cout << "-->���� ���<--";
				GotoXY(30, 13);
				SetColor(15, 0);
				cout << "   �����   ";
			}
			else {
				GotoXY(27, 12);
				SetColor(15, 0);
				cout << "   ���� ���   ";
				GotoXY(30, 13);
				SetColor(14, 0);
				cout << "-->�����<--";
			}
		}
		else if (code == 13)
			k = 1;

	} while (k == 0);
	if (f != 1) exit(0);

	saper();
	cin.get();
}

void main() {





	menu();

}