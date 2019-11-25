#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> container; //临时缓存
        vector<int> nVectorRes; //返回结果
        int nLen = nums.size();
        for(int i =0;i<nLen;i++){
            if(container.find(nums[i]) !=container.end()){
                nVectorRes.push_back(container[nums[i]]);
                nVectorRes.push_back(i);
                return nVectorRes;
            }else{
                container[target - nums[i]] = i;
            }
        }
        return nVectorRes;
    }
};


int main(int argc,char * argv[]){
    vector<int> vectorNum = {43,20,17,20,28,14,23,15};//c11可以定义并初始化，c98不行，会报错
    int sumValue = 40;
    Solution obj = Solution();
    vector<int> res = obj.twoSum(vectorNum,sumValue);
    for(auto _t : res){
        cout<<_t<<endl;
    }
    return 0;
}