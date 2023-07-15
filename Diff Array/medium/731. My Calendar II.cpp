/**
注意差分数组只需要维护区间首尾的计数即可
*/
#include <map>

class MyCalendarTwo {
public:
    map<int, int> m;
    MyCalendarTwo() { }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        int cnt = 0;
        for (auto &[k, v]: m) {
            cnt += v;
            if (cnt > 2) {
                m[start]--;
                m[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */