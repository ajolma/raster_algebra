#include "gdal_map_algebra.hpp"
#include "gma_classes.hpp"
#include "gma_band.hpp"
#include "gma_two_bands.hpp"

gma_operator_t::gma_operator_t() {
    arg1 = NULL;
    arg2 = NULL;
}
void gma_operator_t::set_operand(gma_operand_t *op) {
    if (arg1 == NULL) {
        arg1 = op;
    } else {
        arg2 = op;
    }
}

#define GMA_OPERATOR_SUM_T_GET_VALUE(type)                              \
    void gma_operator_sum_t::get_value(type *value, int x, int y) {     \
    type a1;                                                            \
    type a2;                                                            \
    arg1->get_value(&a1, x, y);                                         \
    arg2->get_value(&a2, x, y);                                         \
    *value = a1 + a2; \
}
GMA_OPERATOR_SUM_T_GET_VALUE(uint8_t);
GMA_OPERATOR_SUM_T_GET_VALUE(uint16_t);
GMA_OPERATOR_SUM_T_GET_VALUE(uint32_t);
GMA_OPERATOR_SUM_T_GET_VALUE(int16_t);
GMA_OPERATOR_SUM_T_GET_VALUE(int32_t);
GMA_OPERATOR_SUM_T_GET_VALUE(float);
GMA_OPERATOR_SUM_T_GET_VALUE(double);

#define GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(type)                       \
    void gma_operator_difference_t::get_value(type *value, int x, int y) { \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 - a2;                                               \
    }
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(uint8_t);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(uint16_t);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(uint32_t);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(int16_t);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(int32_t);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(float);
GMA_OPERATOR_DIFFERENCE_T_GET_VALUE(double);

#define GMA_OPERATOR_PRODUCT_T_GET_VALUE(type)                          \
    void gma_operator_product_t::get_value(type *value, int x, int y) { \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 * a2;                                               \
    }
GMA_OPERATOR_PRODUCT_T_GET_VALUE(uint8_t);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(uint16_t);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(uint32_t);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(int16_t);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(int32_t);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(float);
GMA_OPERATOR_PRODUCT_T_GET_VALUE(double);

#define GMA_OPERATOR_QUOTIENT_T_GET_VALUE(type)                         \
    void gma_operator_quotient_t::get_value(type *value, int x, int y) { \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 / a2;                                               \
    }
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(uint8_t);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(uint16_t);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(uint32_t);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(int16_t);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(int32_t);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(float);
GMA_OPERATOR_QUOTIENT_T_GET_VALUE(double);

#define GMA_OPERATOR_REMAINDER_T_GET_VALUE(type)                        \
    void gma_operator_remainder_t::get_value(type *value, int x, int y) { \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 % a2;                                               \
    }
GMA_OPERATOR_REMAINDER_T_GET_VALUE(uint8_t);
GMA_OPERATOR_REMAINDER_T_GET_VALUE(uint16_t);
GMA_OPERATOR_REMAINDER_T_GET_VALUE(uint32_t);
GMA_OPERATOR_REMAINDER_T_GET_VALUE(int16_t);
GMA_OPERATOR_REMAINDER_T_GET_VALUE(int32_t);
void gma_operator_remainder_t::get_value(float *value, int x, int y) {
    // error
}
void gma_operator_remainder_t::get_value(double *value, int x, int y) {
    // error
}

#define GMA_OPERATOR_EQ_T_GET_VALUE(type)                               \
    void gma_operator_eq_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 == a2;                                              \
    }
GMA_OPERATOR_EQ_T_GET_VALUE(uint8_t);
GMA_OPERATOR_EQ_T_GET_VALUE(uint16_t);
GMA_OPERATOR_EQ_T_GET_VALUE(uint32_t);
GMA_OPERATOR_EQ_T_GET_VALUE(int16_t);
GMA_OPERATOR_EQ_T_GET_VALUE(int32_t);
GMA_OPERATOR_EQ_T_GET_VALUE(float);
GMA_OPERATOR_EQ_T_GET_VALUE(double);

