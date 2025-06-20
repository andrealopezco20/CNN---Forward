#ifndef POOLING_LAYER_H
#define POOLING_LAYER_H

#include "tensor.h"
#include <limits>

enum class PoolType { Max, Min, Average };

class PoolingLayer {
private:
    int kernel_size, stride;
    PoolType type;

public:
    PoolingLayer(int k_size, int s, PoolType t);
    Tensor forward(const Tensor& input) const;
};

#endif
