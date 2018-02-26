//Copyright 2017, Andreas Papadakis, apapadak@bu.edu U40766151
#include <iostream>
#include <string.h>

using namespace std;

// Given two sequences A and B, finds the longest sequence C such that
// C is a subsequence (not necessarily contiguous) of both A and B
string findMaxSubSeq(string str1, string str2)
{
	// the maximum common subsequence
	int len1 = str1.size();
	int len2 = str2.size();

	int D[len1+1][len2+2];


	for (int i=0; i<=len1; i++){
			for (int j=0; j <=len2; j++){
				if (i ==0 || j ==0){
					D[i][j] = 0; //make our first row and first column all be zeros
				}
				else if (str1[i-1] == str2[j-1]){
					D[i][j] = D[i-1][j-1]+1;
				}
				else D[i][j] = max(D[i-1][j], D[i][j-1]);
			}
	}
	//now we have our 2D Dynamic array D
	int Dindex=D[len1][len2]; //our last number in D is the length of our string;


	char result[Dindex+1];
	result[Dindex] = '\0';

	int i= len1;
	int j = len2;


	while (i > 0 && j>0){ //now we backtrack from the end of our matrix in order to form our string

		if (str1[i-1] == str2[j-1]){
			result[Dindex-1] = str1[i-1];
			//cout << "result is "<< result << endl;
			i--;
			j--;
			Dindex--;
		}

		else if (D[i-1][j] > D[i][j-1]) i--;
		//cout << D[i-1][j] << " " << D[i][j-1] << endl;
		else j--;

	}
	//we loop through from the end unt


	string subseq(result);


	// TODO: implement your algorithm here


	return subseq;
}

// (sample) main to test findMaxSubSeq
// The actual test cases may be different, this file is for demonstration of format only
int main(int argc, char const *argv[])
{
	// example sequences A, B
	//string a = "XMJYAUZ";
	//string b = "MZJAWXU";

    string a = argv[1];
    string b = argv[2];
    
	// TODO: add code to read two inputs, a and b, from the command-line, 
        //    and remove the above sample sequences


	// maximum subsequence in example sequences
	string maxSubSeq = findMaxSubSeq(a, b);

	cout << "Maximum common subsequence for " << a << " and " << b << " : " << maxSubSeq << endl;

	return 0;
}
