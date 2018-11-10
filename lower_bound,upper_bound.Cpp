#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int lower_bound(const vector<int> &nums,int start,int end,int num)
{
    int mid,lower_b=-1;
    
    while(start<=end)
    {
        
        mid=start+(end-start)/2;
        if(nums[mid]==num)
        {
            lower_b=mid;
            end=mid-1;
        }
        else if(nums[mid]>num)
        end=mid-1;
        else
        start=mid+1;
        
    }
    
    return lower_b;
    
    
    
}

int upper_bound(const vector<int> &nums,int start,int end,int num)
{
    int mid,upper_b=-1;
    
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(nums[mid]==num){
        upper_b=mid;
        start=mid+1;
    }
        else if(nums[mid]<num)
        start=mid+1;
        else
        end=mid-1;
    }
    
    return upper_b;
}



vector<int> searchRange(const vector<int> &A, int B) {
   vector<int> ans;
   ans.push_back(lower_bound(A,0,A.size()-1,B));
    ans.push_back(upper_bound(A,0,A.size()-1,B));
    return ans;
}

int main()
{
	vector<int> A={2,3,4,4,5};
	int b=4;
	vector<int> ans=searchRange(A,b);
	cout<<ans[0]<<" "<<ans[1];
	return 0;
}
