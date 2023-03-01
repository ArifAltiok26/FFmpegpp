
#include "ffmpegpp.h"
extern "C"
{
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}
int main(int argc, char const *argv[])
{
    using namespace ygv;
    InputFormatContextObject input("rtsp://admin:admin@192.168.1.3");
    input(find);

    int videoIndex = input(find, MediaType::VIDEO);

    DecoderContextObject decoder;
    SwsContextObject scaler;
    {
        AVCodecParametersObject params[2];
        for (int i = 0; i < 2; i++)
        {
            params[i](from, input->streams[videoIndex]);
        }

        params[1]->format = AV_PIX_FMT_BGR24;
        decoder(open, params[0]);
        scaler(open, params[0], params[1], SWS_BILINEAR);
    }

    AVPacketObject packet;
    AVFrameObject frame;
    AVFrameObject scaled;

    while (!input(read, packet))
    {
        if (packet->stream_index == videoIndex)
        {

            int retval = decoder(write, packet);
            while (retval >= 0)
            {
                retval = decoder(read, frame);
                if (retval < 0)
                {
                    break;
                }

                if (scaler(rescale, frame, scaled) >= 0)
                {

                    // Now, You have an image which is named Scaled and formatted in the BGR color space.
                    // You can do whatever you wants on it.

                    // If you've installed the OpenCV library, maybe you want to show it on the screen.
                    // Or you can find a way to show image with other libraries.
                    // I don't know which library you prefer such as SDL, gtklib, WinAPI ... etc.

                    // cv::Mat image(scaled->height, scaled->width, CV_8UC3, scaled->data[0], scaled->linesize[0]);
                    // cv::imshow("Test", image);
                    // if (cv::waitKey(1) == 'q')
                    //     exit(1);
                }
            }
        }
    }
    return 0;
}