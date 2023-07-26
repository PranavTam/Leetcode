class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1,e=1e7,ans=-1;
        bool f=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            double t=0;
            for(int i=0;i<dist.size()-1;i++)
            {
                if(dist[i]%mid!=0)t++;
                t+=dist[i]/mid;
            }
            t+=((double)dist[dist.size()-1])/mid;
            if(t<=hour)
            {
                f=1;
                e=mid-1;
                ans=mid;
            }
            else
            {
                s=mid+1;
            }
        }
        if(f)return ans;
        return -1;
    }
};