#define GMA_OPERATOR_NE_T_GET_VALUE(type)                               \
    void gma_operator_ne_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 != a2;                                              \
    }
GMA_OPERATOR_NE_T_GET_VALUE(uint8_t);
GMA_OPERATOR_NE_T_GET_VALUE(uint16_t);
GMA_OPERATOR_NE_T_GET_VALUE(uint32_t);
GMA_OPERATOR_NE_T_GET_VALUE(int16_t);
GMA_OPERATOR_NE_T_GET_VALUE(int32_t);
GMA_OPERATOR_NE_T_GET_VALUE(float);
GMA_OPERATOR_NE_T_GET_VALUE(double);

#define GMA_OPERATOR_GT_T_GET_VALUE(type)                               \
    void gma_operator_gt_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 > a2;                                               \
    }
GMA_OPERATOR_GT_T_GET_VALUE(uint8_t);
GMA_OPERATOR_GT_T_GET_VALUE(uint16_t);
GMA_OPERATOR_GT_T_GET_VALUE(uint32_t);
GMA_OPERATOR_GT_T_GET_VALUE(int16_t);
GMA_OPERATOR_GT_T_GET_VALUE(int32_t);
GMA_OPERATOR_GT_T_GET_VALUE(float);
GMA_OPERATOR_GT_T_GET_VALUE(double);

#define GMA_OPERATOR_LT_T_GET_VALUE(type)                               \
    void gma_operator_lt_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 < a2;                                               \
    }
GMA_OPERATOR_LT_T_GET_VALUE(uint8_t);
GMA_OPERATOR_LT_T_GET_VALUE(uint16_t);
GMA_OPERATOR_LT_T_GET_VALUE(uint32_t);
GMA_OPERATOR_LT_T_GET_VALUE(int16_t);
GMA_OPERATOR_LT_T_GET_VALUE(int32_t);
GMA_OPERATOR_LT_T_GET_VALUE(float);
GMA_OPERATOR_LT_T_GET_VALUE(double);

#define GMA_OPERATOR_GE_T_GET_VALUE(type)                               \
    void gma_operator_ge_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 >= a2;                                              \
    }
GMA_OPERATOR_GE_T_GET_VALUE(uint8_t);
GMA_OPERATOR_GE_T_GET_VALUE(uint16_t);
GMA_OPERATOR_GE_T_GET_VALUE(uint32_t);
GMA_OPERATOR_GE_T_GET_VALUE(int16_t);
GMA_OPERATOR_GE_T_GET_VALUE(int32_t);
GMA_OPERATOR_GE_T_GET_VALUE(float);
GMA_OPERATOR_GE_T_GET_VALUE(double);

#define GMA_OPERATOR_LE_T_GET_VALUE(type)                               \
    void gma_operator_le_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 <= a2;                                              \
    }
GMA_OPERATOR_LE_T_GET_VALUE(uint8_t);
GMA_OPERATOR_LE_T_GET_VALUE(uint16_t);
GMA_OPERATOR_LE_T_GET_VALUE(uint32_t);
GMA_OPERATOR_LE_T_GET_VALUE(int16_t);
GMA_OPERATOR_LE_T_GET_VALUE(int32_t);
GMA_OPERATOR_LE_T_GET_VALUE(float);
GMA_OPERATOR_LE_T_GET_VALUE(double);

#define GMA_OPERATOR_AND_T_GET_VALUE(type)                              \
    void gma_operator_and_t::get_value(type *value, int x, int y) {     \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 && a2;                                              \
    }
GMA_OPERATOR_AND_T_GET_VALUE(uint8_t);
GMA_OPERATOR_AND_T_GET_VALUE(uint16_t);
GMA_OPERATOR_AND_T_GET_VALUE(uint32_t);
GMA_OPERATOR_AND_T_GET_VALUE(int16_t);
GMA_OPERATOR_AND_T_GET_VALUE(int32_t);
GMA_OPERATOR_AND_T_GET_VALUE(float);
GMA_OPERATOR_AND_T_GET_VALUE(double);

