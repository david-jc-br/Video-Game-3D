﻿#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

int w = 1920, h = 1080;
short op = 1, op0 = 1;

GLfloat angle = 0;

struct observer
{
	GLdouble obsX;
	GLdouble obsY;
	GLdouble obsZ;
};

observer cam;

void initializeCam()
{
	// Inicia valores do observador 
	cam.obsX = 25;
	cam.obsY = -10;
	cam.obsZ = 22;
}

// objetos 3D
//--------------------------------------------------------------------------------------
void drawBox()
{
	glPushMatrix();
	glColor3f(0.1f, 0.5f, 0.6f);
	glTranslated(0, 0, 50);
	glutSolidCube(100);
	glPopMatrix();
}

void drawDisplayVideoGame()
{
	glTranslated(0.001, 0, 0);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3i(3, 1, 14);
		glVertex3i(3, 9, 14);
		glVertex3i(3, 9, 8);
		glVertex3i(3, 1, 8);
		glEnd();

		glTranslated(0.002, 0, 0);
		glBegin(GL_QUADS);
		glColor3f(0.5f, 0.5f, 0.1f);
		glVertex3i(3, 8, 13);
		glVertex3i(3, 8, 9);
		glVertex3i(3, 2, 9);
		glVertex3i(3, 2, 13);
	glEnd();
}

void drawBodyVideoGame()
{
	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.8f, 0.8f);
		glNormal3f(0.f, 0.f, -1.f);
		glVertex3i(0, 0, 15);  //Front
		glVertex3i(0, 10, 15);
		glVertex3i(0, 10, 0);
		glVertex3i(0, 0, 0);

		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(3, 0, 15);//back
		glVertex3i(3, 10, 15);
		glVertex3i(3, 10, 0);
		glVertex3i(3, 0, 0);

		glNormal3f(0.f, 1.f, 0.f);
		glVertex3i(0, 0, 0); //Top
		glVertex3i(3, 0, 0);
		glVertex3i(3, 0, 15);
		glVertex3i(0, 0, 15);

		glNormal3f(0.f, -1.f, 0.f);
		glVertex3i(0, 10, 0); //Botton
		glVertex3i(3, 10, 0);
		glVertex3i(3, 10, 15);
		glVertex3i(0, 10, 15);

		glNormal3f(-1.f, 0.f, 0.f);
		glVertex3i(0, 0, 0); //left
		glVertex3i(3, 0, 0);
		glVertex3i(3, 10, 0);
		glVertex3i(0, 10, 0);

		glNormal3f(1.f, 0.f, 0.f);
		glVertex3i(0, 10, 15); //right
		glVertex3i(0, 0, 15);
		glVertex3i(3, 0, 15);
		glVertex3i(3, 10, 15);
	glEnd();
}

void drawButtonsVideoGame()
{
	glTranslated(0.001, 0, 0);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glColor3f(0.1f, 0.1f, 0.1f);
		glVertex3i(3, 2, 6); // botão de cruz
		glVertex3i(3, 2, 5);
		glVertex3i(3, 3, 5);
		glVertex3i(3, 3, 6);
		glVertex3i(3, 1, 5);
		glVertex3i(3, 1, 4);
		glVertex3i(3, 4, 4);
		glVertex3i(3, 4, 5);
		glVertex3i(3, 2, 4);
		glVertex3i(3, 2, 3);
		glVertex3i(3, 3, 3);
		glVertex3i(3, 3, 4);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.1f, 0.1f, 0.1f); // botão cruz
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(3, 2, 6);
		glVertex3i(3, 2, 5);
		glVertex3i(3, 3, 5);
		glVertex3i(3, 3, 6);

		glVertex3i(3, 1, 5);
		glVertex3i(3, 1, 4);
		glVertex3i(3, 4, 4);
		glVertex3i(3, 4, 5);

		glVertex3i(3, 2, 4);
		glVertex3i(3, 2, 3);
		glVertex3i(3, 3, 3);
		glVertex3i(3, 3, 4);
	glEnd();
		
	glBegin(GL_QUADS); // botões quadrados
		glColor3f(0.5f, 0.5f, 0.5f);
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(3, 4, 1);
		glVertex3i(3, 5, 1);
		glVertex3i(3, 5, 2);
		glVertex3i(3, 4, 2);

		glVertex3i(3, 6, 1);
		glVertex3i(3, 7, 1);
		glVertex3i(3, 7, 2);
		glVertex3i(3, 6, 2);

		glColor3f(0.7f, 0.0f, 0.0f);
		glVertex3i(3, 6, 3);
		glVertex3i(3, 7, 3);
		glVertex3i(3, 7, 4);
		glVertex3i(3, 6, 4);

		glVertex3i(3, 8, 5);
		glVertex3i(3, 8, 4);
		glVertex3i(3, 9, 4);
		glVertex3i(3, 9, 5);
	glEnd();

	glTranslated(0, -0.001, 0);
	glBegin(GL_QUADS); // lateral esquerdo
		glColor3f(0.1f, 0.1f, 0.1f);
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(2, 0, 11); 
		glVertex3i(1, 0, 11);
		glVertex3i(1, 0, 9);
		glVertex3i(2, 0, 9);
	glEnd();

	glTranslated(0, 0.01, 0);
	glBegin(GL_QUADS); // lateral direito
		glColor3f(0.1f, 0.1f, 0.1f);
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(2, 10, 11); 
		glVertex3i(1, 10, 11);
		glVertex3i(1, 10, 9);
		glVertex3i(2, 10, 9);
	glEnd();
}

