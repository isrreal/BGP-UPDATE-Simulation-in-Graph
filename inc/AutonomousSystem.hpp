#ifndef AUTONOMOUSSYSTEM_HPP
#define AUTONOMOUSSYSTEM_HPP

#include "Router.hpp"
#include <queue>

class AutonomousSystem {
private:
    inline static int ASIdentifier = 0;
    int identifier;
    int routerQuantity;
    int edgeQuantity;
    std::list<Router*> routers;
    std::vector<std::pair<int, int>> configuration;
public:
    AutonomousSystem(std::list<Router*> routers, std::vector<std::pair<int, int>> configuration);
    AutonomousSystem(const AutonomousSystem& AS);
    AutonomousSystem();
    ~AutonomousSystem();
   
    int getEdgeQuantity() { return this->edgeQuantity; }

    int getRouterQuantity() { return this->routerQuantity; }
    
    int getIdentifier() { return this->identifier; }

    std::list<Router*> getRouters() { return this->routers; }

    std::vector<std::pair<int, int>> getConfiguration() { return this->configuration; }

    void insertRouter(Router& router);

    void insertRouter(Router& router, std::vector<std::pair<int, int>> configuration);

    void configureEdges(std::vector<std::pair<int, int>> configuration);

    void breadthFirstTraversal(Router& router);

    void breadthFirstTraversal(Router& router, const std::string& message);

    bool depthFirstSearch(Router& router);

    friend std::ostream& operator<<(std::ostream& os, const AutonomousSystem& AutonomousSystem) {
        os << "Autonomous system: " << AutonomousSystem.identifier << std::endl;
        for (const auto& it : AutonomousSystem.routers) {
            if (it->BGPMessage.empty())
                os << *it << it->BGPMessage << std::endl;
            else
                os << *it << " Message: " << it->BGPMessage << std::endl;
        }
        os << std::endl;
        return os;
    }
};

#endif
