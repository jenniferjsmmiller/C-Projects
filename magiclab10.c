#include <FPT.h>

int main()

{
  int column, row, rowinputs, columninputs, i, k, b, c, numbers ;
  double magic[100][100], total[100], count[100000] ;
  cin >> rowinputs ;
  columninputs=rowinputs ;
  row=0 ;
  c=1 ;
  while (row < rowinputs){
    column=0 ;
    while (column < columninputs){
      cin >> numbers ;
      magic[row][column]=numbers ;
      count[numbers]=count[numbers] + 1 ;
      column++ ;
    }
    row++ ;
  }

  numbers=1 ;
  while (numbers <= rowinputs*rowinputs){
    if (count[numbers]==0){
      c=0 ;
    }
    numbers++ ;
  }

  i=0 ;
  while (i < 100){
    total[i]=0 ;
    i++ ;
  }

  i=0 ;
  row=0 ;
  column=0 ;
  while (row < rowinputs){
    total[i]=total[i] + magic[row][column] ;
    row++ ;
    column++ ;
  }

  b=total[i] ;

  i++ ;
  row=0 ;
  column=columninputs-1 ;
  while (row < rowinputs){
    total[i]=total[i] + magic[row][column] ;
    row++ ;
    column=column-1 ;
  }

  i++ ;
  row=0 ;
  while (row < rowinputs){
      column=0 ;
      while (column < columninputs){
        total[i]=total[i] + magic[row][column] ;
        column++ ;
      }
    row++ ;
    i++ ;
  }

  column=0 ;
  while (column < columninputs){
    row=0 ;
    while (row < rowinputs){
      total[i]=total[i] + magic[row][column] ;
      row++ ;
    }
    column++ ;
    i++ ;
  }

  k=0 ;
  while (k < i){
    if ((total[k]==b)&&(c!=0)){
      c=1 ;
    }else{
      c=0 ;
    }
    k++ ;
  }

  if ((c==1)&&(rowinputs > 1)){
    cout << "Oh my, it's a magic square!" << "\n" ;
  }else{
    cout << "No magic in here..." << "\n" ;
  }
}
