#include "AutonomousSystem.hpp"

// Constructors

AutonomousSystem::AutonomousSystem(std::list<Router*> routers,
    std::vector<std::pair<int, int>> configuration): 
        routers(routers),
        routerQuantity(routers.size()),
        edgeQuantity(0), identifier(++AutonomousSystem::ASIdentifier) {
            this->configureEdges(configuration);
            for (const auto& it : routers) {
                it->ASIdentifier = this->identifier;
                this->edgeQuantity += it->adjacencies.size();
            }
            this->edgeQuantity /= 2;           
            this->configuration = configuration;    
}

AutonomousSystem::AutonomousSystem(const AutonomousSystem& autonomousSystem) {
    this->routers = autonomousSystem.routers;
    this->routerQuantity = autonomousSystem.routerQuantity; 
    this->edgeQuantity = autonomousSystem.edgeQuantity;
}

AutonomousSystem::AutonomousSystem() {}

// Destructor
AutonomousSystem::~AutonomousSystem() {
    for (auto& it : routers) 
        delete it;
}

void AutonomousSystem::insertRouter(Router& router) {
    this->routers.push_back(&router);
    ++this->routerQuantity;
}

void AutonomousSystem::insertRouter(Router& router, std::vector<std::pair<int, int>> configuration) {
    router.ASIdentifier = this->identifier;
    std::string message = std::to_string(router.identifier).append("(" + std::to_string(router.ASIdentifier) + ") Added!");
    this->routers.push_back(&router);
    ++this->routerQuantity;
    this->configureEdges(configuration);
    this->breadthFirstTraversal(router, message); 
}

void AutonomousSystem::configureEdges(std::vector<std::pair<int, int>> configuration) {
    Router* v1 = nullptr;
    Router* v2 = nullptr;
    for (const auto& config : configuration) {
        int source = config.first;
        int destination = config.second;
        for (const auto& it : routers) {
            if (it->identifier == source) {
                v1 = it;
                break;
            }
        }

        for (const auto& it : routers) {
            if (it->identifier == destination) {
                v2 = it;
                break;
            }
        }

        if (v1 && v2) { 
            v1->adjacencies.push_back(v2);
            v2->adjacencies.push_back(v1);
            for (const auto& it : routers) 
                this->edgeQuantity += it->adjacencies.size();
            this->edgeQuantity /= 2;
        }
    }
}

void AutonomousSystem::breadthFirstTraversal(Router& router, const std::string& message) {
    std::vector<bool> visited(this->routerQuantity, false);
    std::queue<Router*> queue;
    std::string path = "";
    visited[router.identifier] = true;
    queue.push(&router);
    while (!queue.empty()) {
        Router* v = queue.front();
        queue.pop();
        if (v->borderRouter && queue.front()->borderRouter)
            std::cout << "Interdomain Message! " << "to Border Router: " << v->identifier << "(" << v->ASIdentifier << ")" << std::endl;
        path += v->toString();
        std::cout << v->identifier << " " << 
                message << " Path: " << path << std::endl;
        for (auto it : v->adjacencies) { 
            if (!visited[it->identifier]) { 
                visited[it->identifier] = true; 
                queue.push(it);
            }
        }
    }
}
