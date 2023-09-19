#include "xop/RtmpServer.h"
#include "xop/H264Parser.h"
#include "net/EventLoop.h"

/*
	容送
	ffmpeg -re -i test.mp4 -vcodec h264 -acodec aac -f flv rtmp://127.0.0.1/live/test

	性送
	ffplay -i rtmp://127.0.0.1:1935/live/test

*/

int main(int argc, char **argv)
{

	int port = 1935;

	printf("rtmpServer rtmp://127.0.0.1:%d\n", port);

	xop::EventLoop eventLoop;


	auto rtmp_server = xop::RtmpServer::Create(&eventLoop);
	rtmp_server->SetChunkSize(60000);
	//rtmp_server->SetGopCache(); // enable gop cache

	rtmp_server->SetEventCallback([](std::string type, std::string stream_path) {
		printf("[Event] %s, stream path: %s\n\n", type.c_str(), stream_path.c_str());
	});

	if (!rtmp_server->Start("0.0.0.0", port)) {
		printf("start rtmpServer error\n");
	}


	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
    
	rtmp_server->Stop();

	return 0;
}

