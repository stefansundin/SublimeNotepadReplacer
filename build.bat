@echo off

set prefix=x86_64-w64-mingw32-

:: To compile 32-bit, uncomment this:
:: set prefix=i686-w64-mingw32-

%prefix%gcc -o SublimeNotepadReplacer.exe SublimeNotepadReplacer.c -municode -mwindows -lshlwapi -O2 -s
