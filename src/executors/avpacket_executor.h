#pragma once

struct AVPacket;
struct AVRational;

struct AVPacketExecutor
{
    static void execute(AVPacket *packet, const AVRational &src, const AVRational &dest);
};