#include "pthread_once.h"

int main(int argc, char **argv) {

    singleton* s = singleton::instance();


    return 0;
}