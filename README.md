<div align="center">

# 🪄 Hogwarts Wizards War

</div>

**A text-based wizard battle simulator inspired by the Harry Potter universe, playable entirely in the console.**

---



## 📖 About The Project

This project simulates 1v1 and group battles between wizards. Each wizard is an object with attributes inspired by the Harry Potter lore. The goal is to select your wizards and watch them fight in turn-based matches, with all actions displayed in a formatted console table.

### ✨ Features
- **1v1 Duels:** Classic one-on-one wizard combat.
- **Team Battles:** Group vs group fights.
- **Wizard Attributes:** Each wizard has unique stats based on Hogwarts houses and characters.
- **Formatted Console Display:** Color-coded text and dynamic tables for an immersive terminal experience.
- **Navigation Controls:** Full keyboard control for selecting wizards and teams.

---



## 🎮 How to Play

### Controls
| Key | Action |
|-----|--------|
| `w` / `s` | Move selection up/down in lists |
| `e` | Increase fight animation speed |
| `q` | Decrease fight animation speed |
| `Enter` | Confirm selection |

### Important Tips
1.  **Table Display Issues?** Press `1` when entering the game to fix table formatting.
2.  **List Cut Off?** Use `Ctrl + -` to zoom out in terminal, go back, and re-enter the section.
3.  **Input Problems?** Ensure your keyboard is set to **English** with **Caps Lock off**.

---



## 🛠️ Technical Details

**Language:** C++  
**Type:** Console Application  
**Key Concepts Used:**
- Object-Oriented Programming (Classes: `Wizard`, `color`, `display_game`, etc.)
- Dynamic formatted text output
- Custom console coloring (ASCII 256)
- Keyboard-driven list navigation

---



## 📁 Project Structure

```text
HL_TLD/
├── include/ # Header files (.h)
└── Source filse/ # Source files (.cpp)
```



### Module Descriptions

#### 🎨 `color`
Handles all visual styling in the console.
- `color::paint` — Colors and styles a piece of text.
- `color::change_ascii` — Converts symbols using ASCII 256 table.

#### 🖥️ `display_game`
Manages all formatted console displays for matches.
- `format_text()` — Adjusts string length and fills empty space with a specified character.
- `start_display()` — Draws the fixed parts of the match table at the start of each match.
- `round_display()` — Draws variable match table parts at the beginning of each round.
- `group_display()` — Shows wizard statuses during team matches.

#### ⚔️ `logic`
Core battle mechanics and game logic.
- `round_fight()` — Executes a single round of a match.
- `fight()` — Controls an entire match flow.
- `group_fight()` — Manages group battle execution.

#### 🎯 `selection`
Creates interactive selection menus with keyboard navigation.
- `soloSelection()` — Select one item from a list.
- `multiSelection()` — Select multiple items from a list.

---



## 🧑‍💻 Author

**Alireza Amini**
- GitHub: [@atry2595](https://github.com/atry2595)

---



## 📝 Notes

This project was developed as a personal learning project for C++ and Object-Oriented Programming concepts, with the Harry Potter theme chosen to make the process engaging and fun.

If you have any questions, feel free to reach out or open an issue!
