class Solution {
public:
    double angleClock(int h, int m) {
        float totalh=(h%12 + (float) m/60) * 30;
        float min=m * 6;
        
        double angle= abs(totalh - min);
        
        if(angle>180) return 360 - angle;
        return angle;
    }
};