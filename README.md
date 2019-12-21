# FlowExamples

Flow Graph is a generic tool to script flow of in-world events in game.

## Flow nodes
* A single node in this graph is a simple UObject. 
* Single node should represent a single feature or element of the game.
* Every node can have different setup of pins, so you can easily control flow of events in graph.

## Recipe
* Copy-pasted and cleaned up the Sound Cue editor, one of the simplest node editor in UE4.
* Changed direction of executing nodes to match convention of scripting graphs (logic goes from left to the right).
* Added support for adding custom input and output pins for every nodes. 
* Added methods allowing you to trigger executing pins any way you want to. 
* Copy-pasting QoL features from Material editor: placing nodes by keyboard shortcut and displaying node categories in Palette.
* Displaying debug information on nodes and wires while playing a game.
