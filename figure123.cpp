#include <iostream>
#include <cstdlib>
#include <vector>
#include <GL/glut.h>
#include <ctime>
#include <cmath>

using namespace std;
#define tim 25
#define wid 800
#define hei 800 //высота экрана
#define count 1000 // количество элементов

class Figure{
protected:
	double x;
	double y;
	double speedY, speedX;
public:
	Figure() {
		this->speedY = hei / 75;
		this->speedX = (rand() % ((int)speedY * 2)) - speedY;
		this->x = rand() % wid;
		this->y = (rand() % hei) + hei / 4;
	}

	void motion(){
		y -= speedY;
		x += speedX;
		if (((x - wid / 120) < 0) || ((x + wid / 50) > wid)) {
			speedX *= -1;
		}
		if (y < 0) {
			x = rand() % wid;
			y = (rand() % hei) + hei;
		}
	}

	virtual void draw() = 0;
};

class Square : public Figure{
public:
	void draw() {
		glColor3f(0.0, 0.392, 0.0);
		glRectd(x, y, x + (wid / 50), y + (wid / 50));
	}
};

class Circle : public Figure {
public:
	void draw() {
		glColor3f(0.5, 0.0, 0.0);
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		int t = 50;
		float R = 7;
		for (int i = 0; i < t; i++) {
			float a = (float)i / (float)t * 3.1415f * 2.0f;
			glVertex2f(x - cos(a) * R, y - sin(a) * R);
		}
		glEnd();

	}
};

class Triangle : public Figure {
public:
	void draw() {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_TRIANGLES);
		glColor3d(0.0, 0.0, 1.0);
		glVertex3d(x, y, 0);
		glVertex3d (x + (wid / 50), y, 0);
		glVertex3d(x + (wid / 100), y + 0.866 * (hei / 50), 0);
		glEnd();
		glLineWidth(2);
	}
};

vector<Figure*> figs;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < count; i++) {
		figs[i]->draw();
		figs[i]->motion();
	}
	glFlush();
	glutSwapBuffers();
}

void timer(int = 0) {
	display();
	glutTimerFunc(tim, timer, 0);
}

int main(int argc, char** argv) {
	srand(time(0));

	for (int i = 0; i < count; i += 3) {
		figs.push_back(new Triangle);
		figs.push_back(new Square);
		figs.push_back(new Circle);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(wid, hei);
	glutCreateWindow("Figures");
	glClearColor(1.0, 0.921, 0.8, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, wid, 0, hei);

	glutDisplayFunc(display);
	glutTimerFunc(tim, timer, 0);

	glutMainLoop();

	return 0;
}
