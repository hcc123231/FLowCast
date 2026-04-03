#include<iostream>


#include"core/pull_stream.h"
#include"config_model.h"
#include"config_load.h"


int main(int argc,char* argv[]){
    if(argc<2){
        std::cout<<"Usage ["<<argv[0]<<"] [config_file]\n";
        return 1;
    }
    std::string configfile{argv[1]};
    ConfigModel cm{};
    ConfigLoader cl{configfile,cm};
    cl.load();
    PullStreamer ps{cm};
    ps.pullStream();
    return 0;
}