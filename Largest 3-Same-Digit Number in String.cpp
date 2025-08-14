class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        while(j < n){
            mp[num[j]]++;
            if(j - i + 1 < 3){
                j++;
            }else if(j - i + 1 == 3){
                if(mp.size() == 1){
                    ans = max(ans, num.substr(i, 3));
                }
                mp[num[i]]--;
                if(mp[num[i]] == 0){
                    mp.erase(num[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
