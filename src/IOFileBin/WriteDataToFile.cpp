#include "WriteDataToFile.h"

void WriteDataToFile(const std::string& outputPath, const std::vector<unsigned char>& data) {

    std::ofstream outputFile(outputPath, std::ios::binary);
    if (!outputFile) {
        throw std::runtime_error("cant open for writing: " + outputPath);
    }

    outputFile.write(reinterpret_cast<const char*>(data.data()), data.size());
}