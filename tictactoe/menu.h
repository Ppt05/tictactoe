
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"

enum GameMode {
    MODE_NONE,
    MODE_PVP,
    MODE_AI
};

bool handleMenuEvents(SDL_Event& e, bool& quit, GameMode& mode, Graphics& graphics, SDL_Texture* Rules) {
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
            return false;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            if (x > 250 && y > 270 && x < 420 && y < 320) {
                mode = MODE_PVP; // Select PVP mode
                return true;
            } else if (x > 250 && y > 390 && x < 420 && y < 420) {
                mode = MODE_AI; // Select AI mode
                return true;
            } else if (x > 200 && y > 150 && x < 400 && y < 220) {

                graphics.prepareScene(Rules);
                graphics.presentScene();


                SDL_Event ruleEvent;
                bool backToMenu = false;
                while (!backToMenu) {
                    while (SDL_PollEvent(&ruleEvent)) {
                        if (ruleEvent.type == SDL_QUIT) {
                            backToMenu = true;
                        } else if (ruleEvent.type == SDL_MOUSEBUTTONDOWN) {
                            int rx, ry;
                            SDL_GetMouseState(&rx, &ry);
                            if (rx > 700 && ry > 5 && rx < 800 && ry < 100) {
                                backToMenu = true; // Return to menu
                            }
                        }
                    }
                }
            }
       }
    }
    return false;
}


void showMenu(Graphics& graphics,SDL_Texture * menuBackground , TTF_Font* gFont, SDL_Texture* menu, SDL_Texture* Rule, SDL_Texture* PlayPVP, SDL_Texture* PlayAI) {
    graphics.prepareScene( menuBackground);
    graphics.renderTexture(menu, 150, 30);
    graphics.renderTexture(Rule, 250, 150);
    graphics.renderTexture(PlayPVP, 250, 270);
    graphics.renderTexture(PlayAI, 250, 390);
    graphics.presentScene();
}

#endif // MENU_H
