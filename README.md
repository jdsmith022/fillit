# fillit
Codam Coding College
Cohort January 2019

fillit is the fourth project completed at Codam. The purpose of fillit is to familiarize myself with a recurring problematic in programming: searching for the optimal solution among a huge set of possibilities in a respectable amount of time. In this project, my objective was to find a way to a given Tetriminos set in the smallest possible square and each tetrimino is placed on their most upper-left position.

I wrote a program that creates an executable called fillit. fillit takes only one parameter: a file that contains a list of 1 - 26 tetriminos to assemble. The file has a very specific format: every tetrimino must exactly fit in a 4 by 4 chars square and all tetriminos are separated by a newline. 

A description of a tetrimino is as follows:
  1. Precisly 4 lines of 4 characters, each followed by a newline.
  2. A tetrimino is a classic piece of Tetris composed of 4 blocks.
  3. Each character mus either be a block character (#) or an empty character (.).
  4. Each black of a Tetrimino must touch at least one other block on any of it's 4 sides (up, down, left, and right).
  

Example file:

....
....
....
####

...#
..##
...#
....


If the file submitted does not follow the specific format, or contains an invalid tetrimino, then the program will return invalid.

Example of an errror message is return: 

$> cat invalid_sample.txt | cat -e
....$
####$
....$
...%$
$

or:

$> cat invalid_sample.txt | cat -e
....$
.#..$
.#..$
.##.$
....$
$
....$
....$
..#.$
.###$
$

Fillit displays the smallest asembled square on the standard output. To identify each Tetriminos in the square solution, I assinged a capital letter to each Tetrimino, starting with A and increasing with each new Tetrimino. If the file contains at least one error, the program displays error on the standard output followed by a new line.

Example of valid Tetriminos file and correct output:

$> cat valid_sample.txt | cat -e
....$
##..$
.#..$
.#..$
$
....$
####$
....$
....$
$
#...$
###.$
....$
....$
$
....$
##..$
.##.$
....$

$> ./fillit sample.txt | cat -e
DDAA$
CDDA$
CCCA$
BBBB$

If no paramater is used with executable, a usage error will be returned.

The programe is compiled with a Makefile. Makefile rules are as follows:
make = creates executable
make re = re makes executable after being made
make clean = removes all .o files
make fclean = removes all .o files and the executable

To use programe, copy URL repositoy and safe files to directory on local computer. In terminal, go to newly created directory and run make to compile executable fillit. Create Tetriminos files and in the terminal, run the exectuable with your Tetriminos file as it's paramater. 

Example:

$> ./fillit valid_sample.txt

Enjoy!
