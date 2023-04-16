#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
string minWindow(string s, string t);
bool check(const string& s, unordered_map<char, int> umap);
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
    //注释
    return 0;
}
string minWindow(string s, string t){
    string res;
    unordered_map<char, int > umap;
    if (s.size() < t.size())
        return "";
    for (char cha : t) {
        if (umap.count(cha)) {
            umap[cha]++;
        }
        else {
            umap.emplace(cha, 1);
        }
    }
    int begin = 0;
    int end = 0 + s.size();
    int flag = 0;
    int l = 0;
    int r = 0 + t.size();
    while (r <= s.size()) {
        string substr = s.substr(l, r-l);
        cout << substr << endl;
        if (check(substr, umap)) {
            flag = 1;
            if (r - l == t.size()) {
                begin = l;
                end = r;
                break;
            }
            else if (r - l < end - begin) {
                begin = l;
                end = r;
            }
            else
                l++;
        }
        else {
            r++;
        }

    }
    if (flag) {
        return s.substr(begin, end-begin);
    }
    return "";
}
bool check(const string& s, unordered_map<char, int> umap) {
    for (char cha : s) {
        auto it = umap.find(cha);
        if (it != umap.end()) {
            it->second--;
        }
    }
    for (auto iter = umap.begin(); iter != umap.end(); iter++) {
        if (iter->second > 0)
            return false;
    }
    return true;
}