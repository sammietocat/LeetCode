#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    // v1: by backtrack
    static vector<string> readBinaryWatch(int num) {
        vector<string> times;

        nextTime(times, 0, 0, num, 0);

        return times;
    }

    static void nextTime(vector<string> &times, int hour, int minute, const int num_LED, const int i) {
        if (0 == num_LED) {
            times.emplace_back(std::to_string(hour) + ":");
            times.back() += (minute < 10 ? "0" : "") + std::to_string(minute);

            return;
        } else if (10 - i == num_LED) {
            for (int j = i; j < 10; ++j) {
                if (j < 4) {
                    hour |= (1 << j);
                } else {
                    minute |= (1 << (j - 4));
                }
            }

            // ensure the valid range of hour and minute
            if ((hour < 12) && (minute < 60)) {
                times.emplace_back(std::to_string(hour) + ":");
                times.back() += (minute < 10 ? "0" : "") + std::to_string(minute);
            }

            return;
        }

        if (i < 4) {
            nextTime(times, hour, minute, num_LED, i + 1);

            hour |= (1 << i);
            if (hour >= 12) { return; }
            nextTime(times, hour, minute, num_LED - 1, i + 1);
        } else {
            nextTime(times, hour, minute, num_LED, i + 1);

            minute |= (1 << (i - 4));
            if (minute >= 60) { return; }
            nextTime(times, hour, minute, num_LED - 1, i + 1);
        }
    }
};

int main() {
    //int num_LED = 1;

    /*
    int num_LED = 2;
    // expected
    vector<string> expected_times{
            "0:03", "0:05", "0:06", "0:09", "0:10", "0:12", "0:17", "0:18", "0:20", "0:24", "0:33", "0:34", "0:36",
            "0:40", "0:48", "1:01", "1:02", "1:04", "1:08", "1:16", "1:32", "2:01", "2:02", "2:04", "2:08", "2:16",
            "2:32", "3:00", "4:01", "4:02", "4:04", "4:08", "4:16", "4:32", "5:00", "6:00", "8:01", "8:02", "8:04",
            "8:08", "8:16", "8:32", "9:00", "10:00"
    };
     */
    /*
    const int num_LED = 4;
    // expected
    vector<string> expected_times{
            "0:15", "0:23", "0:27", "0:29", "0:30", "0:39", "0:43", "0:45", "0:46", "0:51", "0:53", "0:54", "0:57",
            "0:58", "1:07", "1:11", "1:13", "1:14", "1:19", "1:21", "1:22", "1:25", "1:26", "1:28", "1:35", "1:37",
            "1:38", "1:41", "1:42", "1:44", "1:49", "1:50", "1:52", "1:56", "2:07", "2:11", "2:13", "2:14", "2:19",
            "2:21", "2:22", "2:25", "2:26", "2:28", "2:35", "2:37", "2:38", "2:41", "2:42", "2:44", "2:49", "2:50",
            "2:52", "2:56", "3:03", "3:05", "3:06", "3:09", "3:10", "3:12", "3:17", "3:18", "3:20", "3:24", "3:33",
            "3:34", "3:36", "3:40", "3:48", "4:07", "4:11", "4:13", "4:14", "4:19", "4:21", "4:22", "4:25", "4:26",
            "4:28", "4:35", "4:37", "4:38", "4:41", "4:42", "4:44", "4:49", "4:50", "4:52", "4:56", "5:03", "5:05",
            "5:06", "5:09", "5:10", "5:12", "5:17", "5:18", "5:20", "5:24", "5:33", "5:34", "5:36", "5:40", "5:48",
            "6:03", "6:05", "6:06", "6:09", "6:10", "6:12", "6:17", "6:18", "6:20", "6:24", "6:33", "6:34", "6:36",
            "6:40", "6:48", "7:01", "7:02", "7:04", "7:08", "7:16", "7:32", "8:07", "8:11", "8:13", "8:14", "8:19",
            "8:21", "8:22", "8:25", "8:26", "8:28", "8:35", "8:37", "8:38", "8:41", "8:42", "8:44", "8:49", "8:50",
            "8:52", "8:56", "9:03", "9:05", "9:06", "9:09", "9:10", "9:12", "9:17", "9:18", "9:20", "9:24", "9:33",
            "9:34", "9:36", "9:40", "9:48", "10:03", "10:05", "10:06", "10:09", "10:10", "10:12", "10:17", "10:18",
            "10:20", "10:24", "10:33", "10:34", "10:36", "10:40", "10:48", "11:01", "11:02", "11:04", "11:08", "11:16",
            "11:32"
    };


    auto times = Solution::readBinaryWatch(num_LED);
    cout << times.size() << ", expect " << expected_times.size() << endl;

    std::sort(std::begin(expected_times), std::end(expected_times));
    std::sort(std::begin(times), std::end(times));

    for (int i = 0; (i < times.size()) && (i < expected_times.size()); ++i) {
        cout << "i: ";
        if (times[i] == expected_times[i]) {
            cout << times[i] << "==" << expected_times[i] << endl;
        } else {
            cout << times[i] << "!=" << expected_times[i] << endl;
            break;
        }
    }
     */

    return 0;
}