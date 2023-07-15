class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size()==0 || s.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int res = 0;
        int m = g.size()-1, n = s.size()-1;
        for(int j=m;j>=0;j--){
            if(n<0) break;
            if(s[n]>=g[j]){
                res++;
                n--;
            }
        }
        return res;
    }
};