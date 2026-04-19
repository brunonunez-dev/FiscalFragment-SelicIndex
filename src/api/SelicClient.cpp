#include <iostream>
#include "api/SelicClient.hpp"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <err.h>
#include <sol/sol.hpp>

SelicClient::SelicClient()
{

};

std::vector<SelicRate> SelicClient::fetchRate()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);
    sol::table config = lua.script_file("scripts/compliance.lua");

    std::string dataInicial = config["dataInicial"].get_or(std::string("01/01/2016"));
    std::string dataFinal = config["dataFinal"].get_or(std::string("18/04/2026"));

    std::vector<SelicRate> rates;
    auto response = cpr::Get(
        cpr::Url{baseUrl},
        cpr::Parameters{
            {"formato", "json"},
            {"dataInicial", dataInicial},
            {"dataFinal", dataFinal}
        },
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

