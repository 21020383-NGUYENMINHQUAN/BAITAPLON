#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Entity
{
private:
    float x,y;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex)
    {
        x=p_x;
        y=p_y;
        tex=p_tex;
        currentFrame.x = 1280/4;
        currentFrame.y = 720/4;
        currentFrame.w = 80;
        currentFrame.h = 46;
    };

    void setCoordinates(float x, float y);

    void setCurrentFlame(float current_x, float current_y, float current_w, float current_h);

    float GetX();

    float GetY();

    SDL_Texture* GetTex();

    SDL_Rect GetCurrentFrame();
};

//void Spawn_Enemy(vector <Entity> Enemies, )