#define GMA_OPERATOR_OR_T_GET_VALUE(type)                               \
    void gma_operator_or_t::get_value(type *value, int x, int y) {      \
        type a1;                                                        \
        type a2;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        arg2->get_value(&a2, x, y);                                     \
        *value = a1 || a2;                                              \
    }
GMA_OPERATOR_OR_T_GET_VALUE(uint8_t);
GMA_OPERATOR_OR_T_GET_VALUE(uint16_t);
GMA_OPERATOR_OR_T_GET_VALUE(uint32_t);
GMA_OPERATOR_OR_T_GET_VALUE(int16_t);
GMA_OPERATOR_OR_T_GET_VALUE(int32_t);
GMA_OPERATOR_OR_T_GET_VALUE(float);
GMA_OPERATOR_OR_T_GET_VALUE(double);

#define GMA_OPERATOR_NOT_T_GET_VALUE(type)                              \
    void gma_operator_not_t::get_value(type *value, int x, int y) {     \
        type a1;                                                        \
        arg1->get_value(&a1, x, y);                                     \
        *value = !a1;                                                   \
    }
GMA_OPERATOR_NOT_T_GET_VALUE(uint8_t);
GMA_OPERATOR_NOT_T_GET_VALUE(uint16_t);
GMA_OPERATOR_NOT_T_GET_VALUE(uint32_t);
GMA_OPERATOR_NOT_T_GET_VALUE(int16_t);
GMA_OPERATOR_NOT_T_GET_VALUE(int32_t);
GMA_OPERATOR_NOT_T_GET_VALUE(float);
GMA_OPERATOR_NOT_T_GET_VALUE(double);

gma_function_rand_t::gma_function_rand_t(int max) {
    m_max = max;
}
#define GMA_FUNCTION_RAND_T_GET_VALUE(type)                             \
    void gma_function_rand_t::get_value(type *value, int, int) {        \
        int x = std::rand() % m_max;                                    \
        *value = x;                                                     \
    }
GMA_FUNCTION_RAND_T_GET_VALUE(uint8_t);
GMA_FUNCTION_RAND_T_GET_VALUE(uint16_t);
GMA_FUNCTION_RAND_T_GET_VALUE(uint32_t);
GMA_FUNCTION_RAND_T_GET_VALUE(int16_t);
GMA_FUNCTION_RAND_T_GET_VALUE(int32_t);
GMA_FUNCTION_RAND_T_GET_VALUE(float);
GMA_FUNCTION_RAND_T_GET_VALUE(double);

#define GMA_FUNCTION_ABS_T_GET_VALUE(type)                              \
    void gma_function_abs_t::get_value(type *value, int x, int y) {     \
        *value = abs(*value);                                           \
    }
GMA_FUNCTION_ABS_T_GET_VALUE(uint8_t);
GMA_FUNCTION_ABS_T_GET_VALUE(uint16_t);
GMA_FUNCTION_ABS_T_GET_VALUE(uint32_t);
GMA_FUNCTION_ABS_T_GET_VALUE(int16_t);
GMA_FUNCTION_ABS_T_GET_VALUE(int32_t);
GMA_FUNCTION_ABS_T_GET_VALUE(float);
GMA_FUNCTION_ABS_T_GET_VALUE(double);

#define GMA_FUNCTION_EXP_T_GET_VALUE(type)                              \
    void gma_function_exp_t::get_value(type *value, int x, int y) {     \
        *value = exp(*value);                                           \
    }
GMA_FUNCTION_EXP_T_GET_VALUE(uint8_t);
GMA_FUNCTION_EXP_T_GET_VALUE(uint16_t);
GMA_FUNCTION_EXP_T_GET_VALUE(uint32_t);
GMA_FUNCTION_EXP_T_GET_VALUE(int16_t);
GMA_FUNCTION_EXP_T_GET_VALUE(int32_t);
GMA_FUNCTION_EXP_T_GET_VALUE(float);
GMA_FUNCTION_EXP_T_GET_VALUE(double);

