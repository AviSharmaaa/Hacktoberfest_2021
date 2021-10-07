// Problem - Given an array of size at-least two, find the smallest subarray 
// that needs to be sorted in place so that the entire input array becomes
// sorted. If the input array is already sorted, the functions should return
//  [-1,-1], otherwise return the start and end index of the smallest subarray.

#include <bits/stdc++.h>
using namespace std;

bool outOfOrder(vector<int> input, int i){
    int x = input[i];
    if(i == 0)
        return x > input[1];
    if(i == input.size() - 1)
        return x < input[i - 1];
    
    return x > input[i + 1] || x < input[i - 1];
}

pair<int, int> smallestSubarray(vector<int> input){
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i = 0; i < input.size(); i++){
        if(outOfOrder(input, i)){
            smallest = min(smallest, input[i]);
            largest = max(largest, input[i]);
        }
    }
    cout << smallest << " " << largest << endl;
    if(smallest == INT_MAX)
        return {-1,-1};
    
    int left = 0;
    while(smallest >= input[left])
        left++;
    int right = input.size() - 1;
    while(largest < input[right])
        right--;

    return {left, right};
}

int main() {
    vector<int> input = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    pair<int, int> result = smallestSubarray(input);
    cout<< "{" << result.first << ", " << result.second << "}";
}
