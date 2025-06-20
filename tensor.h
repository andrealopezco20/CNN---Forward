#ifndef TENSOR_H
#define TENSOR_H

#include <vector>

class Tensor {
public:
    std::vector<float> data;
    int depth, height, width;

    Tensor(int d, int h, int w);

    float& at(int d, int h, int w);
    const float& at(int d, int h, int w) const;
};

#endif
