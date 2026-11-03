SDL3_HEADER = C:/Program Files/SDL3/SDL3-3.4.16/include
SDL3_LIB = C:/Program Files/SDL3/SDL3-3.4.16/lib/x64
SRC_NAME = main.cpp
EXE_NAME = renderer.exe

all:
	cl.exe /nologo /EHsc /I"$(SDL3_HEADER)" /Fe"$(EXE_NAME)" $(SRC_NAME) /link /LIBPATH:"$(SDL3_LIB)" SDL3.lib

run:
	.\$(EXE_NAME)

clean:
	del *.obj
	del *.exe
