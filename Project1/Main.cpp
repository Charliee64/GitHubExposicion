//Fabi
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>//libreria opengl
#endif
GLfloat movY = 0, movX = 0, rotar = 0, tam = 0.0, escX = 0.3, escY = 0.3, escZ = 0.1;//variables de rotacion

//Carlos Daniel
void principal()//creamos la matriz
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Limpiamos pantalla y buffer
	glLoadIdentity();//cargamos los puntos
	glTranslated(movX, movY, 0.0);//translacion
	glRotatef(rotar, 0.1, 0.1, 0.0);//rotacion
	glScalef(escX, escY, escZ);//escalamiento
	glPushMatrix();//abrimos la matriz
	glutWireSphere(tam, 50, 50);//tamaño de la figura
	glPopMatrix();//cerramos matriz
	glFlush();//limpiamos 
	glutSwapBuffers();//limpiamos el buffer
}
//Paty
void movimiento(int keys, int x, int y)//Traslacion
{
	switch (keys)
	{	//MOVIMIENTO
	case GLUT_KEY_RIGHT://derecha
		movX += 0.1;
		break;
	case GLUT_KEY_LEFT://izquierda
		movX -= 0.1;
		break;
	case GLUT_KEY_UP://arriba
		movY += 0.1;
		break;
	case GLUT_KEY_DOWN://abajo
		movY -= 0.1;
		break;
	}
	glutPostRedisplay();// se maca el poligono en la ventana actual para volver a mostrarse.
}
//kevin
void aumentar(unsigned char pres, int x, int y)//rotacion y escalacion
{
	switch (pres)
	{
	case 'a'://rotar 
		rotar -= 4.1;
		break;
	case 's'://rotar
		rotar += 4.1;
		break;
	case 'j'://aumenta tamaño
		tam += 0.3;
		break;
	case 'k'://reduce tamaño
		tam -= 0.3;
		break;
	case 'u'://estirar en X
		escX += 0.1;
		break;
	case 'i'://estirar en Y
		escY += 0.1;
		break;
	case 'o'://estirar en Z
		escZ += 0.1;
		break;
	}
	glutPostRedisplay();//// se maca el poligono en la ventana actual para volver a mostrarse.
}
//Cindy
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);//Inicializar el glut
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);//colores de la pantalla
	glutInitWindowSize(800, 800);//tamaño de la pantalla
	glutInitWindowPosition(450, 150);//posicion de la pantalla
	glutCreateWindow("Transformaciones");//nombre de la pantalla
	glEnable(GL_DEPTH_TEST);//sea visible el grafico
	//Daley
	glutDisplayFunc(principal);//manda a llamar a la funcion donde se optiene la matriz 
	glutSpecialFunc(movimiento);//manda a llamar a la funcion donde se optiene la Traslacion
	glutKeyboardFunc(aumentar);//manda a llamar a la funcion donde se optiene la rotacion y escalacion
	glutMainLoop();//se repita el grafico en pantalla
	return 0;
}
/*
Integrates:
1.- Kevin Narvaez Corona

2.- Rosa Patricia Lucio Cruz

3.- Cindy Mercedes Bermúdez Castellanos

4.- Carlos Daniel López Hernández

5.- Roel Fabian Cruz Hernández

6.- Carlos Daley Navarro simuta
*/