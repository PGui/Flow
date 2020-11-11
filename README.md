# Flow

Flow plug-in for Unreal Engine provides a graph editor tailored for scripting flow of events in virtual worlds. It's based on nearly a decade of experience with designing and implementing narrative in video games. All we need here is... simplicity.
* Licensed under MIT license. You are free to use it for commercial projects, modify it however you see fit and distribute further.

## Concept
It's s design-agnostic event node editor.

![image](https://user-images.githubusercontent.com/5065057/97006262-e429ce00-153f-11eb-9dfd-5dff1fca6d6b.png)

* A single node in this graph is a simple UObject, not a function like in blueprints. This allows you to encapsulate the entire gameplay element (logic with its data) withing the single Flow Node.
* Every node defines its own set of input/output pins. It's deadly simple to design flow of the game - just connect nodes representing features.
* Developers creating a Flow Node can call the execution of pins any way they need. API is extremely simple.
* Editor supports convenient displaying debug information on nodes and wires while playing a game. You simply provide what kind of message would be displayed over active Flow Nodes - you can't have that with blueprint functions.

## Base for your own systems and tools
* It's up to you to add game-specific functionalities by writing your nodes and editor customizations. It's not like a marketplace providing the very specific implementation of systems. It's a convenient base for building systems tailored to fit your needs.
* Quickly build your own Quest system, Dialogue system or any other custom system that would control the flow of events in the game.
* Expand it, build articy:draft equivalent right in the Unreal Engine.

## Simplicity is a key
* It's all about simplifying the cooperation between gameplay programmers and non-programmer people by providing a clean interface between "code of systems" and "using systems".
* Code of gameplay mechanics wouldn't ever be mixed with each other. Usually, system X shouldn't even know about the existence of system Y. Flow Graph is a place to combine features by connecting nodes.
* Every mechanic is exposed to content designers once, in one way only - as the Flow Node. It greatly reduces the number of bugs. Refactoring mechanics is easy since you don't have to update dozens of level blueprints directly calling system functions.
* Systems based on such editor are simple to use for least technical team members, i.e. narrative designers, writers, QA. Every time I ask designers why they love working with such system, they usually reply: "it's so simple to understand and make a game with it".
* Even a complex game might end up only with a few dozens of Flow Nodes. It's easy to manage the game's complexity - a lot of mechanics, mission scripting, narrative events. It makes it very efficient to develop lengthy campaigns and multiplayer games.

## Blueprints
* Programmer writing a new gameplay feature can quickly expose it to content creators by creating a new Flow Node. A given C++ feature doesn't have to be exposed to blueprints at all.
* However, Flow Nodes can be created in blueprints by anyone.

## Flexibility of the system design
Flow Graph communicates with actors in the world by using [Gameplay Tags](https://docs.unrealengine.com/en-US/Gameplay/Tags/index.html). No direct references to actors are used in this variant of scripting - that brings a lot of new possibilities.
* Simply add Flow Component to every "event actor", assign Gameplay Tags identifying this actor. Flow Component registers itself to the Flow Subsystem (or any derived system) when it appears in the world. It's easy to find any event actor this way, just ask Flow Subsystem for actors registered with a given Gameplay Tag.
* It allows for reusing entire Flow Graphs in different maps. Unlike to level blueprints, Flow Graphs aren't bound to levels.
* It's possible to place actors used by the single Flow Graph in different sublevels or even worlds. This removes one of the workflow limitations related to the level design.
* It should work well with the World Partition system coming to Unreal Engine - a truly open-world way of building maps where every actor instance is saved separately to disk. That probably means no sublevels and no level blueprints (except the blueprint of the "persistent level").
* Flow Graph could live as long as the game session, not even bound to the specific world. You can have a meta Flow Graph waiting for events happening anywhere during the game.
* Using Gameplay Tags allow scripting an action on any actor spawned in runtime, typically NPCs.
* In some cases actor with a given Gameplay Tag doesn't even have to exist when starting a related action! Example: On Trigger Enter in the image above would pick up the required trigger after loading a sublevel with this trigger.

## Recommended workflow
* Flow Graph is meant to entirely replace a need to use Level Blueprints (also known as Flying Spaghetti Monster) in production maps. The flow of the game - the connection between consecutive events and actors - should be scripted by using Flow Graphs only. Otherwise, you ending up creating a mess, using multiple tools for the same job.
* This graph also entirely replaces another way of doing things: referencing different actors directly, i.e. hooking up Spawner actor directly to the Trigger actor. Technically it works fine, but it's impossible to read the designed flow of events scripted this way. Debugging can be very cumbersome and time-consuming.
* Actor blueprints are supposed to be used only to script the inner logic of actors, not a connections between actors belonging to different systems.
* Flow Nodes can send and receive blueprint events via Flow Component. This recommended way of communicating between Flow Graph and blueprints.
* Technically, it's always possible to call custom blueprint events directly from blueprint Flow Node, but this would require creating a new Flow Node for every custom blueprint actor. Effectively, you would throw a simplicity of Flow Graph out of the window.

## Acknowledgements
I feel it's important to mention that I didn't invent anything new here, with the Flow Graph. It's an old and proven concept. I'm only the one who decided it would be crazy useful to adopt it for Unreal Engine. And make it publically available as my humble contribution to the open-source community.
* Such simple graph-based tools for scripting game screenplay are utilized for a long time. Traditionally, RPG games needed such tools as there a lot of stories, quest, dialogues.
* The best narrative toolset I had the opportunity to work with is what CD Projekt Red built for The Witcher series. Sadly, you can't download the modding toolkit for The Witcher 2 - yeah, it was publically available for some time. Still... you can watch GDC talk by Piotr Tomsiński on [Cinematic Dialogues in The Witcher 3: Wild Hunt](https://www.youtube.com/watch?v=chf3REzAjgI) - it includes a brief presentation how Quest and Dialogue editors look like. It wouldn't be possible to create such an amazing narrative game without this kind of toolset. I did miss that so much when I moved to the Unreal Engine...
* Finally got an opportunity to work on something like this at [Reikon Games](http://www.reikongames.com/). They badly wanted to build a better tool for implementing game flow than level blueprints or existing Marketplace plug-ins. I was very much interested in this since the studio was just starting with the production of the new title. And we did exactly that, created node editor dedicated to scripting game flow. Kudos to Dariusz Murawski - a programmer who spent a few months with me to establish the working system and editor. And who had to endure my never-ending feedback and requests.
* At some point I felt comfortable enough with programming editor tools so I decided to build my own version of such toolset. Written from the scratch, meant to be published as an open-source project. I am thankful to Reikon bosses they see no issues with me releasing Flow Graph, which is "obviously" similar to our internal tool in many ways. I mean, it's so simple concept of "single node representing a single game feature"... and it's based on the same UE4 node graph API. Some corporations might have an issue with that.

## Further development
* Now I'm working on a short video presenting the Flow Graph.
* I'm planning to release the Flow plugin on the Marketplace, so more people could discover it and conveniently add to their asset libraries. It will be free of charge, obviously.
* Check [Issues](https://github.com/MothCocoon/Flow/issues) for a list of useful things I'm hoping to work on in the future.

## Contact
* Catch me on Twitter: [@MothDoctor](https://twitter.com/MothDoctor)
* Discuss with others on the Discord server: [Flow Discord](https://discord.com/channels/742802606874820619/752181877938323668)
