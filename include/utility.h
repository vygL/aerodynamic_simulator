#pragma once

#include "linmath.h"

#define member_size(type, member) (sizeof( ((type *)0)->member ))

typedef struct {
    vec3 vertex;
    vec4 color;
} point;

typedef vec3 rgb;
typedef vec4 rgba;