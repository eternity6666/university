#include <cmath>
#include <glfw3.h>
#include <cstdio>

void draw_pixel(int ix, int iy)
{
    glBegin(GL_POINTS);
    glVertex2i(ix, iy);
    glEnd();
}

void bresenham(int x1, int y1, int xEnd, int yEnd)
{
    int dx = abs(xEnd - x1), dy = abs(yEnd - y1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * dy - 2 * dx;
    int x, y;
    if (x1 > xEnd)
    {
        x = xEnd;
        y = yEnd;
        xEnd = x1;
    }
    else
    {
        x = x1;
        y = y1;
    }
    draw_pixel(x, y);
    while (x < xEnd)
    {
        x++;
        if (p < 0)
            p += twoDy;
        else
        {
            y++;
            p += twoDyMinusDx;
            draw_pixel(x, y);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(0, 0, 400, 400);
    glFlush();
}

void myinit()
{
    glClearColor(0.8,1.0,1.0,1.0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main()
{
    gluI
}