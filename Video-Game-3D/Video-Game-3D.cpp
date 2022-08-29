#include <GL/glut.h>
#include <GL/gl.h>
#include <iostream>

using namespace std;

// Variavéis Globais 
//--------------------------------------------------------------------------------------

int w = 1920, h = 1080; 

GLfloat R = 0.0f, G = 0.0f, B = 0.0f; // RGB

string action = "up"; // ação da animação se é subir ou descer

GLfloat angle = 15; // angulo inicial da animação

GLfloat height = 0; // altura inicial da animãção 

bool animationState = TRUE; // Estado da animação de ativo ou desativado

short colorVideoGame = 1, backgroundColor = 1; // Cor do video-game e do fundo

// Definções da textura 
//--------------------------------------------------------------------------------------
#define	checkImageWidth 8
#define	checkImageHeight 16
static GLubyte checkImage[checkImageHeight][checkImageWidth][8];

#ifdef GL_VERSION_1_1
static GLuint texName;
#endif

void makeCheckImage(void)
{
	int i, j, c;

	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			c = ((((i & 0x8) == 0) ^ ((j & 0x8)) == 0)) * 255;
			checkImage[i][j][0] = (GLubyte)c;
			checkImage[i][j][1] = (GLubyte)c;
			checkImage[i][j][2] = (GLubyte)c;
			checkImage[i][j][3] = (GLubyte)255;
		}
	}
}

// objetos 3D
//--------------------------------------------------------------------------------------
void drawBox()
{
	switch (backgroundColor)
	{
	case 1:
		glColor3f(0.1f, 0.5f, 0.6f); // azul 
		break;
	case 2:
		glColor3f(0.5f, 0.6f, 0.0f); // verde
		break;
	case 3:
		glColor3f(0.4f, 0.3f, 0.1f); // marrom
		break;
	case 4:
		glColor3f(0.6f, 0.2f, 0.2f); // vermelho
		break;
	}

	glPushMatrix();
	glTranslated(0, 0, 49);
	glutSolidCube(100);
	glPopMatrix();
}

void drawDisplayVideoGame()
{
	glTranslated(0.001, 0, 0);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glColor3f(R, G, B);
		glVertex3i(3, 1, 14);
		glVertex3i(3, 9, 14);
		glVertex3i(3, 9, 6);
		glVertex3i(3, 1, 6);
	glEnd();
}

void drawBodyVideoGame()
{
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, -1.f);
		glVertex3i(3, 0, 15);// frente
		glVertex3i(3, 10, 15);
		glVertex3i(3, 10, 0);
		glVertex3i(3, 0, 0);

		glNormal3f(0.f, 1.f, 0.f);
		glVertex3i(0, 0, 0); // lado esquerdo
		glVertex3i(3, 0, 0);
		glVertex3i(3, 0, 15);
		glVertex3i(0, 0, 15);

		glNormal3f(0.f, -1.f, 0.f);
		glVertex3i(0, 10, 0); // lado direito
		glVertex3i(3, 10, 0);
		glVertex3i(3, 10, 15);
		glVertex3i(0, 10, 15);

		glNormal3f(-1.f, 0.f, 0.f);
		glVertex3i(0, 0, 0); // fundo
		glVertex3i(3, 0, 0);
		glVertex3i(3, 10, 0);
		glVertex3i(0, 10, 0);

		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(0, 0, 15); // trazeira
		glVertex3i(0, 10, 15);
		glVertex3i(0, 10, 0);
		glVertex3i(0, 0, 0);
		
	glEnd();

	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
#ifdef GL_VERSION_1_1
	glBindTexture(GL_TEXTURE_2D, texName);
#endif

	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3i(0, 10, 15); // topo
		glTexCoord2f(0.0, 1.0);glVertex3i(0, 0, 15);
		glTexCoord2f(1.0, 1.0);glVertex3i(3, 0, 15);
		glTexCoord2f(1.0, 0.0);glVertex3i(3, 10, 15);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void drawButtonsVideoGame()
{
	glTranslated(0.001, 0, 0);
	glBegin(GL_QUADS);
		glNormal3f(0.f, 0.f, 1.f);
		glColor3f(0.1f, 0.1f, 0.1f);
		glVertex3i(3, 2, 5); // botão de cruz
		glVertex3i(3, 2, 4);
		glVertex3i(3, 3, 4);
		glVertex3i(3, 3, 5);
		glVertex3i(3, 1, 4);
		glVertex3i(3, 1, 3);
		glVertex3i(3, 4, 3);
		glVertex3i(3, 4, 4);
		glVertex3i(3, 2, 3);
		glVertex3i(3, 2, 2);
		glVertex3i(3, 3, 2);
		glVertex3i(3, 3, 3);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.1f, 0.1f, 0.1f); // botão cruz
		glNormal3f(0.f, 0.f, 1.f);
		glVertex3i(3, 2, 5);
		glVertex3i(3, 2, 4);
		glVertex3i(3, 3, 4);
		glVertex3i(3, 3, 5);

		glVertex3i(3, 1, 4);
		glVertex3i(3, 1, 3);
		glVertex3i(3, 4, 3);
		glVertex3i(3, 4, 4);

		glVertex3i(3, 2, 3);
		glVertex3i(3, 2, 2);
		glVertex3i(3, 3, 2);
		glVertex3i(3, 3, 3);
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

	switch (colorVideoGame)
	{
		case 1:
			glColor3f(0.8f, 0.8f, 0.8f); // cinza 
			break;
		case 2: 
			glColor3f(0.4f, 0.9f, 0.3f); // verde
			break;
		case 3:
			glColor3f(0.7f, 0.5f, 0.0f); // amarelo
			break;
		case 4:
			glColor3f(0.7f, 0.3f, 0.7f); // roxo
			break;
	}

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
	glTranslatef(6, -12, height);
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

