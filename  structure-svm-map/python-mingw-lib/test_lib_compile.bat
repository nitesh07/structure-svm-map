@echo off
%path% = %path%;C:\MinGW\bin;C:\Python26
gcc -mno-cygwin -Wall -LC:\Python26\libs -LC:\Python26\libs\mingw -IC:\Python26\include python_test.c -lpython26 -o python_test.exe