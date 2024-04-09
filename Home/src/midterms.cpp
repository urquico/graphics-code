#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

#define OUTER 3
#define NORMAL 2
#define INNER 1


class Killua{
public:
    int KILLUA_SKIN[3] = {227, 211, 209};
    int KILLUA_DARK_SKIN[3] = {176, 142, 136};
    int KILLUA_SHIRT[3] = {215, 205, 224};
    int KILLUA_SHIRT_SHADOW[3] = {113, 112, 190};
    int KILLUA_SLEEVES[3] = {11, 44, 162};
    int KILLUA_SLEEVES_DARK[3] = {16, 35, 81};
    int KILLUA_PANTS[3] = {22, 52, 126};
    int KILLUA_PANTS_SHADOW[3] = {22, 37, 62};
    int KILLUA_HAIR[3] = {225, 222, 225};
    int KILLUA_HAIR_SHADOW[3] = {175, 147, 197};
    int KILLUA_EYES[3] = {57, 122, 222};
    int KILLUA_EYES_WHITE[3] = {222, 222, 224};
    int KILLUA_BLACK[3] = {30, 34, 33};

    void customPoly(int* points, int pointsLength, int fillColor[], int thickness){
        setfillstyle(SOLID_FILL, COLOR(fillColor[0], fillColor[1], fillColor[2]));
        setcolor(COLOR(KILLUA_BLACK[0], KILLUA_BLACK[1], KILLUA_BLACK[2]));
        setlinestyle(SOLID_LINE, 1, thickness);
        fillpoly(pointsLength / 2, points);
    }

    void detailingPoly(int* points, int pointsLength, int fillColor[], int thickness){
        setfillstyle(SOLID_FILL, COLOR(fillColor[0], fillColor[1], fillColor[2]));
        setcolor(COLOR(fillColor[0], fillColor[1], fillColor[2]));
        setlinestyle(SOLID_LINE, 1, thickness);
        fillpoly(pointsLength / 2, points);
    }

    void neckSleeves(){
        int neck[] = {129,197,123,195,121,200,114,210,114,232,124,248,133,259,146,234,151,234,162,236,166,227,157,207};
        int neckShadow[] = {133,210,136,215,140,220,146,223,155,226,153,232,146,232,138,250,130,244,127,228};

        customPoly(neck, sizeof(neck) / sizeof(neck[0]), KILLUA_SLEEVES, NORMAL);
        customPoly(neckShadow, sizeof(neckShadow) / sizeof(neckShadow[0]), KILLUA_SLEEVES_DARK, NORMAL);        
    }

    void leftSleeves(){
        int leftArm[] = {82,276,80,292,76,300,74,309,75,317,71,321,67,330,66,337,65,347,63,362,60,377,59,386,62,391,66,395,72,401,77,405,82,405,87,406,95,406,101,405,98,395,97,383,96,372,98,362,98,348,96,335,102,331,100,321,113,283};
        int leftShadow[] = {80,275,79,292,85,293,90,296,96,300,105,305,112,291};

        customPoly(leftArm, sizeof(leftArm) / sizeof(leftArm[0]), KILLUA_SLEEVES, NORMAL);
        customPoly(leftShadow, sizeof(leftShadow) / sizeof(leftShadow[0]), KILLUA_SLEEVES_DARK, NORMAL);
    }

