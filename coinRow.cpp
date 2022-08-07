// Please fill up the following
// Name			: Ahmed Jobaer
// Matric No.	: 1918243
// Section		: 02
// (if 2pm-3.20pm: Sec 1; else if 3.30pm - 4.50pm: Sec 2)

#include<iostream>
using namespace std;

void CoinRow(int n[], int);

//main function
int main()
{
    //Initialization
    int coins[] = { 7, 2, 1, 12, 5, 6, 8, 7, 5, 4};
    int s = sizeof(coins) / sizeof(coins[0]); // calculate the size of array

    CoinRow(coins, s); // calling function

    return 0;
}

void CoinRow(int arr[],int arrsize)
{

    int C[arrsize + 1];
    for(int i = 0; i < arrsize+1; i++)
    {
        C[i+1] = arr[i]; // copy the given elements in array C
    }

    //Initialization
    int F[arrsize + 1];
    F[0] = 0;
    F[1] = C[1];

    for(int i = 2; i<= arrsize; i++)
    {
        F[i] = max(C[i] + F[i - 2], F[i-1]); // using recurrence formula to find maximum value
    }

    //showing the result in a list
    for(int i = 0; i<arrsize+1; i++)
    {
        cout<<arr[i-1]<<" = "<<F[i]<<endl;
    }

}

