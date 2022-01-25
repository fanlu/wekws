// Copyright 2022 JDT Inc. All Rights Reserved.

#ifndef DECODER_TORCH_KWS_MODEL_H_
#define DECODER_TORCH_KWS_MODEL_H_

#include <memory>
#include <string>

#include "torch/script.h"
#include "torch/torch.h"
#include "utils/utils.h"

namespace wenet {

using TorchModule = torch::jit::script::Module;
// A wrapper for pytorch k model
class TorchKwsModel {
 public:
  TorchKwsModel() = default;

  void Read(const std::string& model_path, int num_threads = 1);
  int right_context() const { return right_context_; }
  int subsampling_rate() const { return subsampling_rate_; }
  int sos() const { return sos_; }
  int eos() const { return eos_; }
  bool is_bidirectional_decoder() const { return is_bidirectional_decoder_; }

  std::shared_ptr<TorchModule> torch_model() const { return module_; }

 private:
  std::shared_ptr<TorchModule> module_ = nullptr;
  int right_context_ = 1;
  int subsampling_rate_ = 1;
  int sos_ = 0;
  int eos_ = 0;
  bool is_bidirectional_decoder_ = false;

 public:
  WENET_DISALLOW_COPY_AND_ASSIGN(TorchKwsModel);
};

}  // namespace wenet

#endif  // DECODER_TORCH_KWS_MODEL_H_
