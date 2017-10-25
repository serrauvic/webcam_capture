# webcam_capture
Captura imatges de la web cam fork de https://github.com/beta-robots/webcam_capture
### Requeriments inicials i dependències

* CMake : https://cmake.org/  per instal•lar:

 `sudo apt-get install cmake`
 
* OpenCV: https://opencv.org/ per instal·lar:

`sudo apt-get install libopencv-dev`

### Compilar codi font:

Si s’han instal•lat correctament les llibreries anteriors, executar:

`cd webcam_capture`

`mkdir build`

`cd build`

`cmake ..`

`make`

Per executar només cal fer: `./webcam_capture`

## Modes de treball

De manera normal es mostrarà la captura de la webcam, opcións:
 * Prement la tecla g es mostrarà la imatge en escala de grisos.
 * Prement la tecla c es mostrarà la imarge en color.
 * Prement la tecla q es finalitzarà la execució.
