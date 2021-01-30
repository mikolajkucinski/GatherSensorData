#pragma once
#include <memory>
#include <mutex>
#include <vector>

class CircularBuffer
{
public:
    explicit CircularBuffer(size_t bufferSize) : maxSize(bufferSize)
    {
        buffer = std::make_unique<float[]>(bufferSize);
    }

    bool isEmpty() const;
    bool isFull() const;
    size_t getSize() const;
    void putData(float data);
    float getData();
    std::vector<float> getAllAvailableData();

private:
    std::unique_ptr<float[]> buffer;
    size_t headItr{0};
    size_t tailItr{0};
    const size_t maxSize;
    bool isBufferFull{false};

    std::mutex bufferMutex;
};