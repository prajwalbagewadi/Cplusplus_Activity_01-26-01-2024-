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
// global 2d array
int arr[N][N]={

//original matrix:
//    0  1  2  3  4  5  6  7  8
    { 9, 8, 5, 4, 7, 3, 2, 1, 6}, //0
    { 7, 3, 1, 2, 0, 0, 9, 5, 0}, //1 
    { 0, 6, 4, 0, 0, 0, 7, 0, 0}, //2
    { 0, 0, 0, 0, 9, 0, 0, 3, 2}, //3
    { 0, 0, 0, 5, 0, 1, 0, 0, 0}, //4
    { 6, 7, 0, 0, 3, 0, 0, 0, 0}, //5
    { 0, 0, 6, 0, 0, 0, 4, 8, 0}, //6
    { 0, 4, 7, 0, 0, 8, 0, 6, 9}, //7
    { 3, 9, 0, 0, 0, 5, 0, 0, 1}  //8

/*
//original matrix:
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
/*

//    0  1  2  3  4  5  6  7  8
    { 9, 8, 5, 4, 3, 7, 2, 1, 6}, //0
    { 7, 3, 2, 2, 8, 6, 9, 5, 4}, //1
    { 1, 6, 4, 9, 5, 0, 7, 3, 0}, //2
    { 0, 1, 0, 0, 9, 0, 0, 3, 2}, //3
    { 0, 2, 0, 5, 0, 1, 0, 0, 0}, //4
    { 6, 7, 0, 0, 3, 0, 0, 0, 0}, //5
    { 0, 5, 6, 0, 0, 0, 4, 8, 0}, //6
    { 0, 4, 7, 0, 0, 8, 0, 6, 9}, //7
    { 3, 9, 0, 0, 0, 5, 0, 0, 1}  //8

/* 
//    0  1  2  3  4  5  6  7  8
    { 9, 1, 5, 4, 3, 7, 2, 1, 6}, //0
    { 7, 3, 2, 2, 1, 1, 9, 5, 1}, //1
    { 1, 6, 4, 1, 1, 1, 7, 3, 1}, //2
    { 1, 1, 1, 1, 9, 1, 1, 3, 2}, //3
    { 1, 2, 1, 5, 1, 1, 1, 1, 1}, //4
    { 6, 7, 1, 1, 3, 1, 1, 1, 1}, //5
    { 1, 5, 6, 1, 1, 1, 4, 8, 1}, //6
    { 1, 4, 7, 1, 1, 8, 1, 6, 9}, //7
    { 3, 9, 1, 1, 1, 5, 1, 1, 1}  //8 
*/      
};

class getrowcol
{
    public: 
    int row;
    int col;
    bool flag;
    getrowcol()
    {

    }
    getrowcol(int i,int j)
    {
        row=i;
        col=j;
    }
};

getrowcol findEmptyPlace()
{
    //getrowcol false_obj(0,0);
    getrowcol false_obj;
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            if(arr[row][col]==0)
            {
                // if empty cell is found following object is returned
                getrowcol true_obj(row,col);
                true_obj.flag=true;
                return true_obj;
                break;
            }
        }   
    }
    // if no empty cell is found following object is returned
    false_obj.flag=false;
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
bool checknum_for_grid(int gridStartRow,int gridStartCol,int num)
{
  cout<<"check_gridStartRow"<<gridStartRow<<endl;
  cout<<"check_gridStartCol"<<gridStartCol<<endl;    
    // the loop processes the 3 by 3 grid
    //cout<<"checknum_for_grid:num="<<num<<endl;
    int row=0,col=0;
    for(row=gridStartRow;row<gridStartRow+3;row++)
    {
      for(col=gridStartCol;col<gridStartCol+3;col++)
      {
        // cout<<"checknum_for_grid:row="<<row+gridStartRow<<endl;
        // cout<<"checknum_for_grid:col="<<col+gridStartCol<<endl;
        if(arr[row][col]==num)
        { 
          //cout<<"row+gridStartRow="<<row+gridStartRow<<"col+gridStartcol="<<col+gridStartCol<<endl;
          cout<<"checknum_for_grid:row="<<row<<endl;
          cout<<"checknum_for_grid:col="<<col<<endl;
          cout<<"checknum_for_grid:num="<<num<<"false"<<endl;
          return false;  
        }
      }
    }
  cout<<"checknum_for_grid:row="<<row<<endl;
  cout<<"checknum_for_grid:col="<<col<<endl;
  cout<<"checknum_for_grid:num="<<num<<"true"<<endl;  
  return true;
}

// void insert_into_matrix(int row,int col,int val)
// {
//   arr[row][col]=val;
// }

void print_out_matrix()
{
  int row,col;
  for(row=0;row<N;row++)
  {
    for(col=0;col<N;col++)
    {
      cout<<" "<<arr[row][col]<<",";
    }
    cout<<"\n";
  }
}

int main()
{
  label:
  getrowcol cell;
  cell=findEmptyPlace();
  int testnum;
  if(cell.flag!=false)
  {
    cout<<"\tcell.row="<<cell.row<<"\tcell.col="<<cell.col<<"\tcell.flag="<<cell.flag<<endl;
    //check num for row
    for(testnum=1;testnum<=9;testnum++)
    {
      int startGridRow,startGridCol;
      startGridRow=cell.row - cell.row%3;
      startGridCol=cell.col - cell.col%3;
      cout<<"main_startgridrow_send="<<startGridRow<<endl;
      cout<<"main_startgridcol_send="<<startGridCol<<endl;
      if(checknum_for_row(cell.row,cell.col,testnum)==true)
      {
        //cout<<testnum<<"can be placed in"<<cell.row<<cell.col<<endl;
        // if(checknum_for_col(cell.row,cell.col,testnum)==true)
        // {
        //  cout<<testnum<<" can be placed in"<<" "<<cell.row<<" "<<cell.col<<endl;
        //  break;
        // }
        if( checknum_for_col(cell.row,cell.col,testnum)==true )
        {
          if(checknum_for_grid(startGridRow,startGridCol,testnum)==true)
          {
            cout<<"!$!"<<testnum<<" can be placed in"<<" "<<cell.row<<" "<<cell.col<<endl;
            arr[cell.row][cell.col]=testnum; 
            print_out_matrix(); 
            goto label;
          }
        }
      }
    }
  }
  else 
  {
     cout<<"false";
  }
  return 0;
}