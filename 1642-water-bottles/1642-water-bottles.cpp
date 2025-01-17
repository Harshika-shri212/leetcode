class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank=0;
        while(numBottles>=numExchange){
            numBottles=numBottles-numExchange;
            drank=drank+numExchange;
            numBottles+=1;
        }
        drank=drank+numBottles;
        return drank;
    }
};