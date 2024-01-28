for(testnum2=9;testnum2>=1;testnum2--)
    {
      int startGridRow,startGridCol;
      startGridRow=cell.row - cell.row%3;
      startGridCol=cell.col - cell.col%3;
      //cout<<"main_startgridrow_send="<<startGridRow<<endl;
      //cout<<"main_startgridcol_send="<<startGridCol<<endl;
      if(checknum_for_row(cell.row,cell.col,testnum2)==true)
      {
        if(checknum_for_col(cell.row,cell.col,testnum2)==true)
        {
          if(checknum_for_grid(startGridRow,startGridCol,testnum2)==true)
          {
            cout<<"!$!"<<testnum2<<" can be placed in"<<" "<<cell.row<<" "<<cell.col<<endl;
            arr[cell.row][cell.col]=testnum2; 
            print_out_matrix(); 
            break;
          }
        }
      }
    }