/* Programmer: Muhammad Abser Mansoor
 * Date: 15/2/2024
 * Desc.: Chess using OOP
 */

#include <iostream>
#include <string>
#include <vector>

class ChessPiece {

    std::string name;
    std::string color;
    char symbol;

    public:

    ChessPiece() { // Default Constructor

        name = "Pawn";
        color = "White";
        symbol = 'p';

    }

    ChessPiece(std::string customname, std::string customcolor, char customsymbol) { // Parameterized Constructor

        name = customname;
        color = customcolor;
        symbol = customsymbol;

    }

    std::string getname() {
        return name;
    }

    std::string getcolor() { // Getters
        return color;
    }

    char getsymbol() {
        return symbol;
    }

    void setname(std::string newname) {
        name = newname;
    }

    void setcolor(std::string newcolor) { // Setters
        color = newcolor;
    }

    void setsymbol(char newsymbol) {
        symbol = newsymbol;
    }
};

class ChessBoard {

    std::vector <std::vector<ChessPiece>> pieces; // 2D Vector

    public:

    ChessBoard() : pieces(8, std::vector<ChessPiece>(8)) {

        for (int j = 0;j < 8;j++) {

            pieces[6][j] = ChessPiece();
            pieces[1][j] = ChessPiece("Pawn","Black",'P');

        }

        for (int i = 2; i < 6;i++) {

            for (int j = 0;j < 8;j++) {

                pieces[i][j] = ChessPiece("Empty","Empty",'.');
            }
        }

        pieces[7][0] = ChessPiece("Rook","White",'r');
        pieces[7][1] = ChessPiece("Knight","White",'n');
        pieces[7][2] = ChessPiece("Bishop","White",'b');
        pieces[7][3] = ChessPiece("Queen","White",'q');
        pieces[7][4] = ChessPiece("King","White",'k');
        pieces[7][5] = ChessPiece("Bishop","White",'b');
        pieces[7][6] = ChessPiece("Knight","White",'n');
        pieces[7][7] = ChessPiece("Rook","White",'r');

        pieces[0][0] = ChessPiece("Rook","Black",'R');
        pieces[0][1] = ChessPiece("Knight","Black",'N');
        pieces[0][2] = ChessPiece("Bishop","Black",'B');
        pieces[0][3] = ChessPiece("Queen","Black",'Q');
        pieces[0][4] = ChessPiece("King","Black",'K');
        pieces[0][5] = ChessPiece("Bishop","Black",'B');
        pieces[0][6] = ChessPiece("Knight","Black",'N');
        pieces[0][7] = ChessPiece("Rook","Black",'R');

    }

    void display() {

        for (int i = 0; i < 10; i++) {

            if (i == 0 || i == 9) std::cout << "    ";

            for (int j = 0;j < 10;j++) {

                char axis = '`'+j;

                if ((i != 0 && i != 9) && (j == 0 || j == 9)) std::cout << i << "   ";
                if ((i == 0 || i == 9) && (j > 0 && j < 9)) std::cout << axis << "   ";

                if ((i > 0 && i < 9) && (j > 0 && j < 9)) {

                    std::cout << pieces[i-1][j-1].getsymbol() << "   ";
                }
            }
            std::cout << std::endl;
        }
    }

    std::string identifypiece(std::string source) {

        char column = source[0] - 'a';
        char row = source[1] - '1';

        return pieces[row][column].getname(); 

    }

    bool occupied (std::string destination) {

        char column = destination[0] - 'a';
        char row = destination[1] - '1';

        if (pieces[row][column].getname() != "Empty") {
            return true;
        }

        return false;
    }

    bool Movepiece(std::string source, std::string destination) { // We are only considering knight and pawn moves
        
        if (occupied(destination)) {
            std::cout << "Space occupied" << std::endl;
            return false;
        }

        if (identifypiece(source) == "Knight") {
            
            std::cout << "Knight Moving" << std::endl;
            char source_x_coordinate = source[0] - 'a';
            char source_y_coordinate = source[1] - '1';
            char destination_x_coordinate = destination[0] - 'a';
            char destination_y_coordinate = destination[1] - '1';

            if (destination_x_coordinate - source_x_coordinate != 1 &&
                destination_x_coordinate - source_x_coordinate != -1) {
                    
                    std::cout << "x-check failed" << std::endl;
                    return false; }

            if (destination_y_coordinate - source_y_coordinate != 2 &&
                destination_y_coordinate - source_y_coordinate != -2) {

                    std::cout << "y-check failed" << std::endl;
                    return false; }

            std::cout << "Valid" << std::endl;
            return true;

        }

        else {

            if (occupied(destination)) {
            std::cout << "Space occupied" << std::endl;
            return false;
            }

            std::cout << "Pawn Moving" << std::endl;
            char source_x_coordinate = source[0] - 'a';
            char source_y_coordinate = source[1] - '1';
            char destination_x_coordinate = source[0] - 'a';
            char destination_y_coordinate = source[1] - '1';

            if (destination_x_coordinate - source_x_coordinate != 1 &&
                destination_x_coordinate - source_x_coordinate != 2) {
                    
                    std::cout << "x-check failed" << std::endl;
                    return false;
                }

            return true;
        }
    }
};

int main() {

    ChessBoard board;
    board.display();
    board.Movepiece("b8","a6");
}
