#ifndef GLMANAGER_H
#define GLMANAGER_H
//Dependencias Esenciales
#include <Windows.h>
#include <GL/gl.h>
#include <gl\GLU.h>
#include <vector>
#include<iostream>

class GLRenderer
{
	public:
		//
		void testplane();
		void drawCube(float size);
		
		//
		GLRenderer(void);
		~GLRenderer(void);
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
		//Vector de esferas
		
		//
		
		//Referencia de la ventana
		HDC m_hDC;
		
		
};
#endif