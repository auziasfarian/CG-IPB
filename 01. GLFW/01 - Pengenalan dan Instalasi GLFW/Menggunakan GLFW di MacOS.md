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

#### Instalasi GLFW

1. Buka terminal,
2. Ketikkan perintah berikut `brew install glfw`
3. Tunggu hingga proses instalasi selesai
4. Untuk memastikan apakah library GLFW sudah terinstall pada perangkat Mac Anda; buka aplikasi Finder, lalu tekan hotkey pada keyboard `Command + Shift + G` dan ketikkan;
   - `/usr/local/include` (*directory* penyimpanan GLFW *header files*), dan
   - `/usr/local/lib` (*directory* GLFW *library file*). 

#### Create a New Xcode Project

Setelah semua *requirement* terpenuhi, waktunya membuat projek OpenGL. Berikut konfigurasi yang harus dilakukan sebelum mulai menulis program OpenGL pada MacOS:

1. Buka aplikasi XCode,
2. Pilih *"Create a New Xcode Project",*
3. Pada kolom pencarian *project template*, ketikkan "Command Line Tool" , pilih template tersebut, lalu *next*,
4. Isi setiap kolom sesuai dengan projek akan Anda buat, lalu pada opsi *language*, pilih C / C++, lalu *next*, kemudian pilih *directory* untuk menyimpan projek,
5. Selanjutnya Anda akan dihadapkan pada halaman *project configuration* , klik tab "Build Phases", lalu buka dropdown "Link Binary with Libraries", kemudian klik simbol **+** untuk menambahkan framework. Adapun framework yang diperlukan yaitu;
   - OpenGL.framework
   - Cocoa.framework
   - CoreVideo.framework,
   - IOKit.framework,
   - libglfw3.a (pilih others, lalu tekan hotkey pada keyboard `Command + Shift + G` dan ketikkan `/usr/local/lib` kemudian pilih libglfw3.a)
6. Selamat! Sekarang perangkat Mac Anda sudah siap menjalankan library GLFW pada program OpenGL. Berikut program OpenGL sederhana untuk memeriksa apakah konfigurasi telah berhasil dilakukan [OpenGL Documentation](https://www.glfw.org/documentation.html). 

