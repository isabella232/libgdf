#include "gtest/gtest.h"
#include "gdf/cffi/types.h"
#include "gdf/arrow.hpp"
#include <arrow/api.h>
#include <thrust/device_vector.h>
#include <arrow/gpu/cuda_api.h>

using namespace arrow;
using namespace arrow::gpu;

TEST(ArrowTests, GdfToArrow){
  gdf_column inputCol;
  std::vector<int32_t> inputData = {
    17696,
    17697,
  };
  inputCol.dtype = GDF_INT32;
  inputCol.size = 2;
  inputCol.valid = NULL;
  inputCol.null_count = 0;
  thrust::device_vector<int32_t> inputDataDev(inputData);
  inputCol.data = thrust::raw_pointer_cast(inputDataDev.data());
  auto arrow_dtype = int32();
  CudaDeviceManager* manager_;
  CudaDeviceManager::GetInstance(&manager_);
  std::shared_ptr<arrow::gpu::CudaContext> context_;
  manager_->GetContext(0, &context_);

  auto buffer = std::make_shared<CudaBuffer>((uint8_t *) inputCol.data,
                                             inputCol.size,
                                             context_,
                                             true,
                                             false);
  PrimitiveArray array(arrow_dtype, int64_t(inputCol.size), buffer);
  
  arrow_to_gdf(&array, &inputCol);
}
