#include <iostream>
#include <climits>
#define MAX_SIZE 10

using namespace std;

class DiagonalMatrix
{
public:
  int *arr;
  int size;
  int nrows;
  int ncols;

  DiagonalMatrix(int rows = MAX_SIZE,
                 int cols = MAX_SIZE)
  {
    if (rows != cols)
      cerr << "ERROR: Invalid Dimensions" << endl;
    else
    {
      size = rows;
      nrows = ncols = rows;
      arr = new int[size];
      for (int i = 0; i < size; i++)
        arr[i] = 0;
    }
  }

  ~DiagonalMatrix()
  {
    delete[] arr;
  }

  void store(int data, int row, int col)
  {
    if (row != col || row >= nrows || col >= ncols)
      cerr << "ERROR: Invalid Location" << endl;
    else
      arr[row] = data;
  }

  int retrieve(int row, int col)
  {
    if (row >= nrows || col >= ncols)
      return INT_MIN;

    if (row != col)
      return 0;
    else
      return arr[row];
  }

  void display()
  {
    for (int i = 0; i < nrows; i++)
    {
      for (int j = 0; j < ncols; j++)
        if (i == j)
          cout << arr[i] << " ";
        else
          cout << 0 << " ";
      cout << endl;
    }
  }
};

int main(void)
{
  int rows, cols, data, choice = 1;

  cout << "Enter Number of Rows: ";
  cin >> rows;
  cout << "Enter Number of Columns: ";
  cin >> cols;

  DiagonalMatrix matrix(rows, cols);

  do
  {
    cout << "      MENU      \n"
         << "================\n"
         << "(1) Display\n"
         << "(2) Store\n"
         << "(3) Retrieve\n"
         << "(0) Exit\n\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      cout << "\nMatrix:\n";
      matrix.display();
      break;
    case 2:
      cout << "Enter Data: ";
      cin >> data;
      cout << "Enter Position: ";
      cin >> rows >> cols;
      matrix.store(data, rows, cols);
      break;
    case 3:
      cout << "Enter Position: ";
      cin >> rows >> cols;
      data = matrix.retrieve(rows, cols);
      if (data != INT_MIN)
        cout << "Retrieved " << data << endl;
      else
        cerr << "ERROR: Invalid Location" << endl;
      break;
    case 0:
    default:
      break;
    }
    
  } while (choice != 0);

  return 0;
}

/*

OUTPUT -

Enter Number of Rows: 3
Enter Number of Columns: 3

      MENU      
================
(1) Display     
(2) Store       
(3) Retrieve    
(0) Exit        

Enter Choice: 2
Enter Data: 6 
Enter Position: 0 1
ERROR: Invalid Location     

Press any key to continue...

      MENU      
================
(1) Display     
(2) Store
(3) Retrieve  
(0) Exit      

Enter Choice: 2
Enter Data: 5
Enter Position: 1 1

Press any key to continue...

      MENU      
================
(1) Display     
(2) Store       
(3) Retrieve    
(0) Exit        

Enter Choice: 1 

Matrix:
0 0 0
0 5 0
0 0 0

Press any key to continue...

      MENU      
================
(1) Display     
(2) Store     
(3) Retrieve  
(0) Exit      

Enter Choice: 2
Enter Data: 4
Enter Position: 2 2

Press any key to continue..

      MENU      
================
(1) Display     
(2) Store       
(3) Retrieve    
(0) Exit        

Enter Choice: 3 
Enter Position: 2 2
Retrieved 4

Press any key to continue...

      MENU      
================
(1) Display     
(2) Store       
(3) Retrieve    
(0) Exit        

Enter Choice: 3 
Enter Position: 0 2
Retrieved 0

Press any key to continue...

      MENU      
================
(1) Display     
(2) Store       
(3) Retrieve    
(0) Exit        

Enter Choice: 3 
Enter Position: 5 5
ERROR: Invalid Location     

Press any key to continue...

*/
