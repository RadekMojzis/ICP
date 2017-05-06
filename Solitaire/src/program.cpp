#include"program.hpp"


program::program(IF_TYPE IF){
    interface = IF;
    if(interface == GUI){
        gpu.init();
    }
    if(interface == TEXT){
        ppu.init();
    }
};
