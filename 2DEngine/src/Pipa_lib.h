#pragma once

#include<stdio.h>

// defines

// logging
enum TextColor
{
	TEXT_COLOR_BLACK,
	TEXT_COLOR_RED,
	TEXT_COLOR_GREEN,
	TEXT_COLOR_YELLOW,
	TEXT_COLOR_BLUE,
	TEXT_COLOR_MAGENTA,
	TEXT_COLOR_CYAN,
	TEXT_COLOR_WHITE,
	TEXT_COLOR_BRIGHT_BLACK,
	TEXT_COLOR_BRIGHT_RED,
	TEXT_COLOR_BRIGHT_GREEN,
	TEXT_COLOR_BRIGHT_YELLOW,
	TEXT_COLOR_BRIGHT_BLUE,
	TEXT_COLOR_BRIGHT_MAGENTA,
	TEXT_COLOR_BRIGHT_CYAN,
	TEXT_COLOR_BRIGHT_WHITE,
	TEXT_COLOR_COUNT
};

template<typename ...Args>
void _log(char* prefix, char* msg, TextColor textColor, Args... args)
{
	"\x1b[30m" + msg + "\033[0m";	// This is black text
}