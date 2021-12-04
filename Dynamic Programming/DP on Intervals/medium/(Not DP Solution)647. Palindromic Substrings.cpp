class Solution {
public:
    int res = 0;
    int countSubstrings(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        return res;
    }
    void expand(string s,int left,int right){
        bool flag = true;
        while(left>=0 && right<s.size() && flag){
            if(s[left]==s[right]){
                res++;
                left--;
                right++;
                flag = true;
            }else{
                flag = false;
            }
        }
    }
};