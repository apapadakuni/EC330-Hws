//Andreas Papadakis apapadak@bu.edu	 BU ID: U40766151
#include <iostream>
#include <vector>
using namespace std;



int sum(vector <int> vec){
	int summ=0;
	for (int i=0; i<vec.size(); i++){
		summ=summ+vec[i];
	}
	return summ;
}

void MaxIncSeq(int *nums, int len){

vector <int> positions;
vector <int> temppos;
int fromthere;
int firstrun=false;


for (int i=0; i<len; i++){
	for (int k=i; k<len; k++){
		fromthere=i;
		for (int j=k+1; j<len; j++){
			if (nums[fromthere]<nums[j]) {
				if (positions.size()==0){
					positions.push_back(nums[i]);
				}
				positions.push_back(nums[j]);
				fromthere=j;
			}
		}
		if (firstrun==true && temppos.size()<positions.size()){
			temppos=positions;
		}
		else {
			if (firstrun==true && temppos.size()==positions.size() && sum(temppos)<sum(positions)){
				temppos=positions;
			}
		}
		if (firstrun==false){
			temppos=positions;
		}
		firstrun=true;
		positions.erase(positions.begin(),positions.end());


	}	
}


for (int i=0; i<temppos.size(); i++){
	cout <<  temppos[i] << " ";	
}
cout << endl;




}


int main(){

int vec[6];
vec[0]=7;
vec[1]=4;
vec[2]=1;
vec[3]=10;
vec[4]=23;
vec[5]=2;

MaxIncSeq(vec, 6);
return 0;

}
