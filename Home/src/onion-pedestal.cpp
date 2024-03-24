#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <graphics.h>
#include <math.h>
#include <iostream>

bool SLANTED = true;
bool NOT_SLANTED = false;

bool MIRRORED = true;
bool NOT_MIRRORED = false;

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
    outtextxy(x / 2 - pedWidth + 30, textY, "~~~");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "~~");
    outtextxy(x / 2 - pedWidth + 23, textY += 10, "~~~");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "~");
    outtextxy(x / 2 - pedWidth + 30, textY += 10, "~~~");

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

    // while (true) {
    //     fireWorks(rand() % x, rand() % y);
    // }
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

void midFrontFacade(int x, int y, int pedHeight, int pedWidth) {
    // Straight facade in the middle of `midFacade` 
    int topX = x / 2;
    int topY = y - pedHeight - 170;
    int leftX = x / 2 - 100;
    int rightX = x / 2 + 100;
    int bottomY = y - 10;

    int leftBottomX = leftX;
    int leftBottomY = bottomY - 20;

    int topLeftX = topX - 100;
    int topLeftY = topY - 70;

    int topRightX = topX + 100;
    int topRightY = topY - 70;

    int rightBottomX = rightX;
    int rightBottomY = bottomY - 20;

    int points[] = {leftBottomX, leftBottomY, topLeftX, topLeftY, topRightX, topRightY, rightBottomX, rightBottomY};

    // Set the fill style and color for the main facade
    setfillstyle(SOLID_FILL, COLOR(212, 211, 209));
    setcolor(COLOR(151, 150, 146));

    // Draw the main facade
    fillpoly(4, points);

    // Rectangle on top of the main facade longer than the main facade
    int rectLeft = x / 2 - 105;
    int rectTop = y - pedHeight - 170 - 90;
    int rectRight = x / 2 + 105;
    int rectBottom = y - pedHeight - 170 - 80;

    // Draw bars on the rectangle
    for (int i = 0; i < 5; ++i) {
        setfillstyle(SOLID_FILL, i % 2 == 0 ? COLOR(91, 83, 80) : COLOR(212, 211, 209));
        setcolor(i % 2 == 0 ? COLOR(91, 83, 80) : COLOR(151, 150, 146));
        bar(rectLeft + i, rectBottom + i * 3, rectRight - i, rectBottom + i * 3 + 3);
    }
}

void midBackFacade(int x, int y, int pedHeight, int pedWidth) {
    int topX = x / 2;
    int topY = y - pedHeight - 120;
    int leftX = x / 2 - 100;
    int rightX = x / 2 + 100;
    int bottomY = y - 10;

    int leftBottomX = leftX - 70;
    int leftBottomY = bottomY - 20;

    int topLeftX = topX - 170;
    int topLeftY = topY - 70;

    int topXCoord = topX;
    int topYCoord = topY - 100;

    int topRightX = topX + 170;
    int topRightY = topY - 70;

    int rightBottomX = rightX + 70;
    int rightBottomY = bottomY - 20;

    int leftBottomXCoord = leftX;
    int leftBottomYCoord = bottomY;

    int points[] = {leftBottomX, leftBottomY, topLeftX, topLeftY, topXCoord, topYCoord, topRightX, topRightY, rightBottomX, rightBottomY, leftBottomXCoord, leftBottomYCoord};

    // Set the fill style and color for the main facade
    setfillstyle(SOLID_FILL, COLOR(208, 203, 199));
    setcolor(COLOR(167, 166, 165));

    // Draw the main facade
    fillpoly(5, points);

    int border[] = {5, 7, 8, 11};
    int colors[] = {COLOR(91, 83, 80),  COLOR(205, 204, 202), COLOR(91, 83, 80), COLOR(205, 204, 202)};
    int numPolygons = sizeof(border) / sizeof(border[0]);

    for (int i = 0; i < numPolygons; i++) {
        int points[] = {leftBottomX + border[i], leftBottomY - border[i], topLeftX + border[i], topLeftY + border[i], topXCoord, topYCoord + border[i], topRightX - border[i], topRightY + border[i], rightBottomX - border[i], rightBottomY - border[i], leftBottomXCoord + border[i], leftBottomYCoord - border[i]};

        setfillstyle(SOLID_FILL, colors[i]);
        setcolor(colors[i]);

        fillpoly(5, points);
    }
}

