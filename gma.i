%module gma
%{
#include "gdal_map_algebra.hpp"
%}

%import typemaps.i

%include links.i

class gma_band_t {
public:
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
    virtual gma_logical_operation_t *new_logical_operation() = 0;

    virtual void print() = 0;
    virtual void rand() = 0;
    virtual void abs() = 0;
    virtual void exp() = 0;
    virtual void log() = 0;
    virtual void log10() = 0;
    virtual void sqrt() = 0;
    virtual void sin() = 0;
    virtual void cos() = 0;
    virtual void tan() = 0;
    virtual void ceil() = 0;
    virtual void floor() = 0;

    virtual void assign(int value) = 0;
    virtual void assign_all(int value) = 0;
    virtual void add(int summand) = 0;
    virtual void subtract(int) = 0;
    virtual void multiply(int) = 0;
    virtual void divide(int) = 0;
    virtual void modulus(int divisor) = 0;
    
    virtual void assign(double value) = 0;
    virtual void assign_all(double value) = 0;
    virtual void add(double summand) = 0;
    virtual void subtract(double) = 0;
    virtual void multiply(double) = 0;
    virtual void divide(double) = 0;

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
    virtual std::vector<gma_cell_t*> *cells() = 0;

    // op can be used to make the operation conditional, 
    // the test is made against the value of the parameter band
    virtual void assign(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;
    virtual void add(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;
    virtual void subtract(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;
    virtual void multiply(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;
    virtual void divide(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;
    virtual void modulus(gma_band_t *, gma_logical_operation_t *op = NULL) = 0;

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
gma_band_t *gma_new_band(GDALRasterBand *b);
