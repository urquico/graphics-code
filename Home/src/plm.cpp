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

int warp = 15;

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

    int windowPoint[] = {
        x / 2 - 70, y / 2 + 100, 
        x / 2 - 70, y / 2 - 100,
        x / 2 + 70, y / 2 - 100,
        x / 2 + 70, y / 2 + 100
    };

    setfillstyle(SOLID_FILL, COLOR(244, 246, 239));
    setcolor(COLOR(244, 246, 239));

    fillpoly(4, windowPoint);

    int border[] = {5, 7, 8, 11};
    int colors[] = {COLOR(247, 247, 242),  COLOR(84, 80, 69), COLOR(210, 211, 207), COLOR(239, 241, 236)};
    int numPolygons = sizeof(border) / sizeof(border[0]);

    for (int i = 0; i < numPolygons; i++) {
        int windowTop[] = {
            x / 2 - 80 + border[i], y / 2 - 60 - border[i], 
            x / 2 - 80 + border[i], y / 2 - 100 + border[i],
            x / 2 + 80 - border[i], y / 2 - 100 + border[i],
            x / 2 + 80 - border[i], y / 2 - 60 - border[i]
        };

        setfillstyle(SOLID_FILL, colors[i]);
        setcolor(colors[i]);

        fillpoly(4, windowTop);
    }

    // white bar at the edge of the windoTop
    int windowTopBarLeft[] = {
        x / 2 - 10 - 80, y / 2 - 70, 
        x / 2 - 10 - 80, y / 2 - 90,
        x / 2 + 10 - 80, y / 2 - 90,
        x / 2 + 10 - 80, y / 2 - 70
    };

    int windowTopBarRight[] = {
        x / 2 - 10 + 80, y / 2 - 70, 
        x / 2 - 10 + 80, y / 2 - 90,
        x / 2 + 10 + 80, y / 2 - 90,
        x / 2 + 10 + 80, y / 2 - 70
    };

    setfillstyle(SOLID_FILL, COLOR(212, 211, 209));
    setcolor(COLOR(212, 211, 209));

    fillpoly(4, windowTopBarLeft);
    fillpoly(4, windowTopBarRight);

    // Draw the window (3 bars vertically) centered and spaced evenly
    int windowLeft = x / 2 - 15;
    int windowRight = x / 2 + 15;
    int windowTop = y / 2 - 65;
    int windowBottom = y / 2 + 100;
    int windowSpace = 45;

    int windowPointsMid[] = {windowLeft, windowTop, windowLeft, windowBottom, windowRight, windowBottom, windowRight, windowTop};

    int windowPointsLeft[] = {windowLeft - windowSpace, windowTop, windowLeft - windowSpace, windowBottom, windowRight - windowSpace, windowBottom, windowRight - windowSpace, windowTop};

    int windowPointsRight[] = {windowLeft + windowSpace, windowTop, windowLeft + windowSpace, windowBottom, windowRight + windowSpace, windowBottom, windowRight + windowSpace, windowTop};

    setfillstyle(HATCH_FILL, COLOR(56, 50, 60));
    setcolor(COLOR(56, 50, 60));

    fillpoly(4, windowPointsMid);
    fillpoly(4, windowPointsLeft);
    fillpoly(4, windowPointsRight);


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

    // windows
    int windowTop = y / 2 - 70;
    int windowBottom = y / 2;
    int windowLeft = x / 10+ 120;
    int windowRight = x / 10 + 150;

    for(int k = 0; k < 2; k++){
        int offsetK = k * 110;

        for(int i = 0; i < 2; i++){
            int offsetY = i * 2;
            int windowPoints[] = {
                windowLeft + 243 * i, windowBottom + offsetK, 
                windowLeft + 243 * i, windowTop + offsetK,
                windowRight + 243 * i, windowTop + offsetK, 
                windowRight + 243 * i, windowBottom + offsetK
            };

            setfillstyle(HATCH_FILL, COLOR(52, 52, 52));
            setcolor(COLOR(52, 52, 52));

            fillpoly(4, windowPoints);

            int ballisterStartingX = windowLeft + 3;
            for(int j = 0; j <= 3; j++){
                ballisters(ballisterStartingX + 8 * j + (i * 243), windowBottom - 30 + offsetK, NOT_SLANTED);
            }
        } 

        // white long bar at the top edge of the ballisters
        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE); 

        for (int i = 0; i < 2; i++) {
            bar(
                windowLeft + 243 * i, windowTop + 40 - 2 / 2 + offsetK, 
                windowRight + 243 * i, windowTop + 40 + 2 / 2 + offsetK
            );
        }
    }
}

