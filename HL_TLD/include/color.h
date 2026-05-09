#pragma once
#include <iostream>
#include <string>

class color {
public:
	//=====<color of text>=====
	static const std::string RED;
	static const std::string GREEN;
	static const std::string BLACK;
	static const std::string BLUE;
	static const std::string YELLOW;
	static const std::string MAGENTA;
	static const std::string CYAN;
	static const std::string WHITE;
	static const std::string BROWN;
	static const std::string LIME;
	static const std::string PURPLE;
	static const std::string ORANGE;
	static const std::string PINK;
	static const std::string GRAY;
	static const std::string MC;

	//=====<color of background>=====
	static const std::string BG_RED;
	static const std::string BG_GREEN;
	static const std::string BG_BLACK;
	static const std::string BG_BLUE;
	static const std::string BG_YELLOW;
	static const std::string BG_MAGENTA;
	static const std::string BG_CYAN;
	static const std::string BG_WHITE;
	static const std::string BG_BROWN;
	static const std::string BG_LIME;
	static const std::string BG_PURPLE;
	static const std::string BG_ORANGE;
	static const std::string BG_PINK;
	static const std::string BG_MC;

	//=========<style>=========
	static const std::string BOLD;
	static const std::string UNDERLINE;
	static const std::string STRIKE;
	static const std::string RESET;

	//=======<character>=======
	static std::string full;
	static std::string med_shade;
	static std::string horizontal_bar;
	static std::string vertical_bar;
	static std::string tl_corner;
	static std::string tr_corner;
	static std::string bl_corner;
	static std::string br_corner;
	static std::string TJ_left;
	static std::string TJ_right;
	static std::string TJ_down;
	static std::string TJ_up;
	static std::string cross;


	//====<CREATE NEW RGB>====
	static std::string txt_rgb(int r, int g, int b) {
		std::string c = "\x1b[38;2;";
		c += (std::to_string(r % 256) + ";" + std::to_string(g % 256) + ";" + std::to_string(b % 256) + "m");
		return c;
	}

	static std::string background_rgb(int r, int g, int b) {
		std::string c = "\x1b[48;2;";
		c += (std::to_string(r % 256) + ";" + std::to_string(g % 256) + ";" + std::to_string(b % 256) + "m");
		return c;
	}

	//====<color std::string and return>>===
	static std::string paint(const std::string& text, const std::string& fg = MC,
		const std::string& bg = BG_MC, bool bold = false, bool strike = false) {

		std::string result = "";

		if (bold) result += BOLD;
		if (strike) result += STRIKE;
		result += fg;
		result += bg;
		result += text;
		result += RESET;

		return result;
	}

	static void change_ascii();


};

