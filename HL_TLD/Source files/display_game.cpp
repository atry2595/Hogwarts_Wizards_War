#include "display_game.h"
#include "sysFunc.h"
#include "color.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

template<typename every>
bool exist_in(const std::vector<every>& list, const every& goal) {
    for (auto& elem : list) {
        if (elem == goal) return true;
    }
    return false;
}



std::string format_text(const std::string& text, size_t width,
    char fill, TextAlign align) {

    if (text.length() >= width) {
        return text.substr(0, width);
    }

    size_t diff = width - text.length();

    switch (align) {
    case TextAlign::Left:
        return text + std::string(diff, fill);

    case TextAlign::Right:
        return std::string(diff, fill) + text;

    case TextAlign::Center: {
        size_t left_pad = diff / 2;
        size_t right_pad = diff - left_pad;
        return std::string(left_pad, fill) + text + std::string(right_pad, fill);
    }
    }

    return text;
}

void start_display(Wizard& w1, Wizard& w2) {
    system("cls");
    vector<int> hor = { 0,2,13,16 };
    vector<int> ver = { 0,56 };
    vector<int> ver3 = { 28, 2, 13 };
    
    for (int r : hor) {
        gotoxy(r, 0);
        for (int i = 0; i < 57; i++)cout << color::horizontal_bar;
    }
    
    for (int c : ver) {
        for (int i = 0; i < 17; i++) {
            gotoxy(i, c);
            cout << color::vertical_bar;
        }
    }

    
    for (int i = ver3[1]; i < ver3[2] + 1; i++) {
        gotoxy(i, ver3[0]);
        cout << color::vertical_bar;
    }

    gotoxy(0, 0); cout << color::tl_corner;
    gotoxy(0, 56); cout << color::tr_corner;
    gotoxy(16, 0); cout << color::bl_corner;
    gotoxy(16, 56); cout << color::br_corner;
    
    gotoxy(2, 0); cout << color::TJ_right;
    gotoxy(13, 0); cout << color::TJ_right;
    gotoxy(2, 56); cout << color::TJ_left;
    gotoxy(13, 56); cout << color::TJ_left;
    gotoxy(13, 28); cout << color::TJ_up;
    gotoxy(2, 28); cout << color::TJ_down;

    gotoxy(1, 19); cout << color::paint("WIZARD DUEL - Round 1", color::YELLOW);

    gotoxy(3, 2);
    cout << color::paint(format_text(w1.get_name(), 24, ' '), color::BLUE, color::BG_MC, true);
    gotoxy(4, 2);
    cout << "HP : [             ] 100%";
    gotoxy(5, 2);
    cout << "Wizard home: " << color::paint(format_text(w1.get_home(), 11, ' '), color::CYAN);
    gotoxy(6, 2);
    cout << "Mana: " << format_text(to_string(w1.get_mana()), 4, '0', TextAlign::Right);
    gotoxy(6, 16);
    cout << "HP: " << format_text(to_string(w1.get_fhp()), 4, '0', TextAlign::Right);
    gotoxy(8, 2);
    cout << "Spells:           pwr|mana";
    gotoxy(9, 3);
    cout << "Expelliarmus     " << format_text(to_string(w1.get_spell_power(0)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(0)), 3, '0', TextAlign::Right);
    gotoxy(10, 3);
    cout << "Stupefy          " << format_text(to_string(w1.get_spell_power(1)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(1)), 3, '0', TextAlign::Right);
    gotoxy(11, 3);
    cout << "Lomus            " << format_text(to_string(w1.get_spell_power(2)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(2)), 3, '0', TextAlign::Right);
    gotoxy(12, 3);
    cout << "Expecto_Patronum " << format_text(to_string(w1.get_spell_power(3)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(3)), 3, '0', TextAlign::Right);


    gotoxy(3, 2 + 28);
    cout << color::paint(format_text(w2.get_name(), 24, ' '), color::MAGENTA, color::BG_MC, true);
    gotoxy(4, 2 + 28);
    cout << "HP : [             ] 100%";
    gotoxy(5, 2 + 28);
    cout << "Wizard home: " << color::paint(format_text(w2.get_home(), 11, ' '), color::PINK);
    gotoxy(6, 2 + 28);
    cout << "Mana: " << format_text(to_string(w2.get_mana()), 4, '0', TextAlign::Right);
    gotoxy(6, 16 + 28);
    cout << "HP: " << format_text(to_string(w2.get_fhp()), 4, '0', TextAlign::Right);
    gotoxy(8, 2 + 28);
    cout << "Spells:           pwr|mana";
    gotoxy(9, 3 + 28);
    cout << "Expelliarmus     " << format_text(to_string(w2.get_spell_power(0)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(0)), 3, '0', TextAlign::Right);
    gotoxy(10, 3 + 28);
    cout << "Stupefy          " << format_text(to_string(w2.get_spell_power(1)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(1)), 3, '0', TextAlign::Right);
    gotoxy(11, 3 + 28);
    cout << "Lomus            " << format_text(to_string(w2.get_spell_power(2)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(2)), 3, '0', TextAlign::Right);
    gotoxy(12, 3 + 28);
    cout << "Expecto_Patronum " << format_text(to_string(w2.get_spell_power(3)), 3, '0', TextAlign::Right) << "|" << format_text(to_string(w1.get_spell_mana(3)), 3, '0', TextAlign::Right);
    gotoxy(17, 0);
    cout << "enter e key for increase speed" << endl;
    cout << "enter q key for decrease speed" << endl;
}

