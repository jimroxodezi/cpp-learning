#include <future>

uint64_t long_computation(uint64_t value);

uint64_t compute_and_sum(uint64_t value_1, uint64_t value_2) {
    auto future_1 = std::async(std::launch::deferred,
                    [value_1](){return long_computation(value_1); });
    
    auto future_2 = std::async(std::launch::deferred,
                    [value_2](){return long_computation(value_2); });

    return future_1.get() + future_2.get();
}


int main() {
    return 0;
}