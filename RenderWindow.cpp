#include <SDL.h>
#include <SDL_image.h>
#include <entity.h>
#include <iostream>
#include "RenderWindow.h"


    SDL_Renderer* RenderWindow::getRenderer(){
        return renderer;
    }

    void RenderWindow::CleanUp()
    {
        SDL_DestroyWindow(window);
    }

    SDL_Texture* RenderWindow::load_texture( const char *file)
    {
        SDL_Texture *texture = NULL;
        texture = IMG_LoadTexture(renderer, file);
        if (texture == NULL) std::cout<<"cannot open file, error: "<<SDL_GetError()<<std::endl;
        else std::cout<<"open file success"<<std::endl;
        return texture;
    }

    void RenderWindow::clear()
    {
        SDL_RenderClear(renderer);
    }


    void RenderWindow::render(Entity& p_entity)
    {
        SDL_Rect src;
        src.x = p_entity.GetCurrentFrame().x;
        src.y = p_entity.GetCurrentFrame().y;
        src.w = p_entity.GetCurrentFrame().w;
        src.h = p_entity.GetCurrentFrame().h;

        SDL_Rect dst;
        dst.x = p_entity.GetX();
        dst.y = p_entity.GetY();
        dst.w = p_entity.GetCurrentFrame().w;
        dst.h = p_entity.GetCurrentFrame().h;
        SDL_RenderCopy(renderer, p_entity.GetTex(), &src, &dst);
    }

    void RenderWindow::display()
    {
        SDL_RenderPresent(renderer);
    }