void slantedTerraceLeft(int x, int y){
    int leftTerrace = x / 2 - 165; 
    int rightTerrace = x / 2 - 115; 
    int startingBottom = y / 2 + 95;
    int startingTop = startingBottom - 5;

    int slope = 5;

    // ballisters inside the slanted terrace
    for(int i = 0; i <= 6; i++){
        ballisters(leftTerrace + 4 + (7 * i), startingTop - 25 - (i * 0.75), NOT_SLANTED);
    }

    int slantedTerracePoints[] = {
        leftTerrace, startingBottom + slope,
        leftTerrace, startingTop + slope,
        rightTerrace, startingTop,
        rightTerrace, startingBottom
    };

    setfillstyle(SOLID_FILL, COLOR(228, 229, 223));
    setcolor(COLOR(228, 229, 223));

    fillpoly(4, slantedTerracePoints);

    int slantedTerracePointsB[] = {
        leftTerrace, startingBottom - 35 + slope,
        leftTerrace, startingTop - 35 + slope + 2,
        rightTerrace, startingTop - 35 + 2,
        rightTerrace, startingBottom - 35
    };

    setfillstyle(SOLID_FILL, COLOR(100, 90, 88));
    setcolor(COLOR(100, 90, 88));

    fillpoly(4, slantedTerracePointsB);

    int slantedTerracePointsC[] = {
        leftTerrace, startingBottom + slope + 5 + 15,
        leftTerrace, startingTop + slope + 5,
        rightTerrace, startingTop + 5,
        rightTerrace, startingBottom + 5 + 15
    };

    setfillstyle(SOLID_FILL, COLOR(213, 214, 209));
    setcolor(COLOR(213, 214, 209));

    fillpoly(4, slantedTerracePointsC);

    int slantedTerracePointsD[] = {
        leftTerrace, startingBottom + slope + 5 + 18,
        leftTerrace, startingTop + slope + 5 + 18,
        rightTerrace, startingTop + 5 + 19,
        rightTerrace, startingBottom + 5 + 19
    };

    setfillstyle(SOLID_FILL, COLOR(84, 74, 34));
    setcolor(COLOR(84, 74, 34));

    fillpoly(4, slantedTerracePointsD);

    
}

void slantedTerraceRight(int x, int y){
    // flipped slantedTerraceLeft
    int leftTerrace = x - 210;
    int rightTerrace = x - 155;
    int startingBottom = y / 2 + 95;
    int startingTop = startingBottom - 5;

    int slope = 5;

    // ballisters inside the slanted terrace
    for(int i = 0; i <= 6; i++){
        // ballisters(leftTerrace + 4 + (7 * i), startingTop - 25 - (i * 0.75), NOT_SLANTED);
        ballisters(leftTerrace + (7 * i), startingTop - 30 + (i * 0.75), NOT_SLANTED);
    }

    int slantedTerracePoints[] = {
        leftTerrace, startingBottom,
        leftTerrace, startingTop,
        rightTerrace, startingTop + slope,
        rightTerrace, startingBottom + slope
    };

    setfillstyle(SOLID_FILL, COLOR(228, 229, 223));
    setcolor(COLOR(228, 229, 223));

    fillpoly(4, slantedTerracePoints);

    int slantedTerracePointsB[] = {
        leftTerrace, startingBottom - 35,
        leftTerrace, startingTop - 35 + 2,
        rightTerrace, startingTop - 35 + 2 + slope,
        rightTerrace, startingBottom - 35 + slope
    };

    setfillstyle(SOLID_FILL, COLOR(100, 90, 88));
    setcolor(COLOR(100, 90, 88));

    fillpoly(4, slantedTerracePointsB);

    int slantedTerracePointsC[] = {
        leftTerrace, startingBottom + 5 + 15,
        leftTerrace, startingTop + 5,
        rightTerrace, startingTop + 5 + slope,
        rightTerrace, startingBottom + 5 + 15 + slope
    };

    setfillstyle(SOLID_FILL, COLOR(213, 214, 209));
    setcolor(COLOR(213, 214, 209));

    fillpoly(4, slantedTerracePointsC);

    int slantedTerracePointsD[] = {
        leftTerrace, startingBottom + 5 + 18,
        leftTerrace, startingTop + 5 + 18,
        rightTerrace, startingTop + 5 + 19,
        rightTerrace, startingBottom + 5 + 19
    };

    setfillstyle(SOLID_FILL, COLOR(84, 74, 34));
    setcolor(COLOR(84, 74, 34));

    fillpoly(4, slantedTerracePointsD);
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
    // Shadow
    setfillstyle(HATCH_FILL, COLOR(31, 21, 12));
    setcolor(COLOR(31, 21, 12));
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

void leftFacade(int x, int y){
    // 4 point polygon for the left facade
    int left = 0;
    int top = 110;
    int right = x / 3 - 40;
    int bottom = y - 30;

    int points[] = {
        left, bottom + warp, 
        left, top - warp, 
        right, top, 
        right, bottom
    };

    setfillstyle(SOLID_FILL, COLOR(212, 211, 209));
    setcolor(COLOR(151, 150, 146));

    fillpoly(4, points);

    // add facade border
    int border[] = {5, 7, 8, 11};
    int colors[] = {COLOR(91, 83, 80),  COLOR(205, 204, 202), COLOR(91, 83, 80), COLOR(205, 204, 202)};
    int numPolygons = sizeof(border) / sizeof(border[0]);

    for (int i = 0; i < numPolygons; i++) {
        int points[] = {
            left + border[i], bottom + warp - border[i], 
            left + border[i], top - warp + border[i], 
            right - border[i], top + border[i], 
            right - border[i], bottom - border[i]
        };

        setfillstyle(SOLID_FILL, colors[i]);
        setcolor(colors[i]);

        fillpoly(4, points);
    }

    // windows
    int windowTop = y / 2 - 70;
    int windowBottom = y / 2;
    int windowLeft = x / 10 - 45;
    int windowRight = x / 10 - 15;

    for(int k = 0; k < 2; k++){
        int offsetK = k * 90;

        for(int i = 0; i < 4; i++){
            int offsetY = i * 2;
            int windowPoints[] = {
                windowLeft + 35 * i, windowBottom + offsetK, 
                windowLeft + 35 * i, windowTop + offsetK,
                windowRight + 35 * i, windowTop + offsetK, 
                windowRight + 35 * i, windowBottom + offsetK
            };

            setfillstyle(HATCH_FILL, COLOR(52, 52, 52));
            setcolor(COLOR(52, 52, 52));

            fillpoly(4, windowPoints);

            int ballisterStartingX = windowLeft + 3;
            for(int j = 0; j <= 3; j++){
                ballisters(ballisterStartingX + 8 * j + (i * 35), windowBottom - 30 + offsetK, NOT_SLANTED);
            }

            
        } 

        // white long bar at the top edge of the ballisters
        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE); 

        for (int i = 0; i < 4; i++) {
            bar(
                windowLeft + 35 * i, windowTop + 40 - 2 / 2 + offsetK, 
                windowRight + 35 * i, windowTop + 40 + 2 / 2 + offsetK
            );
        }
    }

    for(int k = 2; k < 3; k++){
        int offsetK = k * 90;

        for(int i = 0; i < 4; i++){
            int offsetY = i * 2;
            int windowPoints[] = {
                windowLeft + 35 * i, windowBottom + offsetK + 30, 
                windowLeft + 35 * i, windowTop + offsetK,
                windowRight + 35 * i, windowTop + offsetK, 
                windowRight + 35 * i, windowBottom + offsetK + 30
            };

            setfillstyle(HATCH_FILL, COLOR(52, 52, 52));
            setcolor(COLOR(52, 52, 52));

            fillpoly(4, windowPoints);
        } 
    }

    int pointsBB[] = {
        left, bottom, 
        left, bottom + warp + 15, 
        right + 5, bottom, 
        right + 5, bottom - warp - 15
    };

    setfillstyle(SOLID_FILL, COLOR(233, 232, 229));
    setcolor(COLOR(91, 83, 80));

    fillpoly(4, pointsBB);
}

