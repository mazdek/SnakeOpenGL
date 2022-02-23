#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <atomic>

static GLfloat horizontalSpeed = 0.0f;
static GLfloat verticalSpeed = 0.0f;

#define UP 0;
#define LEFT 1;
#define DOWN 2;
#define RIGHT 3;

int direction;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f + horizontalSpeed, 0.0f + verticalSpeed);
        glVertex2f(0.0f + horizontalSpeed, 0.05f + verticalSpeed);
        glVertex2f(0.05f + horizontalSpeed, 0.05f + verticalSpeed);
        glVertex2f(0.05f + horizontalSpeed, 0.0f + verticalSpeed);
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int xmouse, int ymouse)
{
    switch (key){
		case 'w':
            direction = UP;
			break;
		case 'a':
            direction = LEFT;
		    break;
        case 's':
            direction = DOWN;
		    break;
        case 'd':
            direction = RIGHT;
            break;
		default:
            break;
	}
    std::cout << horizontalSpeed << " " << verticalSpeed << std::endl;
}

void move(int d)
{
    switch (direction){
        case 0:
            if (verticalSpeed >= 0.95f)
                verticalSpeed = -1.0f;
            else
                verticalSpeed += 0.005f;
            break;
        case 1:
            if (horizontalSpeed <= -1.0f)
                horizontalSpeed = 0.95f;
            else
                horizontalSpeed -= 0.005f;
            break;
        case 2:
            if (verticalSpeed <= -1.0f)
                verticalSpeed = 0.95f;
            else
                verticalSpeed -= 0.005f;
            break;
        case 3:
            if (horizontalSpeed >= 0.95f)
                horizontalSpeed = -1.0f;
            else
                horizontalSpeed += 0.005f;
            break;
        default:
            break;
	}

    glutPostRedisplay();
    glutTimerFunc(10, move, direction );
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, move, direction);
    
    glutMainLoop();
    return 0;
}