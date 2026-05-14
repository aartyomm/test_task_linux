#include"scaner.h"
#include <filesystem>

MediaFiles scanMediaFiles(const std::string& homePath) {
    MediaFiles mediaFiles;
    for (const auto& entry : std::filesystem::recursive_directory_iterator(homePath)) {
        if (!entry.is_regular_file())
            continue;
        std::string extension = toLower(entry.path().extension().string());
        std::string filename = entry.path().filename().string();
        if (AUDIO_EXTENSIONS.find(extension) != AUDIO_EXTENSIONS.end())
            mediaFiles.audio.push_back(filename);
        else if (VIDEO_EXTENSIONS.find(extension) != VIDEO_EXTENSIONS.end())
            mediaFiles.video.push_back(filename);
        else if (IMAGE_EXTENSIONS.find(extension) != IMAGE_EXTENSIONS.end())
            mediaFiles.images.push_back(filename);
    }
    return mediaFiles;
}
