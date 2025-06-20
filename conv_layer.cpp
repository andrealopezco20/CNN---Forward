#include "conv_layer.h"
#include <algorithm>

ConvLayer::ConvLayer(int in_ch, int out_ch, int k_size, int s, int p)
    : in_channels(in_ch), out_channels(out_ch), kernel_size(k_size),
      stride(s), padding(p) {
    for (int i = 0; i < out_ch; ++i) {
        kernels.emplace_back(in_ch, k_size, k_size);
        biases.push_back(0.0f);
        for (int d = 0; d < in_ch; ++d)
            for (int h = 0; h < k_size; ++h)
                for (int w = 0; w < k_size; ++w)
                    kernels[i].at(d, h, w) = 1.0f / (k_size * k_size);
    }
}

Tensor ConvLayer::forward(const Tensor& input) const {
    int out_height = (input.height + 2 * padding - kernel_size) / stride + 1;
    int out_width = (input.width + 2 * padding - kernel_size) / stride + 1;
    Tensor output(out_channels, out_height, out_width);

    for (int oc = 0; oc < out_channels; ++oc) {
        for (int oh = 0; oh < out_height; ++oh) {
            for (int ow = 0; ow < out_width; ++ow) {
                float sum = biases[oc];
                for (int ic = 0; ic < in_channels; ++ic) {
                    for (int kh = 0; kh < kernel_size; ++kh) {
                        for (int kw = 0; kw < kernel_size; ++kw) {
                            int ih = oh * stride + kh - padding;
                            int iw = ow * stride + kw - padding;
                            if (ih >= 0 && ih < input.height && iw >= 0 && iw < input.width) {
                                sum += input.at(ic, ih, iw) * kernels[oc].at(ic, kh, kw);
                            }
                        }
                    }
                }
                output.at(oc, oh, ow) = sum;
            }
        }
    }
    return output;
}
