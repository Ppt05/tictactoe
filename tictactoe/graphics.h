
#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "defs.h"
#include "logic.h"



struct ScrollingBackground {
    SDL_Texture* texture;

    int scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }
};


/*struct Menu {
    SDL_Texture* texture, * backgroundTexture,*ruleButtonTexture, *playWithPlayerTexture, *rule;
    TTF_Font* font;



    int mouseX;
    int mouseY;


    void init(SDL_Renderer* renderer) {
        backgroundTexture = loadTexture(BACKGROUND_IMG, renderer);
        ruleButtonTexture = loadTexture("rule_button.png", renderer);
        playWithPlayerTexture = loadTexture("play_with_player_button.png", renderer);




        font = loadFont("assets/Purisa-BoldOblique.ttf", 40);
        SDL_Color color = {0, 0, 0, 0};
        rule  = renderText("The person whose three X or O points line up first is the winner", font, color);

      mouseX = 0;
      mouseY = 0;

    }

    void render(SDL_Renderer* renderer) {
        // Render background
        renderTexture(backgroundTexture, NULL, NULL, renderer);

        // Render buttons on top of the background
        renderTexture(ruleButtonTexture, 700, 200, renderer);
        renderTexture(playWithPlayerTexture, 400, 200, renderer);
    }
   void handleMouseEvent(SDL_Event& event) {
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            // Lấy tọa độ chuột khi click
            mouseX = event.button.x;
            mouseY = event.button.y;

            // Xử lý sự kiện click
            handleClick();
        }
    }

    void handleClick() {
        // Kiểm tra xem chuột được click vào nút nào và thực hiện hành động tương ứng
        if (mouseX >= 700 && mouseX <= 700 + BUTTON_WIDTH && mouseY >= 200 && mouseY <= 200 + BUTTON_HEIGHT) {
            // Click vào nút "rule"
            // Thực hiện hà
            renderTexture(rule, 200, 200);
        }
        } else if (mouseX >= 400 && mouseX <= 400 + BUTTON_WIDTH && mouseY >= 200 && mouseY <= 200 + BUTTON_HEIGHT) {

            // Click vào nút "play with player"
            // Thực hiện hành động tương ứng
        }
    }

};
    // Add additional methods as needed for handling button clicks, etc.
};*/


struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

    SDL_Texture *cellEmpty, *cellX, *cellO, *winX ,*winO, *draw, *X_Turn, *O_Turn;

    TTF_Font* font;

    void init() {
        initSDL();
        font = loadFont("assets/Purisa-BoldOblique.ttf", 40);
         SDL_Color color = {255, 192, 203, 0};
        X_Turn  = renderText("X_Turn", font, color);
        O_Turn  = renderText("O_Turn", font, color);



        cellEmpty = loadTexture("cell_empty.png");
        cellX = loadTexture("cell_x.png");
        cellO = loadTexture("cell_o.png");

        winX=loadTexture("win_x.png");
        winO=loadTexture("win_o.png");
        draw=loadTexture("draw.png");


    }

   void render(const Tictactoe& game) {
        //prepareScene();

        for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int x = BOARD_X + j * CELL_SIZE;
            int y = BOARD_Y + i * CELL_SIZE;
            switch (game.board[i][j]) {
                case EMPTY_CELL:
                    renderTexture(cellEmpty, x, y);  break;
                case X_CELL:
                    renderTexture(cellX, x, y);     break;
                case O_CELL:
                    renderTexture(cellO, x, y);     break;
            }
        }
    }

        if (game.gameOver) {

        if (game.checkWin(X_CELL)) {
            // Người chơi X chiến thắng
            renderTexture(winX, 500, 100);

        } else if (game.checkWin(O_CELL)) {
            // Người chơi O chiến thắng
            renderTexture(winO, 500, 100);

        } else if (game.isBoardFull()) {
            // Trò chơi hòa
            renderTexture(draw, 500, 100);



        }
    }

            if (game.nextMove == X_CELL)

                renderTexture(X_Turn, 100, 400);
             if (game.nextMove == O_CELL)
                renderTexture(O_Turn, 100, 400);

        presentScene();
    }

	void logErrorAndExit(const char* msg, const char* error)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
        SDL_Quit();
    }

	void initSDL() {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            logErrorAndExit("SDL_Init", SDL_GetError());

        window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        //full screen
        //window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (window == nullptr) logErrorAndExit("CreateWindow", SDL_GetError());

        if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
            logErrorAndExit( "SDL_image error:", IMG_GetError());

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
        //Khi chạy trong máy ảo (ví dụ phòng máy ở trường)
        //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));

        if (renderer == nullptr) logErrorAndExit("CreateRenderer", SDL_GetError());

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);


    if (TTF_Init() == -1) {
            logErrorAndExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }

  //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            logErrorAndExit( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        }

    }

	void prepareScene(SDL_Texture * background=nullptr)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopy( renderer, background, NULL, NULL);
    }


   void presentScene()
    {
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char *filename)
    {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

        SDL_Texture *texture = IMG_LoadTexture(renderer, filename);
        if (texture == NULL)
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load texture %s", IMG_GetError());

        return texture;
    }

    void renderTexture(SDL_Texture *texture, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

        SDL_RenderCopy(renderer, texture, NULL, &dest);
    }

    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y)
    {
        SDL_Rect dest;

        dest.x = x;
        dest.y = y;
        dest.w = src->w;
        dest.h = src->h;

        SDL_RenderCopy(renderer, texture, src, &dest);
    }



    void quit()
    {

        SDL_DestroyTexture( X_Turn );
        X_Turn= nullptr;
        SDL_DestroyTexture( O_Turn );
        O_Turn= nullptr;

        TTF_CloseFont( font );
        Mix_Quit();


        SDL_DestroyTexture(cellEmpty);
        cellEmpty = nullptr;
        SDL_DestroyTexture(cellX);
        cellX = nullptr;
        SDL_DestroyTexture(cellO);
        cellO = nullptr;

        SDL_DestroyTexture(winX);
        winX = nullptr;
        SDL_DestroyTexture(winO);
        winO = nullptr;
        SDL_DestroyTexture(draw);
        draw = nullptr;



        IMG_Quit();

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
         TTF_Quit();
    }
void render(const ScrollingBackground& background) {
        renderTexture(background.texture, background.scrollingOffset, 0);
        renderTexture(background.texture, background.scrollingOffset - background.width, 0);
    }

TTF_Font* loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }

    }

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;


    }
 Mix_Music *loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play(Mix_Music *gMusic)
    {
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }


};

#endif // _GRAPHICS__H




