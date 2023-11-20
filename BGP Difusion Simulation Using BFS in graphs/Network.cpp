#include "Network.hpp"

Network::Network(AutonomousSystem& autonomousSystem1, AutonomousSystem& autonomousSystem2, Router& router1, Router& router2) {
    Router* source = nullptr;
    Router* destination = nullptr;
    this->routerQuantity = autonomousSystem1.getRouterQuantity() + autonomousSystem2.getRouterQuantity();
    this->edgeQuantity = autonomousSystem1.getEdgeQuantity() + autonomousSystem2.getEdgeQuantity();
    this->autonomousSystemQuantity = 0;

    for (const auto& it : autonomousSystem1.getRouters()) {
        if (*it == router1) {
            source = it;
            break;
        }
    }

    for (const auto& it : autonomousSystem2.getRouters()) {
        if (*it == router2) {
            destination = it;
            break;
        }
    }

    if (source && destination) {
        source->borderRouter = true;
        destination->borderRouter = true;
        this->topology.push_back(&autonomousSystem1);
        this->topology.push_back(&autonomousSystem2);

        std::vector<std::pair<int, int>> temp = autonomousSystem1.getConfiguration();
        temp.reserve(temp.size() + autonomousSystem2.getConfiguration().size());
        temp.insert(temp.end(), autonomousSystem2.getConfiguration().begin(), autonomousSystem2.getConfiguration().end());

        for (const auto& it : autonomousSystem1.getRouters())
            this->topology[0]->getRouters().push_back(it);

        for (const auto& it : autonomousSystem2.getRouters())
            this->topology[1]->getRouters().push_back(it);

        source->adjacencies.push_back(destination);
        destination->adjacencies.push_back(source);

        this->configuration = temp;
        this->autonomousSystemQuantity += 2;
    }
}
