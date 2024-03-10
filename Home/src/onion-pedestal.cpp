#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <math.h>
#include <iostream>


// •	FLOODFILL
// •	SETLINESTYLE
// •	SETTEXTSTYLE
// •	ELLIPSE
// •	SETFILLSYTYLE
// •	BAR
// •	PUTPIXEL
// •	DELAY
// •	RANDOM

void flame(int x, int y, int size) {
    // add circles to the flame
    setfillstyle(XHATCH_FILL, COLOR(178, 148, 126));
    setcolor(BLACK);
    fillellipse(x, y, size, size / 2 + size / 3);

    // add triangle on the top of the onion
    int points[] = {x - size, y, x + size, y, x, y - size * 2 - size / 3};
    setfillstyle(XHATCH_FILL, COLOR(178, 148, 126));
    fillpoly(3, points);
}

void fireWorks(int x, int y) {
    int numParticles = 20; // Number of particles in the burst

    // Initialize random number generator
    srand(time(NULL));

    // Loop to create each particle in the burst
    for (int i = 0; i < numParticles; i++) {
        int randomX = rand() % 51 - 25; 
        int randomY = rand() % y; 

        // Generate random color for the particle
        int red = rand() % 256;
        int green = rand() % 256;
        int blue = rand() % 256;

        // Set color of the particle
        setcolor(COLOR(red, green, blue));

        // Draw the particle
        putpixel(x + randomX, randomY, getcolor());
    }
}

void pillar(int x, int y, int pedHeight, int pedWidth) {
    int space = 20;

    // Onion at the top of the bowl
    flame(x / 2, y - pedHeight - 120, 40);

    // Gold Pillar at the top of the pedestal
    int pillarTopY = y - pedHeight - 80;
    int pillarWidth = 10;
    int pillarLeftX = x / 2 - space - 5;
    int pillarRightX = x / 2 + space + 5;

    // Set the fill style and color for the gold pillar
    setfillstyle(SOLID_FILL, COLOR(124, 75, 8)); // Darker yellow
    setcolor(BLACK);

    // Draw the gold pillar
    bar(pillarLeftX, pillarTopY, pillarLeftX + pillarWidth, pillarTopY + 40);
    bar(pillarRightX - pillarWidth, pillarTopY, pillarRightX, pillarTopY + 40);

    // Bowl at the top of the pillar
    int bowlTopY = y - pedHeight - 90;

    // Set the fill style and color for the bowl
    setfillstyle(SOLID_FILL, COLOR(13, 13, 11));
    setcolor(COLOR(13, 13, 11));

    // Draw the bowl
    fillellipse(x / 2, bowlTopY, pedWidth, 20);
}

void pedestal(int x, int y, int pedHeight, int pedWidth) {
    int topPedWidth = 20;
    int bottomOffset = 45; // Offset to move the pedestal closer to the bottom

    // Draw the outer pedestal
    setfillstyle(WIDE_DOT_FILL, LIGHTGRAY); 
    bar(x / 2 - pedWidth, y - pedWidth + bottomOffset, x / 2 + pedWidth, y - pedHeight + bottomOffset); 

    // Draw the inner pedestal
    setfillstyle(INTERLEAVE_FILL, COLOR(165, 139, 123));
    bar(x / 2 - pedWidth + 10, y - pedWidth + bottomOffset, x / 2 + pedWidth - 10, y - pedHeight + bottomOffset);

    // Draw the plate inside the inner pedestal 
    setfillstyle(SOLID_FILL, COLOR(165, 139, 123));
    bar(x / 2 - pedWidth + 14, y - pedHeight + 40 + bottomOffset, x / 2 + pedWidth - 14, y - pedHeight + 110 + bottomOffset);

    // Draw the black poster inside the plate
    setfillstyle(SOLID_FILL, BLACK);
    bar(x / 2 - pedWidth + 20, y - pedHeight + 45 + bottomOffset, x / 2 + pedWidth - 20, y - pedHeight + 105 + bottomOffset);

    // Set text color to yellow
    setcolor(COLOR(255, 255, 0));
    settextstyle(0, HORIZ_DIR, 1);

    // Draw the text on the black poster
    int textY = y - pedHeight + 50 + bottomOffset;
    outtextxy(x / 2 - pedWidth + 30, textY, "Kurt");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "Jacob");
    outtextxy(x / 2 - pedWidth + 23, textY += 10, "Urquico");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "BSCS");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "4-1");

    // Draw the bottom of the black pedestal
    int bottomLeftX = x / 2 - pedWidth;
    int topLeftX = x / 2 - pedWidth - topPedWidth;
    int bottomRightX = x / 2 + pedWidth;
    int topRightX = x / 2 + pedWidth + topPedWidth;
    int bottomY = y - pedHeight + bottomOffset;
    int topY = y - pedHeight - 10 + bottomOffset;

    int bottomPoints[] = {bottomLeftX, bottomY, topLeftX, topY, topRightX, topY, bottomRightX, bottomY, bottomLeftX, bottomY};
    
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(DARKGRAY);
    fillpoly(4, bottomPoints);

    // Draw the top of the black pedestal
    setfillstyle(SOLID_FILL, COLOR(56, 57, 66)); 
    bar(x / 2 - pedWidth - topPedWidth, topY, x / 2 + pedWidth + topPedWidth, topY - 30);

    // Draw the onion
    pillar(x, y + bottomOffset, pedHeight, pedWidth);

    while (true) {
        fireWorks(rand() % x, rand() % y);
    }
}



void cement(int x, int y, int pedHeight, int pedWidth) {
    // Define the points of the bottom of the black pedestal
    int botLeftX = x / 2 - 100;
    int topLeftX = botLeftX - 30;
    int botRightX = x / 2 + 100;
    int topRightX = botRightX + 30;
    int bottomY = y - 10;

    // Define the points array
    int points[] = {botLeftX, bottomY, topLeftX, y, topRightX, y, botRightX, bottomY, botLeftX, bottomY};
    
    // Set the fill style and color for the cement
    setfillstyle(SOLID_FILL, COLOR(130, 132, 126));
    setcolor(COLOR(130, 132, 126));

    // Draw the cement shape
    fillpoly(4, points);
}


int main(){
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // to get the co-ordinates i.e. x & y
    y = getmaxy();
    cleardevice();

    int pedHeight = 200;
    int pedWidth = 50;
    
    cement(x, y, pedHeight, pedWidth);
    pedestal(x, y, pedHeight, pedWidth);
 
    getch();
    closegraph();

    return 0;
}