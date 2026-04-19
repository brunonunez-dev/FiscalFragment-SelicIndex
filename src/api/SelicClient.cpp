    #include <iostream>
    #include "api/SelicClient.hpp"
    #include <cpr/cpr.h>
    #include <nlohmann/json.hpp>
    #include <err.h>

    SelicClient::SelicClient()
    {

    };

    std::vector<SelicRate> SelicClient::fetchRate()
    {
        std::vector<SelicRate> rates;
        auto response = cpr::Get(
            cpr::Url{baseUrl},
            cpr::Parameters{{"formato", "json"}, {"dataInicial", "01/01/2026"}},
            cpr::Header{{"Accept", "application/json; charset=utf-8"}}
        
        );

        if(response.status_code == 200)
        {
            auto jsonData = nlohmann::json::parse(response.text);

            for(auto& entry :jsonData)
            {
                SelicRate rate;
                rate.date = entry["data"];
                rate.value = std::stod(entry["valor"].get<std::string>());
                rates.push_back(rate);
            };
        }
        else
        {
            std::cerr << "Failed to fetch Selic data. Status: " << response.status_code << std::endl;
        }
        return rates;
    };

