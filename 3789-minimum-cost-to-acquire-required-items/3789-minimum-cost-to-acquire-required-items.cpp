class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long price1=cost1;
        long long price2=cost2;
        long long both=costBoth;
        long long needa=need1;
        long long needb=need2;
        long long overlap=min(needa,needb);
        long long total=overlap*min(both,price1+price2);
        long long left1=needa-overlap;
        total+=left1*min(price1,both);
        long long left2=needb-overlap;
        total+=left2*min(price2,both);
        return total;

    }
};