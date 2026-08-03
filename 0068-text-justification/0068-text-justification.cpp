class Solution{
public:
    vector<string> fullJustify(vector<string>& words,int maxWidth){
        vector<string> ans;
        int n=words.size(),i=0;
        while(i<n){
            int j=i,len=0;
            while(j<n&&len+words[j].size()+j-i<=maxWidth){
                len+=words[j].size();
                j++;
            }
            int gaps=j-i-1;
            string s;
            if(j==n||gaps==0){
                s=words[i];
                for(int k=i+1;k<j;k++)s+=" "+words[k];
                s+=string(maxWidth-s.size(),' ');
            }else{
                int spaces=maxWidth-len;
                int each=spaces/gaps;
                int extra=spaces%gaps;
                for(int k=i;k<j-1;k++){
                    s+=words[k];
                    s+=string(each+(extra>0),' ');
                    if(extra)extra--;
                }
                s+=words[j-1];
            }
            ans.push_back(s);
            i=j;
        }
        return ans;
    }
};