// 探险家小扣的行动轨迹，都将保存在记录仪中。expeditions[i] 表示小扣第 i 次探险记录，用一个字符串数组表示。其中的每个「营地」由大小写字母组成，通过子串 -> 连接。

// 例："Leet->code->Campsite"，表示到访了 "Leet"、"code"、"Campsite" 三个营地。

// expeditions[0] 包含了初始小扣已知的所有营地；对于之后的第 i 次探险(即 expeditions[i] 且 i > 0)，如果记录中包含了之前均没出现的营地，则表示小扣 新发现 的营地。

// 请你找出小扣发现新营地最多且索引最小的那次探险，并返回对应的记录索引。如果所有探险记录都没有发现新的营地，返回 -1

#include<bits/stdc++.h>
using namespace std;
int adventureCamp(vector<string>& expeditions) {
        unordered_map <string ,int> umap;
        int res=0;
        int n=expeditions.size();
       
        
        vector<string> subs=tiqustring(expeditions[0]);
        for(auto s:subs){
            cout<<s<<endl;
            umap.emplace(s,1);
        }
        int max=0;
        int flag=0;
        for(int i =1;i<n;i++){
            
            vector<string> subs =tiqustring(expeditions[i]);
            int count=0;
            for(auto s:subs){
                
                if(umap.find(s)==umap.end()){
                    count++;
                    flag=1;
                    umap.emplace(s,1);
                }
                  
                
        }
            cout<<count<<endl;
            if(count>max){
                max=count;
                res=i;
            }


        
    }
        
        if(flag==0)
            return -1;
        return res;
    }
    
    vector<string> tiqustring(const string& s){
        int begin=0;
        int len=0;
        vector<string> result;
        int i=0;
        while(i<s.size()){
            int len=0;
            while(s[i]!='-'&&i+1!=s.size()){
                i++;
                len++;
                
            }
            if(i+1==s.size())
                len++;
            i+=2;
            
            result.emplace_back(s.substr(begin,len));
            begin=i;
        
        }
       
        return result;
        
    }
    