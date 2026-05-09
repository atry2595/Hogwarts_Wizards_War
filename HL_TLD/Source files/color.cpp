#include "color.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

const string color::RED = "\x1b[38;2;255;0;0m";
const string color::GREEN = "\x1b[38;2;0;180;60m";
const string color::BLACK = "\x1b[38;2;0;0;0m";
const string color::BLUE = "\x1b[38;2;0;0;255m";
const string color::YELLOW = "\x1b[38;2;255;255;0m";
const string color::MAGENTA = "\x1b[38;2;246;0;164m";
const string color::CYAN = "\x1b[38;2;0;255;255m";
const string color::WHITE = "\x1b[38;2;255;255;255m";
const string color::BROWN = "\x1b[38;2;130;90;0m";
const string color::LIME = "\x1b[38;2;50;255;50m";
const string color::PURPLE = "\x1b[38;2;153;0;204m";
const string color::ORANGE = "\x1b[38;2;255;180;40m";
const string color::PINK = "\x1b[38;2;255;140;255m";
const string color::GRAY = "\x1b[90m";
const string color::MC = "\x1b[39m";

const string color::BG_RED = "\x1b[48;2;255;0;0m";
const string color::BG_GREEN = "\x1b[48;2;0;180;60m";
const string color::BG_BLACK = "\x1b[48;2;0;0;0m";
const string color::BG_BLUE = "\x1b[48;2;0;0;255m";
const string color::BG_YELLOW = "\x1b[48;2;255;255;0m";
const string color::BG_MAGENTA = "\x1b[48;2;246;0;164m";
const string color::BG_CYAN = "\x1b[48;2;0;255;255m";
const string color::BG_WHITE = "\x1b[48;2;255;255;255m";
const string color::BG_BROWN = "\x1b[48;2;130;90;0m";
const string color::BG_LIME = "\x1b[48;2;50;255;50m";
const string color::BG_PURPLE = "\x1b[48;2;153;0;204m";
const string color::BG_ORANGE = "\x1b[48;2;255;180;40m";
const string color::BG_PINK = "\x1b[48;2;255;140;255m";
const string color::BG_MC = "\x1b[49m";

const string color::BOLD = "\x1b[1m";
const string color::UNDERLINE = "\x1b[4m";
const string color::STRIKE = "\x1b[9m";
const string color::RESET = "\x1b[0m";;

string color::full = "\xDB";
string color::med_shade = "\xB0";
string color::horizontal_bar = "\xCD";
string color::vertical_bar = "\xBA";
string color::tl_corner = "\xC9";
string color::tr_corner = "\xBB";
string color::bl_corner = "\xC8";
string color::br_corner = "\xBC";
string color::TJ_left = "\xB9";
string color::TJ_right = "\xCC";
string color::TJ_down = "\xCB";
string color::TJ_up = "\xCA";
string color::cross = "\xCE";

void color::change_ascii() {
	color::full = "#";
	color::med_shade = " ";
	color::horizontal_bar = "-";
	color::vertical_bar = "|";
	color::tl_corner = "+";
	color::tr_corner = "+";
	color::bl_corner = "+";
	color::br_corner = "+";
	color::TJ_left = "+";
	color::TJ_right = "+";
	color::TJ_down = "+";
	color::TJ_up = "+";
	color::cross = "+";
}