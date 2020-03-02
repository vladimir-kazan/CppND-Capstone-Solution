# CPPND: Capstone Hello World Repo

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application starting with this repo, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally

TODO: install vcpkg and deps

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* vcpkg 
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
  * https://www.libsdl.org/download-2.0.php
* SDL2_ttf
  * `brew install sdl2_ttf`
  * TODO: for linux
## Basic Build Instructions

1. Clone this repo.
2. Run
    - `make release && make run`
    - or with explictely defined path to **vcpkg**: 
    ```sh
    export VCPKG=~/bin/vcpkg
    make release && make run
    ```

---
# TODO:
- [ ] The README also indicates the file and class structure, along with the expected behavior or output of the program.
- [ ] The README indicates which rubric points are addressed. The README also indicates where in the code (i.e. files and line numbers) that the rubric points are addressed.
- [ ] The project code must compile and run without errors.

## Loops, Functions, I/O
- [ ] The project demonstrates an understanding of C++ functions and control structures.
- [ ] The project reads data from a file and process the data, or the program writes data to a file.
- [ ] The project accepts user input and processes the input.

## Object Oriented Programming
- [ ] The project uses Object Oriented Programming techniques.
- [ ] Classes use appropriate access specifiers for class members.
- [ ] Class constructors utilize member initialization lists.
- [ ] Classes abstract implementation details from their interfaces.
- [ ] Classes encapsulate behavior.
- [ ] Classes follow an appropriate inheritance hierarchy.
- [ ] Overloaded functions allow the same function to operate on different parameters.
- [ ] Derived class functions override virtual base class functions.
- [ ] Templates generalize functions in the project.

## Memory Management
- [ ] The project makes use of references in function declarations.
- [ ] The project uses destructors appropriately.
- [ ] The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.
- [ ] The project follows the Rule of 5.
- [ ] The project uses move semantics to move data, instead of copying it, where possible.
- [ ] The project uses smart pointers instead of raw pointers.

## Concurrency
- [ ] The project uses multithreading.
- [ ] A promise and future is used in the project.
- [ ] A mutex or lock is used in the project.
- [ ] A condition variable is used in the project.
