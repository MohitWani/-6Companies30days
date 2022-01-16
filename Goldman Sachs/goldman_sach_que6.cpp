class Solution {
public:
    bool check(string &t,int k, string &h){
        int i=0,j=0;
        while(i<t.length()){
            if(t[i]!=h[j%k]){
                return false;
            }
            i++;j++;
        }
        return true;
    }
    string gcdOfStrings(string s, string t) {
        int n = s.length(), m = t.length();
        int k = __gcd(n,m);
        if(check(s,k,t) && check(t,k,t)){
            return t.substr(0,k);
        }
        return "";
        
    }
}
