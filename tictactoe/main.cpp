#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "logic.h"



using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void processClick(int x, int y, Tictactoe& game) {
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    game.move(clickedRow, clickedCol);
}

int main(int argc, char *argv[])
{

    Graphics graphics;
    graphics.init();

    SDL_Texture*Menu = graphics.loadTexture(BACKGROUND_IMG);
    graphics.prepareScene(Menu);


    TTF_Font *gFont = graphics.loadFont("assets/Purisa-BoldOblique.ttf", 30);
    SDL_Color color ={238,169,184,0};

    SDL_Texture* menu = graphics.renderText("Welcome to my game",gFont,color);
    graphics.renderTexture(menu,200 ,30);

    SDL_Texture* Rule = graphics.renderText("Rule",gFont,color);
    graphics.renderTexture(Rule,320 ,150);

    SDL_Texture* Play = graphics.renderText("Play",gFont,color);
    graphics.renderTexture(Play,320 ,270);

    SDL_Texture* Exit = graphics.renderText("Exit",gFont,color);
    graphics.renderTexture(Exit,320 ,390);






    graphics.presentScene();
    waitUntilKeyPressed();

    bool quit = false;
    bool inGame = false;
     SDL_Event e;
    while (!quit) {
        SDL_PollEvent(&e);
        switch (e.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                int x,y;
                SDL_GetMouseState(&x, &y);
                if(x >320 && y> 270 && x <350 && y <300){
                        inGame= true;
                }
                 if(x >320 && y> 390&& x <350 && y <420){
                        quit=true;
                 }

                break;
                }

    }
   /* while (!quit){
    while(SDL_PollEvent(&e)!=0){
        if(e.type==SDL_QUIT){
            quit =true;
        }
        else if(e.type == SDL_MOUSEBUTTONDOWN){
            int X,Y;
            SDL_GetMousetate(&X,&Y);

            if(X<=350 && X<=380 && Y>=200 && Y<=)
        }
    }*/
if(inGame){

    Tictactoe game;
    game.init();
    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));
    graphics.render(game);

    Mix_Chunk *click=graphics.loadSound("assets\\sounds_click.wav");
    Mix_Chunk *endGame = graphics.loadSound("assets\\sounds_endGame.wav");


    int x, y;
    SDL_Event event;
    bool gamequit = false;
    bool endGameSoundPlayed = false;

        while (!gamequit){SDL_PollEvent(&event);
            switch (event.type) {
                case SDL_QUIT:
                    gamequit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    SDL_GetMouseState(&x, &y);
                    processClick(x, y, game);
                    graphics.play(click);
                    graphics.render(game);
                    break;
                case SDL_KEYDOWN:


                if (event.key.keysym.sym == SDLK_RETURN&& game.gameOver) {
                    game.restart();
                     endGameSoundPlayed = false; // Reset biến khi bắt đầu trò chơi mới

                }
                break;

        }

        background.scroll(3);
        graphics.render(background);
        graphics.render(game);

        // Kiểm tra nếu trò chơi kết thúc và âm thanh "end game" chưa được phát
        if (game.gameOver && !endGameSoundPlayed) {
            graphics.play(endGame); // Phát âm thanh "end game"
            endGameSoundPlayed = true; // Đánh dấu rằng âm thanh đã được phát
        }


        graphics.presentScene();
        SDL_Delay(100);
    }

if (click != nullptr) Mix_FreeChunk( click);
if (endGame != nullptr) Mix_FreeChunk(endGame);



    graphics.quit();

    return 0;
}
}
