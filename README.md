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
* Every node defines its own set of Input/Output pins, so its deadly simple to design interactions between systems. 
* System designers creating a Flow node call the execution of pins any way they need. API is extremely simple. There are literally few methods to call, all you need to control the flow.
* Editor supports convenient displaying debug information on nodes and wires while playing a game. Quickly add custom debugging information on specific nodes - you can't have that with blueprint functions.

## Simplicity is a key
* It's all about simplifying the cooperation between gameplay programmers and non-programmer people by providing a clean interface between code of systems and using these systems.
* Code of gameplay mechanics wouldn't ever be mixed with other systems, they don't know about each other. Flow Graph is a place to mix features by connecting nodes.
* Every mechanic is exposed to content designers once, in one way only - as Flow Node. It greatly reduces amount of bugs. Refactoring mechanics is easy, since you don't have to update dozens of level blueprints.
* Systems based on such editor are simple to use for least technical team members, i.e. narrative designers, writers, QA. Every time I ask designers why they love working with such system, they usually reply: "it's so simple to understand and make game with it".
* Even a complex game might end up only with a few dozens of Flow nodes. It's easy to manage game's complexity - a lot of mechanics, mission scripting, narrative events. It makes very efficient to develop lengthy campaigns and multiplayer games.

## Blueprints
* Anyone writing a new gameplay feature can quickly expose it to content creators by creating a new Flow Node. A given C++ feature doesn't have to be exposed to blueprints at all.
* However, Flow nodes can be created in blueprints by designers, as singe blueprint class represents a single Flow node.

## Flexibility of the system design
Flow graph communicates with actors in the world by using [Gameplay Tags](https://docs.unrealengine.com/en-US/Gameplay/Tags/index.html). No direct references to actors are used in this variant of scripting - that brings a lot of new possibilities.
* Actor with the Flow Component register itself to Flow Subsystem (or any derived system) when it appears in the world. It's easy to find any event actor this way, just ask for actors registred with given Gameplay Tag.
* It allows for reusing entire Flow graphs in different maps. Unlikely to level blueprints, Flow Graphs aren't bound to levels.
* It's possible to place actors used by the single Flow Graph in different sublevels or even worlds. This removes one of workflow limitations related to the level design.
* It should work well with World Partition system coming to Unreal Engine - a trully open-world way of building maps where every actor instance is saved separately to disk. That probably means no sublevels and no level blueprints (except the blueprint of the "persistent level").
* Flow Graph could live as long as game session, not even bound to the specific world. You can have a meta Flow Graph waiting for events happening anywhere during the game.
* Using Gameplay Tags allow to script an action on any actor spawned in runtime, typically NPCs.
* In some cases actor with given Gameplay Tag doesn't even have to exist when starting a related action! Example: On Trigger Enter in the image above would pick up required trigger after loading sublevel with this trigger.

## Recommended workflow
* Flow Graph is meant to entirely replace a need to use Level Bluepints (also known as Flying Spaghetti Monster) in production maps. The flow of the game - the connection between consecutive events and actors - should be scripted using this Flow Graph only. Otherwise, you ending up creating a mess - using multiple tools for scripting events.
* This graph also entirely replaces another way of doing things: referencing different actors directly, i.e. hooking up Spawner actor directly to the Trigger actor. Technically it works fine, but it's impossible to read the designed flow of events scripted this way. Debugging it can be very cumbersome and time-consuming.
* Blueprints are supposed to be used only to script the inner logic of actors, not a connection between actors belonging to different systems.
* Flow nodes can send and receive blueprint events via Flow Component. This recommended way of communicating between Flow graph and blueprints.
* Technically, it's always possible to call custom blueprint events directly from blueprint Flow Node, but this would require creating a new Flow Node for every custom blueprint actor. Effectively, you would throw a simplicity of Flow Graph out of the window.


