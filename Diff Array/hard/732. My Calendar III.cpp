#include <map>
#include <algorithm>
class MyCalendarThree {
public:
    map<int, int> m;
    MyCalendarThree() {

    }
    
    int book(int startTime, int endTime) {
        m[startTime]++;
        m[endTime]--;
        int cnt = 0, maxn = -1e9;
        for (auto &[k, v]: m) {
            cnt += v;
            maxn = max(maxn, cnt);
        }
        return maxn;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */