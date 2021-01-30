#include <iostream>
#include "circularBuffer.hpp"

bool CircularBuffer::isEmpty() const
{
    return not isBufferFull and headItr == tailItr;
}

bool CircularBuffer::isFull() const
{
    return isBufferFull;
}

size_t CircularBuffer::getSize() const
{
    if (not isBufferFull)
    {
        return headItr >= tailItr ? (headItr - tailItr) : (maxSize + headItr + tailItr);
    }

    return maxSize;
}

void CircularBuffer::putData(float data)
{
    std::lock_guard<std::mutex> lock(bufferMutex);

    buffer[headItr] = data;

    if (isBufferFull)
    {
        tailItr = (tailItr + 1) % maxSize;
    }
    headItr = (headItr + 1) % maxSize;

    bool isBufferFullNow{headItr == tailItr};
    isBufferFull = isBufferFullNow;
}

std::vector<float> CircularBuffer::getAllAvailableData()
{
    std::lock_guard<std::mutex> lock(bufferMutex);
    std::vector<float> availableData{};

    if (isEmpty())
    {
        return {};
    }

    while (tailItr != headItr)
    {
        availableData.push_back(buffer[tailItr]);
        isBufferFull = false;
        tailItr = (tailItr + 1) % maxSize;
    }

    return availableData;
}