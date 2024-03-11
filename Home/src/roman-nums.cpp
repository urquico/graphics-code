#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <string>

using namespace std;

#define GRID_SIZE_X 10
#define GRID_SIZE_Y 10
#define NAME_SPACE 50

void romanI(int centerX, int centerY, int size) {
    line(centerX, centerY - size, centerX, centerY + size);
}

void romanV(int centerX, int centerY, int size) {
    line(centerX - size / 2, centerY - size, centerX, centerY + size);
    line(centerX + size / 2, centerY - size, centerX, centerY + size);
}

void romanX(int centerX, int centerY, int size) {
    line(centerX - size / 2, centerY + size, centerX + size / 2, centerY - size);
    line(centerX - size / 2, centerY - size, centerX + size / 2, centerY + size);
}

void romanL(int centerX, int centerY, int size) {
    line(centerX - size + 3, centerY + size, centerX - size + 3, centerY - size);
    line(centerX - size + 3, centerY + size, centerX + 3, centerY + size);
}

void romanC(int centerX, int centerY, int size) {
	// Draw the arc to form the shape of 'C'
	setcolor(WHITE);
	arc(centerX + size / 6, centerY + size / 6 - 2, 90, -90, size / 3);
}

void printRomanNumerals(int cNumber, int centerX, int centerY){
	int size = 5;
	int cSize = size + 13;

	int leftAlign = centerX - 20;

	switch (cNumber) {
		case 1:
			romanI(leftAlign, centerY, size);
			break;
		case 2:
			romanI(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			break;
		// III
		case 3:
			romanI(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// IV
		case 4:
			romanI(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			break;
		// V
		case 5:
			romanV(leftAlign, centerY, size);
			break;
		// VI
		case 6:
			romanV(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			break;
		// VII
		case 7:
			romanV(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// VIII
		case 8:
			romanV(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// IX
		case 9:
			romanI(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			break;
		// X
		case 10:
			romanX(leftAlign, centerY, size);
			break;
		// XI
		case 11:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			break;
		// XII
		case 12:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XIII
		case 13:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XIV
		case 14:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			break;
		// XV
		case 15:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			break;
		// XVI
		case 16:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XVII
		case 17:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XVIII
		case 18:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XIX
		case 19:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			break;
		// XX
		case 20:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			break;
		// XXI
		case 21:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XXII
		case 22:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XXIII
		case 23:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XXIV
		case 24:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// XXV
		case 25:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			break;
		// XXVI
		case 26:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XXVII
		case 27:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XXVIII
		case 28:
			romanX(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XXIX
		case 29:
			romanX(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			break;
		// XXX
		case 30:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			break;
		// XXXI
		case 31:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XXXII
		case 32:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XXXIII
		case 33:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// XXXIV
		case 34:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			break;
		// XXXV
		case 35:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// XXXVI
		case 36:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XXXVII
		case 37:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// XXXVIII
		case 38:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			romanI(leftAlign + 42, centerY, size);
			break;
		// XXXIX
		case 39:
			romanX(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanX(leftAlign + 28, centerY, size);
			break;
		// XL
		case 40:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			break;
		// XLI
		case 41:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XLII
		case 42:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XLIII
		case 43:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XLIV
		case 44:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// XLV
		case 45:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			break;
		// XLVI
		case 46:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XLVII
		case 47:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XLVIII
		case 48:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// XLIX
		case 49:
			romanX(leftAlign, centerY, size);
			romanL(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			break;
		// L
		case 50:
			romanL(leftAlign, centerY, size);
			break;
		// LI
		case 51:
			romanL(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			break;
		// LII
		case 52:
			romanL(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// LIII
		case 53:
			romanL(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// LIV
		case 54:
			romanL(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			break;
		// LV
		case 55:
			romanL(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			break;
		// LVI
		case 56:
			romanL(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// LVII
		case 57:
			romanL(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// LVIII
		case 58:
			romanL(leftAlign, centerY, size);
			romanV(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LIX
		case 59:
			romanL(leftAlign, centerY, size);
			romanI(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			break;
		// LX
		case 60:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			break;
		// LXI
		case 61:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			break;
		// LXII
		case 62:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// LXIII
		case 63:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LXIV
		case 64:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// LXV
		case 65:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			break;
		// LXVI
		case 66:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// LXVII
		case 67:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LXVIII
		case 68:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// LXIX
		case 69:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanI(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			break;
		// LXX
		case 70:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			break;
		// LXXI
		case 71:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// LXXII
		case 72:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LXXIII
		case 73:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// LXXIV
		case 74:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			break;
		// LXXV
		case 75:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// LXXVI
		case 76:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LXXVII
		case 77:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// LXXVIII
		case 78:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			romanI(leftAlign + 42, centerY, size);
			break;
		// LXXIX
		case 79:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanX(leftAlign + 28, centerY, size);
			break;
		// LXXX
		case 80:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			break;
		// LXXXI
		case 81:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// LXXXII
		case 82:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// LXXXIII
		case 83:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			romanI(leftAlign + 42, centerY, size);
			break;
		// LXXXIV
		case 84:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanV(leftAlign + 35, centerY, size);
			break;
		// LXXXV
		case 85:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			break;
		// LXXXVI
		case 86:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// LXXXVII
		case 87:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			romanI(leftAlign + 42, centerY, size);
			break;
		// LXXXVIII
		case 88:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanV(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			romanI(leftAlign + 42, centerY, size);
			romanI(leftAlign + 49, centerY, size);
			break;
		// LXXXIX
		case 89:
			romanL(leftAlign, centerY, size);
			romanX(leftAlign + 7, centerY, size);
			romanX(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanX(leftAlign + 35, centerY, size);
			break;
		// XC
		case 90:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			break;
		// XCI
		case 91:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanI(leftAlign + 14, centerY, size);
			break;
		// XCII
		case 92:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XCIII
		case 93:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanI(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XCIV
		case 94:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanI(leftAlign + 14, centerY, size);
			romanV(leftAlign + 21, centerY, size);
			break;
		// XCV
		case 95:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanV(leftAlign + 14, centerY, size);
			break;
		// XCVI
		case 96:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			break;
		// XCVII
		case 97:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			break;
		// XCVIII
		case 98:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanV(leftAlign + 14, centerY, size);
			romanI(leftAlign + 21, centerY, size);
			romanI(leftAlign + 28, centerY, size);
			romanI(leftAlign + 35, centerY, size);
			break;
		// XCIX
		case 99:
			romanX(leftAlign, centerY, size);
			romanC(leftAlign + 7, centerY, cSize);
			romanI(leftAlign + 14, centerY, size);
			romanX(leftAlign + 21, centerY, size);
			break;
		// C
		case 100:
			romanC(leftAlign, centerY, cSize);
			break;
	}
}

int main() {
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

	
	// Determine the width and height of each rectangle
    int rectWidth = x / 10;
    int rectHeight = y / 10 - 10;

    // Calculate the starting coordinates to center the grid
    int startX = (x - 10 * rectWidth) / 2;
    int startY = (y - 10 * rectHeight) / 2 - 50;

	int currentNumber = 1;

    // Draw the grid of rectangles
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int x1 = startX + j * rectWidth;
			int y1 = startY + i * rectHeight;
			int x2 = x1 + rectWidth;
			int y2 = y1 + rectHeight;
			rectangle(x1, y1, x2, y2);

			// Draw the Roman Numerals left to right, top to bottom
			printRomanNumerals(currentNumber, x1 + rectWidth / 2, y1 + rectHeight / 2);

			currentNumber++;
		}
	}


	// rectangle at the bottom of the screen
	setcolor(WHITE);
	rectangle(4, y - 100, x - 5, y - 5);
 
	getch();
    closegraph();

    return 0;
}