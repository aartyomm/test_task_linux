#pragma once

#include <vector>
#include <string>
#include <unordered_set>

struct MediaFiles
{
    std::vector<std::string> audio;
    std::vector<std::string> video;
    std::vector<std::string> images;
};

const std::unordered_set<std::string> AUDIO_EXTENSIONS = {
        ".mp3",
        ".wav"
};

const std::unordered_set<std::string> VIDEO_EXTENSIONS = {
        ".mp4",
        ".mkv"
};

const std::unordered_set<std::string> IMAGE_EXTENSIONS = {
        ".png",
        ".jpg",
        ".jpeg"
};

std::string toLower(std::string str);
