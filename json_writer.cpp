#include"json_writer.h"
#include <fstream>

void writeJsonArray(std::ofstream& file, const std::vector<std::string>& files) {
    file << "[";
    for (int i = 0; i < files.size(); ++i) {
        file << "\"" << files[i] << "\"";
        if (i + 1 < files.size())
            file << ", ";
    }
    file << "]";
}

void saveMediaFiles(const MediaFiles& mediaFiles, const std::string& homePath) {
    std::ofstream file(homePath + "/.media_files");
    file << "{\n";
    file << "    \"audio\": ";
    writeJsonArray(file, mediaFiles.audio);
    file << ",\n";
    file << "    \"video\": ";
    writeJsonArray(file, mediaFiles.video);
    file << ",\n";
    file << "    \"images\": ";
    writeJsonArray(file, mediaFiles.images);
    file << "\n";
    file << "}\n";
}
