# BGP UPDATE Message Diffusion Simulation in Undirected Graph

This code simulates the Border Gateway Protocol (BGP) UPDATE message using an implementation of an undirected graph, with Breadth-First Search chosen as the traversal method.

The code illustrates the spread of information that occurs when a new router is inserted into a specific autonomous system and how the information about this node's insertion propagates throughout the entire network topology, traversing among all nodes of the network.


## What is Border Gateway Protocol (BGP)?

**Border Gateway Protocol** (BGP) is a standardized exterior gateway protocol used for exchanging routing and reachability information between different autonomous systems (ASes) on the Internet. It operates based on the path-vector algorithm, where routers make decisions on how to route data packets based on network policies and the path information exchanged between them.

### What is BGP UPDATE Message?

The **BGP UPDATE message** is a fundamental component of BGP operations. It is used to communicate changes in routing information between BGP-speaking routers. Key attributes of the UPDATE message include:

- **NLRI (Network Layer Reachability Information)**: Specifies the set of IP prefixes that are being advertised or withdrawn.
- **Path Attributes**: Provide additional information about the route, such as AS-PATH (sequence of AS numbers the route has traversed), NEXT-HOP (the IP address to use to reach the prefix), and others like MULTI_EXIT_DISC (metric used for route selection).
- **Withdrawn Routes**: Indicates which previously advertised routes are no longer valid and should be removed from the routing table.

The propagation of UPDATE messages allows BGP routers to dynamically adjust their routing tables based on changes in network topology, ensuring efficient and reliable data transmission across the Internet.

For more detailed information on BGP and its operational aspects, refer to RFCs (Request for Comments) such as RFC 4271.


### What is Autonomous System?

An Autonomous System (AS) is a collection of IP networks and routers under the control of a single administrative entity that presents a common routing policy to the Internet. Typically, an Autonomous System is operated by an Internet Service Provider (ISP), a large enterprise, or an academic institution. It is identified by an Autonomous System Number (ASN), which is unique for each AS and is used to control the routing of IP traffic between different Autonomous Systems on the Internet.

## Code Structure

The code is structured into the following classes:

* `AutonomousSystem`
* `Router`
* `Network`

The graph model is as follows: vertices represent routers, autonomous systems are subgraphs, and a network is a graph resulting from the union of autonomous systems, thereby forming the subgraphs.

## Usage

To compile this program, use the following command in your terminal:

```bash
make
```

To clean dependecies use the following command in your terminal:
```bash
make clean
```
