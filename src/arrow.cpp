#include <gdf/gdf.h>
#include <gdf/errorutils.h>
#include <arrow/api.h>
#include <gdf/arrow.hpp>


gdf_dtype arrow_dtype_to_gdf_dtype(arrow::Type::type type){
  gdf_dtype result;
  switch(type)
    {
    case arrow_type::INT8:
      result =  gdf_dtype::GDF_INT8;
      break;
    case arrow_type::INT16:
      result =  gdf_dtype::GDF_INT16;
      break;
    case arrow_type::INT32:
      result =  gdf_dtype::GDF_INT32;
      break;
    case arrow_type::INT64:
      result =  gdf_dtype::GDF_INT64;
      break;
    case arrow_type::FLOAT:
      result =  gdf_dtype::GDF_FLOAT32;
      break;
    case arrow_type::DOUBLE:
      result =  gdf_dtype::GDF_FLOAT64;
      break;
    }
  return result;
}
arrow_type gdf_dtype_to_arrow_dtype(gdf_dtype type){
  arrow_type result;
  switch(type)
    {
    case gdf_dtype::GDF_INT8:
      result = arrow_type::INT8;
      break;
    case gdf_dtype::GDF_INT16:
      result = arrow_type::INT16;
      break;
    case gdf_dtype::GDF_INT32:
      result = arrow_type::INT32;
      break;
    case gdf_dtype::GDF_INT64:
      result = arrow_type::INT64;
      break;
    case gdf_dtype::GDF_FLOAT32:
      result = arrow_type::FLOAT;
      break;
    case gdf_dtype::GDF_FLOAT64:
      result = arrow_type::DOUBLE;
      break;
    }
  return result;
}
void* arrow_to_gdf(arrow::PrimitiveArray *array, gdf_column* result){
  std::shared_ptr<arrow::ArrayData> data = array->data();
  gdf_dtype dtype = arrow_dtype_to_gdf_dtype(data->type->id());
  result->data = (void *)array->values()->data(); 
  result->valid = (gdf_valid_type*)array->null_bitmap()->data();
  result->size = array->length();
  result->dtype = dtype;
  result-> null_count = array->null_count();
}

// arrow::Array arrow_to_gdf(gdf_column *column){
  
// }


