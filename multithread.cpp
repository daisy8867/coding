#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <chrono>
using namespace std;

// meaning of cnt:
// 10: there are no active readers or writers.
// 1...9: there are 9...1 readers active, The writer is blocked
// 0: temporary value between fetch_sub and fetch_add in reader lock
// -1: there is a writer active. The readers are blocked.
const int N = 10; // nine concurrent readers are allowed
//atomic<int> cnt(N);
//atomic_init(cnt, N);
atomic<int> cnt = ATOMIC_VAR_INIT(N);
 
vector<int> data;
 
void reader(int id)
{
    for(;;)
    {
        // lock
        while(atomic_fetch_sub(&cnt, 1) <= 0)
            atomic_fetch_add(&cnt, 1);
        // read
        if(!data.empty())
            cout << (  "reader " + to_string(id)
                          + " sees " + to_string(*data.rbegin()) + '\n');
        if(data.size() == 100)
            break;
        // unlock
        atomic_fetch_add(&cnt, 1);
        // pause
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}
 
void writer()
{
    for(int n = 0; n < 100; ++n)
    {
        // lock
        while(atomic_fetch_sub(&cnt, N+1) != N)
            atomic_fetch_add(&cnt, N+1);
        // write
        data.push_back(n);
        cout << "writer pushed back " << n << '\n';
        // unlock
        atomic_fetch_add(&cnt, N+1);
        // pause
        this_thread::sleep_for(chrono::milliseconds(1));
    }
}
 
int main()
{
    vector<thread> v;
    for (int n = 0; n < N; ++n) {
        v.emplace_back(reader, n);
    }
    v.emplace_back(writer);
    for (auto& t : v) {
        t.join();
    }
}