void rightFacade(int x, int y){
    // 4 point polygon for the right facade (flipped)
    int left = x - (x / 3 - 40);
    int top = 110;
    int right = x;
    int bottom = y - 30;
    int warp = 15;

    int points[] = {
        left, bottom, 
        left, top, 
        right, top - warp, 
        right, bottom + warp
    };

    setfillstyle(SOLID_FILL, COLOR(212, 211, 209));
    setcolor(COLOR(151, 150, 146));

    fillpoly(4, points);

    // add facade border
    int border[] = {5, 7, 8, 11};
    int colors[] = {COLOR(91, 83, 80),  COLOR(205, 204, 202), COLOR(91, 83, 80), COLOR(205, 204, 202)};
    int numPolygons = sizeof(border) / sizeof(border[0]);

    for (int i = 0; i < numPolygons; i++) {
        int points[] = {
            left + border[i], bottom - border[i], 
            left + border[i], top + border[i], 
            right - border[i], top - warp + border[i], 
            right - border[i], bottom + warp + border[i]};

        setfillstyle(SOLID_FILL, colors[i]);
        setcolor(colors[i]);

        fillpoly(4, points);
    }

    // windows (flipped coordinates)
    int windowTop = y / 2 - 70;
    int windowBottom = y / 2;
    int windowLeft = x / 10 - 45 + 467;
    int windowRight = x / 10 - 15 + 467;

    for(int k = 0; k < 2; k++){
        int offsetK = k * 90;

        for(int i = 0; i < 4; i++){
            int offsetY = i * 2;
            int windowPoints[] = {
                windowLeft + 35 * i, windowBottom + offsetK, 
                windowLeft + 35 * i, windowTop + offsetK,
                windowRight + 35 * i, windowTop + offsetK, 
                windowRight + 35 * i, windowBottom + offsetK
            };

            setfillstyle(HATCH_FILL, COLOR(52, 52, 52));
            setcolor(COLOR(52, 52, 52));

            fillpoly(4, windowPoints);

            int ballisterStartingX = windowLeft + 3;
            for(int j = 0; j <= 3; j++){
                ballisters(ballisterStartingX + 8 * j + (i * 35), windowBottom - 30 + offsetK, NOT_SLANTED);
            }

            
        } 

        // white long bar at the top edge of the ballisters
        setfillstyle(SOLID_FILL, WHITE);
        setcolor(WHITE); 

        for (int i = 0; i < 4; i++) {
            bar(
                windowLeft + 35 * i, windowTop + 40 - 2 / 2 + offsetK, 
                windowRight + 35 * i, windowTop + 40 + 2 / 2 + offsetK
            );
        }
    }

    for(int k = 2; k < 3; k++){
        int offsetK = k * 90;

        for(int i = 0; i < 4; i++){
            int offsetY = i * 2;
            int windowPoints[] = {
                windowLeft + 35 * i, windowBottom + offsetK + 30, 
                windowLeft + 35 * i, windowTop + offsetK,
                windowRight + 35 * i, windowTop + offsetK, 
                windowRight + 35 * i, windowBottom + offsetK + 30
            };

            setfillstyle(HATCH_FILL, COLOR(52, 52, 52));
            setcolor(COLOR(52, 52, 52));

            fillpoly(4, windowPoints);
        } 
    }


    // border at the bottom of pointsB
    int pointsBB[] = {left - 5, bottom, left - 5, bottom - warp - 15, right, bottom, right, bottom + warp + 15};

    setfillstyle(SOLID_FILL, COLOR(233, 232, 229));
    setcolor(COLOR(91, 83, 80));

    fillpoly(4, pointsBB);
}

void grass(int x, int y){
    // Midpoint of the pathway 
    int midpoint = (x / 3 - 40 + 2 * x / 3 + 40) / 2;
    int top = y - 30;
    int bottom = y;

    // Grass in the middle of the pathways
    setfillstyle(WIDE_DOT_FILL, GREEN);
    bar(midpoint - 146, top, midpoint + 146, bottom);
}

void pathway(int x, int y){
    setfillstyle(SOLID_FILL, COLOR(130, 132, 126));
    
    // Pathway left facade
    bar(0, y - y / 4, x / 3 - 40, y);
    
    // Pathway right facade
    bar(2 * x / 3 + 40, y - y / 4, x, y);
}

void sky(int x, int y){
    for (int row = 0; row <= y; row++) {
        int red = 49 + (row * (255 - 75) / y);
        int green = 91 + (row * (255 - 143) / y);
        int blue = 191 + (row * (255 - 216) / y);
        setcolor(COLOR(red, green, blue));
        line(0, row, x, row);
    }
}

void banner(int x, int y){
    // Pamantasan ng Lungsod ng Maynila
    setcolor(COLOR(175, 50, 72)); 
    setfillstyle(SOLID_FILL, COLOR(0, 0, 0));
    setbkcolor(COLOR(212, 211, 209));
    settextstyle(0, HORIZ_DIR, 1);

    settextstyle(8, HORIZ_DIR, 1);
    int textWidth = textwidth("PAMANTASAN MANILA");
    int startX = (x - textWidth) / 2;
    outtextxy(startX, y / 2 - 180, "PAMANTASAN MANILA");

    settextstyle(0, HORIZ_DIR, 1);
    int textWidth2 = textwidth("UNIVERSITY MAYNILA");
    int startX2 = (x - textWidth2) / 2;
    outtextxy(startX2, y / 2 - 160, "UNIVERSITY MAYNILA");    

    setbkcolor(COLOR(0, 0, 0));   
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

    // set background to blue
    sky(x, y);

    // Pathway
    pathway(x, y);

    // Grass
    grass(x, y);
    
    // Main Facade
    midBackFacade(x, y, pedHeight, pedWidth);
    midFrontFacade(x, y, pedHeight, pedWidth);
    banner(x, y);

    // // Terrace
    terrace(x, y, pedHeight, pedWidth);  
    terracePillar(x / 2 - 100, y, NOT_MIRRORED);
    terracePillar(x / 2 + 100, y, MIRRORED);

    // Left Facade
    leftFacade(x, y);

    // Right Facade
    rightFacade(x, y);

    slantedTerraceLeft(x, y);
    slantedTerraceRight(x, y);

    cement(x, y, pedHeight, pedWidth);
    pedestal(x, y, pedHeight, pedWidth); 
 
    getch();
    // closegraph();

    return 0;
}