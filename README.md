# Flow Graph

Flow plug-in for Unreal Engine 4 provides a simple graph editor tailored for scriprintg flow of in-world events in game. 
* Licensed under MIT licence. You are free to use it for commercial projects, modify, distribute :)

## Concept
* It's design-agnostic, a bit customized node editor. It's up to you add game-specicic functionalities by writing your nodes.
* A single node in this graph is a simple UObject, not a function like in blueprints. This allows you encapsulate entire logic and data of given "action" in the single node. 
* Every node can have different setup of pins, so user can easily control flow of events in the graph.
* Gameplay programmer/designer simply call function to trigger execution of pins any way he needs. API is extremely simple.
* Added convenient displaying debug information on nodes and wires while playing a game. It's easy to add custom debugging information on specific nodes, you can't have that with blueprint functions.
* Systems based on such editor are simple to use for least technical team members, i.e. narrative designers, writers.
