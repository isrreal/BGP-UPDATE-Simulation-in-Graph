#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "AutonomousSystem.hpp"

class Network {
private:
    std::vector<AutonomousSystem*> topology;
    std::vector<std::pair<int, int>> configuration;
    int autonomousSystemQuantity;
    int routerQuantity;
    int edgeQuantity;
public:
    Network(AutonomousSystem& AS1, AutonomousSystem& AS2, Router& router1, Router& router2);
    
    int getRouterQuantity() { return this->routerQuantity; }

    int getAutonomousSystemQuantity() { return this->autonomousSystemQuantity; }

    int getEdgeQuantity() { return this->edgeQuantity; }

    std::vector<AutonomousSystem*> getTopology() { return this->topology; }

    std::vector<std::pair<int, int>> getConfiguration() { return this->configuration; };

    friend std::ostream& operator<<(std::ostream& os, const Network& network) {
        for (const auto& it : network.topology)
            os << *it;
        return os;
    }
};

#endif
