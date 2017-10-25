# webcam_capture
Captura imatges de la web cam fork de https://github.com/beta-robots/webcam_capture
### Requeriments inicials i dependències
* CMake
Es necessari disposar de l’eina CMake (https://cmake.org/)  per instal•lar: 
 `sudo apt-get install cmake`

* OpenCV
Es necessari disposar de l'eina OpenCV (https://opencv.org/) per instal·lar:
`sudo apt-get install libopencv-dev`

### Compilar codi font:

Si s’han instal•lat correctament les llibreries anteriors, executar:

`cd webcam_capture`

`mkdir build`

`cd build`

`cmake ..`

`make`

Per executar només cal fer: `./webcam_capture`
