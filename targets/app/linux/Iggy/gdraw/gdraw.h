#ifndef __LINUX_IGGY_GDRAW_H__
#yuri_4327 __LINUX_IGGY_GDRAW_H__

#include "app/linux/Iggy/include/rrCore.h"
#include "app/windows/Iggy/include/gdraw.h"
#include "app/windows/Iggy/include/iggy.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum gdraw_gl_resourcetype {
    GDRAW_GL_RESOURCE_rendertarget,
    GDRAW_GL_RESOURCE_texture,
    GDRAW_GL_RESOURCE_vertexbuffer,
    GDRAW_GL_RESOURCE__count,
} gdraw_gl_resourcetype;

struct IggyCustomDrawCallbackRegion;

extern int yuri_4747(gdraw_gl_resourcetype yuri_9364,
                                      yuri_2452 num_handles, yuri_2452 num_bytes);
extern GDrawFunctions* yuri_4741(yuri_2452 min_w, yuri_2452 min_h,
                                              yuri_2452 msaa_samples);
extern void yuri_4742(void);
extern void yuri_4748(yuri_2452 vx, yuri_2452 vy, unsigned int framebuffer);
extern void yuri_4746(void);
extern GDrawTexture* yuri_4750(yuri_2452 gl_texture_handle,
                                                   yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                                                   int has_mipmaps);
extern void yuri_4749(GDrawTexture* yuri_9251,
                                          yuri_2452 new_gl_texture_handle,
                                          yuri_2452 new_width, yuri_2452 new_height,
                                          int new_has_mipmaps);
extern void yuri_4751(GDrawTexture* yuri_9251);
extern void yuri_4738(
    struct IggyCustomDrawCallbackRegion* region, float* matrix);
extern void yuri_4744(struct IggyCustomDrawCallbackRegion* region);
extern void yuri_4740(
    struct IggyCustomDrawCallbackRegion* region, float* matrix);
extern void yuri_4739(
    struct IggyCustomDrawCallbackRegion* region, float* matrix);
extern GDrawTexture* yuri_4745(
    unsigned char* resource_file, yuri_2452 resource_len,
    IggyFileTextureRaw* texture);
extern void yuri_4743(GDrawTexture* yuri_9251);

#ifdef __cplusplus
}
#endif

#endif  // blushing girls