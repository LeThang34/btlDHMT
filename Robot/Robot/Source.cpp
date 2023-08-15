#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include <GL/freeglut.h>
using namespace std;
float carX, carY, carZ, carR, carG, carB, carAngle = 0;
float carY2, carY1, carY3 = 0.00;
bool isRotated = false;

void truc() {
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(50.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 50.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 50.0);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
}
//void drawBody() {
//	//Thân
//	glPushMatrix();
//	glColor3f(0.5, 0.0, .5); // Màu trắng cho thân xe
//	//glScalef(2, 1.5, 2); // Kích thước thân xe
//	//glutWireCube(2); // Hình khối chữ nhật
//	glScalef(2, 0.5, 0.5);
//	glutWireSphere(2, 50, 50);
//	glPopMatrix();
//
//	//Cánh
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	//glScalef(0.5, 1., 2);// Kích thước nóc xe
//	//glutSolidCube(2); // Hình khối chữ nhật
//	glScalef(1, 0.5, 0.05);
//	glutSolidSphere(2, 50, 50);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	glScalef(1, 0.5, 0.05);
//	glutSolidSphere(2, 50, 50);
//	glPopMatrix();
//
//	//Đuôi
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	glScalef(0.5, 0.05, 1);
//	glutSolidCube(2);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	glScalef(1, 0.5, 0.05);
//	glutSolidSphere(1, 50, 50);
//	glPopMatrix();
//
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	glScalef(1, 0.5, 0.05);
//	glutSolidSphere(1, 50, 50);
//	glPopMatrix();
//
//	//Quạt
//	glPushMatrix();
//	glColor3f(1.00, 1.00, 1.00); // Màu trắng cho nóc xe
//	glTranslatef(1.5, -1, 0); // Vị trí nóc xe
//	glScalef(0.05, 0.75, 0.25);
//	glutSolidSphere(2, 50, 50);
//	glPopMatrix();
//	////cabin
//	//glPushMatrix();
//	//glColor3f(.00, .00, 1.00); // Màu trắng cho nóc xe
//	//glTranslatef(2.2, -0.2, 0); // Vị trí nóc xe
//	//glScalef(0.5, 1., 2);// Kích thước nóc xe
//	////glRotatef(90, 0,1,0);
//	////glutSolidCylinder(0.5,3,50,50); // Hình khối chữ nhật
//	//glutSolidCube(2); // Hình khối chữ nhật
//
//	glPopMatrix();
//
//	//glPushMatrix();
//	//glColor3f(.5, .5, .5); // Màu xám cho cửa sổ trước
//	//glTranslatef(.75, -1, -2); // Vị trí cửa sổ trước
//	//glScalef(.5, .5, .5); // Kích thước cửa sổ trước
//	//glutSolidCube(2); // Hình khối chữ nhật
//	//glPopMatrix();
//
//	//glPushMatrix();
//	//glColor3f(.5, .5, .5); // Màu xám cho cửa sổ sau
//	//glTranslatef(-1, -1, -2); // Vị trí cửa sổ sau
//	//glScalef(.5, .5, .5); // Kích thước cửa sổ sau
//	//glutSolidCube(2); // Hình khối chữ nhật
//	//glPopMatrix()
//
//	//glPushMatrix();
//	//glColor3f(.8, .8, .8); // Màu bạc cho đèn pha trước
//	//glTranslatef(-1, -1, -4); // Vị trí đèn pha trước
//	//glScalef(.25, .25, .25); // Kích thước đèn pha trước
//	//glutSolidSphere(2, 20, 20); // Hình cầu
//	//glPopMatrix();
//
//	//glPushMatrix();
//	//glColor3f(.8, .8, .8); // Màu bạc cho đèn pha sau
//	//glTranslatef(-1, -1, -4); // Vị trí đèn pha sau
//	//glScalef(.25, .25, .25); // Kích thước đèn pha sau
//	//glutSolidSphere(2, 20, 20); // Hình cầu
//	//glPopMatrix();
//
//}
//void drawWheel() {
//	// Vẽ lốp xe
//	glPushMatrix();
//	glColor3f(0.5, 0.7, 0.9);
//	glutSolidTorus(0.15, 0.6, 20, 20);
//	glPopMatrix();
//
//	// Vẽ vành xe
//	glPushMatrix();
//	glColor3f(0.9, 0.9, 0.9);
//	glutSolidTorus(.05, .4, 20, 20);
//	glPopMatrix();
//
//	// Vẽ trục bánh xe
//	glPushMatrix();
//	glColor3f(0.9, 0.9, 0.9);
//	glTranslatef(-.6, -.6, -.6);
//	glutSolidCylinder(.05, .6, 20, 20);
//	glPopMatrix();
//}
bool derechoDown = false;
bool atrasDown = false;
bool izqDown = false;
bool derDown = false;
void myKeyboardUpFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		derechoDown = false;
		break;
	case 'd':
		atrasDown = false;
		break;
	case 'w':
		izqDown = false;
		break;
	case 's':
		derDown = false;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void myKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		derechoDown = true;
		break;
	case 'd':
		atrasDown = true;
		break;
	case 'w':
		izqDown = true;
		break;
	case 's':
		derDown = true;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
