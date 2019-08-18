## Menjalankan Library GLFW di MacOS Menggunakan XCode

#### Requirement

- XCode 10.1 or later (*available on MacOS High Sierra or above*)
- Homebrew  (*package management software*)
- GLFW (*OpenGL library*)

#### Instalasi XCode

Xcode merupakan *integrated development environment* (IDE) resmi besutan Apple yang dirilis pada MacOS yang digunakan sebagai *tools* pengembangan perangkat lunak untuk MacOS, iOS, iPadOS,  watchOS, dan tvOS. Instalasi XCode dapat dilakukan melalui;

- <u>MacOS Mojave</u>: unduh melalui App Store, tunggu proses instalasi, lalu jalankan.
- <u>MacOS High Sierra or below</u>: unduh melalui [XCode releases](https://xcodereleases.com) , *extract file*, pindahkan ke directory `/Applications `, lalu jalankan.

#### Instalasi Homebrew

Homebrew (perintah `brew`) merupakan *package management system* yang berjalan di MacOS (seperti apt-get pada Linux). Instalasi menggunakan *command line* di terminal:

1. Buka terminal,

2. Salin perintah berikut lalu tekan enter untuk memulai instalasi:

   `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
   
3. Ikuti instruksi di terminal dan tunggu hingga proses instalasi selesai,

4. Untuk memastikan apakah homebrew sudah terinstall pada perangkat Mac Anda; ketikkan perintah berikut di terminal `brew help` . Jika terminal tidak mengeluarkan output "*command not found*", maka homebrew berhasil terinstall pada perangkat Mac Anda.

#### Instalasi CMake

1. Buka terminal,
2. Ketikkan perintah berikut `brew install cmake`
3. Tunggu hingga proses instalasi selesai

#### Instalasi GLFW

1. Unduh [GLFW Source Code](https://www.glfw.org) lalu ekstrak file,
2. Buka terminal dan arahkan ke *directory* hasil ekstraksi GLFW *Source Code*,
3. Ketikkan perintah berikut `cmake .`
4. Selanjutnya ketikkan perintah `make`
5. Lalu perintah `make install`
6. Tunggu hingga proses instalasi selesai,
7. Untuk memastikan apakah library GLFW sudah terinstall pada perangkat Mac Anda; buka aplikasi Finder, lalu tekan hotkey pada keyboard `Command + Shift + G` dan ketikkan;
   - `/usr/local/include` (*directory* penyimpanan GLFW *header files*), dan
   - `/usr/local/lib` (*directory* GLFW *library file*). 

#### Create a New Xcode Project

Setelah semua *requirement* terpenuhi, waktunya membuat projek OpenGL. Berikut konfigurasi yang harus dilakukan sebelum mulai menulis program OpenGL pada MacOS:

1. Buka aplikasi XCode,
2. Pilih *"Create a New Xcode Project",*
3. Pada kolom pencarian *project template*, ketikkan "Command Line Tool" , pilih template tersebut, lalu *next*,
4. Isi setiap kolom sesuai dengan projek akan Anda buat, lalu pada opsi *language*, pilih C, lalu *next*, kemudian pilih *directory* untuk menyimpan projek,
5. Selanjutnya Anda akan dihadapkan pada halaman *project configuration* , klik tab **Build Phases**, lalu buka dropdown **Link Binary with Libraries**, kemudian klik simbol **+** untuk menambahkan framework. Adapun framework yang diperlukan yaitu;
   - OpenGL.framework
   - Cocoa.framework
   - CoreVideo.framework,
   - IOKit.framework,
   - libglfw3.a (pilih others, lalu tekan hotkey pada keyboard `Command + Shift + G` dan ketikkan `/usr/local/lib` kemudian pilih libglfw3.a)
6. Lalu pindah ke tab **Build Settings**, kemudian pilih **All** category. Pada *dropdown* **Search Paths** masukkan *directory* **Header Search Paths** menjadi `/usr/local/include`, dan *directory* **Library Search Paths** menjadi `/usr/local/lib`
7. Selamat! Sekarang perangkat Mac Anda sudah siap menjalankan library GLFW pada program OpenGL. Berikut program OpenGL sederhana untuk memeriksa apakah konfigurasi telah berhasil dilakukan

```c
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

