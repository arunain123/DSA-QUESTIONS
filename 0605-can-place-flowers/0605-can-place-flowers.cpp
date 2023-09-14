class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=0;
        while(i<flowerbed.size()){
            if((i==0 || flowerbed[i-1]==0) && (i==flowerbed.size()-1 || flowerbed[i+1]==0) && flowerbed[i]==0){
                n--;
                i+=2;
            }
            else i++;
        }
        return n<=0;
    }
};