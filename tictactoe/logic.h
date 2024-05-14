
#ifndef _LOGIC__H
#define _LOGIC__H
#include <iostream>

#define BOARD_SIZE 3
#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'



using namespace std;
/*struct Menu {
    SDL_Texture* texture, * backgroundTexture,*ruleButtonTexture,*playWithAITexture, *playWithPlayerTexture, *rule;
    TTF_Font* font;



    int mouseX;
    int mouseY;


    void init(SDL_Renderer* renderer) {
        backgroundTexture = loadTexture(BACKGROUND_IMG, renderer);
        ruleButtonTexture = loadTexture("rule_button.png", renderer);
        playWithAITexture = loadTexture("play_with_ai_button.png", renderer);
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
        renderTexture(playWithAITexture, 500, 200, renderer);
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
            renderTexture(X_Turn, 200, 200);
        } else if (mouseX >= 500 && mouseX <= 500 + BUTTON_WIDTH && mouseY >= 200 && mouseY <= 200 + BUTTON_HEIGHT) {
            // Click vào nút "play with AI"
            // Thực hiện hành động tương ứng
        } else if (mouseX >= 400 && mouseX <= 400 + BUTTON_WIDTH && mouseY >= 200 && mouseY <= 200 + BUTTON_HEIGHT) {
            // Click vào nút "play with player"
            // Thực hiện hành động tương ứng
        }
    }

    // Các phương thức khác cũng có thể được thêm vào để xử lý các sự kiện khác như hover, etc.
};
    // Add additional methods as needed for handling button clicks, etc.
};*/




struct Tictactoe {
    char board[BOARD_SIZE][BOARD_SIZE];
    char nextMove = O_CELL;
    bool gameOver = false; // Biến cờ theo dõi trạng thái của trò chơi

    void init() {
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++) board[i][j] = EMPTY_CELL;
    }

    void reset() {
        init();
        nextMove = O_CELL;
        gameOver = false; // Đặt lại trạng thái của trò chơi về chưa kết thúc
    }

    bool isBoardFull() const{
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
                if (board[i][j] == EMPTY_CELL) return false;
        return true;
    }

    bool isValidMove(int row, int column) {
        return row >= 0 && row < BOARD_SIZE && column >= 0 && column < BOARD_SIZE && board[row][column] == EMPTY_CELL;
    }

    bool checkWin(char player) const{
        // Kiểm tra các hàng
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        }
        // Kiểm tra các cột
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player) return true;
        }
        // Kiểm tra đường chéo chính
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
        // Kiểm tra đường chéo phụ
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
        return false;
    }

   void move(int row, int column) {
    if (!gameOver && isValidMove(row, column))
    {
        board[row][column] = nextMove;
        if (checkWin(nextMove)) {
            // Announce winner here and end the game
            cout << "Player " << nextMove << " wins!" << endl;
            gameOver = true;
        } else if (isBoardFull()) {
            // Announce draw if the board is full and no one wins, and end the game
            cout << "It's a draw!" << endl;
            gameOver = true;
        } else {
            nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
        }
    }
}

void restart() {
    init(); // Khởi tạo lại bảng
    nextMove = O_CELL; // Đặt lại người chơi là O
    gameOver = false; // Đặt lại trạng thái game là chưa kết thúc
    }
};



/*void makeAIMove() {
        int bestScore = -INFINITY;
        int bestMoveRow = -1;
        int bestMoveCol = -1;

        // Lặp qua mọi ô trên bảng cờ
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                // Nếu ô đó trống
                if (board[i][j] == EMPTY_CELL) {
                    // Thử nước đi này
                    board[i][j] = AI_PLAYER;
                    int score = minimax(board, 0, false);
                    // Undo nước đi
                    board[i][j] = EMPTY_CELL;
                    // Lưu nước đi có điểm số tốt nhất
                    if (score > bestScore) {
                        bestScore = score;
                        bestMoveRow = i;
                        bestMoveCol = j;
                    }
                }
            }
        }
        // Thực hiện nước đi tốt nhất của AI
        move(bestMoveRow, bestMoveCol);

    }// Hàm Minimax
int minimax(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool isMaximizingPlayer) {
    // Kiểm tra trạng thái kết thúc của trò chơi và trả về điểm số tương ứng
    int score = evaluate(board);
    if (score != 0) {
        return score;
    }

    // Nếu không còn ô trống hoặc đã đạt đến độ sâu tối đa, trả về 0
    if (isBoardFull(board) || depth == MAX_DEPTH) {
        return 0;
    }

    // Nếu lượt chơi là của AI (Maximizer)
    if (isMaximizingPlayer) {
        int bestScore = -INFINITY;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    // Thử nước đi này
                    board[i][j] = AI_PLAYER;
                    int score = minimax(board, depth + 1, false);
                    // Undo nước đi
                    board[i][j] = EMPTY_CELL;
                    // Lưu điểm số tốt nhất
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    } else { // Nếu lượt chơi là của người chơi (Minimizer)
        int bestScore = INFINITY;
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    // Thử nước đi này
                    board[i][j] = HUMAN_PLAYER;
                    int score = minimax(board, depth + 1, true);
                    // Undo nước đi
                    board[i][j] = EMPTY_CELL;
                    // Lưu điểm số tốt nhất
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

// Hàm đánh giá (evaluation function)
int evaluate(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Kiểm tra chiến thắng của AI
    if (checkWin(board, AI_PLAYER)) {
        return 10;
    }
    // Kiểm tra chiến thắng của người chơi
    else if (checkWin(board, HUMAN_PLAYER)) {
        return -10;
    }
    // Trả về 0 nếu không có ai chiến thắng
    return 0;
}*/





#endif

