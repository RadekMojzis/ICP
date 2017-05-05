#include"GPU.hpp"


PPU::PPU(IF_TYPE interface){
    type = interface;
    if(type == TEXT){

    }

    if(type == GUI){
        QApplication a();
        MainWindow w;
        w.show();

        return a.exec();
    }
}
