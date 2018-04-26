How to setup C environment
==========================

* There are several ways to compile C programs on Windows
	* Use built-in gcc of Cygwin
	* Use built-in gcc of MinGW-w64
	* Use TDM-GCC and GitBash
	* Use Visual Studio

## Windows
------------------------------------------------------------
### gcc of Cygwin
* Download an installer of Cygwin
	* https://cygwin.com/install.html
* Install Cygwin
* Install gcc package via Cygwin installer
* Launch Cygwin terminal

### gcc of MinGW-w64
* Download an installer of MinGW-w64
	* https://mingw-w64.org/doku.php/download
* Install MinGW-w64
* Launch terminal (eg. MinTTY)

### gcc of TDM-GCC
* Download an installer of TDM-GCC
	* http://tdm-gcc.tdragon.net/download
* Install TDM-GCC
* Set the path of gcc.exe into PATH environment variable
* Install terminal apps such as GitBash
* Launch terminal (eg. GitBash)


## Linux
------------------------------------------------------------


## Mac OSX
------------------------------------------------------------


## How to build and run
------------------------------------------------------------
* Type following commands on terminal
```sh
gcc -o hello hello.c
./hello
```