    void rightSleeves(){
        int detail[] = {128,296,113,307,110,322,110,341,119,341,128,323};
        int rightArm[] = {129,286,125,299,125,312,121,324,116,333,113,350,113,371,114,386,120,391,125,392,131,398,137,402,137,382,140,364,140,353,137,337,138,326,144,326,154,290,162,265};
        int rightShadow[] = {125,302,132,304,138,306,146,307,151,304,160,291,124,282};

        
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), KILLUA_BLACK, NORMAL);
        customPoly(rightArm, sizeof(rightArm) / sizeof(rightArm[0]), KILLUA_SLEEVES, NORMAL);
        customPoly(rightShadow, sizeof(rightShadow) / sizeof(rightShadow[0]), KILLUA_SLEEVES_DARK, NORMAL);
    }

    void leftShirt(){
        int lineShirt[] = {94,387,110,398};
        int lineShirt2[] = {110,399,115,392};
        int leftShirt[] = {123,274,125,266,133,238,134,228,132,220,127,213,120,208,113,207,104,205,94,209,87,214,78,224,68,239,63,250,54,267,49,280,44,295,40,308,33,323,27,339,25,349,23,363,22,379,20,397,21,407,27,407,31,402,40,395,49,390,58,385,62,368,65,348,65,334,74,316,77,302,78,292,80,283,86,285,93,289,99,292,107,295,115,295,121,295};
        int detail[] = {78,236,80,243,83,252};
        int detail2[] = {78,284,79,264,83,252};
        int detail3[] = {117,271,121,263,126,257};
        int detail4[] = {61,370,55,372,46,378,61,376};

        customPoly(lineShirt, sizeof(lineShirt) / sizeof(lineShirt[0]), KILLUA_BLACK, NORMAL);
        customPoly(lineShirt2, sizeof(lineShirt2) / sizeof(lineShirt2[0]), KILLUA_BLACK, NORMAL);
        leftSleeves();
        customPoly(leftShirt, sizeof(leftShirt) / sizeof(leftShirt[0]), KILLUA_SHIRT, NORMAL);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), KILLUA_BLACK, NORMAL);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), KILLUA_BLACK, NORMAL);
        customPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), KILLUA_BLACK, NORMAL);
        customPoly(detail4, sizeof(detail4) / sizeof(detail4[0]), KILLUA_SHIRT_SHADOW, INNER); 
    }

    void rightShirt(){
        int rightShirt[] = {125,249,101,305,94,401,103,404,113,410,121,396,119,387,115,381,115,372,119,368,115,362,115,326,117,318,125,303,128,295,135,297,144,297,155,298,162,298,162,279,164,273,169,264,174,246,162,234,154,228,152,235,145,233,133,259};
        int detail[] = {128,296,132,287,134,278,137,271,141,265,146,258};
        int detail2[] = {161,276,165,262,166,275};

        rightSleeves();

        customPoly(rightShirt, sizeof(rightShirt) / sizeof(rightShirt[0]), KILLUA_SHIRT, NORMAL);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), KILLUA_BLACK, NORMAL);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), KILLUA_SHIRT_SHADOW, INNER); 
    }

    void shirt(){
        rightShirt();
        neckSleeves();
        leftShirt();   
    }

    void shorts(){
        int shorts[] = {21,398,27,425,26,432,26,441,28,462,28,476,151,478,159,474,155,463,151,452,146,442,140,434,136,423,129,413,129,402,127,394,121,391,105,379,74,366};
        int detail[] = {85,437,85,429,89,421,91,410,91,392};
        int detail2[] = {108,424,98,439,99,477,115,477,112,464,108,451,104,440};

        customPoly(shorts, sizeof(shorts) / sizeof(shorts[0]), KILLUA_PANTS, NORMAL);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), KILLUA_BLACK, NORMAL);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), KILLUA_BLACK, NORMAL);
    }

    void behindHair(){
        int hair[] = {134,200,128,193,117,197,120,192,111,191,122,184,120,173,114,183,113,172,120,164,106,172,110,162,115,158,122,156,113,152,106,150,113,143,121,146,129,150,130,139,123,134,115,132,129,130,139,139,126,121,123,112,136,129,144,136,232,145,235,167,252,166,259,169,250,174,227,173,227,183,235,190,239,198,222,188,217,206,211,216,215,197,210,209,200,216,209,198,205,180,200,187,191,199,193,188,199,170,184,196,190,173,182,176,175,180,170,186,183,163,167,175,160,178,155,181,152,187,175,154,146,191,154,164,141,183,146,165,140,168};

        customPoly(hair, sizeof(hair) / sizeof(hair[0]), KILLUA_HAIR_SHADOW, NORMAL);
    }

    void frontHair(){
        int hair[] = {
            129,154,119,150,106,150,120,143,131,143,126,137,113,134,121,132,136,138,136,131,126,121,123,113,130,113,137,117,147,117,157,122,152,113,147,102,163,118,164,108,159,100,171,105,178,110,180,116,185,102,187,120,189,109,195,102,198,112,205,116,211,121,216,127,214,112,219,116,223,121,226,127,226,135,228,141,234,129,238,125,239,133,239,141,239,147,236,154,232,158,242,156,250,158,237,162,243,164,250,169,258,175,235,171,240,179,244,186,244,193,236,183,236,191,237,204,229,190,234,205,230,210,227,196,224,178,223,202,215,214,217,203,217,193,210,200,210,185,202,198,201,186,197,192,187,206,186,193,190,184,198,178,202,174,191,177,182,184,178,192,176,184,183,174,193,168,178,178,168,186,170,180,173,172,181,166,165,174,160,179,153,184,158,172,165,167,171,164,152,177,147,184,145,193,138,195,139,184,143,173,134,176,138,168,144,163,152,158,136,160,130,163,124,164
        };

        customPoly(hair, sizeof(hair) / sizeof(hair[0]), KILLUA_HAIR, NORMAL);
    }

    void head(){
        int neck[] = {145,223,139,218,134,212,131,204,129,198,135,196};
        int head[] = {134,195,128,191,126,185,124,179,126,172,131,169,137,169,161,151,199,153,206,170,206,197,203,203,200,208,194,214,193,220,190,225,186,229,180,230,174,232,168,234,158,236,153,231,147,225,142,219,138,211,135,202};
        int earlobe[] = {138,188,132,188,130,181,130,174,136,172,139,179};
        int mouth[] = {162,217,166,222,176,227};
        int nose1[] = {179,222,185,219};
        int nose2[] = {182,217,185,219,182,217};
        int eyeLeft[] = {175,200,170,204,164,204,157,202,155,194,151,186,158,183,167,183,175,187,178,193};
        int eyeRight[] = {188,217,186,210,191,204,197,202,200,207,197,212};
        int eyeballLeft[] = {161,184,156,188,156,195,159,200,165,199,169,193,168,185};
        int pupilLeft[] = {164,184,161,189,161,195,167,192};
        int eyeballRight[] = {187,215,192,211,194,205,187,207};
        int pupilRight[] = {187,209,193,210,193,204};

        behindHair();
        customPoly(neck, sizeof(neck) / sizeof(neck[0]), KILLUA_DARK_SKIN, NORMAL);
        customPoly(head, sizeof(head) / sizeof(head[0]), KILLUA_SKIN, NORMAL);
        customPoly(earlobe, sizeof(earlobe) / sizeof(earlobe[0]), KILLUA_DARK_SKIN, INNER);
        customPoly(mouth, sizeof(mouth) / sizeof(mouth[0]), KILLUA_BLACK, INNER);
        customPoly(nose1, sizeof(nose1) / sizeof(nose1[0]), KILLUA_BLACK, NORMAL);
        customPoly(nose2, sizeof(nose2) / sizeof(nose2[0]), KILLUA_BLACK, NORMAL);
        customPoly(eyeLeft, sizeof(eyeLeft) / sizeof(eyeLeft[0]), KILLUA_EYES_WHITE, INNER);
        customPoly(eyeRight, sizeof(eyeRight) / sizeof(eyeRight[0]), KILLUA_EYES_WHITE, INNER);
        customPoly(eyeballLeft, sizeof(eyeballLeft) / sizeof(eyeballLeft[0]), KILLUA_EYES, NORMAL);
        customPoly(pupilLeft, sizeof(pupilLeft) / sizeof(pupilLeft[0]), KILLUA_BLACK, NORMAL);
        customPoly(eyeballRight, sizeof(eyeballRight) / sizeof(eyeballRight[0]), KILLUA_EYES, NORMAL);
        customPoly(pupilRight, sizeof(pupilRight) / sizeof(pupilRight[0]), KILLUA_BLACK, NORMAL);
        frontHair();
    }

    void drawKillua(){
        shorts();
        shirt();
        head();
    }
};

