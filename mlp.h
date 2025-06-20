#ifndef MLP_H
#define MLP_H

#include <vector>
#include <stdexcept>
#include <algorithm>

class MLP {
private:
    std::vector<std::vector<float>> weights;
    std::vector<float> biases;
    int in_size, out_size;

public:
    MLP(int in, int out);
    std::vector<float> forward(const std::vector<float>& input) const;
};

#endif
