const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
 



class Solution {
public:
int find(vector<int>& nums,int s,int e)
{
     int mid=(s+e)/2;
     while(s<e){
         if(nums[mid]>nums[e])s=mid+1;
         else if(nums[mid]<nums[e])e=mid;
         else e--;
         mid=(s+e)/2;
     }
     return mid;
}
int bsearch(vector<int>& nums,int s,int e,int t)
{
    int mid=(s+e)/2;
    if(s>e)return -1;
    if(nums[mid]==t)return mid;
    if(nums[mid]<t) return bsearch(nums,mid+1,e,t);
    return bsearch(nums,s,mid-1,t);
}
    int search(vector<int>& nums, int target) {
         int p=find(nums,0,nums.size()-1);
         if(nums[p]==target)return p;
      return max(bsearch(nums,p,nums.size()-1,target), bsearch(nums,0,p-1,target));


    }
};