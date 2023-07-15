#include <set>
#include <algorithm>

class MyCalendar {
public:
    set<pair<int, int> > rec;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        pair<int, int> p{start, end - 1};
        if (rec.empty()) {
            rec.insert(p);
            return true;
        }
        // 如果能找到这个bound
        // 那么必然是以下2种情况之一
        // it->first = start 且 it->second >= end
        // 或者it->first > start
        auto it = lower_bound(rec.begin(), rec.end(), p);
        if (it == rec.begin()) {
            // 检测是否有重叠
            if (end > it->first) {
                return false;
            }
        } else if (it == rec.end()) {
            it--;
            if (start <= it->second) {
                return false;
            }
        } else {
            // 如果找到的有交叉
            if (it->first < end) {
                return false;
            }
            it--;
            if (it->second >= start) {
                return false;
            }
        }
        rec.insert(p);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */