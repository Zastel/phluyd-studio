#pragma once

namespace zps {
    template <typename T>

    struct Vec3d {
        public:
            T x;
            T y;
            T z;

            Vec3d(T x, T y, T z){
                this->x = x;
                this->y = y;
                this->z = z;
            }

            Vec3d operator+(Vec3d const& a, Vec3d const& b, ){
                return Vec3d(a.x + b.x, a.y + b.y, a.z + b.z);
            }
            Vec3d operator-(Vec3d const& a, Vec3d const& b){
                return Vec3d(a.x - b.x, a.y - b.y, a.z - b.z);
            }
            Vec3d operator*(Vec3d const& a, Vec3d const& b){
                return Vec3d(a.x * b.x, a.y * b.y, a.z * b.z);
            }
            Vec3d operator/(Vec3d const& a, Vec3d const& b){
                return Vec3d(a.x / b.x, a.y / b.y, a.z / b.z);
            }
            Vec3d operator%(Vec3d const& a, Vec3d const& b){
                return Vec3d(a.x % b.x, a.y % b.y, a.z % b.z);
            }
    };
}