#include <future>
#include <thread>
#include <iostream>


void do_work(std::promise<uint64_t> && promised_int) {
    promised_int.set_value(42);
}

int main() {
    std::promise<uint64_t> p_int;

    // f_int value is a future based on p_int promised value
    std::future<uint64_t> f_int = p_int.get_future();
    std::thread thread_1(do_work, std::move(p_int));

    thread_1.join(); 
    std::cout << f_int.get() << "\n";
}