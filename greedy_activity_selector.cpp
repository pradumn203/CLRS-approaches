#include <bits/stdc++.h>
using namespace std;

void GREEDY_ACTIVITY_SELECTOR(int s[], int f[], int n){

    int k = 0;  //select the index of first activity
    cout <<" "<< k; //print the first activity which is always selected
    // to iterate through rest of the activities
    for(int m = 1; m < n ; m++){
        if(s[m] >= f[k]) // if the start time of current activity is greater than or equal to finish time of previous activity
        {
            cout<<" "<<m; //print that current activity
            k = m; // update value of k with the index of latest selected activity
        }
    }
}
int main()
{
    int s[] =  {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int f[] =  {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
    int n = sizeof(s)/sizeof(s[0]);
    cout <<"List of activities selected are : ->";
    GREEDY_ACTIVITY_SELECTOR(s, f, n);
    return 0;
}