#define GMA_FUNCTION_LOG_T_GET_VALUE(type)                              \
    void gma_function_log_t::get_value(type *value, int x, int y) {     \
        *value = log(*value);                                           \
    }
GMA_FUNCTION_LOG_T_GET_VALUE(uint8_t);
GMA_FUNCTION_LOG_T_GET_VALUE(uint16_t);
GMA_FUNCTION_LOG_T_GET_VALUE(uint32_t);
GMA_FUNCTION_LOG_T_GET_VALUE(int16_t);
GMA_FUNCTION_LOG_T_GET_VALUE(int32_t);
GMA_FUNCTION_LOG_T_GET_VALUE(float);
GMA_FUNCTION_LOG_T_GET_VALUE(double);

#define GMA_FUNCTION_LOG10_T_GET_VALUE(type)                            \
    void gma_function_log10_t::get_value(type *value, int x, int y) {   \
        *value = log10(*value);                                         \
    }
GMA_FUNCTION_LOG10_T_GET_VALUE(uint8_t);
GMA_FUNCTION_LOG10_T_GET_VALUE(uint16_t);
GMA_FUNCTION_LOG10_T_GET_VALUE(uint32_t);
GMA_FUNCTION_LOG10_T_GET_VALUE(int16_t);
GMA_FUNCTION_LOG10_T_GET_VALUE(int32_t);
GMA_FUNCTION_LOG10_T_GET_VALUE(float);
GMA_FUNCTION_LOG10_T_GET_VALUE(double);

#define GMA_FUNCTION_SQRT_T_GET_VALUE(type)                             \
    void gma_function_sqrt_t::get_value(type *value, int x, int y) {    \
        *value = sqrt(*value);                                          \
    }
GMA_FUNCTION_SQRT_T_GET_VALUE(uint8_t);
GMA_FUNCTION_SQRT_T_GET_VALUE(uint16_t);
GMA_FUNCTION_SQRT_T_GET_VALUE(uint32_t);
GMA_FUNCTION_SQRT_T_GET_VALUE(int16_t);
GMA_FUNCTION_SQRT_T_GET_VALUE(int32_t);
GMA_FUNCTION_SQRT_T_GET_VALUE(float);
GMA_FUNCTION_SQRT_T_GET_VALUE(double);

#define GMA_FUNCTION_SIN_T_GET_VALUE(type)                              \
    void gma_function_sin_t::get_value(type *value, int x, int y) {     \
        *value = sin(*value);                                           \
    }
GMA_FUNCTION_SIN_T_GET_VALUE(uint8_t);
GMA_FUNCTION_SIN_T_GET_VALUE(uint16_t);
GMA_FUNCTION_SIN_T_GET_VALUE(uint32_t);
GMA_FUNCTION_SIN_T_GET_VALUE(int16_t);
GMA_FUNCTION_SIN_T_GET_VALUE(int32_t);
GMA_FUNCTION_SIN_T_GET_VALUE(float);
GMA_FUNCTION_SIN_T_GET_VALUE(double);

#define GMA_FUNCTION_COS_T_GET_VALUE(type)                              \
    void gma_function_cos_t::get_value(type *value, int x, int y) {     \
        *value = cos(*value);                                           \
    }
GMA_FUNCTION_COS_T_GET_VALUE(uint8_t);
GMA_FUNCTION_COS_T_GET_VALUE(uint16_t);
GMA_FUNCTION_COS_T_GET_VALUE(uint32_t);
GMA_FUNCTION_COS_T_GET_VALUE(int16_t);
GMA_FUNCTION_COS_T_GET_VALUE(int32_t);
GMA_FUNCTION_COS_T_GET_VALUE(float);
GMA_FUNCTION_COS_T_GET_VALUE(double);

#define GMA_FUNCTION_TAN_T_GET_VALUE(type)                              \
    void gma_function_tan_t::get_value(type *value, int x, int y) {     \
        *value = tan(*value);                                           \
    }
