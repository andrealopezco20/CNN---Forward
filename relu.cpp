#include "relu.h"
Tensor ReLU::forward(const Tensor& input) const {
    Tensor output(input.depth, input.height, input.width);
    for (size_t i = 0; i < input.data.size(); ++i) {
        output.data[i] = std::max(0.0f, input.data[i]);
    }
    return output;
}