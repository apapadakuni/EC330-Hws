// Copyright 2017 Andreas Papadakis apapadak@bu.edu


#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(int argc, char const *argv[]){
	string filename;
	filename = argv[1];
	ifstream myfile (filename);
	string line;
	string prevline;
	string biggestline;
	bool firstline=true;
	//cout << line.size();


	if (myfile.is_open()){
		while (getline (myfile, line) ){
		//	cout << line.size() << "      " << prevline.size() << '\n';
			if (line.size()>biggestline.size() and firstline == false){

				biggestline = line;
				
			}
			firstline = false;
			// biggestline = line;
			// cout << line << '\n';
			// cout << line.size() << '\n';

		}
		myfile.close();
		
	}
	cout << biggestline << endl;
	return 0;


}