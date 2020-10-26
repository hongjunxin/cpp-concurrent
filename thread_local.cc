#include <thread>
#include <iostream>
#include <chrono>
#include <assert.h>

int main(int argc, char** argv)
{
    thread_local int a = 0;

    std::thread t([=]{
        a += 1;
        std::chrono::seconds(1);
        assert(a == 1);
    });

    a += 2;
    assert(a == 2);
    t.detach();

    std::cout << "Test passed" << std::endl;
    return 0;
}