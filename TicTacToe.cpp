#include <iostream>
#include <windows.h>
using namespace std;

const int SIZE = 3;
    char board[SIZE][SIZE];

    void setColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    // Function to display splash screen
    void splashScreen() {
        setColor(11); // Light blue color
        cout << "*****************************\n";
        cout << "*    WELCOME TO TIC-TAC-TOE  *\n";
        cout << "*****************************\n";
        system("pause"); // Wait for player to press a key
        system("cls");   // Clear screen
        setColor(15);    // Reset color to white
    }
    void initializeBoard()
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                board[i][j] = ' ';
            }
        }
    }
    void displayBoard()
    {
        setColor(15); // White color for board layout
        cout << "     0   1   2 \n"; // Column indices
        for (int i = 0; i < SIZE; i++) {
            cout << "  " << i << " "; // Row indices
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == 'X') setColor(10); // Green for X
                else if (board[i][j] == 'O') setColor(12); // Red for O
                cout << " " << board[i][j];
                setColor(15); // Reset to default after each cell
                if (j < SIZE - 1) cout << " |"; // Vertical dividers between cells
            }
            cout << "\n";
            if (i < SIZE - 1) cout << "    ---+---+---\n"; // Horizontal dividers
        }
    }
    bool checkWin(char player) {

        for (int i = 0; i < SIZE; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            {
                return true;
            }
        }

        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        {
            return true;
        }
        return false;
    }

bool isDraw()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
void playerTurn(char player)
{
    int row, col;
    while (true)
    {
        setColor(14);
        cout << "Player " << player << ",enter your move (row and column): ";
        setColor(15);
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col < SIZE && board[row][col] == ' ')
        {
            board[row][col] = player;
            break;
        }
        else
        {
            setColor(12);
            cout << "Invalid move, try again.\n";
            setColor(15);
            system("pause");
        }
    }
}
int main()
{
    splashScreen();
    char currentPlayer = 'X';
    initializeBoard();

    while (true)
    {
        displayBoard();
        playerTurn(currentPlayer);

        if (checkWin(currentPlayer))
        {
            displayBoard();
            setColor(10);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (isDraw())
        {
            displayBoard();
            setColor(14);
            cout << "It's a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    setColor(15);
    return 0;
}