GMA_FUNCTION_TAN_T_GET_VALUE(uint8_t);
GMA_FUNCTION_TAN_T_GET_VALUE(uint16_t);
GMA_FUNCTION_TAN_T_GET_VALUE(uint32_t);
GMA_FUNCTION_TAN_T_GET_VALUE(int16_t);
GMA_FUNCTION_TAN_T_GET_VALUE(int32_t);
GMA_FUNCTION_TAN_T_GET_VALUE(float);
GMA_FUNCTION_TAN_T_GET_VALUE(double);

#define GMA_FUNCTION_CEIL_T_GET_VALUE(type)                             \
    void gma_function_ceil_t::get_value(type *value, int x, int y) {    \
        *value = ceil(*value);                                          \
    }
GMA_FUNCTION_CEIL_T_GET_VALUE(uint8_t);
GMA_FUNCTION_CEIL_T_GET_VALUE(uint16_t);
GMA_FUNCTION_CEIL_T_GET_VALUE(uint32_t);
GMA_FUNCTION_CEIL_T_GET_VALUE(int16_t);
GMA_FUNCTION_CEIL_T_GET_VALUE(int32_t);
GMA_FUNCTION_CEIL_T_GET_VALUE(float);
GMA_FUNCTION_CEIL_T_GET_VALUE(double);

#define GMA_FUNCTION_FLOOR_T_GET_VALUE(type)                            \
    void gma_function_floor_t::get_value(type *value, int x, int y) {   \
        *value = floor(*value);                                         \
    }
GMA_FUNCTION_FLOOR_T_GET_VALUE(uint8_t);
GMA_FUNCTION_FLOOR_T_GET_VALUE(uint16_t);
GMA_FUNCTION_FLOOR_T_GET_VALUE(uint32_t);
GMA_FUNCTION_FLOOR_T_GET_VALUE(int16_t);
GMA_FUNCTION_FLOOR_T_GET_VALUE(int32_t);
GMA_FUNCTION_FLOOR_T_GET_VALUE(float);
GMA_FUNCTION_FLOOR_T_GET_VALUE(double);


gma_band_t *gma_new_band(GDALRasterBand *b) {
    switch (b->GetRasterDataType()) {
    case GDT_Byte:
        return new gma_band_p<uint8_t>(b);
    case GDT_UInt16:
        return new gma_band_p<uint16_t>(b);
    case GDT_Int16:
        return new gma_band_p<int16_t>(b);
    case GDT_UInt32:
        return new gma_band_p<uint32_t>(b);
    case GDT_Int32:
        return new gma_band_p<int32_t>(b);
    case GDT_Float32:
        return new gma_band_p<float>(b);
    case GDT_Float64:
        return new gma_band_p<double>(b);
    default:
        //goto not_implemented_for_these_datatypes;
        break;
    }
    return NULL;
}

gma_band_t *gma_new_band(const char *name) {
    return gma_new_band(((GDALDataset*)GDALOpen(name, GA_ReadOnly))->GetRasterBand(1));
}

template <> GDALDataType gma_number_p<uint8_t>::datatype_p() { return GDT_Byte; }
template <> GDALDataType gma_number_p<uint16_t>::datatype_p() { return GDT_UInt16; }
template <> GDALDataType gma_number_p<int16_t>::datatype_p() { return GDT_Int16; }
template <> GDALDataType gma_number_p<uint32_t>::datatype_p() { return GDT_UInt32; }
template <> GDALDataType gma_number_p<int32_t>::datatype_p() { return GDT_Int32; }
template <> GDALDataType gma_number_p<float>::datatype_p() { return GDT_Float32; }
template <> GDALDataType gma_number_p<double>::datatype_p() { return GDT_Float64; }

