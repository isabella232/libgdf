#pragma once

/* --------------------------------------------------------------------------*/
/** 
 * @Synopsis  These enums indicate which method is to be used for an operation.
 * For example, it is used to select between the hash-based vs. sort-based implementations
 * of the Join operation.
 */
/* ----------------------------------------------------------------------------*/

typedef enum {
  GDF_SORT = 0,   /**< Indicates that the sort-based implementation of the function will be used */
  GDF_HASH,       /**< Indicates that the hash-based implementation of the function will be used */
  N_GDF_METHODS,  /* additional methods should go BEFORE N_GDF_METHODS */
} gdf_method;

typedef enum {
  GDF_QUANT_LINEAR =0,
  GDF_QUANT_LOWER,
  GDF_QUANT_HIGHER,
  GDF_QUANT_MIDPOINT,
  GDF_QUANT_NEAREST,
  N_GDF_QUANT_METHODS,
} gdf_quantile_method;


/* --------------------------------------------------------------------------*/
/** 
 * @Synopsis These enums indicate the supported aggregation operations that can be
 * performed on a set of aggregation columns as part of a GroupBy operation
 */
/* ----------------------------------------------------------------------------*/
typedef enum {
  GDF_SUM = 0,        /**< Computes the sum of all values in the aggregation column*/
  GDF_MIN,            /**< Computes minimum value in the aggregation column */
  GDF_MAX,            /**< Computes maximum value in the aggregation column */
  GDF_AVG,            /**< Computes arithmetic mean of all values in the aggregation column */
  GDF_COUNT,          /**< Computes histogram of the occurance of each key in the GroupBy Columns */
  GDF_COUNT_DISTINCT, /**< Counts the number of distinct keys in the GroupBy columns */
  N_GDF_AGG_OPS,      /**< The total number of aggregation operations. ALL NEW OPERATIONS SHOULD BE ADDED ABOVE THIS LINE*/
} gdf_agg_op;

/* --------------------------------------------------------------------------*/
/** 
 * @Synopsis  This struct holds various information about how an operation should be 
 * performed as well as additional information about the input data.
 */
/* ----------------------------------------------------------------------------*/
typedef struct gdf_context_{
  int flag_sorted;        /**< Indicates if the input data is sorted. 0 = No, 1 = yes */
  gdf_method flag_method; /**< The method to be used for the operation (e.g., sort vs hash) */
  int flag_distinct;      /**< for COUNT: DISTINCT = 1, else = 0 */
  int flag_sort_result;   /**< When method is GDF_HASH, 0 = result is not sorted, 1 = result is sorted */
  int flag_sort_inplace;  /**< 0 = No sort in place allowed, 1 = else */
} gdf_context;

struct _OpaqueRadixsortPlan;
typedef struct _OpaqueRadixsortPlan gdf_radixsort_plan_type;


struct _OpaqueSegmentedRadixsortPlan;
typedef struct _OpaqueSegmentedRadixsortPlan gdf_segmented_radixsort_plan_type;




typedef enum{
	GDF_ORDER_ASC,
	GDF_ORDER_DESC
} order_by_type;

typedef enum{
	GDF_EQUALS,
	GDF_NOT_EQUALS,
	GDF_LESS_THAN,
	GDF_LESS_THAN_OR_EQUALS,
	GDF_GREATER_THAN,
	GDF_GREATER_THAN_OR_EQUALS
} gdf_comparison_operator;

typedef enum{
	GDF_WINDOW_RANGE,
	GDF_WINDOW_ROW
} window_function_type;

typedef enum{
	GDF_WINDOW_AVG,
	GDF_WINDOW_SUM,
	GDF_WINDOW_MAX,
	GDF_WINDOW_MIN,
	GDF_WINDOW_COUNT,
	GDF_WINDOW_STDDEV,
	GDF_WINDOW_VAR //variance
} window_reduction_type;