void drawCargoCover()
{
	glColor3f(0.7f, 0.0f, 0.0f);
	glTranslated(0, 0, 0.001);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 1.f, 0.f);
		glVertex3i(0, 2, 15);
		glVertex3i(0, 8, 15);
		glVertex3i(1, 8, 15);
		glVertex3i(1, 2, 15);
	glEnd();

	glTranslated(-0.01,0, 0);
		glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(0, 2, 15);
		glVertex3i(0, 8, 15);
		glVertex3i(0, 8, 12);
		glVertex3i(0, 2, 12);
	glEnd();
}

void drawVideoGame()
{
	drawBodyVideoGame();
	drawDisplayVideoGame();
	drawButtonsVideoGame();
	drawCargoCover();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);

	drawBox();
	glPushMatrix();
	glRotatef(angle, 0, 0, 1);
	drawVideoGame();
	glPopMatrix();
	glFlush();
}

// Menu PopUp
//--------------------------------------------------------------------------------------

void subMenuResolution(int option)
{
	switch (option)
	{

		case 1:
			glutFullScreen();
			glutPostRedisplay();
			break;
		case 2:
			glutReshapeWindow(640, 480);
			glutPostRedisplay();
			break;
		case 3:
			glutReshapeWindow(1280, 750);
			glutPostRedisplay();
			break;
		case 4:
			glutReshapeWindow(1920, 1080);
			glutPostRedisplay();
			break;
	}

}

void subMenuChangeSetence(int option)
{
	switch (option)
	{

		case 1:
			//cout << "Frase do Display alterada para \"Ola Mundo\"" << endl;
			break;
		case 2:
			//cout << "Frase do Display alterada para \"hello World\"" << endl;
			break;
		case 3:
			//cout << "Frase do Display alterada para \"Computação Grafica\"" << endl;
			break;
		case 4:
			//cout << "Frase do Display alterada para \"GAC104\"" << endl;
			break;
	}

}

void menuPrincipal(int option)
{
	switch (option)
	{
		case 0:
			exit(0);
			break;
	}
}

void menuPopUp()
{
	int sMenuResolution, sMenuChangeSetence;

	sMenuResolution = glutCreateMenu(subMenuResolution);

	glutAddMenuEntry("SD", 2);
	glutAddMenuEntry("HD", 3);
	glutAddMenuEntry("FHD", 4);
	glutAddMenuEntry("Tela Cheia", 1);

	sMenuChangeSetence = glutCreateMenu(subMenuChangeSetence);

	glutAddMenuEntry("Olá Mundo", 1);
	glutAddMenuEntry("Hello World", 2);
	glutAddMenuEntry("Computação Gráfica", 3);
	glutAddMenuEntry("GAC104", 4);

	glutCreateMenu(menuPrincipal);

	glutAddSubMenu("Alterar Resolução", sMenuResolution);
	glutAddSubMenu("Alterar frase do Display", sMenuChangeSetence);
	glutAddMenuEntry("Sair", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Init e Reshape
//-------------------------------------------------------------------------------------

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float globalAmb[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmb);

	float light0[4][4] = {
		{ 0.3f, 0.3f, 0.3f, 1.0f }, // ambiente
		{ 0.3f, 0.3f, 0.3f, 1.0f }, // Difusa
		{ 0.1f, 0.1f, 0.1f, 0.0f }, // specular 
		{ 0.0, 200.0f, 0.0, 0.0f }};// positon

	glLightfv(GL_LIGHT0, GL_AMBIENT, &light0[0][0]);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &light0[1][0]);
	glLightfv(GL_LIGHT0, GL_SPECULAR, &light0[2][0]);
	glLightfv(GL_LIGHT0, GL_POSITION, &light0[3][0]);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH);

	glutFullScreen();
}

void reshape(int w, int h)
{
	float aspect = (float)w / (float)h;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, aspect, 0.5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cam.obsX, cam.obsY, cam.obsZ, 0, 0, 0, 0, 0, 1);
}

// Teclado e Mouse
//-------------------------------------------------------------------------------------

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27: 
			exit(0);
			break;
		case '1':
			if (op0 == 1) {
				glDisable(GL_LIGHT0);
				op0 = 0;
			}
			else {
				glEnable(GL_LIGHT0);
				op0 = 1;
			}

			glutPostRedisplay();
			break;

		case '2':
			if (op == 1) {
				glDisable(GL_LIGHTING);
				op = 0;
			}
			else {
				glEnable(GL_LIGHTING);
				op = 1;
			}

			glutPostRedisplay();
			break;
	}
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_RIGHT:
			angle += 1.0f;

			if (angle >= 360.0f)
				angle = 1.0f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			angle -= 1.f;

			if (angle <= -360.0f)
				angle = 1.f;
			glutPostRedisplay();
			break;
	}
}

void mouse(int button, int state, int x, int y)
{

}


// Função Principal
//-------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(w, h);
	glutCreateWindow("Video-Game-3D");
	init();
	initializeCam();
	glutDisplayFunc(display);
	menuPopUp();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}