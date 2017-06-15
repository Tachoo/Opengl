#include "Cube.h"



void Cube::Draw(float size)
{
	float difamb[] = { 1.0,0.5,0.3,1.0 };
	glBegin(GL_QUADS);
	// front face
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, difamb);
	// left face

	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(-size / 2, size / 2, -size / 2);
	// back face
	// right face
	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(size / 2, size / 2, size / 2);
	glVertex3f(size / 2, -size / 2, size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, size / 2, -size / 2);
	// top face
	// bottom face
	glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glEnd();
}

Cube::Cube()
{
}


Cube::~Cube()
{
}
