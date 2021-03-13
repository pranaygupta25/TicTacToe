#include <iostream>
#include <stdlib.h>
using namespace std;

void init_grid(char (&x)[5][11])
{
    for (int i = 1; i < 4; i = i + 2)
    {
        for (int j = 0; j < 11; j++)
            if (j == 3 or j == 7)
            {
                x[i][j] = '+';
            }
            else
            {
                x[i][j] = '-';
            }
    }
    for (int i = 0; i < 5; i = i + 2)
    {
        x[i][3] = '|';
        x[i][7] = '|';
    }
    for (int i = 0; i < 5; i = i + 2)
    {
        for (int j = 0; j < 11; j++)
        {
            if (j == 3 or j == 7)
            {
                continue;
            }
            else
            {
                x[i][j] = ' ';
            }
        }
    }
}

void print_grid(char x[5][11])
{
    for (int i = 0; i < 5; i++)
    {
        cout << '\n';
        for (int j = 0; j < 11; j++)
        {
            cout << x[i][j];
        }
    }
    cout << '\n';
}

void player_turn(char (&x)[5][11], int n, int p)
{
    char c = ' ';
    if (p == 0)
    {
        c = 'o';
    }
    else if (p == 1)
    {
        c = 'x';
    }
    switch (n)
    {
    case 1:
    {
        x[0][1] = c;
        break;
    }
    case 2:
    {
        x[0][5] = c;
        break;
    }
    case 3:
    {
        x[0][9] = c;
        break;
    }
    case 4:
    {
        x[2][1] = c;
        break;
    }
    case 5:
    {
        x[2][5] = c;
        break;
    }
    case 6:
    {
        x[2][9] = c;
        break;
    }

    case 7:
    {
        x[4][1] = c;
        break;
    }
    case 8:
    {
        x[4][5] = c;
        break;
    }
    case 9:
    {
        x[4][9] = c;
        break;
    }
    default:
        break;
    }
}

int check1_win(char (&x)[5][11])
{
    // return -1 if player doesn't wins and 0 otherwise
    char c = 'o';
    if (((x[0][1] == c) && (x[2][1] == c) && (x[4][1] == c)) || ((x[0][5] == c) && (x[2][5] == c) && (x[4][5] == c)) || ((x[0][9] == c) && (x[2][9] == c) && (x[4][9] == c)) || ((x[0][1] == c) && (x[0][5] == c) && (x[0][9] == c)) || ((x[2][1] == c) && (x[2][5] == c) && (x[2][9] == c)) || ((x[4][1] == c) && (x[4][5] == c) && (x[4][9] == c)) || ((x[0][1] == c) && (x[2][5] == c) && (x[4][9] == c)) || ((x[0][9] == c) && (x[2][5] == c) && (x[4][1] == c)))
        return 0;
    else
        return -1;
}

int check2_win(char (&x)[5][11])
{
    // return -1 if player doesn't wins and 1 otherwise
    char c = 'x';
    if (((x[0][1] == c) && (x[2][1] == c) && (x[4][1] == c)) || ((x[0][5] == c) && (x[2][5] == c) && (x[4][5] == c)) || ((x[0][9] == c) && (x[2][9] == c) && (x[4][9] == c)) || ((x[0][1] == c) && (x[0][5] == c) && (x[0][9] == c)) || ((x[2][1] == c) && (x[2][5] == c) && (x[2][9] == c)) || ((x[4][1] == c) && (x[4][5] == c) && (x[4][9] == c)) || ((x[0][1] == c) && (x[2][5] == c) && (x[4][9] == c)) || ((x[0][9] == c) && (x[2][5] == c) && (x[4][1] == c)))
        return 1;
    else
        return -1;
}

int main()
{
    char matrix[5][11];
    char c;
    int input;
    char player1[20], player2[20];
    init_grid(matrix);
    // print_grid(matrix);
    int flag = -1;
    int flag1 = -1;
    int flag2 = -1;
    cout << "Player 1:: Please enter your name: ";
    cin >> player1;
    cout << "Player 2:: Please enter your name: ";
    cin >> player2;
    bool index[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for (int i = 0; i < 9; i++)
    {
        if ((i & 1) == 0)
        {
            c = 'o';
            system("cls");
            system("Color 0A");
        }
        else
        {
            c = 'x';
            system("cls");
            system("Color 06");
        }
        cout << "Current Grid: ";
        print_grid(matrix);

    INP:
        if (c == 'o')
            cout << player1;
        else
            cout << player2;

        cout << ", Enter the tile number where you would like to place '" << c << "'" << '\n';
        cin >> input;
        if (index[input] == 0)
            goto INP;
        player_turn(matrix, input, (i & 1));
        index[input] = 0;
        print_grid(matrix);
        flag1 = check1_win(matrix);
        flag2 = check2_win(matrix);
        if ((flag1 == -1) && (flag2 == -1))
            flag = -1;
        else
            flag = 0;

        if (flag == 0)
            break;
    }

    if (flag1 == 0)
    {
        system("cls");
        system("Color 0A");
        print_grid(matrix);
        cout << '\n'
             << player1 << " wins!" << '\n';
    }
    else if (flag2 == 1)
    {
        system("cls");
        system("Color 06");
        print_grid(matrix);
        cout << '\n'
             << player2 << " wins! " << '\n';
    }
    else
    {
        system("cls");
        system("Color 08");
        print_grid(matrix);
        cout << '\n'
             << "Neither " << player1 << " nor " << player2 << " wins. It's a draw !";
    }
    cout << '\n'
         << '\n'
         << '\n'
         << '\n'
         << '\n'
         << '\n'
         << "Enter 0 to exit";
    char temp;
    cin >> temp;
    return 0;
}