

#include "connector.h"
#include "engine.h"
#include "sqliteconnector.h"

int main(int argc, char *argv[])
{
    Connector* start = new Connector(argc, argv);

    delete start;

    return 0;
}
