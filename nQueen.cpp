#include <iostream>
using namespace std;

static int k = 1;
int i, j, n;
int board[100][100];

class nQueen
{
public:
    nQueen()
    {

        for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                board[i][j]=0;
            }
        nQueenBacktrackSol(0);
    }
void displaySolution()
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        cout<<board[i][j]<<"  ";
        cout<<endl;
    }
    cout<<"----------------------"<<endl;
    cout<<endl;
}
bool checkQPosition( int row, int column)
{
    for (i = 0; i < column; i++)
        if (board[row][i]==1)
            return false;


    for (i=row, j=column; i>=0 && j>=0; i--, j--)
        if (board[i][j]==1)
            return false;

    for (i=row, j=column; j>=0 && i<n; i++, j--)
        if (board[i][j]==1)
            return false;

    return true;
}
void nQueenBacktrackSol(int column)
{
    if (column == n )
    {
        cout<<"Solution -> "<<k++<<endl;
        cout<<"----------------------"<<endl;
        displaySolution();
    }
    else
    for (int i = 0; i < n; i++)
    {
        if ( checkQPosition(i, column) )
        {
            board[i][column] = 1;
            nQueenBacktrackSol(column + 1) ;
            board[i][column] = 0;
        }
    }
}
};
int main()
{
    cout<<"Enter Number of Queen : "<<endl;
    cin>>n;
    nQueen obj1;
    return 0;
}
