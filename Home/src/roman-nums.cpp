#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <iostream>

#define GRID_SIZE_X 10
#define GRID_SIZE_Y 10
#define NAME_SPACE 50

void romanI(int x, int y, int height){
	// one numeral number
	setcolor(WHITE);
	line(x, y, x, y + height);
}

void romanV(int x, int y, int height){
	// five numeral number which looks like V
	setcolor(WHITE);
	line(x, y, x + height / 6, y + height);
	line(x + height / 6, y + height, x + height / 3, y);
}

void romanX(int x, int y, int height){
	// ten numeral number which looks two lines intersecting each other
	setcolor(WHITE);
	line(x, y, x + height / 6, y + height);
	line(x - height / 12, y + height, x + height / 4, y);
}

void romanL(int x, int y, int height){
	// fifty numeral number which looks like L
	setcolor(WHITE);
	line(x, y, x, y + height);
	line(x, y + height, x + height / 4, y + height);
}

void romanC(int x, int y, int height) {
	// Draw the arc to form the shape of 'C'
	setcolor(WHITE);
	arc(x + height / 6, y + height / 6, 90, -90, height / 3);
}

int main()
{
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

	// Calculate rectangle size based on screen dimensions and grid size
    int rectangleSize = x / GRID_SIZE_X;
    if (rectangleSize > (y - NAME_SPACE) / GRID_SIZE_Y)
        rectangleSize = (y - NAME_SPACE) / GRID_SIZE_Y;

    // Calculate offset to center the grid
    int offsetX = (x - GRID_SIZE_X * rectangleSize) / 2;
    int offsetY = (y - NAME_SPACE - GRID_SIZE_Y * rectangleSize) / 2;

	 // Loop through rows
    for (int i = 0; i < GRID_SIZE_Y; ++i) {
        // Loop through columns
        for (int j = 0; j < GRID_SIZE_X; ++j) {
            int x1 = offsetX + j * rectangleSize;
            int y1 = offsetY + i * rectangleSize;
            int x2 = x1 + rectangleSize;
            int y2 = y1 + rectangleSize;

            // Draw rectangle
            rectangle(x1, y1, x2, y2);
        }
    }

	// I
	romanI(offsetX + 20, offsetY + 10, 15);

	// II
	romanI(offsetX + 60, offsetY + 10, 15);
	romanI(offsetX + 65, offsetY + 10, 15);

	// III
	romanI(offsetX + 100, offsetY + 10, 15);
	romanI(offsetX + 105, offsetY + 10, 15);
	romanI(offsetX + 110, offsetY + 10, 15);

	// IV
	romanI(offsetX + 135, offsetY + 10, 15);
	romanV(offsetX + 140, offsetY + 10, 15);

	// V
	romanV(offsetX + 180, offsetY + 10, 15);

	// VI
	romanV(offsetX + 220, offsetY + 10, 15);
	romanI(offsetX + 245, offsetY + 10, 15);

	// VII
	romanV(offsetX + 265, offsetY + 10, 15);
	romanI(offsetX + 280, offsetY + 10, 15);
	romanI(offsetX + 285, offsetY + 10, 15);

	// VIII
	romanV(offsetX + 305, offsetY + 10, 15);
	romanI(offsetX + 320, offsetY + 10, 15);
	romanI(offsetX + 325, offsetY + 10, 15);
	romanI(offsetX + 330, offsetY + 10, 15);

	// IX
	romanI(offsetX + 350, offsetY + 10, 15);
	romanX(offsetX + 360, offsetY + 10, 15);

	// X
	romanX(offsetX + 400, offsetY + 10, 15);

	// XI
	romanX(offsetX + 15, offsetY + 55, 15);
	romanI(offsetX + 30, offsetY + 55, 15);

	// XII
	romanX(offsetX + 55, offsetY + 55, 15);
	romanI(offsetX + 70, offsetY + 55, 15);
	romanI(offsetX + 75, offsetY + 55, 15);

	// XIII
	romanX(offsetX + 95, offsetY + 55, 15);
	romanI(offsetX + 110, offsetY + 55, 15);
	romanI(offsetX + 115, offsetY + 55, 15);
	romanI(offsetX + 120, offsetY + 55, 15);

	// XIV
	romanX(offsetX + 140, offsetY + 55, 15);
	romanI(offsetX + 155, offsetY + 55, 15);
	romanV(offsetX + 160, offsetY + 55, 15);

	// XV
	romanX(offsetX + 180, offsetY + 55, 15);
	romanV(offsetX + 195, offsetY + 55, 15);

	// XVI
	romanX(offsetX + 220, offsetY + 55, 15);
	romanV(offsetX + 230, offsetY + 55, 15);
	romanI(offsetX + 245, offsetY + 55, 15);

	// XVII
	romanX(offsetX + 260, offsetY + 55, 15);
	romanV(offsetX + 270, offsetY + 55, 15);
	romanI(offsetX + 280, offsetY + 55, 15);
	romanI(offsetX + 285, offsetY + 55, 15);

	// XVIII
	romanX(offsetX + 300, offsetY + 55, 15);
	romanV(offsetX + 310, offsetY + 55, 15);
	romanI(offsetX + 320, offsetY + 55, 15);
	romanI(offsetX + 325, offsetY + 55, 15);
	romanI(offsetX + 330, offsetY + 55, 15);

	// XIX
	romanX(offsetX + 350, offsetY + 55, 15);
	romanI(offsetX + 360, offsetY + 55, 15);
	romanX(offsetX + 365, offsetY + 55, 15);

	// XX
	romanX(offsetX + 395, offsetY + 55, 15);
	romanX(offsetX + 405, offsetY + 55, 15);

	// XXI
	romanX(offsetX + 15, offsetY + 100, 15);
	romanX(offsetX + 25, offsetY + 100, 15);
	romanI(offsetX + 35, offsetY + 100, 15);

	// XXII
	romanX(offsetX + 55, offsetY + 100, 15);
	romanX(offsetX + 65, offsetY + 100, 15);
	romanI(offsetX + 75, offsetY + 100, 15);
	romanI(offsetX + 80, offsetY + 100, 15);

	// XXIII
	romanX(offsetX + 90, offsetY + 100, 15);
	romanX(offsetX + 100, offsetY + 100, 15);
	romanI(offsetX + 110, offsetY + 100, 15);
	romanI(offsetX + 115, offsetY + 100, 15);
	romanI(offsetX + 120, offsetY + 100, 15);

	// XXIV
	romanX(offsetX + 135, offsetY + 100, 15);
	romanX(offsetX + 145, offsetY + 100, 15);
	romanI(offsetX + 155, offsetY + 100, 15);
	romanV(offsetX + 160, offsetY + 100, 15);

	// XXV
	romanX(offsetX + 175, offsetY + 100, 15);
	romanX(offsetX + 185, offsetY + 100, 15);
	romanV(offsetX + 195, offsetY + 100, 15);

	// XXVI
	romanX(offsetX + 215, offsetY + 100, 15);
	romanX(offsetX + 225, offsetY + 100, 15);
	romanV(offsetX + 235, offsetY + 100, 15);
	romanI(offsetX + 245, offsetY + 100, 15);

	// XXVII
	romanX(offsetX + 255, offsetY + 100, 15);
	romanX(offsetX + 265, offsetY + 100, 15);
	romanV(offsetX + 275, offsetY + 100, 15);
	romanI(offsetX + 285, offsetY + 100, 15);
	romanI(offsetX + 290, offsetY + 100, 15);

	// XXVIII
	romanX(offsetX + 300, offsetY + 100, 15);
	romanX(offsetX + 305, offsetY + 100, 15);
	romanV(offsetX + 310, offsetY + 100, 15);
	romanI(offsetX + 320, offsetY + 100, 15);
	romanI(offsetX + 325, offsetY + 100, 15);
	romanI(offsetX + 330, offsetY + 100, 15);

	// XXIX
	romanX(offsetX + 340, offsetY + 100, 15);
	romanX(offsetX + 350, offsetY + 100, 15);
	romanI(offsetX + 355, offsetY + 100, 15);
	romanX(offsetX + 360, offsetY + 100, 15);

	// XXX
	romanX(offsetX + 390, offsetY + 100, 15);
	romanX(offsetX + 400, offsetY + 100, 15);
	romanX(offsetX + 410, offsetY + 100, 15);

	// XXXI
	romanX(offsetX + 10, offsetY + 145, 15);
	romanX(offsetX + 20, offsetY + 145, 15);
	romanX(offsetX + 30, offsetY + 145, 15);
	romanI(offsetX + 40, offsetY + 145, 15);

	// XXXII
	romanX(offsetX + 50, offsetY + 145, 15);
	romanX(offsetX + 55, offsetY + 145, 15);
	romanX(offsetX + 60, offsetY + 145, 15);
	romanI(offsetX + 70, offsetY + 145, 15);
	romanI(offsetX + 75, offsetY + 145, 15);

	// XXXIII
	romanX(offsetX + 95, offsetY + 145, 15);
	romanX(offsetX + 100, offsetY + 145, 15);
	romanX(offsetX + 105, offsetY + 145, 15);
	romanI(offsetX + 110, offsetY + 145, 15);
	romanI(offsetX + 115, offsetY + 145, 15);
	romanI(offsetX + 120, offsetY + 145, 15);

	// XXXIV
	romanX(offsetX + 130, offsetY + 145, 15);
	romanX(offsetX + 135, offsetY + 145, 15);
	romanX(offsetX + 140, offsetY + 145, 15);
	romanI(offsetX + 150, offsetY + 145, 15);
	romanV(offsetX + 155, offsetY + 145, 15);

	// XXXV
	romanX(offsetX + 175, offsetY + 145, 15);
	romanX(offsetX + 180, offsetY + 145, 15);
	romanX(offsetX + 185, offsetY + 145, 15);
	romanV(offsetX + 190, offsetY + 145, 15);

	// XXXVI
	romanX(offsetX + 215, offsetY + 145, 15);
	romanX(offsetX + 220, offsetY + 145, 15);
	romanX(offsetX + 225, offsetY + 145, 15);
	romanV(offsetX + 230, offsetY + 145, 15);
	romanI(offsetX + 240, offsetY + 145, 15);

	// XXXVII
	romanX(offsetX + 260, offsetY + 145, 15);
	romanX(offsetX + 265, offsetY + 145, 15);
	romanX(offsetX + 270, offsetY + 145, 15);
	romanV(offsetX + 275, offsetY + 145, 15);
	romanI(offsetX + 285, offsetY + 145, 15);
	romanI(offsetX + 290, offsetY + 145, 15);

	// XXXVIII
	romanX(offsetX + 300, offsetY + 145, 15);
	romanX(offsetX + 305, offsetY + 145, 15);
	romanX(offsetX + 310, offsetY + 145, 15);
	romanV(offsetX + 315, offsetY + 145, 15);
	romanI(offsetX + 323, offsetY + 145, 15);
	romanI(offsetX + 328, offsetY + 145, 15);
	romanI(offsetX + 333, offsetY + 145, 15);

	// XXXIX
	romanX(offsetX + 340, offsetY + 145, 15);
	romanX(offsetX + 345, offsetY + 145, 15);
	romanX(offsetX + 350, offsetY + 145, 15);
	romanI(offsetX + 355, offsetY + 145, 15);
	romanX(offsetX + 360, offsetY + 145, 15);

	// XL
	romanX(offsetX + 390, offsetY + 145, 15);
	romanL(offsetX + 400, offsetY + 145, 15);

	// XLI
	romanX(offsetX + 10, offsetY + 190, 15);
	romanL(offsetX + 20, offsetY + 190, 15);
	romanI(offsetX + 30, offsetY + 190, 15);

	// XLII
	romanX(offsetX + 50, offsetY + 190, 15);
	romanL(offsetX + 60, offsetY + 190, 15);
	romanI(offsetX + 70, offsetY + 190, 15);
	romanI(offsetX + 75, offsetY + 190, 15);

	// XLIII
	romanX(offsetX + 90, offsetY + 190, 15);
	romanL(offsetX + 100, offsetY + 190, 15);
	romanI(offsetX + 110, offsetY + 190, 15);
	romanI(offsetX + 115, offsetY + 190, 15);
	romanI(offsetX + 120, offsetY + 190, 15);

	// XLIV
	romanX(offsetX + 130, offsetY + 190, 15);
	romanL(offsetX + 140, offsetY + 190, 15);
	romanI(offsetX + 150, offsetY + 190, 15);
	romanV(offsetX + 155, offsetY + 190, 15);

	// XLV
	romanX(offsetX + 175, offsetY + 190, 15);
	romanL(offsetX + 185, offsetY + 190, 15);
	romanV(offsetX + 195, offsetY + 190, 15);

	// XLVI
	romanX(offsetX + 215, offsetY + 190, 15);
	romanL(offsetX + 225, offsetY + 190, 15);
	romanV(offsetX + 235, offsetY + 190, 15);
	romanI(offsetX + 245, offsetY + 190, 15);

	// XLVII
	romanX(offsetX + 260, offsetY + 190, 15);
	romanL(offsetX + 265, offsetY + 190, 15);
	romanV(offsetX + 270, offsetY + 190, 15);
	romanI(offsetX + 280, offsetY + 190, 15);
	romanI(offsetX + 285, offsetY + 190, 15);

	// XLVIII
	romanX(offsetX + 300, offsetY + 190, 15);
	romanL(offsetX + 305, offsetY + 190, 15);
	romanV(offsetX + 310, offsetY + 190, 15);
	romanI(offsetX + 320, offsetY + 190, 15);
	romanI(offsetX + 325, offsetY + 190, 15);
	romanI(offsetX + 330, offsetY + 190, 15);

	// XLIX
	romanX(offsetX + 340, offsetY + 190, 15);
	romanL(offsetX + 345, offsetY + 190, 15);
	romanI(offsetX + 355, offsetY + 190, 15);
	romanX(offsetX + 360, offsetY + 190, 15);

	// L
	romanL(offsetX + 400, offsetY + 190, 15);

	// LI
	romanL(offsetX + 10, offsetY + 235, 15);
	romanI(offsetX + 20, offsetY + 235, 15);

	// LII
	romanL(offsetX + 50, offsetY + 235, 15);
	romanI(offsetX + 60, offsetY + 235, 15);
	romanI(offsetX + 65, offsetY + 235, 15);

	// LIII
	romanL(offsetX + 90, offsetY + 235, 15);
	romanI(offsetX + 100, offsetY + 235, 15);
	romanI(offsetX + 105, offsetY + 235, 15);
	romanI(offsetX + 110, offsetY + 235, 15);

	// LIV
	romanL(offsetX + 130, offsetY + 235, 15);
	romanI(offsetX + 140, offsetY + 235, 15);
	romanV(offsetX + 145, offsetY + 235, 15);

	// LV
	romanL(offsetX + 175, offsetY + 235, 15);
	romanV(offsetX + 185, offsetY + 235, 15);

	// LVI
	romanL(offsetX + 215, offsetY + 235, 15);
	romanV(offsetX + 225, offsetY + 235, 15);
	romanI(offsetX + 235, offsetY + 235, 15);

	// LVII
	romanL(offsetX + 260, offsetY + 235, 15);
	romanV(offsetX + 270, offsetY + 235, 15);
	romanI(offsetX + 280, offsetY + 235, 15);
	romanI(offsetX + 285, offsetY + 235, 15);

	// LVIII
	romanL(offsetX + 300, offsetY + 235, 15);
	romanV(offsetX + 310, offsetY + 235, 15);
	romanI(offsetX + 320, offsetY + 235, 15);
	romanI(offsetX + 325, offsetY + 235, 15);
	romanI(offsetX + 330, offsetY + 235, 15);

	// LIX
	romanL(offsetX + 340, offsetY + 235, 15);
	romanI(offsetX + 350, offsetY + 235, 15);
	romanX(offsetX + 355, offsetY + 235, 15);
	
	// LX
	romanL(offsetX + 390, offsetY + 235, 15);
	romanX(offsetX + 400, offsetY + 235, 15);

	// LXI
	romanL(offsetX + 10, offsetY + 280, 15);
	romanX(offsetX + 20, offsetY + 280, 15);
	romanI(offsetX + 30, offsetY + 280, 15);

	// LXII
	romanL(offsetX + 50, offsetY + 280, 15);
	romanX(offsetX + 60, offsetY + 280, 15);
	romanI(offsetX + 70, offsetY + 280, 15);

	// LXIII
	romanL(offsetX + 90, offsetY + 280, 15);
	romanX(offsetX + 100, offsetY + 280, 15);
	romanI(offsetX + 110, offsetY + 280, 15);
	romanI(offsetX + 115, offsetY + 280, 15);
	romanI(offsetX + 120, offsetY + 280, 15);

	// LXIV
	romanL(offsetX + 130, offsetY + 280, 15);
	romanX(offsetX + 140, offsetY + 280, 15);
	romanI(offsetX + 150, offsetY + 280, 15);
	romanV(offsetX + 155, offsetY + 280, 15);

	// LXV
	romanL(offsetX + 175, offsetY + 280, 15);
	romanX(offsetX + 185, offsetY + 280, 15);
	romanV(offsetX + 195, offsetY + 280, 15);

	// LXVI
	romanL(offsetX + 215, offsetY + 280, 15);
	romanX(offsetX + 225, offsetY + 280, 15);
	romanV(offsetX + 235, offsetY + 280, 15);
	romanI(offsetX + 245, offsetY + 280, 15);

	// LXVII
	romanL(offsetX + 260, offsetY + 280, 15);
	romanX(offsetX + 270, offsetY + 280, 15);
	romanV(offsetX + 280, offsetY + 280, 15);
	romanI(offsetX + 290, offsetY + 280, 15);
	romanI(offsetX + 295, offsetY + 280, 15);

	// LXVIII
	romanL(offsetX + 300, offsetY + 280, 15);
	romanX(offsetX + 305, offsetY + 280, 15);
	romanV(offsetX + 310, offsetY + 280, 15);
	romanI(offsetX + 320, offsetY + 280, 15);
	romanI(offsetX + 325, offsetY + 280, 15);
	romanI(offsetX + 330, offsetY + 280, 15);

	// LXIX
	romanL(offsetX + 340, offsetY + 280, 15);
	romanX(offsetX + 350, offsetY + 280, 15);
	romanI(offsetX + 355, offsetY + 280, 15);
	romanX(offsetX + 360, offsetY + 280, 15);

	// LXX
	romanL(offsetX + 390, offsetY + 280, 15);
	romanX(offsetX + 400, offsetY + 280, 15);
	romanX(offsetX + 410, offsetY + 280, 15);





	






	// // rectangle at the bottom of the screen
	// setfillstyle(SOLID_FILL, BLACK);
	// bar(0, y - 100, x, y);

	// // add text 'Roman Numeral Numbers'
	// setcolor(WHITE);
	// settextstyle(10, HORIZ_DIR, 3);
	// outtextxy(10, y - 80, "Roman Numeral Numbers");
	// outtextxy(10, y - 60, "ACTIVITY# 3");
	// outtextxy(10, y - 40, "URQUICO & HILOTINA");

	getch();
    closegraph();

    return 0;
}