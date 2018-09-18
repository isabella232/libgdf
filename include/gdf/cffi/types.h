
typedef enum {
  GDF_SORT = 0,
  GDF_HASH,
  N_GDF_METHODS,  /* additional methods should go BEFORE N_GDF_METHODS */
} gdf_method;

typedef enum {
  GDF_SUM = 0,
  GDF_MIN,
  GDF_MAX,
  GDF_AVG,
  GDF_COUNT,
  GDF_COUNT_DISTINCT,
  N_GDF_AGG_OPS, /* additional aggregation ops should go BEFORE N_GDF_... */
} gdf_agg_op;

/* additonal flags */
typedef struct gdf_context_{
  int flag_sorted;        /* 0 = No, 1 = yes */
  gdf_method flag_method; /* what method is used */
  int flag_distinct;      /* for COUNT: DISTINCT = 1, else = 0 */
} gdf_context;

struct _OpaqueRadixsortPlan;
typedef struct _OpaqueRadixsortPlan gdf_radixsort_plan_type;


struct _OpaqueSegmentedRadixsortPlan;
typedef struct _OpaqueSegmentedRadixsortPlan gdf_segmented_radixsort_plan_type;


struct _OpaqueJoinResult;
typedef struct _OpaqueJoinResult gdf_join_result_type;


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
