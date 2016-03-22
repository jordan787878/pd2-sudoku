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
  void giveQuestion();
  void readIn();
  void solve();

  private:
  bool solver(Sudoku,Sudoku &); 
  bool check(int[]);
  int map[sudokusize];
};

