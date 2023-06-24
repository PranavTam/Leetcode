 const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
 
class Solution {
public:
int first(vector<int>& nums, int t,int s,int e)
{
    int mid=(e-s)/2+s;
    if(s>e)return -1;
    if(nums[mid]==t && ( mid==0 || nums[mid-1]!=nums[mid] ))return mid;
    if(nums[mid]<t){return first(nums,t,mid+1,e);}
    return first(nums,t,s,mid-1);
}
int second(vector<int>& nums, int t,int s,int e)
{
    int mid=(e-s)/2+s;
    if(s>e)return -1;
    if(nums[mid]==t && ( mid==nums.size()-1 || nums[mid+1]!=nums[mid] ))return mid;
    if(nums[mid]>t){return second(nums,t,s,mid-1);}
    return second(nums,t,mid+1,e);
}


vector<int> searchRange(vector<int>& nums, int t) {
        vector<int>v;
        v.push_back(first(nums,t,0,nums.size()-1));
         v.push_back(second(nums,t,0,nums.size()-1));
         return v;

    }
};