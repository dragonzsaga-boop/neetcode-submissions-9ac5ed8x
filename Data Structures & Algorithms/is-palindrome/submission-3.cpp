class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r) {
            while(!isalnum(s[l])) ++l;
            while(!isalnum(s[r])) --r;
            if( l <= r && (tolower(s[l]) != tolower(s[r])) ) {
                // cout<<"'"<<s[l]<<"' ! '"<<s[r]<<"'"<<endl;
                return false;
            }
            ++l;
            --r;
        }
        return true;
    }
};
