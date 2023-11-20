#include "Network.hpp"

int main() {
    AutonomousSystem* AS1 = new AutonomousSystem({new Router, new Router, new Router, new Router},
                                                 {{1, 2}, {2, 3}, {3, 4}, {4, 1}, {2, 4}});
    
    AutonomousSystem* AS2 = new AutonomousSystem({new Router, new Router, new Router, new Router},
                                                 {{5, 8}, {5, 6}, {6, 8}, {8, 7}});
    
    Router* borderRouterAS1 = new Router(*AS1->getRouters().back());
    Router* borderRouterAS2 = new Router(*AS2->getRouters().front());
    
    Network* network = new Network(*AS1, *AS2, *borderRouterAS1, *borderRouterAS2);
    
    Router* newRouter = new Router;
    
    network->getTopology()[1]->insertRouter(*newRouter, {{newRouter->identifier, 7}});
    
    return 0;
}