float wheelAngleLeft = carAngle;
float wheelAngleRight = carAngle;

float quay = 0;
void drawPlane(float x, float y, float z, float angle, float r, float g, float b) {
	// Thân
	glPushMatrix();
	glTranslatef(x, y, z);
	glRotatef(angle * 180 / 3.14, 0.0, 1.0, 0.0);
	glScalef(2, 0.5, 0.5);
	glColor3f(r, g, b);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	// Cabin
	glPushMatrix();
	glTranslatef(x - 1., y + 0.8 * cos(angle), z + 0.8 * sin(angle));
	glScalef(1, 0.5, 0.5);
	glColor3f(r - 0.2, g - 0.2, b - 0.2);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	// Cánh
	glPushMatrix();
	glTranslatef(x + cos(angle), y + 1.2 * cos(angle), z + sin(angle));
	glRotatef(45 + angle * 180 / 3.14, -sin(angle), cos(angle), -sin(angle));
	glScalef(1, 0.5, 0.05);
	glColor3f(r - 0.4, g - 0.4, b - 0.4);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	// Đuôi
	glPushMatrix();
	glTranslatef(x + (2.5 + sin(angle)) * cos(angle), y + (1.5 - cos(angle)) * sin(angle), z + (2 + sin(angle)) * sin(angle));
	glRotatef(35 + angle * 180 / 3.14, -sin(angle), cos(angle), -sin(angle));
	glScalef(0.5, 0.05, 1);
	glColor3f(1, 0, 0);
	glutSolidCube(2);
	glPopMatrix();

}
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glPopMatrix();
//	glPushMatrix();
//
//	glDisable(GL_LIGHT1);
//	glDisable(GL_LIGHT0);
//	glDisable(GL_LIGHTING);
//	truc();
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	float speed = 0.1;
//	float angleSpeed = 0.05;
//	float wheelAngle = 0.1;
//	if (derechoDown) {
//		carX += speed * sin(carAngle - M_PI / 2);
//		carZ += speed * cos(carAngle - M_PI / 2);
//	}
//	if (atrasDown) {
//		carX -= speed * sin(carAngle - M_PI / 2);
//		carZ -= speed * cos(carAngle - M_PI / 2);
//	}
//	if (izqDown) {
//		carAngle -= angleSpeed;
//	}
//	if (derDown) {
//		carAngle += angleSpeed;
//	}
//
//	drawPlane(carX, carY, carZ, carAngle, carR, carG, carB); // Gọi hàm vẽ máy bay
//
//	glutSwapBuffers();
//}

