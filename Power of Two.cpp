class Solution {
public:
    bool isPowerOfTwo(int n) {
        for(int i = 0; i <= 30; i++){
            int x = 1 << i;
            if(x == n){
                return true;
            }
        }
        return false;
    }
};
