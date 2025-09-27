#include "master.h"

Master::Master() {
    // needs to start a tcp server ! listening for connections ...
    // workers then need to connect to a server, the master's tcp server, sending at first some stuff.
    // needs to be a persistent connection (?) so master needs to handle connections async (or sync ? ) 

    create_server();
    // load_dataset();
    // load_code();
    //

}
