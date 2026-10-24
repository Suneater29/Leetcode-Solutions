class Solution {
public:
    int func(string date,vector<int> &days){
        int month=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        for(int i=0;i<month-1;i++){
            day+=days[i];
        }
        return day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aliceStart=func(arriveAlice,days);
        int aliceEnd=func(leaveAlice,days);
        int bobStart=func(arriveBob,days);
        int bobEnd=func(leaveBob,days);
        int start=max(aliceStart,bobStart);
        int end=min(aliceEnd,bobEnd);
        return max(0,end-start+1);
    }
};