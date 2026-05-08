#pragma once
#include "Wizard.h"
#include <iostream>
#include <string>
#include <algorithm>

enum class TextAlign { Left = 0, Center = 1, Right = 2 };

std::string format_text(const std::string& text, size_t width,
    char fill = ' ', TextAlign align = TextAlign::Left);

void start_display(Wizard& w1, Wizard& w2);

void round_display(Wizard& w1, Wizard& w2, int r, int atk1 = 0, int atk2 = 0, int dmg1 = 0, int dmg2 = 0);

void group_display(vector<Wizard*> ws1, vector<Wizard*> ws2, int len1, int point1, int len2, int point2, bool reset);

void oneWin(std::string name1, std::string name2);
void secWin(std::string name1, std::string name2);
void draw(std::string name1, std::string name2);
void cont();
void team_win(std::string s);


//  000000000011111111112222222222333333333344444444445555555
//  012345678901234567890123456789012345678901234567890123456
//  ╔═══════════════════════════════════════════════════════╗
//  ║                  WIZARD DUEL - Round *                ║
//  ╠═══════════════════════════╦═══════════════════════════╣
//  ║1234567890abcdcba0987654321║1234567890abcdcba0987654321║
//  ║ HP : [██████████░░░] ***% ║ HP : [██████████░░░] ***% ║
//  ║          ***/***          ║          ***/***          ║
//  ║ Mana: ***     Skill: ***  ║ Mana: ***     Skill: ***  ║
//  ║                           ║                           ║
//  ║ Spells:           pwr|mana║ Spells:           pwr|mana║
//  ║  Expelliarmus     ***|*** ║  Expelliarmus     ***|*** ║
//  ║  Stupefy          ***|*** ║  Stupefy          ***|*** ║
//  ║  Lomus            ***|*** ║  Lomus            ***|*** ║
//  ║  Expecto_Patronum ***|*** ║  Expecto_Patronum ***|*** ║
//  ╠═══════════════════════════╩═══════════════════════════╣
//  ║   >> data1                                            ║
//  ║   >> data2                                            ║
//  ╚═══════════════════════════════════════════════════════╝
