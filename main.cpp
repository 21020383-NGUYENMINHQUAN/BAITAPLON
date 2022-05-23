#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include <entity.h>
#include <RenderWindow.h>
#include <Create_entity.h>

using namespace std;

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SPAWN_TIME 2
#define MAX_LEVEL 5

void GameOver(RenderWindow win)
{
    SDL_Texture* endgame = win.load_texture("res/gfx/game-over.png");
    Entity EndGame = Entity(0,0,endgame);
    EndGame.setCurrentFlame(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    win.render(EndGame);
    win.display();
}


void respawn(Entity &Enemies, int num)
{
    if (num<2) Enemies.setCoordinates(SCREEN_WIDTH, 0 + rand() % (SCREEN_HEIGHT/2 + 1 - 0));
    else Enemies.setCoordinates(SCREEN_WIDTH, SCREEN_HEIGHT/2 + rand() % (SCREEN_HEIGHT-40 + 1 - SCREEN_HEIGHT/2));

}
void main_program(RenderWindow window);

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return 1;


    bool Gameloop=1;
    while (Gameloop){
        RenderWindow window("Flying helicopter v0.4", SCREEN_WIDTH, SCREEN_HEIGHT);
        main_program(window);
        SDL_Event ev;
        while (true){
            while (SDL_PollEvent(&ev))
            {
                if (ev.type == SDL_QUIT)
                    Gameloop=0;
            }
            GameOver(window);
            const Uint8* keystates = SDL_GetKeyboardState(NULL);
            if (keystates[SDL_SCANCODE_SPACE]) break;
            else if (keystates[SDL_SCANCODE_ESCAPE]) { Gameloop = 0; break;}
        }
        window.CleanUp();
        SDL_Quit();
    }
}

void main_program(RenderWindow window)
{
    int level_present = 1;

    Entity Plane = Create_main_char(window);

    vector <Entity> Enemies = Create_enemy(window);

    Entity screen = Create_bg(window);
    //Entity cot;


    bool GameRunning=true;
    SDL_Event event;
    int enemy_num = 0;
    int score = 0;
    while (GameRunning)
    {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
            {
                GameRunning=0;
            };

        float running_time = SDL_GetTicks()/1000;

        window.clear();
        window.render(screen);
        window.render(Plane);

        for (enemy_num=0;enemy_num<Enemies.size();enemy_num++)
        {
            srand(SDL_GetTicks());

            bool spawn_next_enemy = 0;
            if (running_time - SPAWN_TIME * (enemy_num + 1) >= 0)
                spawn_next_enemy = 1;

            if (Enemies[enemy_num].GetX() >= 0)
            {
                if (spawn_next_enemy)
                {
                    window.render(Enemies[enemy_num]);
                    Enemies[enemy_num].setCoordinates(Enemies[enemy_num].GetX()- level_present , Enemies[enemy_num].GetY());
                    if (abs(Plane.GetX() - Enemies[enemy_num].GetX())<=80 && abs(Plane.GetY() - Enemies[enemy_num].GetY())<=45)
                    {
                        GameRunning=0;
                    }
                }
            }
            else
            {
                respawn(Enemies[enemy_num], enemy_num);
                score++;
            }
        }

        if (score - level_present*5 == 0 && level_present < MAX_LEVEL) {level_present++;}
        cout<<"Score:"<<score<<"   level:"<<level_present<<"\n";
        SDL_Delay(5);

        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        if ((keystates[SDL_SCANCODE_SPACE] || keystates[SDL_SCANCODE_UP]) && Plane.GetY()>=0)
            {Plane.setCoordinates(Plane.GetX(), Plane.GetY()-5);SDL_Delay(1);}
        else if (running_time >= 2) Plane.setCoordinates(Plane.GetX(), Plane.GetY()+3);SDL_Delay(1);

        window.render(Plane);

        window.display();
        if(Plane.GetY()>=SCREEN_HEIGHT) {GameRunning=0;}
    }
    window.display();
}
