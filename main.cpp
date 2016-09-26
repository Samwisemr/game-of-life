#include <iostream>

using namespace std;

// Declarations
int will_be_alive(int alive, int col, int row, int current[][10]);
void print_board(int board[][10]);
void start_game(int current[][10], int time);

//============================================

int will_be_alive(int alive, int col, int row, int current[][10]) {

    // Dealing with elements on the edge of the board being next to objects on the other side
    int col_sub_one;
    int col_plus_one;
    int row_sub_one;
    int row_plus_one;

    if (col == 0) {
        col_sub_one = 9;
    } else {
        col_sub_one = col - 1;
    }
    if (row == 0) {
        row_sub_one = 9;
    } else {
        row_sub_one = row - 1;
    }
    if (col == 9) {
        col_plus_one = 0;
    } else {
        col_plus_one = col + 1;
    }
    if (row == 9) {
        row_plus_one = 0;
    } else {
        row_plus_one = row + 1;
    }
    //=============================

    //Getting the list of adjacent elements
    int neighbors[8];
    int n = 0;
    while (n < 8) {
        if (n == 0) {
            neighbors[n] = current[col_sub_one][row_sub_one];
            n++;
        } else if (n == 1) {
            neighbors[n] = current[col][row_sub_one];
            n++;
        } else if (n == 2) {
            neighbors[n] = current[col_plus_one][row_sub_one];
            n++;
        } else if (n == 3) {
            neighbors[n] = current[col_sub_one][row];
            n++;
        } else if (n == 4) {
            neighbors[n] = current[col_plus_one][row];
            n++;
        } else if (n == 5) {
            neighbors[n] = current[col_sub_one][row_plus_one];
            n++;
        } else if (n == 6) {
            neighbors[n] = current[col][row_plus_one];
            n++;
        } else if (n == 7) {
            neighbors[n] = current[col_plus_one][row_plus_one];
            n++;
        }
    }
    //======================================================

    //Getting the number of adjacent elements that are alive
    int live_neighbors = 0;
    for (int i = 0; i < 8; i++) {
        if (neighbors[i]) {
            live_neighbors++;
        }
    }
    //============================

    //Figuring out whether or not the element lives or dies
    if (alive) {
        if (live_neighbors == 2 || live_neighbors == 3) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (live_neighbors == 3) {
            return 1;
        } else {
            return 0;
        }
    }
    //=================================
}


void print_board(int board[][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (j != 9) {
                if (board[j][i]) {
                    cout << "X ";
                } else {
                    cout << "  ";
                }
            } else {
                if (board[j][i]) {
                    cout << "X" << endl;
                } else {
                    cout << " " << endl;
                }
            }
        }
    }
    cout << "\n\n\n\n";
}

void start_game(int current[][10], int time) {
    int next[10][10];
    int running = time;
    while (running) {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10 ; j++) {
                if (will_be_alive(current[i][j], i, j, current)) {
                    next[i][j] = 1;
                } else {
                    next[i][j] = 0;
                }
            }
        }

    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            current[a][b] = next[a][b];
        }
    }
    print_board(current);
    running--;

    }
}



int main()
{
    // Setting up a board with three alive in a row
    int board[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    board[0][2] = 1;
    board[1][2] = 1;
    board[2][2] = 1;
    board[1][0] = 1;
    board[2][1] = 1;
    print_board(board);

    //===========================

    start_game(board, 50);
}

/*
0,0  1,0  2,0  3,0  4,0  5,0  6,0  7,0  8,0  9,0
0,1  1,1  2,1  3,1  4,1  5,1  6,1  7,1  8,1  9,1
0,2  1,2  2,2  3,2  4,2  5,2  6,2  7,2  8,2  9,2
0,3  1,3  2,3  3,3  4,3  5,3  6,3  7,3  8,3  9,3
0,4
0,5
0,6
0,7
0,8
0,9  1,9  2,9  3,9  4,9  5,9  6,9  7,9  8,9  9,9
*/
