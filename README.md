# casttale

## Disclaimer

For now, I excuse myself, that 90% of the Code is either written by AI tools or lend from other sources. Aswell in the future all C++ in this project will cede to exist, when i find a way, around that giant json.h file. Trust me it will be replaced, if I don't abandon the project.

## Features

- **Pseudo-3D rendering** using raycasting algorithm
- **First-person perspective** navigation
- **Lightweight implementation** in pure C
- **2D map-based world** representation
- **Wall collision detection**
- **Texture mapping**

## Dependencies

To build and run this raycaster, you'll need the following dependencies:

### Required

- **C Compiler** (GCC recommended or Clang)
  - GCC 4.8 or later
  - Clang 3.4 or later # Not tested
  
- **Make** - Build automation tool
  - GNU Make 3.81 or later

- **Graphics Library** (one of the following):
  - **SDL2** (Simple DirectMedia Layer 2)
    - Version 2.0.0

## Installation

### GNU/Linux Debian and derivates

```bash
# Install dependencies
sudo apt-get update
sudo apt-get install gcc make libsdl2-dev

# Clone the repository
git clone https://github.com/aarcticc/casttale.git
cd casttale

# Build the project
make

# Run the raycaster
./casttale
```

### Linux (Fedora/RHEL)

```bash
# Install dependencies
sudo dnf install gcc make SDL2-devel

# Clone the repository
git clone https://github.com/aarcticc/casttale.git
cd casttale

# Build the project (see .txt)
make

# Run the raycaster
./casttale
```

### macOS

```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install dependencies
brew install gcc make sdl2

# Clone the repository
git clone https://github.com/aarcticc/casttale.git
cd casttale

# Build the project
make

# Run the raycaster
./casttale
```

### Windows (MinGW)

```bash
# Install MinGW and SDL2 (or use MSYS2)
# Download SDL2 development libraries from https://www.libsdl.org/download-2.0.php

# Clone the repository
git clone https://github.com/aarcticc/casttale.git
cd casttale

# Build the project
make

# Run the raycaster
casttale.exe
```

## Usage

### Basic Execution

```bash
# Run with default map
./casttale
```

### Building from Source

```bash
# Build
make # additional commands with 'make help'
# Clean previous builds
make clean
```

## Controls

| Key | Action |
|-----|--------|
| `↑` | Move forward |
| `↓` | Move backward |
| `←` | Rotate camera left |
| `→` | Rotate camera right |

### Extending This Project

Ideas for learning and expansion:

1. **Sprites**: Add 2D sprites in 3D space (enemies, items)
2. **Lighting effects**: Distance-based shading
3. **Multiple wall heights**: Variable height walls
4. **Doors**: Animated door objects
5. **Minimap**: Top-down 2D view of the map
6. **Sound effects**: Integrate audio library

## Acknowledgments

- Inspired by Wolfenstein 3D and the classic raycasting technique
- Thanks to @jdah kicking of this idea with his Wolfenstein/DOOM remake series on YT

## Troubleshooting

### Common Issues

**Black screen on launch:**
- Check if SDL2 is properly installed
- Verify the map file is valid
- Ensure graphics drivers are up to date

**Compilation errors:**
- Verify all dependencies are installed
- Check GCC/Clang version compatibility
- Review Makefile paths for libraries

**Performance issues:**
- Lower the screen resolution
- Reduce the number of rays cast
- Check for infinite loops in ray casting code

**Controls not responding:**
- Verify SDL2 event handling is working
- Check keyboard input polling

---

For questions or issues, please open an issue on the GitHub repository.
