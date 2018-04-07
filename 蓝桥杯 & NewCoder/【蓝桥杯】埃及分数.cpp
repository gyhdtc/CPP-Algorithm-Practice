#include <iostream>
using namespace std;
class Solution{
	public:
		Solution(int gyh){
			fenmu=gyh;
			cout<<"start porject:\n";
		}
		int fenmu;
		int getsolution(){
			jixianmin=(fenmu%2==0)?fenmu/2:fenmu/2+1;
			jixianmax=int(jixianmin*fenmu);
			int i = 0;
			int a1, a2;
			int min = jixianmin, max = jixianmax;
    		double shang;
    		for(a1 = min; a1 < fenmu; a1++){
	        	for(a2 = a1+1; a2 <= max; a2++){
				   if((a1 * a2) % fenmu == 0){
	      		   		shang=(a1 * a2)/fenmu;
	       	   		 	if((a1+a2)/shang==2){
				   			i++;
				   			cout<<a1<<"   "<<a2<<endl;
				   		}
            		}
        	 	}
   	 		}
   	 		return i;
		}
	private:
	int jixianmax;
	int jixianmin;	
}; 
int main(){
	int problem;
	cout<<"input your problem you want to solve:"<<endl;
	cin>>problem;
    Solution a(problem);
    int i;
	i=a.getsolution();
    cout<<"====================================="<<endl;
	cout<<i<<" kinds of soltions to your problem "<<problem<<endl;
	return 0;
}
