#pragma once

#include "vec2d.hpp"

namespace zps {
    struct MovingObject {
        public :
            Vec2d<double> pos;
            Vec2d<double> vel;
            Vec2d<double> acc;

            MovingObject(){};
    };
}