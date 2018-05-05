#include "generator.h"

generator::generator(int min, int max){
        unsigned int bron = std::chrono::system_clock::now().time_since_epoch().count();
        gen.seed(bron);
        distrib = std::uniform_int_distribution<int>(min, max);
}

int generator::generate(){
        return distrib(gen);
}
