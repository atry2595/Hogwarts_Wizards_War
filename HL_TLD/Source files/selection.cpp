#include "selection.h"
#include "sysFunc.h"  //gotoxy - cursor
#include "color.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

int soloSelection(vector<string> texts, int& row) {
	int count = texts.size();
	vector<int> list(count, 0);
	row %= count;
	list[row] = 1;

	string Sred = color::txt_rgb(150, 0, 0);
	hidecursor();
	system("cls");

	int x = 0;

	while (1) {
		gotoxy(0, 0);
		for (int i = 0; i < count; i++) {

			switch (list[i]) {
			case 0:
				cout << color::paint(texts[i], color::WHITE) << endl << endl;
				break;
			case 1:
				cout << color::paint(texts[i], color::RED) << endl << endl;
				break;
			}
		}

		if (row == count) {
			cout << color::paint("Back\n", color::RED);
		}
		else cout << color::paint("Back\n", color::WHITE);

		char  inp = _getch();
		switch (inp) {
		case'w':
			if (row > 0 && row < count) {
				list[row]--;
				row--;
				list[row]++;
			}
			else if (row == count) {
				row--;
				list[row]++;
			}
			break;
		case's':
			if (row < count - 1) {
				list[row]--;
				row++;
				list[row]++;
			}
			else if (row < count) {
				list[row]--;
				row++;
			}
			break;
		case'\r':
			if (row == count) {
				return -1;
			}
			else {
				for (int i = 0; i < count; i++) {
					if (list[i] == 1) return i;
				}
				return -1;
			}


			break;
		}
	}
}

vector<int> multySelection(vector<string> texts, int limit, int least, int& row) {
	int count = texts.size();
	vector<int> list(count, 0);
	if (row >= count) row = 0;
	list[row] = 1;

	string Sred = color::txt_rgb(150, 0, 0);
	hidecursor();
	system("cls");

	int x = 0;
	int t = 0;

	while (1) {
		gotoxy(0, 0);
		for (int i = 0; i < count; i++) {

			switch (list[i]) {
			case 0:
				cout << color::paint(texts[i], color::WHITE) << endl << endl;
				break;
			case 1:
				cout << color::paint(texts[i], color::RED) << endl << endl;
				break;
			case 2:
				cout << color::paint(texts[i], color::CYAN) << endl << endl;
				break;
			case 3:
				cout << color::paint(texts[i], Sred) << endl << endl;
				break;
			}
		}
		if (row == count) {
			cout << color::paint("continue\n", color::RED) << endl;
		}
		else cout << color::paint("continue\n", color::WHITE) << endl;

		if (row == count + 1) {
			cout << color::paint("Back", color::RED);
		}
		else cout << color::paint("Back", color::WHITE);

		char  inp = _getch();
		switch (inp) {
		case'w':
			if (row > 0 && row < count) {
				list[row]--;
				row--;
				list[row]++;
			}
			else if (row == count) {
				row--;
				list[row]++;
			}
			else if (row == count + 1) {
				row--;
			}
			break;
		case's':
			if (row < count - 1) {
				list[row]--;
				row++;
				list[row]++;
			}
			else if (row < count) {
				list[row]--;
				row++;
			}
			else if (row < count + 1) {
				row++;
			}
			break;
		case'\r':
			if (row == count) {
				if (t >= least) {
					vector<int> selected = {};
					for (int i = 0; i < count; i++) {
						if (list[i] == 2) selected.push_back(i);
					}
					return selected;
				}
			}
			else if (row == count + 1) {
				vector<int> selected = { -1 };
				return selected;
			}

       		else if (list[row] > 1) {
				list[row] -= 2;
				t--;
			}

			else if (t < limit) {
				list[row] += 2;
				t++;
			}

			break;
		}
	}
}
