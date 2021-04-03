#include <GL/freeglut.h> 
#include <stdlib.h> 

constexpr auto cWindowWidth = 640;
constexpr auto cWindowHeight = 480;

int x, y;
float r, g, b;

void idle()
{                    
    x = rand()%cWindowWidth; 
    y = rand()%cWindowHeight;

    r=(float)((rand() % 9))/8;
    g=(float)((rand() % 9))/8;
    b=(float)((rand() % 9))/8;

    glutPostRedisplay();
}

void magic_dots(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, cWindowWidth, 0.0, cWindowHeight);

	glColor3f(r,g,b); 	

	glBegin(GL_POINTS);
	glVertex2i (x,y);
	glEnd();

	glFlush();	
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(cWindowWidth, cWindowHeight);
	glutCreateWindow("Randomly generated points");
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(magic_dots);
	glutIdleFunc(idle);
	glutMainLoop();
	
	return 0;
}