#include <SDL.h>
#include <SDL_image.h>
#include <entity.h>
#include <RenderWindow.h>
#include <vector>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

Entity Create_main_char(RenderWindow window)
{
    SDL_Surface* plane = IMG_Load("res/gfx/plane80.png");
    SDL_SetColorKey(plane, SDL_TRUE, SDL_MapRGB(plane -> format,0,0xFF,0xFF));
    SDL_Texture* plane_Texture = SDL_CreateTextureFromSurface(window.getRenderer(), plane);
    Entity Plane(SCREEN_WIDTH/3, SCREEN_HEIGHT/2, plane_Texture);
    Plane.setCurrentFlame(0, 0, 80*3/2, 46*3/2);
    Plane.setCoordinates(SCREEN_WIDTH/5,SCREEN_HEIGHT/3);
    return Plane;
}

std::vector<Entity> Create_enemy(RenderWindow window)
{
    SDL_Surface* enemy = IMG_Load("res/gfx/enemy.png");
    SDL_SetColorKey(enemy, SDL_TRUE, SDL_MapRGB(enemy -> format,0,0xFF,0xFF));
    SDL_Texture* enemy_Texture = SDL_CreateTextureFromSurface(window.getRenderer(), enemy);
    std::vector <Entity> Enemies =  {Entity(SCREEN_WIDTH, 0 + rand() % (SCREEN_HEIGHT*2/3 + 1 - 0), enemy_Texture),
                                Entity(SCREEN_WIDTH, SCREEN_HEIGHT/3 + rand() % (SCREEN_HEIGHT + 1 - SCREEN_HEIGHT/3), enemy_Texture),
                                Entity(SCREEN_WIDTH, SCREEN_HEIGHT/3 + rand() % (SCREEN_HEIGHT*2/3 + 1 - SCREEN_HEIGHT/3), enemy_Texture),
                                Entity(SCREEN_WIDTH, 0 + rand() % (SCREEN_HEIGHT + 1 - 0), enemy_Texture)
                               };
    for (int i=0;i<4;i++) Enemies[i].setCurrentFlame(0, 0, 80*3/2, 33*3/2);
    return Enemies;
}

Entity Create_bg(RenderWindow window)
{
    SDL_Texture* bg = window.load_texture("res/gfx/bg.png");
    Entity screen = Entity(0,0,bg);
    screen.setCurrentFlame(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    return screen;
}
