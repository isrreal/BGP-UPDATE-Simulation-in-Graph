# BGP UPDATE Message Difusion Simulation in Undirected Graph
This code simulates the Border Gateway Protocol (BGP) UPDATE message using an implementation of an undirected graph, with Breadth-First Search chosen as the traversal method.

The code illustrates the spread of information that occurs when a new router is inserted into a specific autonomous system and how the information about this node's insertion propagates throughout the entire network topology, traversing among all nodes of the network.

The code is structured into the following classes:

* AutonomousSystem
* Router
* Network
  
The graph model is as follows: vertices represent routers, autonomous systems are subgraphs, and a network is a graph resulting from the union of autonomous systems, thereby forming the subgraphs.

Here is the default compilation mode for the code:

* g++ *.cpp -o main -std=c++17 && ./main
