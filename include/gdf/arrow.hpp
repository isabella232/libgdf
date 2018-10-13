#include "cffi/types.h"
#include <arrow/api.h>

void* arrow_to_gdf(arrow::PrimitiveArray *array, gdf_column* result);
typedef arrow::Type::type arrow_type;
