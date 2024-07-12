class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n =words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),[](string &s1,string &s2){
              return s1.size()<s2.size();
        });
        int maxi=1;
        for(int ind=0;ind<n;ind++){
           for(int prev=0;prev<ind;prev++){
            if(iscompare(words[ind],words[prev]) && 1+dp[prev]>dp[ind]){
                dp[ind]=1+dp[prev];
            }
           }
           maxi=max(dp[ind],maxi);
        }
        return maxi;
    }
    
    bool iscompare(string &s1,string &s2){
      if(s1.size()!=s2.size()+1) return false;

      int first=0,second=0;

      while(first<s1.size()){
        if(second<s2.size() && s1[first]==s2[second]){
            first++;
            second++;
        }
        else
        first++;
      }
        if(first==s1.size() && second==s2.size()) return true;
        else
        return false;
      
   
    }
};
