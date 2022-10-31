# RunicV1 Devlog 2

Welcome to Runic's second devlog.

This will be a fairly small update, but I wanted to at least provide some examples of the current progress. In regards to gameplay mechanics, a teleport ability has been added and the AI have had some adjustments. Up to this point, Gameplay Abilities have had parent classes created in C++, but have been implemented mostly in Blueprints. While this works fine, I wanted to get an idea of what it's like to create abilities purely in C++. As such, the teleport ability's logic is almost completely made in C++ (`RAbilityTeleport`). This was much more flexible than I was expecting, and I will likely be using both methods for future abilities.

The AI has had some updates as well. Base AI can now shield just like the player, which includes the custom damage and flow regen logic used for the player's shield. The AI Behavior Tree provides multiple opportunities to shield, with a randomized chance of actually using the ability, as well as a randomized time for the AI to hold the shield. Some smaller adjustments have made combat a bit faster as well.

Some short vidoes showing current progress have been included with this Devlog. Since most of the progress so far has been building the project's Gameplay Ability System framework, there still isn't much to see visually. The existing animations and VFX are mostly placeholders, as my focus up to this point has been more on creating the logic, rather than creating the animations and VFX. Regardless, it is still nice to see actual visual components working with the logic.


Basic combat:
https://user-images.githubusercontent.com/89817267/197058895-e1131bf5-0fbc-4e35-824b-bdefe61bf25d.mp4
(`RunicV1_Devlog2_CombatBasic.mp4` in repo)

Combat with more enemies:
https://user-images.githubusercontent.com/89817267/197059103-52248015-e000-4724-aafd-25827fb88da9.mp4
(`RunicV1_Devlog2_CombatFull.mp4` in repo)


Thanks for stopping by, more updates to follow.
