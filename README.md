# software-renderer

A pure CPU-based 3D software renderer built from scratch in C. This project moves away from text-based terminal applications to explore low-level pixel manipulation, custom frame buffers, and graphics pipeline fundamentals.

This repository follows the hands-on tutorial: **[Master Low-Level Graphics in C: Build a Software Renderer from Scratch](https://www.freecodecamp.org/news/master-low-level-graphics-in-c-build-a-software-renderer-from-scratch/)** by Gustavo Pezzi via freeCodeCamp.

## 🚀 Core Features & Concepts Learned
* **Custom Frame Buffer:** Manually creating and managing a frame buffer in memory.
* **Coordinate Mapping:** Mapping 2D screen coordinates into a 1D memory array.
* **Low-Level Windowing:** Leveraging the cross-platform power of the **SDL3** library to open a window and handle OS events.
* **Game Loop & Timing:** Controlling application execution and capping the frame rate for smooth 60 FPS rendering.
* **CPU-Driven Effects:** Implementing the iconic, classic *Doom* fire effect entirely using CPU instructions.

## 🛠️ Prerequisites & Dependencies
To build and run this project, you will need:
* A C compiler (like `gcc`, `clang`, or MSVC)
* **SDL3** (Simple DirectMedia Layer 3) library installed on your system
* **Windows:** the Windows 10 or 11 SDK, installed with the Visual Studio Installer (select the **Desktop development with C++** workload)

## 📦 Setup & Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/VaradLanke/software-renderer.git
   cd software-renderer
   ```

2. Install SDL3, compile, and run:

   **Windows** (using the Visual Studio Developer Command Prompt):

   | Step | Instructions |
   | --- | --- |
   | Download SDL3 | Download `SDL3-devel-3.x.x-VC.zip` from the [SDL releases page](https://github.com/libsdl-org/SDL/releases). |
   | Install SDL3 | Extract the files into `C:\Program Files\SDL3`. For SDL 3.4.16, add `C:\Program Files\SDL3\SDL3-3.4.16\lib\x64` to the Windows `Path` environment variable. Restart the command prompt after changing `Path`. |
   | Compile | `cl.exe /EHsc main.cpp /I"C:\Program Files\SDL3\SDL3-3.4.16\include" /Fe:renderer.exe /link /LIBPATH:"C:\Program Files\SDL3\SDL3-3.4.16\lib\x64" SDL3.lib` |
   | Run | `renderer.exe` |

   **Debian / Ubuntu**:

   | Step | Command |
   | --- | --- |
   | Install SDL3 | `sudo apt-get install libsdl3-dev` |
   | Compile | `gcc -Wall -std=c99 src/main.c -o renderer -lSDL3` |
   | Run | `./renderer` |

## 📚 Acknowledgments
* Course Instructor: **Gustavo Pezzi**
* Platform: **freeCodeCamp.org**
