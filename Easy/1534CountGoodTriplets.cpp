class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int n=0;
            int l=arr.size();
            for(int i=0;i<l-2;i++){
                for(int j=i+1;j<l-1;j++){
                    if(abs(arr[i]-arr[j])>a) continue;
                    for(int k=j+1;k<l;k++){
                        if(abs(arr[j]-arr[k])<=b&&abs(arr[i]-arr[k])<=c)
                            n++;
                    }
                }
            }
            return n;
        }
    };