template <> bool gma_number_p<uint8_t>::is_float() { return false; }
template <> bool gma_number_p<uint16_t>::is_float() { return false; }
template <> bool gma_number_p<int16_t>::is_float() { return false; }
template <> bool gma_number_p<uint32_t>::is_float() { return false; }
template <> bool gma_number_p<int32_t>::is_float() { return false; }
template <> bool gma_number_p<float>::is_float() { return true; }
template <> bool gma_number_p<double>::is_float() { return true; }

template <> const char *gma_number_p<uint8_t>::format() { return "%u"; }
template <> const char *gma_number_p<uint16_t>::format() { return "%u"; }
template <> const char *gma_number_p<int16_t>::format() { return "%i"; }
template <> const char *gma_number_p<uint32_t>::format() { return "%u"; }
template <> const char *gma_number_p<int32_t>::format() { return "%i"; }
template <> const char *gma_number_p<float>::format() { return "%.2f"; }
template <> const char *gma_number_p<double>::format() { return "%.3f"; }

template <> int gma_band_p<uint8_t>::m_log10(gma_block<uint8_t>*, gma_object_t**, gma_object_t*, int) { return 0; }
template <> int gma_band_p<uint16_t>::m_log10(gma_block<uint16_t>*, gma_object_t**, gma_object_t*, int) { return 0; }
template <> int gma_band_p<int16_t>::m_log10(gma_block<int16_t>*, gma_object_t**, gma_object_t*, int) { return 0; }
template <> int gma_band_p<uint32_t>::m_log10(gma_block<uint32_t>*, gma_object_t**, gma_object_t*, int) { return 0; }
template <> int gma_band_p<int32_t>::m_log10(gma_block<int32_t>*, gma_object_t**, gma_object_t*, int) { return 0; }

template <> int gma_band_p<float>::m_modulus(gma_block<float>*, gma_object_t**, gma_object_t*, int) { return 0; }
template <> int gma_band_p<double>::m_modulus(gma_block<double>*, gma_object_t**, gma_object_t*, int) { return 0; }

gma_two_bands_t *gma_new_two_bands(GDALDataType type1, GDALDataType type2) {
    switch (type1) {
    case GDT_Byte: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<uint8_t,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<uint8_t,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<uint8_t,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<uint8_t,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<uint8_t,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<uint8_t,float>;
        case GDT_Float64:
            return new gma_two_bands_p<uint8_t,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_UInt16: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<uint16_t,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<uint16_t,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<uint16_t,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<uint16_t,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<uint16_t,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<uint16_t,float>;
        case GDT_Float64:
            return new gma_two_bands_p<uint16_t,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_Int16: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<int16_t,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<int16_t,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<int16_t,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<int16_t,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<int16_t,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<int16_t,float>;
        case GDT_Float64:
            return new gma_two_bands_p<int16_t,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_UInt32: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<uint32_t,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<uint32_t,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<uint32_t,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<uint32_t,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<uint32_t,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<uint32_t,float>;
        case GDT_Float64:
            return new gma_two_bands_p<uint32_t,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_Int32: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<int32_t,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<int32_t,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<int32_t,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<int32_t,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<int32_t,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<int32_t,float>;
        case GDT_Float64:
            return new gma_two_bands_p<int32_t,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_Float32: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<float,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<float,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<float,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<float,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<float,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<float,float>;
        case GDT_Float64:
            return new gma_two_bands_p<float,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    case GDT_Float64: {
        switch (type2) {
        case GDT_Byte:
            return new gma_two_bands_p<double,uint8_t>;
        case GDT_UInt16:
            return new gma_two_bands_p<double,uint16_t>;
        case GDT_Int16:
            return new gma_two_bands_p<double,int16_t>;
        case GDT_UInt32:
            return new gma_two_bands_p<double,uint32_t>;
        case GDT_Int32:
            return new gma_two_bands_p<double,int32_t>;
        case GDT_Float32:
            return new gma_two_bands_p<double,float>;
        case GDT_Float64:
            return new gma_two_bands_p<double,double>;
        default:
            // fixme: call error
            return NULL;
        }
    }
    default:
        // fixme: call error
        return NULL;
    }
}
