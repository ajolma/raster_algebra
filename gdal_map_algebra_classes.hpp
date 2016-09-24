#ifndef GDAL_MAP_ALGEBRA_CLASSES
#define GDAL_MAP_ALGEBRA_CLASSES

#include "gdal_map_algebra_core.h"
#include "gdal.h"
#include "gdal_priv.h"
#include <vector>

/*
  Interface classes for argument and return value objects.
  It is legal to cast gma_object_t* to the subclass
  get_class() reports.
*/

class gma_object_t {
public:
    virtual ~gma_object_t() {};
    virtual gma_class_t get_class() {return gma_object;};
    // x and y are cell coordinates
    // these are really not needed in the public interface...??
    virtual void get_value(uint8_t *value, int x = 0, int y = 0) {return;};
    virtual void get_value(uint16_t *value, int x = 0, int y = 0) {return;};
    virtual void get_value(uint32_t *value, int x = 0, int y = 0) {return;};
    virtual void get_value(int16_t *value, int x = 0, int y =  0) {return;};
    virtual void get_value(int32_t *value, int x = 0, int y = 0) {return;};
    virtual void get_value(float *value, int x = 0, int y = 0) {return;};
    virtual void get_value(double *value, int x = 0, int y = 0) {return;};
    virtual gma_object_t *get_subnode(int i) {return NULL;}; // binary tree, i should be 0 or 1
    virtual void book_blocks(int x_min, int y_min, int x_max, int y_max) {
        for (int i = 0; i < 2; ++i) {
            gma_object_t *n = get_subnode(i);
            if (n) n->book_blocks(x_min, y_min, x_max, y_max);
        }
    };
    virtual void unbook_blocks(int x_min, int y_min, int x_max, int y_max) {
        for (int i = 0; i < 2; ++i) {
            gma_object_t *n = get_subnode(i);
            if (n) n->unbook_blocks(x_min, y_min, x_max, y_max);
        }
    };
};

class gma_operand_t : public gma_object_t {
};

class gma_operator_t : public gma_object_t {
protected:
    gma_operand_t *arg1, *arg2;
public:
    gma_operator_t();
    virtual void set_operand(gma_operand_t *op);
    virtual gma_object_t *get_subnode(int i) {
        if (i == 0)
            return arg1;
        else
            return arg2;
    };
};

class gma_operator_sum_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_difference_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_product_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_quotient_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_remainder_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_eq_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_ne_t : public gma_operator_t {
public:
    gma_operator_ne_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_gt_t : public gma_operator_t {
public:
    gma_operator_gt_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_lt_t : public gma_operator_t {
public:
    gma_operator_lt_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_ge_t : public gma_operator_t {
public:
    gma_operator_ge_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_le_t : public gma_operator_t {
public:
    gma_operator_le_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_and_t : public gma_operator_t {
public:
    gma_operator_and_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_or_t : public gma_operator_t {
public:
    gma_operator_or_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_operator_not_t : public gma_operator_t {
public:
    gma_operator_not_t();
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_rand_t : public gma_operand_t {
    int m_max;
public:
    gma_function_rand_t(int max);
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_abs_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_exp_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_log_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_log10_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_sqrt_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_sin_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_cos_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_tan_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_ceil_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_function_floor_t : public gma_operator_t {
public:
    virtual void get_value(uint8_t *value, int x, int y);
    virtual void get_value(uint16_t *value, int x, int y);
    virtual void get_value(uint32_t *value, int x, int y);
    virtual void get_value(int16_t *value, int x, int y);
    virtual void get_value(int32_t *value, int x, int y);
    virtual void get_value(float *value, int x, int y);
    virtual void get_value(double *value, int x, int y);
};

class gma_number_t : public gma_operand_t {
public:
    virtual gma_class_t get_class() {return gma_number;};
    virtual GDALDataType datatype() = 0;
    virtual void set_value(double value) = 0;
    virtual void set_value(int value) = 0;
    virtual bool is_defined() = 0;
    virtual void set_inf(int inf) = 0; // -1 to minus inf, 0 to not inf, 1 to plus inf
    virtual bool is_inf() = 0;
    virtual bool is_integer() = 0;
    virtual bool is_unsigned() = 0;
    virtual bool is_float() = 0;
};

class gma_pair_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_pair;};
    virtual void set_first(gma_object_t *first) = 0;
    virtual void set_second(gma_object_t *second) = 0;    
    virtual gma_object_t *first() = 0;
    virtual gma_object_t *second() = 0;
};

class gma_bins_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_bins;};
    virtual GDALDataType datatype() = 0;
    virtual unsigned int size()= 0;
    virtual void push(int value) = 0;
    virtual void push(double value) = 0;
};

class gma_histogram_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_histogram;};
    virtual GDALDataType datatype() = 0;
    virtual unsigned int size()= 0;
    virtual gma_object_t *at(unsigned int i) = 0;
    virtual void print() = 0;
};

class gma_classifier_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_classifier;};
    virtual GDALDataType datatype() = 0;
    virtual void add_class(gma_number_t *interval_max, gma_number_t *value) = 0;
    virtual void add_value(gma_number_t *old_value, gma_number_t *new_value) = 0;
    virtual void add_default(gma_number_t *default_value) = 0;
};

class gma_cell_t  : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_cell;};
    virtual GDALDataType datatype() = 0;
    virtual int x()= 0;
    virtual int y()= 0;
    virtual void set_x(int) = 0;
    virtual void set_y(int) = 0;
    virtual void set_value(double value) = 0;
    virtual void set_value(int value) = 0;
    virtual int value_as_int()= 0;
    virtual double value_as_double()= 0;
};

