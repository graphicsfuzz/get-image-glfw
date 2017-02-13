#include <glad/glad.h>
#include <GLFW/glfw3.h>

const float vertices[] = { 
  -1.0f, -1.0f,
  -1.0f, -1.0f,
  -1.0f, -1.0f,
  -1.0f, -1.0f
};

const char* vertex_shader_wo_version = 
"attribute vec2 coord2d;\n"
"varying vec2 surfacePosition;\n"
"void main(void) {\n"
"  gl_Position = vec4(coord2d, 0.0, 1.0);\n"
"  surfacePosition = coord2d;\n"
"}";

int main(int argc, char* argv[]) {

}