void round_display(Wizard& w1, Wizard& w2, int r, int atk1, int atk2, int dmg1, int dmg2) {
    gotoxy(1, 39);
    cout << r;  

    //--------------------------------------
    float hp1 = (w1.get_hp() * 13);
    int hp1_bar;
    if (hp1 == 0) hp1_bar = 0;
    else hp1_bar = hp1 + 1;
    if (hp1_bar > 13) hp1_bar = 13;

    string clr;
    if (hp1_bar > 8) clr = color::GREEN;
    else if (hp1_bar > 3) clr = color::YELLOW;
    else if (hp1_bar > 0) clr = color::RED;
    else clr = color::GRAY;

    gotoxy(4, 8);
    for (int i = 0; i < hp1_bar; i++) {
        cout << color::paint(color::full, clr);
    }
    for (int i = 0; i < 13 - hp1_bar; i++) {
        cout << color::paint(color::med_shade, clr);
    }
    gotoxy(4, 23);
    cout << format_text(to_string((hp1 / 13) * 100), 3, '0', TextAlign::Right);
    gotoxy(6, 8);
    cout << format_text(to_string(w1.get_mana()), 4, '0', TextAlign::Right);

    gotoxy(6, 16);
    cout << "HP: " << format_text(to_string(w1.get_fhp()), 4, '0', TextAlign::Right);

    gotoxy(6, 16 + 28);
    cout << "HP: " << format_text(to_string(w2.get_fhp()), 4, '0', TextAlign::Right);

    //--------------------------------------
    float hp2 = (w2.get_hp() * 13);
    int hp2_bar;
    if (hp2 == 0) hp2_bar = 0;
    else hp2_bar = hp2 + 1;
    if (hp2_bar > 13) hp2_bar = 13;

    clr;
    if (hp2_bar > 8) clr = color::GREEN;
    else if (hp2_bar > 3) clr = color::YELLOW;
    else if (hp2_bar > 0) clr = color::RED;
    else clr = color::GRAY;

    gotoxy(4, 8 + 28);
    for (int i = 0; i < hp2_bar; i++) {
        cout << color::paint(color::full, clr);
    }
    for (int i = 0; i < 13 - hp2_bar; i++) {
        cout << color::paint(color::med_shade, clr);
    }
    gotoxy(4, 23 + 28);
    cout << format_text(to_string((hp2 / 13) * 100), 3, '0', TextAlign::Right);
    gotoxy(6, 8 + 28);
    cout << format_text(to_string(w2.get_mana()), 4, '0', TextAlign::Right);
    
    //--------------------------------------
    gotoxy(14, 8);
    cout << color::paint("attack : ", color::GREEN) << format_text(to_string(atk1), 3, '0', TextAlign::Right);
    gotoxy(15, 8);
    cout << color::paint("damage : ", color::RED) << format_text(to_string(dmg1), 3, '0', TextAlign::Right);
    gotoxy(14, 8 + 28);
    cout << color::paint("attack : ", color::GREEN) << format_text(to_string(atk2), 3, '0', TextAlign::Right);
    gotoxy(15, 8 + 28);
    cout << color::paint("damage : ", color::RED) << format_text(to_string(dmg2), 3, '0', TextAlign::Right);
}



