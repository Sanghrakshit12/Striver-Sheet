#include <bits/stdc++.h>
using namespace std;

vector<int> Printsubarr(vector<int> nums){
    vector<int> temp;
    int sum = 0, res = INT_MIN;
    int n = nums.size();
    int str = 0, ansstr = -1, ansend = -1;
    for (int i = 0; i < n; i++){
        if (sum == 0)
            str = i;
        sum += nums[i];
        if (sum > res){
            res = sum;
            ansstr = str;
            ansend = i;
        }
        if (sum < 0)
            sum = 0;
    }
    return {ansstr, ansend};
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> res = Printsubarr(nums);
    for (auto i : res)
        cout << i << " ";
}