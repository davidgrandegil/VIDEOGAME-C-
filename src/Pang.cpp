//////////////////////////////////////////////////////////////////////
// Autores: Álvaro Zornoza Uña 51540		
//			David Grande Gil 51249
// Asignatura: Informatica Industrial
// Trabajo: Juego Libre con OpenGL (glut)
// Título: "Are you a good shooter?"
// Tutor: Miguel Hernando Gutiérrez
// Fecha: 2º Cuatrimestre  Curso 2015/2016
//////////////////////////////////////////////////////////////////////

#include "Mundo.h"
#include <iostream>

Mundo elmundo;

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void OnSpecialKey(int key, int x, int y);
int winMain;

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	winMain=glutCreateWindow("Are you a good shooter? || David Grande y Alvaro Zornoza || ETSIDI-UPM (2016)");
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	//todas las paredes

	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKey);
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	elmundo.Dibuja();
}

void OnTimer(int value)
{
	glutTimerFunc(25,OnTimer,0);
	glutSetWindow(winMain);
	glutPostRedisplay();
	elmundo.Mover(0.06); 
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
	elmundo.TeclaDisparar(key,x,y);
	glutSetWindow(winMain);
	glutPostRedisplay();
}

void OnSpecialKey(int key, int x, int y)
{
	elmundo.TeclasMover(key,x,y);
	glutSetWindow(winMain);
	glutPostRedisplay();
}
