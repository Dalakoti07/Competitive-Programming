class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  		int nums1L=nums1.size();
  		int nums2L=nums2.size();
  		int a,b;
  		bool odd=false;
  		if((nums2L+nums1L)%2)
  		{
  			odd=true;// if odd then a=b=midpoint and avg taken, less a!=b
  		}
  		// simply merge two arrays and it would take O(n+m)
  		int i=0,j=0,k=0;
  		int arr[nums1L+nums2L];
  		for(;i<nums1L and j<nums2L;)
  		{
  			if(nums1[i]<nums2[j])
  				arr[k++]=nums1[i++];
  			else
  				arr[k++]=nums2[j++];
  		}
  		while(i<nums1L){
  			arr[k++]=nums1[i++];
  		}
  		while(j<nums2L){
  			arr[k++]=nums2[j++];
  		}
  		if(odd){
  			return arr[((nums2L+nums1L+1)/2)-1];
  		}
  		else{
  			double x=1.0;
  			return (arr[((nums2L+nums1L)/2)-1]+arr[(nums2L+nums1L)/2])/(2*x);
  		}
    }
};