#include<bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& permutation) {

        // 1 using inbuild function
        // next_permutation(permutation.begin(), permutation.end());

        // 2 By Finding Breakpoint and swap then reverse
        int n = permutation.size();
        int index = -1;
        // find the break point where arr[i] < arr[i+1]
        for(int i=n-2; i>=0; i--){
            if(permutation[i] < permutation[i+1]){
                index = i;
                break;
            }
        }

        //if break point doen't exist then return first sorted permutataion
        if(index == -1){
            reverse(permutation.begin(), permutation.end());
            return;
        }
        
        //Now find the just bigger element than break point arr[i]
        for(int i=n-1; i>=0; i--){
            //as we know arr is in ascending order from back
            if(permutation[index]<permutation[i]){
                swap(permutation[index], permutation[i]);
                break;
            }
        }

        //for just above permutation reverse from index+1 to end
        reverse(permutation.begin()+index+1, permutation.end());
        // */
    }
};