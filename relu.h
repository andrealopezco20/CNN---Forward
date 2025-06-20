#ifndef RELU_H
#define RELU_H

#include "tensor.h"
#include <algorithm>

class ReLU {
public:
    Tensor forward(const Tensor& input) const;
};

#endif