/*void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	truc();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	float speed = 0.01;
	float angleSpeed = 0.05;
	float wheelAngle = 0.1;
	if (derechoDown) {
		carX += speed * sin(carAngle - 3.14 / 2);
		carZ += speed * cos(carAngle - 3.14 / 2);
	}
	if (atrasDown) {
		carX -= speed * sin(carAngle - 3.14 / 2);
		carZ -= speed * cos(carAngle - 3.14 / 2);
	}
	if (izqDown) {
		carAngle -= angleSpeed;
	}
	if (derDown) {
		carAngle += angleSpeed;
	}
	glPushMatrix();
	glTranslatef(carX, 0.0, carZ);
	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	drawCarBody();


		Thân
		glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(carX, 0.0, carZ);
	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	glScalef(2, 0.5, 0.5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	Cabin
	glPushMatrix();
	glTranslatef(carX - 1., 0, carZ + 0.8);
	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	glScalef(1, 0.5, 0.5);
	glutSolidSphere(1, 50, 50);
	glPopMatrix();

	Cánh
	glPushMatrix();
	glTranslatef(carX, carY + 1.2, carZ);
	glRotatef(carAngle * 180 / 3.14 + 45, 0.0, 0.0, 1.0);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();

	glTranslatef(0, -1.2, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(2, 50, 50);
	drawBody();
	glPopMatrix();
	glPushMatrix();

		Đuôi
		glPushMatrix();
	glTranslatef(carX + 2.5, 0, carZ + 1.5);
	glRotatef(carAngle * 180 / 3.14 + 35, 0.0, 1.0, 0.0);
	glScalef(0.5, 0.05, 1);
	glutSolidCube(2);
	glPopMatrix();

		glTranslatef(2.75, 0.5, 2);
	glRotatef(45, 0, 0, 1);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(1, 50, 50);
	drawBody();
	glPopMatrix();
	glPushMatrix();


	glTranslatef(2.75, -0.5, 2);
	glRotatef(-45, 0, 0, 1);
	glScalef(1, 0.5, 0.05);
	glutSolidSphere(1, 50, 50);
	drawBody();
	glPopMatrix();
	glPushMatrix();

		Quạt
		glColor3f(1, 0, 0);
		glTranslatef(-2.75, 0, 0);
		glRotatef(quay, 1, 0, 0);
		quay = quay + 1;
		glutPostRedisplay();

		glScalef(0.05, 0.75, 0.25);
		glutSolidSphere(2, 50, 50);
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT0);
		drawBody();

	glPopMatrix();

	glutSwapBuffers();
}*/
float speed = 0.1;
float angleSpeed = 0.05;
float wheelAngle = 0.1;
void handleSpecialKey(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		carX += speed * sin(carAngle - 3.14 / 2);
		carZ += speed * cos(carAngle - 3.14 / 2);
		break;
	case GLUT_KEY_DOWN:
		carX -= speed * sin(carAngle - 3.14 / 2);
		carZ -= speed * cos(carAngle - 3.14 / 2);
		break;
	case GLUT_KEY_LEFT:
		carAngle -= angleSpeed;
		break;
	case GLUT_KEY_RIGHT:
		carAngle += angleSpeed;
		break;
	}
	glutPostRedisplay();
}


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPopMatrix();
	glPushMatrix();

	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	truc();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float speed = 0.1;
	float angleSpeed = 0.05;
	float wheelAngle = 0.1;
	if (derechoDown) {
		carX += speed * sin(carAngle - 3.14 / 2);
		carZ += speed * cos(carAngle - 3.14 / 2);
	}
	if (atrasDown) {
		carX -= speed * sin(carAngle - 3.14 / 2);
		carZ -= speed * cos(carAngle - 3.14 / 2);
	}
	if (izqDown) {
		carAngle -= angleSpeed;
	}
	if (derDown) {
		carAngle += angleSpeed;
	}
	glTranslatef(carX * sin(carAngle), 0.0, carZ * cos(carAngle));
	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);

	 //----Thân-----
	glScalef(2, 0.5, 0.5);
	glutSolidSphere(2, 50, 50);
	glPopMatrix();
	glPushMatrix();

	//-----Cánh-----
	//glTranslatef(carX + -0.5, -1.75, carZ + 0);
	//glRotatef(55, 0, 0, 1);
	//glScalef(1.5, 0.5, 0.15);
	//glutSolidSphere(2, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX - 0.5, 1.75, carZ);
	//glRotatef(-55, 0, 0, 1);
	//glScalef(1.5, 0.5, 0.15);
	//glutSolidSphere(2, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	////------Động cơ------
	//glTranslatef(carX + -.75, -2.4, carZ -0.3);
	//glRotatef(90, 0, 1, 0);
	//glScalef(1, 1, 1);
	//glutSolidCylinder(0.3, 2.5, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glColor3f(1, 0, 0);
	//glTranslatef(carX + 1.75, -2.4, carZ -0.2);
	//glRotatef(quay, 1, 0, 0);
	//quay = quay + 1;
	//glScalef(0.05, 0.5, 0.05);
	//glutPostRedisplay();
	//glutSolidSphere(2, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glColor3f(1, 0, 0);
	//glTranslatef(carX + 1.8, -2.4, carZ -0.3);
	//glRotatef(90, 0, 1, 0);
	//glScalef(0.25, 0.25, 0.5);
	//glutSolidCone(1, 1, 20, 20);
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX + -.78, 2.4, carZ -0.3);
	//glRotatef(90, 0, 1, 0);
	//glScalef(1, 1, 1);
	//glutSolidCylinder(0.3, 2.5, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glColor3f(1, 0, 0);
	//glTranslatef(carX + 1.75, 2.4, carZ -0.2);
	//glRotatef(quay, 1, 0, 0);
	//quay = quay + 1;
	//glScalef(0.05, 0.5, 0.05);
	//glutPostRedisplay();
	//glutSolidSphere(2, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glColor3f(1, 0, 0);
	//glTranslatef(carX + 1.78, 2.4, carZ -0.3);
	//glRotatef(90, 0, 1, 0);
	//glScalef(0.25, 0.25, 0.5);
	//glutSolidCone(1, 1, 20, 20);
	//glPopMatrix();
	//glPushMatrix();


	////------Đuôi-------
	//glColor3f(1, 0, 0);
	//glTranslatef(carX - 2.5, 0, carZ+1.5);
	//glRotatef(-35, 0, 1, 0);
	//glScalef(0.5, 0.05, 1);
	//glutSolidCube(2);
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX - 3, 0.5, carZ+ 2);
	//glRotatef(-45, 0, 0, 1);
	//glScalef(1, 0.5, 0.05);
	//glutSolidSphere(1, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX - 3, -0.5, carZ+ 2);
	//glRotatef(45, 0, 0, 1);
	//glScalef(1, 0.5, 0.05);
	//glutSolidSphere(1, 50, 50);
	//glPopMatrix();
	//glPushMatrix();

	////-------Quạt-------
	//glColor3f(1, 0, 0);
	//glTranslatef(carX +3.5, 0, carZ+ 0);
	//glRotatef(quay, 1, 0, 0);
	//quay = quay + 1;
	//glutPostRedisplay();
	//glScalef(0.05, 0.75, 0.25);
	//glutSolidSphere(2, 50, 50);
	//glPopMatrix();
	//glPushMatrix();
	//

	//glDisable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	////-------Cabin---------
	//glTranslatef(carX + 1., 0, carZ+0.8);
	//glScalef(1, 0.5, 0.5);
	//glutSolidSphere(1, 50, 50);
	//glPopMatrix();
	//glPushMatrix();
	//glDisable(GL_LIGHT1);

	//glEnable(GL_LIGHT2);		

	////-----Trục trước---------
	//glTranslatef(carX+3., 0, carZ -.25);
	//glRotatef(carY3-90, 0,1,0);
	//glTranslatef(carX -1,0, carZ+0.75);
	//glScalef(1.,0.25,0.5);
	//glutSolidCube(1);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();

	////Bánh trước
	//glTranslatef(carX+4., 0, carZ );
	////glRotatef(90, 1, 0, 0);
	//glRotatef(carY3-90, 0, 1, 0);
	////carY3 += 0.01;
	////if (carY3 > 60) carY3 = 61;
	//glTranslatef(carX -2, 0, carZ + 1.75);
	//glScalef(0.25, 0.1, 0.25);
	////glutSolidTorus(0.3,0.6, 10, 20);
	//glutSolidSphere(1, 50, 50);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();

	////------Trục sau----------
	////Bên phải
	//glTranslatef(carX -1., 0.2, carZ -0.75);
	//glRotatef(-carY1+90, 0, 1, 0);
	////carY1 += 0.01;
	////if (carY1 > 60) carY1 = 85;
	//glTranslatef(carX+ 0.5, 0.2, carZ+0.25);
	//glScalef(1., 0.25, 0.5);
	//glutSolidCube(1);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX -1.25, 0.2, carZ-0.5);
	////glRotatef(90, 1, 0, 0);
	//glRotatef(-carY1+90 , 0, 1, 0);
	//carY1 += 0.01;
	//if (carY1 > 60) carY1 = 85;
	//glTranslatef(carX + 1.5, 0.2, carZ + 0.5);
	//glScalef(0.25, 0.1, 0.25);
	////glutSolidTorus(0.3,0.6, 10, 20);
	//glutSolidSphere(1, 50, 50);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();
	////Bên trái
	//glTranslatef(carX - 1., -0.2, carZ - 0.75);
	//glRotatef(-carY1 + 90, 0, 1, 0);
	////carY1 += 0.01;
	////if (carY1 > 60) carY1 = 85;
	//glTranslatef(carX + 0.5, -0.2, carZ + 0.25);
	//glScalef(1., 0.25, 0.5);
	//glutSolidCube(1);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();

	//glTranslatef(carX - 1.25, -0.2, carZ - 0.5);
	////glRotatef(90, 1, 0, 0);
	//glRotatef(-carY1 + 90, 0, 1, 0);
	//carY1 += 0.01;
	//if (carY1 > 60) carY1 = 85;
	//glTranslatef(carX + 1.5, -0.2, carZ + 0.5);
	//glScalef(0.25, 0.1, 0.25);
	////glutSolidTorus(0.3,0.6, 10, 20);
	//glutSolidSphere(1, 50, 50);
	//glutPostRedisplay();
	//glPopMatrix();
	//glPushMatrix();
	//glDisable(GL_LIGHT2);

	glDisable(GL_LIGHTING);
	//carX += 0.001;
	//carZ += 0.0005;
	glPopMatrix();
	//	//glPushMatrix();
	//	//glPushMatrix();
	//	//glPushMatrix();
	//	//glTranslatef((carX + 1.75) - 0.25 * sin(carAngle), -0.75, carZ - 1.25 * cos(carAngle));
	//	//glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	//if (izqDown) {
	//	//	glRotatef(-wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	//}
	//	//if (derDown) {
	//	//	glRotatef(wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	//}
	//
	//	/*drawWheel();
	//	glPopMatrix();
	//	glPushMatrix();
	//	glTranslatef((carX + 1.75) + 0.25 * sin(carAngle), -0.75, carZ + 1.25 * cos(carAngle));
	//	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	if (izqDown) {
	//		glRotatef(-wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	}
	//	if (derDown) {
	//		glRotatef(wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0);
	//	}
	//	drawWheel();
	//	glPopMatrix();
	//	glPushMatrix();
	//	glTranslatef((carX - .75) - .25 * sin(carAngle), -.75, carZ + .25 * cos(carAngle));
	//	glRotatef(carAngle * 180 / 3.14 + 180, .5, .5, .5);
	//	drawWheel();
	//	glPopMatrix();
	//	glPushMatrix();
	//	glTranslatef((carX - .75) + .25 * sin(carAngle), -.75, carZ - .25 * cos(carAngle));
	//	glRotatef(carAngle * 180 / 3.14 - 180, .5, .5, .5);
	//	drawWheel();*/
	//	//glPopMatrix();
	glFlush();
}

