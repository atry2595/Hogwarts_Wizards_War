#include "logic.h"
#include "display_game.h"
#include "sysFunc.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;


int fight(Wizard& w1, Wizard& w2) {
	srand(time(0));
	hidecursor();
	start_display(w1, w2);
	round_display(w1, w2, 1);
	int r = 1;
	int lst = 0;
	static int hr = 100;
	long long f = 0;
	gotoxy(19, 0);
	cout << "speed:" << format_text(to_string(1000 / hr), 4) << endl;
	while (w1.isAlive() && w2.isAlive()) {
		while (_kbhit()) {
			char key = _getch();
			if ((key == 'q' || key == 'Q') && hr < 200) hr += 20;
			if ((key == 'e' || key == 'E') && hr > 20) hr -= 20;
		}
		Sleep(1);
		if (lst + hr < f) {
			round_fight(w1, w2, r);
			gotoxy(19, 0);
			cout << "speed:" << format_text(to_string(1000 / hr), 4) << endl;
			lst += hr;

		}
		f++;
	}
	int stat;
	if (w1.isAlive()) {
		stat = 1; oneWin(w1.get_name(), w2.get_name());
	}
	else if (w2.isAlive()) {
		stat = 2; secWin(w1.get_name(), w2.get_name());
	}
	else {
		stat = 0; draw(w1.get_name(), w2.get_name());
	}
	_getch();
	return stat;
}

void round_fight(Wizard& w1, Wizard& w2, int& r) {
	float atk1 = w1.attack();
	float atk2 = w2.attack();
	float dmg1 = w1.takeDamage(atk2);
	float dmg2 = w2.takeDamage(atk1);
	round_display(w1, w2, r, atk1, atk2, dmg1, dmg2);
	r++;
}



//====<group fight>====
void group_fight(vector<Wizard*> ws1, vector<Wizard*> ws2) {
	srand(time(0));
	int len1 = ws1.size();
	int len2 = ws2.size();
	int point1 = 0;
	int point2 = 0;
	group_display(ws1, ws2, len1, point1, len2, point2, true);
	while (point1 < len1 && point2 < len2) {
		group_display(ws1, ws2, len1, point1, len2, point2, false);
		_getch();
		int stat = fight(*(ws1[point1]), *(ws2[point2]));
		group_display(ws1, ws2, len1, point1, len2, point2, true);
		Sleep(500);
		if (stat == 1) point2++;
		else if (stat == 2) point1++;
		else { point1++; point2++; }
	}
	group_display(ws1, ws2, len1, point1, len2, point2, false);
	if (point1 < len1) team_win("first team WIN!!!");
	else if (point2 < len2) team_win("second team WIN!!!");
	else team_win("DRAW");
}