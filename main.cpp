#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Universe{
private:
    char board[22][22];
public:
    Universe();
    void initialize();
    void reset();
    int count_neighbors(int, int);
    void next_generation();
    void display();
    void run(int);
};

int main()
{
    Universe start;
    int run_times;
    cout << "Please enter the number of runs: \n";
    cin >> run_times;
    start.run(run_times);
    return 0;
}

Universe::Universe()
{
    reset();
}

void Universe::initialize()
{
    int cells_number;

    cout << "Enter the number of cells: \n";
    cin >> cells_number;

    while (cells_number)
    {
        int x = rand() % 20;
        int y = rand() % 20;
        board[x][y] = 'B';
        cells_number--;
    }
}

void Universe::reset()
{
    for (int i = 0; i < 22; ++i)
    {
        for (int j = 0; j < 22; ++j)
        {
            board[i][j] = '.';
        }
    }
}

int Universe::count_neighbors(int x, int y)
{
    int alive_count = 0;
    for (int i = x - 1; i <= x + 1; ++i)
    {
        for (int j = y - 1; j <= y + 1; ++j)
        {
            if((i == x) && (j == y)) { continue; }
            if(board[i][j] == 'B') { alive_count++; }
        }
    }
    return alive_count;
}

void Universe::next_generation()
{
    char temp_board[22][22];
    for (int i = 0; i < 22; ++i)
    {
        for (int j = 0; j < 22; ++j)
        {
           temp_board[i][j] = '.';
        }

    }

    for (int i = 1; i < 21; ++i)
    {
        for (int j = 1; j < 21; ++j)
        {
            int count = count_neighbors(i, j);

            if( (board[i][j] == 'B') && ((count == 2) || (count == 3)))
            {
                temp_board[i][j] = 'B';
            }
            else if((board[i][j] == '.') && (count == 3))
            {
                temp_board[i][j] = 'B';
            }
            else
            {
                temp_board[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < 22; ++i)
    {
        for (int j = 0; j < 22; ++j)
        {
            board[i][j] = temp_board[i][j];
        }
    }
}

void Universe::display()
{
    for (int i = 1; i < 21; ++i)
    {
        for (int j = 1; j < 21; ++j)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void Universe::run(int times)
{
    initialize();
    cout << "* START GENERATION * \n\n";
    display();
    sleep(1);

    while (times)
    {
        system("CLS");
        cout << "* NEXT GENERATION * \n\n";
        next_generation();
        display();
        sleep(1);
        times--;
    }
}