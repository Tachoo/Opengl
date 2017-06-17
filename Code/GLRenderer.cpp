#include "GLRenderer.h"
//
#define Shininess 1000.0f
//Global  for testing



float deltatime=1.0f;
void GLRenderer::testplane()
{
	
	
}
void GLRenderer::drawCube(float size)
{
	{
		glBegin(GL_QUADS);
		// front face
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, size / 2);
		// left face
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		// back face
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(size / 2, size / 2, -size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		// right face
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);
		// top face
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);
		// bottom face
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glEnd();
	}
}
GLRenderer::GLRenderer(void)
{
	
	
	m_hDC = NULL;
}

GLRenderer::~GLRenderer(void)
{
	
}

int GLRenderer::Inicializar(HDC _hdc, unsigned int _width, unsigned int _height)
{
	
	//almacenamos la referencia a la ventana
	m_hDC = _hdc;
	//Indicamos el tamaño de la ventana inicial
	Resize(_width, _height);
	//Color del fondo
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Limpeamos el background

	glMatrixMode(GL_PROJECTION);    //cargamos la matriz de proyeccion
	glLoadIdentity();   //movemos al origen la matriz de proyeccion

						//calculamos la relacion del aspecto de la ventana
	gluPerspective(52.0f, (GLfloat)_width / (GLfloat)_height, 1.0f, 1000.0f);
	
	glMatrixMode(GL_MODELVIEW); //cargmos la matrix del modelo
    glEnable(GL_DEPTH_TEST);// indicamos a opengl que tenga enuenta las posiciones y no el orden
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//      glEnable(GL_COLOR_MATERIAL);
	float dif[] = { 1.0,1.0,1.0,1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
	float amb[] = { 0.2,0.2,0.2,1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
	//
	  //glEnable(GL_COLOR_MATERIAL);
	//glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
	//

  return 0;
}

void GLRenderer::Resize(unsigned int _width, unsigned int _height)
{  
	


	//No puede tener un ancho de 0 la ventana //Seguridad
	if(0 == _width)
	{
		_width = 1;
	}
	//Igual la altura
	if(0 == _height)
	{
		_height = 1;
	}

	//Indicamos las dimensiones a OpenGL
	glViewport(0, 0, (GLsizei)_width, (GLsizei)_height);
}

void GLRenderer::Update(float _deltaTime)
{
	

}

void GLRenderer::Render()
{
	
	//Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glLoadIdentity();   //nos posisionamos en el centro
	gluLookAt(0, 0, -5,/*/Donde mira/*/0, 0, 0,/*/Donde esta parado/*/0, 1, 0/*/Que tanto esta despegado del suelo/*/); //Funcion LookAt algo confusa.
	glDisable(GL_LIGHTING);																												//
	//#pragma region MyRegion
	glColor3f(0.0, 0.0, 1.0);
	//glBegin(GL_TRIANGLES);

	//glVertex3f(-1.0, 0.0, 0.0); //P1
	//glVertex3f(0.0, -1.0, 0.0);  //P2
	//glVertex3f(1.0, 0.0, 0.0);  //P3

	//glEnd();  
#pragma endregion


	drawCube(1.0f);
	//Mostramos todo lo dibujado //BACK Buffer
	SwapBuffers(m_hDC);
}









