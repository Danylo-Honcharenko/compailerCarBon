# Compailer Carbon 1.0 for learning
Use cmake to build. **I recommend using 
Visual Studio to build the project.**

## How to build a project?
First, we clone the repository, since 
I use libraries that are submodules for 
git (they have their own repositories), 
you need to go into the cloned directory 
and do the code `git submodule init` - to 
initialize the local configuration file, and 
`git submodule update` - to get all the data of this project 
and fetching the corresponding commit specified in the main
project. And finally, `cmake .` and `cmake --build .`

## Project structure
`dist` - folder with compiled files (res, set, out are 
created when the "carbon compiler" 
compiler is running but are not compiled)

`doc` - documentation folder for compiler functions

`lib` - additional libraries

`src` - cpp project files

## Libraries that are used
`fmt` - open-source formatting 
library providing a fast and 
safe alternative to C stdio and C++ iostreams. 
[more](https://github.com/fmtlib/fmt)
