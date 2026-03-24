#include<bits/stdc++.h>
using namespace std;




enum class Disc {
    EMPTY, 
    RED, 
    YELLOW
};

enum class GameStatus {
    ONGOING,
    WIN,
    DRAW
};

class Player {
    private : 
        string name;
        Disc disc;
    public : 
        Player(string name, Disc disc){
            this->name = name;
            this->disc = disc;
        };

        Disc getDisc() const {
            return disc;
        };
        string getName() const {
            return name;
        };
};



class Board {
    private : 
        const int ROWS = 6;
        const int COLS = 7;
        vector<vector<Disc>>grid;
    public : 
        Board(){
            grid = vector<vector<Disc>>(ROWS,vector<Disc>(COLS, Disc::EMPTY));
        };
        bool isValid(int col){
            return col < COLS && col >= 0 && grid[0][col] == Disc::EMPTY;
        };
        int dropDisc(int col, Disc disc){
            for(int row = ROWS - 1; row >= 0; row--){
                if(grid[row][col] == Disc::EMPTY){
                    grid[row][col] = disc;
                    return row;
                }
            }
            return -1; 
        }
        bool isFull() const {

            for(int col = 0; col < COLS; col++){
                if(grid[0][col] == Disc::EMPTY)
                    return false;
            }

            return true;
        };
        void printBoard(){
            for(auto row : grid){
                for(auto cell : row){
                    char c = '.';
                    if(cell == Disc::RED) c = 'R';
                    if(cell == Disc::YELLOW) c = 'Y';
                    cout<<c<<" "; 
                }
                cout<<endl;
            }
        };

        int countDirection(int row, int col, int dr, int dc, Disc disc){
            int count = 0;
            while(row >= 0 && col>=0 && row < ROWS && col < COLS && grid[row][col] == disc){
                count++;
                row+=dr;
                col+=dc;
            };
            return count;
        }

        bool checkWinner(int row, int col, Disc disc){
            vector<pair<int,int>> directions = {
                {0,1},  
                {1,0}, 
                {1,1},  
                {1,-1}   
            };
            for(auto [dr, dc] : directions){
                int total = countDirection(row, col, dr, dc, disc) + countDirection(row, col, -dr, -dc, disc) - 1;
                if(total >= 4){
                    return true;
                }
            }
            return false;
        }
};

class Game {
    private : 
        Board board;
        Player p1;
        Player p2;

        Player* currentPlayer;
        GameStatus status;
    public : 
         Game(Player a, Player b)
        : p1(a), p2(b),
          currentPlayer(&p1),
          status(GameStatus::ONGOING) {};
        

        void switchPlayer(){
            if(currentPlayer == &p1){
                currentPlayer = &p2;
            }else{
                currentPlayer = &p1;
            }
        }

        void playMove(int col){
            if(!board.isValid(col)){
                cout<<"Invalid"<<endl;
                return;
            }
            Disc currDisc = currentPlayer->getDisc();
            int row = board.dropDisc(col, currDisc);
            if(board.checkWinner(row, col, currDisc)){
                status = GameStatus::WIN;
                cout<<currentPlayer->getName()<<" "<<"wins"<<endl;
                return;
            }
            if(board.isFull()){
                status = GameStatus::DRAW;
                cout<<"Game Drawn"<<endl;
                return;
            }
            board.printBoard();
            switchPlayer();
            if(currentPlayer->getDisc() == Disc::RED){
                cout<<"Next move Red"<<endl;
            }else{
                cout<<"Next move Yellow"<<endl;
            }

        }


};
int main(){

    Player p1("atharva", Disc::RED);
    Player p2("neha", Disc::YELLOW);

    Game game(p1, p2);

    while(true){
        int col;
        cin>>col;
        game.playMove(col);
    }   

}