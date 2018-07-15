# corewar

The corewar project is segmented in multiple part :

- The assembler : It is used to build a champion written by someone to a champion in machine language. Changing the champion.s file to a champion.cor file (in binary) if the .s file is valid.

- The virtual machine : This is the main part of the project. The virtual machine create the arena for the champions to fight, execute the move they are trying to do ( like creating new process, writting code on the code of another ennemy programm ), verify if the champions are alive.

  The virtual machine also create register ( like micro processor ) wich contains information that can quickly be accessed by each programms, without needing to move the memory to reach it.

- The visualizer : It is used to display the arena to graphical image, where you can see each champion expanding it's code, creating process to overwhelm others champions.

**Usage**

To build:

```bash
$ make
```

To execute:

Use :
```
$ ./corewar
```

You will get the usage to use use programm.

Example :

```
$ ./corewar champs/jumper.cor
```

you can put up to 4 champions at the same time in the arena.
Add -g option to see the corewar with the visualizer ( visualizer is explained in options category, below ).


Output:

```
Introducing contestants...
* Player -1, weighing 320 bytes, "Jumper !" ("en fait C forker !") !
Finish ! Number of cycles : 24690
Contestant -1, "Jumper !", has won !
```

The output quickly introduce all champions that are used as argument. If you use only one, the programm will always win.
The number associated to each champions start from -1, to -4.
The cycle show the number of "rounds" the corewar lasted until all champions died. Some specifics actions can take a lot of rounds. If not doing any actions, each process will advance from one step in the "Memory arena" per round.

Options:

-d : option -d associated with a number will stop the programm at the specified cycle and show the state of the arena at that moment :

```
$ ./corewar -d 2000 champs/Gagnant.cor champs/Gagnant.cor
```

-n : Associated with a number, it will give the next champion the specified number.

```
$ ./corewar -n 42 champs/Gagnant.cor champs/jumper.cor
```
--> Gagnant.cor champion's number will be 42.


-g : The visualizer. It is used to show the corewar with ncurse. It is not compatible with others options. Set the window to full screen and use it. 
You can press Space to start/pause the game. 
You can slow the game or make it faster by using " { " and " } ".
You can go on cycle per cycle by pressing "s".



Other options are available, you can see them with the usage by writting : "./corewar"



Assembler :

You can also use the assembler to compile champions yourself.

```
$ ./asm compilable_champs/jumper.s
```

It will create the jumper.cor champion, that you can use in corewar. You can also decompile champion to see how they work with :

```
$ ./dasm champs/jumper.cor
```
