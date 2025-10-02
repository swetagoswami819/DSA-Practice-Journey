class Solution {
public:

 // helper function to compute mid^n safely
 long long power(long long mid, int n, int m) {
        long long ans = 1;
        for (int i=0;i<n;i++) {
            ans = ans * mid;
            if (ans > m) return ans; // stop early if exceeds m
        }
        return ans;
    }
  int NthRoot(int N, int M) {
      int low=1;
      int high=M;

      while(low<=high){
        int mid=(low+high)/2;
        long long val = power(mid, N, M);
        if(val==M){
          return mid;
        }
        else if(val>M){
          high=mid-1;
        }
        else{
          low=mid+1;
        }
      }
      return -1;
      
       
    }
};

