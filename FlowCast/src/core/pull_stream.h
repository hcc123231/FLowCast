#pragma once
extern "C"{
    #include<libavformat/avformat.h>
    #include<libavcodec/avcodec.h>
}



#include"config_model.h"
//拉流
//拉取RTMP或者WebRTC流



//目标
/*
断流重连：网络闪断后自动重新打开输入。

丢帧策略：队列积压时丢弃旧帧，保证实时性。

多路并发：每路独立线程，资源隔离。

动态修改 URL：支持热切换拉流源。

代理/鉴权：RTMP 可能有 rtmp://user:pass@host/app/stream 或自定义 header。
*/

class PullStreamer{
public:
    PullStreamer(const ConfigModel& model):m_model_{model}{};
    void pullStream();
private:
    const ConfigModel& m_model_;

};



