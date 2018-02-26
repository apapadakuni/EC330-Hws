// Copyright 2017 Andreas Papadakis apapadak@bu.edu

// Step by step algorirthm:
// First: need to extract the argument and turn into an integer
// Second: Realise the pattern
// 	(0,0) being the bottom left position
// 	just for the x's: always in pairs vertically, and
// 	that column = n; rows = n and n+1;
// 	just for the o's: if n is even: only one 0 with col = n+1, and row = n+1
// 					if n is odd: two o's with col = n+2 and rows = n and n+2
// Third: make if statements in order to print what we want, by incorporating
// the user inputed number n 			


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char const *argv[]){
string num = argv[1];

int n = stoi(num);

for (int i=0; i<10; i++){ //row
	for (int j=0; j<10; j++){ //column
		if ( (i >= (8-n) and j<=n) and (i==(9-j) or i==(9-(1+j))) ){
			cout << "X"; //done with printing 'X'
		}else if ( (n%2 == 0) and ((j == n+1) and (i == 9-j)) ){
			cout << "O";
		} 
		else if ( (n%2 == 1) and ((j == n+2) and (i==11-j || i == 9-j))){
			cout << "O";
		}
		else
		cout << "_";
	}
	cout << endl;
}

}