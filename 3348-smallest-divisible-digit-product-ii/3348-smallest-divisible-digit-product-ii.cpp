class Solution {
public:
    long long e2=0,e3=0,e5=0,e7=0;
    int digitExp[10][4]; // a,b,c,d for digits 0..9 (0 unused)
    
    // extra table for (r2,r3) combos: keys 0..2 for r2, 0..1 for r3
    int extraTable[3][2] = {
        {0,1}, // r2=0: r3=0->0, r3=1->1
        {1,1}, // r2=1: r3=0->1, r3=1->1
        {1,2}  // r2=2: r3=0->1, r3=1->2
    };
    
    long long M(long long a, long long b, long long c, long long d) {
        long long q8 = a/3, r2 = a%3;
        long long q9 = b/2, r3 = b%2;
        return c + d + q8 + q9 + extraTable[r2][r3];
    }
    
    vector<int> greedyFill(vector<long long> remaining, long long slots) {
        vector<int> res;
        vector<long long> rem = remaining;
        long long sl = slots;
        for (long long s = 0; s < slots; s++) {
            for (int d = 1; d <= 9; d++) {
                long long nr0 = max(rem[0]-digitExp[d][0], 0LL);
                long long nr1 = max(rem[1]-digitExp[d][1], 0LL);
                long long nr2 = max(rem[2]-digitExp[d][2], 0LL);
                long long nr3 = max(rem[3]-digitExp[d][3], 0LL);
                if (M(nr0,nr1,nr2,nr3) <= sl-1) {
                    res.push_back(d);
                    rem = {nr0,nr1,nr2,nr3};
                    sl--;
                    break;
                }
            }
        }
        return res;
    }
    
    string smallestNumber(string num, long long t) {
        long long tt = t;
        while (tt % 2 == 0) { tt /= 2; e2++; }
        while (tt % 3 == 0) { tt /= 3; e3++; }
        while (tt % 5 == 0) { tt /= 5; e5++; }
        while (tt % 7 == 0) { tt /= 7; e7++; }
        if (tt != 1) return "-1";
        
        // digitExp table
        int de[10][4] = {
            {0,0,0,0}, // 0 unused
            {0,0,0,0}, // 1
            {1,0,0,0}, // 2
            {0,1,0,0}, // 3
            {2,0,0,0}, // 4
            {0,0,1,0}, // 5
            {1,1,0,0}, // 6
            {0,0,0,1}, // 7
            {3,0,0,0}, // 8
            {0,2,0,0}  // 9
        };
        for (int i=0;i<10;i++) for(int j=0;j<4;j++) digitExp[i][j]=de[i][j];
        
        int n = num.size();
        vector<int> dl(n);
        for (int i=0;i<n;i++) dl[i] = num[i]-'0';
        
        // Step 1: check num itself
        bool hasZero = false;
        for (int x : dl) if (x==0) { hasZero = true; break; }
        if (!hasZero) {
            long long c2=0,c3=0,c5=0,c7=0;
            for (int x : dl) {
                c2 += digitExp[x][0];
                c3 += digitExp[x][1];
                c5 += digitExp[x][2];
                c7 += digitExp[x][3];
            }
            if (c2>=e2 && c3>=e3 && c5>=e5 && c7>=e7) return num;
        }
        
        vector<long long> cum2(n+1,0), cum3(n+1,0), cum5(n+1,0), cum7(n+1,0);
        for (int i=0;i<n;i++) {
            int x = dl[i];
            int a=0,b=0,c=0,d=0;
            if (x>=1 && x<=9) { a=digitExp[x][0]; b=digitExp[x][1]; c=digitExp[x][2]; d=digitExp[x][3]; }
            cum2[i+1]=cum2[i]+a;
            cum3[i+1]=cum3[i]+b;
            cum5[i+1]=cum5[i]+c;
            cum7[i+1]=cum7[i]+d;
        }
        
        int z = n;
        for (int i=0;i<n;i++) if (dl[i]==0) { z=i; break; }
        
        string ans = "";
        bool found = false;
        int upper = min(n-1, z);
        
        for (int i = upper; i >= 0; i--) {
            long long p2=cum2[i], p3=cum3[i], p5=cum5[i], p7=cum7[i];
            long long r = n-i-1;
            int foundD = -1;
            vector<long long> remaining;
            for (int d = dl[i]+1; d <= 9; d++) {
                long long nr0 = max(e2-p2-digitExp[d][0], 0LL);
                long long nr1 = max(e3-p3-digitExp[d][1], 0LL);
                long long nr2 = max(e5-p5-digitExp[d][2], 0LL);
                long long nr3 = max(e7-p7-digitExp[d][3], 0LL);
                if (M(nr0,nr1,nr2,nr3) <= r) {
                    foundD = d;
                    remaining = {nr0,nr1,nr2,nr3};
                    break;
                }
            }
            if (foundD != -1) {
                vector<int> suffix = greedyFill(remaining, r);
                string s = num.substr(0,i) + char('0'+foundD);
                for (int dd : suffix) s += char('0'+dd);
                ans = s;
                found = true;
                break;
            }
        }
        
        if (found) return ans;
        
        long long Mreq = M(e2,e3,e5,e7);
        long long L = max((long long)(n+1), Mreq);
        vector<long long> req = {e2,e3,e5,e7};
        vector<int> digits = greedyFill(req, L);
        string res = "";
        for (int d : digits) res += char('0'+d);
        return res;
    }
};