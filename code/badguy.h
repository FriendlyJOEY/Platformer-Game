#ifndef __BADGUY_H
#define __BADGUY_H
#include "phys_sprite.h"

namespace csis3700 {
  class badguy : public phys_sprite {
  public:
    badguy(float initial_x=0, float initial_y=0,float x_mx=0,float x_mn=0);
    virtual bool is_passive() const;
    virtual void set_on_ground(bool v);
    virtual void advance_by_time(double dt);
    virtual void resolve(const collision& collision, sprite* other);
    virtual void move_right();
    virtual void stand();
    virtual void draw();
    virtual void move_left();
    virtual bool jump();
    virtual bool kill(bool k);
  private:
    bool on_ground,killbadguy,killplayer;
    float x_max,x_min,direction;
    image_sequence *run_L, *st,*run_R;
  };
}


#endif /* PLAYER_SPRITE_H */
