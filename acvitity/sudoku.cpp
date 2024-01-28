#include<iostream>
using namespace std;
int row=11;
int col=11;
int arr[11][11];
// enter zero for space
void check_col(){
    for(int i=0;i<row;i++){
        if(i==3 || i==7)
        {
            continue;
        }
        for(int j=0;j<col;j++){
            if(i==3 || i==7)
            {
                continue;
            } 
            else{
                if(arr[i][j]==0 && j==0)
                {
                    cout<<"val="<<i<<":"<<j;
                    // for(int var=1;var<=9;var++){
                    //     if(var!=arr[i][j] && i==10)
                    //     {
                    //         arr[i][j]==var;
                    //     }
                    // }
                }
            }
        }
    }
}
int main()
{   
    for(int i=0;i<row;i++)
    {
        if(i==3 || i==7)
        {
            cout<<endl;
        }
        else{
        for(int j=0;j<col;j++)
        {
            if(j==3 || j==7)
            {
                cout<<"\t";
            }
            else
            {
                cout<<"pos:"<<i<<"-"<<j<<":";
                cin>>arr[i][j];
            }           
        }
        cout<<endl;
        }
    } 

    for(int i=0;i<row;i++)
    {
        if(i==3 || i==7)
        {
            cout<<endl;
        }
        else{
        for(int j=0;j<col;j++)
        {
            if(j==3 || j==7)
            {
                cout<<"\t";
            }
            else
            {
                cout<<arr[i][j];
            }           
        }
        cout<<endl;
        }
    }

    
    return 0;
}
/*
    0 1 2 3 4 5 6 7 8 9 10
0   9 0 0 _ 4 0 0 _ 0 1 6 
1   0 0 0 _ 0 0 0 _ 0 0 0
2   0 0 0 _ 0 0 0 _ 0 0 0 
3
4   0 0 0 _ 0 0 0 _ 0 0 0 
5   0 0 0 _ 0 0 0 _ 0 0 0
6   0 0 0 _ 0 0 0 _ 0 0 0 
7
8   0 0 0 _ 0 0 0 _ 0 0 0 
9   0 0 0 _ 0 0 0 _ 0 0 0
10  0 0 0 _ 0 0 0 _ 0 0 0 

*/