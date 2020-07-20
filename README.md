# Pirple C++
* Assignment #1: Getting to Know Your IDE. **GreenBottles**
* Assignment #2: Data Types and Variables. **Variables**
* Assignment #3: Basic Input and Output. **Prices**
* Assignment #4: Conventions and Operators. **Quadratic**
* Assignment #5: Statements, Switches and Loops. **NumberGuess**
* Assignment #6: Arrays and Pointers. **TicTacToe**
* Assignment #7: Binary and Bits. **Engine**
* Assignment #8: Application Structure. **TicTacToe**
* Assignment #9: The String Class. **PlaylistParser**
```bash
> compileCpp

> vi .bash_profile
# init add to file
function compileCpp() {
  file=a.out
  last_modified=`stat -c "%Y" $file`
  echo EHA Compiling Cpp, please wait...
  gcc main.cpp -lstdc++
  if [ $((`stat -c "%Y" $file`-$last_modified)) -eq 0 ]; then
    echo "** ERROR ** CHECK AND COMPILE AGAIN **";
  else
    echo "!! OK !!";
    #clear
    ./$file
  fi
}
# end add to file

> source .bash_profile
```

* Assignment #10: OOP. **Wooffurs**
* Assignment #11: Working With Data (OOP, I/O, vectors). **PlayList**
