#pragma once

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>

#include "moving_object.hpp"

namespace zps {
        /*
        * Should solve every object of the scene with Verlet integration.
        * For reference, the verlet integration to calculate is :
        * new_pos = pos + vel * dt + acc * (dt * dt * 0.5) 
        * new_acc = apply_forces() // calculated when new forces are applied on object
        * new_vel = vel + (acc + new_acc) * (dt*0.5)
        * The apply_forces() method should return the new acceleration of the object, by calculating
        * the acceleration done by gravity, drag, etc. Acceleration of the object should also be modified
        * by a force generator, and constraints.
        * For further references : https://en.wikipedia.org/wiki/Verlet_integration#Algorithmic_representation
        * Steps implementation should also be needed.
        * 
        * TODO : Forgot to pass everything as a reference. Have fun tomorrow's me
        */
    class VerletSolver
    {
    private:
        std::vector<MovingObject> objects;
        double t;
        double dt;

        void refreshTimeDelta(){
            double current = SDL_GetTicks();
            dt = current - t;
            t = current;
        }

        void applyGravity(){
            for (auto obj : objects) {
                obj.acc = obj.acc + Vec2d<double>(0, 9.81);
            }
        }

        void checkCollisions(){
            for (auto obj : objects) {
                if (obj.pos.x < 0 || obj.pos.x > 750){
                    if(obj.pos.x < 0) {
                        obj.pos.x = 0;
                    } else {
                        obj.pos.x = 750;
                    }
                } else if (obj.pos.y < 0 || obj.pos.y > 550){
                    if (obj.pos.y < 0) {
                        obj.pos.y = 0;
                    } else {
                        obj.pos.y = 550;
                    }
                }
            }
        }
    public:
        void computeFrame(){
            refreshTimeDelta();
            applyGravity();
            updateObjects();
            checkCollisions();
        }

        void addObject(MovingObject &obj){
            objects.emplace_back(obj);
        }

        void updateObjects(){
            for (auto obj : objects){
                Vec2d<double> new_pos = obj.pos + (obj.vel * dt) + (obj.acc * (dt * dt * 0.5));
                Vec2d<double> new_acc = applyForces();
                Vec2d<double> new_vel = obj.vel + ((obj.acc + new_acc) * (dt * 0.5));
                
                obj.pos = new_pos;
                obj.acc = new_acc;
                obj.vel = new_vel;
            }
        }

        Vec2d<double> applyForces(){
            return Vec2d<double>();
        }

        VerletSolver(){
            MovingObject obj;
            addObject(obj);
            t = SDL_GetTicks();
        }
    };
}