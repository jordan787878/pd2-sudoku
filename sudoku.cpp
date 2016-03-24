#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include"sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
  for(int i=0;i<sudokusize;i++)
  { map[i]=0; }
}

Sudoku::Sudoku(const int init_map[])
{
  for(int j=0;j<sudokusize;j++)
  { map[j]=init_map[j]; }
}

void Sudoku::setmap(const int set_map[])
{
  for(int k=0;k<sudokusize;k++)
  { map[k]=set_map[k]; }
}

void Sudoku::setelement(int index,int number)
{  
   map[index]=number;
}

int Sudoku::getzero()
{ 
  for(int i=0;i<81;i++)
  {  
     if(map[i]==0)
     return i;    
  } 
    return -1;
}

int Sudoku::getelement(int index)
{ return map[index]; }


bool Sudoku::check(int arr[])
{
  int checkarray[10];
  for(int i=0;i<10;i++)
  { checkarray[i]=0; }

  for(int i=0;i<9;i++)
  { 
   checkarray[arr[i]]++;
  }

  for(int j=1;j<10;j++)
  { 
   
     if(checkarray[j]>1) 
     return false; 
   
  }
 return true;
} 

bool Sudoku::iscorrect()
{
  int testarray[9];
  bool checkresult;

  for(int i=0;i<sudokusize;i+=9)
  {
    for(int j=0;j<9;j++)
    { 
      testarray[j]=map[i+j];
    }

    checkresult=check(testarray);
    if(checkresult==false)
    return false;

  }

  for(int i=0;i<9;i++)
  {
    for(int k=0;k<9;k++)
    {
     testarray[k]=map[i+9*k];
    }
    checkresult=check(testarray);
    if(checkresult==false)
    return false;   

  }
  
  for(int i=0;i<9;i++)
  { 
    int location=0;
    switch(i)
    {
      case 0:
      location=0;
      break;
      
      case 1:
      location=3;
      break;

      case 2:
      location=6;
      break;

      
      case 3:
      location=27;
      break;

      case 4:
      location=30;
      break;

      case 5:
      location=33;
      break;

      case 6:
      location=54;
      break;

      case 7:
      location=57;
      break;

      case 8:
      location=60;
      break;
    }


    for(int j=0;j<9;j++)
    {
      int index_k=0; 
      switch(j)
      {
        case 0:
        index_k=0;
        break;

        case 1:
        index_k=1;
        break;

        case 2:
        index_k=2;
        break;

        case 3:
        index_k=9;
        break;

        case 4:
        index_k=10;
        break;

        case 5:
        index_k=11;
        break;

        case 6:
        index_k=18;
        break;

        case 7:
        index_k=19;
        break;

        case 8:
        index_k=20;
        break;
      }

      testarray[j]=map[location+index_k];
    }
      checkresult=check(testarray);
      if(checkresult==false)
      return false;
  }

return true;
}


void Sudoku::giveQuestion()
{
  int casenumber=0;
  unsigned int seed=(unsigned int)time(NULL);
  srand(seed);
  int key=-1;
  
  ifstream data("quslibrary",ios::in);
  data >> casenumber;
 
  key=0+rand()%casenumber;
 // cout << key; cout << endl;
  int temp[81];
  Sudoku questionarray[casenumber];
 
  
 for(int i=0;i<casenumber;i++)
 {  
   for(int j=0;j<81;j++)
   { data >> temp[j]; }
   questionarray[i].setmap(temp);

 }  
    
   questionarray[key].print();
     
  


}

void Sudoku::readIn()

{ 
  cout << "input 81 number(1-9)" << endl;

  int temp[81];
  for(int i=0;i<81;i++)
  {  temp[i]=0; }

  for(int i=0;i<81;i++)
  {  
      cin >> temp[i];
  }

  setmap(temp);
}     


void Sudoku::solve()
{
  Sudoku::Sudoku ques;
  Sudoku::Sudoku ans;

   for(int i=0;i<81;i++)
   { 
     ques.setelement(i,map[i]);
   }

   if(solver(ques,ans)==true)
   { 
     
      ans.print();
     
      cout << "solve!" << endl;
    }

   else
   cout << "unsolve...." << endl;
}


bool Sudoku::solver(Sudoku question,Sudoku & answer)
{
  int blankindex;
  blankindex=question.getzero();

  if(blankindex==-1)
  { 
    if(question.iscorrect()==true)
    { answer=question; return true; }

    else
    { return false; }
  }

  else
  {
    for(int j=1;j<=9;j++)
    {  
       question.setelement(blankindex,j);
       if(question.iscorrect())
       {  
          if(solver(question,answer))
          { return true; }

       } 
    }
     return false;
  }
}


void Sudoku::print()
{
  for(int i=0;i<81;i++)
  { cout << map[i] << " ";
    if(i%9==8) { cout << endl; }
  }
}

 
void Sudoku::changeNum(int a,int b)
{
  int transform=0;
  int tempa=0;
  int tempb=0;

   
  for(int j=0;j<81;j+=9)
  {
    
   for(int k=0;k<9;k++)
   {
      if( map[k+j]==a )
      { tempa=k+j; }

      if( map[k+j]==b )
      { tempb=k+j; }

   }

    transform=map[tempa];
    map[tempa]=map[tempb];
    map[tempb]=transform;
    
  }
   
}

          
void Sudoku::changeRow(int a,int b)
{ 
  int temp=0;
  int rowa=a*3; int rowb=b*3;
  int numbera=rowa*9; int numberb=rowb*9;  

  for(int h=0;h<3;h++)
  { 
    int j=0; 
    for(int k=0;k<9;k++)
    {
      temp=map[numbera+k+j];
      map[numbera+k+j]=map[numberb+k+j]; 
      map[numberb+k+j]=temp;
    }
    j=j+9;

  }
}    


void Sudoku::changeCol(int a,int b)
{
  int temp;
  int cola=3*a; int colb=3*b;
  
  for(int h=0;h<3;h++)
  {
    for(int i=0;i<81;i+=9)
    { 
      temp=map[cola+i+h];
      map[cola+i+h]=map[colb+i+h];
      map[colb+i+h]=temp;
    }
  }

}








 




  