void subMenuLight0(int option)
{
	switch (option)
	{
		case 1:
			glEnable(GL_LIGHT0);
			glutPostRedisplay();
			break;
		case 2:
			glDisable(GL_LIGHT0);
			glutPostRedisplay();
			break;
	}
}

void subMenuLighting(int option)
{
	switch (option)
	{
	case 1:
		glEnable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	case 2:
		glDisable(GL_LIGHTING);
		glutPostRedisplay();
		break;
	}
}

void subMenuColorVideoGame(int option)
{
	switch (option)
	{
		case 1:
			colorVideoGame = 1;
			glutPostRedisplay();
			break;
		case 2:
			colorVideoGame = 2;
			glutPostRedisplay();
			break;
		case 3:
			colorVideoGame = 3;
			glutPostRedisplay();
			break;
		case 4:
			colorVideoGame = 4;
			glutPostRedisplay();
			break;
	}
}

void subMenuBackgroundColor(int option)
{
	switch (option)
	{
	case 1:
		backgroundColor = 1;
		glutPostRedisplay();
		break;
	case 2:
		backgroundColor = 2;
		glutPostRedisplay();
		break;
	case 3:
		backgroundColor = 3;
		glutPostRedisplay();
		break;
	case 4:
		backgroundColor = 4;
		glutPostRedisplay();
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
	int sMenuResolution, sMenuChangeSetence,
		sMenuLight0, sMenuLighting, sMenuColorVideoGame,
		sMenuBackgroundColor;

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

	sMenuLight0 = glutCreateMenu(subMenuLight0);

	glutAddMenuEntry("Ativar", 1);
	glutAddMenuEntry("Desativar", 2);

	sMenuLighting = glutCreateMenu(subMenuLighting);

	glutAddMenuEntry("Ativar", 1);
	glutAddMenuEntry("Desativar", 2);

	sMenuColorVideoGame = glutCreateMenu(subMenuColorVideoGame);

	glutAddMenuEntry("Cinza", 1);
	glutAddMenuEntry("Verde", 2);
	glutAddMenuEntry("Amarelo", 3);
	glutAddMenuEntry("Roxo", 4);

	sMenuBackgroundColor = glutCreateMenu(subMenuBackgroundColor);

	glutAddMenuEntry("Azul", 1);
	glutAddMenuEntry("Verde", 2);
	glutAddMenuEntry("Marrom", 3);
	glutAddMenuEntry("Vermelho", 4);

	glutCreateMenu(menuPrincipal);

	glutAddSubMenu("Resolução", sMenuResolution);
	glutAddSubMenu("frase do Display", sMenuChangeSetence);
	glutAddSubMenu("Cor do Video-Game ", sMenuColorVideoGame);
	glutAddSubMenu("Cor de Fundo ", sMenuBackgroundColor);
	glutAddSubMenu("Luz 0", sMenuLight0);
	glutAddSubMenu("Iluminação", sMenuLighting);
	glutAddMenuEntry("Sair", 0);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Animações
//--------------------------------------------------------------------------------------

void animationVideoGame(int value = 1)
{
	if (animationState == TRUE)
	{
		if (action == "up")
			height += 0.15f;
		else 
			height -= 0.15f;
		
		if (height > 7)
		{
			height = 7;
			action = "down";
		}

		if (height < 0)
		{
			height = 0.0f;
			action = "up";
		}

		glutPostRedisplay();

		glutTimerFunc(30, animationVideoGame, value);
	}
}

void animationDisplayVideoGame(int value = 1)
{
	if (animationState == TRUE)
	{
		R = rand() % 2;
		G = rand() % 2;
		B = rand() % 2;

		glutPostRedisplay();

		glutTimerFunc(100, animationDisplayVideoGame, value);
	}
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
	glShadeModel(GL_FLAT);

	makeCheckImage();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

#ifdef GL_VERSION_1_1
	glGenTextures(1, &texName);
	glBindTexture(GL_TEXTURE_2D, texName);
#endif

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
#ifdef GL_VERSION_1_1
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
		0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#else
	glTexImage2D(GL_TEXTURE_2D, 0, 4, checkImageWidth, checkImageHeight,
		0, GL_RGBA, GL_UNSIGNED_BYTE, checkImage);
#endif

	glutFullScreen();
	animationVideoGame();
	animationDisplayVideoGame();
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
	gluLookAt(30, -10, 25, 0, 0, 0, 0, 0, 1);
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
	}
}

void specialKeys(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_RIGHT:
			angle += 5.0f;

			if (angle >= 360.0f)
				angle = 0.0f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			angle -= 5.f;

			if (angle <= -360.0f)
				angle = 0.0f;
			glutPostRedisplay();
			break;
	}
}

void mouse(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) // pausa a animação
	{
		animationState = FALSE;
		glutPostRedisplay();
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) // retorna a animaação
	{
		animationState = TRUE;
		animationVideoGame();
		animationDisplayVideoGame();
		glutPostRedisplay();
	}
}

// Função Principal
//-------------------------------------------------------------------------------------

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(w, h);
	glutCreateWindow("Video-Game-3D");
	init();
	glutDisplayFunc(display);
	menuPopUp();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}