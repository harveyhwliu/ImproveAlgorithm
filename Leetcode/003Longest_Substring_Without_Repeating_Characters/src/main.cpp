#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> container;
        int nLen = s.length();
        int nRes = 0;
        while(nLen >=0){

            nLen --;
        }
        return nRes;
    }
};



int main(int argc,char * argv[]){
    Solution obj = Solution();
    string str = "abacddd";
    cout<<obj.lengthOfLongestSubstring(str);

    return 0;
}