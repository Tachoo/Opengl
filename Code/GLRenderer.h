#ifndef GLMANAGER_H
#define GLMANAGER_H
//Dependencias Esenciales
#include"../OpenGL Tutorial1/headersbase.h" //Opengl libs
#include"../OpenGL Tutorial1/localheaders.h"// local headers libs
class GLRenderer
{
	public:
		//

		//
		GLRenderer(void);
		//Inicia la ventana de OpenGL
		int Inicializar(HDC _hdc, unsigned int _width, unsigned int _height);
		//Funcion para notificar a OpenGL que se cambio el tamaño de la ventana
		void Resize(unsigned int _width, unsigned int _height);
		//El Update
		void Update(float _deltaTime);
		//Todo lo de dibujar
		void Render(void);
		//Funcion para inicializar Diferentes cosas en una sola
		
	private:
		objloader loader;
		//
		BaseWorld World;
		//PosicionLuz
		Cube  BaseObj;
		//Referencia de la ventana
		HDC m_hDC;
		
		
};
#endif