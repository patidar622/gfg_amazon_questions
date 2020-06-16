class Solution {
public:
    string find_ipv4(string IP)
    {
        if(IP[0]=='.' || IP[IP.size()-1]=='.')
            return "Neither";
        int i=0,j;
        vector<string>vis;
        while(i<IP.size())
        {
           j=i;
            while(j<IP.size() && IP[j]!='.')
            {
                j++;
            }
            string s1=IP.substr(i,j-i);
            vis.push_back(s1);
             i=j+1;
        }
        if(vis.size()!=4)
           return "Neither";
        
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i].size()==0 || (vis[i][0]=='0' && vis[i].size()>1))
                return "Neither";
            
            if(vis[i].size()>3)
                return "Neither";
            
            for(int j=0;j<vis[i].size();j++)
            {
                if(vis[i][j]<'0' || vis[i][j]>'9')
                    return "Neither";
            }
            
            int i1=stoi(vis[i]);
            if(i1<0  || i1>255)
                return "Neither";
        }
        return "IPv4";
    }
    string find_ipv6(string IP)
    {
        if(IP[0]==':' || IP[IP.size()-1]==':')
            return "Neither";
        int i=0,j;
        vector<string>vis;
        while(i<IP.size())
        {
           j=i;
            while(j<IP.size() && IP[j]!=':')
            {
                j++;
            }
            string s1=IP.substr(i,j-i);
            vis.push_back(s1);
             i=j+1;
        }
         if(vis.size()!=8)
           return "Neither";
        
         for(int i=0;i<vis.size();i++)
        {
            if(vis[i].size()==0 || vis[i].size()>4)
                return "Neither";
             for(auto i1:vis[i])
             {
                      char c=tolower(i1);
                 if((c<'0'|| c>'9' ) && c!='a' && c!='b' && c!='c' && c!='d' && c!='e' && c!='f')
                     return "Neither";
             }
            
        }
        return "IPv6";   
    }
    string validIPAddress(string IP) {
        if(IP.size()==0)
            return "Neither";
        
        
        if(IP.find('.')!=string::npos)
           return find_ipv4(IP);
        if(IP.find(':')!=string::npos)
            return find_ipv6(IP);
    
        return "Neither";
    }
};
