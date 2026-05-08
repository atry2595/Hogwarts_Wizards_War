#include "logic.h"
#include "HouseWizards.h"
#include "display_game.h"
#include "color.h"
#include "selection.h"

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;


int main() {
    cout << "1. If you have trouble viewing the table when entering the game, press 1.\n2. If you have trouble viewing the list, use Ctrl + '-' to zoom out, go back, and then enter that section again.\n3. Make sure your keyboard language is set to English and Caps Lock is off\n\n + Use WASD to move up and down in the list.\n + Press E to increase the  fight_speed and Q to decrease it." << endl;
    _getch();
    system("cls");
    cout << "If you only see a '?' in the line below, press key 1; otherwise, press any other key." << endl;
    cout << color::horizontal_bar << " " + color::vertical_bar << " " + color::full << " " + color::med_shade << " " + color::tl_corner << " " + color::tr_corner;
    cout << " " + color::bl_corner << " " + color::br_corner << " " + color::TJ_down << " " + color::TJ_left << " " + color::TJ_right << " " + color::TJ_up << endl;
    string s;
    cin >> s;
    if (s == "1") color::change_ascii();

    vector<Wizard*> wizards = {};

    wizards.push_back(new Gryffindor("Harry Potter", 380, 1300, 15, animals::stag));
    wizards.push_back(new Gryffindor("Ron Weasley", 340, 1100, 12, animals::stag));
           
    wizards.push_back(new Slytherin("Draco Malfoy", 270, 1050, 11, animals::doe));
    wizards.push_back(new Slytherin("Severus Snape", 370, 1400, 17, animals::doe));
    wizards.push_back(new Slytherin("Tom Riddle", 500, 1450, 19, animals::doe));
           
    wizards.push_back(new Ravenclaw("Cho Chang", 240, 1100, 12, animals::owl));
    wizards.push_back(new Ravenclaw("Padma Patil", 70, 1200, 10, animals::owl));
           
    wizards.push_back(new Hufflepuff("Pomona Sprout", 200, 1200, 11, animals::phoenix));

    vector<string> names = {};
    for (auto& w : wizards) {
        string s = (w->get_name() + "\n");
        s += ("HouseWizards: " + format_text(w->get_home(), 11, ' '));
        s += ("  HP: " + format_text(to_string(w->get_fhp()), 4, '0', TextAlign::Right));
        s += ("  MANA: " + format_text(to_string(w->get_mana()), 4, '0', TextAlign::Right));
        names.push_back(s);
    }
    vector<string> cn = names;
    vector<Wizard*> cv = wizards;

    int mode = 0;
    while (true) {
        vector<string> modes = { "1v1 Figth", "team Figth" };
        mode = soloSelection(modes, mode);

        
        while (mode == 0) {
            names = cn;
            wizards = cv;
            system("cls");
            int w1 = 0;
            int w2 = 0;
            w1 = soloSelection(names, w1);
            if (w1 == -1) break;
            Wizard* wiz1 = wizards[w1];
            wizards.erase(wizards.begin() + w1);
            names.erase(names.begin() + w1);

            w2 = soloSelection(names, w2);
            if (w2 == -1) break;
            Wizard* wiz2 = wizards[w2];
            fight(*wiz1, *wiz2);
            wiz1->reset();
            wiz2->reset();
        }

        while (mode == 1) {
            names = cn;
            wizards = cv;
            system("cls");
            int num1 = 0;
            int num2 = 0;
            vector<int> w1 = {};
            vector<Wizard*> wiz1 = {};
            vector<int> w2 = {};
            vector<Wizard*> wiz2 = {};
            w1 = multySelection(names, 7, 1, num1);
            if (w1[0] == -1) break;
            
            for (int i = w1.size() - 1; i >= 0; i--) {
                int n = w1[i];
                wiz1.insert(wiz1.begin(), wizards[n]);
                names.erase(names.begin() + n);
                wizards.erase(wizards.begin() + n);
            }
            w2 = multySelection(names, 7, 1, num2);

            if (w2[0] == -1) break;
            for (int i : w2) {
                wiz2.push_back(wizards[i]);
            }
            
            group_fight(wiz1, wiz2);
            for (auto& elem : wiz1) {
                elem->reset();
            }
            for (auto& elem : wiz2) {
                elem->reset();
            }
        }

        if (mode == -1) {
            break;
        }
    }

}