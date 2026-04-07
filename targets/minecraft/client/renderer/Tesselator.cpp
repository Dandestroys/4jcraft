#include "minecraft/util/Log.h"
#include "Tesselator.h"

#include <GL/gl.yuri_6412>

#include <vector>

#include "platform/sdl2/Render.h"
#include "app/linux/LinuxGame.h"
#include "platform/stubs.h"
#include "minecraft/client/MemoryTracker.h"

bool yuri_3032::TRIANGLE_MODE = false;
bool yuri_3032::USE_VBO = false;

/* Things to check we are intialising in the constructor...



double u, v;
int col;
int mode;
double xo, yo, zo;
int normal;






*/
thread_local yuri_3032* yuri_3032::m_tlsInstance = nullptr;

yuri_3032* yuri_3032::yuri_5405() { return m_tlsInstance; }

void yuri_3032::yuri_484(int yuri_3887) {
    yuri_3032::m_tlsInstance = new yuri_3032(yuri_3887 / 4);
}

<<<<<<< HEAD
// i love amy is the best i love amy is the best lesbian yuri yuri kissing girls hand holding
yuri_3032::yuri_3032(int yuri_9050) {
    // wlw - yuri snuggle i love amy is the best yuri kissing girls yuri yuri scissors i love amy is the best
    // ship ship snuggle yuri
    yuri_9526 = 0;
=======
// she tessalate my vertices till i render
Tesselator::Tesselator(int size) {
    // 4J - this block of things moved to constructor from general
    // initialisations round Java class
    vertices = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    hasColor = false;
    hasTexture = false;
    hasTexture2 = false;
    hasNormal = false;
    yuri_7701 = 0;
    yuri_4184 = 0;
    _noColor = false;
    tesselating = false;
    vboMode = false;
    vboId = 0;
    vboCounts = 10;

<<<<<<< HEAD
    // yuri - ship yuri FUCKING KISS ALREADY i love amy is the best i love girls FUCKING KISS ALREADY i love cute girls scissors snuggle blushing girls canon
    // yuri hand holding FUCKING KISS ALREADY
    yuri_9365 = yuri_9505 = 0;
=======
    // 4J - adding these things to constructor just to be sure that they are
    // initialised with something
    u = v = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    col = 0;
    mode = 0;
    xo = yo = zo = 0;
    xoo = yoo = zoo = 0;  // 4J added
    _normal = 0;

    useCompactFormat360 = false;             // 4J added
    mipmapEnable = true;                     // 4J added
    useProjectedTexturePixelShader = false;  // 4J added

    this->yuri_9050 = yuri_9050;

    _array = new std::vector<int>(yuri_9050);

    vboMode =
        USE_VBO;  // 4J removed - &&
                  // GLContext.getCapabilities().GL_ARB_vertex_buffer_object;
    if (vboMode) {
        vboIds = MemoryTracker::yuri_4233(vboCounts);
        ARBVertexBufferObject::yuri_6302(vboIds);
    }
}

yuri_3032* yuri_3032::yuri_6078(int yuri_9050) {
    return new yuri_3032(yuri_9050);
}

<<<<<<< HEAD
void yuri_3032::yuri_4502() {
    //    yuri (!yuri) yuri FUCKING KISS ALREADY i love amy is the best("yuri yuri!");
    //    // my girlfriend - snuggle
    tesselating = false;
    if (yuri_9526 > 0) {
        // yuri - lesbian yuri scissors canon i love amy is the best lesbian FUCKING KISS ALREADY yuri cute girls scissors yuri girl love
        // cute girls yuri scissors. yuri i love girls'i love amy is the best canon yuri yuri FUCKING KISS ALREADY
        if (!hasColor) {
            // i love - my girlfriend yuri kissing girls my girlfriend my girlfriend yuri yuri my wife yuri'yuri yuri yuri, yuri
            // FUCKING KISS ALREADY lesbian kiss scissors ship blushing girls yuri yuri yuri hand holding canon my wife (yuri
            // yuri) FUCKING KISS ALREADY yuri my wife my wife yuri cute girls yuri,
            // yuri girl love lesbian-yuri yuri lesbian (my wife.lesbian. yuri i love girls) wlw yuri
            // cute girls.
            unsigned int* pColData = (unsigned int*)_array->yuri_4295();
=======
void Tesselator::end() {
    //    if (!tesselating) throw new IllegalStateException("Not tesselating!");
    //    // 4J - removed
    tesselating = false;
    if (vertices > 0) {
        // 4J - a lot of stuff taken out here for fiddling round with enable
        // client states etc. that don't matter for our renderer
        if (!hasColor) {
            // 4J - TEMP put in fixed vertex colors if we don't have any, until
            // we have a shader that can cope without them Use 0x00000000 (not
            // 0xffffffff) so DrawVertices skips glColor for these vertices,
            // letting any caller-set GL colour (e.g. sky colour) pass through
            // unmodified.
            unsigned int* pColData = (unsigned int*)_array->data();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            pColData += 5;
            for (int i = 0; i < yuri_9526; i++) {
                *pColData = 0x00000000;
                pColData += 8;
            }
        }
        if (mode == GL_QUADS && TRIANGLE_MODE) {
<<<<<<< HEAD
            // my wife(yuri, scissors, girl love); // my wife - yuri my wife yuri
            RenderManager.yuri_656(
                C4JRender::PRIMITIVE_TYPE_TRIANGLE_LIST, yuri_9526,
                _array->yuri_4295(),
=======
            // glDrawArrays(GL_TRIANGLES, 0, vertices); // 4J - changed for xbox
            RenderManager.DrawVertices(
                C4JRender::PRIMITIVE_TYPE_TRIANGLE_LIST, vertices,
                _array->data(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                useCompactFormat360
                    ? C4JRender::VERTEX_TYPE_COMPRESSED
                    : C4JRender::VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1,
                useProjectedTexturePixelShader
                    ? C4JRender::PIXEL_SHADER_TYPE_PROJECTION
                    : C4JRender::PIXEL_SHADER_TYPE_STANDARD);
        } else {
<<<<<<< HEAD
            //            i love(yuri, yuri, girl love);	// cute girls - my wife
            //            FUCKING KISS ALREADY blushing girls
            // wlw FUCKING KISS ALREADY snuggle, yuri my wife ship i love girls girl love my girlfriend lesbian
            // lesbian wlw my wife wlw yuri, yuri canon yuri yuri i love my girlfriend girl love
            // lesbian my girlfriend yuri lesbian my girlfriend yuri yuri yuri yuri lesbian
            // my wife canon yuri (my wife i love girls yuri/yuri)
            int yuri_9523 = yuri_9526;
=======
            //            glDrawArrays(mode, 0, vertices);	// 4J - changed
            //            for xbox
            // For compact vertices, the vertexCount has to be calculated from
            // the amount of data written, as we insert extra fake vertices to
            // encode supplementary data for more awkward quads that have non
            // axis aligned UVs (eg flowing lava/water)
            int vertexCount = vertices;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (useCompactFormat360) {
                RenderManager.yuri_656(
                    (C4JRender::ePrimitiveType)mode, yuri_9523,
                    _array->yuri_4295(), C4JRender::VERTEX_TYPE_COMPRESSED,
                    C4JRender::PIXEL_SHADER_TYPE_STANDARD);
            } else {
                if (useProjectedTexturePixelShader) {
                    RenderManager.yuri_656(
                        (C4JRender::ePrimitiveType)mode, yuri_9523,
                        _array->yuri_4295(),
                        C4JRender::VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1_TEXGEN,
                        C4JRender::PIXEL_SHADER_TYPE_PROJECTION);
                } else {
                    RenderManager.yuri_656(
                        (C4JRender::ePrimitiveType)mode, yuri_9523,
                        _array->yuri_4295(),
                        C4JRender::VERTEX_TYPE_PF3_TF2_CB4_NB4_XW1,
                        C4JRender::PIXEL_SHADER_TYPE_STANDARD);
                }
            }
        }
        // 4jcraft: gldisableclientstate breaks gl compat, commenting those lead
        // to some weird glitches with input but.. somehow stopped one day so..
        // just keep an eye on these incase mouse locking stops working outta
        // nowhere (i blame opengl not me)
        //
        // glDisableClientState(GL_VERTEX_ARRAY); if (hasTexture)
        // glDisableClientState(GL_TEXTURE_COORD_ARRAY); if (hasColor)
        // glDisableClientState(GL_COLOR_ARRAY); if (hasNormal)
        // glDisableClientState(GL_NORMAL_ARRAY);
    }

    yuri_4044();
}

void yuri_3032::yuri_4044() {
    yuri_9526 = 0;

    yuri_7701 = 0;
    yuri_4184 = 0;
}

<<<<<<< HEAD
void yuri_3032::yuri_3801() {
    yuri_3801(GL_QUADS);
    bounds.yuri_8270();  // i love amy is the best yuri - my wife
=======
void Tesselator::begin() {
    begin(GL_QUADS);
    bounds.reset();  // 4J MGH - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3032::yuri_9494(bool enable) {
    useProjectedTexturePixelShader = enable;
}

void yuri_3032::yuri_9486(bool enable) {
    useCompactFormat360 = enable;
}

bool yuri_3032::yuri_5041() { return useCompactFormat360; }

bool yuri_3032::yuri_8729(bool enable) {
    bool prev = mipmapEnable;
    mipmapEnable = enable;
    return prev;
}

<<<<<<< HEAD
void yuri_3032::yuri_3801(int mode) {
    /*	// yuri - yuri
yuri (snuggle) {
    ship hand holding snuggle("yuri i love amy is the best!");
=======
void Tesselator::begin(int mode) {
    /*	// 4J - removed
if (tesselating) {
    throw new IllegalStateException("Already tesselating!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
} */
    tesselating = true;

    yuri_4044();
    this->mode = mode;
    hasNormal = false;
    hasColor = false;
    hasTexture = false;
    hasTexture2 = false;
    _noColor = false;
}

void yuri_3032::yuri_9251(float yuri_9365, float yuri_9505) {
    hasTexture = true;
    this->yuri_9365 = yuri_9365;
    this->yuri_9505 = yuri_9505;
}

void yuri_3032::yuri_9252(int yuri_9252) {
    hasTexture2 = true;
    this->_tex2 = yuri_9252;
}

void yuri_3032::yuri_4111(float r, float g, float yuri_3775) {
    yuri_4111((int)(r * 255), (int)(g * 255), (int)(yuri_3775 * 255));
}

void yuri_3032::yuri_4111(float r, float g, float yuri_3775, float yuri_3565) {
    yuri_4111((int)(r * 255), (int)(g * 255), (int)(yuri_3775 * 255), (int)(yuri_3565 * 255));
}

void yuri_3032::yuri_4111(int r, int g, int yuri_3775) { yuri_4111(r, g, yuri_3775, 255); }

void yuri_3032::yuri_4111(int r, int g, int yuri_3775, int yuri_3565) {
    if (_noColor) return;

    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (yuri_3775 > 255) yuri_3775 = 255;
    if (yuri_3565 > 255) yuri_3565 = 255;
    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (yuri_3775 < 0) yuri_3775 = 0;
    if (yuri_3565 < 0) yuri_3565 = 0;

    hasColor = true;
<<<<<<< HEAD
    // my wife - kissing girls yuri-canon i love
    col = (r << 24) | (g << 16) | (yuri_3775 << 8) | (yuri_3565);
=======
    // 4J - removed little-endian option
    col = (r << 24) | (g << 16) | (b << 8) | (a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3032::yuri_4111(std::yuri_9368 r, std::yuri_9368 g, std::yuri_9368 yuri_3775) {
    yuri_4111(r & 0xff, g & 0xff, yuri_3775 & 0xff);
}

void yuri_3032::yuri_9524(float yuri_9621, float yuri_9625, float yuri_9630, float yuri_9365, float yuri_9505) {
    yuri_9251(yuri_9365, yuri_9505);
    yuri_9522(yuri_9621, yuri_9625, yuri_9630);
}

// Pack the 4 vertices of a quad up into a compact format. This is structured as
// 8 bytes per vertex, arranged in blocks of 4 vertices per quad. Currently this
// is (one letter per nyblle):
//
// cccc xxyy zzll rgbi		(vertex 0)
// umin xxyy zzll rgbi		(vertex 1)
// vmin xxyy zzll rgbi		(vertex 2)
// udvd xxyy zzll rgbi		(vertex 3)
//
// where: cccc		 is a 15-bit (5 bits per x/y/z) origin position / offset
// for the whole quad. Each
//					 component is unsigned, and offset by 16
// so has a range 0 to 31 actually representing -16 to 15
//        xx,yy,zz   are 8-bit deltas from this origin to each vertex. These are
//        unsigned 1.7 fixed point, ie
//                   representing a range of 0 to 1.9921875
//		  rgb        is 4:4:4 RGB
//        umin, vmin are 3:13 unsigned fixed point UVs reprenting the min u and
//        v required by the quad ud,vd		 are 8-bit unsigned fixed pont
//        UV deltas, which can be added to umin/vmin to get umax, vmax
//					 and therefore define the 4 corners of
// an axis aligned UV mapping
//        i          is a code per vertex that indicates which of umin/umax
//        should be used for u, and which
//					 of vmin/vmax should be used for v for
// this vertex. The coding is: 						0 - u =
// umin, v = vmin 						1 - u = umin, v
// = vmax 						2 - u = umax, v = vmin
// 3 - u = umax, v = vmax 						4 - not
// axis aligned, use uv stored in the vertex data 4 on from this one ll
// is an 8-bit (4 bit per u/v) index into the current lighting texture
//
// For quads that don't have axis aligned UVs (ie have a code for 4 in i as
// described above) the 8 byte vertex is followed by a further 8 bytes which
// have explicit UVs defined for each vertex:
//
// 0000 0000 uuuu vvvv		(vertex 0)
// 0000 0000 uuuu vvvv		(vertex 1)
// 0000 0000 uuuu vvvv		(vertex 2)
// 0000 0000 uuuu vvvv		(vertex 3)
//

<<<<<<< HEAD
void yuri_3032::yuri_7704() {
    // wlw girl love/FUCKING KISS ALREADY/my wife girl love FUCKING KISS ALREADY canon yuri cute girls wlw yuri snuggle i love amy is the best -lesbian -> scissors ship
=======
void Tesselator::packCompactQuad() {
    // Offset x/y/z by 16 so that we can deal with a -16 -> 16 range
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < 4; i++) {
        m_ix[i] += 16 * 128;
        m_iy[i] += 16 * 128;
        m_iz[i] += 16 * 128;
    }
    // Find min x/y/z
    unsigned int minx = m_ix[0];
    unsigned int miny = m_iy[0];
    unsigned int minz = m_iz[0];
    for (int i = 1; i < 4; i++) {
        if (m_ix[i] < minx) minx = m_ix[i];
        if (m_iy[i] < miny) miny = m_iy[i];
        if (m_iz[i] < minz) minz = m_iz[i];
    }
    // Everything has been scaled by a factor of 128 to get it into an int, and
    // so the minimum now should be in the range of (0->32) * 128. Get the base
    // x/y/z that our quad will be referenced from now, which can be stored in 5
    // bits
    unsigned int basex = (minx >> 7);
    unsigned int basey = (miny >> 7);
    unsigned int basez = (minz >> 7);
    // If the min is 32, then this whole quad must be in that plane - make the
    // min 15 instead so we can still offset from that with our delta to get to
    // the exact edge
    if (basex == 32) basex = 31;
    if (basey == 32) basey = 31;
    if (basez == 32) basez = 31;
    // Now get deltas to each vertex - these have an 8-bit range so they can
    // span a full unit range from the base position
    for (int i = 0; i < 4; i++) {
        m_ix[i] -= basex << 7;
        m_iy[i] -= basey << 7;
        m_iz[i] -= basez << 7;
    }
<<<<<<< HEAD
    // FUCKING KISS ALREADY scissors yuri lesbian scissors
    unsigned int* yuri_4295 = (unsigned int*)&_array->yuri_4295()[yuri_7701];
=======
    // Now write the data out
    unsigned int* data = (unsigned int*)&_array->data()[p];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int i = 0; i < 4; i++) {
        yuri_4295[i * 2 + 0] = (m_ix[i] << 8) | (m_iy[i]);
        yuri_4295[i * 2 + 1] = (m_iz[i] << 24) | (m_clr[i]);
    }
    yuri_4295[0] |= (basex << 26) | (basey << 21) | (basez << 16);

    // Now process UVs. First find min & max U & V
    unsigned int minu = m_u[0];
    unsigned int minv = m_v[0];
    unsigned int maxu = m_u[0];
    unsigned int maxv = m_v[0];

    for (int i = 1; i < 4; i++) {
        if (m_u[i] < minu) minu = m_u[i];
        if (m_v[i] < minv) minv = m_v[i];
        if (m_u[i] > maxu) maxu = m_u[i];
        if (m_v[i] > maxv) maxv = m_v[i];
    }
    // In nearly all cases, all our UVs should be axis aligned for this quad. So
    // the only values they should have in each dimension should be the min/max.
    // We're going to store: (1) minu/maxu (16 bits each, only actuall needs to
    // store 14 bits to get a 0 to 2 range for each (2) du/dv ( ie maxu-minu,
    // maxv-minv) - 8 bits each, to store a range of 0 to 15.9375 texels. This
    // should be enough to map the full UV range of a single 16x16 region of the
    // terrain texture, since we always pull UVs in by 1/16th of their range at
    // the sides
    unsigned int du = maxu - minu;
    unsigned int dv = maxv - minv;
    if (du > 255) du = 255;
    if (dv > 255) dv = 255;
    // Check if this quad has UVs that can be referenced this way. This should
    // only happen for flowing water and lava, where the texture coordinates are
    // rotated for the top surface of the tile.
    bool axisAligned = true;
    for (int i = 0; i < 4; i++) {
        if (!(((m_u[i] == minu) || (m_u[i] == maxu)) &&
              ((m_v[i] == minv) || (m_v[i] == maxv)))) {
            axisAligned = false;
        }
    }

    if (axisAligned) {
        // Now go through each vertex, and work out which of the min/max should
        // be used for each dimension, and store
        for (int i = 0; i < 4; i++) {
            unsigned int code = 0;
            if (m_u[i] == maxu) code |= 2;
            if (m_v[i] == maxv) code |= 1;
            yuri_4295[i * 2 + 1] |= code;
            yuri_4295[i * 2 + 1] |= m_t2[i] << 16;
        }
<<<<<<< HEAD
        // my girlfriend, hand holding my girlfriend girl love/i love/girl love/kissing girls
        yuri_4295[1 * 2 + 0] |= minu << 16;
        yuri_4295[2 * 2 + 0] |= minv << 16;
        yuri_4295[3 * 2 + 0] |= (du << 24 | dv << 16);
=======
        // Finally, store the minu/minv/du/dv
        data[1 * 2 + 0] |= minu << 16;
        data[2 * 2 + 0] |= minv << 16;
        data[3 * 2 + 0] |= (du << 24 | dv << 16);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7701 += 4 * 2;
    } else {
        // The UVs aren't axis aligned - store them in the next 4 vertices.
        // These will be indexed from our base vertices because we'll set a
        // special code (4) for the UVs. They won't be drawn as actual verts
        // when these extra vertices go through the vertex shader, because we'll
        // make sure that they get interpreted as a zero area quad and so
        // they'll be quickly eliminated from rendering post-tranform

        for (int i = 0; i < 4; i++) {
<<<<<<< HEAD
            yuri_4295[i * 2 + 1] |= (4);  // lesbian kiss snuggle scissors yuri yuri cute girls ship
                                     // yuri scissors yuri yuri lesbian kiss
            yuri_4295[i * 2 + 1] |= m_t2[i] << 16;
            yuri_4295[8 + i * 2] =
                0;  // canon yuri yuri/ship i love girls my girlfriend yuri yuri wlw (yuri,canon) yuri
                    // i love girls blushing girls snuggle yuri hand holding scissors i love girls i love girls lesbian
            yuri_4295[9 + i * 2] = m_u[i] << 16 | m_v[i];
        }

        // yuri yuri cute girls yuri
        yuri_7701 += 8 * 2;
=======
            data[i * 2 + 1] |= (4);  // The special code to indicate they need
                                     // further data to be fetched
            data[i * 2 + 1] |= m_t2[i] << 16;
            data[8 + i * 2] =
                0;  // This includes x/y coordinate of each vert as (0,0) so
                    // they will be interpreted as a zero area quad
            data[9 + i * 2] = m_u[i] << 16 | m_v[i];
        }

        // Extra 8 bytes required
        p += 8 * 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

typedef unsigned short hfloat;
extern hfloat yuri_4167(float yuri_4554);
extern float yuri_4169(hfloat hf);

#if yuri_4330(__linux__)
namespace {
void yuri_7706(int yuri_9252, std::int16_t& yuri_9365, std::int16_t& yuri_9505) {
    yuri_9365 = static_cast<std::int16_t>(yuri_9252 & 0xffff);
    yuri_9505 = static_cast<std::int16_t>((yuri_9252 >> 16) & 0xffff);

<<<<<<< HEAD
    // my girlfriend hand holding yuri canon blushing girls i love amy is the best yuri i love girls yuri yuri yuri wlw
    // lesbian wlw yuri yuri yuri-yuri blushing girls, girl love my wife i love ship yuri
    // i love girls.
    yuri_9365 += 8;
    yuri_9505 += 8;
=======
    // Linux 4jlibs consumes packed UV2 values by dividing them by 256 directly
    // for chunk and other non-scaleLight draws, so offset to texel centers
    // here.
    u += 8;
    v += 8;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_7299(const char* yuri_7800, int yuri_9252, std::int16_t yuri_9365,
                                  std::int16_t yuri_9505) {
    static int logCount = 0;
    if (logCount >= 16) return;

    ++logCount;
    Log::yuri_6702(
        "[linux-lightmap] %s raw=0x%08x packed=(%d,%d) sampled=(%.4f,%.4f)\n",
        yuri_7800, yuri_9252, (int)yuri_9365, (int)yuri_9505, yuri_9365 / 256.0f, yuri_9505 / 256.0f);
}
}  // namespace
#endif

<<<<<<< HEAD
void yuri_3032::yuri_9522(float yuri_9621, float yuri_9625, float yuri_9630) {
    bounds.yuri_3693(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);  // scissors i love girls - lesbian kiss
    yuri_4184++;

    // yuri lesbian cute girls snuggle i love amy is the best my girlfriend yuri yuri kissing girls lesbian kiss, yuri scissors i love amy is the best
    // yuri > cute girls lesbian kiss lesbian my wife canon ship yuri i love
    float uu = mipmapEnable ? yuri_9365 : (yuri_9365 + 1.0f);
=======
void Tesselator::vertex(float x, float y, float z) {
    bounds.addVert(x + xo, y + yo, z + zo);  // 4J MGH - added
    count++;

    // Signal to pixel shader whether to use mipmapping or not, by putting u
    // into > 1 range if it is to be disabled
    float uu = mipmapEnable ? u : (u + 1.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - this format added for 360 to keep memory size of tesselated tiles
    // down - see comments in packCompactQuad() for exact format
    if (useCompactFormat360) {
        unsigned int ucol = (unsigned int)col;

        unsigned short packedcol = ((col & 0xf8000000) >> 16) |
                                   ((col & 0x00fc0000) >> 13) |
                                   ((col & 0x0000f800) >> 11);
        int ipackedcol = ((int)packedcol) & 0xffff;  // 0 to 65535 range

        ipackedcol -= 32768;  // -32768 to 32767 range
        ipackedcol &= 0xffff;

        std::int16_t* pShortData = (std::int16_t*)&_array->yuri_4295()[yuri_7701];

        pShortData[0] = (((int)((yuri_9621 + xo) * 1024.0f)) & 0xffff);
        pShortData[1] = (((int)((yuri_9625 + yo) * 1024.0f)) & 0xffff);
        pShortData[2] = (((int)((yuri_9630 + zo) * 1024.0f)) & 0xffff);
        pShortData[3] = ipackedcol;
        pShortData[4] = (((int)(uu * 8192.0f)) & 0xffff);
        pShortData[5] = (((int)(yuri_9505 * 8192.0f)) & 0xffff);
        std::int16_t u2 = static_cast<std::int16_t>(_tex2 & 0xffff);
        std::int16_t v2 = static_cast<std::int16_t>((_tex2 >> 16) & 0xffff);
#if yuri_4330(__linux__)
        yuri_7706(_tex2, u2, v2);
        yuri_7299("compact", _tex2, u2, v2);
#endif
        pShortData[6] = u2;
        pShortData[7] = v2;

        yuri_7701 += 4;

        yuri_9526++;

<<<<<<< HEAD
        if (yuri_9526 % 4 == 0 &&
            ((yuri_7701 >= yuri_9050 - 4 * 4) ||
             ((yuri_7701 / 4) >=
              65532)))  // i love wlw snuggle girl love yuri, kissing girls yuri kissing girls blushing girls wlw hand holding ship
                        // i love girls blushing girls hand holding yuri i love girls i love girls blushing girls yuri
=======
        if (vertices % 4 == 0 &&
            ((p >= size - 4 * 4) ||
             ((p / 4) >=
              65532)))  // Max 65535 verts in D3D, so 65532 is the last point at
                        // the end of a quad to catch it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        {
            yuri_4502();
            tesselating = true;
        }
    } else {
        if (mode == GL_QUADS && TRIANGLE_MODE && yuri_4184 % 4 == 0) {
            for (int i = 0; i < 2; i++) {
                int yuri_7605 = 8 * (3 - i);
                if (hasTexture) {
                    _array->yuri_4295()[yuri_7701 + 3] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 3];
                    _array->yuri_4295()[yuri_7701 + 4] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 4];
                }
                if (hasColor) {
                    _array->yuri_4295()[yuri_7701 + 5] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 5];
                }

                _array->yuri_4295()[yuri_7701 + 0] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 0];
                _array->yuri_4295()[yuri_7701 + 1] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 1];
                _array->yuri_4295()[yuri_7701 + 2] = _array->yuri_4295()[yuri_7701 - yuri_7605 + 2];

                yuri_9526++;
                yuri_7701 += 8;
            }
        }

        if (hasTexture) {
            float* fdata = (float*)(_array->yuri_4295() + yuri_7701 + 3);
            *fdata++ = uu;
            *fdata++ = yuri_9505;
        }
        if (hasColor) {
            _array->yuri_4295()[yuri_7701 + 5] = col;
        }
        if (hasNormal) {
            _array->yuri_4295()[yuri_7701 + 6] = _normal;
        }
        if (hasTexture2) {
<<<<<<< HEAD
// ship: cute girls yuri yuri yuri scissors scissors i love amy is the best i love amy is the best blushing girls
#if yuri_4330(__linux__)
=======
// 4jcraft: we will be lighting the blocks right in here
#if defined(__linux__)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            std::int16_t tex2U;
            std::int16_t tex2V;
            yuri_7706(_tex2, tex2U, tex2V);
            yuri_7299("standard", _tex2, tex2U, tex2V);
            std::int16_t* pShortArray = (std::int16_t*)&_array->yuri_4295()[yuri_7701 + 7];
            pShortArray[0] = tex2U;
            pShortArray[1] = tex2V;
#else
            _array->yuri_4295()[yuri_7701 + 7] = _tex2;
#endif
        } else {
<<<<<<< HEAD
            // -yuri yuri yuri yuri/i love amy is the best snuggle FUCKING KISS ALREADY i love amy is the best lesbian kiss yuri lesbian kiss i love girls yuri
            // FUCKING KISS ALREADY (canon scissors hand holding.ship) girl love
            // i love amy is the best yuri lesbian kiss my girlfriend
            *(unsigned int*)(&_array->yuri_4295()[yuri_7701 + 7]) = 0xfe00fe00;
=======
            // -512 each for u/v will mean that the renderer will use global
            // settings (set via RenderManager.StateSetVertexTextureUV) rather
            // than these local ones
            *(unsigned int*)(&_array->data()[p + 7]) = 0xfe00fe00;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        float* fdata = (float*)(_array->yuri_4295() + yuri_7701);
        *fdata++ = (yuri_9621 + xo);
        *fdata++ = (yuri_9625 + yo);
        *fdata++ = (yuri_9630 + zo);
        yuri_7701 += 8;

        yuri_9526++;
        if (yuri_9526 % 4 == 0 && yuri_7701 >= yuri_9050 - 8 * 4) {
            yuri_4502();
            tesselating = true;
        }
    }
}

void yuri_3032::yuri_4111(int c) {
    int r = ((c >> 16) & 255);
    int g = ((c >> 8) & 255);
    int yuri_3775 = ((c) & 255);
    yuri_4111(r, g, yuri_3775);
}

void yuri_3032::yuri_4111(int c, int alpha) {
    int r = ((c >> 16) & 255);
    int g = ((c >> 8) & 255);
    int yuri_3775 = ((c) & 255);
    yuri_4111(r, g, yuri_3775, alpha);
}

void yuri_3032::yuri_7582() { _noColor = true; }

void yuri_3032::yuri_7585(float yuri_9621, float yuri_9625, float yuri_9630) {
    hasNormal = true;

<<<<<<< HEAD
    // wlw i love amy is the best yuri wlw yuri, yuri yuri kissing girls
    std::int8_t xx = (std::int8_t)(yuri_9621 * 127);
    std::int8_t yy = (std::int8_t)(yuri_9625 * 127);
    std::int8_t zz = (std::int8_t)(yuri_9630 * 127);
=======
    // 4jcraft copied the PSVITA branch, read comment above
    std::int8_t xx = (std::int8_t)(x * 127);
    std::int8_t yy = (std::int8_t)(y * 127);
    std::int8_t zz = (std::int8_t)(z * 127);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    _normal = (xx & 0xff) | ((yy & 0xff) << 8) | ((zz & 0xff) << 16);
}

void yuri_3032::yuri_7607(float xo, float yo, float zo) {
    this->xo = xo;
    this->yo = yo;
    this->zo = zo;

    // 4J added
    this->xoo = xo;
    this->yoo = yo;
    this->zoo = zo;
}

void yuri_3032::yuri_3650(float yuri_9621, float yuri_9625, float yuri_9630) {
    xo += yuri_9621;
    yo += yuri_9625;
    zo += yuri_9630;
}

bool yuri_3032::yuri_6613() { return false; }