void group_display(vector<Wizard*> ws1, vector<Wizard*> ws2, int len1, int point1, int len2, int point2, bool reset) {
    if (reset) system("cls");

    if (point1 > 0) {
        gotoxy(1, 5);
        cout << color::paint(format_text(ws1[point1 - 1]->get_name(), 15, ' ', TextAlign::Center), color::GRAY, color::BG_MC, false, true);
    }
    if (point2 > 0) {
        gotoxy(1, 5 + 19);
        cout << color::paint(format_text(ws2[point2 - 1]->get_name(), 15, ' ', TextAlign::Center), color::GRAY, color::BG_MC, false, true);
    }

    Sleep(66);

    if (point1 < len1) {
        gotoxy(2, 5);
        cout << color::paint(format_text(ws1[point1]->get_name(), 15, ' ', TextAlign::Center), color::WHITE, color::BG_MC, true);
    }
    else {
        gotoxy(2, 5);
        cout << color::paint(format_text("", 15, ' ', TextAlign::Center), color::GRAY);
    }

    gotoxy(2, 5 + 15); cout << color::paint(" VS ", color::RED);

    if (point2 < len2) {
        gotoxy(2, 5 + 19);
        cout << color::paint(format_text(ws2[point2]->get_name(), 15, ' ', TextAlign::Center), color::WHITE, color::BG_MC, true);
    }
    else {
        gotoxy(2, 5 + 19);
        cout << color::paint(format_text("", 15, ' ', TextAlign::Center), color::GRAY);
    }

    Sleep(66);

    if (point1 + 1 < len1) {
        gotoxy(3, 5);
        cout << color::paint(format_text(ws1[point1 + 1]->get_name(), 15, ' ', TextAlign::Center), color::GRAY);
    }
    else {
        gotoxy(3, 5);
        cout << color::paint(format_text("", 15, ' ', TextAlign::Center), color::GRAY);
    }

    if (point2 + 1 < len2) {
        gotoxy(3, 5 + 19);
        cout << color::paint(format_text(ws2[point2 + 1]->get_name(), 15, ' ', TextAlign::Center), color::GRAY);
    }
    else {
        gotoxy(3, 5 + 19);
        cout << color::paint(format_text("", 15, ' ', TextAlign::Center), color::GRAY);
    }

    gotoxy(6, 0);
    cout << "Press any key to continue     " << endl;

}


void oneWin(string name1, string name2) {
    gotoxy(14, 1);
    cout << color::paint(format_text(name1 + " won the game!!!", 54, ' ', TextAlign::Center), color::GREEN);
    
    gotoxy(15, 1);
    cout << color::paint(format_text(name2 + " was killed!!!", 54, ' ', TextAlign::Center), color::RED);
    cont();
}

void secWin(std::string name1, std::string name2) {
    gotoxy(14, 1);
    cout << color::paint(format_text(name1 + " was killed!!!", 54, ' ', TextAlign::Center), color::RED);

    gotoxy(15, 1);
    cout << color::paint(format_text(name2 + " won the game!!!", 54, ' ', TextAlign::Center), color::GREEN);
    cont();

}

void draw(std::string name1, std::string name2) {
    gotoxy(14, 1);
    cout << color::paint(format_text(name1 + " was killed!!!", 54, ' ', TextAlign::Center), color::RED);


    gotoxy(15, 1);
    cout << color::paint(format_text(name2 + " was killed!!!", 54, ' ', TextAlign::Center), color::RED);
    cont();
}

void cont() {
    gotoxy(17, 0);
    cout << "                              " << endl;
    cout << "Press any key to continue     " << endl;
    cout << "                              " << endl;
}

void team_win(string s) {
    gotoxy(5, 12);
    cout << color::paint((s), color::GREEN);
    _getch();
}

//  000000000011111111112222222222333333333344444444445555555
//  012345678901234567890123456789012345678901234567890123456
//  ╔═══════════════════════════════════════════════════════╗ 00
//  ║                  WIZARD DUEL - Round *                ║ 01
//  ╠═══════════════════════════╦═══════════════════════════╣ 02
//  ║1234567890abcdcba0987654321║1234567890abcdcba0987654321║ 03
//  ║ HP : [██████████░░░] ***% ║ HP : [██████████░░░] ***% ║ 04
//  ║ Wizard home: **********   ║ Wizard home: **********   ║ 05
//  ║ Mana: ***     Skill: ***  ║ Mana: ***     Skill: ***  ║ 06
//  ║                           ║                           ║ 07
//  ║ Spells:           pwr|mana║ Spells:           pwr|mana║ 08
//  ║  Expelliarmus     ***|*** ║  Expelliarmus     ***|*** ║ 09
//  ║  Stupefy          ***|*** ║  Stupefy          ***|*** ║ 10
//  ║  Lomus            ***|*** ║  Lomus            ***|*** ║ 11
//  ║  Expecto_Patronum ***|*** ║  Expecto_Patronum ***|*** ║ 12
//  ╠═══════════════════════════╩═══════════════════════════╣ 13
//  ║       attack : ***                attack : ***        ║ 14
//  ║       damage : ***                damage : ***        ║ 15
//  ╚═══════════════════════════════════════════════════════╝ 16