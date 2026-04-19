#include <iostream>
#include <strings.h>
#include "api/SelicClient.hpp"

int main()
{
    SelicClient client;
    auto rates = client.fetchRate();

    for(const auto& r : rates)
    {
        std::cout << r.date << " -> " << r.value << std::endl;
    }

    return 0;
}