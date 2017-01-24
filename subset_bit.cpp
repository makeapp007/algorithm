#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ret;
        int limit = (1 << nums.size()) - 1; // 2^n-1
        // sort(nums.begin(), nums.end());     // 排序，保证子集的是由小到大
        for (int i = 0; i <= limit; ++i) {  // 枚举 0 ~ 2^n-1
            vector<int> tp;
            int p = i, now = 0;
            while (p) {
                // 若该位为1，则表示该位需要存入子集
                if (p & 1 == 1) tp.push_back( nums[now] );
                p >>= 1, ++now;
            }
            ret.push_back(tp);
        }
        return ret;
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