class Garfield {
public:
    int GARFIELD_SKIN[3] = {251, 177, 49};
    int GARFIELD_WHITE[3] = {254, 254, 254};
    int GARFIELD_BLACK[3] = {37, 33, 34};
    int GARFIELD_NOSE[3] = {238, 211, 206};
    int GARFIELD_MUSTACHE[3] = {255, 248, 152};

    void customPoly(int* points, int pointsLength, int fillColor[], int thickness){
        setfillstyle(SOLID_FILL, COLOR(fillColor[0], fillColor[1], fillColor[2]));
        setcolor(COLOR(GARFIELD_BLACK[0], GARFIELD_BLACK[1], GARFIELD_BLACK[2]));
        setlinestyle(SOLID_LINE, 1, thickness);
        fillpoly(pointsLength / 2, points);
    }

    void detailingPoly(int* points, int pointsLength, int thickness){
        setfillstyle(SOLID_FILL, COLOR(GARFIELD_SKIN[0], GARFIELD_SKIN[1], GARFIELD_SKIN[2]));
        setcolor(COLOR(GARFIELD_SKIN[0], GARFIELD_SKIN[1], GARFIELD_SKIN[2]));
        setlinestyle(SOLID_LINE, 1, thickness);
        fillpoly(pointsLength / 2, points);
    }

