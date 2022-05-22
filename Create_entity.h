#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <entity.h>
#include <RenderWindow.h>
#include <bits/stdc++.h>

Entity Create_main_char(RenderWindow window);
std::vector <Entity> Create_enemy(RenderWindow window);
Entity Create_bg(RenderWindow window);
