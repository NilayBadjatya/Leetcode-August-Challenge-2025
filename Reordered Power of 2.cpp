class Solution {
public:

    void solve(string& s, string& temp, unordered_set<string>& permut, vector<bool>& isUsed){
        if(temp.size() == s.size() && permut.count(temp) == 0 && temp[0] != '0'){
            permut.insert(temp);
            return;
        }
        for(int start = 0; start < s.size(); start++){
            if(isUsed[start] == 0){
                temp += s[start];
                isUsed[start] = 1;
                solve(s, temp, permut, isUsed);
                temp.pop_back();
                isUsed[start] = 0;
            }
        }
    }

    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        vector<bool> isUsed(s.size()+1, 0);
        string temp = "";
        unordered_set<string> permut;
        solve(s, temp, permut, isUsed);
        // for(auto& x : permut){
        //     cout << x << " ";
        // }
        for(auto& x : permut){
            int ele = stoi(x);
            for(int i = 0; i < 31; i++){
                int val = (1 << i);
                if(ele == val) return true;
            }
        }
        return false;
    }
};
