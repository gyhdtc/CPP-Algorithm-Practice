#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
struct student{
	long long name;
	double score[4];
	int Rank[4];
	int best;
};
int h = -1;
bool cmp1(student a, student b){
	return a.score[h] > b.score[h];
}

int main(){
	int num, question;
	cin >> num >> question;
	student gyh[num];
	
	for(int i = 0; i < num; i++){
		cin >> gyh[i].name >> gyh[i].score[0] >> gyh[i].score[1] >> gyh[i].score[2];
		gyh[i].score[3] = (gyh[i].score[0] + gyh[i].score[1] + gyh[i].score[2])/3;
	}
	
	for(int i = 0; i < num; i++){
		cout<<gyh[i].name<<" ";
		for(int j = 0; j < 4; j++)
			cout<<gyh[i].score[j]<<" ";
		cout<<endl;
	}
	
	for(h = 0; h < 4; h++){
		sort(gyh, gyh+num, cmp1);
		gyh[0].Rank[h] = 1;
        for(int j = 1; j < num; j++){
            gyh[j].Rank[h] = j + 1;
			if(gyh[j].score[h] == gyh[j-1].score[h])
				gyh[j].Rank[h] = gyh[j-1].Rank[h];
        }
	}
	
	char out[4] = {'C','M','E','A'};
	int getname;
	int flag;
	int k;
	for(int i = 0; i < question; i++){
		cin >> getname;
		flag = 0;
		for(k = 0; k < num; k++){
			if(gyh[k].name == getname){
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			int min = gyh[k].Rank[0];
			int index = 0;
			for(int j = 1; j < 4; j++){
				if(gyh[k].Rank[j] <= min){
					min = gyh[k].Rank[j];
					index = j;
				}
			}
			cout << min << " " << out[index] << endl;
		} else {
			cout<< "N/A" << endl;
		}
	}
	return 0;
}
