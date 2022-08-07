
//================================
// Dynamic Programming - Knapsack
//================================

// Please fill up the following
// Name			: Ahmed Jobaer
// Matric No.	: 1918243
// Section		: Sec 2
// (if 2pm-3.20pm: Sec 1; else if 3.30pm - 4.50pm: Sec 2)

//====================================================================
#include <iostream>
using namespace std;

const int W = 5; // max knapsack capacity

//==========================================================================
// Dynamic Programming function for solving Knapsack Problem
void Knapsack(int i, int j, int w[], int n, int v[], int F[][W + 1])
{

    for (i = 0; i <= n; i++) // this for loop is depends on number of items
    {
        for (j = 0; j <= W; j++) // this for loop is depends on max knapsack capacity
        {
            // if items and capacity is 0 then initialize array with 0
            if (i == 0)
                F[i][j] = 0;
            else if (j == 0)
                F[i][j] = 0;

            // here i use knapsack formula to find max value
            else if (w[i - 1] <= j)
            {
                F[i][j] = max(F[i - 1][j], F[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
                F[i][j] = F[i - 1][j];
        }
    }
}

//===============
// Main Function
int main(void)
{
    //===============

    // number of items
    const int n = 4;

    int i; // item: 1 <= i <= n
    int j; // capacity: 1 <= j <= W

    int weight[] = {2, 1, 3, 2};    // weight of each item
    int value[] = {12, 10, 20, 15}; // value of each item

    // Instruction: Initialize F
    // F: dynamic programming table/matrix, containing values of F(i,j)
    int F[n + 1][W + 1];

    // call the dynamic programming function
    Knapsack(i, j, weight, n, value, F);

    // show the result with list
    cout << "----------------------------------------------" << endl;
    cout << "       Dynamic Programming List" << endl;
    cout << "----------------------------------------------" << endl;

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            cout << "F(" << i << "," << j << ") = " << F[i][j] << endl;
        }
    }

    cout << endl;

    // show the result with table
    cout << "\n----------------------------------------------" << endl;
    cout << "       Dynamic Programming Matrix" << endl;
    cout << "----------------------------------------------" << endl;

    for (i = 0; i <= n; i++)
    {

        for (j = 0; j <= W; j++)
        {
            cout << F[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
