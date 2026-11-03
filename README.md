# software-renderer

A C++ learning project exploring the fundamentals behind a CPU-based software renderer, with SDL3 used for windowing and display. It follows along with Gustavo Pezzi's [Master Low-Level Graphics in C: Build a Software Renderer from Scratch](https://www.freecodecamp.org/news/master-low-level-graphics-in-c-build-a-software-renderer-from-scratch/) tutorial.

## Requirements

The included Makefile is configured for a Windows x64 build and requires:

- Visual Studio's C++ build tools, including the **Desktop development with C++** workload
- GNU Make
- The SDL3 development libraries for Visual C++ (x64)

## Build and run on Windows

1. Install SDL3. Download the Visual C++ development archive from the [SDL releases page](https://github.com/libsdl-org/SDL/releases) and extract it. The Makefile defaults to:

   ```text
   C:/Program Files/SDL3/SDL3-3.4.16
   ```

   If your SDL3 directory is elsewhere, pass its path as `SDL3_DIR` when running Make.

2. Open a **Visual Studio Developer Command Prompt** and change to the project directory:

   ```bat
   cd software-renderer\src\01_Simple_SDL_Window
   ```

3. Build and run:

   ```bat
   make
   make run
   ```

   The build produces `renderer.exe`. If Windows cannot find `SDL3.dll` when launching it, add SDL3's `lib\x64` directory to `Path`.

To use a non-default SDL3 installation:

```bat
make SDL3_DIR="C:/path/to/SDL3"
```

Remove generated files with:

```bat
make clean
```

## Learning goals

As the project develops, it explores frame buffers, mapping screen coordinates to memory, game-loop timing, and CPU-rendered effects.

## Acknowledgments

- Tutorial by [Gustavo Pezzi](https://www.freecodecamp.org/news/master-low-level-graphics-in-c-build-a-software-renderer-from-scratch/), published by [freeCodeCamp](https://www.freecodecamp.org/)
