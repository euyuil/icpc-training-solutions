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
public:
    vector<Interval> merge(vector<Interval> &intervals) {

        sort(intervals.begin(), intervals.end(),
            [](const Interval &a, const Interval &b) -> bool {
                return a.start < b.start;
            }
        );

        int delta = 0;

        for (int i = 1; i < intervals.size(); ++i) {
            int curr = i - delta, prev = curr - 1;
            if (prev >= 0) {
                if (intervals[prev].end >= intervals[i].start) {
                    intervals[prev].end = intervals[i].end;
                    ++delta;
                } else {
                    intervals[curr].start = intervals[i].start;
                    intervals[curr].end = intervals[i].end;
                }
            }
        }

        // maybe I shouldn't do it in-place?
        intervals.resize(intervals.size() - delta);

        return intervals;
    }
};
