#ifndef ROUTER_HPP
#define ROUTER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>

struct Router {
    inline static int classIdentifier = 0;
    int identifier;
    int ASIdentifier;
    std::string BGPMessage;
    bool borderRouter;
    std::list<Router*> adjacencies;

    Router() : BGPMessage({""}), borderRouter(false),
               identifier(++Router::classIdentifier), ASIdentifier(0) {}

    Router(const Router& router) : borderRouter(true), identifier(router.identifier),
                                   BGPMessage(router.BGPMessage), adjacencies(router.adjacencies),
                                   ASIdentifier(router.ASIdentifier) {}

    std::string toString() {
        return std::to_string(this->identifier).append("(" + std::to_string(this->ASIdentifier) + ") ");
    }

    friend std::ostream& operator<<(std::ostream& os, Router& router) {
        if (!router.adjacencies.empty()) {
            os << router.identifier << " -> ";
            for (const auto& it : router.adjacencies)
                os << it->identifier << " ";
        } else {
            os << "";
        }
        return os;
    }

    bool operator==(const Router& router) {
        return this->identifier == router.identifier;
    }

    Router& operator=(Router& router) {
        return *(new Router(router));
    }

    ~Router() {
        for (auto& it : this->adjacencies)
            delete it;
    }
};

#endif
