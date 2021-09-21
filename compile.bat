@echo off

cd src/
set objs=
for /R %%f in (*.cpp) do call set objs=%%objs%% %%f
cd ..


g++ -std=c++17 %objs% -o parser.exe