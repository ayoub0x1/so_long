# so_long

![so long play screen shot](so_long_play_screen_shot.png)
This is a small game project from 1337/42school implemented using MiniLibX. The project is inspired by Game Freak's Pokemon Firered.

## Goals
This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.

## Getting Started
```
🚨 Please check that you have mlxlib installed in your machine.
```
### Install
```bash
$ make
```

### Usage
```bash
$ ./so_long [MAP_FILE.ber]
```
Only map files with extension `.ber` are available. Map file examples are available in the `maps/` directory.

```bash
$ ./so_long maps/map.ber
```
Run the code to use all the features of the game.

### HOW TO PLAY
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.

|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`ESC ⎋`|Close the game window|

## Reference
 * [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
 * [42Docs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
 * [taelee42/mlx_example](https://github.com/taelee42/mlx_example)
 * [pret/Disassembly of Pokémon FireRed and LeafGreen](https://github.com/pret/pokefirered)
