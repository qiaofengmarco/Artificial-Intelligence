#ifndef MY_BOARD_HPP
#define MY_BOARD_HPP

#include "Headers.h"

#define x first
#define y second

int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int rand_dir()
{
    return (int) (((double) rand() / (double) RAND_MAX) * 4);
}

unsigned int calc_Manhattan_Dis(const vector< pair<int, int> > &position);

class Board
{
public:
    static int puzzle;
    static int grid_size;
    int* board;
    unsigned int Manhattan_Dis = 0;
    string rep;
    size_t hash_val;
    vector< pair<int, int> > position;
    Board() 
    {
        position.resize(puzzle + 1);
        board = new int[puzzle + 1];
        rep = "";
    }
    Board(const Board &b)
    {
        position.resize(puzzle + 1);
        board = new int[puzzle + 1];
        for (int i = 0; i <= puzzle; i++)
        {
            board[i] = b.board[i];
            position[i].x = b.position[i].x;
            position[i].y = b.position[i].y;
        }
        Manhattan_Dis = calc_Manhattan_Dis(position);
        rep = b.rep;
        hash_val = b.hash_val;
    }
    bool operator==(const Board& b)
    {
        for (int i = 0; i <= puzzle; i++)
        {
            if (board[i] != b.board[i])
                return false;
        }
        return true;
    }
    bool operator==(const Board& b) const
    {
        for (int i = 0; i <= puzzle; i++)
        {
            if (board[i] != b.board[i])
                return false;
        }
        return true;
    }
    bool operator!=(const Board& b)
    {
        for (int i = 0; i <= puzzle; i++)
        {
            if (board[i] != b.board[i])
                return true;
        }
        return false;
    }
    bool operator!=(const Board& b) const
    {
        for (int i = 0; i <= puzzle; i++)
        {
            if (board[i] != b.board[i])
                return true;
        }
        return false;
    }
    const Board& operator= (const Board &b)
    {
        for (int i = 0; i <= puzzle; i++)
        {
            board[i] = b.board[i];
            position[i].x = b.position[i].x;
            position[i].y = b.position[i].y;
        }
        Manhattan_Dis = b.Manhattan_Dis;
        rep = b.rep;
        hash_val = b.hash_val;
        return *this;
    }
    bool operator<(const Board& b)
    {
        return Manhattan_Dis < b.Manhattan_Dis;
    }
    bool operator<(const Board& b) const
    {
        return Manhattan_Dis < b.Manhattan_Dis;
    }
    void random(const unsigned int step = 15)
    {
        int dir;
        rep = "";
        for (int i = 0; i <= puzzle; i++)
        {
            board[i] = i;
            position[i].x = i / grid_size;
            position[i].y = i % grid_size;
            rep += (char) (board[i] + 48);
        }
        cout << "Begin randoming moves..." << endl;
        for (unsigned int i = 0; i < step; i++)
        {
            dir = rand_dir();
            while (!movable(dir))
            {
                dir = (dir + 1) % 4;
            }
            this_move(dir);
        }
        Manhattan_Dis = calc_Manhattan_Dis(position);
        hash<string> hasher;
        hash_val = hasher(rep);
        cout << "Finished randoming." << endl;
    }
    static int calc_pos(int a, int b)
    {
        return a * grid_size + b;
    }
    void draw()
    {
        int index = 0;
        for (int i = 0; i < grid_size; i++)
        {
            if (puzzle == 8)
                cout << "----------------" << endl;
            else if (puzzle == 15)
                cout << "---------------------" << endl;
            else
                cout << "--------------------------" << endl;
            for (int j = 0; j < grid_size; j++)
            {
                cout << "|";
                index = calc_pos(i, j);
                if (board[index] < 10)
                    cout << " ";
                if (!board[index])
                    cout << "   ";
                else
                    cout << " " << board[index] << " ";
            }
            cout << "|" << endl;  
        }   
        if (puzzle == 8)
            cout << "----------------" << endl;
        else if (puzzle == 15)
            cout << "---------------------" << endl;
        else
            cout << "--------------------------" << endl;
    }
    Board move(int dir)
    {
        Board ans(*this);
        pair<int, int> new_pos;
        int index1, index2;
        new_pos.x = position[0].x + direct[dir][0];
        new_pos.y = position[0].y + direct[dir][1];
        index1 = calc_pos(position[0].x, position[0].y);
        index2 = calc_pos(new_pos.x, new_pos.y);
        ans.position[board[index2]].x = position[0].x;
        ans.position[board[index2]].y = position[0].y;
        swap(ans.board[index1], ans.board[index2]);
        swap(ans.rep[index1], ans.rep[index2]);
        ans.position[0].x = new_pos.x;
        ans.position[0].y = new_pos.y;
        hash<string> hasher;
        ans.hash_val = hasher(ans.rep);
        return ans;
    }
    void this_move(int dir)
    {
        pair<int, int> new_pos;
        int index1, index2;
        new_pos.x = position[0].x + direct[dir][0];
        new_pos.y = position[0].y + direct[dir][1];
        index1 = calc_pos(position[0].x, position[0].y);
        index2 = calc_pos(new_pos.x, new_pos.y);
        position[board[index2]].x = position[0].x;
        position[board[index2]].y = position[0].y;
        swap(board[index1], board[index2]);
        swap(rep[index1], rep[index2]);
        position[0].x = new_pos.x;
        position[0].y = new_pos.y;
        hash<string> hasher;
        hash_val = hasher(rep);
    }
    bool movable(int dir)
    {
        pair<int, int> blank = position[0];
        if ((dir <= 3) && (dir >= 0))
        {
            blank.x += direct[dir][0];
            blank.y += direct[dir][1];
            return ((blank.x <= grid_size - 1) && (blank.y <= grid_size - 1) && (blank.x >= 0) && (blank.y >= 0));
        }
        return false;
    }
    static bool goal_test(const Board &board)
    {
        for (int i = 0; i <= puzzle; i++)
            if (board.board[i] != i)
                return false;
        return true;
    }
    static Board goal_state()
    {
        Board b;
        for (int i = 0; i <= puzzle; i++)
        {
            b.board[i] = i;
            b.position[i].x = i / grid_size;
            b.position[i].y = i % grid_size;
            b.rep += (char) (b.board[i] + 48);
        }
        b.Manhattan_Dis = calc_Manhattan_Dis(b.position);
        hash<string> hasher;
        b.hash_val = hasher(b.rep);
        return b;
    }
    void writeBoard(string s)
    {
        FILE *f = fopen(s.c_str(), "w");
        fwrite(board, sizeof(int), puzzle + 1, f);
        fclose(f);
    }
    void readBoard(string s)
    {
        FILE *f = fopen(s.c_str(), "r");
        fread(board, sizeof(int), puzzle + 1, f);
        rep = "";
        for (int i = 0; i <= puzzle; i++)
        {
            rep += (char) (board[i] + 48);
            position[board[i]].x = i / grid_size;
            position[board[i]].y = i % grid_size;
        }
        Manhattan_Dis = calc_Manhattan_Dis(position);
        hash<string> hasher;
        hash_val = hasher(rep);
        fclose(f);
    }
    ~Board()
    {
        vector< pair<int, int> >().swap(position);
        delete[] board;
    }
};

int Board::puzzle = 8;
int Board::grid_size = 3;

unsigned int calc_Manhattan_Dis(const vector< pair<int, int> > &position)
{
    unsigned int ans = 0;
    for (int i = 0; i <= Board::puzzle; i++)
        ans += abs(position[i].x - i / Board::grid_size) + abs(position[i].y - i % Board::grid_size);
    return ans;
}

template <>
struct hash<Board>
{
    size_t operator()(const Board& b)
    {
        return b.hash_val;
    }
};

struct board_hash_less
{
    bool operator()(const Board& a, const Board & b)
    {
        return a.hash_val < b.hash_val;
    }
};

#endif