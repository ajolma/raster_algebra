#include "gdal_map_algebra.hpp"

int main() {

    GDALAllRegister();
    srand(time(NULL));
    GDALDriver *d = GetGDALDriverManager()->GetDriverByName("MEM");
    int w_band = 16, h_band = 10;
    GDALDataset *ds = d->Create("", w_band, h_band, 2, GDT_Byte, NULL);
    GDALRasterBand *b = ds->GetRasterBand(1);

    gma_band_t *bx = gma_new_band(b);
    {
        gma_operator_remainder_t *t = new gma_operator_remainder_t();
        gma_function_rand_t *t2 = new gma_function_rand_t(40);
        t->set_operand(t2);
        gma_number_t *a = bx->new_number();
        a->set_value(20);
        t->set_operand(a);
        bx->compute(t);
    }
    bx->print();
    printf("\n");

    {
        gma_operator_sum_t *t = new gma_operator_sum_t();
        t->set_operand(bx);
        gma_number_t *a = bx->new_number();
        a->set_value(5);
        t->set_operand(a);
        bx->compute(t);
    }
    bx->print();
    printf("\n");
    

    GDALRasterBand *b2 = ds->GetRasterBand(2);

    gma_band_t *by = gma_new_band(b2);
    {
        gma_function_rand_t *t2 = new gma_function_rand_t(10);
        by->compute(t2);
    }
    by->print();
    printf("\n");

    {
        gma_operator_sum_t *t = new gma_operator_sum_t();
        t->set_operand(bx);
        t->set_operand(by);
        bx->compute(t);
    }
    bx->print();
    printf("\n");

    {
        gma_operator_sum_t *t = new gma_operator_sum_t();
        t->set_operand(by);
        gma_number_t *a = by->new_number();
        a->set_value(250);
        t->set_operand(a);
        by->compute(t);
    }
    by->print();
    printf("\n");

    gma_histogram_t *hm = bx->histogram();

    hm->print();

    gma_pair_t *r = bx->get_range();
    gma_number_t *min = (gma_number_t*)r->first();
    gma_number_t *max = (gma_number_t*)r->second();
    int min2, max2;
    min->get_value(&min2);
    max->get_value(&max2);
    printf("[%i..%i]\n", min2, max2);

    gma_pair_t *arg = bx->new_pair();

    gma_number_t *tmp = bx->new_number();
    tmp->set_value(5);
    arg->set_first(tmp);
    arg->set_second(r);

    hm = bx->histogram(arg);
    hm->print();
}
