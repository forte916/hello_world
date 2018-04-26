How to setup Python environment
===============================

* There is incompatible between Python 2.7 and 3.x
* It is better to enable switching the version via third party tools (eg. pyenv, virtualenv)

## Windows
------------------------------------------------------------
### Install Python
* Download an installer of Python
	* https://www.python.org/downloads/
* Install Python
* Set the path of python.exe into PATH environment variable
	* eg) `SETX PATH=C:\Python27\;%PATH%`

### Install pip (python package manager)
* `pip` is attached in Python 3.4 and later also Python 2.7.9 and later
* You don't need additional install for pip, just add the path of pip.exe as follows
	* eg) `SETX PATH=C:\Python27\Scripts;%PATH%`

* See also
	* https://docs.python.org/ja/2.7/installing/index.html

### Switch version
* to be written


## Linux
------------------------------------------------------------


## Mac OSX
------------------------------------------------------------


## How to run
------------------------------------------------------------
* Type following commands on terminal
```sh
python hello.py
```
* Or, just `./hello.py` if shebang line present

