#include <chrono>
#include <iostream>

int main()
{
    std::cout << std::boolalpha;
    std::cout << "high_resolution_clock::is_steady = "
              << std::chrono::high_resolution_clock::is_steady << "\n";
    std::cout << "steady_clock::is_steady           = "
              << std::chrono::steady_clock::is_steady << "\n";
    std::cout << "system_clock::is_steady           = "
              << std::chrono::system_clock::is_steady << "\n";
}
