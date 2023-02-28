#pragma once
namespace ygv
{
namespace hardware
{
enum class DeviceType
{
    NONE,
    VDPAU,
    CUDA,
    VAAPI,
    DXVA2,
    QSV,
    VIDEOTOOLBOX,
    D3D11VA,
    DRM,
    OPENCL,
    MEDIACODEC,
    VULKAN,
};
} // namespace hardware
} // namespace ygv