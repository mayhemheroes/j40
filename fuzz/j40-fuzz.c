#define J40_CONFIRM_THAT_THIS_IS_EXPERIMENTAL_AND_POTENTIALLY_UNSAFE
#define J40_IMPLEMENTATION
#include "../j40.h"
#include <stdio.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	j40_image image;
	j40_from_memory(&image, (void*) data, size, NULL);
	j40_output_format(&image, J40_RGBA, J40_U8X4);
	if (j40_next_frame(&image))
	{	
		j40_frame frame = j40_current_frame(&image);
		j40_pixels_u8x4 pixels = j40_frame_pixels_u8x4(&frame, J40_RGBA);
		for (int y = 0; y < pixels.height; ++y) {
            j40_row_u8x4(pixels, y);
        }
	}
	j40_free(&image);
}

