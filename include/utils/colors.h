#pragma once

typedef struct Color
{
	int r;
	int g;
	int b;
} Color;

#define LIGHTGRAY  (Color){ 200, 200, 200 }   // Light Gray
#define GRAY       (Color){ 130, 130, 130 }   // Gray
#define DARKGRAY   (Color){ 80, 80, 80 }      // Dark Gray
#define YELLOW     (Color){ 253, 249, 0 }     // Yellow
#define GOLD       (Color){ 255, 203, 0 }     // Gold
#define ORANGE     (Color){ 255, 161, 0 }     // Orange
#define PINK       (Color){ 255, 109, 194 }   // Pink
#define RED        (Color){ 230, 41, 55 }     // Red
#define MAROON     (Color){ 190, 33, 55 }     // Maroon
#define GREEN      (Color){ 0, 228, 48 }      // Green
#define LIME       (Color){ 0, 158, 47 }      // Lime
#define DARKGREEN  (Color){ 0, 117, 44 }      // Dark Green
#define SKYBLUE    (Color){ 102, 191, 255 }   // Sky Blue
#define BLUE       (Color){ 0, 121, 241 }     // Blue
#define DARKBLUE   (Color){ 0, 82, 172 }      // Dark Blue
#define PURPLE     (Color){ 200, 122, 255 }   // Purple
#define VIOLET     (Color){ 135, 60, 190 }    // Violet
#define DARKPURPLE (Color){ 112, 31, 126 }    // Dark Purple
#define BEIGE      (Color){ 211, 176, 131 }   // Beige
#define BROWN      (Color){ 127, 106, 79 }    // Brown
#define DARKBROWN  (Color){ 76, 63, 47 }      // Dark Brown

#define WHITE      (Color){ 255, 255, 255 }   // White
#define BLACK      (Color){ 0, 0, 0 }         // Black
#define BLANK      (Color){ 0, 0, 0 }           // Blank (Transparent)
#define MAGENTA    (Color){ 255, 0, 255 }     // Magenta
#define RAYWHITE   (Color){ 245, 245, 245 }   // My own White (raylib logo)
