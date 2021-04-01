#include <math.h>
#include "seamcarving.h"
#include "c_img.h"

/**
 * Note:
 * 	rgb_img raster pixels are stored as one continuous array
 *		y is given by i / width
 *		x is given by i % width
 * 	where i represents each pixel
 * 	color sub-pixel channels are accessed 
 * 	by indexing in the following way:
 * 		raster[3*i + color], where color = 0, 1, 2 (for r, g, b)
 **/

///////////////////////////////////////////
// Part 1: Dual-Gradient Energy Function //
///////////////////////////////////////////

/**
 * TODO: change pixel energy to take a single index value, rather than x and y
 **/

#define RED 0
#define GREEN 1
#define BLUE 2

static double pixel_energy(const struct rgb_img *im, int i)
{
	int rx, ry, gx, gy, bx, by;
	int width = im->width;
	int height = im->height;
	// NOTE: can also allow the index to increment to the next row (reduces the number of checks)
	/* set the adjacent pixel coordinates, wrapping around to the other
	side of the image if the coordinate is outside of the allowed range */
	int x_1 = i - 1;
	if(i % width == 0)
		x_1 += width;
	int x_2 = i + 1;
	if(x_2 % width == 0)
		x_2 -= width;
	int y_1 = i - width;
	if(y_1 < 0)
		y_1 += width * height;
	int y_2 = i + width;
	if(y_2 >= width * height)
		y_2 -= width * height;

	rx = im->raster[3 * x_2 + RED] - im->raster[3 * x_1 + RED];
	gx = im->raster[3 * x_2 + GREEN] - im->raster[3 * x_1 + GREEN];
	bx = im->raster[3 * x_2 + BLUE] - im->raster[3 * x_1 + BLUE];
	ry = im->raster[3 * y_2 + RED] - im->raster[3 * y_1 + RED];
	gy = im->raster[3 * y_2 + GREEN] - im->raster[3 * y_1 + GREEN];
	by = im->raster[3 * y_2 + BLUE] - im->raster[3 * y_1 + BLUE];

	// TODO: convert function to use integers and return without performing square root
	return sqrt(rx*rx + ry*ry + gx*gx + gy*gy + bx*bx + by*by); // is it even necessary to square-root
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad)
{
	*grad = (struct rgb_img*) malloc(sizeof(struct rgb_img));
	(*grad)->raster = (uint8_t*) malloc(sizeof(uint8_t) * im->width * im->height);
	(*grad)->width = im->width;
	(*grad)->height = im->height;
	for(int i = 0; i < (*grad)->height * (*grad)->width; i++)
	{
		(*grad)->raster[i] = (uint8_t) (0.1 * pixel_energy(im, i));
	}
}

////////////////////////
// Part 2: Cost Array //
////////////////////////

void dynamic_seam(struct rgb_img *grad, double **best_arr)
{
	double* partial_seam_energy = (double*) malloc(sizeof(double) * grad->width * grad->height);
	// NOTE
	// x = i % width;
	// y = i / width;
	int width = grad->width;
	int height = grad->height;

	// CASE 1: first row of tiles: seam energy == tile energy
	int i = 0;
	for(; i < width ; i++)
	{
		partial_seam_energy[i] = grad->raster[i];
	}

	int min_prev_seam;
	for(; i < width * height; i++)
	{
		// CASE 2: first column of tiles (no left ) 
		if(i % width == 0)
		{
			// set the tile seam energy to the smaller of the above seam energies + the tile energy
			partial_seam_energy[i] = 
				partial_seam_energy[i - width] <= partial_seam_energy[i - width + 1] ? 
				grad->raster[i] + partial_seam_energy[i - width] :
				grad->raster[i] + partial_seam_energy[i - width + 1];
			continue;
		}

		// CASE 3: last column of tiles (no right)
		if((i+1) % width == 0)
		{
			partial_seam_energy[i] = 
				partial_seam_energy[i - width - 1] <= partial_seam_energy[i - width] ? 
				grad->raster[i] + partial_seam_energy[i - width - 1] :
				grad->raster[i] + partial_seam_energy[i - width];
			continue;
		}

		// CASE 4: any other column (all three tiles above are valid comparisons)
		min_prev_seam = partial_seam_energy[i - width - 1];
		if(min_prev_seam < partial_seam_energy[i - width])
			min_prev_seam = partial_seam_energy[i - width];
		if(min_prev_seam < partial_seam_energy[i - width + 1])
			min_prev_seam = partial_seam_energy[i - width + 1];

		partial_seam_energy[i] = grad->raster[i] + min_prev_seam;

	}

	*best_arr = partial_seam_energy;
}

void recover_path(double *best, int height, int width, int **path);
void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path);


int main(void)
{
	struct rgb_img* image;
	struct rgb_img* grad;
	read_in_img(&image, "3x4.bin");
	calc_energy(image, &grad);
	print_grad(grad);

	destroy_image(image);
	free(grad);
}