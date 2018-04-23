#include "connector.h"

int main(int argc, char *argv[])
{
    Connector* start = new Connector(argc, argv);

    delete start;

    return 0;
}
