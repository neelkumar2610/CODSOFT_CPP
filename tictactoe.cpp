#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Function to initialize the board
void initializeBoard()
{
    char ch = '1';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ch++;
        }
    }
    currentPlayer = 'X';
}

// Function to display the board
void displayBoard()
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
        if (i < 2)
            cout << "---|---|---" << endl;
    }
    cout << "\n";
}

// Function to make a move
bool makeMove(int choice)
{
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return false;

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = currentPlayer;
        return true;
    }

    return false;
}

// Function to check winner
bool checkWin()
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Function to check draw
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Function to switch players
void switchPlayer()
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int main()
{
    char playAgain;

    do
    {
        initializeBoard();
        bool gameOver = false;

        while (!gameOver)
        {
            displayBoard();

            int choice;
            cout << "Player " << currentPlayer
                 << ", enter your move (1-9): ";
            cin >> choice;

            if (!makeMove(choice))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWin())
            {
                displayBoard();
                cout << "🎉 Player " << currentPlayer << " Wins!\n";
                gameOver = true;
            }
            else if (checkDraw())
            {
                displayBoard();
                cout << "🤝 Game Draw!\n";
                gameOver = true;
            }
            else
            {
                switchPlayer();
            }
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThank you for playing!\n";

    return 0;
}
