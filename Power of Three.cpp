// Iterative Approach
typedef long long ll;
class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int x = 0;; x++){
            ll power = (ll)pow(3, x);
            if(power == n) return true;
            if(power > n) return false;
        }
        return false;
    }
};
