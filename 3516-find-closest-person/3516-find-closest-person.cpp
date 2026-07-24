class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distY = abs(z-y);
        int distX= abs(z-x);

    
        if(distY > distX)return 1;
        if(distY<distX)return 2;

        return 0;
    }
};