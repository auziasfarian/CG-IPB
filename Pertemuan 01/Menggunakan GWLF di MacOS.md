# Menggunakan GLFW di Mac

UPDATE: Sejak versi MacOS Mojave, status OpenGL menjadi _deprecated_ dan tidak dapat digunakan karena Apple beralih ke Metal. So sad.

## Instalasi Brew
Fungsi Brew adalah _package management system_ yang berjalan di MacOS (seperti apt-get pada Linux). 
- Buka [situs Brew](https://brew.sh/) dan salin perintah instalasi di halaman tersebut ke terminal (atau salin perintah berikut). 

``` 
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
``` 
- Ikuti instruksi di terminal dan pastikan Brew terpasang pada sistem operasi Anda. 

## Instalasi GLFW
- Buka terminal dan ketikkan perintah berikut
```brew install glfw ``` 

## Kompilasi Program 
- Buka terminal dan ketikkan:
```gcc <path ke kode program> -o <nama berkas output> -framework OpenGl -lglfw```
