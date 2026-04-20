/*
 * This file is part of the project version released under the MIT License.
 * Up to release v1.0.0 (branch legacy-mit), the project was licensed under MIT.
 *
 * See the LICENSE file in this branch for details.
 */


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