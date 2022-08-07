//====================================================
// Dynamic Programming - Knapsack - Recursion + Table
//====================================================

// Please fill up the following
// Name			: Ahmed Jobaer
// Matric No.	: 1918243
// Section		: 02
// (if 2pm-3.20pm: Sec 1; else if 3.30pm - 4.50pm: Sec 2)


#include<iostream>
using namespace std;

//Initialization
int F[5][6];
int w[5];
int v[100];

int MFKnapsack(int i,int j)
{
    // if items and capacity is 0 then initialize array with 0
    if(i==0)
        return 0;
    else if(j==0)
        return 0;

    // else then recursively calling dynamic programming function
    else if(w[i]<=j)
        F[i][j] = max(MFKnapsack(i-1,j),v[i]+MFKnapsack(i-1,j-w[i]));
    else
        F[i][j] = MFKnapsack(i-1,j);
    return F[i][j];
}


int main(void)
{

    int i; // item: 1 <= i <= n  (row)
    int j; // capacity: 1 <= j <= W (column)


    // Initialization

    // start from the goal F(n, W), then recursively calling dynamic programming function
    i = 4;
    j = 5;

    int weight[] = {2,1,3,2}; 	// weight of each item
    int value[] = {12,10,20,15}; 	// value of each item

    for(int ii=0; ii<=i; ii++)
    {
        // if number of items and capacity is 0 then initialize F with 0
        for(int jj=0; jj<=j; jj++)
        {
            if(ii==0 || jj==0)
                F[ii][jj]=0;
        // otherwise it -1
            else
                F[ii][jj]=-1;
        }
    }

    // store the value in array
    for(int ii=0; ii<i; ii++)
    {
        w[ii+1]=weight[ii];
        v[ii+1]=value[ii];
    }

    cout << "Memory Function Knapsack \n";
    cout << MFKnapsack(i,j) << endl;


    // show the result

    cout<<"\n----------------------------------------------"<<endl;
    cout<<"       Dynamic Programming List"<<endl;
    cout<<"----------------------------------------------"<<endl;


    for (int ii = 0; ii <=i; ii++)
    {
        for (int jj = 0; jj <=j; jj++)
        {
            cout << "F(" << ii << "," << jj << ") = " << F[ii][jj] << endl;
        }
    }

    cout << endl;


    cout<<"\n----------------------------------------------"<<endl;
    cout<<"       Dynamic Programming Matrix"<<endl;
    cout<<"----------------------------------------------"<<endl;

    for (int  ii= 0; ii <= i; ii++)
    {

        for (int jj = 0; jj <= j; jj++)
        {
            cout<<F[ii][jj]<<"\t";
        }
        cout<<endl;
    }


    return 0;
}




