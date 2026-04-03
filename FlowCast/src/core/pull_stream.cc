#include"pull_stream.h"


#include<iostream>

void PullStreamer::pullStream(){
    //初始化ffmpeg网络模块
    avformat_network_init();
    //打开rtmp源
    AVFormatContext* ipt_ctx=NULL;
    int ret=-1;
    ret=avformat_open_input(&ipt_ctx,m_model_["RTMP_URL"].c_str(),NULL,NULL);   
    if(ret!=0){
        std::cout<<"pullStream::avformat_open_input failed\n";
        exit(-1);
    }
    //获取流信息
    ret=avformat_find_stream_info(ipt_ctx,NULL);
    if(ret<0){
        std::cout<<"pullStream::avformat_find_stream_info failed\n";
        exit(-1);
    }
    
}