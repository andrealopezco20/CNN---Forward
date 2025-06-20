#ifndef CONV_LAYER_H
#define CONV_LAYER_H

#include "tensor.h"

class ConvLayer {
private:
    int in_channels, out_channels, kernel_size, stride, padding;
    std::vector<Tensor> kernels;
    std::vector<float> biases;

public:
    ConvLayer(int in_ch, int out_ch, int k_size, int s, int p);
    Tensor forward(const Tensor& input) const;
};

#endif
