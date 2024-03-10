#include <iostream>
#include <graphics.h>
#include <ctime>
#include <cmath>

#define PI 3.14159265

int main(){
    int gm, x, y, gd = DETECT, i;
    // int midx, midy;
    int stangle = 45, endangle = 50;
    
    char data[] = "C:\\MinGW\\lib\\libbgi.a"; //static file

    initgraph(&gd, &gm, data);

    // Get current time
    time_t now = time(0);
    struct tm *currentTime = localtime(&now);

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int radius = 150;

    while (!kbhit()) {
        // Clear screen
        cleardevice();

        // Draw clock face
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        circle(centerX, centerY, radius);
        floodfill(centerX, centerY, WHITE);

        // Draw hour marks
        setcolor(BLACK);
        for (int i = 0; i < 12; ++i) {
            double angle = i * 30 * PI / 180;
            int x1 = centerX + (radius - 10) * cos(angle);
            int y1 = centerY + (radius - 10) * sin(angle);
            int x2 = centerX + radius * cos(angle);
            int y2 = centerY + radius * sin(angle);
            line(x1, y1, x2, y2);
        }

        // Draw hour hand
        setcolor(RED);
        setlinestyle(SOLID_LINE, 0, 3);
        double hour_angle = (currentTime->tm_hour % 12 + currentTime->tm_min / 60.0) * 30 * PI / 180;
        line(centerX, centerY, centerX + 0.5 * radius * cos(hour_angle), centerY + 0.5 * radius * sin(hour_angle));

        // Draw minute hand
        setcolor(GREEN);
        setlinestyle(SOLID_LINE, 0, 2);
        double minute_angle = currentTime->tm_min * 6 * PI / 180;
        line(centerX, centerY, centerX + 0.8 * radius * cos(minute_angle), centerY + 0.8 * radius * sin(minute_angle));

        // Draw second hand
        setcolor(BLUE);
        setlinestyle(SOLID_LINE, 0, 1);
        double second_angle = currentTime->tm_sec * 6 * PI / 180;
        line(centerX, centerY, centerX + 0.9 * radius * cos(second_angle), centerY + 0.9 * radius * sin(second_angle));

        delay(1000); // Delay for one second
        now = time(0);
        currentTime = localtime(&now);
    }

    closegraph();

    return 0;
}