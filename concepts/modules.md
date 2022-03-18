# Modules

Modules in ASC are a variation of [sequence](sequence.md) which adds the concept of **encapsulation**.

# Module Structure

Modules contain three explicit components.
The dependency component lists the names of other modules which are required for the current module's definition.
The structure component contains definitions which are only visible to entities which are also in the module.
The surface component contains definitions which are visible to entities both inside and outside the module.