// Brute Force Approach - O(N^2 * M^2)
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    for(int p = i; p < m; p++){
                        for(int q = j; q < n; q++){
                            bool flag = true;
                            for(int x = i; x <= p; x++){
                                for(int y = j; y <= q; y++){
                                    if(!mat[x][y]){
                                        flag = false;
                                        break;
                                    }
                                }
                            }
                            if(flag) ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }


// Optimal Approach - O(M * M * N)

class Solution {
public:
    int countSubMatrices(vector<int>& nums, int n) {
        int ans = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                len = 0;
            } else {
                len++;
            }
            ans += len;
        }
        return ans;
    }

    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;
        for (int row = 0; row < m; row++) {
            vector<int> nums(n, 1);
            for (int i = row; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] && nums[j]) {
                        nums[j] = 1;
                    } else {
                        nums[j] = 0;
                    }
                }
                ans += countSubMatrices(nums, n);
            }
        }
        return ans;
    }
};
};
