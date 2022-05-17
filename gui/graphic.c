#include "gfx.h"

int main(){
    gfx_open(200, 200, "Window Name");
    gfx_color(0,255,0);
    gfx_line(100,100,200,100);
    gfx_color(255,0,255);
    gfx_line(150,150,250,150);
    char key;
    while(key != 'q'){
        key = gfx_wait();
    }
    return 0;
}
