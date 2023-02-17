# What is the purpose of this repo ?

FFmpeg is a great open source library for those who want to work on videos and sounds. However, since it is written in the C programming language, it is far from the object-oriented programming paradigm. The C++ Programming language can run FFMPEG directly because it supports the C language. This repo aims to pull a thin layer over FFmpeg with modern C++ to present it as object-oriented, as well as to easily present the components of FFMPEG. 

Also, if you use it from this repo instead of using FFmpeg directly, you will be less affected by the changes between FFmpeg versions.

# What is not the purpose of this repo ?

This repo is definitely not a repo of a FFmpeg competitor. Even this repo has a direct FFmpeg dependency. You should understand that if you are looking for an alternative to FFmpeg, this repo will not benefit you. As described above, it is to make FFMPEG suitable for the object-oriented programming paradigm with modern C++ and provide ease of use.

# What are the design principles of this repo ?
- Simplicity is the primary goal.
- It is to avoid extra latency with compile time bindings.
- Wrapper classes should be able to work directly with FFmpeg functions if necessary.

# Requirements
- C++ Compiler that defines at least the c++14 standard.
- The appropriate version of FFMPEG (version 5.0 for now)

# To Do

- The documentation will be prepared.
- Sample programs will be prepared.
- Benchmark tests will be prepared directly from FFmpeg and comparisons of this repo usage.
- Ffmpeg installation for windows and linux os .bat/.sh their files will be prepared.
- The wrapping, which is currently FFmpeg version 5.0, will be extended backwards to all versions.

# How do you contribute ? 

Contributions to this repo are welcomed with satisfaction. Also, since this repo is still very new, even the smallest test result is a huge contribution. Please do not hesitate to contact.

