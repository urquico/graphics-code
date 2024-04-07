#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

struct RGB {
    int red;
    int green;
    int blue;
};

#define OUTER 3
#define NORMAL 2
#define INNER 1

int GARFIELD_SKIN[] = {251, 177, 49};
int GARFIELD_WHITE[] = {254, 254, 254};
int GARFIELD_BLACK[] = {37, 33, 34};
int GARFIELD_NOSE[] = {238, 211, 206};
int GARFIELD_MUSTACHE[] = {255, 248, 152};

void customPoly(int* points, int pointsLength, int fillColor[], int thickness){
    setfillstyle(SOLID_FILL, COLOR(fillColor[0], fillColor[1], fillColor[2]));
    setcolor(COLOR(GARFIELD_BLACK[0], GARFIELD_BLACK[1], GARFIELD_BLACK[2]));
    setlinestyle(SOLID_LINE, 1, thickness);
    fillpoly(pointsLength / 2, points);
}

void garfieldHead(){
    // head shape 
    int headPoints[] = {430, 195, 418, 195, 409, 192, 400, 189, 393, 180, 389, 173, 387, 165, 386, 157, 387, 147, 390, 140, 392, 133, 395, 126, 401, 119, 405, 110, 412, 104, 418, 101, 413, 91, 413, 83, 416, 75, 425, 72, 434, 73, 441, 74, 447, 78, 452, 85, 462, 78, 473, 74, 483, 73, 491, 75, 494, 80, 495, 87, 493, 95, 491, 100, 496, 103, 503, 110, 509, 116, 513, 123, 516, 132, 519, 139, 520, 146, 520, 154, 520, 162, 518, 167, 517, 174, 513, 179, 509, 185, 503, 189, 496, 194, 486, 196, 477, 197};
    customPoly(headPoints, sizeof(headPoints) / sizeof(headPoints[0]), GARFIELD_SKIN, OUTER);

    int mustache[] = {453,164,412,142,406,140,401,143,396,147,394,152,395,157,399,161,404,161,407,155,407,165,407,170,409,174,413,178,416,181,420,183,425,185,431,185,437,185,442,184,447,181,453,179,459,181,463,183,469,185,475,185,482,185,487,182,493,179,496,174,499,165,499,157,504,161,509,157,513,151,510,143,502,140,490,141};
    customPoly(mustache, sizeof(mustache) / sizeof(mustache[0]), GARFIELD_MUSTACHE, NORMAL);

    int leftEye[] = {453,165,447,166,442,170,434,170,427,167,419,161,413,153,412,144,412,135,412,125,415,118,419,111,422,105,426,99,431,96,437,94,443,94,448,96,452,100,455,105};
    customPoly(leftEye, sizeof(leftEye) / sizeof(leftEye[0]), GARFIELD_WHITE, NORMAL);
    
    int rightEye[] = {455,102,453,162,459,165,463,169,468,169,473,169,479,167,484,165,488,161,491,156,493,151,495,145,495,138,495,130,493,122,491,114,487,108,483,101,478,97,470,95,461,95};
    customPoly(rightEye, sizeof(rightEye) / sizeof(rightEye[0]), GARFIELD_WHITE, NORMAL);

    int leftPupil[] = {448,153,448,161};
    customPoly(leftPupil, sizeof(leftPupil) / sizeof(leftPupil[0]), GARFIELD_BLACK, OUTER);

    int rightPupil[] = {461,153,461,161};
    customPoly(rightPupil, sizeof(rightPupil) / sizeof(rightPupil[0]), GARFIELD_BLACK, OUTER);

    int nose[] = {453,164,447,166,443,170,444,175,448,178,454,178,460,176,463,170};
    customPoly(nose, sizeof(nose) / sizeof(nose[0]), GARFIELD_NOSE, NORMAL);
}

void garfieldBody(){
    int bodyShape[] = {451,180,408,214,402,222,398,230,395,237,392,245,392,253,392,260,393,265,395,270,399,274,403,277,407,281,414,282,420,283,425,285,430,285,435,285,442,286,447,286,455,285,462,285,471,284,477,282,485,281,491,279,497,277,503,274,507,266,511,260,512,251,510,242,507,233,502,223,497,213};
    customPoly(bodyShape, sizeof(bodyShape) / sizeof(bodyShape[0]), GARFIELD_SKIN, OUTER);
}

int main()
{
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    int radius = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);
    x = getmaxx(); // 639
    y = getmaxy(); // 479

    setbkcolor(WHITE);
    cleardevice();
    
    garfieldBody();
    garfieldHead();
   
    getch();
    closegraph();

    return 0;
}
