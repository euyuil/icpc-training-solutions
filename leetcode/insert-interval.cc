/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {

    inline static void pushInterval(
        vector<Interval> &ret, Interval &interval) {

        if (ret.size() && ret.back().end >= interval.start) {
            ret.back().end = max(ret.back().end, interval.end);
        } else {
            ret.push_back(interval);
        }
    }

public:

    vector<Interval> insert(
        vector<Interval> &intervals, Interval newInterval) {

        bool inserted = false;
        vector<Interval> ret;

        for (int i = 0; i < intervals.size(); ++i) {
            if (!inserted && intervals[i].start >= newInterval.start) {
                inserted = true;
                pushInterval(ret, newInterval);
            }
            pushInterval(ret, intervals[i]);
        }

        if (!inserted) pushInterval(ret, newInterval);

        return ret;
    }
};
