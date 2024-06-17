#include <bits/stdc++.h>
using namespace std;

// Two passes on the array O(n)+O(n)
bool check(vector<int> &nums){
    int n = nums.size();
    int i;
    for (i = 0; i < n - 1; i++){
        if (nums[i] > nums[i + 1])
            break;
    }
    ++i;
    for (int j = 0; j < n - 1; j++){
        int x = nums[(j + i) % n];
        int y = nums[(j + i + 1) % n];
        if (x > y)
            return 0;
    }
    return 1;
}


// One Pass O(n)
bool Optimal(vector<int> nums){
    int n = nums.size();
    int c = 0;
    for (int i = 0; i < n - 1; i++)
        if (nums[i] > nums[i + 1])
            c++;
    if (nums[n - 1] > nums[0])
        c++;
    if (c > 1)
        return 0;
    return 1;
}

int main(){
    vector<int> v = {3, 4, 5, 1, 2};
    cout << check(v) << endl;
}