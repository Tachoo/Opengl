#ifndef GLMANAGER_H
#define GLMANAGER_H
//Dependencias Esenciales
#include <Windows.h>
#include <GL/gl.h>
#include <gl\GLU.h>
class GLRenderer
{
    protected:

	public:		
		//Inicia la ventana de OpenGL
		int Inicializar(HDC _hdc, unsigned int _width, unsigned int _height);
		//Funcion para notificar a OpenGL que se cambio el tamaño de la ventana
		void Resize(unsigned int _width, unsigned int _height);
		//El Update
		void Update(float _deltaTime);
		//Todo lo de dibujar
		void Render(void);
		//	
		//constructor
		GLRenderer(void);
		//destructor
		~GLRenderer(void);
		//
	private:
		//Funciones Preset
		void initAll();
		//Referencia de la ventana
		HDC m_hDC;
};
#endif