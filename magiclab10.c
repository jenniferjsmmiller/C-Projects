#include <FPT.h>

int main() {
  int column, row, row_inputs, column_inputs, i, k, b, c, numbers;
  double magic[100][100], total[100], count[100000];
  
  cin >> row_inputs;
  column_inputs = rowinputs;
  row = 0;
  c = 1;
  while (row < row_inputs) {
    column = 0;
    while (column < column_inputs) {
      cin >> numbers;
      magic[row][column] = numbers;
      count[numbers]++;
      column++;
    }
    row++;
  }

  numbers = 1;
  while (numbers <= row_inputs * row_inputs) {
    if (count[numbers] == 0) {
      c = 0;
    }
    numbers++;
  }

  i = 0;
  while (i < 100){
    total[i] = 0;
    i++;
  }

  i = 0;
  row = 0;
  column = 0;
  while (row < row_inputs) {
    total[i] += magic[row][column] ;
    row++;
    column++;
  }

  b = total[i];

  i++;
  row = 0;
  column = column_inputs - 1;
  while (row < row_inputs) {
    total[i] += magic[row][column];
    row++;
    column--;
  }

  i++;
  row = 0;
  while (row < row_inputs) {
      column = 0;
      while (column < column_inputs) {
        total[i] += magic[row][column];
        column++;
      }
    row++;
    i++;
  }

  column = 0;
  while (column < column_inputs) {
    row = 0;
    while (row < row_inputs) {
      total[i] += magic[row][column];
      row++;
    }
    column++;
    i++;
  }

  k = 0;
  while (k < i) {
    if ((total[k] == b) && (c != 0)) {
      c = 1;
    } else {
      c = 0;
    }
    k++;
  }

  if ((c == 1) && (row_inputs > 1)) {
    cout << "Oh my, it's a magic square!" << "\n";
  } else {
    cout << "No magic in here..." << "\n";
  }
}
