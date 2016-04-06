#include<iostream>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include"Sudoku.h"
#include<vector>
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
  
   Sudoku question;
   int temp[81]={8,0,0,0,0,0,0,0,0,
                 0,0,3,6,0,0,0,0,0,
                 0,7,0,0,9,0,2,0,0,
                 0,5,0,0,0,7,0,0,0,
                 0,0,0,0,4,5,7,0,0,
                 0,0,0,1,0,0,0,3,0,
                 0,0,1,0,0,0,0,6,8,
                 0,0,8,5,0,0,0,1,0,
                 0,9,0,0,0,0,4,0,0};

   question.setmap(temp);
   question.transform(); 
        
  
}

void Sudoku::readIn()

{ 
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

  vector<int> tempa(81);
  vector<int> tempb(81);
  
  
  Sudoku quesa;
  
  Sudoku ansa;
  Sudoku multia;

   for(int i=0;i<81;i++)
   { quesa.setelement(i,map[i]); }


 
if(solvera(quesa,ansa)==true)
{
   /* for(int i=0;i<81;i++)
    { tempa.at(i)=ansa.getelement(i);    
    }
  
    if(multi(quesa,multia)==true)
    {
     for(int i=0;i<81;i++)
     { tempb.at(i)=multia.getelement(i); }
    }

 if(tempa!=tempb) { cout << '2' << endl; }*/
// else
 { cout << '1' << endl; ansa.print(); }

}
else
cout << '0' << endl;


 
}


bool Sudoku::solvera(Sudoku question,Sudoku & answer)
{
 
  int blankindex;
  blankindex=question.getzero();
  
  if(blankindex==-1)
  { 
    if(question.iscorrect()==true)
    { answer=question; return true; }

    if(question.iscorrect()==false)
    { return false; }
  }

  else
  { 
    for(int j=1;j<=9;j++)            
   {  
       question.setelement(blankindex,j);
       if(question.iscorrect())
       {  
          if(solvera(question,answer))
          { return true; }

       } 
    }
     return false;
   } 
  

}


bool Sudoku::multi(Sudoku question,Sudoku & answer)
{
  int blankindex;
  blankindex=question.getzero();
  if(blankindex==-1)
  { 
    if(question.iscorrect()==true)
    { answer=question; return true; }

    if(question.iscorrect()==false)
    { return false; }

  }
  else
  { 

    for(int j=9;j>=1;j--)       
    {  
       question.setelement(blankindex,j);
       if(question.iscorrect())
       {
          if(multi(question,answer))
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
  int indexa[81];
  int indexb[81];
  for(int i=0;i<81;i++)
  { indexa[i]=-1; indexb[i]=-1;}


  
  for(int i=0;i<81;i+=9)
  {
    
    for(int j=0;j<9;j++)
    {  
      
       if(map[i+j]!=0 && map[j+i]==a)
       {
         indexa[i]=j+i;
       }

       if(map[i+j]!=0 && map[i+j]==b)
       {
         indexb[i]=j+i;
       }
      
    }
     
  } 



  for(int i=0;i<81;i++)
  { 
      
      map[indexa[i]]=b;
    
      map[indexb[i]]=a;
  }

}

          
void Sudoku::changeRow(int a,int b)
{ 
  int temp=0;
  int q;
  if(a-b>0) {q=a-b;} else {q=b-a;}

  for(int h=0;h<27;h+=9)
  { 
     
    for(int k=0;k<9;k++)
    {
      temp=map[h+k];
      map[h+k]=map[h+k+q*27]; 
      map[h+k+q*27]=temp;
    }
    

  }
}    


void Sudoku::changeCol(int a,int b)
{ 
  int temp=0;
  int q;
  if(a-b>0) {q=a-b;} else {q=b-a;}

  for(int h=0;h<3;h++)
  { 
    for(int k=0;k<81;k+=9)
    {
      temp=map[h+k];
      map[h+k]=map[h+k+q*3]; 
      map[h+k+q*3]=temp;
    }
    
  }
}    


void Sudoku::rotate(int n)
{
 
 
  int tempstore[81];
  for(int i=0;i<81;i++)
  { tempstore[i]=0; }
  
 if(n%4==1)
 {     
  int i;  int h;
  for(i=0;i<81;i+=9)
   {  int q=i/9;
      int j=8-q;
      int k=0;

      for(h=0;h<9;h++)
      { 
        tempstore[j+k]=map[i+h]; 
        k=k+9;  
      }        

    }
    setmap(tempstore);
 }   
  
 if(n%4==2)
 {
   for(int i=0;i<81;i+=9)
   {
     for(int j=0;j<9;j++)
     {
       tempstore[80-i-j]=map[i+j];
     }  
   }
   setmap(tempstore);
 }

 if(n%4==3)
 {  
   int k=72;
   for(int i=0;i<81;i+=9)
   {
     int h=0;
     
     for(int j=0;j<9;j++)
     {  
        tempstore[k-h]=map[i+j];
        h+=9; 
     }
    
     k++;
   }
   setmap(tempstore);
 }



}
    
void Sudoku::flip(int n)
{
  int tempstore[81];
  for(int i=0;i<81;i++)
  { tempstore[i]=0; }

  if(n==0)
  {
    int k=72;
    for(int i=0;i<81;i+=9)
    { 
     
      for(int j=0;j<9;j++)
      { 
        tempstore[k+j]=map[i+j];
      }
      
      k=k-9;
    }

    setmap(tempstore);
  }
 
  if(n==1)
  {
    for(int i=0;i<9;i++)
    {
     for(int j=0;j<81;j+=9)
     { 
       tempstore[j+8-i]=map[i+j];
     }
    }
   setmap(tempstore);
  }
 
}

void Sudoku::transform()
{
  change();
  print();
}

void Sudoku::change()
{
  unsigned int seed=(unsigned int)time(NULL);
  srand(seed);

  int a=1+rand()%9; int b=1+rand()%9;
  
  while(a==b)
  { a=1+rand()%9; }
 
  changeNum(a,b);

  int c=0+rand()%3; int d=rand()%3;
  while(c==d)
  { c=rand()%3; }
  
  changeRow(c,d);


  int e=0+rand()%3; int f=rand()%3;
  while(e==f)
  { e=rand()%3; }

  changeCol(e,f);
  
  int g=0+rand()&100;
  rotate(g); 

  int h=0+rand()%2;
  flip(h);

}

