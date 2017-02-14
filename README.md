# Get image (GLFW)

A tool for rendering a fragment shader to a PNG file.

## Build

You will need CMake. Look at `Dockerfile` for the required packages if building on Debian/Ubuntu (`gcc-mingw-w64` is only needed when cross-compiling for Windows, `git` and `golang` are only needed for uploading releases).

1. Change into `build/`.
2. Execute `./build-linux` (or another `./build-*` file for other platforms/configurations).
3. The binaries will be in `out/linux/install/bin/`.

Run `get_image` on the provided `simple.frag` shader to test that it works. E.g.

```bash
out/linux/install/bin/get_image --persist simple.frag
```


## Usage

`./get_image <PATH_TO_FRAGMENT_SHADER>`

Useful flags:
* `--persist` - causes the shader to be rendered until the window is closed
* `--output <OUTPUT_FILE>` - a png file will be produced at the given location with the contents of the rendered shader (default is `output.png`)
* `--vertex <PATH_TO_VERTEX_SHADER>` - provide a custom vertex shader file rather than using the default (provided in `get_image.cpp`).

