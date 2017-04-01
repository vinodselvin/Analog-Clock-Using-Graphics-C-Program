/*
@Author: Vinod Selvin
@Desc: Analog Clock source code.
*/

#include <graphics.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>
#include <math.h> 
#include <dos.h> 
#include <process.h>

float rad = 3.14 / 180;
float th, ang = 1, ang1 = 1;
int i, gdriver = DETECT, gmode, errorcode;
int xmax, ymax;
double s, c, s1, c1, s2, c2;
int X1, X2, Y2, Y1, k, xc, yc, r;
int x1, y1, X, Y, x2, y2, x3, y3;
int X0, Y0, x0, y0, x4, y4, j;

void hour() {

  setcolor(BLACK);

  line(xc, yc, x4 + xc, y4 + yc);

  setcolor(GREEN);

  ang1 = rad * j;

  s2 = sin(ang1);
  c2 = cos(ang1);

  x0 = X0 - xc;
  y0 = Y0 - yc;

  x4 = x0 * c2 + y0 * s2;
  y4 = x0 * s2 - y0 * c2;

  setcolor(GREEN);

  outtextxy(xc - 15, yc - 100, "Vinod");

  setcolor(GREEN);

  line(xc, yc, x4 + xc, y4 + yc);
}

void sec() {

  setcolor(GREEN);

  line(xc, yc, x4 + xc, y4 + yc);

  setcolor(9);

  ang = rad * i;

  s1 = sin(ang);
  c1 = cos(ang);

  X = x1 - xc;
  Y = 25 + x1 - yc;

  x2 = X * c1 + Y * s1;
  y2 = X * s1 - Y * c1;

  setcolor(WHITE);

  line(xc, yc, x3 + xc, y3 + yc);

  setcolor(GREEN);

  outtextxy(xc - 15, yc - 100, "Vinod");

  setcolor(9);

  line(xc, yc, x2 + xc, y2 + yc);

  delay(1000);

  setcolor(BLACK);

  line(xc, yc, x2 + xc, y2 + yc);
}

void minute() {

  setcolor(BLACK);

  line(xc, yc, x3 + xc, y3 + yc);

  setcolor(WHITE);

  ang1 = rad * k;

  s = sin(ang1);
  c = cos(ang1);

  X2 = X1 - xc;
  Y2 = 50 + X1 - yc;

  x3 = X2 * c + Y2 * s;
  y3 = X2 * s - Y2 * c;

  setcolor(GREEN);

  outtextxy(xc - 15, yc - 100, "Vinod");

  setcolor(WHITE);

  line(xc, yc, x3 + xc, y3 + yc);
}

void main() {

  initgraph( & gdriver, & gmode, "");

  errorcode = graphresult();

  if (errorcode != grOk) {

    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");

    getch();
    exit(1);
  }

  xc = 350;
  yc = 250;
  r = 200;

  x1 = xc;
  y1 = yc - 120;

  X1 = xc;
  Y1 = yc - 120;

  X0 = xc;
  Y0 = yc - 90;

  setcolor(YELLOW);

  for (i = 0; i <= 4; i++) {

    circle(xc, yc, r + i);
  }

  setcolor(WHITE);

  for (i = 10; i <= 14; i++) {

    circle(xc, yc, r + i);
  }

  //no's

  setcolor(RED);

  outtextxy(xc, yc - 180, "12");

  outtextxy(xc + 180, yc, "3");

  outtextxy(xc, yc + 180, "6");

  outtextxy(xc - 180, yc, "9");

  outtextxy(xc + 90, yc - 150, "1");

  outtextxy(xc + 150, yc - 90, "2");

  outtextxy(xc + 150, yc + 90, "4");

  outtextxy(xc + 90, yc + 150, "5");

  outtextxy(xc - 90, yc + 150, "7");

  outtextxy(xc - 150, yc + 90, "8");

  outtextxy(xc - 150, yc - 90, "10");

  outtextxy(xc - 90, yc - 150, "11");

  //calculation
  setlinestyle(0, 0, 2);

  line(xc, yc, x1, y1);

  setcolor(BLACK);

  line(xc, yc, x1, y1);

  for (j = 0; j <= 360; j = j + 30) {

    hour();

    for (k = 6; k <= 360; k = k + 6) {

      minute();

      for (i = 6; i <= 360; i = i + 6) {

        if (kbhit() > 0) {

          break;
        } else {

          sec();
        }
      }
    }
  }
getch();
}
