#include <vector>
#include <string>

/**
 * Status codes:
 * 0: empty
 * 1: up
 * 2: right
 * 3: down
 * 4: left
 * 5: box for player 1
 * 6: box for player 2
 */

class Dot_boxes_board{
    private:
        int row,column,scoreA,scoreB;
        std::vector<std::vector<std::string>> board;
    public:
        Dot_boxes_board(int r,int c):row(r),column(c){
            board.resize(row);
            for(auto &i : board)
                i.resize(column,"0");
            scoreA = 0;
            scoreB = 0;
        }
        ~Dot_boxes_board(){
            delete &board;
        }
        bool add(int r,int c,std::string status,int player){
            if(board[r][c].find(status) == board[r][c].npos)
                return false;
            board[r][c] += status;
            if(status == "1")
                board[r-1][c] += "3";
            else if(status == "2")
                board[r][c+1] += "4";
            else if(status == "3")
                board[r+1][c] += "1";
            else if(status == "4")
                board[r][c-1] += "2";
            if((board[r][c].find("1") != std::string::npos)&&(board[r][c].find("2") != std::string::npos)&&(board[r][c].find("3") != std::string::npos)&&(board[r][c].find("4") != std::string::npos)){
                if((r%2==1)&&(c%2==1)){
                    board[r][c] = (player == 1) ? "5" : "6";
                }
            }
            return true;
        }
        int check(){
            scoreA = scoreB = 0;
            for(auto i : board){
                for(auto j : i ){
                    if(j == "5")
                        scoreA++;
                    else if(j == "6")
                        scoreB++;
                }
            }
        }
        std::vector<std::vector<std::string>> get(){
            return this->board;
        }
};