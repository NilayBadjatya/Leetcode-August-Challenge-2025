class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dime) {
        int maxDiag = 0.0;
        int area = INT_MIN;
        for(auto& d : dime){
            int l = d[0];
            int b = d[1];
            int diag = (l * l) + (b * b);
            // diag = sqrt(diag);
            // cout << diag << " ";
            if(diag > maxDiag){
                area = l * b;
                maxDiag = diag;
            }else if(diag == maxDiag){
                area = max(area, l * b);
            }
        }
        return area;
    }
};
