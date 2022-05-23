#include "entity.h"
#include <SDL.h>
#include <SDL_image.h>

void Entity::setCoordinates(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

void Entity::setCurrentFlame(float current_x, float current_y, float current_w, float current_h)
    {
        currentFrame.x = current_x;
        currentFrame.y = current_y;
        currentFrame.w = current_w;
        currentFrame.h = current_h;
    }

float Entity::GetX(){
	return x;
}

float Entity::GetY(){
	return y;
}

SDL_Texture* Entity::GetTex()
{
	return tex;
};
SDL_Rect Entity::GetCurrentFrame()
{
	return currentFrame;
};
