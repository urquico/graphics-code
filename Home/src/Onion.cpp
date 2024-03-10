#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

// •	FLOODFILL
// •	SETLINESTYLE
// •	SETTEXTSTYLE
// •	ELLIPSE
// •	SETFILLSYTYLE
// •	BAR
// •	PUTPIXEL
// •	DELAY
// •	RANDOM

void pedestal(int x, int y, int pedHeight, int pedWidth){
     // Outer pedestal
    rectangle(x / 2 - pedWidth, y - pedHeight, x / 2 + pedWidth, y - pedWidth);

    // Inner lines of the pedestal
    line(x / 2 - pedWidth + 10, y - pedWidth, x / 2 - pedWidth + 10, y - pedHeight);
    line(x / 2 + pedWidth - 10, y - pedWidth, x / 2 + pedWidth - 10, y - pedHeight);

    // bottom of the black pedestal
    int botLeft[] = {x / 2 - pedWidth, y - pedHeight};
    int topLeft[] = {x / 2 - pedWidth - 40, y - pedHeight - 10};
    int botRight[] = {x / 2 + pedWidth, y - pedHeight};
    int topRight[] = {x / 2 + pedWidth + 40, y - pedHeight - 10};

    int points[] = {botLeft[0], botLeft[1], topLeft[0], topLeft[1], topRight[0], topRight[1], botRight[0], botRight[1], botLeft[0], botLeft[1]};
    
    drawpoly(4, points); 

    // top of the black pedestal
    rectangle(x / 2 - pedWidth - 40, y - pedHeight - 10, x / 2 + pedWidth + 40, y - pedHeight - 40);

}

int main(){
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    // setbkcolor(BLUE);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();
    
    pedestal(x, y, 200, 50);
 
    getch();
    closegraph();

    return 0;
}