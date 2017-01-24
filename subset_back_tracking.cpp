#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



// using backtracking algorithm
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs;
        vector<int> sub;  
        genSubsets(nums, 0, sub, subs);
        return subs; 
    }
    void genSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            genSubsets(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};


// test program
int main(){
	Solution a;
	vector<int> data={1,2,3,11};
	vector< vector<int> > result=a.subsets(data);
	cout<<"["<<endl;
	for(int i=0;i<result.size();i++){
		cout<<"    [";
		vector<int> tmp=result[i];
		for(int j=0;j<tmp.size();j++){
			cout<<tmp[j];
			if(j!=tmp.size()-1) cout<<",";
		}
		cout<<"],"<<endl;
	}
	cout<<"]";

	return 0;
}



