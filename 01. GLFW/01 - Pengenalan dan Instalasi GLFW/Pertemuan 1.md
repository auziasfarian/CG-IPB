# **PRAKTIKUM GRAFIKA KOMPUTER**
## **Pertemuan 1 : Pengenalan dan Instalasi GLFW**

### Pengenalan GLFW
- GLFW(Graphics Library Framework) adalah salah satu toolkit atau library yang menyediakan fungsi-fungsi untuk mempermudah mempelajari OpenGL
- GLFW bersifat *Open Source* dan dapat digunakan untuk kepentingan komersial
- Cocok untuk pembuatan program berbasis OpenGL skala kecil
- GLFW bisa digunakan pada OpenGL, OpenGL ES, Vulkan, dan sebagainya
- GLFW ditulis dalam bahasa C dengan versi terakhir dari GLFW adalah versi 3.3
- GLFW dapat menangani inputan dari keyboard, mouse, joystick, clipboard dan waktu
- GLFW dapat digunakan dalam berbagai *platform* seperti Windows(XP and later), macOS (10.7 Lion and later), Linux, FreeBSD dan Cygwin.

### Instalasi GLFW
Kali ini hal yang akan dilakukan adalah instalasi GLFW pada Code::Blocks (pastikan sudah ada Code::Blocks pada komputer atau laptop yang akan digunakan).
Hal yang perlu dilakukan untuk instalasi GLFW adalah:
1. Download source code GLFW di [Source Code GLFW 3.3](https://github.com/auziasfarian/CG-IPB/tree/master/01.%20GLFW/Berkas%20Instalasi)
2. Extract file yang sudahdi download
3. Copy folder "include", "lib", dan "glad", kemudian paste ke dalam folder C:/Program Files/CodeBlocks/MinGW
4. Copy file glfw3.dll yang telah didownload tadi ke dalam folder C:/Windows/System32 dan C:/Windows/System
5. Buka program Code::Blocks, lalu pilih menu Settings lalu pilih Compiler
6. Pilih menu Linker settings lalu tambahkan library secara berurutan dari atas ke bawah: glfw3dll.a , libgdi32.a , libglfw3.a , libopengl32.a
<h1 align="center"><img src="https://github.com/auziasfarian/CG-IPB/blob/master/01.%20GLFW/01%20-%20Pengenalan%20dan%20Instalasi%20GLFW/urutan%20library.png"></h1>

### Contoh Kode GLFW

```cpp
    #include <GLFW/glfw3.h>
    #include <stdlib.h>
    #include <stdio.h>

    static void error_callback(int error, const char* description) {
      fputs(description, stderr);
    }
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){  
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    }

    int main(void) {
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window){
      glfwTerminate();
      exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window)){
      float ratio;
      int width, height;
      glfwGetFramebufferSize(window, &width, &height);
      ratio = width / (float) height;
      glViewport(0, 0, width, height);
      glClear(GL_COLOR_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
      glBegin(GL_TRIANGLES);
      glColor3f(1.f, 0.f, 0.f);
      glVertex3f(-0.6f, -0.4f, 0.f);
      glColor3f(0.f, 1.f, 0.f);
      glVertex3f(0.6f, -0.4f, 0.f);
      glColor3f(0.f, 0.f, 1.f);
      glVertex3f(0.f, 0.6f, 0.f);
      glEnd();
      glfwSwapBuffers(window);
      glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    }
``` 
    
### Objek Primitif pada OpenGL
Dibawah ini adalah objek primitif yang apabila dirangkai dapat membentuk suatu objek tertentu lainnya
<h3 align="center"><img src="https://github.com/auziasfarian/CG-IPB/blob/master/01.%20GLFW/01%20-%20Pengenalan%20dan%20Instalasi%20GLFW/objek%20primitif.PNG"></h3>

### Struktur Program Sederhana

    #include <GLFW/glfw3.h>
    #include <stdlib.h>
    #include <stdio.h>
    static void error_callback(int error, const char* description){
      fputs(description, stderr);
    }
    static void key_callback(GLFWwindow* window, int key, int
    scancode, int action, int mods){
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
    }
    int main(void) {
      //isi display, control, dsb
    }

### Fungsi Display

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
    exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window) {
      glfwTerminate();
      exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);
    
 ### Fungsi Rendering
    
    while (!glfwWindowShouldClose(window)){
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef((float) glfwGetTime() * 50.f, 0.f,0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
    glfwSwapBuffers(window);
    glfwPollEvents();
    }
 
Cobalah untuk mengganti parameter fungsi glBegin dengan jenis objek primitif lainnya, seperti GL_LINES, GL_POINTS, dan sebagainya.
contoh untuk GL_POINTS :

    glColor3f(0.0f,0.0f,1.0f); //warna biru
    glPointSize(10.0f);//set ukuran titik ke 10 pixels
    glBegin(GL_POINTS); //mulai menggambar point
      glVertex3f(1.0f,1.0f,0.0f);//upper-right corner
      glVertex3f(-1.0f,-1.0f,0.0f);//lower-left corner
    glEnd();//end drawing of points
    
### Fungsi Exit

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