    void head(){
        int hair[] = {409,106,402,103,394,103,387,104,382,109};
        int hair2[] = {414,106,408,102,402,98,394,96,386,96};
        int hair3[] = {413,102,410,96,404,91,398,88,391,88};
        int hair4[] = {490,106,494,102,498,97,504,93,511,89,517,89};
        int hair5[] = {490,112,497,104,502,100,507,98,514,97,522,96};
        int hair6[] = {492,111,498,107,504,103,513,103,521,103,526,103};
        int headPoints[] = {430, 195, 418, 195, 409, 192, 400, 189, 393, 180, 389, 173, 387, 165, 386, 157, 387, 147, 390, 140, 392, 133, 395, 126, 401, 119, 405, 110, 412, 104, 418, 101, 413, 91, 413, 83, 416, 75, 425, 72, 434, 73, 441, 74, 447, 78, 452, 85, 462, 78, 473, 74, 483, 73, 491, 75, 494, 80, 495, 87, 493, 95, 491, 100, 496, 103, 503, 110, 509, 116, 513, 123, 516, 132, 519, 139, 520, 146, 520, 154, 520, 162, 518, 167, 517, 174, 513, 179, 509, 185, 503, 189, 496, 194, 486, 196, 477, 197};
        int mustache[] = {453,164,412,142,406,140,401,143,396,147,394,152,395,157,399,161,404,161,407,155,407,165,407,170,409,174,413,178,416,181,420,183,425,185,431,185,437,185,442,184,447,181,453,179,459,181,463,183,469,185,475,185,482,185,487,182,493,179,496,174,499,165,499,157,504,161,509,157,513,151,510,143,502,140,490,141};
        int leftEye[] = {453,165,447,166,442,170,434,170,427,167,419,161,413,153,412,144,412,135,412,125,415,118,419,111,422,105,426,99,431,96,437,94,443,94,448,96,452,100,455,105};
        int rightEye[] = {455,102,453,162,459,165,463,169,468,169,473,169,479,167,484,165,488,161,491,156,493,151,495,145,495,138,495,130,493,122,491,114,487,108,483,101,478,97,470,95,461,95};
        int leftPupil[] = {448,153,448,161};
        int rightPupil[] = {461,153,461,161};
        int nose[] = {453,164,447,166,443,170,444,175,448,178,454,178,460,176,463,170};
        int detail[] = {492,192,497,188,502,185,507,182};
        int detail2[] = {513,176,515,170,515,164,516,158};
        int detail3[] = {515,141,513,134,508,127};
        int detail4[] = {503,116,496,110};
        int detail5[] = {413,190,407,189,399,184};
        int detail6[] = {394,176,392,169,390,156};
        int detail7[] = {392,140,395,133,400,125};
        int detail8[] = {404,116,408,111,413,106};
        int detail9[] = {453,99,448,92,443,87,438,83,434,78,425,75};
        int detail10[] = {438,88,433,82,428,78,420,74};
        int detail11[] = {432,90,427,84,420,76};
        int detail12[] = {425,92,422,86,417,79};
        int detail13[] = {422,99,418,92,415,84};
        int detail14[] = {415,85,422,82,426,77,413,85,414,77,419,74,424,73,426,77,415,85};
        int detail15[] = {474,79,480,79,486,79,490,83,494,88,494,79,488,73,482,72};
        int detail16[] = {468,89,481,76};
        int detail17[] = {454,99,458,91,465,88,471,82,480,74};
        int detail18[] = {476,92,481,83,486,77};
        int detail19[] = {480,93,485,89,490,80};
        int detail20[] = {486,98,488,92,492,87,494,80};

        customPoly(hair, sizeof(hair) / sizeof(hair[0]), GARFIELD_BLACK, INNER);
        customPoly(hair2, sizeof(hair2) / sizeof(hair2[0]), GARFIELD_BLACK, INNER);
        customPoly(hair3, sizeof(hair3) / sizeof(hair3[0]), GARFIELD_BLACK, INNER);
        customPoly(hair4, sizeof(hair4) / sizeof(hair4[0]), GARFIELD_BLACK, INNER);
        customPoly(hair5, sizeof(hair5) / sizeof(hair5[0]), GARFIELD_BLACK, INNER);
        customPoly(hair6, sizeof(hair6) / sizeof(hair6[0]), GARFIELD_BLACK, INNER);
        customPoly(headPoints, sizeof(headPoints) / sizeof(headPoints[0]), GARFIELD_SKIN, OUTER);
        customPoly(mustache, sizeof(mustache) / sizeof(mustache[0]), GARFIELD_MUSTACHE, NORMAL);
        customPoly(leftEye, sizeof(leftEye) / sizeof(leftEye[0]), GARFIELD_WHITE, NORMAL);
        customPoly(rightEye, sizeof(rightEye) / sizeof(rightEye[0]), GARFIELD_WHITE, NORMAL);
        customPoly(leftPupil, sizeof(leftPupil) / sizeof(leftPupil[0]), GARFIELD_BLACK, OUTER);
        customPoly(rightPupil, sizeof(rightPupil) / sizeof(rightPupil[0]), GARFIELD_BLACK, OUTER);
        customPoly(nose, sizeof(nose) / sizeof(nose[0]), GARFIELD_NOSE, NORMAL);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail4, sizeof(detail4) / sizeof(detail4[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail5, sizeof(detail5) / sizeof(detail5[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail6, sizeof(detail6) / sizeof(detail6[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail7, sizeof(detail7) / sizeof(detail7[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail8, sizeof(detail8) / sizeof(detail8[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail9, sizeof(detail9) / sizeof(detail9[0]), GARFIELD_BLACK, INNER);
        customPoly(detail10, sizeof(detail10) / sizeof(detail10[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail11, sizeof(detail11) / sizeof(detail11[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail12, sizeof(detail12) / sizeof(detail12[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail13, sizeof(detail13) / sizeof(detail13[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail14, sizeof(detail14) / sizeof(detail14[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail15, sizeof(detail15) / sizeof(detail15[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail16, sizeof(detail16) / sizeof(detail16[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail17, sizeof(detail17) / sizeof(detail17[0]), GARFIELD_BLACK, INNER);
        customPoly(detail18, sizeof(detail18) / sizeof(detail18[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail19, sizeof(detail19) / sizeof(detail19[0]), GARFIELD_BLACK, NORMAL);
        customPoly(detail20, sizeof(detail20) / sizeof(detail20[0]), GARFIELD_BLACK, NORMAL);
    }

    void leftArm(){
        int leftArm[] = {430,194,420,195,412,195,403,193,392,189,380,184,369,178,363,174,340,194,344,198,348,200,354,201,359,204,363,205,368,207,373,209,378,212,383,212,387,213,394,214,399,214,406,215};
        int hand[] ={358,177,363,172,365,166,363,157,368,154,373,150,375,142,370,137,362,135,356,140,352,145,352,152,350,137,346,127,342,120,336,115,330,117,325,121,325,127,326,134,329,139,334,143,331,149,325,144,320,139,312,137,305,139,302,144,301,151,303,157,308,160,317,161,323,161,322,169,315,169,307,168,301,170,300,175,300,180,303,184,307,187,312,187,324,184,325,190,330,195,335,195,342,193};
        int detail[] = {347,168,342,162,342,154};
        int detail2[] = {348,167,345,161,345,154};
        int detail3[] = {339,186,345,188,349,193,357,196,365,190,365,184,357,180,350,176,336,181};
        int detail4[] = {400,197,419,201,427,202,442,202,439,209,437,216,425,216,412,216,402,213,392,210};

        customPoly(leftArm, sizeof(leftArm) / sizeof(leftArm[0]), GARFIELD_SKIN, OUTER);
        customPoly(hand, sizeof(hand) / sizeof(hand[0]), GARFIELD_SKIN, OUTER);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        detailingPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), OUTER);
        detailingPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), OUTER);
        detailingPoly(detail4, sizeof(detail4) / sizeof(detail4[0]), OUTER);
    }

    void rightArm(){
        int rightArm[] = {503,189,507,192,512,193,516,196,521,198,525,201,529,205,531,209,532,213,532,218,529,222,526,226,521,231,515,234,509,236,503,224,498,217,490,211,483,205,475,203,471,195,480,196,486,197,492,196,497,193};

        customPoly(rightArm, sizeof(rightArm) / sizeof(rightArm[0]), GARFIELD_SKIN, OUTER);
    }

    void body(){
        int bodyShape[] = {451,180,408,214,402,222,398,230,395,237,392,245,392,253,392,260,393,265,395,270,399,274,403,277,407,281,414,282,420,283,425,285,430,285,435,285,442,286,447,286,455,285,462,285,471,284,477,282,485,281,491,279,497,277,503,274,507,266,511,260,512,251,510,242,507,233,502,223,497,213};
        int detail[] = {403,273,399,268,396,262};
        int detail2[] = {397,254,396,246,399,239};
        int detail3[] = {400,232,402,226,407,220};
        int detail4[] = {499,272,503,268,505,261};
        int detail5[] = {507,254,508,248,506,242};
        int detail6[] = {504,233,501,227,497,220};

        customPoly(bodyShape, sizeof(bodyShape) / sizeof(bodyShape[0]), GARFIELD_SKIN, OUTER);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail4, sizeof(detail4) / sizeof(detail4[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail5, sizeof(detail5) / sizeof(detail5[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail6, sizeof(detail6) / sizeof(detail6[0]), GARFIELD_BLACK, OUTER);

        leftArm();
        rightArm();
    }

    void tail(){
        int tail[] = {439,282,434,295,425,309,416,324,411,335,404,337,397,333,390,331,383,332,377,333,372,336,367,338,363,342,360,347,359,353,359,360,372,368,406,371,419,371,427,365,433,356,438,346,441,337,447,328,451,314,455,300,465,278};
        int detail[] = {359,359,359,352,361,344,366,340,371,336,377,332,383,331,391,331,400,334,387,337,397,340,379,339,392,344,373,345,387,349,368,349,382,355,368,356,373,362,359,372};
        int detail2[] = {413,342,439,295};
        int detail3[] = {418,341,442,301};
        int detail4[] = {435,292,440,295,444,299,449,301,454,303,463,274,442,263};

        customPoly(tail, sizeof(tail) / sizeof(tail[0]), GARFIELD_SKIN, OUTER);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail4, sizeof(detail4) / sizeof(detail4[0]), GARFIELD_BLACK, OUTER);
    }

    void leftFoot(){
        int foot[] = {416,276,416,285,416,294,420,351,413,353,420,356,405,354,397,352,388,352,380,353,370,356,360,359,351,366,345,372,340,379,340,388,342,393,348,391,349,396,355,399,361,399,365,391,367,397,371,400,377,399,382,396,388,387,392,391,397,393,402,394,408,391,413,388,423,388,432,388,447,386,457,384,463,379,462,370,456,364,444,357,437,286};
        int detail[] = {365,396,364,390,364,383,369,376};
        int detail2[] = {347,395,347,388,348,381,351,373};

        customPoly(foot, sizeof(foot) / sizeof(foot[0]), GARFIELD_SKIN, OUTER);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), GARFIELD_BLACK, OUTER);
    }

    void rightFoot(){
        int foot[] = {466,287,450,342,448,349,443,354,437,363,447,373,459,379,468,379,480,378,482,383,487,386,493,389,503,384,507,388,511,393,517,394,525,393,528,387,532,391,538,391,545,386,547,379,550,384,552,375,548,366,542,359,535,356,528,354,522,351,516,351,509,350,502,349,495,349,485,351,479,351,473,352,475,336,488,281};
        int detail[] = {525,370,529,374,530,380,529,386,526,391};
        int detail2[] = {538,364,542,368,546,372,547,379,549,384};

        customPoly(foot, sizeof(foot) / sizeof(foot[0]), GARFIELD_SKIN, OUTER);
        customPoly(detail, sizeof(detail) / sizeof(detail[0]), GARFIELD_BLACK, OUTER);
        customPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), GARFIELD_BLACK, OUTER);
    }

    void shadow(){
        int shadow[] = {345,388,339,390,334,393,335,398,342,400,349,400,357,398,360,391,366,398,372,400,382,400,387,400,379,391,391,395,399,395,415,380,441,374,453,385,471,388,484,388,493,388,505,390,520,388,532,392,541,394,547,394,553,394,545,382,520,372,484,365,420,364,369,370};

        customPoly(shadow, sizeof(shadow) / sizeof(shadow[0]), GARFIELD_BLACK, OUTER);
    }

    void topDetails(){
        int detail[] = {415,219,422,211,415,201,437,198,435,191,446,193,467,191,472,201,480,209,490,221};
        int detail2[] = {467,194,472,200,487,199,497,199,499,206,487,211,476,216,461,212};
        int detail3[] = {484,290,471,290,482,283,475,278,462,282,445,281,434,280,434,290,420,290,416,263,457,255,480,258,487,267};

        detailingPoly(detail, sizeof(detail) / sizeof(detail[0]), OUTER);
        detailingPoly(detail2, sizeof(detail2) / sizeof(detail2[0]), OUTER);
        detailingPoly(detail3, sizeof(detail3) / sizeof(detail3[0]), OUTER);
    }

    void drawGarfield(){
        shadow();
        tail();
        body();
        head();
        rightFoot();
        leftFoot();
        topDetails();
    }
};

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
    
    Garfield garfield;
    garfield.drawGarfield();

    Killua killua;
    killua.drawKillua();

    setcolor(COLOR(0, 0, 0));
    settextstyle(3, HORIZ_DIR, 5);
    outtextxy(10, 10, "Kurt Jacob E. Urquico");
   
    getch();
    closegraph();

    return 0;
}
