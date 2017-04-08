#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void errorCallback(int error, const char* description) {
  std::cerr << error << ": " << description << std::endl;
  exit(EXIT_FAILURE);
}

GLint getInt(GLenum name) {
  GLint temp = 0;
  glGetIntegerv(name, &temp);
  return temp;
}

template<class KT, class VT> void output(KT key, VT val) {
  std::cout << "    \"" << key << "\": \"" << val << "\",\n";
}

int go(int argc, char* argv[]) {

  glfwWindowHint(GLFW_RESIZABLE, 0);
#ifdef __APPLE__
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

  GLFWwindow* window = glfwCreateWindow(640, 480, "Get gl info", NULL, NULL);

  if(!window) {
    return EXIT_FAILURE;
  }

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
  glfwSwapInterval(1);

  std::cout << "{\n";

  output("GL_VERSION", glGetString(GL_VERSION));
  output("GL_MAJOR_VERSION", getInt(GL_MAJOR_VERSION));
  output("GL_MINOR_VERSION", getInt(GL_MINOR_VERSION));
  output("GL_SHADING_LANGUAGE_VERSION", glGetString(GL_SHADING_LANGUAGE_VERSION));
  output("GL_VENDOR", glGetString(GL_VENDOR));
  output("GL_RENDERER", glGetString(GL_RENDERER));

  GLuint glslNumVersions = (GLuint) getInt(GL_NUM_SHADING_LANGUAGE_VERSIONS);

  std::cout << "    \"Supported_GLSL_versions\": [";
  if(glslNumVersions > 0) {
    std::cout << "\"" << glGetStringi(GL_SHADING_LANGUAGE_VERSION, 0) << "\"";
    for(GLuint i=1; i < glslNumVersions; ++i) {
      std::cout << ", \"" << glGetStringi(GL_SHADING_LANGUAGE_VERSION, i) << "\"";
    }
  }
  std::cout << "]\n";

  std::cout << "}" << std::endl;

  return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {

  glfwSetErrorCallback(errorCallback);

  if(!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  int res = go(argc, argv);

  glfwTerminate();
  return res;
}

