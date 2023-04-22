#include<bits/stdc++.h>
using namespace std;
// 远征队即将开启未知的冒险之旅，不过在此之前，将对补给车队进行最后的检查。supplies[i] 表示编号为 i 的补给马车装载的物资数量。
// 考虑到车队过长容易被野兽偷袭，他们决定将车队的长度变为原来的一半（向下取整），计划为：

// 找出车队中 物资之和最小 两辆 相邻 马车，将它们车辆的物资整合为一辆。若存在多组物资之和相同的马车，则取编号最小的两辆马车进行整合；
// 重复上述操作直到车队长度符合要求。
// 请返回车队长度符合要求后，物资的分布情况。
vector<int> supplyWagon(vector<int>& supplies) {
        int n=supplies.size();
        int count=n/2;
        
        
        if(n%2==0){
             count--;
        }
        cout<<count<<endl;
        vector<int> res;
        while(count>=0){
            auto del_it=supplies.begin();
            int min=INT_MAX;
            for(auto it=supplies.begin();it!=supplies.end();it++){
                if((it+1)!=supplies.end()&&*it+*(it+1)<min){
                    min=*it+*(it+1);
                    del_it = it;
                }
                
                
            }
            count--;
            del_it=supplies.erase(del_it);
            *del_it=min;
            
            
        }
        return supplies;
        
    }