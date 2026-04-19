#pragma once

#include <string>
#include <vector>

struct SelicRate
{
    std::string date;
    double value;
};

class SelicClient
{
    public:
        SelicClient();
        std::vector<SelicRate> fetchRate();

    private:
        const std::string baseUrl = "https://api.bcb.gov.br/dados/serie/bcdata.sgs.11/dados?formato=json";
};