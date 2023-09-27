// Copyright 2020 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "video_core/renderer_opengl/texture_filters/scale_force/scale_force.h"

#include "shaders/scale_force.frag"
#include "shaders/tex_coord.vert"

namespace OpenGL {

ScaleForce::ScaleForce(u16 scale_factor) : TextureFilterBase(scale_factor) {
    program.Create(tex_coord_vert.data(), scale_force_frag.data());
    vao.Create();
    src_sampler.Create();

    state.draw.shader_program = program.handle;
    state.draw.vertex_array = vao.handle;
    state.draw.shader_program = program.handle;
    state.texture_units[0].sampler = src_sampler.handle;

    glSamplerParameteri(src_sampler.handle, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glSamplerParameteri(src_sampler.handle, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glSamplerParameteri(src_sampler.handle, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glSamplerParameteri(src_sampler.handle, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void ScaleForce::Filter(const OGLTexture& src_tex, Common::Rectangle<u32> src_rect,
                        const OGLTexture& dst_tex, Common::Rectangle<u32> dst_rect) {
    const OpenGLState cur_state = OpenGLState::GetCurState();
    state.texture_units[0].texture_2d = src_tex.handle;
    state.draw.draw_framebuffer = draw_fbo.handle;
    state.viewport = {static_cast<GLint>(dst_rect.left), static_cast<GLint>(dst_rect.bottom),
                      static_cast<GLsizei>(dst_rect.GetWidth()),
                      static_cast<GLsizei>(dst_rect.GetHeight())};
    state.Apply();

    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                           dst_tex.handle, 0);
    glFramebufferTexture2D(GL_DRAW_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, 0, 0);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    cur_state.Apply();
}

} // namespace OpenGL
