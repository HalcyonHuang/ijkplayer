/*
 * Copyright (c) 2016 Bilibili
 * copyright (c) 2016 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "internal.h"

/* *******************  画面黑白 滤镜  ******************* */
 /*static const char g_shader[] = IJK_GLES_STRING(
    precision highp float;
    varying   highp vec2 vTexCoord;
    uniform   lowp  sampler2D sTexture;
    void main()
    {
        lowp    vec3 rgb = texture2D(sTexture, vTexCoord).rgb;
        gl_FragColor = vec4(0.299*rgb.r+0.587*rgb.g+0.114*rgb.b);
    }
);*/

/*static const char v_shader[] = IJK_GLES_STRING(
    precision highp float;
    varying   highp vec2 vTexCoord;
    attribute highp vec4 aPosition;
    attribute highp vec2 aTexCoord;

    void main()
    {
        vTexCoord = vec2(aTexCoord.x,1.0-aTexCoord.y);
        gl_Position = aPosition;
    }
);*/
/* *******************  画面黑白 滤镜  ******************* */



/* *******************  画面反转 滤镜  ******************* */
static const char g_shader[] = IJK_GLES_STRING(
               varying highp vec2 textureCoordinate;    
              uniform sampler2D inputImageTexture; 
              void main()  
              {   
                 gl_FragColor = texture2D(inputImageTexture, textureCoordinate); 
              }
);  
 
static const char v_shader[] = IJK_GLES_STRING(
            attribute vec4 position;
            attribute vec4 inputTextureCoordinate;
            varying vec2 textureCoordinate;
            void main()
            {
               gl_Position = position;
               textureCoordinate = inputTextureCoordinate.xy;
            }
);
/* *******************  画面反转 滤镜  ******************* */




const char *IJK_GLES2_getFragmentShader_test()
{
    return g_shader;
}

const char *IJK_GLES2_getVertexShader_test()
{
    return v_shader;
}