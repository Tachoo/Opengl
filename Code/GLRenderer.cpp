#include "GLRenderer.h"

GLRenderer::GLRenderer(void)
{
	
	//
	m_hDC = NULL;
}

GLRenderer::~GLRenderer(void)
{
	
}

void GLRenderer::initAll()
{
	//llamar las demas funciones de  Puntos , Modelos , espacios etc...

	//Plano del piso
	
	//Planos de colisiones
	
	//Jugador
	
	//Puntos

}

int GLRenderer::Inicializar(HDC _hdc, unsigned int _width, unsigned int _height)
{
	//almacenamos la referencia a la ventana
	m_hDC = _hdc;
	//Indicamos el tamaño de la ventana inicial
	Resize(_width, _height);
	//Color del fondo
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Limpeamos el background
    //
	glMatrixMode(GL_PROJECTION);    //cargamos la matriz de proyeccion
	glLoadIdentity();   //movemos al origen la matriz de proyeccion
	gluPerspective(52.0f, (GLfloat)_width / (GLfloat)_height, 1.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW); //cargmos la matrix del modelo
    glEnable(GL_DEPTH_TEST);// indicamos a opengl que tenga enuenta las posiciones y no el orden
	
	
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

void GLRenderer::Update(float _deltaTime)//-->> El tiempo de muestra es de 3.25-0
{

}

void GLRenderer::Render()
{
	 //Limpiamos pantalla
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//[1,0,0]
	//[0,1,0]
	//[0,0,1]
	glLoadIdentity();   
	gluLookAt(-2, 5, -5,/*/Donde mira/*/0, 0, 0,/*/Donde esta parado/*/0, 1, 0/*/Que tanto esta despegado del suelo/*/); //Funcion LookAt algo confusa.
	 //

	 //
	SwapBuffers(m_hDC);
}










