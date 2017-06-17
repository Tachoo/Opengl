#include "BaseWorld.h"



void BaseWorld::Draw(float size)
{	
		float difamb[] = { 1,1,1,1.0 };/*Creo que es gris*/
		glBegin(GL_QUADS);
		// front face
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);

		glNormal3f(1.0, 0.0, 0.0);
		glVertex3f(-size / 2, size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(-size / 2, size / 2, -size / 2);
		// back face
		// right face
		glNormal3f(-1.0, 0.0, 0.0);
		glVertex3f(size / 2, size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, size / 2, -size / 2);
		// top face
		// bottom face
		glNormal3f(0.0, 1.0, 0.0);
		glVertex3f(size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, size / 2);
		glVertex3f(-size / 2, -size / 2, -size / 2);
		glVertex3f(size / 2, -size / 2, -size / 2);
		glEnd();
}

BaseWorld::BaseWorld()
{
}


BaseWorld::~BaseWorld()
{
}
