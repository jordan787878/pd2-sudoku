#include<iostream>
#include<cstdlib>
using namespace std;
class Sudoku
{
  public:
  Sudoku();
  Sudoku(const int[]);
  void setmap(const int[]);
  void setelement(int,int);
  int getzero();
  int getelement(int);
  bool iscorrect();
  const static int sudokusize=81;
  void print();
  void giveQuestion();
  void readIn();
  void solve();
  void changeNum(int,int);
  void changeRow(int,int);
  void changeCol(int,int);
  void rotate(int);
  void flip(int);
  void transform();
  
 
  private:
  bool solvera(Sudoku,Sudoku &);
  bool multi(Sudoku,Sudoku &);
  bool check(int[]);
  int map[sudokusize];
  void change();
  void getbackzero();

};

