/*
Author=prajwal Narayan Bagewadi
College=Dr.D.Y.Patil Arts Science and Commerce College pimpri pune 18
Branch=B.C.A(Sci) Class=S.Y.B.C.A(Sci)
Roll_no=05
Subject=C++
Activity_01=Puzzle Design Using C++ Code  
Reference:https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
*/
#include<iostream>
#define N 9
using namespace std;
int arr[N][N]={
/*
original matrix:
//    0  1  2  3  4  5  6  7  8
    { 9, 0, 0, 4, 0, 0, 0, 1, 6}, //0
    { 7, 3, 0, 2, 0, 0, 9, 5, 0}, //1 
    { 0, 6, 4, 0, 0, 0, 7, 0, 0}, //2
    { 0, 0, 0, 0, 9, 0, 0, 3, 2}, //3
    { 0, 0, 0, 5, 0, 1, 0, 0, 0}, //4
    { 6, 7, 0, 0, 3, 0, 0, 0, 0}, //5
    { 0, 0, 6, 0, 0, 0, 4, 8, 0}, //6
    { 0, 4, 7, 0, 0, 8, 0, 6, 9}, //7
    { 3, 9, 0, 0, 0, 5, 0, 0, 1}  //8
*/

//    0  1  2  3  4  5  6  7  8
    { 9, 0, 5, 4, 3, 7, 2, 1, 6}, //0
    { 7, 3, 2, 2, 0, 0, 9, 5, 0}, //1
    { 1, 6, 4, 0, 0, 0, 7, 0, 0}, //2
    { 0, 1, 0, 0, 9, 0, 0, 3, 2}, //3
    { 0, 2, 0, 5, 0, 1, 0, 0, 0}, //4
    { 6, 7, 0, 0, 3, 0, 0, 0, 0}, //5
    { 0, 5, 6, 0, 0, 0, 4, 8, 0}, //6
    { 0, 4, 7, 0, 0, 8, 0, 6, 9}, //7
    { 3, 9, 0, 0, 0, 5, 0, 0, 1}  //8
};
// class to store the empty cell indices
class getrowcol
{
    public: 
    int row;
    int col;
    getrowcol()
    {

    }
    getrowcol(int i,int j)
    {
        row=i;
        col=j;
    }
};
// function to find the empty cell in matrix
getrowcol findEmptyPlace()
{
    getrowcol false_obj(0,0);
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            if(arr[row][col]==0)
            {
                // if empty cell is found foll object is returned
                getrowcol true_obj(row,col);
                return true_obj;
                break;
            }
        }   
    }
    // if no empty cell is found foll object is returned
    return false_obj;
}
// function to check if num can be placed row
bool checknum_for_row(int row,int col,int num)
{
    cout<<"checknum_for_row:row="<<row<<endl;
    cout<<"checknum_for_row:col="<<col<<endl;
    cout<<"checknum_for_row:num="<<num<<endl;
    cout<<endl;
    for(int col_i=0;col_i<N;col_i++)
    {
        // row remains constant and col is iterated 
        if(col_i!=col && arr[row][col_i]==num)
        {
            return false;
        }
    }
    return true;
}
// function to check if num can be placed col
bool checknum_for_col(int row,int col,int num)
{
    cout<<"checknum_for_col:row="<<row<<endl;
    cout<<"checknum_for_col:col="<<col<<endl;
    cout<<"checknum_for_col:num="<<num<<endl;
    cout<<endl;
    for(int row_i=0;row_i<N;row_i++)
    {
        // col remains constant and row is iterated 
        if(row_i!=row && arr[row_i][col]==num)
        {
            return false;
        }
    }
    return true;
}
// function to check if num can be placed 3X3 grid
bool checknum_for_grid(int gridStartRow,int gridStartcol,int num)
{
    // the loop processes the 3 by 3 grid
    for(int row=0;row<3;row++)
    {
        for(int col=0;col<3;col++)
        {
            if(arr[row+gridStartRow][col+gridStartcol]==num)
            {
                return false;
            }
        }
    }
    return true;
}

// function to insert the value after value confirmation
void insert_into(int row,int col,int val)
{
    if(arr[row][col]==0)
    {
        arr[row][col]=val;
    }
    
}

// function to print the processed after value confirmation
void print_out()
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            cout<<arr[row][col]<<" ";
        }   
        cout<<"\n";
    }
}

