/********
 * Kernels to be optimized for the CS:APP Performance Lab
 ********/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following team_t struct
 */
team_t team = {
        "",    /* Team Name */
        "",    /* First student ID */
        "",    /* First student name */
        
        "",        /* Second student ID */
        ""         /* Second student name */

};


/*******
 * BATCHED MATRIX MULTIPLICATION \W SUM REDUCTION KERNEL
 *******/

/*********
 * Your different versions of the batched matrix multiplication functions go here
 *********/

/*
 * naive_batched_mm - The naive baseline version of batched matrix multiplication
 */
char naive_batched_mm_descr[] = "naive_batched_mm: Naive baseline implementation";
void naive_batched_mm(int dim, int *b_mat, int *mat, int *dst) {
    int i,j,k,l;
    
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            for (k = 0; k < dim; k++) {
            	if (i == 0){
            	    dst[RIDX(j, k, dim)] = 0;
            	}
            	for (l = 0; l < dim; l++){
                    dst[RIDX(j, k, dim)] += b_mat[RIDX(i*dim+j, l, dim)] * mat[RIDX(l, k, dim)];
                }
            }
        }
    }
    
}



/*
 * batched_mm - Your current working version of batched matrix multiplication
 * IMPORTANT: This is the version you will be graded on
 */
char batched_mm_descr[] = "Batched MM with sum reduction: Current working version";
void batched_mm(int dim, int *b_mat, int *mat, int *dst)
{

    int i,j,k,nj,ni,sum = 0,size;
    int tmp[dim * dim];
    int tmp2[dim * dim];
    size = dim * dim;
    for (i = 0; i < size; i+=4) {
        dst[i] = 0;
        dst[i + 1] = 0;
        dst[i + 2] = 0;
        dst[i + 3] = 0;
        
        tmp[i] = 0;
        tmp[i + 1] = 0;
        tmp[i + 2] = 0;
        tmp[i + 3] = 0;

        
    }
    ni = 0;
    for (i = 0; i < dim; i++) {
        nj = 0;
        for (j = 0; j < dim; j++) {
            for (k = 0; k < dim; k += 32) { 
            	dst[nj + k] += b_mat[ni + nj + k];
                dst[nj + k + 1] += b_mat[ni + nj + k + 1];
                dst[nj + k + 2] += b_mat[ni + nj + k + 2];
                dst[nj + k + 3] += b_mat[ni + nj + k + 3];
                dst[nj + k + 4] += b_mat[ni + nj + k + 4];
                dst[nj + k + 5] += b_mat[ni + nj + k + 5];
                dst[nj + k + 6] += b_mat[ni + nj + k + 6];
                dst[nj + k + 7] += b_mat[ni + nj + k + 7];
                dst[nj + k + 8] += b_mat[ni + nj + k + 8];
                dst[nj + k + 9] += b_mat[ni + nj + k + 9];
                dst[nj + k + 10] += b_mat[ni + nj + k + 10];
                dst[nj + k + 11] += b_mat[ni + nj + k + 11];
                dst[nj + k + 12] += b_mat[ni + nj + k + 12];
                dst[nj + k + 13] += b_mat[ni + nj + k + 13];
                dst[nj + k + 14] += b_mat[ni + nj + k + 14];
                dst[nj + k + 15] += b_mat[ni + nj + k + 15];
                dst[nj + k + 16] += b_mat[ni + nj + k + 16];
                dst[nj + k + 17] += b_mat[ni + nj + k + 17];
                dst[nj + k + 18] += b_mat[ni + nj + k + 18];
                dst[nj + k + 19] += b_mat[ni + nj + k + 19];
                dst[nj + k + 20] += b_mat[ni + nj + k + 20];
                dst[nj + k + 21] += b_mat[ni + nj + k + 21];
                dst[nj + k + 22] += b_mat[ni + nj + k + 22];
                dst[nj + k + 23] += b_mat[ni + nj + k + 23];
                dst[nj + k + 24] += b_mat[ni + nj + k + 24];
                dst[nj + k + 25] += b_mat[ni + nj + k + 25];
                dst[nj + k + 26] += b_mat[ni + nj + k + 26];
                dst[nj + k + 27] += b_mat[ni + nj + k + 27];
                dst[nj + k + 28] += b_mat[ni + nj + k + 28];
                dst[nj + k + 29] += b_mat[ni + nj + k + 29];
                dst[nj + k + 30] += b_mat[ni + nj + k + 30];
                dst[nj + k + 31] += b_mat[ni + nj + k + 31];
            }
            nj += dim;
        }
        ni += size;
    }
    ni = 0;
    for (i = 0; i < dim; i++){
        nj = 0; 
        for (j = 0; j < dim; j++){
            tmp2[ni + j] = mat[nj + i];
            nj += dim;
        }
        ni += dim;
    }
    ni = 0;
    for (i = 0; i < dim; i++) {
        nj = 0;
        for (j = 0; j < dim; j++) {
            sum = 0;
            for (k = 0; k < dim; k+=32){
            	sum += dst[ni + k] * tmp2[nj + k];
                sum += dst[ni + k + 1] * tmp2[nj + k + 1];
                sum += dst[ni + k + 2] * tmp2[nj + k + 2];
                sum += dst[ni + k + 3] * tmp2[nj + k + 3];
                sum += dst[ni + k + 4] * tmp2[nj + k + 4];
                sum += dst[ni + k + 5] * tmp2[nj + k + 5];
                sum += dst[ni + k + 6] * tmp2[nj + k + 6];
                sum += dst[ni + k + 7] * tmp2[nj + k + 7];
                sum += dst[ni + k + 8] * tmp2[nj + k + 8];
                sum += dst[ni + k + 9] * tmp2[nj + k + 9];
                sum += dst[ni + k + 10] * tmp2[nj + k + 10];
                sum += dst[ni + k + 11] * tmp2[nj + k + 11];
                sum += dst[ni + k + 12] * tmp2[nj + k + 12];
                sum += dst[ni + k + 13] * tmp2[nj + k + 13];
                sum += dst[ni + k + 14] * tmp2[nj + k + 14];
                sum += dst[ni + k + 15] * tmp2[nj + k + 15];
                sum += dst[ni + k + 16] * tmp2[nj + k + 16];
                sum += dst[ni + k + 17] * tmp2[nj + k + 17];
                sum += dst[ni + k + 18] * tmp2[nj + k + 18];
                sum += dst[ni + k + 19] * tmp2[nj + k + 19];
                sum += dst[ni + k + 20] * tmp2[nj + k + 20];
                sum += dst[ni + k + 21] * tmp2[nj + k + 21];
                sum += dst[ni + k + 22] * tmp2[nj + k + 22];
                sum += dst[ni + k + 23] * tmp2[nj + k + 23];
                sum += dst[ni + k + 24] * tmp2[nj + k + 24];
                sum += dst[ni + k + 25] * tmp2[nj + k + 25];
                sum += dst[ni + k + 26] * tmp2[nj + k + 26];
                sum += dst[ni + k + 27] * tmp2[nj + k + 27];
                sum += dst[ni + k + 28] * tmp2[nj + k + 28];
                sum += dst[ni + k + 29] * tmp2[nj + k + 29];
                sum += dst[ni + k + 30] * tmp2[nj + k + 30];
                sum += dst[ni + k + 31] * tmp2[nj + k + 31];

            }
            tmp[ni + j] = sum;
            nj += dim;
        }
        ni += dim; 
    }
    for (i = 0; i < size; i += 32) {
        dst[i] = tmp[i];
        dst[i + 1] = tmp[i + 1];
        dst[i + 2] = tmp[i + 2];
        dst[i + 3] = tmp[i + 3];
        dst[i + 4] = tmp[i + 4];
        dst[i + 5] = tmp[i + 5];
        dst[i + 6] = tmp[i + 6];
        dst[i + 7] = tmp[i + 7];
        dst[i + 8] = tmp[i + 8];
        dst[i + 9] = tmp[i + 9];
        dst[i + 10] = tmp[i + 10];
        dst[i + 11] = tmp[i + 11];
        dst[i + 12] = tmp[i + 12];
        dst[i + 13] = tmp[i + 13];
        dst[i + 14] = tmp[i + 14];
        dst[i + 15] = tmp[i + 15];
        dst[i + 16] = tmp[i + 16];
        dst[i + 17] = tmp[i + 17];
        dst[i + 18] = tmp[i + 18];
        dst[i + 19] = tmp[i + 19];
        dst[i + 20] = tmp[i + 20];
        dst[i + 21] = tmp[i + 21];
        dst[i + 22] = tmp[i + 22];
        dst[i + 23] = tmp[i + 23];
        dst[i + 24] = tmp[i + 24];
        dst[i + 25] = tmp[i + 25];
        dst[i + 26] = tmp[i + 26];
        dst[i + 27] = tmp[i + 27];
        dst[i + 28] = tmp[i + 28];
        dst[i + 29] = tmp[i + 29];
        dst[i + 30] = tmp[i + 30];
        dst[i + 31] = tmp[i + 31];
    }

}


