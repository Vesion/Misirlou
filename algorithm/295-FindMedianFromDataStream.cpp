#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// The key idea is to use two heaps, one max-heap(small) to store smaller half part, and one min-heap(large) to store larger half part.
// Then the top of small is the largest one of smaller half part, the top if large is the smallest one of larger half part.
// To deal with odd and even, we promise the size of small is 1 larger than large, or equal to large.

class MedianFinder {
private:
    priority_queue<int> small; // max-heap, store the smaller half part
    priority_queue<int, vector<int>, greater<int>> large; // min-heap, store the larger half part
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()) { // this condition only be true when insert the odd'th(1, 3, 5...) num
            small.push(large.top());
            large.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small.size() > large.size()) return small.top();
        return (small.top() + large.top()) * 0.5;
    }
};

int main() {
    MedianFinder f;
    f.addNum(1);
    f.addNum(2);
    f.addNum(3);
    f.addNum(4);
    cout << f.findMedian() << endl;

    return 0;
}
