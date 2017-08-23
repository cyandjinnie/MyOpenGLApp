#ifndef __DRAWABLE_OBJECT_H__
#define __DRAWABLE_OBJECT_H__

#include "Entity.h"

class DrawableObject : public Entity
{
public:
	DrawableObject();
	virtual ~DrawableObject();

	virtual void draw() = 0;
private:

	// TODO: VBO, VAO, VEO, Shader programs, etc
};

#endif