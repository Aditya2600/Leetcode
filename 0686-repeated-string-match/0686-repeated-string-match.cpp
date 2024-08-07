class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        string tp = a;
        int ans = 1;
        while(a.size() < b.size()){
            a += tp;
            ans++;
        }
        if(ck(a,b)){
            return ans;
        }
        if(ck(a+tp,b)){
            return ans+1;
        }
        return -1;
    }
    bool ck(string a, string b){
        int n = a.size();
        int m = b.size();
        for(int i=0; i<=n-m; i++){
            int j;
            for(j=0; j<m; j++){
                if(a[i+j] != b[j]){
                    break;
                }
            }
            if(j == m)return 1;
        }
        return 0;
    }
};