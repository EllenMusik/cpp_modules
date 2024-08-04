#pragma once

/* FOREGROUND */
#define RST   "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

// Text formatting
#define C_RESET			"\x1b[0m"     // Reset all text attributes
#define BOLD_			"\x1b[1m"     // Bold text
#define DIM_			"\x1b[2m"     // Dim text
#define ITAL_			"\x1b[3m"     // Italic text
#define ULINE_			"\x1b[4m"     // Underlined text

// Text color
#define BLACK			"\x1b[30m"    // Black text
#define RED				"\x1b[31m"    // Red text
#define GREEN			"\x1b[32m"    // Green text
#define YELLOW			"\x1b[33m"    // Yellow text
#define BLUE			"\x1b[34m"    // Blue text
#define PURPLE			"\x1b[35m"    // Purple text
#define CYAN			"\x1b[36m"    // Cyan text
#define WHITE			"\x1b[37m"    // White text

// Bright text color
#define BRIGHT_BLACK	"\x1b[90m"    // Bright black text
#define BRIGHT_RED		"\x1b[91m"    // Bright red text
#define BRIGHT_GREEN	"\x1b[92m"    // Bright green text
#define BRIGHT_YELLOW	"\x1b[93m"    // Bright yellow text
#define BRIGHT_BLUE		"\x1b[94m"    // Bright blue text
#define BRIGHT_PURPLE	"\x1b[95m"    // Bright purple text
#define BRIGHT_CYAN		"\x1b[96m"    // Bright cyan text
#define BRIGHT_WHITE	"\x1b[97m"    // Bright white text

// Background color
#define BG_BLACK		"\x1b[40m"    // Black background
#define BG_RED			"\x1b[41m"    // Red background
#define BG_GREEN		"\x1b[42m"    // Green background
#define BG_YELLOW		"\x1b[43m"    // Yellow background
#define BG_BLUE			"\x1b[44m"    // Blue background
#define BG_PURPLE		"\x1b[45m"    // Purple background
#define BG_CYAN			"\x1b[46m"    // Cyan background
#define BG_WHITE		"\x1b[47m"    // White background

// Bright background color
#define BG_BRIGHT_BLACK		"\x1b[100m"   // Bright black background
#define BG_BRIGHT_RED		"\x1b[101m"   // Bright red background
#define BG_BRIGHT_GREEN		"\x1b[102m"   // Bright green background
#define BG_BRIGHT_YELLOW	"\x1b[103m"   // Bright yellow background
#define BG_BRIGHT_BLUE		"\x1b[104m"   // Bright blue background
#define BG_BRIGHT_PURPLE	"\x1b[105m"   // Bright purple background
#define BG_BRIGHT_CYAN		"\x1b[106m"   // Bright cyan background
#define BG_BRIGHT_WHITE		"\x1b[107m"   // Bright white background


// Ellens Custom colours
#define RESET               "\e[38;5;0m"

#define YELLOW2             "\e[38;5;11m"
#define PINK                "\e[38;5;163m"
#define ORANGE              "\e[38;5;202m"
#define BRIGHT_ORANGE       "\e[38;5;209m"
#define LAVENDER            "\e[38;5;183m"
#define TEAL                "\e[38;5;30m"
#define TURQUOISE           "\e[38;5;43m"
#define PASTEL_PINK         "\e[38;5;212m"
#define PASTEL_BLUE         "\e[38;5;117m"
#define PASTEL_GREEN        "\e[38;5;156m"
#define PASTEL_RED          "\e[38;5;210m"
#define PASTEL_YELLOW       "\e[38;5;228m"