void ballisters(int x, int y, bool isSlanted){
    int bWidth = 3;

    if(isSlanted){
        int points[] = {x, y, x + 10, y - 10, x + 10, y - 20, x, y - 10, x, y};
        setfillstyle(SOLID_FILL, COLOR(56, 53, 42));
        setcolor(COLOR(56, 53, 42));
        fillpoly(5, points);

        int points2[] = {x, y, x - 10, y - 10, x - 10, y - 20, x, y - 10, x, y};
        setfillstyle(SOLID_FILL, COLOR(56, 53, 42));
        setcolor(COLOR(56, 53, 42));
        fillpoly(5, points2);

        return;
    }

    setfillstyle(SOLID_FILL, COLOR(56, 53, 42));
    setcolor(COLOR(56, 53, 42));
    bar(x - bWidth, y, x + bWidth, y + 7);

    setfillstyle(SOLID_FILL, COLOR(177, 172, 172));
    setcolor(COLOR(177, 172, 172));
    bar(x - bWidth + 1, y + 7, x + bWidth - 1, y + 26);

    setfillstyle(SOLID_FILL, COLOR(56, 53, 42));
    setcolor(COLOR(56, 53, 42));
    bar(x - bWidth, y + 26, x + bWidth, y + 33);
}

void terrace( int x, int y, int pedHeight, int pedWidth){
    int bottomLeftX = x / 2 - pedWidth - 80;
    int bottomRightX = x / 2 + pedWidth + 80;
    int bottomY = y - pedHeight + 40;

    int ballisterX = x / 2;

    // top terrace
    for(int i = 0; i < 11; i++){
        ballisters(ballisterX + 10 * i, bottomY - 33, NOT_SLANTED);
        ballisters(ballisterX - 10 * i, bottomY - 33, NOT_SLANTED);
    }

    // block bar at the top of the ballisters
    setfillstyle(SOLID_FILL, COLOR(100, 90, 88));
    setcolor(COLOR(100, 90, 88));
    bar(bottomLeftX, bottomY - 33, bottomRightX, bottomY - 30);

    // bar at the end left and right of the ballisters
    setfillstyle(SOLID_FILL, COLOR(233, 230, 225));
    setcolor(COLOR(233, 230, 225));

    bar(bottomLeftX + 5, bottomY - 30, bottomLeftX + 13, bottomY + 5);
    bar(bottomRightX - 5, bottomY - 30, bottomRightX - 13, bottomY + 5);

    // bottom terrace
    setfillstyle(SOLID_FILL, COLOR(228, 229, 223));
    setcolor(COLOR(228, 229, 223));

    bar(bottomLeftX, bottomY, bottomRightX, bottomY + 5);

    setfillstyle(SOLID_FILL, COLOR(91, 83, 80));
    setcolor(COLOR(91, 83, 80));

    bar(bottomLeftX + 5, bottomY + 5, bottomRightX - 5, bottomY + 7);

    setfillstyle(SOLID_FILL, COLOR(228, 229, 223));
    setcolor(COLOR(228, 229, 223));

    bar(bottomLeftX + 5, bottomY + 7, bottomRightX - 5, bottomY + 27);

    // bar inside the previous bar
    setfillstyle(SOLID_FILL, COLOR(212, 205, 202));
    setcolor(COLOR(212, 205, 202));

    bar(bottomLeftX + 8, bottomY + 10, bottomRightX - 8, bottomY + 24);

    setfillstyle(SOLID_FILL, COLOR(84, 74, 34));
    setcolor(COLOR(84, 74, 34));

    bar(bottomLeftX + 7, bottomY + 27, bottomRightX - 7, bottomY + 30);
}

void terracePillar(int x, int y, bool isMirrored){
    // shadow
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(BLACK);

    bar(x - 60, y - 120, x + 60, y - 30);

    // foot pillar
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);
    
    if(isMirrored) bar(x + 6, y - 33, x - 35, y - 30);
    else bar(x - 6, y - 33, x + 35, y - 30);

    // pillar
    setfillstyle(SOLID_FILL, COLOR(209, 206, 199));
    setcolor(BLACK);

    if(isMirrored) bar(x, y - 120, x - 30, y - 30);
    else bar(x, y - 120, x + 30, y - 30);

    // details
    setfillstyle(SOLID_FILL, WHITE);
    setcolor(WHITE);

    if(isMirrored) bar(x - 4, y - 117, x - 26, y - 60);
    else bar(x + 4, y - 117, x + 26, y - 60);

    if(isMirrored) bar(x + 6, y - 55, x - 34, y - 50);
    else bar(x - 6, y - 55, x + 34, y - 50);

    if(isMirrored) bar(x - 4, y - 47, x - 26, y - 33);
    else bar(x + 4, y - 47, x + 26, y - 33);
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

    int pedHeight = 190;
    int pedWidth = 40;
    
    // Main Facade
    midBackFacade(x, y, pedHeight, pedWidth);
    midFrontFacade(x, y, pedHeight, pedWidth);

    // Terrace
    terrace(x, y, pedHeight, pedWidth);
    terracePillar(x / 2 - 100, y, NOT_MIRRORED);
    terracePillar(x / 2 + 100, y, MIRRORED);

    cement(x, y, pedHeight, pedWidth);
    pedestal(x, y, pedHeight, pedWidth);
 
    getch();
    closegraph();

    return 0;
}