// function  to process the matrix by function utilization
void Process_sudoku()
{
    getrowcol result;
    int num_canBePlacedIn_row,num_canBePlacedIn_col,num_canBePlacedIn_grid;
    result=findEmptyPlace();
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            result=findEmptyPlace();
            cout<<"result.row="<<result.row<<"result.col="<<result.col<<endl;
            for(int testnum=1;testnum<=9;testnum++)
            {
                if(checknum_for_row(result.row,result.col,testnum)==true)
                {
                    //cout<<"ansfor_checknum_for_row="<<testnum;
                    num_canBePlacedIn_row=testnum;
                    //break;
                    if(checknum_for_col(result.row,result.col,num_canBePlacedIn_row)==true)
                    {
                        //cout<<"ansfor_checknum_for_col="<<testnum;
                        //num_canBePlacedIn_col=testnum;
                        // break;
                        num_canBePlacedIn_col=num_canBePlacedIn_row;
                        int startGridRow,startGridCol;
                        startGridRow=result.row-result.row%3;
                        startGridCol=result.col-result.col%3;
                        if(checknum_for_grid(startGridRow,startGridCol,num_canBePlacedIn_col)==true)
                        {
                            //cout<<"ansfor_checknum_for_col="<<testnum;
                            num_canBePlacedIn_grid=num_canBePlacedIn_col;
                            insert_into(row,col,num_canBePlacedIn_grid);  
                            // break;
                        }
                    }
                }
            }
        }
       //print_out();  
    }
    print_out();  
    //return 0;
}

// function to search empty cells with recsive type
// int search()
// {
//     for(int row=0;row<N;row++)
//     {
//         for(int col=0;col<N;col++)
//         {
//             if(arr[row][col]==0)
//             {
//                     Process_sudoku();
//                     return 5;
//             }
//         }
//     }
//     return 6;
// }

// function to process recursion
// int scan(int a=search())
// {
//     if(a==5)
//     {
//         a=search();
//     }
//     else
//     {
//         return 6;
//     }
// }

int main()
{

    // int result;
    // do
    // {
    //     result=search();
    // }
    // while(result!=6);
    return 0;
}

// int main()
// {
//     getrowcol result;
//     result=findEmptyPlace();
//     //checknum_for_row()
//     cout<<"result.row="<<result.row<<"result.col="<<result.col<<endl;
//     int num_canBePlacedIn_row,num_canBePlacedIn_col,num_canBePlacedIn_grid;
//     for(int testnum=1;testnum<=9;testnum++)
//     {
//         if(checknum_for_row(result.row,result.col,testnum)==true)
//         {
//             //cout<<"ansfor_checknum_for_row="<<testnum;
//             num_canBePlacedIn_row=testnum;
//             break;
//         }
//     }
//     //checknum_for_col()
//     for(int testnum=1;testnum<=9;testnum++)
//     {
//         if(checknum_for_col(result.row,result.col,testnum)==true)
//         {
//             //cout<<"ansfor_checknum_for_col="<<testnum;
//             num_canBePlacedIn_col=testnum;
//             break;
//         }
//     }
//     cout<<"num_canBePlacedIn_row="<<num_canBePlacedIn_row<<endl;
//     cout<<"num_canBePlacedIn_col="<<num_canBePlacedIn_col<<endl;

//     //check grid
//     int startGridRow,startGridCol;
//     startGridRow=result.row-result.row%3;
//     startGridCol=result.col-result.col%3;
//     for(int testnum=1;testnum<=9;testnum++)
//     {
//         if(checknum_for_grid(startGridRow,startGridCol,testnum)==true)
//         {
//             //cout<<"ansfor_checknum_for_col="<<testnum;
//             num_canBePlacedIn_grid=testnum;
//             break;
//         }
//     }
//     cout<<"num_canBePlacedIn_grid="<<num_canBePlacedIn_grid<<endl;
//     return 0;
// }



// for matrix:
/*
//    0  1  2  3  4  5  6  7  8
    { 9, 0, 5, 4, 3, 7, 2, 1, 6}, //0
    { 7, 3, 2, 2, 0, 0, 9, 5, 0}, //1 
    { 1, 6, 4, 0, 0, 0, 7, 0, 0}, //2
    { 0, 1, 0, 0, 9, 0, 0, 3, 2}, //3
    { 0, 2, 0, 5, 0, 1, 0, 0, 0}, //4
    { 6, 7, 0, 0, 3, 0, 0, 0, 0}, //5
    { 0, 5, 6, 0, 0, 0, 4, 8, 0}, //6
    { 0, 4, 7, 0, 0, 8, 0, 6, 9}, //7
    { 3, 9, 0, 0, 0, 5, 0, 0, 1}  //8
};
output :
hp@hp-Presario-CQ58-Notebook-PC:~/cpp_programs$ cd "/home/hp/cpp_programs/assignment2/activityone/" && g++ sudosol.cpp -o sudosol && "/home/hp/cpp_programs/assignment2/activityone/"sudosol
result.row=0result.col=1
checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=1

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=2

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=3

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=4

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=5

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=6

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=7

checknum_for_row:row=0
checknum_for_row:col=1
checknum_for_row:num=8

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=1

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=2

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=3

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=4

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=5

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=6

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=7

checknum_for_col:row=0
checknum_for_col:col=1
checknum_for_col:num=8

num_canBePlacedIn_row=8
num_canBePlacedIn_col=8
num_canBePlacedIn_grid=8
hp@hp-Presario-CQ58-Notebook-PC:~/cpp_programs/assignment2/activityone$ 
*/