#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <entity.h>

class RenderWindow
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    RenderWindow(const char* path, int w, int h)
    {
        window = SDL_CreateWindow("Flying helicopter v0.3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    SDL_Renderer* getRenderer();
    void CleanUp();
    SDL_Texture* load_texture( const char *file);
    void clear();
    void render(Entity& p_entity);
    void display();

};

