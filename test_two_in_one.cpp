#include <iostream>
#include <stdint.h>
#include <bitset>

#define MAKE_QWORD(HIGH_DWORD, LOW_DWORD) { (((int64_t)HIGH_DWORD << 32) | ( ((int64_t)LOW_DWORD) & 0xffffffff )) }
typedef union
    {
    struct
        {
        uint32_t lpd_id;
        uint32_t segment_id;
        };
    uint64_t data;
    } int64_stick;

int main()
    {
    int64_stick stick;
    uint32_t segment_id = 13;
    uint32_t lpd_id = 100000001;
    uint64_t id;
    stick.data = MAKE_QWORD(segment_id, lpd_id);
    std::cout << stick.data << " lpdid " << stick.lpd_id << " segment_id " << stick.segment_id << "\n";
    //stick.data  = (((int64_t)segment_id << 32) | ( ((int64_t)lpd_id) & 0xffffffff ));
    return 0;
    }