void init() {
	glClearColor(1., .9, .9, .9);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);
	GLfloat posi[] = { 1, 0, 0, 1 };
	GLfloat ambient[] = { 1, 0, 0, 1 };
	GLfloat diffu[] = { 0, 0.5, 1.0, 1 };
	GLfloat specu[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, posi);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffu);

	glEnable(GL_LIGHT1);
	GLfloat posi1[] = { 1, 0, 0, 1 };
	GLfloat ambient1[] = { 1, 0, 0, 1 };
	GLfloat diffu1[] = { 0.8, 0.8, 0.8, 1 };
	GLfloat specu1[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT1, GL_POSITION, posi1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffu1);

	glEnable(GL_LIGHT2);
	GLfloat posi2[] = { 1, 0, 0, 1 };
	GLfloat ambient2[] = { 1, 0, 0, 1 };
	GLfloat diffu2[] = { 0., 0., 0., 1 };
	GLfloat specu2[] = { 1, 1, 1, 1 };
	glLightfv(GL_LIGHT2, GL_POSITION, posi2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, ambient2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, diffu2);
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, (GLfloat)w / (GLfloat)h, .5, 500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(7, 5, 10, 0, 0, 0, 0,0, 1);

	//glLoadIdentity(); // Đặt ma trận phép chiếu về ma trận đơn vị
	//glOrtho(2.0, 2.0, 2.0, 2.0, 10.0, 10.0); // Thiết lập ma trận phép chiếu trực giao


}
//float carX, carZ, carAngle = 0;
//
//
//void truc() {
//	glBegin(GL_LINES);
//	glColor3f(1.0, 0.0, 0.0);
//	glVertex3f(10.0, 0.0, 0.0);
//	glVertex3f(0.0, 0.0, 0.0);
//
//	glColor3f(0.0, 1.0, 0.0);
//	glVertex3f(0.0, 10.0, 0.0);
//	glVertex3f(0.0, 0.0, 0.0);
//
//	glColor3f(0.0, 0.0, 1.0);
//	glVertex3f(0.0, 0.0, 10.0);
//	glVertex3f(0.0, 0.0, 0.0);
//	glEnd();
//
//}
//
//void drawCarBody() {
//	// Vẽ thân ô tô bằng các hình hình học cơ bản
//	glPushMatrix();
//
//	// Thân trên
//	glColor3f(0.58, 0.87, 0.85);
//	glScalef(2.0, 0.5, 1.0);
//	glutSolidCube(2.0);
//
//	// Thân dưới
//	// Vẽ nửa dưới của thân ô tô
//	glPushMatrix();
//	glColor3f(0.58, 0.87, 0.85);
//
//	glTranslatef(0.0, -0.75, 0.0);
//	glScalef(1.5, 0.5, 1.0);
//	glutSolidCube(2.0);
//	glPopMatrix();
//
//	// Cửa trước
//	glColor3f(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glTranslatef(0.75, 0.0, 0.0);
//	glScalef(0.5, 1.0, 1.0);
//	glutSolidCube(2.0);
//	glPopMatrix();
//
//	// Cửa sau
//	glColor3f(0.0, 0.0, 1.0);
//	glPushMatrix();
//	glTranslatef(-0.75, 0.0, 0.0);
//	glScalef(0.5, 1.0, 1.0);
//	glutSolidCube(2.0);
//	glPopMatrix();
//
//	glPopMatrix();
//}
//
//void drawWheel() {
//	// Vẽ vòng ngoài của bánh xe
//	glPushMatrix();
//	glColor3f(0.0, 0.0, 0.0);  // Màu đen
//	glutSolidTorus(0.1, 0.5, 20, 20);  // Vẽ một vòng tròn mô phỏng bánh xe
//	glPopMatrix();
//
//	// Vẽ trục bánh xe
//	glPushMatrix();
//	glColor3f(0.0, 0.0, 0.0);  // Màu đen
//	glTranslatef(0.0, 0.0, -0.25);  // Di chuyển trục bánh xe về phía trước
//	glutSolidCylinder(0.05, 0.5, 20, 20);  // Vẽ một hình trụ mô phỏng trục bánh xe
//	glPopMatrix();
//}
//
//bool derechoDown = false;
//bool atrasDown = false;
//bool izqDown = false;
//bool derDown = false;
//// Hàm xử lý sự kiện nhả phím
//void myKeyboardUpFunc(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'a':
//		derechoDown = false;
//		break;
//	case 'd':
//		atrasDown = false;
//		break;
//	case 'w':
//		izqDown = false;//quay trái
//		break;
//	case 's':
//		derDown = false;//quay phải
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//// Hàm xử lý sự kiện nhấn phím
//void myKeyboardFunc(unsigned char key, int x, int y) {
//	switch (key) {
//	case 'a':
//		derechoDown = true;
//		break;
//	case 'd':
//		atrasDown = true;
//		break;
//	case 'w':
//		izqDown = true;
//		break;
//	case 's':
//		derDown = true;
//		break;
//	default:
//		break;
//	}
//	glutPostRedisplay();
//}
//
//float wheelAngleLeft = carAngle;
//float wheelAngleRight = carAngle;
//
//
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	truc();
//
//	float speed = 0.1; // Tốc độ di chuyển của xe
//	float angleSpeed = 0.05; // Tốc độ quay của xe
//	float wheelAngle = 0.1; // Góc nghiêng của bánh xe
//	// Tính toán và cập nhật các giá trị của carX, carZ, và carAngle
//	if (derechoDown) {
//		carX += speed * sin(carAngle - 3.14 / 2); // Di chuyển xe theo phương ngang
//		carZ += speed * cos(carAngle - 3.14 / 2); // Di chuyển xe theo phương dọc
//	}
//	if (atrasDown) {
//		carX -= speed * sin(carAngle - 3.14 / 2); // Di chuyển xe theo phương ngang
//		carZ -= speed * cos(carAngle - 3.14 / 2); // Di chuyển xe theo phương dọc
//	}
//	if (izqDown) {
//		carAngle -= angleSpeed; // Quay xe sang trái
//	}
//	if (derDown) {
//		carAngle += angleSpeed; // Quay xe sang phải
//	}
//	// Xoay, di chuyển, và vẽ xe theo các giá trị mới
//	glPushMatrix();
//	glTranslatef(carX, 0.0, carZ); // Di chuyển xe đến vị trí mới
//	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Xoay xe theo góc mới
//	drawCarBody(); // Vẽ thân xe
//	glPopMatrix();
//
//	// Vẽ 4 bánh xe
//	glPushMatrix();
//
//	// Bánh xe 1
//	glPushMatrix();
//	glTranslatef((carX+1.75) - 0.25 * sin(carAngle), -0.75, carZ - 1.25 * cos(carAngle)); // Di chuyển bánh xe về phía trước và sang trái
//	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Xoay bánh xe theo góc của xe
//	if (izqDown) {
//		glRotatef(-wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Nghiêng bánh xe sang trái khi rẽ trái
//	}
//	if (derDown) {
//		glRotatef(wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Nghiêng bánh xe sang phải khi rẽ phải
//	}
//	drawWheel(); // Vẽ hình dạng của bánh xe
//	glPopMatrix();
//
//	// Bánh xe2 
//	glPushMatrix();
//	glTranslatef((carX + 1.75) + 0.25*sin(carAngle), -0.75, carZ + 1.25*cos(carAngle)); // Di chuyển bánh xe về phía trước và sang phải
//	glRotatef(carAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Xoay bánh xe theo góc của xe
//	if (izqDown) {
//		glRotatef(-wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Nghiêng bánh xe sang trái khi rẽ trái
//	}
//	if (derDown) {
//		glRotatef(wheelAngle * 180 / 3.14, 0.0, 1.0, 0.0); // Nghiêng bánh xe sang phải khi rẽ phải
//	}
//	drawWheel(); // Vẽ hình dạng của bánh xe
//	glPopMatrix();
//
//	// Bánh xe 3
//	glPushMatrix();
//	glTranslatef((carX - 1.75) - 0.25 * sin(carAngle), -0.75, carZ + 1.25 * cos(carAngle)); // Di chuyển bánh xe về phía sau và sang trái
//	glRotatef(carAngle * 180 / 3.14 + 180, 0.0, 1.0, 0.0); // Xoay bánh xe theo góc của xe và xoay ngược lại để đối xứng với bánh trước 
//	drawWheel(); // Vẽ hình dạng của bánh xe
//	glPopMatrix();
//
//	// Bánh xe4 
//	glPushMatrix();
//	glTranslatef((carX - 1.75) + 0.25*sin(carAngle), -.75, carZ - 1.25*cos(carAngle)); // Di chuyển bánh xe về phía sau và sang phải
//	glRotatef(carAngle * 180 / 3.14 - 180, 0.0, 1.0, 0.0); // Xoay bánh xe theo góc của xe và xoay ngược lại để đối xứng với bánh trước
//	drawWheel(); // Vẽ hình dạng của bánh xe
//	glPopMatrix();
//
//	glFlush();
//}
//
//void init()
//{
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glEnable(GL_DEPTH_TEST);
//}
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(45, (GLfloat)w / (GLfloat)h, 1, 200);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	gluLookAt(0, 10, 0, 0, 0, 0, 1, 0, 0 );
//}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");
	glutKeyboardUpFunc(myKeyboardUpFunc);
	init();
	glutDisplayFunc(MyDisplay);

	glutKeyboardUpFunc(myKeyboardUpFunc);
	glutKeyboardFunc(myKeyboardFunc);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}