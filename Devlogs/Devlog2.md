# RunicV1 Devlog 2

Welcome to Runic's second devlog.

This will be a fairly small update, but I wanted to at least provide some examples of the current progress. In regards to gameplay mechanics, a teleport ability has been added and the AI have had some adjustments. Up to this point, Gameplay Abilities have had parent classes created in C++, but have been implemented mostly in Blueprints. While this works fine, I wanted to get an idea of what it's like to create abilities purely in C++. As such, the teleport ability's logic is almost completely made in C++ (`RAbilityTeleport`). This was a great learning experience, and I will likely be using both methods for future abilities.

The AI has had some updates as well. Base AI can now shield just like the player, which includes the custom damage and flow regen logic used for the player's shield. The AI Behavior Tree provides multiple opportunities to shield, with a randomized chance of actually using the ability, as well as a randomized time for the AI to hold the shield. Some smaller adjustments have made combat a bit faster as well.

Thanks for stopping by, more updates to follow.