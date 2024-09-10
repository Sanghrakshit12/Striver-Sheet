#include <iostream>
using namespace std;

int countLessEqual(int mid, int N) {
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        count += min(mid / i, N);
    }
    return count;
}

string findMedian(int N) {
    int low = 1, high = N * N;
    int desiredCount = (N * N) / 2 + 1; // because we need the (N*N)/2 + 1 element for the median
    
    while (low < high) {
        int mid = (low + high) / 2;
        if (countLessEqual(mid, N) < desiredCount) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return to_string(low);
}

int main() {
    int N;
    cin >> N;
    
    cout << findMedian(N) << endl;
    
    return 0;
}