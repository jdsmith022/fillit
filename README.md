# fillit

![gif](https://github.com/jdsmith022/fillit/blob/master/pictures/gif.gif)

### Codam Coding College project filllit
Cohort January 2019

fillit is the fourth project completed at Codam. The purpose of fillit is to become familiarize  with a recurring problematic in programming: searching for the optimal solution among a huge set of possibilities in a respectable amount of time. In this project, the objective was to find a way to a given Tetriminos set in the smallest possible square and each tetrimino is placed on their most upper-left position.

For a full explaination of the project in pdf form, including rules and examples of correct solutions, please click [here](https://github.com/jdsmith022/fillit/blob/master/fillit.en.pdf).

### Prerequities
This program complies with a Makefile. For Windows, user can download Cygwin [here](http://www.cygwin.com/) for functionality similar to Linus for Windows.

### Installation

From terminal, the program can be install with git clone with the project repository, followed by the name of the directory you wish to download the repository to.

#### Example 
```
$ git clone git@github.com:jdsmith022/fillit.git [directory-name]
```
### Usage

In terminal, go into the project directory. This program uses a makefile to compile. To compile, run:
```
$ make
```

The executable name is fillit. A directory in the repository named test files that can be used to test the program. To see names of files available for use is maps directory of repository, from terminal and in git repository:
```
$ ls -la tests/
```
![ls-la display](https://github.com/jdsmith022/fillit/blob/master/pictures/ls-la.png)

However, a tetreminos file from the local computer can be used as long as the path to the file is given as parameter.
```
$ ./fillit [path-to-file]
```

#### Example:
```
$ ./fillit ./tests/test_1
```

If incorrect parameters are given or the test is invalid, an error message will be given.

To delete all object files from directory, run:
```
$ make clean
```
To delete executable from directory, run:
```
$ make fclean
```

### Collaborator
This project was a group effort with:
[Malou](https://github.com/mminkjan)
