class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.length();
        int n2=p.length();
        vector<bool> prev(n2+1,false),curr(n2+1,false);
        prev[0]=true;
        
        for(int j=1;j<=n2;j++){
            bool flag=true;
            for(int k=1;k<=j;k++){
            if(p[k-1]!='*'){
            flag=false;
            break;
            }
        }
        prev[j]=flag;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                 if(s[i-1]==p[j-1] || p[j-1]=='?')
             curr[j]=prev[j-1];
        
        else if(p[j-1]=='*')
        curr[j]=prev[j] || curr[j-1];

        else curr[j]=false;
            }
           prev=curr; 
        }
      

        return prev[n2];


    }


};
