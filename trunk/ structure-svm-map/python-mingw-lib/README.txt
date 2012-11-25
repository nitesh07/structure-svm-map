Generate lib for MINGW32
"gendef.exe" is download from "http://sourceforge.net/projects/mingw/files/MinGW/Extension/gendef/gendef-1.0.1346/"
"dlltool.exe" is one tool provided by MinGW32.

RUN:
Step 1: 
RUN: gendef python26.dll, "python26.def" will be generated
Step 2:
dlltool -D python26.dll -d python26.def -l libpython26.a, "libpython26.a" will be generated
Step 3: 
Test the new lib file
gcc -mno-cygwin -Wall -LC:\Python26\libs -L. -IC:\Python26\include python_test.c -lpython26 -o python_test.exe