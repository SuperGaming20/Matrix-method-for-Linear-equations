// Developed by Dharrun Sriman
#include <iostream>
#include <string>
using namespace std;

// ad - bc = 0 (no inverse matrix)
// 1/(ad-bc) * (d,-b,-c,a), std (a,b,c,d)

int main()
{
  float x1, y1, z1;
  float x2, y2, z2;
  cout << "Enter coefficients of first equation: " << endl;
  cin >> x1 >> y1 >> z1;
  cout << "Enter coefficients of second equation: " << endl;
  cin >> x2 >> y2 >> z2;
  float inverse_matrix[2][2] = {y2,-y1,-x2,x1};
  float answer_matrix[2][1] = {z1,z2};
  float coefficient = 1/((y2*x1)-((-y1)*(-x2)));
  float new_matrix[2][1];
  float summation = 0;
  char var[2] = {'x','y'};
  for(int current_row = 0; current_row < 2; current_row++)
  {
    for(int current_col = 0; current_col < 2; current_col++)
    {
      summation += inverse_matrix[current_row][current_col] * answer_matrix[current_col][0];
      if (current_col == 1) {new_matrix[current_row][0] = {coefficient * summation};}
    }
    if (current_row == 0) {cout << endl;}
    cout << var[current_row] << " = " << new_matrix[current_row][0] << endl;
    if (current_row == 1) {cout << endl;}
    summation = 0;
  }
}