/*
  Return value 0 interrupts, 1 denotes ok, and 2 denotes ok and a need
  to save the cell value back to band.
*/
typedef int (*gma_cell_callback_f)(gma_cell_t*, gma_object_t*);

class gma_cell_callback_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_cell_callback;};
    virtual void set_callback(gma_cell_callback_f callback) = 0;
    virtual void set_user_data(gma_object_t*) = 0;
};

class gma_hash_t : public gma_object_t {
public:
    virtual gma_class_t get_class() {return gma_hash;};
    virtual GDALDataType datatype() = 0;
    virtual int size()= 0;
    virtual std::vector<gma_number_t*> keys_sorted() = 0;
    virtual gma_object_t *get(gma_number_t *key) = 0;
};

class gma_band_t : public gma_operand_t {
public:
    virtual gma_class_t get_class() {return gma_band;};
    virtual void update() = 0;
    virtual GDALRasterBand *band() = 0;
    virtual GDALDataset *dataset() = 0;
    virtual GDALDriver *driver() = 0;
    virtual GDALDataType datatype() = 0;
    virtual bool datatype_is_integer() = 0;
    virtual bool datatype_is_float() = 0;
    virtual int w()= 0;
    virtual int h()= 0;

    virtual void set_progress_fct(GDALProgressFunc progress, void * progress_arg) = 0;

    virtual gma_band_t *new_band(const char *name, GDALDataType datatype) = 0;
    virtual gma_number_t *new_number() = 0;
    virtual gma_number_t *new_int(int value) = 0;
    virtual gma_pair_t *new_pair() = 0;
    virtual gma_pair_t *new_range() = 0;
    virtual gma_bins_t *new_bins() = 0;
    virtual gma_cell_t *new_cell() = 0;
    virtual gma_classifier_t *new_classifier() = 0;
    virtual gma_cell_callback_t *new_cell_callback() = 0;

    virtual void compute(gma_object_t*) = 0;

    virtual void print() = 0;
    virtual void classify(gma_classifier_t*) = 0;
    virtual void cell_callback(gma_cell_callback_t*) = 0;

    // arg = NULL, pair:(n,pair:(min,max)), or bins; returns histogram
    virtual gma_histogram_t *histogram() = 0;
    virtual gma_histogram_t *histogram(gma_pair_t *arg) = 0;
    virtual gma_histogram_t *histogram(gma_bins_t *arg) = 0;
    // returns hash of a hashes, keys are zone numbers
    virtual gma_hash_t *zonal_neighbors() = 0;
    virtual gma_number_t *get_min() = 0;
    virtual gma_number_t *get_max() = 0;
    // returns a pair of numbers
    virtual gma_pair_t *get_range() = 0;
    virtual std::vector<gma_cell_t*> cells() = 0;

    // this = value where decision is true
    // the decision band must be of type uint8_t
    virtual void decision(gma_band_t *value, gma_band_t *decision) = 0;

    virtual gma_hash_t *zonal_min(gma_band_t *zones) = 0;
    virtual gma_hash_t *zonal_max(gma_band_t *zones) = 0;

    virtual void rim_by8(gma_band_t *areas) = 0;

    virtual void fill_depressions(gma_band_t *dem) = 0;
    virtual void D8(gma_band_t *dem) = 0;
    virtual void route_flats(gma_band_t *dem) = 0;
    virtual void upstream_area(gma_band_t *) = 0;
    virtual void catchment(gma_band_t *, gma_cell_t *) = 0;

};

#endif
