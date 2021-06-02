
//**********************8x8 Chess box By Diganta*********************************//
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<Windows.h>
int x = 50, y = 50;
bool check = true;
void bBox(int x, int y)//For BlackBox
{
glBegin(GL_POLYGON);
glVertex2i(x, y);
glVertex2i(x, y + 50);
glVertex2i(x + 50, y + 50);
glVertex2i(x + 50, y);
glEnd();
}
void wBox(int x, int y)//For White Box
{
glBegin(GL_LINE_LOOP);
glVertex2i(x, y);
glVertex2i(x, y + 50);
glVertex2i(x + 50, y + 50);
glVertex2i(x + 50, y);
glEnd();
}
void chessDisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0);
glPointSize(1.0);
for (int i = 0; i < 8; i++)
{
if (i % 2 == 0)
{
    check = true;
}
else
{
    check = false;
}
for (int j = 0; j < 8; j++)
{
if (check)
{
bBox(x, y);
check = false;
}
else
{
wBox(x, y);
check = true;
}
x += 50;
}
y += 50;
x = 50;
}
bBox(100, 100);
wBox(150, 100);
glFlush();
}
void mydisplay(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutCreateWindow("8X8 chessboard by Diganta");
glutInitWindowSize(1280,820);
glutInitWindowPosition(50, 50);
glutDisplayFunc(chessDisplay);
mydisplay();
glutMainLoop();
}
