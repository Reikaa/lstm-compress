#ifndef LAYER_H
#define LAYER_H

#include <valarray>
#include <stdlib.h>
#include <math.h>

class Layer {
 public:
  Layer(unsigned int input_size, unsigned int auxiliary_input_size,
      unsigned int output_size, unsigned int num_cells, int horizon,
      float learning_rate, float gradient_clip);
  void ForwardPass(const std::valarray<float>& input, int input_symbol,
      std::valarray<float>* hidden, int hidden_start);
  void BackwardPass(const std::valarray<float>& input, int epoch,
      int layer, int input_symbol, std::valarray<float>* hidden_error);
  static inline float Rand() {
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
  }
  static inline float Logistic(float val) { return 1 / (1 + exp(-val)); }

 private:
  std::valarray<float> state_, output_gate_error_, state_error_,
      input_node_error_, input_gate_error_, forget_gate_error_, stored_error_;
  std::valarray<std::valarray<float>> tanh_state_, output_gate_state_,
      input_node_state_, input_gate_state_, forget_gate_state_, last_state_,
      forget_gate_, input_node_, input_gate_, output_gate_, forget_gate_update_,
      input_node_update_, input_gate_update_, output_gate_update_;
  float learning_rate_, gradient_clip_;
  unsigned int num_cells_, epoch_, horizon_, input_size_, output_size_;

  void ClipGradients(std::valarray<float>* arr);
};

#endif
