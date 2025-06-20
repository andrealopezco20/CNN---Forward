#include "pooling_layer.h"
#include <algorithm>

PoolingLayer::PoolingLayer(int k_size, int s, PoolType t)
    : kernel_size(k_size), stride(s), type(t) {}

Tensor PoolingLayer::forward(const Tensor& input) const {
    int out_height = (input.height - kernel_size) / stride + 1;
    int out_width = (input.width - kernel_size) / stride + 1;
    Tensor output(input.depth, out_height, out_width);

    for (int d = 0; d < input.depth; ++d) {
        for (int oh = 0; oh < out_height; ++oh) {
            for (int ow = 0; ow < out_width; ++ow) {
                float value = 0.0f;
                if (type == PoolType::Max) value = -std::numeric_limits<float>::infinity();
                if (type == PoolType::Min) value = std::numeric_limits<float>::infinity();
                int count = 0;

                for (int kh = 0; kh < kernel_size; ++kh) {
                    for (int kw = 0; kw < kernel_size; ++kw) {
                        int ih = oh * stride + kh;
                        int iw = ow * stride + kw;
                        if (ih < input.height && iw < input.width) {
                            float val = input.at(d, ih, iw);
                            if (type == PoolType::Max) value = std::max(value, val);
                            if (type == PoolType::Min) value = std::min(value, val);
                            if (type == PoolType::Average) {
                                value += val;
                                count++;
                            }
                        }
                    }
                }
                if (type == PoolType::Average) value /= count;
                output.at(d, oh, ow) = value;
            }
        }
    }
    return output;
}
