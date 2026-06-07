class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x/2 + 1;

        while(low <= high) {
            long long mid = low + (high-low) / 2;

            if(mid * mid == x) return mid;
            else if(mid * mid < x) low = mid + 1;
            else high = mid - 1;
        }

        return high;
    }
};