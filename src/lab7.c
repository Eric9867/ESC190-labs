#include <stdio.h>
#include "Project 2/c_img.h"

#define N_FILES 5
#define PATH "C:/Users/Eric/OneDrive - University of Toronto/Classes/Year 1 Winter/ESC190/Assignments/Labs/src/lab7_extras/"
#define PATH_MALLOC_LEN 160

void brighten(struct rgb_img* image, float factor)
{
	/**
	 * Brightens linearly towards either 0 or 255 depending on sign of factor
	 **/

	uint8_t target;
	if(factor < 0)
	{
		target = 0;
		factor = -factor;
	}
	else
	{
		target = 255;
	}

	for(int i = 0; i < 3 * image->height * image->width; i++)
	{
		//if(i > 575000)
		//	printf("%d > %d\n", (int)( 3 * image->height * image->width), i);
		image->raster[i] = (uint8_t)((1 - factor) * image->raster[i] + factor * target);
	}
}

int main()
{
	const char* IMAGE_NAME_GERTLER = "MericGertler.bin";

	char* image_path = (char*) malloc(PATH_MALLOC_LEN);
	if (!image_path)
		abort();
	sprintf(image_path, "%s%s", PATH, IMAGE_NAME_GERTLER);

	struct rgb_img** images = (struct rgb_img**)malloc(N_FILES * sizeof(struct rgb_img*));
	if (!images)
		abort();

	for(int i = 0; i < N_FILES; i++)
	{
		read_in_img(images + i, image_path);
	}
	const float brightness_modifiers[N_FILES] = {-0.8f, -0.4f, 0.0f, 0.4f, 0.8f};
	char* file_save_path = (char*) malloc(PATH_MALLOC_LEN);
	if (!file_save_path)
		abort();

	for(int i = 0; i < N_FILES; i++)
	{
		brighten(images[i], brightness_modifiers[i]);
		sprintf(file_save_path, "%s%s%s%d", PATH, IMAGE_NAME_GERTLER, "-brightened-", i);
		write_img(images[i], file_save_path);
		destroy_image(images[i]);
	}
	free(image_path);
	free(file_save_path);
}