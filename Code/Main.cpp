#include <Windows.h>
#include <iostream>
#include "resource.h"
#include "GLRenderer.h"
using namespace std;
//Nombre de la venta
#define WINDOW_TITLE "2do Examen OpenGL"

//Nombre de la ventana
#define WINDOW_CLASS WINDOW_TITLE " Class"

//Ancho y alto de la vetana
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
//Podriamos usar un point para sacar la posicion de el raton
POINTS MousePos;

//OpenGL
GLRenderer *g_pGLRenderer(NULL);

//Funcion que se encargara de los mensajes de la ventana
LRESULT CALLBACK MensajesWindows(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{   
		/*Caso para Cerrar o terminar el proceso directamente*/
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
///Detectar los eventos del Raton
		//Caso cuando se presiona  el boton izquierdo del raton
	case WM_LBUTTONDOWN:

		MousePos = MAKEPOINTS(lParam);
		
		/**/

		/**/

		break;
		//Caso cuando se presiona  el boton Derecha del raton
	case WM_RBUTTONDOWN:

		break;
		//Caso cuando y se presiona un boton del raton  y se mueve a la vez
	case WM_MOUSEMOVE:
		//GetCursorPos(&aPoint);
		switch (wParam)
		{
		case MK_LBUTTON:
		//	g_pGLRenderer->value += 1;
			//std::cout << "Izquierda" + g_pGLRenderer->value;
			break;
		case MK_RBUTTON:
			//g_pGLRenderer->value -= 1;
			//std::cout <<" Derecha" + g_pGLRenderer->value;
			break;

		default:
			break;
		}
		break;

		/*Caso del Keyboard*/
	case WM_KEYDOWN:
		switch(wParam)
		{ 
		case VK_NUMPAD0:// se cierra con el Numero 0
		case VK_ESCAPE: //se cierra con el teclado 'esc'
				PostQuitMessage(0);
				break;
		case WM_KEYDOWN:
			if(wParam==VK_SPACE)
			{
				
			}
			else
			{
				char ltr[2];
				GetKeyNameText(lParam, (LPSTR)ltr, 2);
				if (ltr[0]=='q'||ltr[1]=='Q')
				{
					// A qui aumentar el valor atravez de un puntero g_pGLRenderer->
				}
			}
			break;
			//
			default:
				break;
		}
		break;
	default:
		break;
	}

	return (DefWindowProc(hwnd, message, wParam, lParam));
}

void SetupPixelFormat(HDC hDC)
{
	//prepara ventana para funcionar con OpenGLy
	PIXELFORMATDESCRIPTOR pfd;
	//Tama�o
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	//Version
	pfd.nVersion = 1;
	//Ventana dibujable, con soporte a OpenGl y necesita BackBuffer
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	//Colores en ventana
	pfd.iPixelType = PFD_TYPE_RGBA;
	//24 bits de color
	pfd.cColorBits = 24;
	//profundidad de color
	pfd.cDepthBits = 16;
	
	//Asignaos el formato de colores
	int pixelFormat(ChoosePixelFormat(hDC, &pfd));
	SetPixelFormat(hDC, pixelFormat, &pfd);
}

//Codigo de ventana
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prev, LPSTR cmd, int show)
{	   
	//Estructura de la ventana
	WNDCLASSEX windowClass;

	//En visual studio se tiene que inicializar ventana
	memset(&windowClass, 0, sizeof(WNDCLASSEX));

	windowClass.cbSize = sizeof(WNDCLASSEX);		//Tama�o de estructura
	windowClass.style = CS_HREDRAW | CS_VREDRAW;	
	windowClass.lpfnWndProc = MensajesWindows;			//Funcion  que se encargara de ventanas
	windowClass.hInstance = hInstance;			//Handle to the window's instance
	windowClass.hIcon = NULL;	//Icono del proyecto
	windowClass.hIconSm = NULL;//Icono
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);//Cursos
	windowClass.hbrBackground = (HBRUSH) COLOR_ACTIVEBORDER;//Color de ventana de activo
	windowClass.lpszClassName = WINDOW_CLASS;			//Nombre de clases

	//Registramos la clase
	if(!RegisterClassEx(&windowClass))
	{
		//ya esta registrado
		return -1;
	}

	//Creamos ventana
	HWND hwnd(CreateWindowEx(NULL, WINDOW_CLASS, WINDOW_TITLE, WS_OVERLAPPEDWINDOW, 100, 100,
							WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0, hInstance, NULL));
   
	//Ventana se pudo crear?
	if(!hwnd)
	{
		return -1; //Error al crear ventana
	}
  
	//Obtenemos el HDC
	HDC hDC(GetDC(hwnd));
	//Ajustamos pixeles para OpenGL
	SetupPixelFormat(hDC);

	//Creamos HDC de OpenGL
	HGLRC hRC(wglCreateContext(hDC));

	//Se pudo?
	if(NULL == hRC)
	{
		return -1;
	}

	//Ligamos los HDC de ventana y openGL
	if(!wglMakeCurrent(hDC, hRC))
	{
		//Exit the program
		return -1;
	}

	//Creamos OpenGL
	g_pGLRenderer = new GLRenderer();

	//Mostramos ventana
	ShowWindow(hwnd, SW_SHOW);
  
	//Estructura de mensajes
	MSG msg;
  
	//obtenemos tama�o de ventana
	RECT windowRect;
	GetClientRect(hwnd, &windowRect);

	//Cremaos OpenGL
	if(g_pGLRenderer->Inicializar(hDC, windowRect.right, windowRect.bottom) == 0)
	{

		//Muestra tiempo
		float ultimaMuestra = (float)timeGetTime(); //La primer muestra de tiempo

		//GameLoop
		while(true)
		{
			//Hubo mensaje?
			if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				//Se intenta salir, salimos del whle
				if(WM_QUIT == msg.message) 
				{
					break;
				}

				//Procesamos mensaeje
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				}
			else
			{

				//Tomamos una muestra del tiempo actual
	            float actualMuestra = (float)timeGetTime();
	            //calculamos el cambio del tiempo en segundos
	            float deltaTiempo = (actualMuestra - ultimaMuestra)* 0.001f;



				g_pGLRenderer->Update(deltaTiempo);
				//Dibujamos OpenGL
				g_pGLRenderer->Render();

				ultimaMuestra = actualMuestra; //reestablecemos la mestra de tiempo
			}
		}		
	}

	//Destuimos y liberamos memoria
	delete g_pGLRenderer; 
	wglMakeCurrent(hDC, NULL);
	wglDeleteContext(hRC);
	UnregisterClass(WINDOW_CLASS, windowClass.hInstance);

	return (int) msg.wParam;
}