/*********
 * register_batched_mm_functions - Register all of your different versions
 *     of the batched matrix multiplication functions  with the driver by calling the
 *     add_batched_mm_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********/

void register_batched_mm_functions() {
    add_batched_mm_function(&naive_batched_mm, naive_batched_mm_descr);
    add_batched_mm_function(&batched_mm, batched_mm_descr);
    /* ... Register additional test functions here */
}




/****
 * POINT REFLECTION KERNEL
 ****/

/*******
 * Your different versions of the point reflection go here
 *******/

/*
 * naive_reflect - The naive baseline version of point reflection
 */
char naive_reflect_descr[] = "Naive Point Reflection: Naive baseline implementation";
void naive_reflect(int dim, int *src, int *dst) {
    int i, j;

    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            dst[RIDX(dim-1-i, dim-1-j, dim)] = src[RIDX(i, j, dim)];
        }
    }
}






/*
 * reflect - Your current working version of reflect
 * IMPORTANT: This is the version you will be graded on
 */
char reflect_descr[] = "Point Reflection: Current working version";
void reflect(int dim, int *src, int *dst)
{

    int i;
    int index = dim*dim;
    int size = index;
    for(i = 0; i < size;){
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];
        dst[--index] = src[i++];

    }

}

/**********
 * register_reflect_functions - Register all of your different versions
 *     of the reflect with the driver by calling the
 *     add_reflect_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 **********/

void register_reflect_functions() {
    add_reflect_function(&naive_reflect, naive_reflect_descr);
    add_reflect_function(&reflect, reflect_descr);
    /* ... Register additional test functions here */
}