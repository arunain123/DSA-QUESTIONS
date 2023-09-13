class Solution {
public:
    #define c 1000000007
    
    int countOrders(int n) {
        long long ans=1;
        long long a=(long long)2*n;
        while(a>=2){
            long long val=(a*(a-1))/2;
            ans=((ans%c)*1l*(val%c))%c;
            a=a-2;
        }
        
        return (int)ans;
    }
};