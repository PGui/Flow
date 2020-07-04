# Flow Graph

Flow plug-in for Unreal Engine 4 provides a simple graph editor tailored for scripting flow of in-world events in game.
* Licensed under MIT license. You are free to use it for commercial projects, modify, distribute

## Concept
* It's design-agnostic, a bit customized node editor. It's up to you to add game-specific functionalities by writing your nodes.
* A single node in this graph is a simple UObject, not a function like in blueprints. This allows you to encapsulate the entire logic and data for the given gameplay element in the single node.
* Every node can have a different setup of pins, so users can easily control flow of events in the graph.
* Gameplay programmer/designer simply calls a function to trigger the execution of pins any way he needs. API is extremely simple.
* Added convenient displaying debug information on nodes and wires while playing a game. Quickly add custom debugging information on specific nodes, you can't have that with blueprint functions.

## Simplicity is a key
* Even a huge game would typically need only a few dozens of Flow nodes. It makes it easy to manage game's complexity - in terms of mechanics, narrative events, lengthy campaigns and handling multiplayer. This concept scales very well.
* Systems based on such editor are simple to use for least technical team members, i.e. narrative designers, writers, QA.
* Anyone writing a new gameplay feature can quickly expose it to content creators by creating a new Flow Node. This way a given feature doesn't have to be exposed to blueprints.
* Code of gameplay mechanics wouldn't ever be mixed with other systems, they don't know about each other. Flow Graph is a place to mix features by connecting nodes.

## Recommended workflow
* Flow Graph is meant to entirely replace a need to use Level Blueprints in production maps. The flow of the game (the connection between consecutive events and actors) should be scripted using this graph only. Otherwise, you ending up creating a mess - using multiple tools for scripting events.
* For the same reason, it's recommended to entirely forget about referencing different actors directly, i.e. hooking up Spawner or Door actor directly to the Trigger actor. Technically it works fine, but it's impossible to read the designed flow of events scripted this way. And debugging it can be very cumbersome.
* Blueprints are supposed to be used mostly to script the inner logic of actors, not a connection between actors belonging to different systems.
