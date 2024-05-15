
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"
#include "menu.h"
#include "AI.h"

using namespace std;

void waitUntilKeyPressed() {
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

void processClick(int x, int y, Tictactoe& game) {
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
}

int main(int argc, char* argv[]) {
    Graphics graphics;
    graphics.init();

    bool quit = false;
    bool inGame = false;
    SDL_Event e;
    GameMode mode = MODE_NONE;


    SDL_Texture* menuBackground = graphics.loadTexture(BACKGROUND_IMG);
    TTF_Font* gFont = graphics.loadFont("assets/Purisa-BoldOblique.ttf", 40);
    SDL_Texture* menu = graphics.renderText("Menu:", gFont, {255, 192, 203, 0});
    SDL_Texture* Rule = graphics.renderText("Rules", gFont, {255, 192, 203, 0});
    SDL_Texture* Play = graphics.renderText("Play With Player", gFont, {255, 192, 203, 0});
    SDL_Texture* PlayWithAI = graphics.renderText("Play With AI", gFont, {255, 192, 203, 0});
    SDL_Texture* Rules = graphics.loadTexture("rules.png");


    // Main loop
    while (!quit) {
        if (!inGame) {
            showMenu(graphics, menuBackground, gFont, menu, Rule, Play, PlayWithAI);
             inGame = handleMenuEvents(e, quit, mode, graphics, Rules);
            graphics.presentScene();
        } else {
            Tictactoe game;
            game.init();
            ScrollingBackground background;
            background.setTexture(graphics.loadTexture(BACKGROUND_IMG));
            graphics.render(game);

            Mix_Chunk* click = graphics.loadSound("assets/sounds_click.wav");
            Mix_Chunk* endGame = graphics.loadSound("assets/sounds_endGame.wav");

            bool gamequit = false;
            bool endGameSoundPlayed = false;

            while (!gamequit && inGame) {
                while (SDL_PollEvent(&e)) {
                    switch (e.type) {
                        case SDL_QUIT:
                            gamequit = true;
                            quit = true; // Exit both game and menu
                            break;
                        case SDL_MOUSEBUTTONDOWN:
                            int x, y;
                            SDL_GetMouseState(&x, &y);
                            processClick(x, y, game);
                            graphics.play(click);
                            graphics.render(game);

                            if (mode == MODE_AI && !game.gameOver) {
                                Move bestMove = findBestMove(game);
                                game.move(bestMove.row, bestMove.col);
                                graphics.render(game);
                            }
                            break;
                        case SDL_KEYDOWN:
                            if (e.key.keysym.sym == SDLK_RETURN && game.gameOver) {
                                game.restart();
                                endGameSoundPlayed = false; // Reset flag for new game
                            }
                             else if (e.key.keysym.sym == SDLK_ESCAPE && game.gameOver) {
                                inGame = false; // Return to menu
                                gamequit = true;
                             }
                            break;

                }
                }

                background.scroll(3);
                graphics.render(background);
                graphics.render(game);

                // Check if the game is over and end game sound hasn't been played
                if (game.gameOver && !endGameSoundPlayed) {
                    graphics.play(endGame); // Play end game sound
                    endGameSoundPlayed = true; // Mark sound as played
                }

                graphics.presentScene();
                SDL_Delay(100);
            }

            if (click != nullptr) Mix_FreeChunk(click);
            if (endGame != nullptr) Mix_FreeChunk(endGame);

            inGame = false; // Return to menu after game ends
        }
    }

    graphics.quit();
     SDL_DestroyTexture(menuBackground);
    SDL_DestroyTexture(menu);
    SDL_DestroyTexture(Rule);
    SDL_DestroyTexture(Play);
    SDL_DestroyTexture(PlayWithAI);
     SDL_DestroyTexture(Rules);
    return 0;
}




