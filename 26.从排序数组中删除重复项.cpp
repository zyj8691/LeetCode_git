
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::vector<int>::iterator it = nums.begin();
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    nums.erase(it+j);
                }
                else{
                    break;
                }
            }
        }
        return nums.size();
    }
};

