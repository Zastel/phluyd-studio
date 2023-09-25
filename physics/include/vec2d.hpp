#pragma once

namespace zps {
    template <typename T>

    struct Vec2d {
        public:
            T x;
            T y;

            Vec2d(T x, T y){
                this->x = x;
                this->y = y;
            }

            Vec2d(Vec2d *vect){
                vect->x = x;
                vect->y = y;
            }

            Vec2d(){
                x = (T)0;
                y = (T)0;
            }

            friend Vec2d operator + (Vec2d const& a, Vec2d const& b){
                return Vec2d(a.x + b.x, a.y + b.y);
            }
            friend Vec2d operator - (Vec2d const& a, Vec2d const& b){
                return Vec2d(a.x - b.x, a.y - b.y);
            }
            friend Vec2d operator * (Vec2d const& a, Vec2d const& b){
                return Vec2d(a.x * b.x, a.y * b.y);
            }
            friend Vec2d operator / (Vec2d const& a, Vec2d const& b){
                return Vec2d(a.x / b.x, a.y / b.y);
            }
            
            friend Vec2d operator + (Vec2d const& a, T b){
                return Vec2d(a.x + b, a.y + b);
            }
            friend Vec2d operator - (Vec2d const& a, T b){
                return Vec2d(a.x - b, a.y - b);
            }
            friend Vec2d operator * (Vec2d const& a, T b){
                return Vec2d(a.x * b, a.y * b);
            }
            friend Vec2d operator / (Vec2d const& a, T b){
                return Vec2d(a.x / b, a.y / b);
            }
    };
}