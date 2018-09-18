#ifndef GDF_GDF_H
#define GDF_GDF_H

#include <cstdlib>
#include <cstdint>

#include "gdf-arrow/cffi/types.h"


#include "cffi/types.h"


#define GDF_VALID_BITSIZE  (sizeof(gdf_valid_type) * 8)

extern "C"{
#include "gdf-arrow/cffi/functions.h"  
#include "cffi/functions.h"
}

#endif /* GDF_GDF_H */
