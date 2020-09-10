# Flow

Flow plug-in for Unreal Engine 4 provides a simple graph editor tailored for scripting flow of in-world events in game.
* Licensed under MIT license. You are free to use it for commercial projects, modify it however you see fit and distribute further.
* Just don't try to sell on any digital marketplace as-is, without adding something substantial to it. It would be a scam.

## Concept
It's s design-agnostic event node editor. 
* It's up to you to add game-specific functionalities by writing your nodes and editor customizations. It's not like a marketplace providing very specific implementation of systems, it's a convenient base for building systems tailored to fit your needs.
* Quickly build your own Quest system, Dialogue system or any other custom system that would control flow of events in the game.
* Expand it, build articy:draft equivavalent right in the Unreal Engine.

![image](https://user-images.githubusercontent.com/5065057/92635150-a8abab00-f2d5-11ea-9241-994b5d56b04d.png)

* A single node in this graph is a simple UObject, not a function like in blueprints. This allows you to encapsulate the entire gameplay element (logic with data) in the single node.
* Every node can have a different setup of pins, so developers can easily control flow of events in the graph.
* System designers creating a Flow node call the execution of pins any way they need. API is extremely simple. There are literally few methods to call, all you need to control the flow.
* Editor supports convenient displaying debug information on nodes and wires while playing a game. Quickly add custom debugging information on specific nodes - you can't have that with blueprint functions.

## Simplicity is a key
* It's all about simplifying the cooperation between gameplay programmers and non-programmer people by providing a clean interface between code of systems and using these systems.
* Systems based on such editor are simple to use for least technical team members, i.e. narrative designers, writers, QA.
* Code of gameplay mechanics wouldn't ever be mixed with other systems, they don't know about each other. Flow Graph is a place to mix features by connecting nodes.
* Even a huge game would typically need only a few dozens of Flow nodes. It makes it easy to manage game's complexity - in terms of mechanics, narrative events, lengthy campaigns or handling multiplayer. This concept scales very well.
* Anyone writing a new gameplay feature can quickly expose it to content creators by creating a new Flow Node. This way a given feature doesn't have to be exposed to blueprints.

## Flexibility of the system design
Flow graph communicates with actors in the world by using [Gameplay Tags](https://docs.unrealengine.com/en-US/Gameplay/Tags/index.html). No direct references to actors are used in this variant of scripting - that brings more flexibility to the system design.
* Actor with the Flow Component register itself to Flow Subsystem (or any derived system) when it appears in the world. It's easy to find any actor this way.
* It allows for reusing entire event graphs, unlikely to level blueprints. Graphs aren't bound to levels.
* It's possible to place actors used in the single Flow Graph in different sublevels or even worlds - as Flow Graph could live as long as game session, not bound to the world.
* It should work well with World Partition system coming to Unreal Engine - a trully open-world way of building maps where every actor instance is saved separately to disk. That probably means no sublevels and no level blueprints (except the blueprint of the "persistent level").
* Using Gameplay Tags allow to script an action on any actor spawned in runtime, typically NPCs.
* In some cases actor with given Gameplay Tag doesn't even have to exist when running related action! Example: On Trigger Enter in the image above would pick up required trigger just after loading sublevel with this trigger.

## Recommended workflow
* Flow Graph is meant to entirely replace a need to use Flying Spaghetti Monster (also known as Level Blueprints) in production maps. The flow of the game (the connection between consecutive events and actors) should be scripted using this graph only. Otherwise, you ending up creating a mess - using multiple tools for scripting events.
* This graph also entirely replaces another way of doing things: referencing different actors directly, i.e. hooking up Spawner actor directly to the Trigger actor. Technically it works fine, but it's impossible to read the designed flow of events scripted this way. And debugging it can be very cumbersome.
* Blueprints are supposed to be used only to script the inner logic of actors, not a connection between actors belonging to different systems.

