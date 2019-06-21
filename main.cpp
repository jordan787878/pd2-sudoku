#include<iostream>
#include"Sudoku.cpp"
using namespace std;
int main(){
	
	//input the Sudoku qustion in the quesmap.
	int quesmap[81]={8,0,0,0,0,0,0,0,0,
                 	 0,0,3,6,0,0,0,0,0,
                 	 0,7,0,0,9,0,2,0,0,
                 	 0,5,0,0,0,7,0,0,0,
                 	 0,0,0,0,4,5,7,0,0,
                 	 0,0,0,1,0,0,0,3,0,
                 	 0,0,1,0,0,0,0,6,8,
                 	 0,0,8,5,0,0,0,1,0,
                 	 0,9,0,0,0,0,4,0,0};
	
	//put the question into su1 obj
	Sudoku su1(quesmap);
	cout << "Sudoku Question is:\n";
	su1.print();
	cout << endl;
	
	//solve it
	su1.solve();

return 0;	
}
