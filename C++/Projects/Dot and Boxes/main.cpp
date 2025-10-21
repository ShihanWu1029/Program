#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

class dot_boxes_board {
private:
    int n; // size (n x n boxes -> (n+1)x(n+1) dots)
    vector<vector<bool>> hLines; // horizontal lines
    vector<vector<bool>> vLines; // vertical lines
    vector<vector<char>> boxes;  // store owner of boxes (' ', 'P', 'C')
    int playerScore, compScore;

public:
    dot_boxes_board(int size) : n(size) {
        hLines = vector<vector<bool>>(n + 1, vector<bool>(n, false));
        vLines = vector<vector<bool>>(n, vector<bool>(n + 1, false));
        boxes = vector<vector<char>>(n, vector<char>(n, ' '));
        playerScore = 0;
        compScore = 0;
        srand(time(nullptr));
    }

    void display() {
        cout << "\n   Player(P): " << playerScore << " | Computer(C): " << compScore << "\n\n";
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ".";
                if (hLines[i][j]) cout << "---";
                else cout << "   ";
            }
            cout << ".\n";
            if (i < n) {
                for (int j = 0; j < n + 1; ++j) {
                    if (vLines[i][j]) cout << "|";
                    else cout << " ";

                    if (j < n) cout << " " << boxes[i][j] << " ";
                }
                cout << "\n";
            }
        }
        cout << "\n";
    }

    bool isFull() {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (boxes[i][j] == ' ') return false;
        return true;
    }

    bool makeMove(int x, int y, char type, char player) {
        // type: 'h' or 'v'
        bool valid = false;
        if (type == 'h' && x >= 0 && x <= n && y >= 0 && y < n && !hLines[x][y]) {
            hLines[x][y] = true;
            valid = true;
        } else if (type == 'v' && x >= 0 && x < n && y >= 0 && y <= n && !vLines[x][y]) {
            vLines[x][y] = true;
            valid = true;
        }

        if (!valid) return false;

        bool scored = updateBoxes(player);
        return scored;
    }

    bool updateBoxes(char player) {
        bool scored = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (boxes[i][j] == ' ' && hLines[i][j] && hLines[i + 1][j] && vLines[i][j] && vLines[i][j + 1]) {
                    boxes[i][j] = player;
                    if (player == 'P') playerScore++;
                    else compScore++;
                    scored = true;
                }
            }
        }
        return scored;
    }

    pair<int,int> evaluateBox(int i, int j) {
        int count = 0;
        if (hLines[i][j]) count++;
        if (hLines[i + 1][j]) count++;
        if (vLines[i][j]) count++;
        if (vLines[i][j + 1]) count++;
        return {count, (boxes[i][j] == ' ')};
    }

    void computerMove() {
        // 1. Try to complete a box if possible
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                auto [cnt, empty] = evaluateBox(i, j);
                if (empty && cnt == 3) {
                    if (!hLines[i][j]) { makeMove(i, j, 'h', 'C'); return; }
                    if (!hLines[i + 1][j]) { makeMove(i + 1, j, 'h', 'C'); return; }
                    if (!vLines[i][j]) { makeMove(i, j, 'v', 'C'); return; }
                    if (!vLines[i][j + 1]) { makeMove(i, j + 1, 'v', 'C'); return; }
                }
            }
        }

        // 2. Avoid giving boxes to player (avoid 3-sided boxes)
        vector<tuple<int,int,char>> safeMoves;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < n; ++j)
                if (!hLines[i][j] && !creates3Sided(i, j, 'h')) safeMoves.push_back({i,j,'h'});
        for (int i = 0; i < n; ++i)
            for (int j = 0; j <= n; ++j)
                if (!vLines[i][j] && !creates3Sided(i, j, 'v')) safeMoves.push_back({i,j,'v'});

        if (!safeMoves.empty()) {
            auto [x,y,t] = safeMoves[rand() % safeMoves.size()];
            makeMove(x, y, t, 'C');
        } else {
            // if no safe moves, pick random
            vector<tuple<int,int,char>> allMoves;
            for (int i = 0; i <= n; ++i)
                for (int j = 0; j < n; ++j)
                    if (!hLines[i][j]) allMoves.push_back({i,j,'h'});
            for (int i = 0; i < n; ++i)
                for (int j = 0; j <= n; ++j)
                    if (!vLines[i][j]) allMoves.push_back({i,j,'v'});
            if (!allMoves.empty()) {
                auto [x,y,t] = allMoves[rand() % allMoves.size()];
                makeMove(x, y, t, 'C');
            }
        }
    }

    bool creates3Sided(int x, int y, char t) {
        // simulate placing a line and check if it makes a 3-side box
        bool result = false;
        vector<vector<bool>> h = hLines, v = vLines;
        if (t == 'h') h[x][y] = true;
        else v[x][y] = true;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                if (h[i][j]) cnt++;
                if (h[i+1][j]) cnt++;
                if (v[i][j]) cnt++;
                if (v[i][j+1]) cnt++;
                if (boxes[i][j]==' ' && cnt==3) result = true;
            }
        return result;
    }

    void play() {
        cout << "\nWelcome to Dot and Boxes!";
        cout << "\nYou will play as P. Enter moves like: h 0 1 for horizontal or v 1 2 for vertical line.\n";
        bool playerTurn = true;

        while (!isFull()) {
            display();
            if (playerTurn) {
                cout << "Your move (type row col): ";
                char t; int x, y; cin >> t >> x >> y;
                bool scored = makeMove(x, y, t, 'P');
                if (!scored) playerTurn = false;
            } else {
                cout << "Computer's move...\n";
                bool scored = true;
                while (scored) {
                    scored = false;
                    computerMove();
                    display();
                    if (updateBoxes('C')) scored = true;
                    if (!isFull() && scored) cout << "Computer gets another turn!\n";
                }
                playerTurn = true;
            }
        }
        display();
        cout << "Game Over!\n";
        if (playerScore > compScore) cout << "You win!\n";
        else if (playerScore < compScore) cout << "Computer wins!\n";
        else cout << "It's a draw!\n";
    }
};

int main() {
    int n;
    cout << "Enter board size (recommended 3-5): ";
    cin >> n;
    dot_boxes_board game(n);
    game.play();
    return 0;
}