#include "tensor.h"

Tensor::Tensor(int d, int h, int w) : depth(d), height(h), width(w) {
    data.resize(d * h * w);
}

float& Tensor::at(int d, int h, int w) {
    return data[d * height * width + h * width + w];
}

const float& Tensor::at(int d, int h, int w) const {
    return data[d * height * width + h * width + w];
}
