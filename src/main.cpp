#include <iostream>

#include <activities.h>
#include <fetcher.h>

int main() {
    Fetcher::Activities list;
    auto k = nlohmann::json::object();

    std::optional<json> temp;

    //Showing stateless style

    temp = Fetcher::DataFetcher::GetRandomActivity();

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByType(Fetcher::ActivityType::busywork);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByKey(3943506);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByParticipants(1);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByPrice(0.1);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByPriceRange(0.1, 1.0);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByAccessibility(0.1);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    temp = Fetcher::DataFetcher::GetActivityByAccessibilityRange(0.1, 1.0);

    if (temp) {
        k = *temp;
        list.AddActivity(k);
    }

    //Showing state style

    Fetcher::DataFetcher fetcher;
    fetcher.SetMinPrice(0);
    fetcher.SetParticipants(2);

    temp = fetcher.Fetch();
    if (temp) {
        k = *temp;
        std::cout << k;
        list.AddActivity(k);
    }

    fetcher.SetKey(3943506);

    temp = fetcher.Fetch();
    if (temp) {
        k = *temp;
        std::cout << k;
        list.AddActivity(k);
    }

    std::cout << list.dump() << std::endl;

    std::cout << "Showing 'delete' functionality" << std::endl;

    list.DeleteActivity(0);
    list.DeleteActivity(1);
    list.DeleteActivity(2);
    list.DeleteActivity(3);
    list.DeleteActivity(4);

    std::cout << list.dump();

    return 0;
}
